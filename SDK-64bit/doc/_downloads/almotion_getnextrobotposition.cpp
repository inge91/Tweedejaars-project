#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_getnextrobotposition pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Example showing how to get a simplified next robot position in world.
  std::vector<float> result = motion.getNextRobotPosition();

  std::cout << "Next robot position is: " << result << std::endl;

  return 0;
}
