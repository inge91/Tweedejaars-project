%module "kinematics_swig"
%include "std_string.i"
%include "std_vector.i"
%include "std_map.i"

%{
#define SWIG_FILE_WITH_INIT
#include "kinematics_swig.h"
%}

namespace std {
    %template(map_string_double) map<string, double>;
}

class KinematicsSWIG
{
    public:
        KinematicsSWIG(std::string ip);
        std::map<std::string, double> approach_position(std::string leg,
                double target_x,
                double target_y,
                double target_z,
                int lambda=5,
                int max_iter=100,
                int dmax=50);

        std::map<std::string, double> change_position(std::string leg,
                double offset_x,
                double offset_y,
                double offset_z,
                int lambda=5,
                int max_iter=100,
                int dmax=50);
};
