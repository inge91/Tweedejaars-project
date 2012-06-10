#include <qi/os.hpp>
#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_killtask pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  AL::ALValue names      = "HeadYaw";
  AL::ALValue angleLists = 1.0f;
  AL::ALValue timeLists  = 10.0f;
  bool isAbsolute        = true;
  motion.setStiffnesses(names, 1.0f);
  motion.post.angleInterpolation(names, angleLists, timeLists, isAbsolute);
  qi::os::msleep(3000);

  std::cout << "Killing task..." << std::endl;
  AL::ALValue TaskList = motion.getTaskList();
  int uiMotion = TaskList[0][1];
  motion.killTask(uiMotion);
  std::cout << "Task killed." << std::endl;

  motion.setStiffnesses(names, 0.0f);

  return 0;
}
