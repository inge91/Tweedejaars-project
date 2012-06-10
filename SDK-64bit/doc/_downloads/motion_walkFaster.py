#-*- coding: iso-8859-15 -*-

''' Walk: Small example to make Nao walk '''
'''       Faster (Step of 6cm)          '''

import config
import time

def main():
    motionProxy = config.loadProxy("ALMotion")

    # Set NAO in stiffness On
    config.StiffnessOn(motionProxy)
    config.PoseInit(motionProxy)

    # Initialize the walk process.
    # Check the robot pose and take a right posture.
    # This is blocking called.
    motionProxy.walkInit()

    # TARGET VELOCITY
    X         = 1.0
    Y         = 0.0
    Theta     = 0.0
    Frequency = 1.0

    # Default walk (MaxStepX = 0.04 m)
    motionProxy.setWalkTargetVelocity(X, Y, Theta, Frequency)
    time.sleep(3.0)
    print "walk Speed X :",motionProxy.getRobotVelocity()[0]," m/s"

    # Speed walk  (MaxStepX = 0.06 m)
    # Could be faster: see walk documentation
    motionProxy.setWalkTargetVelocity(X, Y, Theta, Frequency, [["MaxStepX", 0.06]])
    time.sleep(4.0)
    print "walk Speed X :",motionProxy.getRobotVelocity()[0]," m/s"

    # stop walk on the next double support
    motionProxy.stopWalk()

if __name__ == "__main__":
    main()
