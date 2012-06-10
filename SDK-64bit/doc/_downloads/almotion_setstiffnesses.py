import sys
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_setstiffnesses.py IP [PORT]'"
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

# Example showing how to set the stiffness to 1.0.
# Beware, doing this could be dangerous, it is safer to use the 
#   stiffnessInterpolation method which takes a duration parameter.
names  = 'Body'
# If only one parameter is received, this is applied to all joints
stiffnesses  = 1.0
proxy.setStiffnesses(names, stiffnesses)