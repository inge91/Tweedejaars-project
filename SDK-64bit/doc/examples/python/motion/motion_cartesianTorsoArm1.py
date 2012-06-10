#-*- coding: iso-8859-15 -*-

''' Cartesian control: Multiple Effector Trajectories '''

import config
import motion
import almath

def main():
    ''' Simultaneously control three effectors :
    the Torso, the Left Arm and the Right Arm
    Warning: Needs a PoseInit before executing
    '''

    motionProxy = config.loadProxy("ALMotion")

    # Set NAO in Stiffness On
    config.StiffnessOn(motionProxy)

    # Send Robot to Pose Init
    config.PoseInit(motionProxy)

    space      = motion.SPACE_NAO
    coef       = 0.5                   # motion speed
    times      = [coef, 2.0*coef, 3.0*coef, 4.0*coef]
    isAbsolute = False

    # Relative movement between current and desired positions
    dy         = +0.06                 # translation axis Y (meters)
    dz         = -0.03                 # translation axis Z (meters)
    dwx        = +0.30                 # rotation axis X (radians)

    # Motion of Torso with post process
    effector   = "Torso"
    path       = [
      [0.0, -dy,  dz, -dwx, 0.0, 0.0], # point 1
      [0.0, 0.0, 0.0,  0.0, 0.0, 0.0], # point 2
      [0.0, +dy,  dz, +dwx, 0.0, 0.0], # point 3
      [0.0, 0.0, 0.0,  0.0, 0.0, 0.0]] # point 4
    axisMask   = almath.AXIS_MASK_ALL  # control all the effector axes
    motionProxy.post.positionInterpolation(effector, space, path,
                                           axisMask, times, isAbsolute)

    # Motion of Arms with block process
    axisMask   = almath.AXIS_MASK_VEL  # control just the position
    times      = [1.0*coef, 2.0*coef]  # seconds

    dy         = +0.03                 # translation axis Y (meters)
    # Motion of Right Arm during the first half of the Torso motion
    effector   = "RArm"
    path       = [
      [0.0, -dy, 0.0, 0.0, 0.0, 0.0],  # point 1
      [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]]  # point 2
    motionProxy.positionInterpolation(effector, space, path,
                                      axisMask, times, isAbsolute)

    # Motion of Left Arm during the last half of the Torso motion
    effector   = "LArm"
    path       = [
      [0.0,  dy, 0.0, 0.0, 0.0, 0.0],  # point 1
      [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]]  # point 2
    motionProxy.positionInterpolation(effector, space, path,
                                      axisMask, times, isAbsolute)

if __name__ == "__main__":
    main()
