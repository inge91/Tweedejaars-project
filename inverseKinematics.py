import numpy as np
from naoqi import ALProxy
#inverse kinematics function inspired by BHuman paper about closed loop gait
def solve_ik(Foot2Torso, Leg):
    """ Foot2Torso is the new position of the foot in torso space"""
    # distance between hips is 50 mm
    lDist = 50
    lUpperLeg = 100 
    lLowerLeg = 102.9

    # move the position above the hip instead of torso
    Foot2Hip = np.matrix([[1, 0, 0, 0], [0, 1, 0, lDist], [0, 0, 1, 0],
        [0,0,0,1]]) * Foot2Torso
    # rotate 45 degrees to compensate for rotated hip joints
    Foot2HipOrth = np.matrix([[1, 0, 0, 0], [0, cos(pi/4), -sin(pi/4), 0],
        [0, sin(pi/4), cos(pi/4) , 0 ], [0,0,0,1]]) * Foot2Hip
    # instead of foot in hip coordinates we want foot2hip
    HipOrth2Foot =  np.inv(Foot2HipOrth)

    trans= HipOrth2Foot[:, 3]
    lTrans = math.sqrt(np.vdot(trans, trans))
    #calculating gamma by rewriting the law of cosines
    gamma = math.acos * (lUpperLeg**2 + lLowerLeg**2 - lTrans**2)/ 2 * lUpperLeg
    * lLowerLeg

    # the angle of the knee
    delta_knee = math.pi - gamma

    # the foot pitch angle
    delta_footPitch1 = math.acos(lLowerLeg**2 + lTrans**2 - lUpperLeg**2 )/ (2*
    lLowerLeg * lTrans)

    delta_footPitch2 = math.atan2(x, math.sqrt(y**2 + z**2))
    delta_footRoll = atan2(y,z)

    delta_footPitch = delta_footPitch1 + delta_footPitch2

    HipOrth2Thigh = np.linalg.inv(Thigh2Foot) * HipOrth2Foot 
    
    rotfootx = np.matrix( [[1, 0, 0, 0], 
                           [0, cos(delta_footRoll),-sin(delta_footRoll), 0], 
                           [0, sin(delta_footRoll), cos(delta_footRoll), 0], 
                           [0, 0, 0, 1]])
    rotfooty = np.matrix( [[cos(delta_footPitch), 0, sin(delta_footPitch), 0],
                           [ 0, 1, 0, 0], 
                           [ -sin(delta_footPitch), 0 cos(delta_footPitch), 0] 
                           [0, 0, 0, 1]] ) 
    transzleg = [[1, 0, 0, 0], 
                 [0, 1, 0, 0],
                 [0, 0, 1, lLowerLeg],
                 [0, 0, 0, 1]]
    rotkneey = np.matrix( [[cos(delta_knee), 0, sin(delta_knee), 0],
                           [ 0, 1, 0, 0], 
                           [ -sin(delta_knee), 0 cos(delta_knee), 0] 
                           [0, 0, 0, 1]] ) 
    transupperlegz = [[1, 0, 0, 0], 
                 [0, 1, 0, 0],
                 [0, 0, 1, lUpperLeg],
                 [0, 0, 0, 1]]

    Thight2Foot =  rotfootx * rotfooty * transzleg * rotkneey * transupperlegz
    
    rothip_x = math.acos(HipOrth2Thigh[3,2])
    rothippitchy = math.atan2(-HipOrth2Thigh[3,1], HipOrth2Thigh[3,3])
    rothipyawz = math.atan2(-HipOrth2Thigh[1,2], HipOrth2Thigh[2,2])
    rothiprollx = rothip_x - math.pi/4
    mot = ALProxy("ALMotion", ip, 9559)
    mot.setStiffnesses("Body", 1)
    if Leg == "RLeg":
        l = "R"
    else:
        l = "L"
    mot.setAngles([l + "AnkleRoll", l + "AnklePitch", l + "KneePitch", l +
        "HipPitch", l + "HipRoll" ], [] )


    






    
    



    




