import sys
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_getcom.py IP [PORT]'"
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

# Example showing how to get the COM position of "HeadYaw". 
pName = "HeadYaw" 
pSpace = 0 # SPACE_TORSO 
pUseSensors = False 
pos = proxy.getCOM(pName, pSpace, pUseSensors) 
print "HeadYaw COM Position: x = ", pos[0], " y:", pos[1], " z:", pos[2]