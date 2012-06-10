import sys
import time
from naoqi import ALProxy
import almath

if (len(sys.argv) < 2):
    print "Usage: 'python motion_angleinterpolationreactif.py IP [PORT]'"
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
    
proxy.setStiffnesses("Head", 1.0)

# Head Start to zeros
names             = "Head"
targetAngles      = [0.0, 0.0]
maxSpeedFraction  = 0.2 # Using 20% of maximum joint speed 
proxy.angleInterpolationWithSpeed(names, targetAngles, maxSpeedFraction)

# Example showing a reactive control with time function angleInterpolation
# Goal: after 1.0 second, retarget from 40 to 0 degree: smooth transition

# Interpolate the head yaw to 20 degrees in 2.0 seconds
# With post, angleInterpolation become non-blocking
names      = "HeadYaw"
angleLists = 20.0*almath.TO_RAD
timeLists  = 2.0
isAbsolute = True
proxy.post.angleInterpolation(names, angleLists, timeLists, isAbsolute)
time.sleep(0.5)

# Call getTaskList to have the previous angleInterpolation task number
TaskList = proxy.getTaskList()

# Prepare the next target to 50.0 degrees in 1.0 second
angleLists = 50.0*almath.TO_RAD
timeLists  = 1.0
proxy.post.angleInterpolation(names, angleLists, timeLists, isAbsolute)
time.sleep(0.5)

# Kill the first angleInterpolation (go to 40.0 degrees), the second start
# smoothly from the current joint position and velocity (go to 0 degrees)
proxy.killTask(TaskList[0][1])

time.sleep(2.0)
proxy.setStiffnesses("Head", 0.0)
