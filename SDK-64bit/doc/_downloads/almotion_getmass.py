import sys
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_getmass.py IP [PORT]'"
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

# Example showing how to get the mass of "HeadYaw". 
pName = "HeadYaw" 
mass = proxy.getMass(pName)
print pName + " mass: " + str(mass)

# Example showing how to get the mass "LLeg" chain. 
pName = "LLeg" 
print "LLeg : ", proxy.getMass(pName) 
 
# It is equivalent to the following script 
pNameList = ["LHipYawPitch", "LHipRoll", "LHipPitch", "LKneePitch", "LAnkleRoll", "LAnklePitch"] 
mass = 0 
for pName in pNameList: 
    mass = mass + proxy.getMass(pName) 
print "LLeg :", mass