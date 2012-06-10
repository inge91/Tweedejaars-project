#-*- coding: iso-8859-15 -*-

'''Stiffness On: active stiffness of all joints and actuators'''

import config

def main():
    motionProxy = config.loadProxy("ALMotion")

    #We use the "Body" name to signify the collection of all joints
    pNames = "Body"
    pStiffnessLists = 1.0
    pTimeLists = 1.0
    motionProxy.stiffnessInterpolation(pNames, pStiffnessLists, pTimeLists)

    # print motion state
    print motionProxy.getSummary()

if __name__ == "__main__":
    main()
