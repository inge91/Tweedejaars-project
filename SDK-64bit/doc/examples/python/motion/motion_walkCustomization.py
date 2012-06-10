#-*- coding: iso-8859-15 -*-

''' Walk: Small example to make Nao walk '''
'''       with gait customization        '''
'''       NAO is Keyser Soze             '''

import config
import time
import almath

def main():
    motionProxy = config.loadProxy("ALMotion")

    # Set NAO in stiffness On
    config.StiffnessOn(motionProxy)
    config.PoseInit(motionProxy)

    # TARGET VELOCITY
    X         = 1.0
    Y         = 0.0
    Theta     = 0.0
    Frequency = 1.0

    # Defined a limp walk
    motionProxy.setWalkTargetVelocity(X, Y, Theta, Frequency,
        [ # LEFT FOOT
        ["StepHeight", 0.02],
        ["TorsoWy", 5.0*almath.TO_RAD] ],
        [ # RIGHT FOOT
        ["StepHeight", 0.005],
        ["MaxStepX", 0.001],
        ["MaxStepFrequency", 0.0],
        ["TorsoWx", -7.0*almath.TO_RAD],
        ["TorsoWy", 5.0*almath.TO_RAD] ] )

    time.sleep(4.0)

    motionProxy.setWalkTargetVelocity(X, Y, Theta, Frequency)

    time.sleep(4.0)

    # stop walk in the next double support
    motionProxy.stopWalk()

if __name__ == "__main__":
    main()
