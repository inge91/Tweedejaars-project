import sys
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_getjointnames.py IP [PORT]'"
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

# Example showing how to get the names of all the joints in the body. 
bodyNames = proxy.getJointNames("Body")
print "Body: " + str(bodyNames)

# Example showing how to get the names of all the joints in the left leg. 
leftLegJointNames = proxy.getJointNames("LLeg")
print "LLed: " + str(bodyNames)