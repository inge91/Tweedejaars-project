#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_wbenable pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Example showing how to active Whole Body Balancer.
  bool isEnabled = true;
  motion.wbEnable(isEnabled);
  std::cout << "Whole body enabled." << std::endl;

  isEnabled = false;
  motion.wbEnable(isEnabled);
  std::cout << "Whole body disabled." << std::endl;

  return 0;
}
