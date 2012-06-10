#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_wbenablebalanceconstraint pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Example showing how to Constraint Balance Motion.
  bool isEnable = true;
  std::string supportLeg  = "Legs";
  motion.wbEnableBalanceConstraint(isEnable, supportLeg);
  std::cout << "Enabled whole body balance constraint on " << supportLeg << std::endl;

  isEnable = false;
  motion.wbEnableBalanceConstraint(isEnable, supportLeg);
  std::cout << "Disabled whole body balance constraint on " << supportLeg << std::endl;

  return 0;
}
