/**
* @author Cyrille Collette
* Copyright (c) Aldebaran Robotics 2010 All Rights Reserved
*/

#pragma once

#ifndef _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALWALKCONFIG_H_
#define _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALWALKCONFIG_H_

#include <almodelutils/model/types/algaitconfig.h>
#include <almath/types/alpose2d.h>
#include <vector>
#include <string>

namespace AL {
  namespace Motion {

    struct ALWalkConfig
    {
      // If 1, use all nbPreviewSamples
      // If x, use 1 to x preview sample, more faster
      int previewRatio;

      // which preview used
      // 1: preview with fix foot
      // 2: preview with dynamic foot placement
      int previewUsed;

      // which preview torso used
      // 1: preview with Acc contraint
      // 2: preview with smooth
      int previewTorsoUsed;

      float perturbationGain;   // usefull for JOYSTICK PERTURBATION
      float perturbationFactor; // usefull for JOYSTICK PERTURBATION

      // WALK USER
      // Number of previous sample needed
      // to compute com trajectory
      unsigned int nbPreviewSamples;
      unsigned int nbSamplesFirstAndLastFootStep;
      float minTorsoWx;
      float maxTorsoWx;
      float minTorsoWy;
      float maxTorsoWy;
      float percentOfDoubleSupport;
      float invertedPendulumHeight;

      // Foot Step
      float minFootSeparation;
      float footOrientation;
      float minStepHeight;
      float maxStepHeight;
      unsigned int stepMinPeriod;
      unsigned int stepMaxPeriod;
      float minStepX;
      float maxStepX;
      float maxStepY;
      float maxStepTheta;

      // cop trajectory offset
      float copOffsetX;
      float copOffsetY;

      // gait config
      ALGaitConfig defaultGaitConfig;

      // Close loop
      float observerGain;
      int   sensorDelay;
      float deadzoneCopError;
      float maxTrapezoid;
      float minTrapezoid;
      bool enableSensorDelayFootStep;
      bool enableSensorDelayTorsoHeight;

      // Arm motions
      std::string shoulderPitchName;
      std::string shoulderYawName;
      std::string elbowYawName;
      std::string elbowRollName;
      bool wristRollActif;

      float shoulderPitchMedian;
      float shoulderPitchAmplitude;
      float shoulderYawMedian;
      float shoulderYawAmplitude;
      float elbowYawMedian;
      float elbowRollMedian;
      float elbowRollAmplitude;
      float wristRollMedian;

      // Torso Height
      bool         enableTorsoHeight;
      float        torsoHeight;
      float        minTorsoHeight;
      float        maxTorsoHeight;
      float        maxLegLength;
      unsigned int nbPreviewTorsoHeight;
      float        maxVerticalAccelerationTorso;
      // Offset between absolute max trajectory and constraint trajectory
      float        offsetConstraintTorsoHeight;
      // Offset between constraint trajectory and desired trajectory
      float        offsetDesiredTorsoHeight;
      float        torsoHeightWeightQ;
      float        torsoHeightWeightR;

      // Foot Bounding box
      // usefull for check foot collision
      std::vector<AL::Math::Pose2D> leftFootBoundingBox;
      std::vector<AL::Math::Pose2D> rightFootBoundingBox;

      ALWalkConfig() :
        previewRatio(1),
        previewUsed(1),
        previewTorsoUsed(2),
        perturbationGain(0.0f),
        perturbationFactor(0.0f),

        // WALK USER PARAMS ARE DEFINED IN THE XML MODELS
        nbPreviewSamples(40),
        nbSamplesFirstAndLastFootStep(20),
        minTorsoWx(0.0f),
        maxTorsoWx(0.0f),
        minTorsoWy(0.0f),
        maxTorsoWy(0.0f),
        percentOfDoubleSupport(0.0f),
        invertedPendulumHeight(0.0f),

        // foot steps
        minFootSeparation(0.0f),
        footOrientation(0.0f),
        minStepHeight(0.0f),
        maxStepHeight(0.0f),
        stepMinPeriod(0),
        stepMaxPeriod(0),
        minStepX(0.0f),
        maxStepX(0.0f),
        maxStepY(0.0f),
        maxStepTheta(0.0f),

        // cop trajectory offset
        copOffsetX(0.0f),
        copOffsetY(0.0f),

        // gait config
        defaultGaitConfig(),

        // Close loop
        observerGain(0.5f),
        sensorDelay(40),
        deadzoneCopError(0.0f),
        maxTrapezoid(0.0f),
        minTrapezoid(0.0f),
        enableSensorDelayFootStep(true),
        enableSensorDelayTorsoHeight(true),

        // Arms motions
        shoulderPitchName("ShoulderPitch"),
        shoulderYawName("ShoulderRoll"),
        elbowYawName("ElbowYaw"),
        elbowRollName("ElbowRoll"),
        wristRollActif(false),
        shoulderPitchMedian(0.0f),
        shoulderPitchAmplitude(0.0f),
        shoulderYawMedian(0.0f),
        shoulderYawAmplitude(0.0f),
        elbowYawMedian(0.0f),
        elbowRollMedian(0.0f),
        elbowRollAmplitude(0.0f),
        wristRollMedian(0.0f),

        // TORSO HEIGHT
        enableTorsoHeight(true),
        torsoHeight(0.0f),
        minTorsoHeight(0.0f),
        maxTorsoHeight(0.0f),
        maxLegLength(0.0f),
        nbPreviewTorsoHeight(15), // was 20
        maxVerticalAccelerationTorso(1.0f), // was 0.25f
        offsetConstraintTorsoHeight(0.010f), // with old version: 0.015f -- 0.010f is better
        offsetDesiredTorsoHeight(0.018f), // with old version: 0.020f -- 0.018f is better
        torsoHeightWeightQ(10.0f),
        torsoHeightWeightR(100.0f)
        {}

    };
  }
}
#endif  // _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALWALKCONFIG_H_
