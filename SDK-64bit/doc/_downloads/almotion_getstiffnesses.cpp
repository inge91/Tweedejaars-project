#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_getstiffnesses pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Example showing how to get the Body stiffnesses
  std::string jointName = "Body";
  std::vector<float> stiffnesses = motion.getStiffnesses(jointName);

  std::cout << jointName << "stiffnesses: " << stiffnesses << std::endl;

  return 0;
}
