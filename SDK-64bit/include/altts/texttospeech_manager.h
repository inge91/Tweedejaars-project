/**
* @author Gwennael Gate
* Aldebaran Robotics (c) 2010 All Rights Reserved - This file is confidential.\n
*
* Version : $0.0$
*/

#pragma once

#ifndef _LIB_ALTTS_TEXTTOSPEECH_MANAGER_H_
#define _LIB_ALTTS_TEXTTOSPEECH_MANAGER_H_

#include <string>
#include <vector>
#include <map>


#include <boost/shared_ptr.hpp>
#include "texttospeech_engine.h"
#include "althread/almutex.h"

#include <iostream>

namespace AL
{
  class TextToSpeechManager : public TextToSpeechEngine
  {

  public:

    TextToSpeechManager(TtsCallBack parentModuleCallback,
                        TtsEventCallBack parentModuleEventCallback,
                        void *ttsParentModule);

    ~TextToSpeechManager();

    bool xInitialize();
    bool xTerminate();

    void xStartSynthetizer(const std::string & pStringToSay);
    void xPauseSynthetizer();
    void xStopSynthetizer();
    void xRestartSynthetizer();

    void xSetParameter(const std::string &pEffectName, const float &pEffectValue);
    float xGetParameter(const std::string &pEffectName) const;

    void xSetCurrentLanguage(const std::string &pLanguage);

    void xSetCurrentVoice(const std::string &pVoiceID);

    std::map<std::string, std::string> xGetAvailableVoices() const;
    std::vector<std::string> xGetAvailableLanguages() const;
    std::vector<std::string> xGetAvailableParameters() const;

    bool xTestTextEncoding(const std::string &pText);

    int xGetCurrentSamplingRate() const;
    void xEnableNotifications();
    void xDisableNotifications();

    std::string xGetName() const;

    //void test();

  private:

    static void staticCallBack(void * data,
                               signed short* buffer,
                               unsigned int size);
    static void staticReceiveEventCallBack(void * data,
                               int eventType,
                               int value);

    void callBackFromSynthetizer(signed short* data, unsigned int size);
    void callBackEventFromSynthetizer(int eventType, int value);

    boost::shared_ptr< TextToSpeechEngine > xGetRelevantEngine() const;

    std::map< std::string, boost::shared_ptr<TextToSpeechEngine> > fEngineNameToEnginePtr;
    std::map< std::string, std::string > fLanguageToEngineName;
    std::map< std::string, std::string > fVoiceToLanguage;

    const boost::shared_ptr<ALMutex> fMutex;
  };

}
#endif  // _LIB_ALTTS_TEXTTOSPEECH_MANAGER_H_


