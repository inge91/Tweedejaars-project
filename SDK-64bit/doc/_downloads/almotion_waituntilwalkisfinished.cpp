#include <iostream>
#include <alproxies/almotionproxy.h>
#include <qi/os.hpp>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_waituntilwalkisfinished pIp"
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

  // Example showing how to use waitUntilWalkIsFinished.
  // Start a walk
  float x = 0.10f;
  float y = 0.0f;
  float theta = 0.0f;
  motion.walkTo(x, y, theta);

  // Wait for it to finish
  motion.waitUntilWalkIsFinished();
  // Then do something else

  return 0;
}
