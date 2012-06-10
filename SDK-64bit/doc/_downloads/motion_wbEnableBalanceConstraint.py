#-*- coding: iso-8859-15 -*-

''' Whole Body Motion: Enable Balance Constraint '''

import config
import math

def main():
    ''' Example of a whole body Enable Balance Constraint
    Warning: Needs a PoseInit before executing
             Whole body balancer must be inactivated at the end of the script
    '''

    motionProxy = config.loadProxy("ALMotion")

    # Set NAO in Stiffness On
    config.StiffnessOn(motionProxy)

    # Send NAO to Pose Init
    config.PoseInit(motionProxy)

    # Activate Whole Body Balancer
    isEnabled  = True
    motionProxy.wbEnable(isEnabled)

    # Legs are constrained in a plane
    stateName  = "Fixed"
    supportLeg = "Legs"
    motionProxy.wbFootState(stateName, supportLeg)

    # Constraint Balance Motion
    isEnable   = True
    supportLeg = "Legs"
    motionProxy.wbEnableBalanceConstraint(isEnable, supportLeg)

    # KneePitch angleInterpolation
    # Without Whole Body balancer, foot will fall down
    names      = ["LKneePitch", "RKneePitch"]
    angleLists = [ [0.0, 40.0*math.pi/180.0], [0.0, 40.0*math.pi/180.0]]
    timeLists  = [ [5.0, 10.0], [5.0, 10.0]]
    isAbsolute = True
    motionProxy.angleInterpolation(names, angleLists, timeLists, isAbsolute)

    # Deactivate Whole Body Balancer
    isEnabled  = False
    motionProxy.wbEnable(isEnabled)

if __name__ == "__main__":
    main()
