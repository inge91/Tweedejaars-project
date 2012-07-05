/*
 * Copyright (c) 2012 Aldebaran Robotics. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the COPYING file.
 */
#include <iostream>
#include <boost/numeric/ublas/io.hpp>
#include <alerror/alerror.h>

#include "com.h"

using namespace std;
using boost::numeric::ublas::matrix;
using boost::numeric::ublas::identity_matrix;

CenterOfMass::CenterOfMass(string ip_address, int port) :
    m_motion_proxy(ip_address, port)
{
}

matrix<double> CenterOfMass::translation_matrix(string previous, string current)
{
    vector<double> offsets;

    if (previous == "None") {
        offsets[0] = 0;
        offsets[1] = 0;
        offsets[2] = 0;
    } else {
        //pair<vector<double>, double> j_off = CenterOfMass::jointOffsets[pair<string, string>(previous, current)];
        //offsets = j_off.first;
    }

    vector<vector<double> > mat =
    {
        {1, 2, 3},
        {4, 5, 6}
    };

    return matrix<double>(4, 4);
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
    std::vector<vector<double> > vec =
    { {1, 2, 3},
      {4, 5, 6} };

    std::cout << com.vec_to_mat(vec) << std::endl;

    try {
        std::cout << "reached try block" << std::endl;
        AL::ALMotionProxy mp("0.0.0.0", 9559);
        cout << mp.getAngles("RKneePitch", true) << std::endl;
    } catch (const AL::ALError &e) {
        std::cout << "caught error" << std::endl;
    }
}

// the data
map<string, pair<vector<double>, double> > CenterOfMass::jointCOM =
{
    {"RAnkleRoll",      { {25.40, -3.32, -32.41}, 0.16175}},
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
