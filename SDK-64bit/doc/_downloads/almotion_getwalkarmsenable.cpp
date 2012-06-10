#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_getwalkarmsenable pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Example showing how to get the enabled flags for the arms
  AL::ALValue result = motion.getWalkArmsEnable();
  std::cout << "LeftArmEnabled: " << result[0] << std::endl;
  std::cout << "RightArmEnabled: " << result[1] << std::endl;

  return 0;
}
