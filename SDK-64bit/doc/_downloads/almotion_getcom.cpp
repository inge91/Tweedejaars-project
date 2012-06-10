#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_getcom pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Example showing how to get the COM of "HeadYaw".
  std::string pName = "HeadYaw";
  int pSpace = 0; // SPACE_TORSO
  bool pUseSensors = false;
  std::vector<float> pos = motion.getCOM(pName, pSpace, pUseSensors);

  std::cout << pName << " COM position: " << std::endl;
  std::cout << "x: " << pos[0] << "; y: " << pos[1] << "; z: " << pos[2]
            << std::endl;

  return 0;
}
