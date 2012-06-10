import sys
import time
from naoqi import ALProxy
from naoqi import motion

if (len(sys.argv) < 2):
    print "Usage: 'python motion_killtask.py IP [PORT]'"
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

# This function is useful to kill motion Task
# To see the current motionTask please use getTaskList() function

proxy.post.angleInterpolation('HeadYaw', 90*motion.TO_RAD, 10, True)
time.sleep(3)
TaskList = proxy.getTaskList()
uiMotion = TaskList[0][1]
proxy.killTask(uiMotion)

proxy.setStiffnesses("Head", 0.0)