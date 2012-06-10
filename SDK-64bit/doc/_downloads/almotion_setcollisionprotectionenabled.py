import sys
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_setcollisionprotectionenabled.py IP [PORT]'"
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

# Example showing how to activate "Arms" anticollision 
# Anticollision can be activated at every time 
pChainName = "Arms" 
pEnable    = True 
isSuccess  = proxy.setCollisionProtectionEnabled(pChainName, pEnable)
print "Anticollision activation on arms: " + str(isSuccess)

# Example showing how to deactivate "LArm" anticollision 
# Anticollision can be inactivated only if there is no collision in the desired chain 
pChainName = "LArm" 
collisionState= proxy.isCollision(pChainName) 
pEnable = False 
if ((collisionState =="none") or 
    (collisionState =="near")): 
    isSuccess= proxy.setCollisionProtectionEnabled(pChainName, pEnable)
    print "Anticollision deactivation on arms: " + str(isSuccess)
else:
    print "Cannot deactivate collision protection on left arm: collisionState = collision"