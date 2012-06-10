/**
* @author Geoffrey Bosne
* Copyright (c) Aldebaran Robotics 2010 All Rights Reserved
*/

#pragma once

#ifndef _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALCHAINCONFIG_H_
#define _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALCHAINCONFIG_H_
#include <string>
#include <vector>
#include <almath/types/altransform.h>

namespace AL
{
  namespace Motion
  {
    /* Used as a container for chains parameters */
    struct ChainConfig
    {
      std::string               name;            // name of chain
      unsigned int              chainID;         // ID of Chain
      std::string               parentJoint;
      unsigned int              nbJoints;
      std::vector<std::string>  jointNames;
      // Transform de la chain par rapport au corps d'attache
      AL::Math::Transform       baseTransform;
      AL::Math::Transform       endTransform;
      std::string               image;

      ChainConfig(
        const std::string&  pName        = "",
        const std::string&  pParentJoint = "",
        const unsigned int  pNbJoints    = 0):
        name(pName),
        chainID(0),
        parentJoint(pParentJoint),
        nbJoints(pNbJoints),
        baseTransform(AL::Math::Transform()),
        endTransform(AL::Math::Transform()),
        image(""){};
    };
  }
}
#endif  // _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALCHAINCONFIG_H_
