import sys
import time
from naoqi import ALProxy
import almath as m #python's wrapping of almath

if (len(sys.argv) < 2):
    print "Usage: 'python motion_getnextrobotposition.py IP [PORT]'"
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
result = proxy.getNextRobotPosition() 
print "Next Robot Position", result

# Example showing how to use this information to know the robot's diplacement
# during the walk process.

# Make the robot walk
proxy.post.walkTo(0.6,0.0,0.5)  #No blocking due to post called
time.sleep(1.0)
initRobotPosition = m.Pose2D(m.vectorFloat(proxy.getNextRobotPosition())) 

# Make the robot walk
proxy.walkTo(0.1,0.0,0.2)

endRobotPosition = m.Pose2D(m.vectorFloat(proxy.getNextRobotPosition())) 

# Compute robot's' displacement
robotMove = m.pose2DInverse(initRobotPosition)*endRobotPosition
print "Robot Move :", robotMove
