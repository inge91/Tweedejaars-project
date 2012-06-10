''' Example showing how to use almath with python and send the results to
    the robot by using a proxy to ALMotion '''


import time

from naoqi import ALProxy

# Import almath
import almath

IP = "127.0.0.1" # set your Ip adress here
PORT = 9559

# Create a proxy to ALMotion.
try:
  motionProxy = ALProxy("ALMotion", IP, PORT)
except Exception,e:
  print "Could not create proxy to ALMotion"
  print "Error was: ",e

chainName = "RArm"
space = 1
useSensors = True

# Set stiffness on.
# motionProxy.stiffnessInterpolation("Body", 1.0, 0.5)

# Stand up.
motionProxy.walkInit()

##############################################
# Retrieve a transform matrix using ALMotion #
##############################################

# Retrieve current transform from ALMotion.
transformList = motionProxy.getTransform(chainName, space, useSensors)

# Convert it to vector format of ALMath.
transformVector = almath.vectorFloat(transformList)

# Convert it to a transform matrix for ALMath.
origTransform = almath.Transform(transformVector)

# Visualize the transform using overriden print from ALMath
print "Original transform"
print origTransform

##########################################################
# Use almath to do some computations on transform matrix #
##########################################################

# Compute a transform corresponding to the desired move
# (here, move the chain for 5cm along the Z axis and the X axis).
desiredPosition = almath.Position3D(0.05, 0.0, 0.05)
moveTransform = almath.transformFromPosition3D(desiredPosition)

# Compute the corresponding target transform.
targetTransform = moveTransform * origTransform

# Visualize it.
print "Target transform"
print targetTransform

##############################################
# Send a transform to the robot via ALMotion #
##############################################

# Convert it to a almath vector.
targetTransformVector = targetTransform.toVector()

# Convert it to a list.
targetTransformList = []
for val in targetTransformVector:
  targetTransformList.append(val)

# Send the target transform to NAO through ALMotion.
motionProxy.setTransform(chainName, space, targetTransformList, 0.5, 7)

time.sleep(2.0)
