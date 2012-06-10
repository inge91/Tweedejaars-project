#-*- coding: iso-8859-15 -*-

''' MoveHand: Small example to make Nao move Hands. '''

import config
import time

def main():
    proxy = config.loadProxy("ALMotion")

    #~ MOVE_HAND_BY_INTERPOLATION = True
    MOVE_HAND_BY_INTERPOLATION = False

    #####################
    ## Test for Hand detection
    #####################
    # Get the Robot Configuration
    robotConfig = proxy.getRobotConfig()
    robotHasHands = False
    for i in range(len(robotConfig[0])):
      if (robotConfig[0][i] == "Hands"):
        robotHasHands = robotConfig[1][i]

    if (robotHasHands):
        if (MOVE_HAND_BY_INTERPOLATION):
            pNames = "LHand"
            # put stiffness on LHand
            proxy.stiffnessInterpolation(pNames, 1.0, 1.0)
            pMaxSpeedFraction = 0.5
            proxy.angleInterpolationWithSpeed(pNames, 1.0, pMaxSpeedFraction)
            proxy.angleInterpolationWithSpeed(pNames, 0.0, pMaxSpeedFraction)

        else:
            # NOTE that open and close Hand put Stifnees to 0.0 after execution !!!

            # Close hand
            pHandName = "RHand"
            proxy.closeHand(pHandName)
            pHandName = "LHand"
            proxy.closeHand(pHandName)

            time.sleep(2)

            # Open hand
            pHandName = "RHand"
            proxy.openHand(pHandName)
            pHandName = "LHand"
            proxy.openHand(pHandName)

            time.sleep(2)

            # Close hand
            pHandName = "RHand"
            proxy.closeHand(pHandName)
            pHandName = "LHand"
            proxy.closeHand(pHandName)
    else:
        print "ERROR : Your robot doesn't have Hands"
        print "This test is not availbale for your Robot"
        print "---------------------"
        exit(1)

if __name__ == "__main__":
    main()



