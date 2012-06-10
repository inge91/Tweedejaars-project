/**
* @author Cyrille Collette and Geoffrey Bosne
* Copyright (c) Aldebaran Robotics 2010 All Rights Reserved
*/


#pragma once

#ifndef _LIB_ALMOTION_ALMOTION_MODEL_DATA_ALMODEL_ROMEO_H_
#define _LIB_ALMOTION_ALMOTION_MODEL_DATA_ALMODEL_ROMEO_H_

#include <almodelutils/model/types/alrobotconfig.h>
#include <almodelutils/model/types/alchainconfig.h>
#include <almodelutils/model/types/alsensorconfig.h>
#include <almodelutils/model/types/alactuatorconfig.h>
#include <almodelutils/model/types/alsubactuatorconfig.h>
#include <almodelutils/model/types/alwalkconfig.h>

#include <almodelutils/model/types/alcollisionshape.h>

#include <almodelutils/alrobotstate.h>

#include <boost/shared_ptr.hpp>
#include <string>
#include <map>

namespace AL
{
  namespace Motion
  {
    namespace Model
    {

      void loadDataRomeo(
        const ALRobotState&                       pRobotState,
        RobotConfig&                              pRobotConfig,
        std::map<std::string, ActuatorConfig>&    pActuatorConfig,
        std::map<std::string, SensorConfig>&      pSensorConfig,
        std::map<std::string, JointConfig>&       pJointConfig,
        std::map<std::string, ChainConfig>&       pChainConfig,
        std::map<std::string, SubActuatorConfig>& pSubActuatorConfig,
        std::map<std::string, boost::shared_ptr<ALCollisionShape> >&  pCollisionShape,
        ALWalkConfig&                             pWalkConf);

    } // end namespace model
  } // end namespace motion
} // end namespace al
#endif  // _LIB_ALMOTION_ALMOTION_MODEL_DATA_ALMODEL_ROMEO_H_



