#-*- coding: iso-8859-15 -*-

''' Whole Body Motion: Left or Right Arm position control '''

import config
import motion
import time

def main(effectorName = "LArm"):
    ''' Example of a whole body Left or Right Arm position control
    Warning: Needs a PoseInit before executing
             Whole body balancer must be inactivated at the end of the script
    '''

    motionProxy = config.loadProxy("ALMotion")

    # Set NAO in Stiffness On
    config.StiffnessOn(motionProxy)

    # Send NAO to Pose Init
    config.PoseInit(motionProxy)

    space     = motion.SPACE_NAO
    useSensor = False

    effectorInit = motionProxy.getPosition(effectorName, space, useSensor)

    # Active LArm tracking
    isEnabled = True
    motionProxy.wbEnableEffectorControl(effectorName, isEnabled)

    # Example showing how to set position target for LArm
    # The 3 coordinates are absolute LArm position in NAO_SPACE
    # Position in meter in x, y and z axis.

    # X Axis LArm Position feasible movement = [ +0.00, +0.12] meter
    # Y Axis LArm Position feasible movement = [ -0.05, +0.10] meter
    # Y Axis RArm Position feasible movement = [ -0.10, +0.05] meter
    # Z Axis LArm Position feasible movement = [ -0.10, +0.10] meter

    coef = 1.0
    if (effectorName == "LArm"):
        coef = +1.0
    elif (effectorName == "RArm"):
        coef = -1.0

    targetCoordinateList = [
    [ +0.12, +0.00*coef, +0.00], # target 0
    [ +0.12, +0.00*coef, -0.10], # target 1
    [ +0.12, +0.05*coef, -0.10], # target 1
    [ +0.12, +0.05*coef, +0.10], # target 2
    [ +0.12, -0.10*coef, +0.10], # target 3
    [ +0.12, -0.10*coef, -0.10], # target 4
    [ +0.12, +0.00*coef, -0.10], # target 5
    [ +0.12, +0.00*coef, +0.00], # target 6
    [ +0.00, +0.00*coef, +0.00], # target 7
    ]


    # wbSetEffectorControl is a non blocking function
    # time.sleep allow head go to his target
    # The minimum period advised between two successives set commands is 0.2 s
    for targetCoordinate in targetCoordinateList:
        targetCoordinate = [targetCoordinate[i] + effectorInit[i] for i in range(3)]
        motionProxy.wbSetEffectorControl(effectorName, targetCoordinate)
        time.sleep(4.0)

    # Deactivate Head tracking
    isEnabled    = False
    motionProxy.wbEnableEffectorControl(effectorName, isEnabled)

if __name__ == "__main__":
    effectorName = "RArm" # "LArm" or "RArm"
    main(effectorName)
