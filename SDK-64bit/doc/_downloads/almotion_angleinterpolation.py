import sys
import time
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_angleinterpolation.py IP [PORT]'"
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

# Example showing a single target angle for one joint
# Interpolate the head yaw to 1.0 radian in 1.0 second
names      = "HeadYaw"
angleLists = 1.0
timeLists  = 1.0
isAbsolute = True
proxy.angleInterpolation(names, angleLists, timeLists, isAbsolute)

time.sleep(1.0)

# Example showing a single trajectory for one joint
# Interpolate the head yaw to 1.0 radian and back to zero in 2.0 seconds
names      = "HeadYaw"
#              2 angles
angleLists = [1.0, 0.0]
#              2 times
timeLists  = [1.0, 2.0]
isAbsolute = True
proxy.angleInterpolation(names, angleLists, timeLists, isAbsolute)

time.sleep(1.0)

# Example showing multiple trajectories
names      = ["HeadYaw", "HeadPitch"]
angleLists = [0.5, 0.5]
timeLists  = [1.0, 1.2]
isAbsolute = True
proxy.angleInterpolation(names, angleLists, timeLists, isAbsolute)

# Example showing multiple trajectories
# Interpolate the head yaw to 1.0 radian and back to zero in 2.0 seconds
# while interpolating HeadPitch up and down over a longer period.
names  = ["HeadYaw","HeadPitch"]
# Each joint can have lists of different lengths, but the number of 
# angles and the number of times must be the same for each joint.
# Here, the second joint ("HeadPitch") has three angles, and 
# three corresponding times.
angleLists  = [[1.0, 0.0], [-0.5, 0.5, 0.0]]
timeLists   = [[1.0, 2.0], [ 1.0, 2.0, 3.0]]
isAbsolute  = True
proxy.angleInterpolation(names, angleLists, timeLists, isAbsolute)

proxy.setStiffnesses("Head", 0.0)
