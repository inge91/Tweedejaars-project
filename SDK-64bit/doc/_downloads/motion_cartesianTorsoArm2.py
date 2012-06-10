#-*- coding: iso-8859-15 -*-

''' Cartesian control: Multiple Effector Trajectories '''

import config
import motion
import almath

def main():
    ''' Move the torso and keep arms fixed in nao space
    Warning: Needs a PoseInit before executing
    '''

    motionProxy = config.loadProxy("ALMotion")

    # Set NAO in Stiffness On
    config.StiffnessOn(motionProxy)

    # Send NAO to Pose Init
    config.PoseInit(motionProxy)

    space      = motion.SPACE_NAO
    isAbsolute = False

    effectorList = ["LArm", "RArm"]

    # Motion of Arms with block process
    axisMaskList = [almath.AXIS_MASK_VEL, almath.AXIS_MASK_VEL]

    timesList    = [[1.0], [1.0]]         # seconds
    pathList     = [[[0.0, -0.04, 0.0, 0.0, 0.0, 0.0]],
                    [[0.0,  0.04, 0.0, 0.0, 0.0, 0.0]]]
    motionProxy.positionInterpolations(effectorList, space, pathList,
                                       axisMaskList, timesList, isAbsolute)


    effectorList = ["LArm", "RArm", "Torso"]

    # Motion of Arms and Torso with block process
    axisMaskList = [almath.AXIS_MASK_VEL,
                    almath.AXIS_MASK_VEL,
                    almath.AXIS_MASK_ALL]

    timesList    = [[4.0],                  # LArm  in seconds
                    [4.0],                  # RArm  in seconds
                    [1.0, 2.0, 3.0, 4.0]]   # Torso in seconds

    dx           = 0.03                  # translation axis X (meters)
    dy           = 0.04                  # translation axis Y (meters)

    pathList     = [[[0.0, 0.0, 0.0, 0.0, 0.0, 0.0]], # LArm do not move
                    [[0.0, 0.0, 0.0, 0.0, 0.0, 0.0]], # RArm do not move
                    [[0.0, +dy, 0.0, 0.0, 0.0, 0.0],  # Torso point 1
                     [-dx, 0.0, 0.0, 0.0, 0.0, 0.0],  # Torso point 2
                     [0.0, -dy, 0.0, 0.0, 0.0, 0.0],  # Torso point 3
                     [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]]  # Torso point 4
                    ]
    motionProxy.positionInterpolations(effectorList, space, pathList,
                                       axisMaskList, timesList, isAbsolute)


if __name__ == "__main__":
    main()
