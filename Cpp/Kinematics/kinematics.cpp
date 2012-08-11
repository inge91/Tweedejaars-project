#include <iostream>
#include <alerror/alerror.h>
#include <cmath>
#include <functional>

#include "kinematics.h"

#include <Eigen/Eigen>
#include <Eigen/Geometry>

using Eigen::EigenSolver;

using namespace std;

Kinematics::Kinematics(string ip_address)
    : m_motion_proxy(ip_address, 9559)
{
}

joint_loc_map Kinematics::get_locations_dict(BodyPart leg, bool online,
                                             const map<string, double> &joint_dict)
{
    map<string, Matrix4d> transformations = get_transformations_dict(leg, online,
                                                                     joint_dict);
    joint_loc_map locations;

    Vector4d origin; origin << 0, 0, 0, 1;
    for (pair<string, Matrix4d> p : transformations) {
        locations[p.first] = p.second * origin;
    }

    return locations;
}

Vector4d Kinematics::get_CoM(BodyPart leg, bool online,
                             const map<string, double> &joint_dict)
{
    joint_loc_map joint_locs = get_locations_dict(leg, online, joint_dict);

    // calculating total mass
    double total_mass = 0;

    for (auto &jcom : jointCOM) {
        total_mass += jcom.second.second;
    }

    // calculating CoM
    Vector4d com;
    com << 0, 0, 0, 1;

    string joint;
    Vector4d joint_loc;
    vector<double> centroid_vec;
    Vector4d centroid;
    double mass;
    for (auto &p : joint_locs) {
        joint = p.first;
        joint_loc = p.second;
        pair<vector<double>, double> com_mass = jointCOM[joint];
        centroid_vec = com_mass.first;
        mass = com_mass.second;

        centroid(0) = centroid_vec[0];
        centroid(1) = centroid_vec[1];
        centroid(2) = centroid_vec[2];
        centroid(3) = 1;

        joint_loc += centroid;
        com += (mass * joint_loc) / total_mass;
    }

    return com;
}

map<string, Matrix4d> Kinematics::get_transformations_dict(BodyPart leg, bool online,
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

    map<string, Matrix4d> joint_locs;

    // initial transformation matrix
    Matrix4d T = Matrix4d::Identity();

    // loop through every element except the first,
    // along with its previous element
    string current, previous;
    for (unsigned cur = 1, prev = 0; cur< path.size(); ++cur, ++prev) {
        current = path[cur]; previous = path[prev];

        // update the transformation matrix to calculate the centroid location
        int towards_torso = jointOffsets[pair<string, string>(previous, current)].second;
        towards_torso *= -1;

        T *= translation_matrix(previous, current);
        T *= rotation_matrix(current, towards_torso, online, joint_dict);

        // add joint location
        Vector4d origin;
        origin << 0, 0, 0, 1;
        joint_locs[current] = T;
    }

    // now calculate the all other branches from the torso
    vector<BodyPart> branches = { (leg == RLEG) ? LLEG : RLEG,
        LARM, RARM, HEAD};

    for (BodyPart &branch : branches)
        locs_from_torso(T, branch, joint_locs, online, joint_dict);

    return joint_locs;
}

void Kinematics::locs_from_torso(Matrix4d T, BodyPart part,
                                   map<string, Matrix4d> &joint_locs,
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

        T *= translation_matrix(previous, current);
        T *= rotation_matrix(current, towards_torso, online, joint_dict);

        // add joint location
        Vector4d origin;
        origin << 0, 0, 0, 1;

        joint_locs[current] = T;
    }
}

Matrix4d Kinematics::translation_matrix(string previous, string current)
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
    Matrix4d mat;
    mat << 1, 0, 0, offsets[0],
           0, 1, 0, offsets[1],
           0, 0, 1, offsets[2],
           0, 0, 0, 1;

    return mat;
}

