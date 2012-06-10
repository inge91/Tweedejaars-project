#include <qi/os.hpp>
#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_gettasklist pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Example showing how to get the current task list
  // We will create a task first, so that we see a result
  AL::ALValue names      = "HeadYaw";
  AL::ALValue angleLists = 1.0f;
  AL::ALValue timeList   = 3.0f;
  bool isAbsolute        = true;
  motion.setStiffnesses(names, 1.0f);
  motion.post.angleInterpolation(names, angleLists, timeList, isAbsolute);
  qi::os::msleep(100);
  std::cout << "Tasklist: " << motion.getTaskList() << std::endl;
  qi::os::sleep(3.0f);
  motion.setStiffnesses(names, 0.0f);

  return 0;
}
