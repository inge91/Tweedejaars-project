#-*- coding: iso-8859-15 -*-

''' PoseZero: Set all the motors of the body to zero. '''

import config

def main():
    motionProxy = config.loadProxy("ALMotion")

    # We use the "Body" name to signify the collection of all joints and actuators
    pNames = "Body"

    # Get the Number of Joints
    numBodies = len(motionProxy.getJointNames(pNames))

    # We prepare a collection of floats
    pTargetAngles = [0.0] * numBodies

    # We set the fraction of max speed
    pMaxSpeedFraction = 0.3

    # Ask motion to do this with a blocking call
    motionProxy.angleInterpolationWithSpeed(pNames, pTargetAngles, pMaxSpeedFraction)

if __name__ == "__main__":
    main()
