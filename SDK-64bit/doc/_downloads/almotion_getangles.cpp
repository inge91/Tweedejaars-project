#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_getangles pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Example that finds the difference between the command and sensed angles.
  std::string names = "Body";
  bool useSensors   = false;
  std::vector<float> commandAngles = motion.getAngles(names, useSensors);
  std::cout << "Command angles: " << commandAngles << std::endl;
  useSensors = true;
  std::vector<float> sensorAngles = motion.getAngles(names, useSensors);
  std::cout << "Sensor angles: " << sensorAngles << std::endl;

  return 0;
}
