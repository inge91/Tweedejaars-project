#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_walkisactive pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Example showing how to use walk is active.
  bool walkIsActive = motion.walkIsActive();

  std::cout << "Walk is active: " << walkIsActive << std::endl;

  return 0;
}
