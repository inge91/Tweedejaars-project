/**
* @author Cyrille Collette
* Copyright (c) Aldebaran Robotics 2011 All Rights Reserved
*/
#pragma once

#ifndef _LIB_ALMOTION_ALMODELUTILS_MODEL_TYPES_ALCOLLISIONSHAPE_SPHERE_H_
#define _LIB_ALMOTION_ALMODELUTILS_MODEL_TYPES_ALCOLLISIONSHAPE_SPHERE_H_

#include <string>
#include <almath/types/alposition3d.h>
#include <almodelutils/model/types/alcollisionshape.h>

namespace AL
{
namespace Motion
{

class ALCollisionShape_Sphere: public ALCollisionShape
{
public:

  /**
     * Constructor.
     */
  ALCollisionShape_Sphere(
    const COLLISION_SHAPE&      pType        = COLLISION_SHAPE_SPHERE,
    const std::string&          pName        = "",
    const std::string&          pParentJoint = "",
    const float&                pRadius      = 0.0f,
    const AL::Math::Position3D& pPos         = AL::Math::Position3D());

  virtual std::string getName(void);

  virtual std::string getParentJoint(void);

  /**
     * Destructor.
     */
  virtual ~ALCollisionShape_Sphere();

// protected:
  std::string          name;
  std::string          parentJoint;
  float                radius;
  // Position in local parent joint repere
  AL::Math::Position3D pos;
};

}
}
#endif  // _LIB_ALMOTION_ALMODELUTILS_MODEL_TYPES_ALCOLLISIONSHAPE_SPHERE_H_
