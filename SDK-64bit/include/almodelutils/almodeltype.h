/**
* @author Chris Kilner
* Copyright (c) Aldebaran Robotics 2009 All Rights Reserved
*/
#pragma once

#ifndef _LIB_ALMODELUTILS_ALMODELUTILS_ALMODELTYPE_H_
#define _LIB_ALMODELUTILS_ALMODELUTILS_ALMODELTYPE_H_

#include <string>

namespace AL {

    /* Used to switch between the two models */
    enum MODEL_TYPE
    {
      MODEL_TYPE_NAO_H25,
      MODEL_TYPE_NAO_H21,
      MODEL_TYPE_NAO_T2,
      MODEL_TYPE_NAO_T14,
      MODEL_TYPE_ROMEO,
      MODEL_TYPE_ROMEO_ONE_LEG
    };

    enum ROBOT_VERSION
    {
      VERSION_32,
      VERSION_33,
      VERSION_40,
      ROMEO,
      ROMEO_ONE_LEG
    };

    enum LASER_OR_NOT
    {
      LASER_FALSE = 0,
      LASER_TRUE  = 1
    };

    enum ROBOCUP_OR_NOT
    {
      ROBOCUP_FALSE = 0,
      ROBOCUP_TRUE  = 1
    };

    std::string modelTypeToString(const MODEL_TYPE pModelType);

    std::string robotVersionToString(const ROBOT_VERSION pRobotVersion);

    void stringToModelType(
      const std::string& pModelTypeString,
      MODEL_TYPE&        pModelType);

}
#endif  // _LIB_ALMODELUTILS_ALMODELUTILS_ALMODELTYPE_H_
