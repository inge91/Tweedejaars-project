#ifndef COM_H
#define COM_H

#include <string>
#include <map>
#include <functional>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/tuple/tuple.hpp>

#include <alproxies/almotionproxy.h>

using namespace std;
using boost::numeric::ublas::matrix;
using boost::tuples::tuple;

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
    // runs from the torso to the arms and kicking leg, and adds the found joint
    // locations to the given joint_loc_map
    void locs_from_torso(matrix<double> T, joint_loc_map &joints_locs,
                         bool online=true,
                         const map<string, double> &joint_dict=map<string, double>());

/* fields */
public:
    static map<string, tuple<vector<double>, double> > jointCOM;
    static map<tuple<string, string>, tuple<vector<double>, double> > jointOffsets;
private:
    AL::ALMotionProxy m_motion_proxy;
};

#endif
