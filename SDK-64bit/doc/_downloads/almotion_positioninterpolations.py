import sys
from naoqi import ALProxy
from naoqi import motion

if (len(sys.argv) < 2):
    print "Usage: 'python motion_positioninterpolations.py IP [PORT]'"
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

# Example showing how to use positionInterpolations 
space        = motion.SPACE_NAO 
isAbsolute   = False 
 
# Motion of Arms with block process 
effectorList = ["LArm", "RArm"] 
axisMaskList = [motion.AXIS_MASK_VEL, motion.AXIS_MASK_VEL] 
timeList     = [[1.0], [1.0]]         # seconds 
pathList     = [[[0.0, -0.04, 0.0, 0.0, 0.0, 0.0]], 
                [[0.0,  0.04, 0.0, 0.0, 0.0, 0.0]]] 
proxy.positionInterpolations(effectorList, space, pathList, 
                             axisMaskList, timeList, isAbsolute) 
 
# Motion of Arms and Torso with block process 
effectorList = ["LArm", "RArm", "Torso"] 
axisMaskList = [motion.AXIS_MASK_VEL, 
                motion.AXIS_MASK_VEL, 
                motion.AXIS_MASK_ALL] 
timeList    = [[4.0], 
                [4.0], 
                [1.0, 2.0, 3.0, 4.0]] # seconds 
dx           = 0.03                   # translation axis X (meters) 
dy           = 0.04                   # translation axis Y (meters) 
pathList     = [[[0.0, 0.0, 0.0, 0.0, 0.0, 0.0]], 
                [[0.0, 0.0, 0.0, 0.0, 0.0, 0.0]], 
                [[0.0, +dy, 0.0, 0.0, 0.0, 0.0], # point 1 
                 [-dx, 0.0, 0.0, 0.0, 0.0, 0.0], # point 2 
                 [0.0, -dy, 0.0, 0.0, 0.0, 0.0], # point 3 
                 [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]] # point 4 
               ] 
proxy.positionInterpolations(effectorList, space, pathList, 
                                 axisMaskList, timeList, isAbsolute)