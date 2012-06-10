#include <iostream>
#include <alproxies/almotionproxy.h>
#include <qi/os.hpp>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_setposition pIp"
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

  // Example showing how to set Torso Position, using a fraction of max speed
  std::string chainName  = "Torso";
  int space              = 2;
  std::vector<float> position(6, 0.0f); // Absolute Position
  position[2] = 0.25f;
  float fractionMaxSpeed = 0.2f;
  int axisMask           = 63;
  motion.setPosition(chainName, space, position, fractionMaxSpeed, axisMask);
  qi::os::sleep(2.0f);

  return 0;
}
