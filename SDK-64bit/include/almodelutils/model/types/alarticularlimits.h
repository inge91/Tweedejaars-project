/**
* @author Geoffrey Bosne
* Copyright (c) Aldebaran Robotics 2010 All Rights Reserved
*/

#pragma once

#ifndef _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALARTICULARLIMITS_H_
#define _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALARTICULARLIMITS_H_

#include <string>
#include <vector>

namespace AL
{
  namespace Motion
  {
    struct ALArticularLimits
    {
      std::string                       jointName0;
      std::string                       jointName1;
      unsigned int                      jointId0;
      unsigned int                      jointId1;
      std::vector<std::vector<float> >  limits;

      ALArticularLimits(
        const std::string&  pJointName0 = "",
        const std::string&  pJointName1 = "",
        const unsigned int& pJointId0   = 0,
        const unsigned int& pJointId1   = 0) :
        jointName0(pJointName0),
        jointName1(pJointName1),
        jointId0(pJointId0),
        jointId1(pJointId1)
      {}
    };
  }
}
#endif  // _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALARTICULARLIMITS_H_
