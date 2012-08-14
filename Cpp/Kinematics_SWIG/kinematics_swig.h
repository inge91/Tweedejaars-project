#ifndef KINEMATICS_SWIG_H
#define KINEMATICS_SWIG_H

#include <string>
#include <map>
#include "kinematics.h"

using namespace std;

class KinematicsSWIG
{
    public:
        KinematicsSWIG(string ip);
        map<string, double> approach_position(string leg,
                double target_x,
                double target_y,
                double target_z,
                int lambda=5,
                int max_iter=100,
                int dmax=50);

        map<string, double> change_position(string leg,
                double offset_x,
                double offset_y,
                double offset_z,
                int lambda=5,
                int max_iter=100,
                int dmax=50);

    private:
        /**
         * Kinematics instance which does the main work.
         */
        Kinematics m_kinematics;
};

#endif // KINEMATICS_SWIG_H
