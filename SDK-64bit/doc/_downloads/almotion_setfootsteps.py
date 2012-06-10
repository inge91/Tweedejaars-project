import sys
import time
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_setfootsteps.py IP [PORT]'"
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
    
proxy.setStiffnesses("Body", 1.0)
proxy.walkInit()

# A small step forwards and anti-clockwise with the left foot 
legName  = ["LLeg"]
X        = 0.2
Y        = 0.1
Theta    = 0.3
footSteps = [[X, Y, Theta]]
timeList = [0.6]
clearExisting = False
proxy.setFootSteps(legName, footSteps, timeList, clearExisting)

time.sleep(1.0)

# A small step forwards and anti-clockwise with the left foot 
legName = ["LLeg", "RLeg"]
X       = 0.2
Y       = 0.1
Theta   = 0.3
footSteps = [[X, Y, Theta], [X, -Y, Theta]]
timeList = [0.6, 1.2]
clearExisting = False
proxy.setFootSteps(legName, footSteps, timeList, clearExisting)
