#ifndef COM_H
#define COM_H

#include <string>
#include <map>

#include <boost/numeric/ublas/matrix.hpp>
#include <alproxies/almotionproxy.h>

using namespace std;
using boost::numeric::ublas::matrix;

typedef map<string, matrix<double> > joint_loc_map;

class CenterOfMass
{
/* methods */
public:
    // constructor
    CenterOfMass(string ip_address, int port);

    // returns the center of mass relative to the given (standing) leg
    matrix<double> get_CoM(string leg, bool online=true,
                           const map<string, double> &joint_dict=map<string, double>());

    // returns a map where the keys are names of bodyparts
    // (all the joints + Torso), and the values are their location relative to
    // the standing foot
    joint_loc_map get_locations_dict(string leg, bool online=true,
                                     const map<string, double> &joint_dict=map<string, double>());

private:
public: //debug
    // runs from the torso to the arms and kicking leg, and adds the found joint
    // locations to the given joint_loc_map
    void locs_from_torso(matrix<double> T, string part,
                         joint_loc_map &joint_locs,
                         bool online=true,
                         const map<string, double> &joint_dict=map<string, double>());

    // returns a rotation matrix over a given joint
    matrix<double> rotation_matrix(string joint, int towards_torso,
                                   bool online=true,
                                   const map<string, double> &joint_dict=map<string, double>());

    // returns a translation matrix between two joints
    matrix<double> translation_matrix(string previous, string current);

    // converts a 2-dimensional vector to a matrix
    matrix<double> vec_to_mat(vector<vector<double> > vec);

    // check if a string contains a certain substring
    bool contains(string str, string substr);

/* fields */
public:
    static map<string, pair<vector<double>, double> > jointCOM;
    static map<pair<string, string>, pair<vector<double>, double> > jointOffsets;
private:
    AL::ALMotionProxy m_motion_proxy;
};

#endif
