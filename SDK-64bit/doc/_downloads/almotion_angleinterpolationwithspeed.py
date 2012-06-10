import sys
import time
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_angleinterpolationwithspeed.py IP [PORT]'"
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

time.sleep(1.0)

# Example showing a single target for one joint
names             = "HeadYaw" 
targetAngles      = 1.0 
maxSpeedFraction  = 0.2 # Using 20% of maximum joint speed 
proxy.angleInterpolationWithSpeed(names, targetAngles, maxSpeedFraction)

time.sleep(1.0)

# Example showing multiple joints
# Instead of listing each joint, you can use a chain name, which will 
# be expanded to contain all the joints in the chain. In this case,
# "Head" will be interpreted as ["HeadYaw", "HeadPitch"]
names  = "Head"
# We still need to specify the correct number of target angles
targetAngles     = [0.5, 0.25]
maxSpeedFraction = 0.2 # Using 20% of maximum joint speed 
proxy.angleInterpolationWithSpeed(names, targetAngles, maxSpeedFraction)

proxy.setStiffnesses("Head", 0.0)

proxy.setStiffnesses("Body", 1.0)

# Example showing body zero position
# Instead of listing each joint, you can use a the name "Body" 
names  = "Body"
# We still need to specify the correct number of target angles, so 
# we need to find the number of joints that this Nao has.
# Here we are using the getJointNames method, which tells us all
# the names of the joints in the alias "Body".
# We could have used this list for the "names" parameter.
numJoints = len(proxy.getJointNames("Body"))
# Make a list of the correct length. All angles are zero.
targetAngles  = [0.0]*numJoints
# Using 10% of maximum joint speed
maxSpeedFraction  = 0.1
proxy.angleInterpolationWithSpeed(names, targetAngles, maxSpeedFraction)