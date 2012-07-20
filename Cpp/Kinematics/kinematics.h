#ifndef COM_H
#define COM_H

#include <string>
#include <map>
#include <vector>

#include <boost/numeric/ublas/matrix.hpp>
#include <alproxies/almotionproxy.h>

using namespace std;
using boost::numeric::ublas::matrix;

typedef map<string, matrix<double> > joint_loc_map;

/**
 * Handles both forward and inverse kinematics for a Nao robot.
 */
class Kinematics
{
    /* fields */
public:
    /**
     * A map of joint offsets.
     *
     * The keys are pairs of joint names, the values are pairs of:
     * - a vector containing 3 elements, the x y and z offsets
     * - a multiplier (1 or -1) indicating wether the transition is towards the torso
     */
     static map<string, pair<vector<double>, double> > jointCOM;
private:
    /**
     * An ALMotion proxy
     */
     AL::ALMotionProxy m_motion_proxy;

     /* methods */
public:
    /**
     * Constructor, initalizes the class.
     *
     * @param ip_address the ip_address of a running Naoqi instance
     */
     Kinematics(string ip_address);

     /**
      * Returns a map of joint name with their corresponding location in space.
      *
      * @param leg The leg whose ankle is used as origin of the coordinate system.
      * @param online Whether the calculation is done online (using the current
      *     pose of the Nao) or offline using a specified map of joint angles.
      * @param joint_dict A map of joint names and their angle. Only needs to be
      *     specified if the "online" parameter is true.
      * @return A map of joint names with their angles.
      */
      joint_loc_map get_locations_dict(string leg, bool online=true,
        const map<string, double> &joint_dict=map<string, double>());

private:
    void locs_from_torso(matrix<double> T, string part,
        joint_loc_map &joint_locs,
        bool online=true)
        const map<string, double> &joint_dict=map<string, double>());

    matrix<double> rotation_matrix(string joint, int towards_torso,
        bool online=true,
        const map<string, double> &joint_dict=map<string, double>());
};

#endif