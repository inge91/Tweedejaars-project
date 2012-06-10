import sys
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_wbseteffectorcontrol.py IP [PORT]'"
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
proxy.wbEnable(True)

# Example showing how to set orientation target for Head tracking. 
effectorName = "Head" 
targetCoordinate = [0.1, 0.0, 0.0] 
proxy.wbSetEffectorControl(effectorName, targetCoordinate)

proxy.wbEnable(False)