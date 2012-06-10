#-*- coding: iso-8859-15 -*-

import config
import motion
import almath

def main():
    ''' 
		 Example showing a Hula Hoop Motion
         with the NAO cartesian control of torso
    '''

    motionProxy = config.loadProxy("ALMotion")

    # Set NAO in Stiffness On
    config.StiffnessOn(motionProxy)

    # Send NAO to Pose Init
    config.PoseInit(motionProxy)

    # Define the changes relative to the current position
    dx         = 0.07                    # translation axis X (meter)
    dy         = 0.07                    # translation axis Y (meter)
    dwx        = 0.15                    # rotation axis X (rad)
    dwy        = 0.15                    # rotation axis Y (rad)

    # Define a path of two hula hoop loops
    path = [ [+dx, 0.0, 0.0,  0.0, -dwy, 0.0],  # point 01 : forward  / bend backward
             [0.0, -dy, 0.0, -dwx,  0.0, 0.0],  # point 02 : right    / bend left
             [-dx, 0.0, 0.0,  0.0,  dwy, 0.0],  # point 03 : backward / bend forward
             [0.0, +dy, 0.0,  dwx,  0.0, 0.0],  # point 04 : left     / bend right

             [+dx, 0.0, 0.0,  0.0, -dwy, 0.0],  # point 01 : forward  / bend backward
             [0.0, -dy, 0.0, -dwx,  0.0, 0.0],  # point 02 : right    / bend left
             [-dx, 0.0, 0.0,  0.0,  dwy, 0.0],  # point 03 : backward / bend forward
             [0.0, +dy, 0.0,  dwx,  0.0, 0.0],  # point 04 : left     / bend right

             [+dx, 0.0, 0.0,  0.0, -dwy, 0.0],  # point 05 : forward  / bend backward
			 [0.0, 0.0, 0.0,  0.0,  0.0, 0.0] ] # point 06 : Back to init pose

    timeOneMove  = 0.4 #seconds
    times = []
    for i in range(len(path)):
        times.append( (i+1)*timeOneMove )

    # call the cartesian control API
    effector   = "Torso"
    space      =  motion.SPACE_NAO

    axisMask   = almath.AXIS_MASK_ALL
    isAbsolute = False

    motionProxy.positionInterpolation(effector, space, path,
                                      axisMask, times, isAbsolute)

if __name__ == "__main__":
    main()
