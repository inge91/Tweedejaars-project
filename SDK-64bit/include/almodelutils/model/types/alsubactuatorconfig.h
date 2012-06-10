/**
* @author Geoffrey Bosne
* Copyright (c) Aldebaran Robotics 2010 All Rights Reserved
*/

/**
* This class was added in order to store actuators information for Choregraph
* Could be replaced by actuatorconfig ?
*/

#pragma once

#ifndef _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALSUBACTUATORCONFIG_H_
#define _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALSUBACTUATORCONFIG_H_

#include <string>
#include <almath/types/altransform.h>
#include <almath/types/alposition3d.h>

namespace AL
{
  namespace Motion
  {
    /* Used as a container for actuators parameters */
    struct SubActuatorConfig
    {
      std::string          name;
      std::string          mesh;
      float                minAngle;
      float                maxAngle;
      float                startAngle;
      float                maxSpeed;
      AL::Math::Position3D axisRotation;
      std::string          parentActuator; // actuator supportant le doigt
      AL::Math::Transform  transform;      // transform du doigt par rapport au joint qui la porte

      SubActuatorConfig(
          const std::string&          pName           = "",
          const float                 pMinAngle       = 0.0f,
          const float                 pMaxAngle       = 0.0f,
          const float                 pStartAngle     = 0.0f,
          const float                 pMaxSpeed       = 0.0f,
          const AL::Math::Position3D& pAxisRotation   = AL::Math::Position3D(),
          const std::string&          pParentActuator = "") :
          name(pName),
          mesh(""),
          minAngle(pMinAngle),
          maxAngle(pMaxAngle),
          startAngle(pStartAngle),
          maxSpeed(pMaxSpeed),
          axisRotation(pAxisRotation),
          parentActuator(pParentActuator),
          transform(AL::Math::Transform()){};
    };
  }
}
#endif  // _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALSUBACTUATORCONFIG_H_
