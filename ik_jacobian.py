from numpy import matrix, cross, eye
from numpy.linalg import eig, pinv, norm
import sys
from CoM import CenterOfMass
from naoqi import ALProxy
from collections import defaultdict

import scipy
from scipy import linalg

sys.path.append("SDK")

def get_jacobian(leg, joint_angles, joint_trans):
    """ Returns the Jacobian matrix """

    joints = ["HipYawPitch", "HipRoll", "HipPitch", "KneePitch",
              "AnklePitch", "AnkleRoll"]

    if leg == "LLeg":
        joints = ["L" + joint for joint in joints]
        end_effectors = ["LAnkleRoll"]
    else:
        joints = ["R" + joint for joint in joints]
        end_effectors = ["RAnkleRoll"]

    k = len(end_effectors)
    n = len(joints)

    J = matrix([0] * (3*k * n))
    J.shape = (3*k, n)

    # filling the jacobian
    for i in xrange(0, 3*k, 3):
        for j in xrange(n):
            joint = joints[j]
            end_effector = end_effectors[i if i < 3 else i - (2*(i/3))]

            v = rotation_axis(joint_trans[joint])
            v = v[:3]
            s = joint_trans[end_effector] * matrix([[0], [0], [0], [1]])
            s = s[:3]
            p = joint_trans[joint] * matrix([[0], [0], [0], [1]])
            p = p[:3]

            cross_prod = cross(v.T, (s-p).T)
            J[i,   j] = cross_prod[0, 0]
            J[i+1, j] = cross_prod[0, 1]
            J[i+2, j] = cross_prod[0, 2]

    return J

def rotation_axis(transformation):
    """ Returns the axis of rotation of the given homogeneous
    transformation matrix """

    rotation = transformation[:3, :3]
    nullspace = null(rotation - eye(3))

    if nullspace.shape != (3, 1):
        raise Exception("Nullspace dimensions invalid")

    return nullspace / norm(nullspace)

def null(A, eps=1e-15):
    u, s, vh = scipy.linalg.svd(A)
    null_mask = (s <= eps)
    null_space = scipy.compress(null_mask, vh, axis=0)
    return scipy.transpose(null_space)

def set_position(ip, leg, target, error_thresh=5, max_iter=100):
    # initialization of some variables
    com = CenterOfMass(ip, 9559)
    mp = ALProxy("ALMotion", ip, 9559)

    kick_joints = ["HipYawPitch", "HipRoll", "HipPitch", "KneePitch",
              "AnklePitch", "AnkleRoll"]
    kick_joints = [("L" if leg == "LLeg" else "R") + joint for joint in kick_joints]

    stand_joints = ["HipYawPitch", "HipRoll", "HipPitch", "KneePitch",
              "AnklePitch", "AnkleRoll"]
    stand_joints = [("R" if leg == "LLeg" else "L") + joint for joint in stand_joints]

    rest_of_body = ["HeadPitch", "HeadYaw", "LShoulderPitch", "LShoulderRoll",
                    "LElbowYaw", "LElbowRoll", "RShoulderPitch", "RShoulderRoll",
                    "RElbowYaw", "RElbowRoll"]

    # initial angles
    angles = {}
    for joint in kick_joints:        
        angles[joint] = mp.getAngles(joint, True)[0]
    for joint in stand_joints:
        angles[joint] = mp.getAngles(joint, True)[0]
    for joint in rest_of_body:
        angles[joint] = mp.getAngles(joint, True)[0]

    end_effector = "LAnkleRoll" if leg == "LLeg" else "RAnkleRoll"
    stand_leg = "RLeg" if leg == "LLeg" else "LLeg"
    theta = matrix([angles[joint] for joint in kick_joints]).T

    for _ in xrange(max_iter):
        joint_trans = com.get_locations_dict(stand_leg, transformation=True, online=False, joint_dict=angles)

        # difference between goal position and end-effector
        dX = target - (joint_trans[end_effector] * matrix([[0], [0], [0], [1]]))[:3, 0]
        print norm(dX)
        if norm(dX) < 15:
            break

        J = get_jacobian(leg, angles, joint_trans)
        Jinv = pinv(J)

        while True:
            error = norm( (eye(J.shape[0]) - (J*Jinv)) * dX )
            if (error < error_thresh):
                break;
            else:
                dX /= 2

        theta += (Jinv * dX) + (eye(6) - (Jinv * J)) * matrix([[0], [0], [0], [0], [0], [0]])
        update_angles(angles, kick_joints, theta, stand_joints, mp)

    return dict(zip(kick_joints, map(lambda x: x[0, 0], theta)))

def update_angles(angles, joints, theta, stand_joints, mp):
    end_effector_angles = dict(zip(joints, theta))

    for joint, angle in end_effector_angles.iteritems():
        angles[joint] = angle

    # update the angles of the standing leg because they might've been changed
    # by a balance controller
    for joint in stand_joints:
        angles[joint] = mp.getAngles(joint, True)[0]

def modulo(a, b):
    if a < 0:
        negative = True
    a = abs(a)
    mod = a % b

    if negative:
        return -1 * mod
    else:
        return mod

def testing(ip):
    import CoM as c
    import sys
    sys.path.append("SDK")
    from naoqi import ALProxy

    com = c.CenterOfMass(ip, 9559)
    mp = ALProxy("ALMotion", ip, 9559)
    angles = {}
    for joint in joints:
        angles[joint] = mp.getAngles(joint, True)

    joint_trans = com.get_locations_dict("LLeg", transformation=True)
    target_pos = matrix([[1], [1], [1]])

    return get_jacobian("RLeg", angles, joint_trans)