import sys
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

# Simple command for the HeadYaw joint at 10% max speed
names            = "HeadYaw"
angles           = 0.2
fractionMaxSpeed = 0.1
proxy.setAngles(names,angles,fractionMaxSpeed)
