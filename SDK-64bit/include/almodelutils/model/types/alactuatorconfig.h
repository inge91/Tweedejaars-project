/**
* @author Geoffrey Bosne
* Copyright (c) Aldebaran Robotics 2010 All Rights Reserved
*/

#pragma once

#ifndef _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALACTUATORCONFIG_H_
#define _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALACTUATORCONFIG_H_
#include <string>
#include <almath/types/alposition3d.h>
#include <almath/types/altransform.h>
#include <almodelutils/types/almirror.h>

namespace AL
{
  namespace Motion
  {
    /* Used as a container for actuators parameters */
    struct ActuatorConfig
    {
      std::string                             name;
      float                                   minAngle;
      float                                   maxAngle;
      float                                   startAngle;
      float                                   maxTorque;
      float                                   maxSpeed;
      std::string                             parentJoint;  // joint supportant la pince
      // transform de la pince par rapport au joint qui la porte
      AL::Math::Transform                     transform;
      std::vector<std::vector<std::string> >  subActuators;
      Mirror                                  mirror;

      ActuatorConfig(const std::string& pName = "") :
        name(pName),
        minAngle(0),
        maxAngle(0),
        startAngle(0),
        maxTorque(0),
        maxSpeed(0),
        parentJoint(""),
        transform(AL::Math::Transform()),
        mirror(){};

    };
  }
}
#endif  // _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALACTUATORCONFIG_H_
