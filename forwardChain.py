from numpy import matrix
import sys
sys.path.append("SDK")
from math import cos, sin, pi
from naoqi import ALProxy

def main(ip, leg):
    mot = ALProxy("ALMotion", ip, 9559)
    forward_chain(leg, mot)

# gets the position of one of the legs in pseudo-torso coordinates (a la Bhuman)
def forward_chain(leg, mot):
    """ leg is the leg for which to get the position in torso coordinates"""
    # list of all joint offsets
    jointOffsets = {
            ("Torso", "HeadYaw")                : ([0.0, 0.0, 126.50 ], -1),
            ("HeadYaw", "Torso")                : ([0.0, 0.0, -126.50 ], 1),
            ("HeadYaw","HeadPitch")             : ([0.0, 0.0, 0.0 ], -1),
            ("HeadPitch","HeadYaw")             : ([0.0, 0.0, 0.0 ], 1),
            ("Torso", "LShoulderPitch")         : ([0.0, 98.0, 100.00 ], -1),
            ("LShoulderPitch", "Torso")         : ([0.0, -98.0, -100.00 ], 1),
            ("LShoulderPitch", "LShoulderRoll") : ([0.0, 0.0, 0.0], -1),
            ("LShoulderRoll", "LShoulderPitch") : ([0.0, 0.0, 0.0], 1),
            ("LShoulderRoll", "LElbowYaw" )     : ([105.00, 15.00, 0.00], -1),
            ("LElbowYaw", "LShoulderRoll" )     : ([-105.00, -15.00, 0.00], 1),
            ("LElbowYaw", "LElbowRoll")         : ([0, 0, 0], -1),
            ("LElbowRoll", "LElbowYaw")         : ([0, 0, 0], 1),
            ("LElbowRoll", "LWristYaw")         : ([55.95, 0, 0 ], -1),
            ("LWristYaw", "LElbowRoll")         : ([-55.95, 0, 0 ], 1),
            ("Torso", "LHipYawPitch")           : ([0, 50.0, -85.0], -1),
            ("LHipYawPitch", "Torso")           : ([0, -50.0, 85.0], 1),
            ("LHipYawPitch", "LHipRoll")        : ([0.0 , 0.0, 0.0], -1),
            ("LHipRoll", "LHipYawPitch")        : ([0.0 , 0.0, 0.0], 1),
            ("LHipRoll", "LHipPitch")           : ([0.0, 0.0, 0.0], -1),
            ("LHipPitch", "LHipRoll")           : ([0.0, 0.0, 0.0], 1),
            ("LHipPitch", "LKneePitch")         : ([0.0, 0.0, -100.0], -1),
            ("LKneePitch", "LHipPitch")         : ([0.0, 0.0, 100.0], 1),
            ("LKneePitch","LAnklePitch")        : ([0.0, 0.0, -102.9], -1),
            ("LAnklePitch","LKneePitch")        : ([0.0, 0.0, 102.9], 1),
            ("LAnklePitch", "LAnkleRoll")       : ([0.0, 0.0, 0.0], -1),
            ("LAnkleRoll", "LAnklePitch")       : ([0.0, 0.0, 0.0], 1),
            ("Torso", "RShoulderPitch")         : ([0.0, -98.0, 100.00 ], -1),
            ("RShoulderPitch", "Torso")         : ([0.0, 98.0, -100.00 ], 1),
            ("RShoulderPitch", "RShoulderRoll") : ([0.0, 0.0, 0.0], -1),
            ("RShoulderRoll", "RShoulderPitch") : ([0.0, 0.0, 0.0], 1),
            ("RShoulderRoll", "RElbowYaw" )     : ([105.00, -15.00, 0.00],  -1),
            ("RElbowYaw", "RShoulderRoll" )     : ([-105.00, 15.00, 0.00], 1),
            ("RElbowYaw", "RElbowRoll")         : ([0, 0, 0], -1),
            ("RElbowRoll", "RElbowYaw")         : ([0, 0, 0], 1),
            ("RElbowRoll", "RWristYaw")         : ([55.95, 0, 0 ], -1),
            ("RWristYaw", "RElbowRoll")         : ([-55.95, 0, 0 ], 1),
            ("Torso", "RHipYawPitch")           : ([0, -50.0, 0], -1),
            ("RHipYawPitch", "Torso")           : ([0, 50.0, 0], 1),
            ("RHipYawPitch", "RHipRoll")        : ([0.0 , 0.0, 0.0], -1),
            ("RHipRoll", "RHipYawPitch")        : ([0.0 , 0.0, 0.0], 1),
            ("RHipRoll", "RHipPitch")           : ([0.0, 0.0, 0.0], -1),
            ("RHipPitch", "RHipRoll")           : ([0.0, 0.0, 0.0], 1),
            ("RHipPitch", "RKneePitch")         : ([0.0, 0.0, -100.0], -1),
            ("RKneePitch", "RHipPitch")         : ([0.0, 0.0, 100.0], 1),
            ("RKneePitch","RAnklePitch")        : ([0.0, 0.0, -102.9], -1),
            ("RAnklePitch","RKneePitch")        : ([0.0, 0.0, 102.9], 1),
            ("RAnklePitch", "RAnkleRoll")       : ([0.0, 0.0, 0.0], -1),
            ("RAnkleRoll", "RAnklePitch")       : ([0.0, 0.0, 0.0], 1),
            ( None, "Torso")                    : ([0.0, 0.0, 0.0], -1)
            }
    if leg == "RLeg":
        l = "R"
    else:
        l = "L"

    path = [ "Torso", str(l) + "HipYawPitch", str(l) + "HipRoll", str(l) +
            "HipPitch", str(l) + "KneePitch", str(l) + "AnklePitch", str(l)
            + "AnkleRoll"]

    #starting point of the matrix
    T = matrix([[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]])
    print "initial T", T

    for previous, current in ((path[i-1], path[i]) for i in xrange(1,
        len(path))):
        
        _, direction = jointOffsets[(previous, current)]
        #stupid hack, still needs changing
        direction *= -1 
        T = T * translation_matrix(previous, current, jointOffsets)
        T = T * rotation_matrix(current, direction, mot)
        print current, T[:, 3]
    print T



