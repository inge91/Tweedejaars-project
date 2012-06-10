#-*- coding: iso-8859-15 -*-

''' Walk: Small example to make Nao walk '''
'''       with jerky head                '''

import config
import time
import random

def main():
    motionProxy = config.loadProxy("ALMotion")

    # Set NAO in stiffness On
    config.StiffnessOn(motionProxy)
    config.PoseInit(motionProxy)

    # Initialize the walk process.
    # Check the robot pose and take a right posture.
    # This is blocking called.
    motionProxy.walkInit()
    
    testTime = 10 # seconds
    t = 0
    dt = 0.2
    while (t<testTime):

        # WALK
        X         = random.uniform(0.4, 1.0)
        Y         = random.uniform(-0.4, 0.4)
        Theta     = random.uniform(-0.4, 0.4)
        Frequency = random.uniform(0.5, 1.0)
        motionProxy.setWalkTargetVelocity(X, Y, Theta, Frequency)

        # JERKY HEAD
        motionProxy.setAngles("HeadYaw", random.uniform(-1.0, 1.0), 0.6)
        motionProxy.setAngles("HeadPitch", random.uniform(-0.5, 0.5), 0.6)

        t = t + dt
        time.sleep(dt)

    # stop walk on the next double support
    motionProxy.stopWalk()

if __name__ == "__main__":
    main()
