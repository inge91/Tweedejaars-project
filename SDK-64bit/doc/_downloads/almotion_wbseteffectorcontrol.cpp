#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_wbseteffectorcontrol pIp"
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

  bool isEnabled = true;
  motion.wbEnable(isEnabled);

  // Example showing how to set orientation target for Head tracking.
  std::string effectorName = "Head";
  AL::ALValue targetCoordinate = AL::ALValue::array(0.1f, 0.0f, 0.0f);
  motion.wbSetEffectorControl(effectorName, targetCoordinate);

  isEnabled = false;
  motion.wbEnable(isEnabled);

  return 0;
}
