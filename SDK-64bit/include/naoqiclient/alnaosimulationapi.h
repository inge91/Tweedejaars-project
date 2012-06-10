/**
 * @author Chris Kilner
 *
 * Version : $
 */


#pragma once
#ifndef _LIBNAOQICLIENT_NAOQICLIENT_ALNAOSIMULATIONAPI_H_
#define _LIBNAOQICLIENT_NAOQICLIENT_ALNAOSIMULATIONAPI_H_

#include <vector>
#include <boost/shared_ptr.hpp>
#include <naoqiclient/api.h>
#include <naoqiclient/interface/alnaosimulation_interface.h>

#define AL_NUMBER_OF_JOINTS 22
#define AL_NUMBER_OF_FSR 8
#define AL_NUMBER_OF_ACCEL_AXIS 3

namespace AL {
  class ALProxy;
  class ALBroker;
  class NAOQICLIENT_API ALNaoSimulationAPI : public ALNaoSimulationInterface
  {
    public:
      ALNaoSimulationAPI(std::string pIP, int pPort);
      ALNaoSimulationAPI(boost::shared_ptr<ALBroker> pBroker );
      virtual ~ALNaoSimulationAPI(void);
      bool isInitialized(void);

      bool shouldReset(void);
      std::vector<float> getBodyAngles(void);
      bool updateRealBodyAngles(std::vector<float> pAngles);

      /**
      * updateSonarValues. Update event (high level information), not DCM value (hardware)
      * @param pLeftDistance left obstacle distance
      * @param pRightDistance right obstacle distance
      * @param nothing true to signal left or right obstacle disapeared
      * @result true if succeed to update ALMemory information
      */
      bool updateSonarValues(float pLeftDistance, float pRightDistance, bool pNothing);
      bool updateFSRValues(std::vector<float> pFSRValues);
      bool updateAccelerometers(std::vector<float> pAccelValues);
      bool updateInertialValues(std::vector<float> pInertialValues);
      bool updatePositionEstimate(std::vector<float>);
      bool updateImageSize(int width, int height);
      int  getActiveCamera();
      // Warning, buffer must be valid pointer to a width * height * 3 byte zone.
      bool updateImage(uint8 *buffer, int width, int height);
      bool insertFloatInMemory(const std::string& pName,const float pValue);


      // Get the confidence for a word recognized by ALSpeechRecognition
      float getConfidence(const std::string& pWord, const std::vector<std::string> & pWordList, const std::string &pLanguage, const int & pNbVoices);
      void  readPhonetizations(const std::string & pWord, const std::string & pLanguage);

      /**
       * updateLaserValues
       * @param pLaserValues vector of pairs distance (mm), angle (rad)
       * @return true if succeed to update ALMemory information
       */
      bool updateLaserValues(const std::vector<std::pair<int, float> >& pLaserValues);

    protected:
      void xInit(void);
      bool fIsInitialized;
      std::vector<std::string> fJointNames;
      std::vector<std::string> fFSRNames;
      std::vector<std::string> fAccelerometerNames;
      std::vector<std::string> fInertialNames;
      std::vector<std::string> fPositionEstimate;
      bool xSendUpdates(std::vector<std::string>& pNames, std::vector<float> pValues);

      boost::shared_ptr< ALProxy> fMemory;
      boost::shared_ptr< ALProxy> fNaoCam;
      boost::shared_ptr< ALProxy> fMotion;
      boost::shared_ptr< ALProxy> fSpeechReco;
      boost::shared_ptr< ALProxy> fTextToSpeech;

  };
}
#endif  // _LIBNAOQICLIENT_NAOQICLIENT_ALNAOSIMULATIONAPI_H_
