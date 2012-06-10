import sys
import time
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_walkisactive.py IP [PORT]'"
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

# Example showing how to use walk is active. 
# start a 0.2 meter walk 
proxy.post.walkTo(0.2, 0.0, 0.0)

while proxy.walkIsActive(): 
    # do something
    print "Walk is active"

# sleep a little 
time.sleep(1) 

# when finished do something else