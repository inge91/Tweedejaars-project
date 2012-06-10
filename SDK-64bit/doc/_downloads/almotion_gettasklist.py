import sys
import time
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_gettasklist.py IP [PORT]'"
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

# Example showing how to get the current task list
# We will create a task first, so that we see a result
names      = "HeadYaw" 
angleLists = 1.0 
timeList   = 3.0 
isAbsolute = True 
proxy.post.angleInterpolation(names, angleLists, timeList, isAbsolute) 
time.sleep(0.1) 
print 'Tasklist', proxy.getTaskList()

time.sleep(2.0)

proxy.setStiffnesses("Head", 0.0)