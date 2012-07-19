import CoM
import cPickle as pickle
from collections import defaultdict

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
    
    print RHipRoll
    print RHipPitch
    #position dict is the final dict that will contain all reachable places
    table_lLeg = defaultdict(lambda: defaultdict(lambda: defaultdict(lambda:
        defaultdict(lambda: defaultdict(lambda: defaultdict)))))

    com = CoM.CenterOfMass()

    # loop constructs dict for left leg kick
    for i in xrange(LHipYawPitch[0], LHipYawPitch[1]) :
        for j in xrange(LHipRoll[0], LHipRoll[1]) :
            for k in xrange(LHipPitch[0], LHipPitch[1]) :
                for l in xrange(LKneePitch[0], LKneePitch[1]) :
                    for m in xrange(RHipRoll[0], RHipRoll[1]):
                        for n in xrange(RHipPitch[0], RHipPitch[1]):
                            #calculate back to the readians
                            angle_hipyawpitch = i / float(resolution)
                            angle_hiproll     = j / float(resolution)
                            angle_hippitch    = k / float(resolution)
                            angle_kneepitch   = l / float(resolution)
                            angle_rhiproll    = m / float(resolution)
                            angle_rhippitch   = n / float(resolution)
                            # putting the angles in a dict
                            angle_dict = {
                                          "LHipYawPitch"  : angle_hipyawpitch,
                                          "LHipRoll"      : angle_hiproll,
                                          "LHipPitch"     : angle_hippitch,
                                          "LKneePitch"    : angle_kneepitch,
                                          "RHipYawPitch"  : angle_hipyawpitch,
                                          "RHipRoll"      : angle_rhiproll,
                                          "RHipPitch"     : angle_rhippitch,
                                          # Position of ankle is taken from a Nao in
                                          # normal pose as we do not want these to
                                          # change
                                          "LAnkleRoll"    : 0,
                                          "LAnklePitch"   : -0.55,
                                          # set other values to initial pose values or
                                          # zero
                                          "RKneePitch"    : 1.5739259719848633,
                                          "RAnklePitch"   : -1.0461461544036865,
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
                            joint_locs = com.get_locations_dict("RLeg", False,
                                    angle_dict)["LAnkleRoll"]
                            x = joint_locs[0,0] 
                            y = joint_locs[1,0]
                            z = joint_locs[2,0]
                            table_lLeg[x][y][z][angle_rhiproll][angle_rhippitch] = angle_dict
    f = open(r'~/Project/Tweedejaarsproject/LLeg_positions.txt','w')
    pickle.dump(table_lLeg, f)
    f.write(table_lLeg)
    f.close()
    table_rLeg = defaultdict(lambda: defaultdict(lambda: defaultdict(lambda:
        defaultdict(lambda: defaultdict(lambda: defaultdict)))))
    # loop constructs dict for left leg kick
    for i in xrange(RHipYawPitch[0], RHipYawPitch[1]) :
        for j in xrange(RHipRoll[0], RHipRoll[1]) :
            for k in xrange(RHipPitch[0], RHipPitch[1]) :
                for l in xrange(RKneePitch[0], RKneePitch[1]) :
                    for m in xrange(LHipRoll[0], LHipRoll[1]):
                        for n in xrange(LHipPitch[0], LHipPitch[1]):
                            #calculate back to the readians
                            angle_hipyawpitch = i / resolution
                            angle_hiproll     = j / resolution
                            angle_hippitch    = k / resolution
                            angle_kneepitch   = l / resolution
                            angle_lhiproll    = m / resolution
                            angle_lhippitch   = n / resolution
                            # putting the angles in a dict
                            angle_dict = {
                                          "RHipYawPitch"  : angle_hipyawpitch,
                                          "RHipRoll"      : angle_hiproll,
                                          "RHipPitch"     : angle_hippitch,
                                          "RKneePitch"    : angle_kneepitch,
                                          "LHipYawPitch"  : angle_hipyawpitch,
                                          "LHipRoll"      : angle_lhiproll,
                                          "LHipPitch"     : angle_lhippitch,
                                          # Position of ankle is taken from a Nao in
                                          # normal pose as we do not want these to
                                          # change
                                          "RAnkleRoll"    : 0,
                                          "RAnklePitch"   : -0.55,
                                          # set other values to initial pose values or
                                          # zero
                                          "LKneePitch"    : 1.6413381099700928,
                                          "LAnklePitch"   : -0.9403839111328125,
                                          "LAnkleRoll"    : 0,
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
                            joint_locs = com.get_locations_dict("LLeg", False, angle_dict) 
                            x = joint_locs[0] 
                            y = joint_locs[1]
                            z = joint_locs[2]
                            table_rLeg[x][y][z][angle_lhiproll][angle_lhippitch] = angle_dict
    f = open(r'~/Project/Tweedejaarsproject/RLeg_positions.txt','w')
    pickle.dump(table_rLeg, f)
    f.write(table_rLeg)
    f.close()

