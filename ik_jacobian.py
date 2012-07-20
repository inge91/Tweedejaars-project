from numpy import matrix, cross, eye
from numpy.linalg import eig, pinv, norm, inv
import sys
from CoM import CenterOfMass
from naoqi import ALProxy
from collections import defaultdict

import scipy
from scipy import linalg

sys.path.append("Resources")
from joint_constraints import joint_constraints

sys.path.append("SDK")

def get_jacobian(leg, joint_angles, joint_trans):
    """ Returns the Jacobian matrix """

    joints = ["HipYawPitch", "HipRoll", "HipPitch", "KneePitch"]

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

def change_position(ip, leg, offset, lambd=5, max_iter=100):
    com = CenterOfMass(ip, 9559)
    stand_leg = "LLeg" if leg == "RLeg" else "RLeg"
    joint_locs = com.get_locations_dict(stand_leg, transformation=False, online=True)

    current_loc = joint_locs["LAnkleRoll" if leg == "LLeg" else "RAnkleRoll"][:3, 0]

    x, y, z = offset
    offset_matrix = matrix([[x], [y], [z]])
    target = current_loc + offset_matrix

    return set_position(ip, leg, target, lambd=lambd, max_iter=max_iter)


def set_position(ip, leg, target, lambd=5, max_iter=100):
    """
    ip: IP address of the desired naoqi
    leg: the leg to be actuated
    target: target position relative to the other (stand, non-actuated leg) leg
    lambd: lambda parameter for Levenberg-Marquardt method (lambda is a protected
        python keyword)
    max_iter: maximum number of iterations
    """
    # initialization of some variables
    com = CenterOfMass(ip, 9559)
    mp = ALProxy("ALMotion", ip, 9559)

    kick_joints = ["HipYawPitch", "HipRoll", "HipPitch", "KneePitch"]
    kick_joints = [("L" if leg == "LLeg" else "R") + joint for joint in kick_joints]

    stand_joints = ["HipYawPitch", "HipRoll", "HipPitch", "KneePitch"]
    stand_joints = [("R" if leg == "LLeg" else "L") + joint for joint in stand_joints]

    rest_of_body = ["HeadPitch", "HeadYaw", "LShoulderPitch", "LShoulderRoll",
                    "LElbowYaw", "LElbowRoll", "RShoulderPitch", "RShoulderRoll",
                    "RElbowYaw", "RElbowRoll", "LAnkleRoll", "LAnklePitch",
                    "RAnklePitch", "RAnkleRoll"]

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

        lambd = 5

        # Levenberg-Marquardt
        d_theta = (J.T * inv((J * J.T) + (lambd**2 * eye(3)))) * dX

        # update theta and the joint angle dictionary
        update_theta(theta, d_theta, leg)
        update_angles(angles, kick_joints, theta, stand_joints, mp)

    return dict(zip(kick_joints, map(lambda x: x[0, 0], theta)))

# updates theta vector, respecting each joint's angle constraints
def update_theta(theta, d_theta, leg):
    kick_joints = ["HipYawPitch", "HipRoll", "HipPitch", "KneePitch"]
    kick_joints = [("L" if leg == "LLeg" else "R") + joint for joint in kick_joints]

    # update the angles
    theta += d_theta

    # check the boundaries
    for i, (joint, angle) in enumerate(zip(kick_joints, theta)):
        min, max = joint_constraints[joint]

        if angle < min:
            theta[i, 0] = min
        elif angle > max:
            theta[i, 0] = max

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

    joints = ["HipYawPitch", "HipRoll", "HipPitch", "KneePitch"]

    leg = "RLeg"
    if leg == "LLeg":
        joints = ["L" + joint for joint in joints]
        end_effectors = ["LAnkleRoll"]
    else:
        joints = ["R" + joint for joint in joints]
        end_effectors = ["RAnkleRoll"]

    com = c.CenterOfMass(ip, 9559)
    mp = ALProxy("ALMotion", ip, 9559)
    angles = {}
    for joint in joints:
        angles[joint] = mp.getAngles(joint, True)

    joint_trans = com.get_locations_dict("LLeg", transformation=True)
    target_pos = matrix([[1], [1], [1]])

    return get_jacobian("RLeg", angles, joint_trans)