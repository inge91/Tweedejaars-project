#-*- coding: iso-8859-15 -*-

''' Cartesian control: Arm trajectory example '''

import config
import motion
import almath

def main():
    ''' Example showing a path of two positions
    Warning: Needs a PoseInit before executing
    '''

    motionProxy = config.loadProxy("ALMotion")

    # Set NAO in Stiffness On
    config.StiffnessOn(motionProxy)

    # Send NAO to Pose Init
    config.PoseInit(motionProxy)

    effector   = "LArm"
    space      = motion.SPACE_NAO
    axisMask   = almath.AXIS_MASK_VEL    # just control position
    isAbsolute = False

    # Since we are in relative, the current position is zero
    currentPos = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]

    # Define the changes relative to the current position
    dx         =  0.03      # translation axis X (meters)
    dy         =  0.03      # translation axis Y (meters)
    dz         =  0.00      # translation axis Z (meters)
    dwx        =  0.00      # rotation axis X (radians)
    dwy        =  0.00      # rotation axis Y (radians)
    dwz        =  0.00      # rotation axis Z (radians)
    targetPos  = [dx, dy, dz, dwx, dwy, dwz]

    # Go to the target and back again
    path       = [targetPos, currentPos]
    times      = [2.0, 4.0] # seconds

    motionProxy.positionInterpolation(effector, space, path,
                                      axisMask, times, isAbsolute)

if __name__ == "__main__":
    main()