Matrix4d Kinematics::rotation_matrix(string joint, int towards_torso,
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

    Matrix4d rot_matrix;

    /* special case for the HipYawPitch
       it's split up evenly between a Yaw and a Pitch component
     */
    if (contains(joint, "YawPitch")) {
        double h_angle = angle / 2.0;

        Matrix4d yaw_component;
        Matrix4d pitch_component;

        yaw_component <<
            cos(h_angle), -sin(h_angle), 0, 0,
            sin(h_angle), cos(h_angle),  0, 0,
            0,            0,             1, 0,
            0,            0,             0, 1;

        pitch_component <<
            cos(h_angle),  0, sin(h_angle), 0,
            0,             1, 0,            0,
            -sin(h_angle), 0, cos(h_angle), 0,
            0,             0, 0,            1;

        rot_matrix = yaw_component * pitch_component;
    }

    else if (contains(joint, "Roll")) {
        rot_matrix <<
            1, 0,          0,           0,
            0, cos(angle), -sin(angle), 0,
            0, sin(angle), cos(angle),  0,
            0, 0,          0,           1;
    }

    else if (contains(joint, "Pitch")) {
        rot_matrix <<
            cos(angle),  0, sin(angle), 0,
            0,           1, 0,          0,
            -sin(angle), 0, cos(angle), 0,
            0,           0, 0,          1;
    }

    else if (contains(joint, "Yaw")) {
        rot_matrix <<
            cos(angle), -sin(angle), 0, 0,
            sin(angle), cos(angle),  0, 0,
            0,          0,           1, 0,
            0,          0,           0, 1;
    }

    else if (contains(joint, "Torso")) {
        rot_matrix <<
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1;
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

MatrixXd Kinematics::get_jacobian(BodyPart leg,
                                  map<string, double> &joint_angles,
                                  map<string, Matrix4d> &joint_trans)
{
    vector<string> joints = {"HipYawPitch", "HipRoll", "HipPitch", "KneePitch"};
    vector<string> end_effectors;

    switch (leg) {
    case LLEG:
        for (string &j : joints)
            j.insert(j.begin(), 'L');
        end_effectors.push_back("LAnkleRoll");
        break;

    case RLEG:
        for (string &j : joints)
            j.insert(j.begin(), 'R');
        end_effectors.push_back("RAnkleRoll");
        break;
    }

    int k = end_effectors.size();
    int n = joints.size();

    MatrixXd J(3*k, n);

    // some variables for use during the loop
    Vector4d origin; origin << 0, 0, 0, 1;
    Vector3d v, s, p, cross_prod;
    Vector4d s4, p4;

    // filling the Jacobian
    for (int i = 0; i < 3*k; i += 3) {
        for (int j = 0; j < n; ++j) {
            string joint = joints[j];
            string end_effector = end_effectors[(i < 3) ? i : i - (2*(i/3))];

            v = rotation_axis(joint_trans[joint]);

            s4 = joint_trans[end_effector] * origin;
            s = s4.start(3);

            p4 = joint_trans[joint] * origin;
            p = p4.start(3);

            cross_prod = v.transpose().cross( (s - p).transpose() );

            J(i,   j) = cross_prod(0);
            J(i+1, j) = cross_prod(1);
            J(i+2, j) = cross_prod(2);
        }
    }

    return J;
}

Vector3d Kinematics::rotation_axis(Matrix4d transformation)
{
    Matrix3d rotation = transformation.block(0, 0, 3, 3);

    // getting the nullspace
    EigenSolver<Matrix3d> eigensolver(rotation);
    EigenSolver<Matrix3d>::EigenvalueType eigenValues;
    EigenSolver<Matrix3d>::EigenvectorType eigenVectors;
    Vector3d nullspace;

    eigenValues = eigensolver.eigenvalues();
    eigenVectors =  eigensolver.eigenvectors();

    // the axis of rotation is equivalent to the nullspace of the rotation matrix,
    // which can be found by searching for an eigenvector with the corresponding
    // eigenvalue of 1
    for (unsigned i = 0; i < eigenValues.size(); ++i) {
        if (eigenValues(i).real() == 1) {
            nullspace = eigenVectors.col(i).real();
        }
    }

    return nullspace;
}

map<string, double> Kinematics::approach_position(BodyPart leg,
                                                  Vector3d target,
                                                  int lambda,
                                                  int max_iter)
{
    // setting up some variable lists
    vector<string> kick_joints = {"HipYawPitch", "HipRoll", "HipPitch", "KneePitch"};
    vector<string> stand_joints = {"HipYawPitch", "HipRoll", "HipPitch", "KneePitch"};

    vector<string> rest_of_body = {"HeadPitch", "HeadYaw", "LShoulderPitch",
                                   "LShoulderRoll", "LElbowYaw", "LElbowRoll",
                                   "RShoulderPitch", "RShoulderRoll", "RElbowYaw",
                                   "RElbowRoll", "LAnkleRoll", "LAnklePitch",
                                   "RAnklePitch", "RAnkleRoll"};

    for (string &joint : kick_joints)
        joint.insert(joint.begin(), leg == RLEG ? 'R' : 'L');
    for (string &joint : stand_joints)
        joint.insert(joint.begin(), leg == RLEG ? 'L' : 'R');

    string end_effector = (leg == LLEG) ? "LAnkleRoll" : "RAnkleRoll";
    BodyPart stand_leg = (leg == LLEG) ? RLEG : LLEG;

    // initial angles
    map<string, double> angles;
    for (string &joint : kick_joints)
      angles[joint] = m_motion_proxy.getAngles(joint, true)[0];
    for (string &joint : stand_joints)
      angles[joint] = m_motion_proxy.getAngles(joint, true)[0];
    for (string &joint : rest_of_body)
      angles[joint] = m_motion_proxy.getAngles(joint, true)[0];

    // put the angles into vector-form as needed by the algorithm
    VectorXd theta(kick_joints.size());
    for (unsigned i = 0; i < kick_joints.size(); ++i)
        theta(i) = angles[kick_joints[i]];

    // save the best result in case the algorithm does not terminate before the
    // maximum number of iterations
    VectorXd best_theta;
    int best_error = 99999;

    Vector4d origin; origin << 0, 0, 0, 1;
    // main loop
    for (int i = 0; i < max_iter; ++i) {
        map<string, Matrix4d> joint_trans;
        Vector3d dX;
        MatrixXd J, Jt;
        VectorXd d_theta;

        joint_trans = get_transformations_dict(stand_leg, false, angles);

        // difference between goal position and end-effector
        dX = target - (joint_trans[end_effector] * origin).start(3);

        int error = dX.norm();
        cout << "Error: " << error << endl; // debug

        if (error < best_error) {
            best_error = error;
            best_theta = theta;
        }

        // target basically reached
        if (best_error < 15)
            break;

        J = get_jacobian(leg, angles, joint_trans);

        // Levenberg-Marquardt method to approximate the inverse of the Jacobian
        Jt = J.transpose();
        d_theta = (Jt * ((J * Jt) + (pow(lambda, 2) * Matrix3d::Identity())).inverse()) * dX;

        // update theta and the joint angle dictionary
        update_theta(theta, d_theta, kick_joints, leg);
        update_angles(angles, kick_joints, theta, stand_joints);
    }

    // put the found angles into a dictionary shape
    map<string, double> result_dict;

    for (unsigned i = 0; i < kick_joints.size(); ++i)
        result_dict[kick_joints[i]] = theta(i);

    return result_dict;
}

map<string, double> Kinematics::change_position(BodyPart leg,
                                                Vector3d offset,
                                                int lambda,
                                                int max_iter)
{
    BodyPart support_leg = (leg == RLEG) ? LLEG : RLEG;
    joint_loc_map joint_locs = get_locations_dict(support_leg);

    Vector3d current_loc, target;
    if (leg == LLEG)
        current_loc = joint_locs["LAnkleRoll"].start(3);
    else
        current_loc = joint_locs["RAnkleRoll"].start(3);

    target = current_loc + offset;

    return approach_position(leg, target, lambda, max_iter);
}

void Kinematics::update_theta(VectorXd &theta,
                              VectorXd d_theta,
                              vector<string> kick_joints,
                              BodyPart leg)
{
    // update the angles
    theta += d_theta;

    // check the boundaries
    for (unsigned i = 0; i < kick_joints.size(); ++i) {
        double min, max, angle;
        string joint = kick_joints[i];
        min = joint_constraints[joint].first;
        max = joint_constraints[joint].second;

        angle = theta(i);

        if (angle < min)
            theta(i) = min;
        else if (angle > max)
            theta(i) = max;
    }
}

void Kinematics::update_angles(map<string, double> &angles,
                               vector<string> joints,
                               VectorXd theta,
                               vector<string> stand_joints)
{
    for (unsigned i = 0; i < joints.size(); ++i)
        angles[joints[i]] = theta(i);

    // update the angles of the standing leg because they might've been changed
    // by a balance controller
    for (unsigned i = 0; i < stand_joints.size(); ++i)
        angles[stand_joints[i]] = m_motion_proxy.getAngles(stand_joints[i], true)[0];
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

map<string, pair<double, double> > Kinematics::joint_constraints =
{
    {"LHipYawPitch", {-1.145303, 0.740810}},
    {"LHipRoll", 	{-0.379472, 0.790477}},
    {"LHipPitch",	{-1.773912, 0.484090}},
    {"LKneePitch",	{-0.092346, 2.112528}},
    {"LAnklePitch",  {-1.189516, 0.922747}},
    {"LAnkleRoll",   {-0.397880, 0.769001}},

    {"RHipYawPitch", {-1.145303, 0.740810}},
    {"RHipRoll", 	{-0.738231, 0.414754}},
    {"RHipPitch",	{-1.772308, 0.485624}},
    {"RKneePitch",	{-0.103083, 2.120198}},
    {"RAnklePitch",  {-1.186448, 0.932056}},
    {"RAnkleRoll",   {-0.785875, 0.388676}}
};

map<string, pair<vector<double>, double> > Kinematics::jointCOM =
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

int main()
{
    Kinematics k("0.0.0.0");

    Vector3d target;
    target << 100, -100, 5;

    k.approach_position(Kinematics::RLEG, target, 5, 300);
}
