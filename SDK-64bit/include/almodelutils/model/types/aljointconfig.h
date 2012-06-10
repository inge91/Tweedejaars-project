/**
* @author Chris Kilner
* Copyright (c) Aldebaran Robotics 2010 All Rights Reserved
*/

#pragma once

#ifndef _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALJOINTCONFIG_H_
#define _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALJOINTCONFIG_H_

#include <string>
#include <almath/types/alposition3d.h>
#include <almath/types/altransform.h>
#include <almodelutils/types/almirror.h>

namespace AL
{
  namespace Motion
  {
    /* Used as a container for joint parameters */
    struct JointConfig
    {
      std::string          name;
      std::string          mesh;
      float                minAngle;
      float                maxAngle;
      float                startAngle;
      float                maxTorque;
      float                maxSpeed;
      float                mass;
      std::vector<float>   inertialMatrix;
      AL::Math::Position3D com;
      AL::Math::Position3D comOrigin;
      AL::Math::Transform  basicTransform;
      AL::Math::Transform  endTransform;
      AL::Math::Position3D axisRotation;
      Mirror               mirror;

      // params other than Name can not be in constructor because
      // of the "if/else if" conditions generated for different versions
      JointConfig(
        const std::string& pName = "") :
        name(pName),
        mesh(""),
        minAngle(0.0),
        maxAngle(0.0),
        startAngle(0.0),
        maxTorque(0.0),
        maxSpeed(0.0),
        mass(0.0f),
        com(AL::Math::Position3D()),
        comOrigin(AL::Math::Position3D()),
        basicTransform(AL::Math::Transform()),
        endTransform(AL::Math::Transform()),
        axisRotation(AL::Math::Position3D()),
        mirror()
      {
        inertialMatrix.resize(9);
        for(unsigned int i =0; i< 9; i++)
          inertialMatrix[i] = 0;
      }
    };

  }
}
#endif  // _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALJOINTCONFIG_H_
