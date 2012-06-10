#-*- coding: iso-8859-15 -*-

''' setFootStep: Small example to make Nao execute     '''
'''              Random Foot Steps                     '''
'''              Using setFootStep API                 '''
import config
import almath
import random

def main():
    motionProxy = config.loadProxy("ALMotion")

    # Set NAO in stiffness On
    config.StiffnessOn(motionProxy)
    config.PoseInit(motionProxy)

    # This example create 10 random Step
    for i in range(10):
        motionProxy.setFootStepsWithSpeed(
            [random.choice(["RLeg","LLeg"])], # Leg name
            [[random.uniform(-0.04, 0.06),    # X
              random.uniform(-0.16, 0.16),    # Y
              random.uniform(-30.0*almath.TO_RAD, 30.0*almath.TO_RAD), # Theta
              [["StepHeight", random.uniform(0.005, 0.03)],             # Step height
               ["TorsoWy", random.uniform(7.0*almath.TO_RAD, -7.0*almath.TO_RAD)],    # TorsoWy
               ["TorsoWx", random.uniform(7.0*almath.TO_RAD, -7.0*almath.TO_RAD)]]]], # TorsoWx
               [random.uniform(0.01, 0.99)],     # Frequency
               False)

if __name__ == "__main__":
    main()

