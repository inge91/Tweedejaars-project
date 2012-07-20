#include <iostream>
#include <boost/numeric/ublas/io.hpp>
#include <alerror/alerror.h>
#include <cmath>
#include <functional>

#include "kinematics.h"

using namespace std;
using boost::numeric::ublas::matrix;
using boost::numeric::ublas::prod;
using boost::numeric::ublas::identity_matrix;
using boost::numeric::ublas::trans;

Kinematics::Kinematics(string ip_address) :
    m_motion_proxy(ip_address, 9559)
{
}


joint_loc_map Kinematics::get_locations_dict(BodyPart leg, bool online,
                                               const map<string, double> &joint_dict)
{
    vector<string> left_path = {"None", "LAnkleRoll", "LAnklePitch", "LKneePitch", "LHipPitch",
        "LHipRoll", "LHipYawPitch", "Torso"};
    vector<string> right_path = {"None", "RAnkleRoll", "RAnklePitch", "RKneePitch", "RHipPitch",
        "RHipRoll", "RHipYawPitch", "Torso"};
    vector<string> path;

    switch (leg) {
        case LLEG:
            path = left_path;
            break;
        case RLEG:
            path = right_path;
            break;
    }

    joint_loc_map joint_locs;

    // initial transformation matrix
    matrix<double> T = identity_matrix<double>(4, 4);

    // loop through every element except the first,
    // along with its previous element
    string current, previous;
    for (unsigned cur = 1, prev = 0; cur< path.size(); ++cur, ++prev) {
        current = path[cur]; previous = path[prev];

        // update the transformation matrix to calculate the centroid location
        int towards_torso = jointOffsets[pair<string, string>(previous, current)].second;
        towards_torso *= -1;

        T = prod(T, translation_matrix(previous, current));
        T = prod(T, rotation_matrix(current, towards_torso, online, joint_dict));

        // add joint location
        vector<vector<double> > origin = { {0}, {0}, {0}, {1} };
        joint_locs[current] = prod(T, vec_to_mat(origin));
    }

    // now calculate the all other branches from the torso
    vector<BodyPart> branches = { (leg == RLEG) ? LLEG : RLEG,
        LARM, RARM, HEAD};

    for (BodyPart &branch : branches)
        locs_from_torso(T, branch, joint_locs, online, joint_dict);

    return joint_locs;
}

void Kinematics::locs_from_torso(matrix<double> T, BodyPart part,
                                   joint_loc_map &joint_locs,
                                   bool online,
                                   const map<string, double> &joint_dict)
{
    map<BodyPart, vector<string> >paths =
    {
        {LLEG, {"Torso", "LHipYawPitch", "LHipRoll", "LHipPitch", "LKneePitch",
                  "LAnklePitch", "LAnkleRoll"}},
        {RLEG, {"Torso", "RHipYawPitch", "RHipRoll", "RHipPitch", "RKneePitch",
                  "RAnklePitch", "RAnkleRoll"}},
        {LARM, {"Torso", "LShoulderPitch", "LShoulderRoll", "LElbowYaw",
                  "LElbowRoll"}},
        {RARM, {"Torso", "RShoulderPitch", "RShoulderRoll", "RElbowYaw",
                  "RElbowRoll"}},
        {HEAD, {"Torso", "HeadYaw", "HeadPitch"}}
    };

    vector<string> path = paths[part];

    // loop through every element except the first,
    // along with its previous element
    string current, previous;
    for (unsigned cur = 1, prev = 0; cur< path.size(); ++cur, ++prev) {
        current = path[cur];
        previous = path[prev];

        // update the transformation matrix
        int towards_torso = jointOffsets[pair<string, string>(previous, current)].second;
        towards_torso *= -1;

        T = prod(T, translation_matrix(previous, current));
        T = prod(T, rotation_matrix(current, towards_torso, online, joint_dict));

        // add joint location
        vector<vector<double> > origin = { {0}, {0}, {0}, {1} };
        joint_locs[current] = prod(T, vec_to_mat(origin));
    }
}

matrix<double> Kinematics::translation_matrix(string previous, string current)
{
    // get the x, y and z offset values
    vector<double> offsets;

    if (previous == "None") {
        offsets.push_back(0);
        offsets.push_back(0);
        offsets.push_back(0);
    } else {
        pair<vector<double>, double> j_off = Kinematics::jointOffsets[pair<string, string>(previous, current)];
        offsets = j_off.first;
    }

    // create the translation matrix
    vector<vector<double> > mat =
    {
        {1, 0, 0, offsets[0]},
        {0, 1, 0, offsets[1]},
        {0, 0, 1, offsets[2]},
        {0, 0, 0,          1}
    };

    return vec_to_mat(mat);
}

