
import math
import numpy as np
import time 

def find_point(ball_loc, direction, kick_positions, positions):
    """ ball_loc are the coordinates of the ball, the direction are coordinates
    of where the ball should go. kick_positions is the position of the kicking
    leg and positions is the positions of the standing leg. Legs should be in
    normal pose"""
    # unpack leg positions
    kick_x, kick_y, kick_z = kick_positions
    pos_x, pos_y, pos_z = positions 
    # ball position relative to the kicking foot
    ball_loc = [0.3, 0, 0 ]
    # all boundaries for the kicking leg
    min_x = kick_positions[0] - 0.13641
    max_x = kick_positions[0] + 0.18485
    min_y = kick_positions[1] - 0.1340
    max_y = kick_positions[1] + 0.1014
    min_z = kick_positions[2] 
    max_z = kick_positions[2] + 0.1526
    print min_x
    print max_x
    print min_y
    print max_y
    # make ball position in world_space coordinates
    bal_x = kick_x + ball_loc[0]
    bal_y = kick_y + ball_loc[1]
    bal_z = kick_z + ball_loc[2]
    # make direction in world_space coordinates
    direction_x = kick_x + direction[0]
    direction_y = kick_y + direction[1]
    direction_z = kick_z + direction[2]
    direction = np.matrix([ [direction[0]], [direction[1]], [direction[2]]])
    # no retraction when other leg is there(change these values)
    if( pos_y < max_y or pos_y > min_y):
        if( abs(pos_y - max_y) > abs(pos_y - min_y)):
            min_y = pos_y
        else:
            max_y = pos_y
    best_pos = 0
    # make the minimal values compatible with xrange
    min_x_r = int(min_x*100)
    max_x_r = int(max_x*100)
    min_y_r = int(min_y*100)
    max_y_r = int(max_y*100)
    min_z_r = int(min_z*100)
    max_z_r = int(max_z*100)
    # make matrix of the world_space ball and direction coordinates
    bal_loc = np.matrix([[bal_x], [bal_y], [bal_z]])
    direction = np.matrix([[direction_x], [direction_y], [direction_z]])
    #print min_x, min_y, min_z
    for x in xrange(min_x_r, max_x_r, 1):
        for y in xrange(min_y_r, max_y_r, 1):
            for z in xrange(min_z_r, max_z_r, 1):
                #time.sleep(1)
                #print "xyz"
                #print x,y,z
                value = retractionPoint(bal_loc, np.matrix([[x/100.0], [y/100.0],
                    [z/100.0]]), direction, 1)
                if value > best_pos:
                    print value
                    best_pos = value
                    kick_x = x/100.0
                    kick_y = y/100.0
                    kick_z = z/100.0
    #print kick_x, kick_y, kick_z
    return [kick_x, kick_y, kick_z]


# the function that evaluates the best possible retraction point
def retractionPoint(ball_loc, point, direction, t, delta = 1 - 10**(-3) ):
    """ball_loc is the location of the ball, direction is a vector in a direction to
    kick the ball to"""
    # ball radius is given in mm
    ball_radius = 0.03342
    force_direction = direction
    # where to kick the ball
    contact_point = ball_loc - (direction * ball_radius) 
    #print "contact point:"
    #print contact_point
    (retract_distance ,output) = g(point, contact_point,  force_direction, t)
    return (1 - delta) * retract_distance + delta * ( 1+ output) 

# a function that returns the accuracy 
def g(point, contact_point, force_direction,t):
    """ point is a possible retraction point. 
    contact_point the place to hit the ball(coords), force_direction which
    way to move the foot"""
    #print "point"
    #print point
    #print "contact_point"
    #print contact_point
    retract_distance = math.sqrt(np.vdot(contact_point - point, contact_point - point))
    #print contact_point - point
    #print "retract_distance:"
    #print retract_distance
    final = np.vdot(np.power(contact_point - point, t), force_direction)/retract_distance
    return (retract_distance, final)

# tests the retraction point
def test_retraction(ip, kicking_leg, direction):
    """
    kicking_leg: LLeg or RLeg
    direction: a direction vector as python list
    """
    # create a motion proxy
    import sys
    sys.path.append("SDK")
    from naoqi import ALProxy
    mp = ALProxy("ALMotion", ip, 9559)

    # set the other leg's name
    other_leg = "RLeg" if kicking_leg == "LLeg" else "LLeg"

    normalPose(mp, True)

    kick_pos = mp.getPosition(kicking_leg, 1, True)[:3]
    other_pos = mp.getPosition(other_leg, 1, True)[:3]
    point = find_point("This is irrelevant!", direction, kick_pos, other_pos)
    point += [0, 0, 0] # make it 6d for cartesian control api

    # test the location!
    mp.setPosition(kicking_leg, 1, point, 0.3, 7)

def normalPose(motProxy, force = False): 
    anglelist = motProxy.getAngles(['RHipPitch','RKneePitch', 'RAnklePitch'],True)
    if force or not( posProxy.getActualPoseAndTime()[0] == 'Stand' and
                    -0.41 <= anglelist[0] <= -0.39 and
                    0.94 <= anglelist[1] <= 0.96 and 
                    -0.56 <= anglelist[2] <= -0.54):
        names = list()
        times = list()
        angles = list()
                
        names.extend( ['LShoulderPitch','LShoulderRoll','LElbowYaw','LElbowRoll','RShoulderPitch','RShoulderRoll'])
        angles.extend([[1.2],           [0.15],         [0.0],      [0.0],       [1.2],           [-0.15] ])
        times.extend( [[1.0],           [1.0],          [1.0],      [1.0],       [1.0],           [1.0  ] ])
 
        names.extend( ['RElbowYaw','RElbowRoll','LHipYawPitch','LHipRoll','LHipPitch','LKneePitch','LAnklePitch'])
        angles.extend([[0.0],      [0.0],       [0.0],         [0.0],     [-0.4],      [0.95],     [-0.55]])
        times.extend( [[1.0],      [1.0],       [1.0],         [1.0],     [1.0],       [1.0],      [1.0]])

        names.extend( ['LAnkleRoll', 'RHipRoll', 'RHipPitch', 'RKneePitch', 'RAnklePitch', 'RAnkleRoll'] )
        angles.extend([[0.0],        [0.0],      [-0.4],      [0.95],       [-0.55],       [0.0]] )
        times.extend( [[1.0],        [1.0],      [1.0],       [1.0],        [1.0],         [1.0]] )

        motProxy.angleInterpolation(names, angles, times, True)    
