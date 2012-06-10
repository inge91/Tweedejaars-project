import sys
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_wbfootstate.py IP [PORT]'"
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
proxy.wbEnable(True)

# Example showing how to fix the feet.
print "Feet fixed."
stateName = "Fixed" 
supportLeg = "Legs" 
proxy.wbFootState(stateName, supportLeg)

# Example showing how to fix the left leg and constrained in a plane the right leg.
print "Left leg fixed, right leg in a plane."
proxy.wbFootState("Fixed", "LLeg") 
proxy.wbFootState("Plane", "RLeg")

# Example showing how to fix the left leg and keep free the right leg.
print "Left leg fixed, right leg free"
proxy.wbFootState("Fixed", "LLeg") 
proxy.wbFootState("Free", "RLeg")

proxy.wbEnable(False)