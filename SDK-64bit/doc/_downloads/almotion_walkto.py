import sys
import math
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_walkto.py IP [PORT]'"
    sys.exit(1)

IP = sys.argv[1]
PORT = 9559
if (len(sys.argv) > 2):
    PORT = sys.argv[2]
try:
    proxy = ALProxy("ALMotion", IP, PORT)
except Exception,e:
    print "Could not create proxy to ALMotion"
    print "Error was: ",e
    sys.exit(1)

proxy.stiffnessInterpolation("Body", 1.0, 0.1)
proxy.walkInit()

# Example showing the walkTo command 
# The units for this command are meters and radians 
x  = 0.2 
y  = 0.2 
theta  = math.pi/2
proxy.walkTo(x, y, theta) 
# Will block until walk Task is finished

########
# NOTE #
########
# If walkTo() method does nothing on the robot,
# please refer to special walk protection in the
# setWalkTargetVelocity() method description below.