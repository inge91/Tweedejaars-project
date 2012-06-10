/**
* @author Cyrille Collette
* Copyright (c) Aldebaran Robotics 2010 All Rights Reserved
*/
#pragma once

#ifndef _LIB_ALMODELUTILS_ALMODELUTILS_ALMODEL_CHOICEUTILS_H_
#define _LIB_ALMODELUTILS_ALMODELUTILS_ALMODEL_CHOICEUTILS_H_

#include <almodelutils/alrobotstate.h>

namespace AL
{

    ALRobotState stringsToRobotState(
      const std::string& pLegsVs,
      const std::string& pArmsVs,
      const std::string& pHandsVs,
      const std::string& pHeadVs,
      const std::string& pBodyVs,
      const std::string& pLaserVs,
      const std::string& pRobocupVs);

    void stringsToRobotState(
      const std::string& pLegsVs,
      const std::string& pArmsVs,
      const std::string& pHandsVs,
      const std::string& pHeadVs,
      const std::string& pBodyVs,
      const std::string& pLaserVs,
      const std::string& pRobocupVs,
      ALRobotState&      pRobotState);


    MODEL_TYPE robotStateToModelType(const ALRobotState& pRobotState);


} // end namespace AL
#endif  // _LIB_ALMODELUTILS_ALMODELUTILS_ALMODEL_CHOICEUTILS_H_

