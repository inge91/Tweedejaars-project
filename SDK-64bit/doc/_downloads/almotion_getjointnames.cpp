#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_getjointnames pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Example showing how to get the names of all the joints in the body.
  std::vector<std::string> bodyNames = motion.getJointNames("Body");
  std::cout << "All joints in Body: " << std::endl;
  std::cout << bodyNames << std::endl;

  // Example showing how to get the names of all the joints in the left leg.
  std::vector<std::string> leftLegJointNames = motion.getJointNames("LLeg");
  std::cout << "All joints in LLeg: " << std::endl;
  std::cout << leftLegJointNames << std::endl;

  return 0;
}
