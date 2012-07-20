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
    /* enumerations */
    public:
        enum BodyPart {
            LLEG,
            RLEG,
            RARM,
            LARM,
            HEAD
        };

    /* fields */
    public:
        /**
         * A map of joint offsets.
         *
         * The keys are pairs of joint names, the values are pairs of:
         * - a vector containing 3 elements, the x y and z offsets
         * - a multiplier (1 or -1) indicating whether the transition is towards the torso
         */
        static map<pair<string, string>, pair<vector<double>, double> > jointOffsets;
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
         * pose of the Nao) or offline using a specified map of joint angles.
         * @param joint_dict A map of joint names and their angle. Only needs to be
         * specified if the "online" parameter is true.
         * @return A map of joint names with their angles.
         */
        joint_loc_map get_locations_dict(BodyPart leg, bool online=true,
                const map<string, double> &joint_dict=map<string, double>());

    private:
        /**
         * Runs from the torso to the arms and legs, and adds the found joint
         * locations to the given joint_loc_map.
         *
         * @param T A homogeneous transformation matrix describing the location
         * of the torso
         * @param part The bodypart whose joints to add to the map
         * @param online Whether the calculation is done online (using the current
         * pose of the Nao) or offline using a specified map of joint angles.
         * @param joint_dict A map of joint names and their angle. Only needs to be
         * specified if the "online" parameter is true.
         */
        void locs_from_torso(matrix<double> T, BodyPart part,
                joint_loc_map &joint_locs,
                bool online=true,
                const map<string, double> &joint_dict=map<string, double>());

        /**
         * Returns a rotation matrix over a given joint.
         *
         * @param joint The joint.
         * @param towards_torso a multiplier (1 or -1) indicating whether the
         * transition is towards the torso
         * @param online Whether the calculation is done online (using the current
         * pose of the Nao) or offline using a specified map of joint angles.
         * @param joint_dict A map of joint names and their angle. Only needs to be
         * specified if the "online" parameter is true.
         * @return A 4x4 homogeneous rotation matrix.
         */
        matrix<double> rotation_matrix(string joint, int towards_torso,
                bool online=true,
                const map<string, double> &joint_dict=map<string, double>());

        /**
         * Returns a translation matrix between two joints.
         *
         * @param previous The previous joint.
         * @param current The current joint.
         * @return A 4x4 homogenous translation matrix.
         */
        matrix<double>translation_matrix(string previous, string current);
        
        /**
         * Utility function: converts a 2-dimensional vector to a matrix.
         *
         * @param vec A 2-dimensional vector.
         * @return A matrix.
         */
        static matrix<double> vec_to_mat(vector<vector<double> > vec);

        /**
         * Utility function: checks if a string contains a certain substring.
         *
         * @param str The string.
         * @param substr The substring.
         * @return a boolean
         */
        bool contains(string str, string substr);
};

#endif
