#include <iostream>
#include <alproxies/almotionproxy.h>
#include <qi/os.hpp>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_changetransform pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  std::vector<float> stiffness = motion.getStiffnesses("Body");
  if (stiffness[0] < 0.5f) {
    std::cerr << "Warning: following example will have no effect. "
              << "Robot must be stiff and standing." << std::endl;
  }

  // Example showing how to set Torso Transform, using a fraction of max speed
  std::string chainName  = "Torso";
  int space     = 2; // SPACE_NAO
  std::vector<float> transform(12, 0.0f);
  transform[0]  = 1.0f;  // 1.0f, 0.0f, 0.0f, 0.05f
  transform[3]  = 0.05f; // 0.0f, 1.0f, 0.0f, 0.0f
  transform[5]  = 1.0f;  // 0.0f, 0.0f, 1.0f, 0.0f
  transform[10] = 1.0f;
  float fractionMaxSpeed = 0.2f;
  int axisMask  = 63;
  motion.changeTransform(chainName, space, transform, fractionMaxSpeed, axisMask);

  qi::os::sleep(2.0f);

  return 0;
}
