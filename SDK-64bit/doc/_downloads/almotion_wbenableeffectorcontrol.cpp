#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_wbenableeffectorcontrol pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Example showing how to active Head tracking.
  std::string effectorName = "Head";
  bool isEnabled = true;
  motion.wbEnableEffectorControl(effectorName, isEnabled);
  std::cout << "Enabled whole body effector " << effectorName << " control"
            << std::endl;

  isEnabled = false;
  motion.wbEnableEffectorControl(effectorName, isEnabled);
  std::cout << "Disabled whole body effector " << effectorName << " control"
            << std::endl;

  return 0;
}
