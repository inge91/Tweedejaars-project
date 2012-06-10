import sys
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_waituntilwalkisfinished.py IP [PORT]'"
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

proxy.stiffnessInterpolation("Body", 1.0, 0.1)
proxy.walkInit()

# Example showing how to use waitUntilWalkIsFinished. 
 
# Start a walk 
x = 0.2 
y = 0.0 
theta = 0.0 
proxy.post.walkTo(x, y, theta) 
 
# Wait for it to finish  
proxy.waitUntilWalkIsFinished()
 
# Then do something else
print "Walk is finished"