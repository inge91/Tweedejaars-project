import sys
import math
import time
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_taskmanagement1.py IP [PORT]'"
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

# move slowly the head to look in the left direction
names  = "HeadYaw"
angles = math.pi/2
fractionMaxSpeed  = .1
proxy.setAngles(names, angles, fractionMaxSpeed)

time.sleep(1.)

# while the previous motion is still running, update the angle
angles  = -math.pi/6
fractionMaxSpeed  = 1.
proxy.setAngles(names, angles, fractionMaxSpeed)
