import sys
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_settransform.py IP [PORT]'"
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

# Example showing how to set Torso Transform, using a fraction of max speed
chainName        = "Torso" 
space            = 2 
transform        = [1.0, 0.0, 0.0, 0.00, 
                    0.0, 1.0, 0.0, 0.00, 
                    0.0, 0.0, 1.0, 0.25] # Absolute Position
fractionMaxSpeed = 0.2 
axisMask         = 63 
proxy.setTransform(chainName, space, transform, fractionMaxSpeed, axisMask)