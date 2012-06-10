import sys
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_getsensornames.py IP [PORT]'"
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

# Example showing how to get the list of the sensors 
sensorList = proxy.getSensorNames() 
for sensor in sensorList: 
    print sensor