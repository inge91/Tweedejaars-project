#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_getmass pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Example showing how to get the mass of "HeadYaw".
  std::string pName = "HeadYaw";
  float mass = motion.getMass(pName);

  std::cout << "Mass on " << pName << " is " << mass << std::endl;

  return 0;
}
