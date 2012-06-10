import sys
from naoqi import ALProxy
from naoqi import motion

if (len(sys.argv) < 2):
    print "Usage: 'python motion_positioninterpolation.py IP [PORT]'"
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

# Example of a cartesian foot trajectory 
# Warning: Needs a PoseInit before executing 
# Example available: path/to/aldebaran-sdk/examples/ 
#                    python/motion_cartesianFoot.py 
 
space      =  motion.SPACE_NAO 
axisMask   = 63                     # control all the effector's axes
isAbsolute = False
 
# Lower the Torso and move to the side 
effector   = "Torso" 
path       = [0.0, -0.07, -0.03, 0.0, 0.0, 0.0] 
timeList   = 2.0                    # seconds 
proxy.positionInterpolation(effector, space, path, 
                            axisMask, timeList, isAbsolute) 
 
# LLeg motion 
effector   = "LLeg" 
path       = [0.0,  0.06,  0.00, 0.0, 0.0, 0.8] 
timeList   = 2.0            # seconds 
proxy.positionInterpolation(effector, space, path, 
                            axisMask, timeList, isAbsolute)
                            
