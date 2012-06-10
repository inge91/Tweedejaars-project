#-*- coding: iso-8859-15 -*-

''' setFootStep: Small example to make Nao execute     '''
'''              The Cha Cha Basic Steps for Men       '''
'''              Using setFootStep API                 '''
''' http://www.dancing4beginners.com/cha-cha-steps.htm '''
import config

def main():
    motionProxy = config.loadProxy("ALMotion")

    # Set NAO in stiffness On
    config.StiffnessOn(motionProxy)
    config.PoseInit(motionProxy)

    ###############################
    # First we defined each step
    ###############################
    footStepsList = []

    # 1) Step forward with your left foot
    footStepsList.append([["LLeg"], [[0.06, 0.1, 0.0]]])

    # 2) Sidestep to the left with your left foot
    footStepsList.append([["LLeg"], [[0.00, 0.16, 0.0]]])

    # 3) Move your right foot to your left foot
    footStepsList.append([["RLeg"], [[0.00, -0.1, 0.0]]])

    # 4) Sidestep to the left with your left foot
    footStepsList.append([["LLeg"], [[0.00, 0.16, 0.0]]])

    # 5) Step backward & left with your right foot
    footStepsList.append([["RLeg"], [[-0.04, -0.1, 0.0]]])

    # 6)Step forward & right with your right foot
    footStepsList.append([["RLeg"], [[0.00, -0.16, 0.0]]])

    # 7) Move your left foot to your right foot
    footStepsList.append([["LLeg"], [[0.00, 0.1, 0.0]]])

    # 8) Sidestep to the right with your right foot
    footStepsList.append([["RLeg"], [[0.00, -0.16, 0.0]]])

    ###############################
    # Send Foot step 
    ###############################
    stepFrequency = 0.8
    clearExisting = False
    nbStepDance = 2 # defined the number of cycle to make

    for j in range( nbStepDance ):
        for i in range( len(footStepsList) ):
            motionProxy.setFootStepsWithSpeed(
                footStepsList[i][0],
                footStepsList[i][1],
                [stepFrequency],
                clearExisting)

if __name__ == "__main__":
    main()

