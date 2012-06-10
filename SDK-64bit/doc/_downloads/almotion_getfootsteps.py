import sys
import time
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_getfootsteps.py IP [PORT]'"
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

#####################################
# A small example using getFootSteps
#####################################

# Initialize the walk
proxy.walkInit()

# First call of walk API
# with post prefix to not be bloquing here.
proxy.post.walkTo(0.3, 0.0, 0.5)

# wait that the walk process start running
time.sleep(0.1)

# get the foot steps vector
footSteps = proxy.getFootSteps()

# print the result
leftFootWorldPosition = footSteps[0][0]
print "leftFootWorldPosition: " , leftFootWorldPosition
rightFootWorldPosition = footSteps[0][1]
print "rightFootWorldPosition: " , rightFootWorldPosition

footStepsUnchangeable = footSteps[1]
print "Unchangeable: " , footStepsUnchangeable

footStepsChangeable   = footSteps[2]
print "Changeable: " , footStepsChangeable
