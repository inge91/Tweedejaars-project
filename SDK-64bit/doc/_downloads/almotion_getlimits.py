import sys
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_getlimits.py IP [PORT]'"
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

# Example showing how to get the limits for the whole body 
name = "Body" 
limits = proxy.getLimits(name) 
jointNames = proxy.getJointNames(name) 
for i in range(0,len(limits)): 
  print jointNames[i] + ":"
  print "MinAngle", limits[i][0], "MaxAngle", limits[i][1],"MaxVelocity", limits[i][2]