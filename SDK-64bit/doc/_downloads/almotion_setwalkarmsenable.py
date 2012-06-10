import sys
import time
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_setwalkarmsenable.py IP [PORT]'"
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

x          = 0.6
y          = 0.0
theta      = 0.0
frequency  = 1.0
proxy.setWalkTargetVelocity(x, y, theta, frequency)

time.sleep(1.0)

# Example showing how to disable left arm motions during a walk
leftArmEnable  = False
rightArmEnable  = True
proxy.setWalkArmsEnable(leftArmEnable, rightArmEnable)
print "Disabled left arm"

# disable also right arm motion after 1 seconds
time.sleep(1.0)
rightArmEnable  = False
proxy.setWalkArmsEnable(leftArmEnable, rightArmEnable)
print "Disabled right arm"

time.sleep(1.0)

proxy.stopWalk()

leftArmEnable  = True
rightArmEnable  = True
proxy.setWalkArmsEnable(leftArmEnable, rightArmEnable)