# constructs a transformation matrix for shifting from the previous
# coordinate-system to the current one
def translation_matrix( previous, current, jointOffsets):
    # get the x, y and z offset values
    if previous == None:
        offsets = [0, 0, 0]
    else:
        offsets, _ = jointOffsets[(previous, current)]

    rotation = [[1, 0, 0],
                [0, 1, 0],
                [0, 0, 1]]

    # merge the rotation and translation together
    rotation[0].append(offsets[0])
    rotation[1].append(offsets[1])
    rotation[2].append(offsets[2])
    rotation.append([0, 0, 0, 1]) # homogenous stuff

    return matrix(rotation)




def rotation_matrix(joint, towards_torso, mot, online=True, joint_dict=None):

    if online:
        mot.getAngles(joint, True)
    else:
        get_angles = lambda x: joint_dict[x]

    # get the 3x3 rotation matrix using the angle of the joint
    # there's a special exception for the Torso, which isn't a joint
    if joint != "Torso":
        angle = mot.getAngles(joint, True)[0] * towards_torso
    else:
        angle = 0

    # special case for the crazy-ass hip
    # we split the angle up in two components, the yaw and pitch, and
    # divide the angle evenly between them (the joint is set at a 45
    # degree angle)
    #
    # FIXME: might need to do something extra to handle the 45 degree 
    # rotation
    if "YawPitch" in joint:
        h_angle = angle / 2.0
        yaw_component = matrix([[cos(h_angle), -sin(h_angle), 0],
                                [sin(h_angle), cos(h_angle), 0],
                                [0, 0, 1]])

        pitch_component = matrix([[cos(h_angle), 0, sin(h_angle)],
                                  [0, 1, 0],
                                  [-sin(h_angle), 0, cos(h_angle)]])

        # 45 degree (1/4 pi) component
        roll_component = matrix([[1, 0, 0],
                                 [0, cos(0.25*pi * towards_torso), -sin(0.25*pi * towards_torso)],
                                 [0, sin(0.25*pi * towards_torso), cos(0.25*pi * towards_torso)]])

        # convert it back to a list representation for the next part of the
        # function
        rotation = (yaw_component * pitch_component).tolist()

    elif "Roll" in joint:
        rotation = [[1, 0, 0],
                    [0, cos(angle), -sin(angle)],
                    [0, sin(angle), cos(angle)]]
    elif "Pitch" in joint:
        rotation = [[cos(angle), 0, sin(angle)],
                    [0, 1, 0],
                    [-sin(angle), 0, cos(angle)]]
    elif "Yaw" in joint:
        rotation = [[cos(angle), -sin(angle), 0],
                    [sin(angle), cos(angle), 0],
                    [0, 0, 1]]
    # the silly Torso isn't a joint
    elif "Torso" in joint:
        rotation = [[1, 0, 0],
                    [0, 1, 0],
                    [0, 0, 1]]

    # merge the rotation and translation together
    rotation[0].append(0)
    rotation[1].append(0)
    rotation[2].append(0)
    rotation.append([0, 0, 0, 1]) # homogenous stuff

    return matrix(rotation)

