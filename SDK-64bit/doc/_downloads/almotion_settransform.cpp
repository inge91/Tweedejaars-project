#include <iostream>
#include <alproxies/almotionproxy.h>
#include <qi/os.hpp>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_settransform pIp"
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

  // Example showing how to set Torso Transform, using a fraction of max speed
  std::string chainName  = "Torso";
  int space              = 2;
  std::vector<float> transform(12, 0.0f); // Absolute Position
  transform[0]  = 1.0f;  // 1.0f, 0.0f, 0.0f, 0.00f
  transform[5]  = 1.0f;  // 0.0f, 1.0f, 0.0f, 0.00f
  transform[10] = 1.0f;  // 0.0f, 0.0f, 1.0f, 0.25f
  transform[11] = 0.25f;
  float fractionMaxSpeed = 0.2f;
  int axisMask           = 63;
  motion.setTransform(chainName, space, transform, fractionMaxSpeed, axisMask);
  qi::os::sleep(3.0f);

  return 0;
}
