#include <iostream>
#include <alproxies/almotionproxy.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: motion_walkto pIp"
              << std::endl;
    return 1;
  }
  const std::string pIp = argv[1];

  AL::ALMotionProxy motion(pIp);

  motion.setStiffnesses("Body", 1.0f);
  motion.walkInit();

  // Example showing the walkTo command
  // as length of path is less than 0.4m
  // the path will be an SE3 interpolation
  // The units for this command are meters and radians
  float x  = 0.2f;
  float y  = 0.2f;
  // pi/2 anti-clockwise (90 degrees)
  float theta = 1.5709f;
  motion.walkTo(x, y, theta);
  // Will block until walk Task is finished

  // Example showing the walkTo command
  // as length of path is more than 0.4m
  // the path will be follow a dubins curve
  // The units for this command are meters and radians
  x  = -0.1f;
  y  = -0.7f;
  theta  = 0.0f;
  motion.walkTo(x, y, theta);

  return 0;
}
