#-*- coding: iso-8859-15 -*-

'''Walk To: Small example to make Nao Walk To an Objective '''
'''         With customization '''

import config

def main():
    motionProxy = config.loadProxy("ALMotion")

    # Set NAO in stiffness On
    config.StiffnessOn(motionProxy)

    x     = 0.2
    y     = 0.0
    theta = 0.0

    # This example show customization for the both foot
    # with all the possible gait parameters
    motionProxy.walkTo(x, y, theta,
        [ ["MaxStepX", 0.02],         # step of 2 cm in front
          ["MaxStepY", 0.16],         # default value
          ["MaxStepTheta", 0.4],      # default value
          ["MaxStepFrequency", 0.0],  # low frequency
          ["StepHeight", 0.01],       # step height of 1 cm
          ["TorsoWx", 0.0],           # default value
          ["TorsoWy", 0.1] ])         # torso bend 0.1 rad in front

    # This example show customization for the both foot
    # with just one gait parameter, in this case, the other
    # parameters are set to the default value
    motionProxy.walkTo(x, y, theta, [ ["StepHeight", 0.04] ]) # step height of 4 cm

if __name__ == "__main__":
    main()
