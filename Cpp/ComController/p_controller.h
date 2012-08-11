#ifndef PCONTROLLER_H
#define PCONTROLLER_H

#include <string>
#include <map>
#include <eigen2/Eigen/Core>
#include <alproxies/almotionproxy.h>
#include "kinematics.h"

using namespace std;
USING_PART_OF_NAMESPACE_EIGEN

class PController
{
/* methods */
public:
    // constructor
    PController(Kinematics::BodyPart standing_leg, string ip,
                double gain=0.0005,
                double threshold=5);

    // main loop that balances the Nao
    void run();

private:
    // calculates the error of a position
    pair<double, double> error(Vector4d com_loc);

/* fields */
public:
    static vector<string> joints;
private:
    AL::ALMotionProxy m_mp;
    string m_leg_prefix;
    Kinematics::BodyPart m_leg;
    Kinematics m_kinematics;
    double m_gain;
    double m_threshold;
};

#endif
