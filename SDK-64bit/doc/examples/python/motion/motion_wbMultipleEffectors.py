#-*- coding: iso-8859-15 -*-

''' Whole Body Motion: Multiple Effectors control '''

import config
import motion
import almath
import time

def main():
    ''' 
		Example of a whole body multiple effectors control "LArm", "RArm" and "Torso"
        Warning: Needs a PoseInit before executing
                 Whole body balancer must be inactivated at the end of the script
    '''

    proxy = config.loadProxy("ALMotion")

    #Set NAO in Stiffness On
    config.StiffnessOn(proxy)

    # send robot to Pose Init
    config.PoseInit(proxy)

    # Enable Whole Body Balancer
    isEnabled  = True
    proxy.wbEnable(isEnabled)

    # Legs are constrained fixed
    stateName  = "Fixed"
    supportLeg = "Legs"
    proxy.wbFootState(stateName, supportLeg)

    # Constraint Balance Motion
    isEnable   = True
    supportLeg = "Legs"
    proxy.wbEnableBalanceConstraint(isEnable, supportLeg)


	# Arms motion
    effectorList = ["LArm", "RArm"]

    space        = motion.SPACE_NAO

    pathList     = [
                    [
                     [0.0,   0.08,  0.14, 0.0, 0.0, 0.0], # target 1 for "LArm"
                     [0.0,  -0.05, -0.07, 0.0, 0.0, 0.0], # target 2 for "LArm"
                     [0.0,   0.08,  0.14, 0.0, 0.0, 0.0], # target 3 for "LArm"
                     [0.0,  -0.05, -0.07, 0.0, 0.0, 0.0], # target 4 for "LArm"
                     [0.0,   0.08,  0.14, 0.0, 0.0, 0.0], # target 5 for "LArm"
                     ],
                    [
                     [0.0,   0.05, -0.07, 0.0, 0.0, 0.0], # target 1 for "RArm"
                     [0.0,  -0.08,  0.14, 0.0, 0.0, 0.0], # target 2 for "RArm"
                     [0.0,   0.05, -0.07, 0.0, 0.0, 0.0], # target 3 for "RArm"
                     [0.0,  -0.08,  0.14, 0.0, 0.0, 0.0], # target 4 for "RArm"
                     [0.0,   0.05, -0.07, 0.0, 0.0, 0.0], # target 5 for "RArm"
                     [0.0,  -0.08,  0.14, 0.0, 0.0, 0.0], # target 6 for "RArm"
                     ]
                    ]

    axisMaskList = [almath.AXIS_MASK_VEL, # for "LArm"
                    almath.AXIS_MASK_VEL] # for "RArm"

    coef       = 1.5
    timesList  = [ [coef*(i+1) for i in range(5)],  # for "LArm" in seconds
                   [coef*(i+1) for i in range(6)] ] # for "RArm" in seconds

    isAbsolute   = False

	# called cartesian interpolation
    proxy.positionInterpolations(effectorList, space, pathList,
                                 axisMaskList, timesList, isAbsolute)

	# Torso Motion
    effectorList = ["Torso"]

    dy = 0.05
    dz = 0.05
    pathList     = [
                    [
                     [0.0, +dy, -dz, 0.0, 0.0, 0.0], # target  1 for "Torso"
                     [0.0, 0.0, 0.0, 0.0, 0.0, 0.0], # target  2 for "Torso"
                     [0.0, -dy, -dz, 0.0, 0.0, 0.0], # target  3 for "Torso"
                     [0.0, 0.0, 0.0, 0.0, 0.0, 0.0], # target  4 for "Torso"
                     [0.0, +dy, -dz, 0.0, 0.0, 0.0], # target  5 for "Torso"
                     [0.0, 0.0, 0.0, 0.0, 0.0, 0.0], # target  6 for "Torso"
                     [0.0, -dy, -dz, 0.0, 0.0, 0.0], # target  7 for "Torso"
                     [0.0, 0.0, 0.0, 0.0, 0.0, 0.0], # target  8 for "Torso"
                     [0.0, +dy, -dz, 0.0, 0.0, 0.0], # target  9 for "Torso"
                     [0.0, 0.0, 0.0, 0.0, 0.0, 0.0], # target 10 for "Torso"
                     [0.0, -dy, -dz, 0.0, 0.0, 0.0], # target 11 for "Torso"
                     [0.0, 0.0, 0.0, 0.0, 0.0, 0.0], # target 12 for "Torso"
                     ],
                    ]

    axisMaskList = [almath.AXIS_MASK_ALL] # for "Torso"

    coef       = 0.5
    timesList  = [[coef*(i+1) for i in range(12)]] # for "Torso" in seconds

    isAbsolute   = False

    proxy.positionInterpolations(effectorList, space, pathList,
                                 axisMaskList, timesList, isAbsolute)


    # Remove optimization of "LArm" and "RArm". 
    isActive     = False
    proxy.wbEnableEffectorOptimization("LArm", isActive)
    proxy.wbEnableEffectorOptimization("RArm", isActive)

    # Let Arms time to return to Pose Init
    time.sleep(3.0)

    # Deactivate Head tracking
    isEnabled    = False
    proxy.wbEnable(isEnabled)

if __name__ == "__main__":
    main()
