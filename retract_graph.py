

#TODO: an initial mode is still needed
import math
import numpy as np
import time 

xy = []
z = []
distance_point = []
accuracy_point = [] 

x_pos = []
y_pos = []
z_pos = []

def find_point(ball_loc, direction, kick_positions, positions):
    """ ball_loc are the coordinates of the ball, the direction are coordinates
    of where the ball should go. kick_positions is the position of the kicking
    leg and positions is the positions of the standing leg. Legs should be in
    normal pose"""
    # unpack leg positions
    kick_x, kick_y, kick_z = kick_positions
    pos_x, pos_y, pos_z = positions 
    # ball position relative to the kicking foot
    ball_loc = [100, -100.55154471, 0.09521921 ]
    # all boundaries for the kicking leg
    min_x = int(kick_positions[0] - 75) #- 0.13641
    max_x = int(kick_positions[0] +75)
    #min_y = int(kick_positions[1] - 75)  #0.1340
    #max_y = int(kick_positions[1] + 75)#0.1014
    min_y =  -140
    max_y = -90
    #min_z = int(kick_positions[2] ) #0.05
    #max_z = int(kick_positions[2] + 50)  #0.1526
    min_z = 40
    max_z = 75

    # make ball position in world_space coordinates
    bal_x =  ball_loc[0]
    bal_y =  ball_loc[1]
    bal_z =  ball_loc[2]
    # make direction in world_space coordinates
    #direction_x = kick_x + direction[0]
    #direction_y = kick_y + direction[1]
    #direction_z = kick_z + direction[2]
    direction = np.matrix([ [direction[0]], [direction[1]], [direction[2]]])
    # no retraction when other leg is there(change these values)
    #if( pos_y < max_y or pos_y > min_y):
    #    if( abs(pos_y - max_y) > abs(pos_y - min_y)):
    #        min_y = pos_y
    #    else:
    #        max_y = pos_y
    best_pos = 0
    # make matrix of the world_space ball and direction coordinates
    bal_loc = np.matrix([[bal_x], [bal_y], [bal_z]])
    #direction = np.matrix([[direction_x], [direction_y], [direction_z]])
    for x in xrange(min_x, max_x, 10):
        for y in xrange(min_y, max_y, 10):
            for z in xrange(min_z, max_z, 10):
                global x_pos
                global y_pos
                global z_pos
                x_pos = x_pos + [x]
                y_pos = y_pos + [y]
                z_pos = z_pos + [z]
                contact_point, value = retractionPoint(bal_loc, np.matrix([[x], [y],
                    [z]]), direction, 1)
                #print "contact", contact_point
                if value > best_pos:
                    best_pos = value
                    kick_x = x
                    kick_y = y
                    kick_z = z
                
    contact = [contact_point[0,0], contact_point[1,0], contact_point[2,0]]
    return contact, [kick_x, kick_y, kick_z]


# the function that evaluates the best possible retraction point
def retractionPoint(ball_loc, point, direction, t, delta = 0.999 ):
    """ball_loc is the location of the ball, direction is a vector in a direction to
    kick the ball to"""
    # ball radius is given in meters
    ball_radius = 33.42
    force_direction = direction
    #print "dir", direction
    #print ball_radius
    # where to kick the ball
    contact_point = ball_loc - (direction * ball_radius) 
    (retract_distance ,output) = g(point, contact_point,  force_direction, ball_loc, t)
    
    return contact_point, (1 - delta) * retract_distance + delta * (output) 

# a function that returns the accuracy 
def g(point, contact_point, force_direction, ball_loc, t):
    """ point is a possible retraction point. 
    contact_point the place to hit the ball(coords), force_direction which
    way to move the foot"""
    # line equation = ball_loc + t*direction
    # distance to the ooi
    #distance = ( np.linalg.norm( np.cross((ball_loc[:2] - point[:2]), force_direction[:2], 0, 0) ) / 
    #    np.linalg.norm(force_direction[:2]))
    direction = force_direction
    force_direction = force_direction + contact_point
    print force_direction
    distance = np.linalg.norm(np.cross(point[:2] - contact_point[:2], point[:2] -
        force_direction[:2], 0 , 0)) / np.linalg.norm(abs(force_direction[:2] -
            contact_point[:2]))
    #the smaller the distance, the bigger the number
    distance = 100 / distance

    global accuracy_point 
    accuracy_point= accuracy_point + [distance]

    retract_distance_x = math.sqrt(np.vdot(contact_point[0] - point[0],
        contact_point[0] - point[0]))
    retract_distance_y = math.sqrt(np.vdot(contact_point[1] - point[1],
        contact_point[1] - point[1]))
    retract_distance_z = math.sqrt(np.vdot(contact_point[2] - point[2], contact_point[2] - point[2]))
    global xy
    xy = xy + [retract_distance_x + retract_distance_y]
    global z 
    z = z + [retract_distance_z * 0.3]

    retract_distance = 0
    # the retraction distance gets favored in the x and y directions
    retract_distance =  (direction[0] * retract_distance_x +
            direction[1] *
            retract_distance_y + 0.3 *  retract_distance_z)
            #force_direction[1] * retract_distance_y + force_direction[2] *  retract_distance_z)
    global distance_point 
    print retract_distance
    distance_point =  distance_point + [np.ndarray.tolist(retract_distance)[0][0]]
    return (retract_distance, distance)

# tests the retraction point
def test_retraction(kicking_leg, direction):
    """
    kicking_leg: LLeg or RLeg
    direction: a direction vector as python list
    """
    # create a motion proxy
    other_leg = "RLeg" if kicking_leg == "LLeg" else "LLeg"

    #mp.setStiffnesses("Body", 1)
    #normalPose(mp, True)

    
    kick_pos = [1.5962, -99.724, -0.18]
    other_pos = [0,0,0]
    contact_point ,point = find_point("This is irrelevant!", direction, kick_pos, other_pos)
    global xy
    print xy
    global z
    print z 
    global distance_point
    print distance_point
    global accuracy_point 
    print  accuracy_point 
   # global x_pos
   # global y_pos
   # print x_pos
   # print y_pos
   # print contact_point
   # print point


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

def bezier_list(p0, p1, p2):
    positions = []
    for t in [0, 0.25, 0.50, 0.75, 1]:
        positions.append( (1-t)**2 * p0 + 2*(1-t)*t*p1 + t**2 *p2)

    return positions

def initial_pose(mp):
    """ args:
            mp: a MotionProxy
    """
    joints = ['LHipPitch', 'RHipPitch', 'LKneePitch', 'RKneePitch']
    ankles = ['LAnklePitch', 'RAnklePitch']

    joint_angles = mp.getAngles(joints, True)
    ankle_angles = mp.getAngles(ankles, True)

    # actuation
    mp.setAngles(joints, joint_angles, 0.1)
    time.sleep(0.375)
    mp.setAngles(ankles, ankle_angles, 0.1)
