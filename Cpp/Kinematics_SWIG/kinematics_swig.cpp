#include "kinematics_swig.h"

#include <Eigen/Core>

USING_PART_OF_NAMESPACE_EIGEN

    KinematicsSWIG::KinematicsSWIG(string ip)
: m_kinematics(ip)
{
}

map<string, double> KinematicsSWIG::approach_position(string leg,
        double target_x,
        double target_y,
        double target_z,
        int lambda,
        int max_iter,
        int dmax)
{
    Vector3d target;
    target << target_x, target_y, target_z;

    Kinematics::BodyPart bpart_leg;
    if (leg == "RLEG")
        bpart_leg = Kinematics::RLEG;
    else
        bpart_leg = Kinematics::LLEG;

    return m_kinematics.approach_position(bpart_leg, target, lambda, max_iter, dmax);
}

map<string, double> KinematicsSWIG::change_position(string leg,
        double offset_x,
        double offset_y,
        double offset_z,
        int lambda,
        int max_iter,
        int dmax)
{
    Vector3d target;
    target << offset_x, offset_y, offset_z;

    Kinematics::BodyPart bpart_leg;
    if (leg == "RLEG")
        bpart_leg = Kinematics::RLEG;
    else
        bpart_leg = Kinematics::LLEG;

    return m_kinematics.change_position(bpart_leg, target, lambda, max_iter, dmax);
}
