''' This example shows how to guide NAO by the hand, while computing his
    moves with only footsteps, using ALMath library. Footstep clipping is
    described in almath_foot_clip.py. '''

import sys
import time
import math

from naoqi import ALProxy
import almath

import almath_foot_clip

armName = "LArm"
lFootOffset = almath.Pose2D(0.0, 0.09, 0.0)
rFootOffset = almath.Pose2D(0.0, -0.09, 0.0)
stepSpeed = 1.0
stepLength = 0.05

def initRobotPosition(motionProxy):
  ''' Inits NAO's position and stiffnesses to make the guiding possible.'''

  motionProxy.stiffnessInterpolation("Body", 1.0, 0.5)
  motionProxy.walkInit()
  time.sleep(1.0)
  # Make left arm loose.
  motionProxy.setAngles("LWristYaw", 0.0, 1.0, True)
  motionProxy.setAngles("Head", [0.44, -0.44], 0.5)
  motionProxy.setStiffnesses("LArm", 0.0)
  motionProxy.setStiffnesses("LWristYaw", 0.2)

  # Disable arm moves while walking on left arm.
  motionProxy.setWalkArmsEnable(False, True)
  time.sleep(1.0)



def interpretJointsPose(motionProxy, memoryProxy):
  ''' Translates the current left arm pose into a target position for NAO's
      foot. '''

  # Retrieve current arm position.
  armPose = motionProxy.getAngles(armName, True)

  targetX = 0.0
  targetY = 0.0
  targetTheta = 0.0
  gaitConfig = motionProxy.getFootGaitConfig("Default")

  # Filter Shoulder Pitch.
  if (armPose[0] > - 0.9 and armPose[0] < -0.20):
    targetX = stepLength
  elif (armPose[0] > -2.5 and armPose[0] < -1.5):
    targetX = - stepLength - 0.02

  # Filter Wrist Yaw.
  if (armPose[4] > 0.2):
    targetTheta = gaitConfig[2][1]
  elif (armPose[4] < -0.2):
    targetTheta = - gaitConfig[2][1]

  # Return corresponding pose.
  return almath.Pose2D(targetX, targetY, targetTheta)


def crouch(motionProxy):
  ''' Makes NAO crouch. '''
  names = list()
  times = list()
  keys = list()

  names.append("HeadYaw")
  times.append([ 1.00000])
  keys.append([ -0.03379])

  names.append("HeadPitch")
  times.append([ 1.00000])
  keys.append([ 0.32823])

  names.append("LShoulderPitch")
  times.append([ 1.00000])
  keys.append([ 1.62600])

  names.append("LShoulderRoll")
  times.append([ 1.00000])
  keys.append([ -0.01998])

  names.append("LElbowYaw")
  times.append([ 1.00000])
  keys.append([ -0.98640])

  names.append("LElbowRoll")
  times.append([ 1.00000])
  keys.append([ -1.24250])

  names.append("LWristYaw")
  times.append([ 1.00000])
  keys.append([ 0.08433])

  names.append("LHand")
  times.append([ 1.00000])
  keys.append([ 0.00015])

  names.append("RShoulderPitch")
  times.append([ 1.00000])
  keys.append([ 1.51870])

  names.append("RShoulderRoll")
  times.append([ 1.00000])
  keys.append([ -0.05680])

  names.append("RElbowYaw")
  times.append([ 1.00000])
  keys.append([ 0.72554])

  names.append("RElbowRoll")
  times.append([ 1.00000])
  keys.append([ 1.26099])

  names.append("RWristYaw")
  times.append([ 1.00000])
  keys.append([ 0.72094])

  names.append("RHand")
  times.append([ 1.00000])
  keys.append([ 0.00018])

  names.append("LHipYawPitch")
  times.append([ 1.00000])
  keys.append([ 0.01538])

  names.append("LHipRoll")
  times.append([ 1.00000])
  keys.append([ -0.00456])

  names.append("LHipPitch")
  times.append([ 1.00000])
  keys.append([ -0.90962])

  names.append("LKneePitch")
  times.append([ 1.00000])
  keys.append([ 2.11255])

  names.append("LAnklePitch")
  times.append([ 1.00000])
  keys.append([ -1.18889])

  names.append("LAnkleRoll")
  times.append([ 1.00000])
  keys.append([ 0.00464])

  names.append("RHipRoll")
  times.append([ 1.00000])
  keys.append([ 0.10589])

  names.append("RHipPitch")
  times.append([ 1.00000])
  keys.append([ -0.90203])

  names.append("RKneePitch")
  times.append([ 1.00000])
  keys.append([ 2.11255])

  names.append("RAnklePitch")
  times.append([ 1.00000])
  keys.append([ -1.18630])

  names.append("RAnkleRoll")
  times.append([ 1.00000])
  keys.append([ -0.10427])

  motionProxy.angleInterpolation(names, keys, times, True)



