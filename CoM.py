import sys

# adding the Naoqi Python SDK to the path
sys.path.append("SDK")

from numpy import matrix
from naoqi import ALProxy
from math import cos, sin
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
                "Torso"           : ( [-4.15,  0.07,   42.58,   1.03948]),
                ######### Misschien niet de juiste versie################
                "HeadPitch"       : ( [1.20,  -0.84,   53.53],  0.52065)}
     

    jointOffsets = {
            ("Torso", "HeadYaw")                : [0.0, 0.0, 126.50 ],
            ("HeadYaw", "Torso")                : [0.0, 0.0, -126.50 ],
            ("HeadYaw","HeadPitch")             : [0.0, 0.0, 0.0 ],
            ("HeadPitch","HeadYaw")             : [0.0, 0.0, 0.0 ],
            ("Torso", "LShoulderPitch")         : [0.0, 98.0, 100.00 ],
            ("LShoulderPitch", "Torso")         : [0.0, 98.0, -100.00 ],
            ("LShoulderPitch", "LShoulderRoll") : [0.0, 0.0, 0.0],
            ("LShoulderRoll", "LShoulderPitch") : [0.0, 0.0, 0.0],
            ("LShoulderRoll", "LElbowYaw" )     : [105.00, 15.00, 0.00],        
            ("LElbowYaw", "LShoulderRoll" )     : [105.00, 15.00, 0.00],        
            ("LElbowYaw", "LElbowRoll")         : [0, 0, 0],
            ("LElbowRoll", "LElbowYaw")         : [0, 0, 0],
            ("LElbowRoll", "LWristYaw")         : [55.95, 0, 0 ],
            ("LWristYaw", "LElbowRoll")         : [55.95, 0, 0 ],
            ("Torso", "LHipYawPitch")           : [0, 50.0, -85.0],
            ("LHipYawPitch", "Torso")           : [0, 50.0, 85.0],
            ("LHipYawPitch", "LHipRoll")        : [0.0 , 0.0, 0.0],
            ("LHipRoll", "LHipYawPitch")        : [0.0 , 0.0, 0.0],
            ("LHipRoll", "LHipPitch")           : [0.0, 0.0, 0.0],
            ("LHipPitch", "LHipRoll")           : [0.0, 0.0, 0.0],
            ("LHipPitch", "LKneePitch")         : [0.0, 0.0, -100.0],
            ("LKneePitch", "LHipPitch")         : [0.0, 0.0, 100.0],
            ("LKneePitch","LAnklePitch")        : [0.0, 0.0, -102.9],
            ("LAnklePitch","LKneePitch")        : [0.0, 0.0, 102.9],
            ("LAnklePitch", "LAnkleRoll")       : [0.0, 0.0, 0.0],
            ("LAnkleRoll", "LAnklePitch")       : [0.0, 0.0, 0.0],
            ("Torso", "RShoulderPitch")         : [0.0, -98.0, 100.00 ],
            ("RShoulderPitch", "Torso")         : [0.0, -98.0, -100.00 ],
            ("RShoulderPitch", "RShoulderRoll") : [0.0, 0.0, 0.0],
            ("RShoulderRoll", "RShoulderPitch") : [0.0, 0.0, 0.0],
            ("RShoulderRoll", "RElbowYaw" )     : [105.00, -15.00, 0.00],        
            ("RElbowYaw", "RShoulderRoll" )     : [105.00, -15.00, 0.00],        
            ("RElbowYaw", "RElbowRoll")         : [0, 0, 0],
            ("RElbowRoll", "RElbowYaw")         : [0, 0, 0],
            ("RElbowRoll", "RWristYaw")         : [55.95, 0, 0 ],
            ("RWristYaw", "RElbowRoll")         : [55.95, 0, 0 ],
            ("Torso", "RHipYawPitch")           : [0, -50.0, -85.0],
            ("RHipYawPitch", "Torso")           : [0, -50.0, 85.0],
            ("RHipYawPitch", "RHipRoll")        : [0.0 , 0.0, 0.0],
            ("RHipRoll", "RHipYawPitch")        : [0.0 , 0.0, 0.0],
            ("RHipRoll", "RHipPitch")           : [0.0, 0.0, 0.0],
            ("RHipPitch", "RHipRoll")           : [0.0, 0.0, 0.0],
            ("RHipPitch", "RKneePitch")         : [0.0, 0.0, -100.0],
            ("RKneePitch", "RHipPitch")         : [0.0, 0.0, 100.0],
            ("RKneePitch","RAnklePitch")        : [0.0, 0.0, -102.9],
            ("RAnklePitch","RKneePitch")        : [0.0, 0.0, 102.9],
            ("RAnklePitch", "RAnkleRoll")       : [0.0, 0.0, 0.0],
            ("RAnkleRoll", "RAnklePitch")       : [0.0, 0.0, 0.0]
            }

    # constructor, initalizes the ALProxy
    def __init__(self, ip_address, port):
        self.motion_proxy = ALProxy("ALMotion", ip_address, port)

    # returns the center of mass of a given part
    def get_CoM(self, leg):
        # TODO: add the HipYawPitches to the lists
        path = {
                "LLeg" : ("LAnkleRoll", "LAnklePitch", "LKneePitch", "LHipPitch",
                    "LHipRoll, LHipYawPitch", "Torso"),
                "RLeg" : ("RAnkleRoll", "RAnklePitch", "RKneePitch", "RHipPitch",
                    "RHipRoll, RHipYawPitch", "Torso")
                }.get(leg)

        # initial transformation matrix
        T = matrix([[1, 0, 0, 0],
                    [0, 1, 0, 0],
                    [0, 0, 1, 0],
                    [0, 0, 0, 1]])

        # initial weighted CoM location based on the first element of the path
        centroid, mass = self.jointCOM[path[0]]
        centroid = matrix(centroid + [1]).transpose()
        total_CoM = mass * centroid
        total_mass = mass

        # loop through every element except the first, along with its
        # previous element
        for current, previous in ((path[i], path[i-1]) 
                for i in xrange(1, len(path))):
            # update the transformation matrix to calculate the centroid location
            T = T * self.transformation_matrix(previous, current)

            # FIXME: debug
            print current + ":"
            print T * matrix([0, 0, 0, 1]).transpose()

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
            branch_com, branch_mass = com_from_torso(deepcopy(T), branch)
            
            total_CoM += branch_com
            total_mass += branch_mass

        # the final CoM is the total weighted CoM location divided by the total
        # weight
        return total_CoM / float(total_mass)

    # returns the center of mass and total weight of a specific bodypart
    def com_from_torso(T, part):
        path = {
                "LLeg" : ("Torso", "LHipYawPitch", "LHipRoll", "LHipPitch", "LKneePitch",
                    "LAnklePitch", "LAnkleRoll"),
                "RLeg" : ("Torso", "RHipYawPitch", "RHipRoll", "RHipPitch", "RKneePitch",
                    "RAnklePitch", "RAnkleRoll"),
                "LArm" : ("Torso", "LShoulderPitch", "LShoulderRoll", "LElbowYaw",
                    "LElbowRoll", "LWristYaw"),
                "RArm" : ("Torso", "RShoulderPitch", "RShoulderRoll", "RElbowYaw",
                    "RElbowRoll", "RWristYaw"),
                "Head" : ("Torso", "HeadYaw", "HeadPitch")
                }.get(part)

        # loop through every element except the first, along with its
        # previous element
        mass = 0
        for current, previous in ((path[i], path[i-1]) 
                for i in xrange(1, len(path))):
            # update the transformation matrix to calculate the centroid location
            T = T * self.transformation_matrix(previous, current)

            # FIXME: debug
            print current + ":"
            print T * matrix([0, 0, 0, 1]).transpose()

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
    def transformation_matrix(self, previous, current):
        # get the x, y and z offset values
        offsets = self.jointOffsets[(previous, current)]

        # get the 3x3 rotation matrix using the angle of the previous joint
        angle = self.motion_proxy.getAngles(previous, False)[0]

        # special case for the crazy-ass hip
        # we split the angle up in two components, the yaw and pitch, and
        # divide the angle evenly between them (the joint is set at a 45
        # degree angle)
        #
        # FIXME: might need to do something extra to handle the 45 degree 
        # rotation
        if "YawPitch" in previous:
            h_angle = angle / 2.0
            yaw_component = matrix([[cos(h_angle), -sin(h_angle), 0],
                                    [sin(h_angle), cos(h_angle), 0],
                                    [0, 0, 1]])

            pitch_component = matrix([[cos(h_angle), 0, -sin(h_angle)],
                                      [0, 1, 0],
                                      [sin(h_angle), 0, cos(h_angle)]])

            # convert it back to a list representation for the next part of the
            # function
            rotation = (yaw_component * pitch_component).tolist()

        elif "Roll" in previous:
            rotation = [[1, 0, 0],
                        [0, cos(angle), -sin(angle)],
                        [0, sin(angle), cos(angle)]]
        elif "Pitch" in previous:
            rotation = [[cos(angle), 0, -sin(angle)],
                        [0, 1, 0],
                        [sin(angle), 0, cos(angle)]]
        elif "Yaw" in previous:
            rotation = [[cos(angle), -sin(angle), 0],
                        [sin(angle), cos(angle), 0],
                        [0, 0, 1]]

        # merge the rotation and translation together
        rotation[0].append(offsets[0])
        rotation[1].append(offsets[1])
        rotation[2].append(offsets[2])
        rotation.append([0, 0, 0, 1]) # homogenous stuff

        return matrix(rotation)

if __name__ == '__main__':
    com = CenterOfMass("10.0.0.35", 9559)
    com.get_CoM("RLeg")
