import sys, re, platform
from cStringIO import StringIO

# adding the correct Naoqi Python SDK to the path

# linux
if 'linux' in sys.platform:
    if platform.machine() == 'x86_64':
        sys.path.append("SDK-64bit")
    else:
        sys.path.append("SDK")

# windows
else:
    # could potentially add the windows SDK here
    pass


from numpy import matrix
from naoqi import ALProxy
from math import cos, sin, pi
from copy import deepcopy

class CenterOfMass():
    #TODO: voor Linker joints y even inverse waarde geven
                # center of mass        x           y        z
    jointCOM = {"RAnkleRoll"      : ( [25.40,  -3.32, -32.41],  0.16175 ),
                "LAnkleRoll"      : ( [25.40,  3.32, -32.41],  0.16175 ),
                "RAnklePitch"     : ( [1.42,   -0.28,  6.38],  0.13892 ),
                "LAnklePitch"     : ( [1.42,   0.28,  6.38],  0.13892 ),
                "RKneePitch"      : ( [4.22,   -2.52, -48.68],  0.25191 ),
                "LKneePitch"      : ( [4.22,   2.52, -48.68],  0.25191 ),
                "RHipPitch"       : ( [1.32,   -2.35, -53.52],  0.39421 ),
                "LHipPitch"       : ( [1.32,   2.35, -53.52],  0.39421 ),
                "RHipRoll"        : ( [-16.49, -0.29, -4.75],  0.13530),
                "LHipRoll"        : ( [-16.49, 0.29, -4.75],  0.13530),
                "RHipYawPitch"    : ( [-7.66,  12.00,  27.17 ], 0.07117 ),
                "LHipYawPitch"    : ( [-7.66,  -12.00,  27.17 ], 0.07117 ),
                "RElbowRoll"      : ( [65.36,  -0.34, -0.02],  0.18500 ),
                "LElbowRoll"      : ( [65.36,  0.34, -0.02],  0.18500 ),
                "RElbowYaw"       : ( [-25.60,  0.01, -0.19],  0.05971),
                "LElbowYaw"       : ( [-25.60, - 0.01, -0.19],  0.05971),
                "RShoulderRoll"   : ( [18.85,  -5.77,  0.65],  0.12309),
                "LShoulderRoll"   : ( [18.85,  5.77,  0.65],  0.12309),
                "RShoulderPitch"  : ( [-1.78,  24.96,  0.18],  0.06996 ),
                "LShoulderPitch"  : ( [-1.78,  -24.96,  0.18],  0.06996 ),
                "HeadYaw"         : ( [-0.02,  0.17,  -25.56],  0.05930),
                "Torso"           : ( [-4.15,  0.07,   42.58],   1.03948),
                ######### Misschien niet de juiste versie################
                "HeadPitch"       : ( [1.20,  -0.84,   53.53],  0.52065)}
     
    # (x, y, z),  is towards torso (1) or not(-1)
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
            ("Torso", "RHipYawPitch")           : ([0, -50.0, -85.0], -1),
            ("RHipYawPitch", "Torso")           : ([0, 50.0, 85.0], 1),
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

            # special endvalues
            (None, "RAnkleRoll")                : ([0.0, 0.0, 0.0], 1),
            ("RAnkleRoll", None)                : ([0.0, 0.0, 0.0], -1),
            (None, "LAnkleRoll")                : ([0.0, 0.0, 0.0], 1),
            ("LAnkleRoll", None)                : ([0.0, 0.0, 0.0], -1)
            }

    # constructor, initalizes the ALProxy
    def __init__(self, ip_address, port):
        self.motion_proxy = ALProxy("ALMotion", ip_address, port)

    # returns the center of mass of a given part
    def get_CoM(self, leg):
        path = {
                "LLeg" : (None, "LAnkleRoll", "LAnklePitch", "LKneePitch", "LHipPitch",
                    "LHipRoll", "LHipYawPitch", "Torso"),
                "RLeg" : (None, "RAnkleRoll", "RAnklePitch", "RKneePitch", "RHipPitch",
                    "RHipRoll", "RHipYawPitch", "Torso")
                }.get(leg)

        # initial transformation matrix
        T = matrix([[1, 0, 0, 0],
                    [0, 1, 0, 0],
                    [0, 0, 1, 0],
                    [0, 0, 0, 1]])

        # initial values
        total_CoM = matrix([0, 0, 0, 1]).transpose()
        total_mass = 0

        # loop through every element except the first, along with its
        # previous element
        for current, previous in ((path[i], path[i-1]) 
                for i in xrange(1, len(path))):
            # update the transformation matrix to calculate the centroid location
            _, towards_torso = self.jointOffsets[previous, current]
            towards_torso *= -1
            T = T * self.translation_matrix(previous, current)
            T = T * self.rotation_matrix(current, towards_torso)

            # FIXME: debug
            print '"' + current + '"' + ":"
            print T * matrix([0, 0, 0, 1]).transpose(), ","

            # multiply the transformed centroid with its weight and update the
            # total CoM and mass
            centroid, mass = self.jointCOM[current]
            centroid = matrix(centroid + [1]).transpose()
            centroid = T * centroid

            total_CoM += mass * centroid
            total_mass += mass

        # now calculate all other branches from the torso
        branches = [("LLeg" if leg == "RLeg" else "RLeg"), "LArm", "RArm", "Head"]
        for branch in branches:
            branch_com, branch_mass = self.com_from_torso(deepcopy(T), branch)

            total_CoM += branch_com
            total_mass += branch_mass

        # the final CoM is the total weighted CoM location divided by the total
        # weight
        return total_CoM / float(total_mass)

    # returns the center of mass and total weight of a specific bodypart
    def com_from_torso(self, T, part):
        path = {
                "LLeg" : ("Torso", "LHipYawPitch", "LHipRoll", "LHipPitch", "LKneePitch",
                    "LAnklePitch", "LAnkleRoll"),
                "RLeg" : ("Torso", "RHipYawPitch", "RHipRoll", "RHipPitch", "RKneePitch",
                    "RAnklePitch", "RAnkleRoll"),
                "LArm" : ("Torso", "LShoulderPitch", "LShoulderRoll", "LElbowYaw",
                    "LElbowRoll"),
                "RArm" : ("Torso", "RShoulderPitch", "RShoulderRoll", "RElbowYaw",
                    "RElbowRoll"),
                "Head" : ("Torso", "HeadYaw", "HeadPitch")
                }.get(part)

        # loop through every element except the first, along with its
        # previous element
        total_mass = 0
        total_CoM = T * matrix([[0], [0], [0], [1]]) # start at the torso location
        for current, previous in ((path[i], path[i-1]) 
                for i in xrange(1, len(path))):
            # update the transformation matrix to calculate the centroid location
            _, towards_torso = self.jointOffsets[previous, current]
            towards_torso *= -1
            T = T * self.translation_matrix(previous, current)
            T = T * self.rotation_matrix(current, towards_torso)

            # FIXME: debug
            print '"' + current + '"' + ":"
            print T * matrix([0, 0, 0, 1]).transpose(), ","

            # multiply the transformed centroid with its weight and update the
            # total CoM and mass
            centroid, mass = self.jointCOM[current]
            centroid = matrix(centroid + [1]).transpose()
            centroid = T * centroid

            total_CoM += mass * centroid
            total_mass += mass

        return total_CoM, total_mass


    # constructs a transformation matrx for shifting from the previous
    # coordinate-system to the current one
    def translation_matrix(self, previous, current):
        # get the x, y and z offset values
        if previous == None:
            offsets = [0, 0, 0]
        else:
            offsets, _ = self.jointOffsets[(previous, current)]

        rotation = [[1, 0, 0],
                    [0, 1, 0],
                    [0, 0, 1]]

        # merge the rotation and translation together
        rotation[0].append(offsets[0])
        rotation[1].append(offsets[1])
        rotation[2].append(offsets[2])
        rotation.append([0, 0, 0, 1]) # homogenous stuff

        return matrix(rotation)

    def rotation_matrix(self, joint, towards_torso):
        # get the 3x3 rotation matrix using the angle of the joint
        # there's a special exception for the Torso, which isn't a joint
        if joint != "Torso":
            angle = self.motion_proxy.getAngles(joint, True)[0] * towards_torso
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


