#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_wbgotobalance pIp"
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

  // Example showing how to com go to LLeg.
  std::string supportLeg = "LLeg";
  float duration         = 2.0f;
  motion.wbGoToBalance(supportLeg, duration);

  isEnabled = false;
  motion.wbEnable(isEnabled);

  return 0;
}
