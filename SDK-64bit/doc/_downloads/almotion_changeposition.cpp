#include <iostream>
#include <alproxies/almotionproxy.h>
#include <qi/os.hpp>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_changeposition pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Example showing how to move forward (2cm) "LArm".
  std::string effectorName  = "LArm";
  int space                 = 2; // SPACE_NAO
  std::vector<float> positionChange(6, 0.0f);
  positionChange[0] = 0.02f;
  float fractionMaxSpeed    = 0.5f;
  int axisMask              = 7;
  // Setting effector stiffness on.
  motion.setStiffnesses(effectorName, 1.0f);
  motion.changePosition(effectorName, space, positionChange, fractionMaxSpeed, axisMask);

  qi::os::sleep(1.0f);

  // Setting left arm stiffness on.
  motion.setStiffnesses(effectorName, 0.0f);

  return 0;
}
