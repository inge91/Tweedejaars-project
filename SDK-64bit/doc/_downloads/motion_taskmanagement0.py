import sys
import math
import time
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_taskmanagement0.py IP [PORT]'"
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

# go to an init head pose.
names  = ["HeadYaw", "HeadPitch"]
angles = [0., 0.]
times  = [1.0, 1.0]
isAbsolute = True
proxy.angleInterpolation(names, angles, times, isAbsolute)

# move slowly the head to look in the left direction. The motion will
# take 4 seconds
names  = "HeadYaw"
angles = math.pi/2
times  = 4.0
isAbsolute = True
proxy.post.angleInterpolation(names, angles, times, isAbsolute)

time.sleep(1.)

# one second after having started motion1, check the resources use.
# As expected the "HeadYaw" resource is busy
isAvailable = proxy.areResourcesAvailable([names])
print("areResourcesAvailable({0}): {1}".format([names], isAvailable))

time.sleep(1.)

# try to look in the right direction. As the "HeadYaw" joint is busy,
# this motion is postponed until the resource is freed
angles = -math.pi/2
times  = 2.0
isAbsolute = True
proxy.post.angleInterpolation(names, angles, times, isAbsolute)
