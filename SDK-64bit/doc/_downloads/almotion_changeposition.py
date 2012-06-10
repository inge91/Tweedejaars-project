import sys
import time
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_changeposition.py IP [PORT]'"
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
    
proxy.setStiffnesses("LArm", 1.0)

# Example showing how to move forward (2cm) "LArm". 
effectorName     = "LArm" 
space            = 2 # SPACE_NAO 
positionChange   = [0.05, 0.0, 0.0, 0.0, 0.0, 0.0] 
fractionMaxSpeed = 0.5 
axisMask         = 7 
proxy.changePosition(effectorName, space, positionChange, fractionMaxSpeed, axisMask)

time.sleep(1.0)

proxy.setStiffnesses("LArm", 0.0)