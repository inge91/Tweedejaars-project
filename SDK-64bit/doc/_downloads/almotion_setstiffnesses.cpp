#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_setstiffnesses pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Example showing how to set the stiffness to 1.0.
  // Beware, doing this could be dangerous, it is safer to use the
  // stiffnessInterpolation method which takes a duration parameter.
  std::string names  = "Body";
  // If only one parameter is received, this is applied to all joints
  float stiffnesses  = 1.0f;
  motion.setStiffnesses(names, stiffnesses);

  return 0;
}
