from threading import Thread
from CoM import CenterOfMass
from copy import copy
from numpy import matrix

# uses a proportional controller to balance the Nao by adjusting the hip
# joints of the standing leg
class P_Controller(Thread):
    # a list of joints in the order of the getAngles function
    joints = ["HeadYaw", "HeadPitch", "LShoulderPitch", "LShoulderRoll",
              "LElbowYaw", "LElbowRoll", "LHipYawPitch", "LHipRoll",
              "LHipPitch", "LKneePitch", "LAnklePitch", "LAnkleRoll",
              "RHipYawPitch", "RHipRoll", "RHipPitch", "RKneePitch",
              "RAnklePitch", "RAnkleRoll", "RShoulderPitch", "RShoulderRoll",
              "RElbowYaw", "RElbowRoll"]

    def __init__(self, standing_leg, ip, gain):
        super(P_Controller, self).__init__()

        self.leg_prefix = "L" if standing_leg == "LLeg" else "R"
        self.leg = standing_leg
        self.com = CenterOfMass(ip, 9559)
        self.gain = gain

        self.mp = self.com.motion_proxy

        # make sure the fallmanager is disabled
        try:
            self.mp.setFallManagerEnabled(False)
        except:
            pass
        self.running = True

    def run(self):
        # getting the right index for the getAngles array
        roll_index = (self.joints.index("LHipRoll") if self.leg == "LLeg"
            else self.joints.index("RHipRoll"))
        pitch_index = (self.joints.index("LHipPitch") if self.leg == "LLeg"
            else self.joints.index("RHipPitch"))

        # main loop
        while self.running:
            error = self.error(self.com.get_CoM(self.leg))
            print "Error: ", error

            # output = error * proportional gain
            p_out = self.gain * error

            angles = self.mp.getAngles("Body", True)
            cur_joints = dict(zip(self.joints, angles))

            # looking for the best course of action
            best_pangle = 0
            best_rangle = 0
            best_com_error = 999
            for pitch_angle in (0, -p_out, p_out):
                for roll_angle in (0, -p_out, p_out):
                    joints = copy(cur_joints)
                    joints[self.leg_prefix + "HipRoll"] += roll_angle
                    joints[self.leg_prefix + "HipPitch"] += pitch_angle

                    com_err = self.error(self.com.get_CoM(self.leg, False, joints))

                    if com_err < best_com_error:
                        best_com_error = com_err
                        best_pangle = pitch_angle
                        best_rangle = roll_angle

            print "HipRoll: ", best_rangle
            print "HipPitch: ", best_pangle
            print ""

            self.mp.changeAngles(self.leg_prefix + "HipRoll", best_rangle, 0.3)
            self.mp.changeAngles(self.leg_prefix + "HipPitch", best_pangle, 0.3)

    def kill(self):
        self.running = False

    def error(self, com_loc):
        polygon = matrix([[3], [0], [0], [1]])
        diff = polygon - com_loc

        abs_sum = 0
        for i in diff[0:2]:
            abs_sum += abs(i[0, 0])

        return abs_sum

if __name__ == '__main__':
    import time

    cont = P_Controller("LLeg", "0.0.0.0", 0.05)
    cont.start()
    time.sleep(5)
    cont.kill()
    cont.join()
    del cont