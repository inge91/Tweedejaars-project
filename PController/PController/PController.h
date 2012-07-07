#ifndef PCONTROLLER_H
#define PCONTROLLER_H
#include <string>
#endif // PCONTROLLER_H


class PController{
private:
    string leg_prefix;
    string leg;
    int com;           ///////////
    int gain;
    int mp;             /////
    std::string joints[5] = {"HeadYaw", "HeadPitch", "LShoulderPitch", "LShoulderRoll",
          "LElbowYaw", "LElbowRoll", "LHipYawPitch", "LHipRoll",
          "LHipPitch", "LKneePitch", "LAnklePitch", "LAnkleRoll",
          "RHipYawPitch", "RHipRoll", "RHipPitch", "RKneePitch",
          "RAnklePitch", "RAnkleRoll", "RShoulderPitch", "RShoulderRoll",
          "RElbowYaw", "RElbowRoll"};
    int polygon[4] = {3,0,0,1}
}
