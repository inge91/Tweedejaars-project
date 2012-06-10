/**
* @author Cyrille Collette
* Copyright (c) Aldebaran Robotics 2011 All Rights Reserved
*/
#pragma once

#ifndef _LIB_ALMOTION_ALMODELUTILS_MODEL_TYPES_ALCOLLISIONSHAPE_PILL_H_
#define _LIB_ALMOTION_ALMODELUTILS_MODEL_TYPES_ALCOLLISIONSHAPE_PILL_H_

#include <string>
#include <almath/types/alposition3d.h>
#include <almodelutils/model/types/alcollisionshape.h>

namespace AL
{
namespace Motion
{

class ALCollisionShape_Pill: public ALCollisionShape
{
public:

  /**
     * Constructor.
     */
  ALCollisionShape_Pill(
    const COLLISION_SHAPE&      pType        = COLLISION_SHAPE_PILL,
    const std::string&          pName        = "",
    const std::string&          pParentJoint = "",
    const float&                pRadius1     = 0.0f,
    const float&                pRadius2     = 0.0f,
    const AL::Math::Position3D& pPos1        = AL::Math::Position3D(),
    const AL::Math::Position3D& pPos2        = AL::Math::Position3D());

  virtual std::string getName(void);

  virtual std::string getParentJoint(void);

  /**
     * Destructor.
     */
  virtual ~ALCollisionShape_Pill();

// protected:
  std::string          name;
  std::string          parentJoint;
  float                radius1;
  float                radius2;
  // Position in local parent joint repere
  AL::Math::Position3D pos1;
  AL::Math::Position3D pos2;
};

}
}
#endif  // _LIB_ALMOTION_ALMODELUTILS_MODEL_TYPES_ALCOLLISIONSHAPE_PILL_H_

