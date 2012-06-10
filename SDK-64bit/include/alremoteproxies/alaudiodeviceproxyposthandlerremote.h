// Generated for ALAudioDevice version 1.12


#ifndef ALAUDIODEVICEPROXYPOSTHANDLERREMOTE_H_
#define ALAUDIODEVICEPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALAudioDeviceProxyRemote;

/// <summary>The ALAudioDevice module allows other modules to access to the sound data of the nao's microphones, and to send sound toward its loudspeakers  The way to receive or send the audio data depends whether the modules are local (dynamic library) or remote (executable).</summary>
class ALAudioDeviceProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALAudioDeviceProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// The ALAudioDevice module allows other modules to access to the sound data of the nao's microphones, and to send sound toward its loudspeakers  The way to receive or send the audio data depends whether the modules are local (dynamic library) or remote (executable).
    /// ALAudioDevicePostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALAudioDeviceProxyPostHandlerRemote() : fParent(NULL)
    {}



    /// <summary>
    /// Closes the audio device for capture. You can call this method if you want to have access to the alsa input buffers in another program than naoqi while naoqi is running (with arecord for example)
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int closeAudioInputs()
    {
      return fParent->pCall("closeAudioInputs");
    }

    /// <summary>
    /// Closes the audio device for playback. close the audio device for capture. You can call this method if you want to send sound to alsa in another program than naoqi while naoqi is running (with aplay for example)
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int closeAudioOutputs()
    {
      return fParent->pCall("closeAudioOutputs");
    }

    /// <summary>
    /// Disables the computation of the energy of each microphone signal
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int disableEnergyComputation()
    {
      return fParent->pCall("disableEnergyComputation");
    }

    /// <summary>
    /// Enables the computation of the energy of each microphone signal
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int enableEnergyComputation()
    {
      return fParent->pCall("enableEnergyComputation");
    }

    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int exit()
    {
      return fParent->pCall("exit");
    }

    /// <summary>
    /// Flush the audio device for playback. close the audio device for capture. You can call this method if you want to send sound to alsa in another program than naoqi while naoqi is running (with aplay for example)
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int flushAudioOutputs()
    {
      return fParent->pCall("flushAudioOutputs");
    }
















    /// <summary>
    /// mute the loudspeakers
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int muteAudioOut(const bool& arg1)
    {
      return fParent->pCall("muteAudioOut" , arg1);
    }

    /// <summary>
    /// Opens the audio device for capture. If you closed the audio inputs with the closeAudioInputs method, you must call this method to be able to access to the sound data of the nao's microphones.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int openAudioInputs()
    {
      return fParent->pCall("openAudioInputs");
    }

    /// <summary>
    /// Opens the audio device for playback. If you closed the audio outputs with the closeAudioOutputs method, you must call this method to ear or send sound onto the nao's loudspeakers.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int openAudioOutputs()
    {
      return fParent->pCall("openAudioOutputs");
    }


    /// <summary>
    /// Play a sine wave which specified caracteristics.
    /// </summary>
    /// <param name="frequence"> Frequence in Hertz </param>
    /// <param name="gain"> Volume Gain between 0 and 100 </param>
    /// <param name="pan"> Stereo Pan set to either {-1,0,+1} </param>
    /// <param name="duration"> Duration of the sine wave in seconds </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int playSine(const int& frequence, const int& gain, const int& pan, const float& duration)
    {
      return fParent->pCall("playSine" , frequence, gain, pan, duration);
    }

    /// <summary>
    /// reset ALSA driver. Use this method only when no audio module is subscribed to ALAudioDevice
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int resetAudio()
    {
      return fParent->pCall("resetAudio");
    }



    /// <summary>
    /// Set AudioDevice Client preferences
    /// </summary>
    /// <param name="name"> name of the client </param>
    /// <param name="sampleRate"> sample rate of the microphones data sent to the process function - must be 16000 or 48000 </param>
    /// <param name="channelsConfiguration"> An int (defined in ALSoundExtractor) indicating which microphones data will be send to the process function. ALLCHANNELS, LEFTCHANNEL, RIGHTCHANNEL, FRONTCHANNEL, REARCHANNEL are the configuration currently supported. </param>
    /// <param name="deinterleaved"> indicates if the microphones data sent to the process function are interleaved or not - 0 : interleaved - 1 : deinterleaved </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setClientPreferences(const std::string& name, const int& sampleRate, const int& channelsConfiguration, const int& deinterleaved)
    {
      return fParent->pCall("setClientPreferences" , name, sampleRate, channelsConfiguration, deinterleaved);
    }

    /// <summary>
    /// Set AudioDevice Client preferences. This function is deprecated, the use of the alternate 4 arguments setClientPreferences() is now prefered.
    /// </summary>
    /// <param name="name"> name of the client </param>
    /// <param name="sampleRate"> sample rate of the microphones data sent to the processSound or processSoundRemote functions - must be 16000 or 48000 </param>
    /// <param name="channelsVector"> ALValue containing a vector of int indicating which microphones data will be send to the processSound or processSoundRemote functions </param>
    /// <param name="deinterleaved"> indicates if the microphones data sent to the processSound or processSoundRemote functions are interleaved or not - 0 : interleaved - 1 : deinterleaved </param>
    /// <param name="timeStamp"> parameter indicating if audio timestamps are sent to the processSound or processSoundRemote functions - 0 : no - 1 : yes </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setClientPreferences(const std::string& name, const int& sampleRate, const AL::ALValue& channelsVector, const int& deinterleaved, const int& timeStamp)
    {
      return fParent->pCall("setClientPreferences" , name, sampleRate, channelsVector, deinterleaved, timeStamp);
    }

    /// <summary>
    /// This method allows to send sound samples contained in a sound file at the input of ALAudioDevice, instead of the nao's microphones sound data. The sound file must be a .wav file containing 16bits / 4 channels / interleaved samples. Once the file has been read, microphones sound data will again taken as input
    /// </summary>
    /// <param name="pFileName"> Name of the input file. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setFileAsInput(const std::string& pFileName)
    {
      return fParent->pCall("setFileAsInput" , pFileName);
    }

    /// <summary>
    /// Sets the output sound level of the system.
    /// </summary>
    /// <param name="volume"> Volume [0-100]. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setOutputVolume(const int& volume)
    {
      return fParent->pCall("setOutputVolume" , volume);
    }

    /// <summary>
    /// This method sets the specified internal parameter ('outputSampleRate' or 'inputBufferSize')
    ///
    /// inputBufferSize can bet set to 8192 or 16384. Warning: when speech recognition is running, a buffer size of 8192 is used. Don't change it during the recognition process.
    ///
    /// outputSampleRate can bet set to 16000 Hz, 22050 Hz, 44100 Hz or 48000 Hz. Warning: if speech synthesis is running, a sample rate of 16000 Hz or 22050 Hz is used (depending of the language). Don't change it during the synthesis process
    /// </summary>
    /// <param name="pParamName"> Name of the parameter to set ('outputSampleRate' or 'inputBufferSize'). </param>
    /// <param name="pParamValue"> The value to which the specified parameter should be set. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setParameter(const std::string& pParamName, const int& pParamValue)
    {
      return fParent->pCall("setParameter" , pParamName, pParamValue);
    }

    /// <summary>
    /// This method allows to record the signal collected on the nao's microphones. You can choose to record only the front microphone in a ogg file, or the 4 microphones in a wav file. In this last case the format of the file is 4 channels, 16 bits little endian, 48 KHz
    /// </summary>
    /// <param name="pFileName"> Name of the file where to record the sound. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int startMicrophonesRecording(const std::string& pFileName)
    {
      return fParent->pCall("startMicrophonesRecording" , pFileName);
    }

    /// <summary>
    /// returns true if the method is currently running
    /// </summary>
    /// <param name="id"> the ID of the method to wait for </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int stop(const int& id)
    {
      return fParent->pCall("stop" , id);
    }

    /// <summary>
    /// This method calls a procedure to stop and clear the audio output buffers.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int stopAudioOut()
    {
      return fParent->pCall("stopAudioOut");
    }

    /// <summary>
    /// This method stops the recording of the sound collected by the microphones.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int stopMicrophonesRecording()
    {
      return fParent->pCall("stopMicrophonesRecording");
    }

    /// <summary>
    /// This function allows a module to subscribe to the ALAudioDevice module.For more informations see the audio part of the red documentation
    /// </summary>
    /// <param name="pModule"> Name of the module </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int subscribe(const std::string& pModule)
    {
      return fParent->pCall("subscribe" , pModule);
    }



    /// <summary>
    /// This function allows a module to subscribe to the ALAudioDevice module.For more informations see the audio part of the red documentation
    /// </summary>
    /// <param name="pModule"> Name of the module </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int unsubscribe(const std::string& pModule)
    {
      return fParent->pCall("unsubscribe" , pModule);
    }



};

}
#endif // ALAUDIODEVICEPROXYPOSTHANDLERREMOTE_H_

