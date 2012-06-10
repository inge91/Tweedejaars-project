/**
* @author Cyrille Collette
* Copyright (c) Aldebaran Robotics 2010 All Rights Reserved
*/

#pragma once

#ifndef _LIB_ALMODELUTILS_ALMODELUTILS_ALROBOTSTATEIO_H_
#define _LIB_ALMODELUTILS_ALMODELUTILS_ALROBOTSTATEIO_H_

#include <almodelutils/alrobotstate.h>

namespace AL {


  std::ostream& operator<< (
      std::ostream& pStream,
      const ALRobotState& j);

  std::string toString(const ALRobotState& p);

}
#endif  // _LIB_ALMODELUTILS_ALMODELUTILS_ALROBOTSTATEIO_H_
