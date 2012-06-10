/**
* @author Cyrille Collette
* Copyright (c) Aldebaran Robotics 2010 All Rights Reserved
*/


#pragma once

#ifndef _LIB_ALMOTION_ALMOTION_MODEL_DATA_ALMODEL_DATA_H_
#define _LIB_ALMOTION_ALMOTION_MODEL_DATA_ALMODEL_DATA_H_

#include <map>

#include <almodelutils/alrobotstate.h>

#include <almodelutils/model/types/alrobotconfig.h>
#include <almodelutils/model/types/alchainconfig.h>
#include <almodelutils/model/types/alsensorconfig.h>
#include <almodelutils/model/types/alactuatorconfig.h>
#include <almodelutils/model/types/alsubactuatorconfig.h>
#include <almodelutils/model/types/alcollisionshape.h>
#include <almodelutils/model/types/alwalkconfig.h>

#include <boost/shared_ptr.hpp>

namespace AL
{
  namespace Motion
  {
    namespace Model
    {

      void loadModelData(
        const ALRobotState&                       paraRobotState,
        RobotConfig&                              paraRobotConfig,
        std::map<std::string, ActuatorConfig>&    paraActuatorConfig,
        std::map<std::string, SensorConfig>&      paraSensorConfig,
        std::map<std::string, JointConfig>&       paraJointConfig,
        std::map<std::string, ChainConfig>&       paraChainConfig,
        std::map<std::string, SubActuatorConfig>& paraSubActuatorConfig,
        std::map<std::string, boost::shared_ptr<ALCollisionShape> >&  paraCollisionShape,
        ALWalkConfig&                             paraWalkConf);

    } // end namespace model
  } // end namespace motion
} // end namespace al
#endif  // _LIB_ALMOTION_ALMOTION_MODEL_DATA_ALMODEL_DATA_H_
