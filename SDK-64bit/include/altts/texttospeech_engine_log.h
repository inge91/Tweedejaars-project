/**
* @author Patrick de Pas
* Aldebaran Robotics (c) 2010 All Rights Reserved - This file is confidential.\n
*
* Version : $0.0$
*/

#pragma once

#ifndef _LIB_ALTTS_TEXTTOSPEECH_ENGINE_LOG_H_
#define _LIB_ALTTS_TEXTTOSPEECH_ENGINE_LOG_H_

#include "texttospeech_engine.h"
#include <string>
#include <vector>



namespace AL
{

  class TextToSpeechLog : public TextToSpeechEngine
  {

  public:

    TextToSpeechLog(TtsCallBack callback, TtsEventCallBack receiveBufferCallback,
                    void * manager, const std::string & pathToVoicesDirectory = "");

    ~TextToSpeechLog();

  private:

    std::string xGetName() const;

    bool xInitialize();
    bool xTerminate();

    void xStartSynthetizer( const std::string &stringToSay );
    void xPauseSynthetizer();
    void xStopSynthetizer();
    void xRestartSynthetizer(){};

    void xSetParameter ( const std::string &pEffectName, const float &pEffectValue );
    float xGetParameter ( const std::string &pEffectName ) const;

    void xSetCurrentLanguage ( const std::string &pLanguage );
    std::string xGetCurrentLanguage () const;

    void xSetCurrentVoice ( const std::string &pVoiceID );
    std::string xGetCurrentVoice () const;

    std::map<std::string, std::string> xGetAvailableVoices() const;
    std::vector<std::string> xGetAvailableLanguages() const;
    std::vector<std::string> xGetAvailableParameters() const;

    int xGetCurrentSamplingRate() const;

    std::string xReplaceTags(const std::string &pText,
                             const std::string & newchar);

    bool xTestTextEncoding(const std::string &pText) ;


  private:
    const std::string fMarkerFirst;
    const std::string fMarkerLast;
    bool fStopImmediately;
  };

}
#endif  // _LIB_ALTTS_TEXTTOSPEECH_ENGINE_HTS_H_


