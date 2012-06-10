#include <iostream>
#include <alproxies/almotionproxy.h>
#include <qi/os.hpp>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_angleinterpolation pIp" << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Setting head stiffness on.
  motion.setStiffnesses("Head", 1.0f);

  // Example showing a single target angle for one joint
  // Interpolate the head yaw to 1.0 radian in 1.0 second
  AL::ALValue names      = "HeadYaw";
  AL::ALValue angleLists = 1.0f;
  AL::ALValue timeLists  = 1.0f;
  bool isAbsolute        = true;
  std::cout << "Step 1: single target angle for one joint" << std::endl;
  motion.angleInterpolation(names, angleLists, timeLists, isAbsolute);

  qi::os::sleep(1.0f);

  // Example showing a single trajectory for one joint
  // Interpolate the head yaw to 1.0 radian and back to zero in 2.0 seconds
  names      = "HeadYaw";
  angleLists.clear();
  angleLists = AL::ALValue::array(1.0f, 0.0f);
  timeLists.clear();
  timeLists  = AL::ALValue::array(1.0f, 2.0f);
  isAbsolute = true;
  std::cout << "Step 2: single trajectory for one joint" << std::endl;
  motion.angleInterpolation(names, angleLists, timeLists, isAbsolute);

  qi::os::sleep(1.0f);

  // Example showing multiple trajectories
  // Interpolate the HeadYaw to 1.0 radian and back to zero in 2.0 seconds
  // while interpolating HeadPitch up and down over a longer period.
  names = AL::ALValue::array("HeadYaw", "HeadPitch");
  // Each joint can have lists of different lengths, but the number of
  // angles and the number of times must be the same for each joint.
  // Here, the second joint ("HeadPitch") has three angles, and
  // three corresponding times.
  angleLists.clear();
  angleLists.arraySetSize(2);
  angleLists[0] = AL::ALValue::array(1.0f, 0.0f);
  angleLists[1] = AL::ALValue::array(-0.5f, 0.5f, 0.0f);

  timeLists.clear();
  timeLists.arraySetSize(2);
  timeLists[0] = AL::ALValue::array(1.0f, 2.0f);
  timeLists[1] = AL::ALValue::array(1.0f, 2.0f, 3.0f);

  isAbsolute = true;
  std::cout << "Step 3: multiple trajectories" << std::endl;
  motion.angleInterpolation(names, angleLists, timeLists, isAbsolute);

  // Setting head stiffness off.
  motion.setStiffnesses("Head", 0.0f);

  return 0;
}
