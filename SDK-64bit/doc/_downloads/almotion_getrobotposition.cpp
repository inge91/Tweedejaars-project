#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_getrobotposition pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Example showing how to get a simplified robot position in world.
  bool useSensorValues = false;
  std::vector<float> result = motion.getRobotPosition(useSensorValues);

  std::cout << "Robot position is: " << result << std::endl;

  return 0;
}
