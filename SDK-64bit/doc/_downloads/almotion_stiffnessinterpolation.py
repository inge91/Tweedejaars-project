import sys
from naoqi import ALProxy
import time

if (len(sys.argv) < 2):
    print "Usage: 'python motion_stiffnessinterpolation.py IP [PORT]'"
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

# Example showing how to interpolate to maximum stiffness in 1 second
names  = 'Body'
stiffnessLists  = 0.0
timeLists  = 1.0
proxy.stiffnessInterpolation(names, stiffnessLists, timeLists)

time.sleep(1.0)

# Example showing a stiffness trajectory for a single joint
names  = ['HeadYaw']
stiffnessLists  = [0.25,0.5,1.0, 0.0]
timeLists  = [1.0,2.0,3.0, 4.0]
proxy.stiffnessInterpolation(names, stiffnessLists, timeLists)