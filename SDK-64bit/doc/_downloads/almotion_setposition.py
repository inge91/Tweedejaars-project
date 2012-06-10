import sys
import time
from naoqi import ALProxy
from naoqi import motion

if (len(sys.argv) < 2):
    print "Usage: 'python motion_setposition.py IP [PORT]'"
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

# Example showing how to set LArm Position, using a fraction of max speed  
chainName = "LArm" 
space     = motion.SPACE_TORSO 
useSensor = False 
 
# Get the current position of the chainName in the same space 
current = proxy.getPosition(chainName, space, useSensor) 
 
target  = [ 
current[0] + 0.1, 
current[1] + 0.1, 
current[2] + 0.1, 
current[3] + 0.0, 
current[4] + 0.0, 
current[5] + 0.0] 
 
fractionMaxSpeed = 0.5 
axisMask         = 7 # just control position 
 
proxy.setPosition(chainName, space, target, fractionMaxSpeed, axisMask)

time.sleep(1.0)

# Example showing how to set Torso Position, using a fraction of max speed
chainName        = "Torso" 
space            = 2 
position         = [0.0, 0.0, 0.25, 0.0, 0.0, 0.0] # Absolute Position
fractionMaxSpeed = 0.2 
axisMask         = 63 
proxy.setPosition(chainName, space, position, fractionMaxSpeed, axisMask)