import CoM

def create(resolution = 10):
    """ the bigger the resolution, the bigger the list of endpositions"""
    # all the ranges in radians multiplied with the given resolution
    LHipYawPitch = (int(-1.145303 * resolution), int(0.740810 * resolution))
    LHipRoll     = (int(-0.379472 * resolution), int(0.790477 * resolution))
    LHipPitch 	 = (int(-1.773912 * resolution), int(0.484090 * resolution))
    LKneePitch 	 = (int(-0.092346 * resolution), int(2.112528 * resolution))
    RHipYawPitch = (int(-1.145303 * resolution), int(0.740810 * resolution))
    RHipRoll 	 = (int(-0.738321 * resolution), int(0.414754 * resolution))
    RHipPitch 	 = (int(-1.772308 * resolution), int(0.485624 * resolution))
    RKneePitch 	 = (int(-0.103083 * resolution), int(2.120198 * resolution))
    
    #position dict is the final dict that will contain all reachable places
    position_dict = {}

    com = CoM.CenterOfMass()

    # loop that runs through all possible radians with right stepwidth
    for i in xrange(LHipYawPitch[0], LHipYawPitch[1]) :
        for j in xrange(LHipRoll[0], LHipRoll[1]) :
            for k in xrange(LHipPitch[0], LHipPitch[1]) :
                for l in xrange(LKneePitch[0], LKneePitch[1]) :
                    #calculate back to the readians
                    angle_hipyawpitch = i / resolution
                    angle_hiproll     = j / resolution
                    angle_hippitch    = k / resolution
                    angle_kneepitch   = l / resolution
                    # putting the angles in a dict
                    angle_dict = {
                                  "LHipYawPitch"  : angle_hipyawpitch,
                                  "LHipRoll"      : angle_hiproll,
                                  "LHipPitch"     : angle_hippitch,
                                  "LKneePitch"    : angle_kneepitch,
                                  # Position of ankle is taken from a Nao in
                                  # normal pose
                                  "LAnkleRoll"    : 0,
                                  "LAnklePitch"   : -0.55,
                                  # set other values to zero
                                  "RHipYawPitch"  : 0,
                                  "RHipRoll"      : 0,
                                  "RHipPitch"     : 0,
                                  "RKneePitch"    : 0,
                                  "RAnklePitch"   : 0,
                                  "RAnkleRoll"    : 0,
                                  "LShoulderPitch": 0, 
                                  "LShoulderRoll" : 0,
                                  "LElbowYaw"     : 0,
                                  "LElbowRoll"    : 0,
                                  "RShoulderPitch": 0,
                                  "RShoulderRoll" : 0,
                                  "RElbowYaw"     : 0,
                                  "RElbowRoll"    : 0,
                                  "HeadYaw"       : 0,
                                  "HeadPitch"     : 0
                                 }
                    joint_locs = com.get_locations_dict("RLeg", False, angle_dict) 
                    position_dict[joint_locs["LAnkleRoll"]] =  angle_dict 
    f=open(r'~/Project/Tweedejaarsproject/RLeg_positions.txt','w')
    f.write(position_dict)
    f.close()


