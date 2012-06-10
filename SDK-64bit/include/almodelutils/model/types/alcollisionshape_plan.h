/**
* @author Cyrille Collette
* Copyright (c) Aldebaran Robotics 2011 All Rights Reserved
*/
#pragma once

#ifndef _LIB_ALMOTION_ALMODELUTILS_MODEL_TYPES_ALCOLLISIONSHAPE_PLAN_H_
#define _LIB_ALMOTION_ALMODELUTILS_MODEL_TYPES_ALCOLLISIONSHAPE_PLAN_H_

#include <string>
#include <almath/types/alposition3d.h>
#include <almodelutils/model/types/alcollisionshape.h>

namespace AL
{
namespace Motion
{

class ALCollisionShape_Plan: public ALCollisionShape
{
public:

  /**
     * Constructor.
     */
  ALCollisionShape_Plan(
    const COLLISION_SHAPE& pType    = COLLISION_SHAPE_PLAN,
    const std::string& pName        = "",
    const std::string& pParentJoint = "");

  virtual std::string getName(void);

  virtual std::string getParentJoint(void);

  /**
     * Destructor.
     */
  virtual ~ALCollisionShape_Plan();

//protected:
  std::string          name;
  std::string          parentJoint;
};

}
}
#endif  // _LIB_ALMOTION_ALMODELUTILS_MODEL_TYPES_ALCOLLISIONSHAPE_PLAN_H_
