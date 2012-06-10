import motion
import almath

import sys
from naoqi import ALProxy

if (len(sys.argv) < 2):
    print "Usage: 'python motion_angleinterpolation.py IP [PORT]'"
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


# Get transform of Left Arm in Torso space
chainName = "LArm"
space     = motion.SPACE_TORSO
useSensor = False
tf = almath.Transform(almath.vectorFloat(proxy.getTransform(chainName, space, useSensor)))

# Compute desired transform: rotation of 15 degrees around the Y axis
tfEnd = almath.Transform.fromRotY(15.0*motion.TO_RAD)*tf
tfEnd.r1_c4 = tf.r1_c4
tfEnd.r2_c4 = tf.r2_c4
tfEnd.r3_c4 = tf.r3_c4

# Set the desired target
axisMask = 63
fractionMaxSpeed = 0.1
transform = [val for val in tfEnd.toVector()]
proxy.setTransform(chainName, space, transform, fractionMaxSpeed, axisMask)
