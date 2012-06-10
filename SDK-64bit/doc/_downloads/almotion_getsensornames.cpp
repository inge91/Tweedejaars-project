#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_getsensornames pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Gets the list of sensors supported on your robot.
  std::vector<std::string> sensorList = motion.getSensorNames();
  std::cout << "Sensors: " << std::endl;
  for (unsigned int i=0; i<sensorList.size(); i++)
  {
     std::cout << sensorList.at(i) << std::endl;
  }

  return 0;
}
