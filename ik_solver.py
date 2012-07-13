from numpy import matrix
from numpy.linalg import norm, inv
from math import cos, sin, pi, acos, atan2, sqrt, asin

def get_angles(foot_to_torso, leg):
    """ returns a dictionary of joint angles required to reach the given
    foot-position. The footposition is given as a homogenous 4x4 numpy matrix
    that transforms foot-coordinates into torso-coordinates.
    The calculation is done according to B-Human's analytic solution.
    This leg parameter is either the string LLeg or RLeg. """

    sign = -1 if leg == "LLeg" else 1

    angles = {}

    # first we define a number of coordinate translations
    # translations are done in millimeters
    foot_to_hip = trans(y=50*sign) * foot_to_torso
    foot_to_hip_orth = rotation_x(pi/4.0, sign) * foot_to_hip
    hiporth_to_foot = inv(foot_to_hip_orth)

    # get the knee-angle
    l_upperleg = 100
    l_lowerleg = 102.90

    trans_vector = hiporth_to_foot[:3, 3]
    l_trans = norm(trans_vector) # length of translation vector
    gamma = acos( (l_upperleg**2 + l_lowerleg**2 - l_trans**2) /
                  (2 * l_upperleg * l_lowerleg) )

    delta_knee = pi - gamma
    angles["KneePitch"] = delta_knee

    # now all the foot-angles
    delta_footpitch1 = acos((l_lowerleg**2 + l_trans**2 - l_upperleg**2) /
                              (2 * l_lowerleg * l_trans))
    delta_footpitch2 = atan2(foot_to_hip_orth[0, 3],
       sqrt(foot_to_hip_orth[1, 3]**2 +foot_to_hip_orth[2, 3]**2))

    # now we got the footpitch
    delta_footpitch = delta_footpitch1 + delta_footpitch2
    angles["AnklePitch"] = delta_footpitch

    # and here comes the footroll
    delta_footroll = atan2(foot_to_hip_orth[1, 3], foot_to_hip_orth[2, 3]) * sign
    angles["AnkleRoll"] = delta_footroll

    # now for the other angles
    thigh_to_foot = (rotation_x(delta_footroll) * rotation_y(delta_footpitch) *
        trans(z=l_lowerleg) * rotation_y(delta_knee) * trans(z=l_upperleg) )

    hiporth_to_thigh = inv(thigh_to_foot) * hiporth_to_foot

    # the hip angles can be extracted from the rotational part of
    # hiporth_to_thigh
    rot_component = hiporth_to_thigh[:3, :3]

    delta_x = asin(rot_component[2, 1])
    delta_hipyaw = atan2(-rot_component[0, 1], rot_component[1, 1]) * -sign
    delta_hippitch = atan2(-rot_component[2, 0], rot_component[2, 2])
    delta_hiproll = delta_x - (pi / 4.0) * sign

    angles["HipYawPitch"] = delta_hipyaw
    angles["HipPitch"] = delta_hippitch
    angles["HipRoll"] = delta_hiproll

    # we're done!
    return angles


def trans(x=0, y=0, z=0):
    """ returns a homogenous translation matrix """
    return matrix(
        [[1, 0, 0, x],
         [0, 1, 0, y],
         [0, 0, 1, z],
         [0, 0, 0, 1]])

def rotation_x(angle, sign=1):
    """ returns a homogenous rotation matrix over the x-axis """
    return matrix(
        [[1, 0,                  0,                 0],
         [0, cos(angle),         sin(angle) * sign, 0],
         [0, sin(angle) * -sign, cos(angle),        0],
         [0, 0,                  0,                 1]])

def rotation_y(angle):
    """ returns a homogenous rotation matrix over the y-axis """
    return matrix(
        [[cos(angle),  0, sin(angle), 0],
         [0,           1, 0,          0],
         [-sin(angle), 0, cos(angle), 0],
         [0,           0, 0,          1]])

def rotation_z(angle):
    """ returns a homogenous rotation matrix over the z-axis """
    return matrix(
        [[cos(angle), -sin(angle), 0, 0],
         [sin(angle), cos(angle),  0, 0],
         [0,          0,           1, 0],
         [0,          0,           0, 1]])

def set_position(mp, leg, location, speed):
    """ Sets the desired end-effector at the given locations.
    mp: an ALMotion proxy
    Leg: LLeg or RLeg
    Location: a 6d vector (x, y, z, rx, ry, rz) describing the foot relative
    to the torso.
    Speed: the speed with which to change the joint angles """

    x, y, z, rx, ry, rz = location
    location_matrix = (rotation_x(rx) * rotation_y(ry) * rotation_z(rz) *
        trans(x=x, y=y, z=z))

    angles = get_angles(location_matrix, leg)
    angles = angles.items()
    leg_prefix = "L" if leg == "LLeg" else "R"

    joint_list = [(leg_prefix + j) for j, _ in angles]
    angle_list = [v for _, v in angles]

    mp.setAngles(joint_list, angle_list, speed)