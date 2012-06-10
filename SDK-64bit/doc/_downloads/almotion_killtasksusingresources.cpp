#include <qi/os.hpp>
#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_killtaskusingresources pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Example showing how to killTasksUsingResources
  // We will create a task first, so that we see a result
  AL::ALValue names      = "HeadYaw";
  AL::ALValue angleLists = 1.0f;
  AL::ALValue timeList   = 3.0f;
  bool isAbsolute        = true;
  motion.setStiffnesses(names, 1.0f);
  motion.post.angleInterpolation(names, angleLists, timeList, isAbsolute);
  qi::os::msleep(1000);
  std::cout << "Killing task..." << std::endl;
  motion.killTasksUsingResources(AL::ALValue::array(names));
  std::cout << "Task killed." << std::endl;

  motion.setStiffnesses(names, 0.0f);

  return 0;
}
