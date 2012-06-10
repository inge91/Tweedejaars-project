#-*- coding: iso-8859-15 -*-

''' Whole Body Motion: Foot State '''

import config
import math

def main():
    ''' Example of a whole body FootState
    Warning: Needs a PoseInit before executing
             Whole body balancer must be inactivated at the end of the script
    '''

    proxy = config.loadProxy("ALMotion")

    # Set NAO in stiffness On
    config.StiffnessOn(proxy)

    # Send robot to Pose Init
    config.PoseInit(proxy)

    # Activate Whole Body Balancer.
    isEnabled  = True
    proxy.wbEnable(isEnabled)

    # Legs are constrained in a plane
    stateName  = "Plane"
    supportLeg = "Legs"
    proxy.wbFootState(stateName, supportLeg)

    # HipYawPitch angleInterpolation
    # Without Whole Body balancer, foot will not be keeped plane.
    names      = "LHipYawPitch"
    angleLists = [-45.0, 10.0, 0.0]
    timeLists  = [3.0, 6.0, 9.0]
    isAbsolute = True
    angleLists = [angle*math.pi/180.0 for angle in angleLists]
    proxy.angleInterpolation(names, angleLists, timeLists, isAbsolute)

    # Deactivate Whole Body Balancer.
    isEnabled  = False
    proxy.wbEnable(isEnabled)

if __name__ == "__main__":
    main()
