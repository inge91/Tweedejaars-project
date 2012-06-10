#-*- coding: iso-8859-15 -*-

''' Whole Body Motion: kick '''

import config
import motion
import time
import math

def main():
    ''' Example of a whole body kick
    Warning: Needs a PoseInit before executing
             Whole body balancer must be inactivated at the end of the script
    '''

    proxy = config.loadProxy("ALMotion")

    #Set NAO in stiffness On
    config.StiffnessOn(proxy)

    # send robot to Pose Init
    config.PoseInit(proxy)

    # Activate Whole Body Balancer
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

    # Com go to LLeg
    supportLeg = "LLeg"
    duration   = 2.0
    proxy.wbGoToBalance(supportLeg, duration)

    # RLeg is free
    stateName  = "Free"
    supportLeg = "RLeg"
    proxy.wbFootState(stateName, supportLeg)

    # RLeg is optimized
    effectorName = "RLeg"
    axisMask     = 63
    space        = motion.SPACE_NAO


    # Motion of the RLeg
    dx      = 0.05                  # translation axis X (meters)
    dz      = 0.05                  # translation axis Z (meters)
    dwy     = 5.0*math.pi/180.0    # rotation axis Y (radian)


    times   = [2.0, 2.7, 4.5]
    isAbsolute = False

    targetList = [
      [-dx, 0.0, dz, 0.0, +dwy, 0.0],
      [+dx, 0.0, dz, 0.0, 0.0, 0.0],
      [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]]

    proxy.positionInterpolation(effectorName, space, targetList,
                                 axisMask, times, isAbsolute)


    # Example showing how to Enable Effector Control as an Optimization
    isActive     = False
    proxy.wbEnableEffectorOptimization(effectorName, isActive)

    # Com go to LLeg
    supportLeg = "RLeg"
    duration   = 2.0
    proxy.wbGoToBalance(supportLeg, duration)

    # RLeg is free
    stateName  = "Free"
    supportLeg = "LLeg"
    proxy.wbFootState(stateName, supportLeg)
    
    effectorName = "LLeg"
    proxy.positionInterpolation(effectorName, space, targetList,
                                axisMask, times, isAbsolute)

    time.sleep(1.0)

    # Deactivate Head tracking
    isEnabled    = False
    proxy.wbEnable(isEnabled)

    # send robot to Pose Init
    pMaxSpeedFraction = 0.1
    config.PoseInit(proxy, pMaxSpeedFraction)

if __name__ == "__main__":
    main()
