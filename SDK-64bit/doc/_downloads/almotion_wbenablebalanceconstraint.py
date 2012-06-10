import sys
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_wbenablebalanceconstraint.py IP [PORT]'"
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

# Example showing how to Constraint Balance Motion. 
isEnable   = True 
supportLeg = "Legs" 
proxy.wbEnableBalanceConstraint(isEnable, supportLeg)

proxy.wbEnable(False)