#-*- coding: iso-8859-15 -*-

'''Walk To: Small example to make Nao Walk To an Objective'''

import math
import almath as m #python's wrapping of almath
import config

def main():
    motionProxy = config.loadProxy("ALMotion")

    # Set NAO in stiffness On
    config.StiffnessOn(motionProxy)

    #####################
    ## Enable arms control by Walk algorithm
    #####################
    motionProxy.setWalkArmsEnabled(True, True)
    #~ motionProxy.setWalkArmsEnabled(False, False)

    #####################
    ## FOOT CONTACT PROTECTION
    #####################
    #~ motionProxy.setMotionConfig([["ENABLE_FOOT_CONTACT_PROTECTION",False]])
    motionProxy.setMotionConfig([["ENABLE_FOOT_CONTACT_PROTECTION", True]])

    #####################
    ## get robot position before move
    #####################
    initRobotPosition = m.Pose2D(m.vectorFloat(motionProxy.getRobotPosition(False)))

    X = 0.3
    Y = 0.1
    Theta = math.pi/2.0
    motionProxy.post.walkTo(X, Y, Theta)
    # wait is useful because with post walkTo is not blocking function
    motionProxy.waitUntilWalkIsFinished()

    #####################
    ## get robot position after move
    #####################
    endRobotPosition = m.Pose2D(m.vectorFloat(motionProxy.getRobotPosition(False)))

    #####################
    ## compute and print the robot motion
    #####################
    robotMove = m.pose2DInverse(initRobotPosition)*endRobotPosition
    print "Robot Move :", robotMove 

if __name__ == "__main__":
    main()
