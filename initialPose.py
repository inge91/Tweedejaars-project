from naoqi import ALProxy
import motions, time

#makes a pose that keeps balance before exercising the kicking motion
def initialPose(kickSide, ip):
    if(kickSide == "RLeg"):
        standLeg = "L"
        kickLeg = "R"
    else:
        standLeg = "R"
        kickLeg = "L"

    mp = ALProxy("ALMotion", ip, 9559)
    mot = motions.debug(ip)

    mot.stiff()
    mot.normalPose(True)
    time.sleep(1)

    crouched_position(mp)
    shift_balance(mp, standLeg)

def crouched_position(mp):
    """a stable, crouched position"""
    joints = ['LHipPitch', 'RHipPitch', 'LKneePitch', 'RKneePitch']
    ankles = ['LAnklePitch', 'RAnklePitch']

    joint_angles = [-0.6074221134185791,
                    -0.4356980323791504,
                     1.6413381099700928,
                     1.5739259719848633]

    ankle_angles = [-0.9403839111328125, -1.0461461544036865]

    # actuation
    mp.setAngles(joints, joint_angles, 0.1)
    time.sleep(0.420)
    mp.setAngles(ankles, ankle_angles, 0.1)

def shift_balance(mp, standing_leg):
    """ from a crouched position, shift the balance to the standing leg """
    pass