matrix<double> Kinematics::rotation_matrix(string joint, int towards_torso,
                                             bool online,
                                             const map<string, double> &joint_dict)
{
    // create the function needed to obtain the joint angles
    function<double(string)> get_angles;
    if (online)
        get_angles = [this](string x) { return m_motion_proxy.getAngles(x, true)[0]; };
    else
        get_angles = [&joint_dict](string x) { return joint_dict.find(x)->second; };

    // get the angle, or 0 if the current "joint" is the torso (which isn't a joint)
    double angle = 0;
    if (joint != "Torso")
        angle = get_angles(joint) * towards_torso;

    /* special case for the HipYawPitch
       it's split up evenly between a Yaw and a Pitch component
     */
    matrix<double> rot_matrix;
    if (contains(joint, "YawPitch")) {
        double h_angle = angle / 2.0;

        vector<vector<double> > yaw_component =
        {
            {cos(h_angle), -sin(h_angle), 0, 0},
            {sin(h_angle), cos(h_angle),  0, 0},
            {0,            0,             1, 0},
            {0,            0,             0, 1}
        };

        vector<vector<double> > pitch_component =
        {
            {cos(h_angle),  0, sin(h_angle), 0},
            {0,             1, 0,            0},
            {-sin(h_angle), 0, cos(h_angle), 0},
            {0,             0, 0,            1}
        };

        rot_matrix = prod(vec_to_mat(yaw_component),  vec_to_mat(pitch_component));
    }

    else if (contains(joint, "Roll")) {
        vector<vector<double> > rotation =
        {
            {1, 0,          0,           0},
            {0, cos(angle), -sin(angle), 0},
            {0, sin(angle), cos(angle),  0},
            {0, 0,          0,           1}
        };

        rot_matrix = vec_to_mat(rotation);
    }

    else if (contains(joint, "Pitch")) {
        vector<vector<double> > rotation =
        {
            {cos(angle),  0, sin(angle), 0},
            {0,           1, 0,          0},
            {-sin(angle), 0, cos(angle), 0},
            {0,           0, 0,          1}
        };

        rot_matrix = vec_to_mat(rotation);
    }

    else if (contains(joint, "Yaw")) {
        vector<vector<double> > rotation =
        {
            {cos(angle), -sin(angle), 0, 0},
            {sin(angle), cos(angle),  0, 0},
            {0,          0,           1, 0},
            {0,          0,           0, 1}
        };

        rot_matrix = vec_to_mat(rotation);
    }

    else if (contains(joint, "Torso")) {
        vector<vector<double> > rotation =
        {
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1}
        };

        rot_matrix = vec_to_mat(rotation);
    }

    return rot_matrix;
}

bool Kinematics::contains(string str, string substr)
{
    if (str.find(substr) != string::npos)
        return true;
    else
        return false;
}

matrix<double> Kinematics::vec_to_mat(vector<vector<double> > vec)
{
    matrix<double> mat(vec.size(), vec[0].size());

    for (unsigned i = 0; i < vec.size(); ++i) {
        for (unsigned j = 0; j < vec[0].size(); ++j) {
            mat(i, j) = vec[i][j];
        }
    }

    return mat;
}

