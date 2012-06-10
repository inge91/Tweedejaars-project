#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_getlimits pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Example showing how to get the limits for the whole body
  std::string name = "Body";
  std::vector<std::string> jointNames = motion.getJointNames(name);
  AL::ALValue limits = motion.getLimits(name);
  for (unsigned int i=0; i<limits.getSize(); i++)
  {
    std::cout << " Joint name " << jointNames[i]
              << " MinAngle " << limits[i][0] << " rad"
              << " MaxAngle " << limits[i][1] << " rad"
              << " MaxChange " << limits[i][2] << " rad.s-1"
              << std::endl;
  }

  return 0;
}
