/**
* @author Geoffrey Bosne
* Copyright (c) Aldebaran Robotics 2010 All Rights Reserved
*/

#pragma once

#ifndef _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALROBOTCONFIG_H_
#define _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALROBOTCONFIG_H_

#include <string>
#include <almodelutils/model/types/aljointconfig.h>
#include <almodelutils/model/types/alarticularlimits.h>

namespace AL
{
  namespace Motion
  {

  struct wbConfig
  {
    // Head WX WY WZ
    float headWXInit;
    float headWXMin;
    float headWXMax;
    float headWYInit;
    float headWYMin;
    float headWYMax;
    float headWZInit;
    float headWZMin;
    float headWZMax;
    // LArm X Y Z
    float lArmXInit;
    float lArmXMin;
    float lArmXMax;
    float lArmYInit;
    float lArmYMin;
    float lArmYMax;
    float lArmZInit;
    float lArmZMin;
    float lArmZMax;
    // RArm X Y Z
    float rArmXInit;
    float rArmXMin;
    float rArmXMax;
    float rArmYInit;
    float rArmYMin;
    float rArmYMax;
    float rArmZInit;
    float rArmZMin;
    float rArmZMax;

    wbConfig():
      headWXInit(0.0f),
      headWXMin(0.0f),
      headWXMax(0.0f),
      headWYInit(0.0f),
      headWYMin(0.0f),
      headWYMax(0.0f),
      headWZInit(0.0f),
      headWZMin(0.0f),
      headWZMax(0.0f),
      lArmXInit(0.0f),
      lArmXMin(0.0f),
      lArmXMax(0.0f),
      lArmYInit(0.0f),
      lArmYMin(0.0f),
      lArmYMax(0.0f),
      lArmZInit(0.0f),
      lArmZMin(0.0f),
      lArmZMax(0.0f),
      rArmXInit(0.0f),
      rArmXMin(0.0f),
      rArmXMax(0.0f),
      rArmYInit(0.0f),
      rArmYMin(0.0f),
      rArmYMax(0.0f),
      rArmZInit(0.0f),
      rArmZMin(0.0f),
      rArmZMax(0.0f) {}
  };

    struct Coupled
    {
      std::vector<std::string>      jointNames;
      std::vector<unsigned short>   jointIndexes;
      std::vector<unsigned short>   bodyIndexes;
      std::vector<unsigned short>   chainIndexes;
    };

    struct PaireCollisionLoad {
      std::string name1;
      std::string name2;
      bool        isSmartstiffness;
      bool        isRepulsion;

      PaireCollisionLoad(
        const std::string& pName1            = "",
        const std::string& pName2            = "",
        const bool&        pIsSmartstiffness = false,
        const bool&        pIsRepulsion      = false):
        name1(pName1),
        name2(pName2),
        isSmartstiffness(pIsSmartstiffness),
        isRepulsion(pIsRepulsion) {}
    };

    struct RobotConfig
    {
      unsigned int                   nbChains;
      unsigned int                   nbContacts;
      // is not in the xml model and is filled in the model.h
      unsigned int                   nbSensors;

      std::vector<std::string>       chainNames;
      std::vector<std::string>       sensorNames;
      std::vector<std::string>       actuatorNames;
      std::vector<std::string>       contactNames;
      std::vector<std::string>       tagNames;

      Coupled                        coupled;
      std::vector<ALArticularLimits> articularLimits;
      JointConfig                    root;

      std::vector<PaireCollisionLoad> paireCollisionLoad;

      wbConfig                        wbConf;

      RobotConfig(
        const unsigned int pNbChains   = 0,
        const unsigned int pNbContacts = 0):
      nbChains(pNbChains),
        nbContacts(pNbContacts),
        nbSensors(0){};
    };
  }
}


#endif  // _LIB_ALMOTION_ALMOTION_MODEL_TYPES_ALROBOTCONFIG_H_
