#ifndef PCONTROLLER_H
#define PCONTROLLER_H

#include <string>
#include <map>
#include <boost/numeric/ublas/matrix.hpp>
#include <alproxies/almotionproxy.h>

#include "com.h"

using namespace std;
using boost::numeric::ublas::matrix;

class PController
{
/* methods */
public:
    // constructor
    PController(string standing_leg, string ip,
                double gain=0.0005,
                double threshold=5);

    // main loop that balances the Nao
    void run();

private:
    // calculates the error of a position
    pair<double, double> error(matrix<double> com_loc);

/* fields */
public:
    static vector<string> joints;
private:
    AL::ALMotionProxy m_mp;
    string m_leg_prefix;
    string m_leg;
    CenterOfMass m_com;
    double m_gain;
    double m_threshold;
};

#endif
