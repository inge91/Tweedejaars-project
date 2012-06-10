/**
* @author Julien Fremy and Cyrille Collette
* Copyright (c) 2010 Aldebaran Robotics  All Rights Reserved
*/

#pragma once

#ifndef _LIB_ALMODELUTILS_ALMODELUTILS_ALMODELUTILS_H_
#define _LIB_ALMODELUTILS_ALMODELUTILS_ALMODELUTILS_H_

#include <map>
#include <set>
#include <string>

#include <almodelutils/alrobotstate.h>

namespace AL
{

class ModelUtils{

  public:

    enum Format
    {
      DCM,
      MOTION,
      UNKNOWN,
    };

    static void robotStateFromXml(
      const std::string& xmlString,
      ALRobotState& pRobotState);

    static void robotStateFromDcmXml(
      const std::string& xmlString,
      ALRobotState& pRobotState);

    static bool checkMotionXml(const std::string& xmlString);
    static bool checkDcmXml(const std::string& xmlString);
    static const Format determineFormat(const std::string& xmlString);

    static std::string xmlFromDcmMap(
      const std::map<std::string, std::string>& dcmValues);

    static std::map<std::string, std::string> motionMapFromXml(
      const std::string& xmlString);

    static std::map<std::string, std::string> motionMapFromDcmXml(
      const std::string& xmlString);

    static std::string defaultModel();

    static std::string robotNameFromXml(const std::string& xml);

  private:

    static std::map<std::string, std::string> xMotionMapFromDcmMap(
      const std::map<std::string, std::string>& dcmMap);

    static std::string xXmlFromMotionMap(
      const std::map<std::string, std::string>& motionValues);

    static void xMotionMapToMotionValues(
      const std::map<std::string, std::string>& pMotionValues,
      std::string& pLegsVersion,
      std::string& pArmsVersion,
      std::string& pHandsVersion,
      std::string& pHeadVersion,
      std::string& pBodyVersion,
      std::string& pLaserVersion,
      std::string& pRobocupVersion);

    static bool xValidateMotionMap(
      const std::map<std::string, std::string>& motionMap);

  public:
    static const std::string defaultLegsVersionName;
    static const std::string defaultArmsVersionName;
    static const std::string defaultHandsVersionName;
    static const std::string defaultBodyVersionName;
    static const std::string defaultHeadVersionName;
    static const std::string defaultLaserVersionName;
    static const std::string defaultRobocupVersionName;

    /// for DCM map
    static const std::string dcmRobotConfigLegsVersion;
    static const std::string dcmRobotConfigLeftArmVersion;
    static const std::string dcmRobotConfigRightArmVersion;
    static const std::string dcmRobotConfigLeftHandVersion;
    static const std::string dcmRobotConfigRightHandVersion;
    static const std::string dcmRobotConfigBodyVersion;
    static const std::string dcmRobotConfigHeadVersion;
    static const std::string dcmRobotConfigHeadLaserVersion;
    static const std::string dcmRobotConfigTouchBoardVersion;

  private:
    static const std::string romeoBeacon;
    static const std::string naoT2V33Beacon;
    static const std::string naoT2V32Beacon;
    static const std::string naoT14V33Beacon;
    static const std::string naoT14V32Beacon;
    static const std::string naoH21V33Beacon;
    static const std::string naoH21V32Beacon;
    static const std::string naoH25V33Beacon;
    static const std::string naoH25V32Beacon;

    static const std::string romeoFileName;
    static const std::string naoT2V33FileName;
    static const std::string naoT2V32FileName;
    static const std::string naoT14V33FileName;
    static const std::string naoT14V32FileName;
    static const std::string naoH21V33FileName;
    static const std::string naoH21V32FileName;
    static const std::string naoH25V33FileName;
    static const std::string naoH25V32FileName;

    static std::set<std::string> legValues;
    static std::set<std::string> armValues;
    static std::set<std::string> handValues;
    static std::set<std::string> bodyValues;
    static std::set<std::string> headValues;
    static std::set<std::string> laserValues;
    static std::set<std::string> robocupValues;
};

} // namespace

#endif  // _LIB_ALMODELUTILS_ALMODELUTILS_ALMODELUTILS_H_
