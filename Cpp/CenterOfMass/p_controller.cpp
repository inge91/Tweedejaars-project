#include "p_controller.h"

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <boost/numeric/ublas/matrix.hpp>

using namespace std;
using boost::numeric::ublas::matrix;

PController::PController(string standing_leg, string ip,
                         double gain,
                         double threshold) :
    m_com(ip, 9559), m_mp(ip, 9559)
{
    m_leg_prefix = standing_leg == "LLeg" ? "L" : "R";
    m_leg = standing_leg;
    m_gain = gain;
    m_threshold = threshold;
}

void PController::run()
{
    // main loop
    while (true) {
        pair<double, double> error = this->error(m_com.get_CoM(m_leg));
        double error_x = error.first;
        double error_y = error.second;

        if (error_x < m_threshold && error_x > -m_threshold)
            error_x = 0;
        if (error_y < m_threshold && error_y > -m_threshold)
            error_y = 0;

        if ((!error_x) && (!error_y))
            continue;

        // output = error * proportional gain
        double p_out_x = m_gain * error_x;
        double p_out_y = m_gain * error_y;

        vector<float> angles = m_mp.getAngles("Body", true);
        map<string, double> cur_joints;

        for (unsigned i = 0; i < PController::joints.size(); ++i) {
            cur_joints[PController::joints[i]] = angles[i];
        }

        // looking for the best course of action
        double best_pangle = 0;
        double best_rangle = 0;
        double best_com_error = 999;
        vector<double> pitch_range = {0, p_out_x * (m_leg == "LLeg" ? -1 : 1)};
        vector<double> roll_range = {0, p_out_y * (m_leg == "LLeg" ? 1 : 1)};

        for (double &pitch_angle : pitch_range) {
            for (double &roll_angle : roll_range) {
                map<string, double> js(cur_joints);
                js[m_leg_prefix + "AnkleRoll"] += roll_angle;
                js[m_leg_prefix + "AnklePitch"] += pitch_angle;

                pair<double, double> com_err = this->error(m_com.get_CoM(m_leg, false, js));
                double abs_err = abs(com_err.first) + abs(com_err.second);

                if (abs_err < best_com_error) {
                    best_com_error = abs_err;
                    best_pangle = pitch_angle;
                    best_rangle = roll_angle;
                }
            }
        }

        // actuate!
        m_mp.changeAngles(m_leg_prefix + "AnkleRoll", best_rangle, 1);
        m_mp.changeAngles(m_leg_prefix + "AnklePitch", best_pangle, 1);
    }
}

pair<double, double> PController::error(matrix<double> com_loc)
{
    vector<vector<double> > polygon_v =
    {
        {3},
        {0},
        {0},
        {1}
    };

    matrix<double> polygon = CenterOfMass::vec_to_mat(polygon_v);
    matrix<double> diff = polygon - com_loc;

    return pair<double, double>(diff(0, 0), diff(1, 0));
}

vector<string> PController::joints =
{
    "HeadYaw", "HeadPitch", "LShoulderPitch", "LShoulderRoll",
    "LElbowYaw", "LElbowRoll", "LHipYawPitch", "LHipRoll",
    "LHipPitch", "LKneePitch", "LAnklePitch", "LAnkleRoll",
    "RHipYawPitch", "RHipRoll", "RHipPitch", "RKneePitch",
    "RAnklePitch", "RAnkleRoll", "RShoulderPitch", "RShoulderRoll",
    "RElbowYaw", "RElbowRoll"
};

int main(int argc, char *argv[])
{
    PController cont(argv[1], argv[2], atof(argv[3]), atof(argv[4]));
    cont.run();
}