map<pair<string, string>, pair<vector<double>, double> > Kinematics::jointOffsets =
{
    { {"Torso", "HeadYaw"},             { {0.0, 0.0, 126.50}, -1 } },
    { {"HeadYaw", "Torso"}                , {{0.0, 0.0, -126.50 }, 1}},
    { {"HeadYaw","HeadPitch"}             , {{0.0, 0.0, 0.0 }, -1}},
    { {"HeadPitch","HeadYaw"}             , {{0.0, 0.0, 0.0 }, 1}},
    { {"Torso", "LShoulderPitch"}         , {{0.0, 98.0, 100.00 }, -1}},
    { {"LShoulderPitch", "Torso"}         , {{0.0, -98.0, -100.00 }, 1}},
    { {"LShoulderPitch", "LShoulderRoll"} , {{0.0, 0.0, 0.0}, -1}},
    { {"LShoulderRoll", "LShoulderPitch"} , {{0.0, 0.0, 0.0}, 1}},
    { {"LShoulderRoll", "LElbowYaw" }     , {{105.00, 15.00, 0.00}, -1}},
    { {"LElbowYaw", "LShoulderRoll" }     , {{-105.00, -15.00, 0.00}, 1}},
    { {"LElbowYaw", "LElbowRoll"}         , {{0, 0, 0}, -1}},
    { {"LElbowRoll", "LElbowYaw"}         , {{0, 0, 0}, 1}},
    { {"LElbowRoll", "LWristYaw"}         , {{55.95, 0, 0 }, -1}},
    { {"LWristYaw", "LElbowRoll"}         , {{-55.95, 0, 0 }, 1}},
    { {"Torso", "LHipYawPitch"}           , {{0, 50.0, -85.0}, -1}},
    { {"LHipYawPitch", "Torso"}           , {{0, -50.0, 85.0}, 1}},
    { {"LHipYawPitch", "LHipRoll"}        , {{0.0 , 0.0, 0.0}, -1}},
    { {"LHipRoll", "LHipYawPitch"}        , {{0.0 , 0.0, 0.0}, 1}},
    { {"LHipRoll", "LHipPitch"}           , {{0.0, 0.0, 0.0}, -1}},
    { {"LHipPitch", "LHipRoll"}           , {{0.0, 0.0, 0.0}, 1}},
    { {"LHipPitch", "LKneePitch"}         , {{0.0, 0.0, -100.0}, -1}},
    { {"LKneePitch", "LHipPitch"}         , {{0.0, 0.0, 100.0}, 1}},
    { {"LKneePitch","LAnklePitch"}        , {{0.0, 0.0, -102.9}, -1}},
    { {"LAnklePitch","LKneePitch"}        , {{0.0, 0.0, 102.9}, 1}},
    { {"LAnklePitch", "LAnkleRoll"}       , {{0.0, 0.0, 0.0}, -1}},
    { {"LAnkleRoll", "LAnklePitch"}       , {{0.0, 0.0, 0.0}, 1}},
    { {"Torso", "RShoulderPitch"}         , {{0.0, -98.0, 100.00 }, -1}},
    { {"RShoulderPitch", "Torso"}         , {{0.0, 98.0, -100.00 }, 1}},
    { {"RShoulderPitch", "RShoulderRoll"} , {{0.0, 0.0, 0.0}, -1}},
    { {"RShoulderRoll", "RShoulderPitch"} , {{0.0, 0.0, 0.0}, 1}},
    { {"RShoulderRoll", "RElbowYaw" }     , {{105.00, -15.00, 0.00},  -1}},
    { {"RElbowYaw", "RShoulderRoll" }     , {{-105.00, 15.00, 0.00}, 1}},
    { {"RElbowYaw", "RElbowRoll"}         , {{0, 0, 0}, -1}},
    { {"RElbowRoll", "RElbowYaw"}         , {{0, 0, 0}, 1}},
    { {"RElbowRoll", "RWristYaw"}         , {{55.95, 0, 0 }, -1}},
    { {"RWristYaw", "RElbowRoll"}         , {{-55.95, 0, 0 }, 1}},
    { {"Torso", "RHipYawPitch"}           , {{0, -50.0, -85.0}, -1}},
    { {"RHipYawPitch", "Torso"}           , {{0, 50.0, 85.0}, 1}},
    { {"RHipYawPitch", "RHipRoll"}        , {{0.0 , 0.0, 0.0}, -1}},
    { {"RHipRoll", "RHipYawPitch"}        , {{0.0 , 0.0, 0.0}, 1}},
    { {"RHipRoll", "RHipPitch"}           , {{0.0, 0.0, 0.0}, -1}},
    { {"RHipPitch", "RHipRoll"}           , {{0.0, 0.0, 0.0}, 1}},
    { {"RHipPitch", "RKneePitch"}         , {{0.0, 0.0, -100.0}, -1}},
    { {"RKneePitch", "RHipPitch"}         , {{0.0, 0.0, 100.0}, 1}},
    { {"RKneePitch","RAnklePitch"}        , {{0.0, 0.0, -102.9}, -1}},
    { {"RAnklePitch","RKneePitch"}        , {{0.0, 0.0, 102.9}, 1}},
    { {"RAnklePitch", "RAnkleRoll"}       , {{0.0, 0.0, 0.0}, -1}},
    { {"RAnkleRoll", "RAnklePitch"}       , {{0.0, 0.0, 0.0}, 1}},

    // special endvalues
    { {"None", "RAnkleRoll"}                , {{0.0, 0.0, 0.0}, 1}},
    { {"RAnkleRoll", "None"}                , {{0.0, 0.0, 0.0}, -1}},
    { {"None", "LAnkleRoll"}                , {{0.0, 0.0, 0.0}, 1}},
    { {"LAnkleRoll", "None"}                , {{0.0, 0.0, 0.0}, -1}}
};
