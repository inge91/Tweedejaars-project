/**
 * @author Chris Kilner
 *
 * Version : $
 */


#pragma once
#ifndef _LIBNAOQICLIENT_NAOQICLIENT_NAOQICLIENT_H_
#define _LIBNAOQICLIENT_NAOQICLIENT_NAOQICLIENT_H_


#include <vector>
#include <string>
#include <naoqiclient/api.h>

namespace AL {
  class ALNaoSimulationInterface;
  class ALMotionProxyInterface;
  class NAOQICLIENT_API ALNaoQiClient
  {
    public:
      ALNaoQiClient(void);
      inline void setALPath(const std::string& path);
      bool runNaoqi(const std::string& playerName);
      void kill();
      virtual ~ALNaoQiClient(void);
      void initialize(const std::string& pName);
      std::string version();

      AL::ALNaoSimulationInterface* getSimulationAPI(const std::string& pIP, int pPort);
      AL::ALNaoSimulationInterface* getSimulationAPI();
      AL::ALMotionProxyInterface* getMotionProxy(const std::string& pIP, int pPort);

    protected:
      std::string fALPath;
      bool fIsConnected;
  };
  inline void ALNaoQiClient::setALPath(const std::string& path) {fALPath = path;}
}
#endif  // _LIBNAOQICLIENT_NAOQICLIENT_NAOQICLIENT_H_

