import sys
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_getrobotconfig.py IP [PORT]'"
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

# Example showing how to get the robot config 
robotConfig = proxy.getRobotConfig() 
for i in range(len(robotConfig[0])): 
    print robotConfig[0][i], ": ", robotConfig[1][i] 
 
# "Model Type"   : "naoH25", "naoH21", "naoT14" or "naoT2".
# "Head Version" : "VERSION_32" or "VERSION_33" or "VERSION_40".
# "Body Version" : "VERSION_32" or "VERSION_33" or "VERSION_40".
# "Laser"        : True or False.
# "Legs"         : True or False.
# "Arms"         : True or False.
# "Extended Arms": True or False.
# "Hands"        : True or False.
# "Arm Version"  : "VERSION_32" or "VERSION_33" or "VERSION_40".
