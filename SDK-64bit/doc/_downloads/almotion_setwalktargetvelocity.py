import sys
import time
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_setwalktargetveclocity.py IP [PORT]'"
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

# Example showing the use of setWalkTargetVelocity
# The parameters are fractions of the maximums
# Here we are asking for full speed forwards
x  = 1.0
y  = 0.0
theta  = 0.0
frequency  = 1.0
proxy.setWalkTargetVelocity(x, y, theta, frequency)
# If we don't send another command, he will walk forever
# Lets make him slow down(step length) and turn after 3 seconds
time.sleep(3)
x = 0.5
theta = 0.6
proxy.setWalkTargetVelocity(x, y, theta, frequency)
# Lets make him slow down(frequency) after 3 seconds
time.sleep(3)
frequency  = 0.5
proxy.setWalkTargetVelocity(x, y, theta, frequency)
# Lets make him stop after 3 seconds
time.sleep(3)
proxy.stopWalk()
# Note that at any time, you can use a walkTo command
# to walk a precise distance. The last command received,
# of velocity or position always wins