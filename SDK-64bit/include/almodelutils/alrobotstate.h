/**
* @author Cyrille Collette
* Copyright (c) Aldebaran Robotics 2010 All Rights Reserved
*/

#pragma once

#ifndef _LIB_ALMODELUTILS_ALMODELUTILS_ALROBOTSTATE_H_
#define _LIB_ALMODELUTILS_ALMODELUTILS_ALROBOTSTATE_H_

#include <almodelutils/almodeltype.h>

namespace AL {

    struct ALRobotState
    {
      unsigned int   robotNumLegs;
      unsigned int   robotNumArms;
      unsigned int   robotNumHands;

      ROBOT_VERSION  armVersion;
      ROBOT_VERSION  headVersion;
      ROBOT_VERSION  bodyVersion;
      LASER_OR_NOT   laser;
      ROBOCUP_OR_NOT robocup;

      ALRobotState() :
        robotNumLegs(2),
        robotNumArms(2),
        robotNumHands(2),
        armVersion(VERSION_32),
        headVersion(VERSION_32),
        bodyVersion(VERSION_32),
        laser(LASER_FALSE),
        robocup(ROBOCUP_FALSE)
        {}
    };
}
#endif  // _LIB_ALMODELUTILS_ALMODELUTILS_ALROBOTSTATE_H_