def moveToTargetPose(targetPose, motionProxy, isLeftSupport):
  ''' Move to the desired target with the current foot. '''

  targetTf = almath.transformFromPose2D(targetPose)

  # Compute foot position with the offset in NAOSpace.
  if (isLeftSupport):
    footTargetTf = targetTf * almath.transformFromPose2D(rFootOffset)
    footTargetPose = almath.pose2DFromTransform(footTargetTf)
    name = ["RLeg"]
  else:
    footTargetTf = targetTf * almath.transformFromPose2D(lFootOffset)
    footTargetPose = almath.pose2DFromTransform(footTargetTf)
    name = ["LLeg"]

  # Clip the footstep to avoid collisions and too wide steps.
  almath_foot_clip.clipFootStep(footTargetPose, isLeftSupport)

  step = [[footTargetPose.x, footTargetPose.y, footTargetPose.theta]]
  speed = [stepSpeed]

  # Send the footstep to NAO.
  motionProxy.setFootStepsWithSpeed(name, step, speed, False)

  # Change current foot.
  isLeftSupport = not isLeftSupport

def main(robotIP):

  # Init proxies.
  motionProxy = ALProxy("ALMotion", robotIP, 9559)
  memoryProxy = ALProxy("ALMemory", robotIP, 9559)
  ledsProxy = ALProxy("ALLeds", robotIP, 9559)

  # Init robot position.
  initRobotPosition(motionProxy)

  # Wait for the user to press the front tactil sensor.
  while (not memoryProxy.getData("FrontTactilTouched")):
    pass

  # Start by moving left foot.
  isLeftSupport = False
  isMoving = False
  ledsProxy.fadeRGB("FaceLeds", 255, 0.1)

  while (not memoryProxy.getData("RearTactilTouched")):
    targetPose = interpretJointsPose(motionProxy, memoryProxy)

    # Filter the pose to avoid too small steps.
    if (math.fabs(targetPose.x) > 0.01 or math.fabs(targetPose.y) > 0.01 or math.fabs(targetPose.theta) > 0.08):
      moveToTargetPose(targetPose, motionProxy, isLeftSupport)
      isLeftSupport = not isLeftSupport
      isMoving = True
      # Set LEDs to green.
      ledsProxy.fadeRGB("FaceLeds", 256 * 255, 0.1)

    elif (isMoving):
      # Stop the robot.
      motionProxy.stopWalk()
      isMoving = False
      # Set LEDs to blue.
      ledsProxy.fadeRGB("FaceLeds", 255, 0.1)

  # Set LEDs to white.
  ledsProxy.fadeRGB("FaceLeds", 256 * 256 * 255 + 256 * 255 + 255, 0.1)

  # Crouch.
  motionProxy.stiffnessInterpolation("Body", 1.0, 0.5)
  crouch(motionProxy)
  time.sleep(1.0)
  # Set stiffness off.
  motionProxy.stiffnessInterpolation("Body", 0.0, 0.5)


if __name__ == "__main__":
    if (len(sys.argv) < 2):
      print "Usage python almath_robot_guide.py robotIP"
      sys.exit(1)

    main(sys.argv[1])

