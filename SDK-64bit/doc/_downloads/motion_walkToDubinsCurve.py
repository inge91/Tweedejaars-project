#-*- coding: iso-8859-15 -*-

'''Walk To: Small example to make Nao Walk follow'''
'''         a Dubins Curve '''

import config
import almath as m #python's wrapping of almath

def main():
    motionProxy = config.loadProxy("ALMotion")

    # Set NAO in stiffness On
    config.StiffnessOn(motionProxy)

    # first we defined the goal
    goal = m.Pose2D(0.0, -0.4, 0.0)

    # We get the dubins solution (control points) by
    # calling an almath function

    circleRadius = 0.04
    # Warning : the circle use by dubins curve
    #           have to be 4*CircleRadius < norm(goal)
    dubinsSolutionAbsolute = m.getDubinsSolutions(goal, circleRadius)

    # walkTo With control Points use relative commands but
    # getDubinsSolution return absolute position
    # So, we compute dubinsSolution in relative way
    dubinsSolutionRelative = []
    dubinsSolutionRelative.append(dubinsSolutionAbsolute[0])
    for i in range(len(dubinsSolutionAbsolute)-1):
        dubinsSolutionRelative.append(dubinsSolutionAbsolute[i].inverse()*dubinsSolutionAbsolute[i+1])  

    # create a vector of walkTo with dubins Control Points
    walkToTargets = []
    for i in range(len(dubinsSolutionRelative)):
        walkToTargets.append(
            [dubinsSolutionRelative[i].x,
             dubinsSolutionRelative[i].y,
             dubinsSolutionRelative[i].theta] )

    # Initialized the Walk process and be sure the robot is ready to walk
    # without this call, the first getRobotPosition() will not refer to the position
    # of the robot before the walk process
    motionProxy.walkInit()

    # get robot position before move
    robotPositionBeforeCommand  = m.Pose2D(m.vectorFloat(motionProxy.getRobotPosition(False)))

    motionProxy.walkTo( walkToTargets )

    # With WalkTo control Points, it's also possible to customize the gait parameters
    # motionProxy.walkTo(walkToTargets,
    #                    [["StepHeight", 0.001],
    #                     ["MaxStepX", 0.06],
    #                     ["MaxStepFrequency", 1.0]])

    # get robot position after move
    robotPositionAfterCommand = m.Pose2D(m.vectorFloat(motionProxy.getRobotPosition(False)))

    # compute and print the robot motion
    robotMoveCommand = m.pose2DInverse(robotPositionBeforeCommand)*robotPositionAfterCommand
    print "The Robot Move Command: ", robotMoveCommand


if __name__ == "__main__":
    main()
