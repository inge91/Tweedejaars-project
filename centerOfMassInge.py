import sys

# adding the Naoqi Python SDK to the path
sys.path.append("SDK")

from numpy import matrix
from naoqi import ALProxy
from math import cos, sin

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
    def get_CoM(self, part):
        # TODO: add the HipYawPitches to the lists
        path = {
                "LLeg" : ("LAnkleRoll", "LAnklePitch", "LKneePitch", "LHipPitch",
                    "LHipRoll"),
                "RLeg" : ("RAnkleRoll", "RAnklePitch", "RKneePitch", "RHipPitch",
                    "RHipRoll")
                }.get(part)

        # initial transformation matrix
        T1 = matrix([[1, 0, 0, 0],
                    [0, 1, 0, 0],
                    [0, 0, 1, 0],
                    [0, 0, 0, 1]])
        # first work up to the torso 
        c1, m1 = self.jointCOM[part + 'AnkleRoll']
        c1 = matrix(c1 + [1]).transpose()
        f1 = m1 * (T1 * c1) 
        total_mass += m1

        c2, m2 = self.jointCOM[part + 'AnklePitch'] 
        c2 = matrix(c2 + [1]).transpose()
        T2 = transformation_matrix(part + 'AnkleRoll', part + 'AnklePitch')
        f2 = m2 * ((T1 * T2) * c2)    
        total_mass += m2

        c3, m3 = self.jointCOM[part+'KneePitch']
        T3 = transformation_matrix(part + 'AnklePitch', part + 'KneePitch')
        c3 = matrix(c3 + [1]).transpose()
        f3 = m3 * (((T1 * T2) * T3)) * c3)
        total_mass += m3

        c4, m4 = self.jointCOM[part+'HipPitch']
        T4 = transformation_matrix(part+'KneePitch', part + 'HipPitch')
        c4 = matrix(c4 + [1]).transpose()
        f4 = m4 *((((T1 * T2) * T3) * T4) * c4)
        total_mass += m4

        cc, mm = self.jointCOM[part+'HipRoll']
        TT = transformation_matrix(part+'HipPitch', part + 'HipRoll')
        cc = matrix(cc + [1]).transpose()
        ff = mm * (((((T1 * T2) * T3) * T4) * TT) * cc)
        total_mass += mm

        ################ The important HipYawPitch
        c5, m5 = self.jointCOM[part+'HipYawPitch']
        T5 = transformation_matrix(part+'HipRoll', part + 'HipYawPitch')
        c5 = matrix(c5 + [1]).transpose()
        f5 = m5 *((((((T1 * T2) * T3) * T4) * TT)* T5) * c5)
        total_mass += m5

        # adding the torso to the chain
        c6, m6 = self.jointCOM['Torso']
        T6 = transformation_matrix(part+'HipYawPitch', 'Torso')
        c6 = matrix(c6 + [1]).transpose()
        f6 = m6 *(((((((T1 * T2) * T3) * T4) *  TT) * T5) * T6) * c6)
        total_mass += m6

        # branching out to all parts of body. First parts of right arm
        c7, m7 = self.jointCOM['RShoulderRoll']
        T7 = transformation_matrix('Torso', 'RShoulderRoll')
        c7 = matrix(c7 + [1]).transpose()
        f7 = m7 * ((((((((T1 * T2) * T3) * T4) * TT) * T5) * T6) * T7) *  c7)
        total_mass += m7

        c8, m8 = self.jointCOM['RShoulderPitch']
        T8 = transformation_matrix('RShoulderRoll', 'RShoulderPitch')
        c8 = matrix(c8 + [1]).transpose()
        f8 = m8 * (((((((((T1 * T2) * T3) * T4) * TT) * T5) * T6) * T7) * T8) * c8)
        total_mass += m8

        c9, m9 = self.jointCOM['RElbowRoll']
        T9 = transformation_matrix('RShoulderPitch', 'RElbowRoll')
        c9 = matrix(c9 + [1]).transpose()
        f9 = m9 *((((((((((T1 * T2) * T3) * T4) * TT) * T5) * T6) * T7) * T8) * T9) * c9)
        total_mass += m9

        c10, m10 = self.jointCOM['RElbowYaw']
        T10 = transformation_matrix('RElbowRoll', 'RElbowYaw')
        c10 = matrix(c10 + [1]).transpose()
        f10 = m10 * (((((((((((T1 * T2) * T3) * T4) * TT) * T5) * T6) * T7) * T8) * T9) *
        T10) * c10)
        total_mass += m10

        # now the same for the left arm
        c7, m7 = self.jointCOM['LShoulderRoll']
        T7 = transformation_matrix('Torso', 'LShoulderRoll')
        c7 = matrix(c7 + [1]).transpose()
        f11 = m7 *((((((((T1 * T2) * T3) * T4) * TT) * T5) * T6) * T7) *  c7)
        total_mass += m7

        c8, m8 = self.jointCOM['LShoulderPitch']
        T8 = transformation_matrix('LShoulderRoll', 'LShoulderPitch')
        c8 = matrix(c8 + [1]).transpose()
        f12 = m8 *(((((((((T1 * T2) * T3) * T4) * TT) * T5) * T6) * T7) * T8) * c8)
        total_mass += m8

        c9, m9 = self.jointCOM['LElbowRoll']
        T9 = transformation_matrix('LShoulderPitch', 'LElbowRoll')
        c9 = matrix(c9 + [1]).transpose()
        f13 = m9 * ((((((((((T1 * T2) * T3) * T4) * TT) * T5) * T6) * T7) * T8) * T9) * c9)
        total_mass += m9

        c10, m10 = self.jointCOM['LElbowYaw']
        T10 = transformation_matrix('LElbowRoll', 'LElbowYaw')
        c10 = matrix(c10 + [1]).transpose()
        f14 = m10 * (((((((((((T1 * T2) * T3) * T4) * TT) * T5) * T6) * T7) * T8) * T9) *
        T10) * c10)
        total_mass += m10

        # now from torso to head
        c7, m7 = self.jointCOM['HeadYaw']
        T7 = transformation_matrix('Torso', 'HeadYaw')
        c7 = matrix(c7 + [1]).transpose()
        f15 = m7 * ((((((((T1 * T2) * T3) * T4) * TT)* T5) * T6) * T7) *  c7)
        total_mass += m7

        c8, m8 = self.jointCOM['HeadPitch']
        T8 = transformation_matrix('HeadPitch', 'HeadYaw')
        c8 = matrix(c8 + [1]).transpose()
        f16 = m8 * (((((((((T1 * T2) * T3) * T4) * TT) * T5) * T6) * T7) * T8) * c8)
        total_mass += m8
        
        # back down the other leg
        if( part == 'R'):
            other = 'L'
        else:
            other = 'R'
        c8, m8 = self.jointCOM[other + 'HipYawRoll']
        T8 = transformation_matrixmin('Torso', other + 'HipYawRoll')
        c8 = matrix(c8 + [1]).transpose()
        f17 = m8 * (((((((((T1 * T2) * T3) * T4) * TT ) * T5) * T6) * T7) * T8) * c8)
        total_mass += m8

        c9, m9 = self.jointCOM[other + 'HipRoll']
        T9 = transformation_matrixmin(other + 'HipYawRoll', other + 'HipRoll')
        c9 = matrix(c9 + [1]).transpose()
        f18 = m9 * (((((((((T1 * T2) * T3) * T4) * TT) * T5) * T6) * T7) * T8) * T9) * c9)
        total_mass += m9

        c10, m10 = self.jointCOM[other + 'HipPitch']
        T10 = transformation_matrixmin(other + 'HipRoll', other + 'HipPitch')
        c10 = matrix(c10 + [1]).transpose()
        f19 = m10 *( ((((((((((T1 * T2) * T3) * T4) * TT) *  T5) * T6) * T7) * T8) * T9) *
        T10) * c10)
        total_mass += m10

        c11, m11 = self.jointCOM[other + 'KneePitch']
        T11 = transformation_matrixmin(other + 'HipPitch', other + 'KneePitch')
        c11 = matrix(c11 + [1]).transpose()
        f20 = m11 * ((((((((((((T1 * T2) * T3) * T4) * TT) * T5) * T6) * T7) * T8) * T9) *
        T10) * T11) * c11)
        total_mass += m11
        
        c12, m12 = self.jointCOM[other + 'AnklePitch']
        T12 = transformation_matrixmin(other + 'KneePitch', other + 'AnklePitch')
        c12 = matrix(c12 + [1]).transpose()
        f21 = m12 * (((((((((((((T1 * T2) * T3) * T4) * TT) * T5) * T6) * T7) * T8) * T9) *
        T10) * T11) *T12) * c12)
        total_mass += m12

        c13, m13 = self.jointCOM[other + 'AnkleRoll']
        T13 = transformation_matrixmin(other + 'AnklePitch', other + 'AnkleRoll')
        c13 = matrix(c13 + [1]).transpose()
        f22 = m12 * ((((((((((((((T1 * T2) * T3) * T4) * TT) * T5) * T6) * T7) * T8) * T9) *
        T10) * T11) *T12) * T13) * c12)
        total_mass += m13


        # the final CoM is the total weighted CoM location divided by the total
        # weight
        return total_CoM / float(total_mass)

    # constructs a transformation matrx for shifting from the previous
    # coordinate-system to the current one
    def transformation_matrix(se]f, previous, current):
        # get the x, y and z offset values
        offsets = self.jointOffsets[(previous, current)]

        # get the 3x3 rotation matrix using the angle of the previous joint
        angle = self.motion_proxy.getAngles(previous, False)[0]

        # special case for the crazy-ass hip
        if "YawPitch" in previous:
            pass #TODO

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


    # constructs a transformation matrx for shifting from the previous
    # coordinate-system to the current one
    def transformation_matrixmin(self, previous, current):
        # get the x, y and z offset values
        offsets = self.jointOffsets[(previous, current)]

        # get the 3x3 rotation matrix using the angle of the previous joint
        angle = self.motion_proxy.getAngles(previous, False)[0]

        angle = - angle
        # special case for the crazy-ass hip
        if "YawPitch" in previous:
            pass #TODO

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

