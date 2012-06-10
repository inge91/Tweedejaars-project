import sys
import time
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_areresourcesavailable.py IP [PORT]'"
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

# Example showing how to use areResourcesAvailable
# We will create a task first, so that we see a result 
name = "HeadYaw" 
proxy.post.angleInterpolation(name, 1.0, 1.0, True) 
time.sleep(0.1) 
print "Are " + name + " resources available? " + str(proxy.areResourcesAvailable([name]))

time.sleep(1.0)

proxy.setStiffnesses("Head", 0.0)

