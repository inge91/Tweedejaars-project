#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_getrobotconfig pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Example showing how to get the robot config
  AL::ALValue robotConfig = motion.getRobotConfig();
  for (unsigned int i=0; i<robotConfig[0].getSize(); i++)
  {
    std::cout << robotConfig[0][i] << ": " << robotConfig[1][i] << std::endl;
  }

  return 0;
}
