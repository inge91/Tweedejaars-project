#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_positioninterpolation pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  std::vector<float> stiffnesses = motion.getStiffnesses("Body");
  if (stiffnesses[0] < 0.5f) {
    std::cerr << "Warning: this example will have no effect. "
              << "Robot must be stiff and standing." << std::endl;
    return 1;
  }

  // Example of a cartesian foot trajectory
  // Warning: Needs a PoseInit before executing
  int space       =  2; // SPACE_NAO
  int axisMask    = 63; // control all the effector's axes
  bool isAbsolute = false;

  // Lower the Torso and move to the side
  std::string effector = "Torso";
  AL::ALValue path     = AL::ALValue::array(0.0f, -0.07f, -0.03f, 0.0f, 0.0f, 0.0f);
  AL::ALValue timeList = 2.0f; // seconds
  motion.positionInterpolation(effector, space, path,
                              axisMask, timeList, isAbsolute);

  // LLeg motion
  effector   = "LLeg";
  path       = AL::ALValue::array(0.0f,  0.06f,  0.00f, 0.0f, 0.0f, 0.8f);
  timeList   = 2.0f; // seconds
  motion.positionInterpolation(effector, space, path,
                              axisMask, timeList, isAbsolute);

  return 0;
}
