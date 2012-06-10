#include <alparammanager/alparammanager.h>

namespace AL {
namespace Param {

ParamError::ParamError(const std::string& what)
    : std::runtime_error(what) {
}

ParamError::~ParamError() throw() {
}

} // Param
} // AL
