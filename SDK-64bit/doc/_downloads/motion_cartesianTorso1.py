#-*- coding: iso-8859-15 -*-

''' Cartesian control: Torso trajectory '''

import config
import motion
import almath

def main():
    ''' Example showing a path of five positions
    Needs a PoseInit before execution
    '''

    motionProxy = config.loadProxy("ALMotion")

    # Set NAO in Stiffness On
    config.StiffnessOn(motionProxy)

    # Send NAO to Pose Init
    config.PoseInit(motionProxy)

    effector   = "Torso"
    space      =  motion.SPACE_WORLD

    # Position Only
    axisMask   = almath.AXIS_MASK_ALL           # full control
    isAbsolute = False

    # Define the changes relative to the current position
    dx         = 0.045                          # translation axis X (meter)
    dy         = 0.050                          # translation axis Y (meter)

    path       = [
      [+dx, 0.0, 0.0, 0.0, 0.0, 0.0],           # point 1
      [0.0, -dy, 0.0, 0.0, 0.0, 0.0],           # point 2
      [-dx, 0.0, 0.0, 0.0, 0.0, 0.0],           # point 3
      [0.0, +dy, 0.0, 0.0, 0.0, 0.0],           # point 4
      [+dx, 0.0, 0.0, 0.0, 0.0, 0.0],           # point 5
      [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]]           # point 6

    times      = [1.0, 2.0, 3.0, 4.0, 5.0, 6.0] # seconds
    motionProxy.positionInterpolation(effector, space, path,
                                axisMask, times, isAbsolute)

if __name__ == "__main__":
    main()
