import sys
import time
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_setangles.py IP [PORT]'"
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

proxy.setStiffnesses("Head", 0.1)

# Example simulating reactive control
names = "HeadYaw"
angles = 0.3
fractionMaxSpeed = 0.1
proxy.setAngles(names,angles,fractionMaxSpeed)
# wait half a second
time.sleep(0.5)
# change target
angles = 0.0
proxy.setAngles(names,angles,fractionMaxSpeed)
# wait half a second
time.sleep(0.5)
# change target
angles = 0.1
proxy.setAngles(names,angles,fractionMaxSpeed)
