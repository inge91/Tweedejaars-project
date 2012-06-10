#-*- coding: iso-8859-15 -*-

''' Cartesian control: Arm trajectory example '''

import config
import motion

def main():
    ''' Example showing a hand ellipsoid
    Warning: Needs a PoseInit before executing
    '''

    motionProxy = config.loadProxy("ALMotion")

    # Set NAO in Stiffness On
    config.StiffnessOn(motionProxy)

    # Send NAO to Pose Init
    config.PoseInit(motionProxy)

    effector   = "LArm"
    space      = motion.SPACE_NAO
    path       = [
     [0.0, -0.05, +0.00, 0.0, 0.0, 0.0],        # point 1
     [0.0, +0.00, +0.04, 0.0, 0.0, 0.0],        # point 2
     [0.0, +0.04, +0.00, 0.0, 0.0, 0.0],        # point 3
     [0.0, +0.00, -0.02, 0.0, 0.0, 0.0],        # point 4
     [0.0, -0.05, +0.00, 0.0, 0.0, 0.0],        # point 5
     [0.0, +0.00, +0.00, 0.0, 0.0, 0.0]]        # point 6
    axisMask   = 7                              # just control position
    times      = [0.5, 1.0, 2.0, 3.0, 4.0, 4.5] # seconds
    isAbsolute = False
    motionProxy.positionInterpolation(effector, space, path,
                                      axisMask, times, isAbsolute)

if __name__ == "__main__":
    main()
