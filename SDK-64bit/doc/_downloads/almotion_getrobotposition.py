import sys
from naoqi import ALProxy
import almath

if (len(sys.argv) < 2):
    print "Usage: 'python motion_getrobotposition.py IP [PORT]'"
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

# Example showing how to get a simplified robot position in world. 
useSensorValues = False 
result = proxy.getRobotPosition(useSensorValues) 
print "Robot Position", result

# Example showing how to use this information to know the robot's diplacement. 
useSensorValues = False 
initRobotPosition = almath.Pose2D(almath.vectorFloat(proxy.getRobotPosition(useSensorValues))) 

# Make the robot walk
proxy.walkTo(0.1,0.0,0.2)

endRobotPosition = almath.Pose2D(almath.vectorFloat(proxy.getRobotPosition(useSensorValues))) 

# Compute robot's' displacement
robotMove = almath.pose2DInverse(initRobotPosition)*endRobotPosition
print "Robot Move :", robotMove