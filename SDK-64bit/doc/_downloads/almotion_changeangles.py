import sys
import time
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_changeangles.py IP [PORT]'"
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

proxy.setStiffnesses("Head", 1.0)

# Example showing a slow, relative move of "HeadYaw".
# Calling this multiple times will move the head further.
names            = "HeadYaw"
changes          = 0.5
fractionMaxSpeed = 0.05
proxy.changeAngles(names, changes, fractionMaxSpeed)

time.sleep(2.0)

proxy.setStiffnesses("Head", 0.0)