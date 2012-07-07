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
            err_x, err_y = self.error(self.com.get_CoM(self.leg))
            print "Error: ", err_x, err_y

            # output = error * proportional gain
            p_x = self.gain * err_x
            p_y = self.gain * err_y

            # torso naar voren -> positieve hoek (Pitch)
            pitch_angle = p_y * -1;
            # roll is positief naar buiten toe
            roll_angle = p_x * (-1 if self.leg == "LLeg" else 1)

            print "HipPitch: ", pitch_angle
            print "HipRoll: ", roll_angle
            print ""

            self.mp.changeAngles(self.leg_prefix + "HipPitch", pitch_angle,  1)
            self.mp.changeAngles(self.leg_prefix + "HipRoll", roll_angle, 1)

    def kill(self):
        self.running = False

    def error(self, com_loc):
        polygon = matrix([[3], [0], [0], [1]])
        diff = polygon - com_loc

        # return the X and Y difference
        return (diff[0, 0], diff[1, 0])

if __name__ == '__main__':
    import time

    cont = P_Controller("LLeg", "0.0.0.0", 0.05)
    cont.start()
    time.sleep(5)
    cont.kill()
    cont.join()
    del cont