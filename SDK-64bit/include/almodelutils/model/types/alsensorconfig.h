/**
* @author Chris Kilner
* Copyright (c) Aldebaran Robotics 2007 All Rights Reserved
*/
#pragma once

#ifndef _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALSENSORCONFIG_H_
#define _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALSENSORCONFIG_H_

#include <string>
#include <almath/types/altransform.h>

namespace AL
{
  namespace Motion
  {
    /* Used to store a position of an interesting point on Nao */
    struct SensorConfig
    {
      std::string           name;
      std::string           parentJoint;
      unsigned short        parent;
      AL::Math::Transform transform;

      SensorConfig(
        const std::string&         pName        = "",
        const std::string&         pParentJoint = "",
        const AL::Math::Transform& pT           = AL::Math::Transform()) :
        name(pName),
        parentJoint(pParentJoint),
        parent(0),
        transform(pT) {};
    };

  }
}
#endif  // _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALSENSORCONFIG_H_
