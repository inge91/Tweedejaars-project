/*
 * Copyright (c) 2012 Aldebaran Robotics. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the COPYING file.
 */
#include <iostream>
#include <boost/numeric/ublas/io.hpp>
#include <alerror/alerror.h>
#include <cmath>
#include <functional>

#include "com.h"

using namespace std;
using boost::numeric::ublas::matrix;
using boost::numeric::ublas::prod;
using boost::numeric::ublas::identity_matrix;

CenterOfMass::CenterOfMass(string ip_address, int port) :
    m_motion_proxy(ip_address, port)
{
}

void CenterOfMass::locs_from_torso(matrix<double> T, string part,
                                   joint_loc_map &joint_locs,
                                   bool online,
                                   const map<string, double> &joint_dict)
{
    map<string, vector<string> >paths =
    {
        {"LLeg", {"Torso", "LHipYawPitch", "LHipRoll", "LHipPitch", "LKneePitch",
                  "LAnklePitch", "LAnkleRoll"}},
        {"RLeg", {"Torso", "RHipYawPitch", "RHipRoll", "RHipPitch", "RKneePitch",
                  "RAnklePitch", "RAnkleRoll"}},
        {"LArm", {"Torso", "LShoulderPitch", "LShoulderRoll", "LElbowYaw",
                  "LElbowRoll"}},
        {"RArm", {"Torso", "RShoulderPitch", "RShoulderRoll", "RElbowYaw",
                  "RElbowRoll"}},
        {"Head", {"Torso", "HeadYaw", "HeadPitch"}}
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

matrix<double> CenterOfMass::translation_matrix(string previous, string current)
{
    // get the x, y and z offset values
    vector<double> offsets;

    if (previous == "None") {
        offsets[0] = 0;
        offsets[1] = 0;
        offsets[2] = 0;
    } else {
        pair<vector<double>, double> j_off = CenterOfMass::jointOffsets[pair<string, string>(previous, current)];
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

matrix<double> CenterOfMass::rotation_matrix(string joint, int towards_torso,
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

bool CenterOfMass::contains(string str, string substr)
{
    if (str.find(substr) != string::npos)
        return true;
    else
        return false;
}

matrix<double> CenterOfMass::vec_to_mat(vector<vector<double> > vec)
{
    matrix<double> mat(vec.size(), vec[0].size());

    for (unsigned i = 0; i < vec.size(); ++i) {
        for (unsigned j = 0; j < vec[0].size(); ++j) {
            mat(i, j) = vec[i][j];
        }
    }

    return mat;
}

int main()
{
    CenterOfMass com("0.0.0.0", 9559);
    std::cout << com.translation_matrix("Torso", "HeadYaw") << std::endl;
}

// the data
map<string, pair<vector<double>, double> > CenterOfMass::jointCOM =
{
    {"RAnkleRoll",       { {25.40, -3.32, -32.41}, 0.16175}},
    {"LAnkleRoll",       { {25.40,  3.32, -32.41},  0.16175}},
    {"RAnklePitch",      { {1.42,   -0.28,  6.38},  0.13892}},
    {"LAnklePitch",      { {1.42,   0.28,  6.38},  0.13892}},
    {"RKneePitch",       { {4.22,   -2.52, -48.68},  0.25191}},
    {"LKneePitch",       { {4.22,   2.52, -48.68},  0.25191}},
    {"RHipPitch",        { {1.32,   -2.35, -53.52},  0.39421}},
    {"LHipPitch",        { {1.32,   2.35, -53.52},  0.39421}},
    {"RHipRoll",         { {-16.49, -0.29, -4.75},  0.13530}},
    {"LHipRoll",         { {-16.49, 0.29, -4.75},  0.13530}},
    {"RHipYawPitch",     { {-7.66,  12.00,  27.17}, 0.07117}},
    {"LHipYawPitch",     { {-7.66,  -12.00,  27.17}, 0.07117}},
    {"RElbowRoll",       { {65.36,  -0.34, -0.02},  0.18500}},
    {"LElbowRoll",       { {65.36,  0.34, -0.02},  0.18500}},
    {"RElbowYaw",        { {-25.60,  0.01, -0.19},  0.05971}},
    {"LElbowYaw",        { {-25.60, - 0.01, -0.19},  0.05971}},
    {"RShoulderRoll",    { {18.85,  -5.77,  0.65},  0.12309}},
    {"LShoulderRoll",    { {18.85,  5.77,  0.65},  0.12309}},
    {"RShoulderPitch",   { {-1.78,  24.96,  0.18},  0.06996}},
    {"LShoulderPitch",   { {-1.78,  -24.96,  0.18},  0.06996}},
    {"HeadYaw",          { {-0.02,  0.17,  -25.56},  0.05930}},
    {"Torso",            { {-4.15,  0.07,   42.58},   1.03948}},
    {"HeadPitch",        { {1.20,  -0.84,   53.53},  0.52065}}
};

map<pair<string, string>, pair<vector<double>, double> > CenterOfMass::jointOffsets =
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
