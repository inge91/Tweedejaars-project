/**
* @author Cyrille Collette
* Copyright (c) Aldebaran Robotics 2011 All Rights Reserved
*/
#pragma once

#ifndef _LIB_ALMOTION_ALMODELUTILS_MODEL_TYPES_ALCOLLISIONSHAPE_H_
#define _LIB_ALMOTION_ALMODELUTILS_MODEL_TYPES_ALCOLLISIONSHAPE_H_

#include <almodelutils/model/types/alcollisionshape_utils.h>

#include <iostream>

namespace AL
{
namespace Motion
{


class ALCollisionShape
{
public:

  /**
    * Constructor.
    */
  // par defaut
  ALCollisionShape(const COLLISION_SHAPE& pCollisionShape = COLLISION_SHAPE_SPHERE);

  virtual std::string getName(void) = 0;

  virtual std::string getParentJoint(void) = 0;

  COLLISION_SHAPE getCollisionShape(void);

  /**
    * Destructor.
    */
  virtual ~ALCollisionShape();

protected:
  COLLISION_SHAPE fCollisionShape;
};


}
}
#endif  // _LIB_ALMOTION_ALMODELUTILS_MODEL_TYPES_ALCOLLISIONSHAPE_H_
