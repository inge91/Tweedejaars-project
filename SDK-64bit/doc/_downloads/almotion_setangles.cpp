#include <iostream>
#include <alproxies/almotionproxy.h>
#include <qi/os.hpp>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_setangles pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  // Example showing how to set angles, using a fraction of max speed
  AL::ALValue names       = AL::ALValue::array("HeadYaw", "HeadPitch");
  AL::ALValue angles      = AL::ALValue::array(0.2f, -0.2f);
  float fractionMaxSpeed  = 0.2f;
  motion.setStiffnesses(names, AL::ALValue::array(1.0f, 1.0f));
  motion.setAngles(names, angles, fractionMaxSpeed);
  qi::os::sleep(1.0f);
  motion.setStiffnesses(names, AL::ALValue::array(0.0f, 0.0f));

  return 0;
}
