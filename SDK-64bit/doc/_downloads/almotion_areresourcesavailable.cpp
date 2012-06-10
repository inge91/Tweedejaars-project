#include <iostream>
#include <alproxies/almotionproxy.h>
#include <qi/os.hpp>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_areresourcesavailable pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Setting head stiffness on.
  motion.setStiffnesses("Head", 1.0f);

  // Example showing how to use areResourcesAvailable
  // We will create a task first, so that we see a result
  AL::ALValue names = "HeadYaw";
  AL::ALValue angleLists = 1.0f;
  AL::ALValue timeList   = 3.0f;
  bool isAbsolute        = true;
  motion.post.angleInterpolation(names, angleLists, timeList, isAbsolute);
  qi::os::msleep(100);
  std::cout << "Are resources "<< names << " available?" << std::endl;
  std::cout << motion.areResourcesAvailable(AL::ALValue::array(names)) << std::endl;

  qi::os::sleep(3.0f);

  // Setting head stiffness off.
  motion.setStiffnesses("Head", 0.0f);
  return 0;
}
