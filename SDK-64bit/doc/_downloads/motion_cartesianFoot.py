#-*- coding: iso-8859-15 -*-

''' Cartesian control: Torso and Foot trajectories '''

import config
import motion
import almath

def main():
    ''' Example of a cartesian foot trajectory
    Warning: Needs a PoseInit before executing
    '''

    motionProxy = config.loadProxy("ALMotion")

    # Set NAO in Stiffness On
    config.StiffnessOn(motionProxy)

    # Send NAO to Pose Init
    config.PoseInit(motionProxy)

    space      = motion.SPACE_NAO
    axisMask   = almath.AXIS_MASK_ALL   # full control
    isAbsolute = False

    # Lower the Torso and move to the side
    effector   = "Torso"
    path       = [0.0, -0.07, -0.03, 0.0, 0.0, 0.0]
    time       = 2.0                    # seconds
    motionProxy.positionInterpolation(effector, space, path,
                                axisMask, time, isAbsolute)

    # LLeg motion
    effector   = "LLeg"
    path       = [0.0,  0.06,  0.00, 0.0, 0.0, 0.8]
    times      = 2.0                    # seconds

    motionProxy.positionInterpolation(effector, space, path,
                                      axisMask, times, isAbsolute)

if __name__ == "__main__":
    main()
