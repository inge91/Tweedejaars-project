#include "p_controller.h"

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <boost/numeric/ublas/matrix.hpp>

using namespace std;
using boost::numeric::ublas::matrix;

PController::PController(string standing_leg,
                         string ip, double gain) :
    m_com(ip, 9559), m_mp(ip, 9559)
{
    m_leg_prefix = standing_leg == "LLeg" ? "L" : "R";
    m_leg = standing_leg;
    m_gain = gain;
}

void PController::run()
{
    // main loop
    while (true) {
        pair<double, double> error = this->error(m_com.get_CoM(m_leg));
        double err_x = error.first;
        double err_y = error.second;

        // output = error * proportional gain
        pair<double, double> p_out = error;
        double p_x = m_gain * err_x;
        double p_y = m_gain * err_y;

        // torso to the front -> positive pitch angle
        double pitch_angle = p_y * (m_leg == "LLeg" ? -1 : 1);
        // roll is positive to the outside direction
        double roll_angle = p_x * -1;//(m_leg == "LLeg" ? -1 : 1);

        cout << "HipPitch: " << pitch_angle << endl;
        cout << "HipRoll: " << roll_angle << endl;

        // actuate!
        m_mp.changeAngles(m_leg_prefix + "HipPitch", pitch_angle, 1);
        m_mp.changeAngles(m_leg_prefix + "HipRoll", roll_angle, 1);
    }
}

pair<double, double> PController::error(matrix<double> com_loc)
{
    vector<vector<double> > polygon_v =
    {
        {0},
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
    PController cont(argv[1], argv[2], atof(argv[3]));
    cont.run();
}
