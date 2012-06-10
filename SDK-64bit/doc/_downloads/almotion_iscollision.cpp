#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_iscollision pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Example showing how to get the collision state
  std::string pChainName = "LArm";
  std::string collisionState = motion.isCollision(pChainName);

  std::cout << pChainName << " collision state: " << collisionState << std::endl;
  return 0;
}
