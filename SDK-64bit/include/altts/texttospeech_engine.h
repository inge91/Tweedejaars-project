/**
* @author Gwennael Gate
* Aldebaran Robotics (c) 2010 All Rights Reserved - This file is confidential.\n
*
* Version : $0.0$
*/

#include <string>
#include <map>
#include <vector>

#include <althread/almutex.h>
#include <althread/alcriticalsection.h>

#ifndef TEXTTOSPEECHENGINEIMPL_H
#define TEXTTOSPEECHENGINEIMPL_H

namespace AL
{
  typedef void (*TtsCallBack)(void *data, signed short* buffer, unsigned int size);
  typedef void (*TtsEventCallBack)(void *data, int eventType, int value);

  class TextToSpeechEngine
  {
  public:
    TextToSpeechEngine(TtsCallBack callback,
                       TtsEventCallBack receiveEventCallback,
                       void * manager);

    virtual ~TextToSpeechEngine();

    std::string getName() const;

    bool initialize();
    bool terminate();
    void reload();

    void startSynthetizer(const std::string &pStringToSay);
    void pauseSynthetizer();
    void stopSynthetizer();
    void restartSynthetizer();

    void setParameter( const std::string &pEffectName,
                       const float &pEffectValue );

    float getParameter( const std::string &pEffectName ) const;

    void setCurrentLanguage( const std::string &pLanguage );
    std::string getCurrentLanguage() const;

    void setCurrentVoice( const std::string &pVoiceID );
    std::string getCurrentVoice() const;

    std::map<std::string, std::string> getAvailableVoices() const;
    std::vector<std::string> getAvailableLanguages() const;
    std::vector<std::string> getAvailableParameters() const;

    int getCurrentSamplingRate() const;

    bool isInitialized() const;

    bool testTextEncoding(const std::string &pText);

    void enableNotifications();
    void disableNotifications();

    //virtual int test() {};

  private:

    virtual std::string xGetName() const = 0;

    virtual bool xInitialize() = 0;
    virtual bool xTerminate() = 0;

    virtual void xStartSynthetizer( const std::string &pStringToSay ) = 0;
    virtual void xStopSynthetizer() = 0;
    virtual void xPauseSynthetizer() = 0;
    virtual void xRestartSynthetizer() = 0;

    virtual void xSetParameter ( const std::string &pEffectName,
                                 const float &pEffectValue ) = 0;

    virtual float xGetParameter ( const std::string &pEffectName ) const = 0;

    virtual void xSetCurrentLanguage ( const std::string &pLanguage ) = 0;

    virtual void xSetCurrentVoice ( const std::string &pVoiceID ) = 0;

    virtual std::map<std::string, std::string> xGetAvailableVoices() const = 0;
    virtual std::vector<std::string> xGetAvailableLanguages() const = 0;
    virtual std::vector<std::string> xGetAvailableParameters() const = 0;

    virtual int xGetCurrentSamplingRate() const = 0;

    virtual bool xTestTextEncoding(const std::string &pText) = 0;
    virtual void xEnableNotifications() {}
    virtual void xDisableNotifications(){}

  protected:
    std::string fCurrentLanguage;
    std::string fCurrentVoice;
    bool fIsInitialized;
    bool fIsCallBackSet;
    bool fbNotificationsEnabled;
    bool fbEngineIsStarted;
    bool fbEngineIsPaused;

  public:
    TtsCallBack fTtsCallBack;
    TtsEventCallBack fTtsEventCallBack;
    void * fManager;
  };
}


#endif // TEXTTOSPEECHENGINEIMPL_H