# a debug wrapper for the CenterOfMass class
# prints a dictionary of joint locations to the file "debug_com.txt"
class DebugCoM(CenterOfMass):
    def __init__(self, ip_address, port):
        CenterOfMass.__init__(self, ip_address, port)

    def get_CoM(self, leg):
        # backup the old stdout and set the new one to a StringIO
        old_stdout = sys.stdout
        sys.stdout = stringout = StringIO()

        # call the regular function, with the output surrounded by braces to
        # make it the output a proper dictionary
        print "{"
        com = CenterOfMass.get_CoM(self, leg)
        print "}"

        # restore the regular stdout
        sys.stdout = old_stdout

        # write the captured output to a file
        output = stringout.getvalue()

        # adds commas to the places that need one
        comma_regex = re.compile(r"""
            ([^\]])         # any character that is not a ']'
            ]               # followed by a ']'
            ([^\]])         # any character that is not a ']'
            """, re.VERBOSE)
        
        output = re.sub(comma_regex, r'\1],\2', output)
        output = re.sub(r",\n}", '\n}', output)  # remove the last comma
        with open("debug_com.txt", 'w') as f:
            f.write(output)

        # return the regular value
        return com

if __name__ == '__main__':
    com = CenterOfMass("10.0.0.38", 9559)
    com.get_CoM("RLeg")
