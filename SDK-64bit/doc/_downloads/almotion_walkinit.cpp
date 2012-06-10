#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_walkinit pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  std::vector<float> stiffnesses = motion.getStiffnesses("Body");
  if (stiffnesses[0] < 0.5f) {
    std::cerr << "Warning: this example will have no effect. "
              << "Robot must be stiff and standing." << std::endl;
    return 1;
  }

  // Example showing how Initialize walk process.
  motion.walkInit();

  return 0;
}
