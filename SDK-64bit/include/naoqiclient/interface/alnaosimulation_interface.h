/**
 * @author Chris Kilner
 *
 * Version : $
 */


#pragma once
#ifndef _LIBNAOQICLIENT_NAOQICLIENT_INTERFACE_ALNAOSIMULATION_INTERFACE_H_
#define _LIBNAOQICLIENT_NAOQICLIENT_INTERFACE_ALNAOSIMULATION_INTERFACE_H_

#include <vector>
#include <string>
#include <naoqiclient/api.h>

#define AL_NUMBER_OF_JOINTS 22
#define AL_NUMBER_OF_FSR 8
#define AL_NUMBER_OF_ACCEL_AXIS 3
typedef unsigned char uint8;

namespace AL {

  /** Helper methods for simulators
  */
  class NAOQICLIENT_API ALNaoSimulationInterface
  {
    public:
      virtual bool isInitialized(void)=0;
      virtual std::vector<float> getBodyAngles(void)=0;
      virtual bool updateRealBodyAngles(std::vector<float> pAngles)=0;
      virtual bool updateSonarValues(float pLeftDistance, float pRightDistance, bool pNothing)=0;
      virtual bool updateFSRValues(std::vector<float> pFSRValues)=0;
      virtual bool updateAccelerometers(std::vector<float> pAccelValues)=0;
      virtual bool updateInertialValues(std::vector<float> pInertialValues)=0;
      virtual bool shouldReset(void)=0;
      virtual bool updatePositionEstimate(std::vector<float> pPosition)=0;
      virtual bool updateImageSize(int width, int height)=0;
      virtual int  getActiveCamera()=0;
      virtual bool updateImage(uint8 *buffer, int width, int height)=0;
      virtual bool insertFloatInMemory(const std::string& pName,const float pValue)=0;
      virtual float getConfidence(const std::string& pWord, const std::vector<std::string> & pWordList, const std::string &pLanguage, const int & pNbVoices)=0;
      virtual void  readPhonetizations(const std::string& pWord, const std::string &pLanguage)=0;
      virtual bool updateLaserValues(const std::vector<std::pair<int, float> >& pLaserValues)=0;
  };

}

#endif  // _LIBNAOQICLIENT_NAOQICLIENT_INTERFACE_ALNAOSIMULATION_INTERFACE_H_

