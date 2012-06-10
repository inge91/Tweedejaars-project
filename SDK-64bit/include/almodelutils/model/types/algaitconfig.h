/**
* @author David Gouaillier
* Copyright (c) Aldebaran Robotics 2011 All Rights Reserved
*/

#pragma once

#ifndef _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALGAITCONFIG_H_
#define _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALGAITCONFIG_H_

namespace AL {
  namespace Motion {

    struct ALGaitConfig
    {
      // Foot Step
      unsigned int stepMinPeriod;
      unsigned int stepMaxPeriod;
      float minStepX;
      float maxStepX;
      float maxStepY;
      float maxStepTheta;
      float stepHeight;
      float footSeparation;

      // Torso
      float torsoWx;
      float torsoWy;

      ALGaitConfig(
        // Foot Step
        const unsigned int pStepMinPeriod     = 0,
        const unsigned int pStepMaxPeriod     = 0,
        const float        pMinStepX          = 0.0f,
        const float        pMaxStepX          = 0.0f,
        const float        pMaxStepY          = 0.0f,
        const float        pMaxStepTheta      = 0.0f,
        const float        pStepHeight        = 0.0f,
        const float        pFootSeparation    = 0.0f,
        // Torso
        const float        pTorsoWx = 0.0f,
        const float        pTorsoWy = 0.0f):
          stepMinPeriod(pStepMinPeriod),
          stepMaxPeriod(pStepMaxPeriod),
          minStepX(pMinStepX),
          maxStepX(pMaxStepX),
          maxStepY(pMaxStepY),
          maxStepTheta(pMaxStepTheta),
          stepHeight(pStepHeight),
          footSeparation(pFootSeparation),
          torsoWx(pTorsoWx),
          torsoWy(pTorsoWy){}
    };
  }
}
#endif  // _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALGAITCONFIG_H_
