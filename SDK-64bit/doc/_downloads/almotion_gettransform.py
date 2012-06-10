import sys
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_gettransform.py IP [PORT]'"
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

# Example showing how to get the end of the right arm as a transform 
# represented in torso space. The result is a 4 by 4 matrix composed 
# of a 3*3 rotation matrix and a column vector of positions. 
name  = 'RArm' 
space  = 0 
useSensorValues  = True 
result = proxy.getTransform(name, space, useSensorValues) 
for i in range(0,4): 
  for j in range(0,4): 
    print result[4*i + j], 
  print ''