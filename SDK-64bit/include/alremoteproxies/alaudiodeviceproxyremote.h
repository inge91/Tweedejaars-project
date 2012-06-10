// Generated for ALAudioDevice version 1.12

#ifndef ALAUDIODEVICEPROXYREMOTE_H_
#define ALAUDIODEVICEPROXYREMOTE_H_
#include <alremoteproxies/alaudiodeviceproxyposthandlerremote.h>

namespace AL
{

/// <summary>The ALAudioDevice module allows other modules to access to the sound data of the nao's microphones, and to send sound toward its loudspeakers  The way to receive or send the audio data depends whether the modules are local (dynamic library) or remote (executable).</summary>
class ALAudioDeviceProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALAudioDeviceProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALAudioDevice", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALAudioDeviceProxyPostHandlerRemote post;


    /// <summary>
    /// Closes the audio device for capture. You can call this method if you want to have access to the alsa input buffers in another program than naoqi while naoqi is running (with arecord for example)
    /// </summary>
    void closeAudioInputs()
    {

        callVoidRemote("closeAudioInputs");
    }


    /// <summary>
    /// Closes the audio device for playback. close the audio device for capture. You can call this method if you want to send sound to alsa in another program than naoqi while naoqi is running (with aplay for example)
    /// </summary>
    void closeAudioOutputs()
    {

        callVoidRemote("closeAudioOutputs");
    }


    /// <summary>
    /// Disables the computation of the energy of each microphone signal
    /// </summary>
    void disableEnergyComputation()
    {

        callVoidRemote("disableEnergyComputation");
    }


    /// <summary>
    /// Enables the computation of the energy of each microphone signal
    /// </summary>
    void enableEnergyComputation()
    {

        callVoidRemote("enableEnergyComputation");
    }


    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit()
    {

        callVoidRemote("exit");
    }


    /// <summary>
    /// Flush the audio device for playback. close the audio device for capture. You can call this method if you want to send sound to alsa in another program than naoqi while naoqi is running (with aplay for example)
    /// </summary>
    void flushAudioOutputs()
    {

        callVoidRemote("flushAudioOutputs");
    }


    /// <summary>
    /// Gets the name of the parent broker.
    /// </summary>
    /// <returns> The name of the parent broker. </returns>
    std::string getBrokerName()
    {

        return callRemote<std::string >("getBrokerName");
    }


    /// <summary>
    /// Returns the energy of the front microphone signal
    /// </summary>
    /// <returns> energy of the front microphone signal </returns>
    float getFrontMicEnergy()
    {

        return callRemote<float >("getFrontMicEnergy");
    }


    /// <summary>
    /// Returns the energy of the left microphone signal
    /// </summary>
    /// <returns> energy of the left microphone signal </returns>
    float getLeftMicEnergy()
    {

        return callRemote<float >("getLeftMicEnergy");
    }


    /// <summary>
    /// Retrieves a method's description.
    /// </summary>
    /// <param name="methodName"> The name of the method. </param>
    /// <returns> A structure containing the method's description. </returns>
    AL::ALValue getMethodHelp(const std::string& methodName)
    {

        return callRemote<AL::ALValue >("getMethodHelp" , methodName);
    }


    /// <summary>
    /// Retrieves the module's method list.
    /// </summary>
    /// <returns> An array of method names. </returns>
    std::vector<std::string> getMethodList()
    {

        return callRemote<std::vector<std::string> >("getMethodList");
    }


    /// <summary>
    /// Retrieves the module's description.
    /// </summary>
    /// <returns> A structure describing the module. </returns>
    AL::ALValue getModuleHelp()
    {

        return callRemote<AL::ALValue >("getModuleHelp");
    }


    /// <summary>
    /// Gets the output sound level of the system.
    /// </summary>
    /// <returns> outputVolume of the system </returns>
    int getOutputVolume()
    {

        return callRemote<int >("getOutputVolume");
    }


    /// <summary>
    /// This method returns the specified internal parameter ('outputSampleRate' or 'inputBufferSize'). The value -1 is returned if the specified parameter is not valid.
    /// </summary>
    /// <param name="pParamName"> Name of the parameter to get ('outputSampleRate' or 'inputBufferSize'). </param>
    /// <returns> value of the specified parameter </returns>
    int getParameter(const std::string& pParamName)
    {

        return callRemote<int >("getParameter" , pParamName);
    }


    /// <summary>
    /// Returns the energy of the rear microphone signal
    /// </summary>
    /// <returns> energy of the rear microphone signal </returns>
    float getRearMicEnergy()
    {

        return callRemote<float >("getRearMicEnergy");
    }


    /// <summary>
    /// Returns the energy of the right microphone signal
    /// </summary>
    /// <returns> energy of the right microphone signal </returns>
    float getRightMicEnergy()
    {

        return callRemote<float >("getRightMicEnergy");
    }


    /// <summary>
    /// Gets the method usage string. This summarise how to use the method.
    /// </summary>
    /// <param name="name"> The name of the method. </param>
    /// <returns> A string that summarises the usage of the method. </returns>
    std::string getUsage(const std::string& name)
    {

        return callRemote<std::string >("getUsage" , name);
    }


    /// <summary>
    /// check if loudspeakers are muted
    /// </summary>
    /// <returns> 1 if true / 0 otherwise </returns>
    bool isAudioOutMuted()
    {

        return callRemote<bool >("isAudioOutMuted");
    }


    /// <summary>
    /// Allows to know if audio inputs are closed or not
    /// </summary>
    /// <returns> True if audio inputs are closed / False otherwise </returns>
    bool isInputClosed()
    {

        return callRemote<bool >("isInputClosed");
    }


    /// <summary>
    /// Allows to know if audio ouputs are closed or not
    /// </summary>
    /// <returns> True if audio outputs are closed / False otherwise </returns>
    bool isOutputClosed()
    {

        return callRemote<bool >("isOutputClosed");
    }


    /// <summary>
    /// Returns true if the method is currently running.
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <returns> True if the method is currently running </returns>
    bool isRunning(const int& id)
    {

        return callRemote<bool >("isRunning" , id);
    }


    /// <summary>
    /// mute the loudspeakers
    /// </summary>
    /// <param name="arg1"> arg </param>
    void muteAudioOut(const bool& arg1)
    {

        callVoidRemote("muteAudioOut" , arg1);
    }


    /// <summary>
    /// Opens the audio device for capture. If you closed the audio inputs with the closeAudioInputs method, you must call this method to be able to access to the sound data of the nao's microphones.
    /// </summary>
    void openAudioInputs()
    {

        callVoidRemote("openAudioInputs");
    }


    /// <summary>
    /// Opens the audio device for playback. If you closed the audio outputs with the closeAudioOutputs method, you must call this method to ear or send sound onto the nao's loudspeakers.
    /// </summary>
    void openAudioOutputs()
    {

        callVoidRemote("openAudioOutputs");
    }


    /// <summary>
    /// Just a ping. Always returns true
    /// </summary>
    /// <returns> returns true </returns>
    bool ping()
    {

        return callRemote<bool >("ping");
    }


    /// <summary>
    /// Play a sine wave which specified caracteristics.
    /// </summary>
    /// <param name="frequence"> Frequence in Hertz </param>
    /// <param name="gain"> Volume Gain between 0 and 100 </param>
    /// <param name="pan"> Stereo Pan set to either {-1,0,+1} </param>
    /// <param name="duration"> Duration of the sine wave in seconds </param>
    void playSine(const int& frequence, const int& gain, const int& pan, const float& duration)
    {

        callVoidRemote("playSine" , frequence, gain, pan, duration);
    }


    /// <summary>
    /// reset ALSA driver. Use this method only when no audio module is subscribed to ALAudioDevice
    /// </summary>
    void resetAudio()
    {

        callVoidRemote("resetAudio");
    }


    /// <summary>
    /// This function allows a local module to send sound onto the nao's loudpseakers
    ///
    /// You must pass to this function a pointer to the stereo buffer to send, and the number of frames per channel. The buffer must contain 16bits stereo interleaved samples, and the number of frames does not exceed 16384
    /// </summary>
    /// <param name="nbOfFrames"> Number of 16 bits samples per channel to send. </param>
    /// <param name="pBuffer"> Buffer to send </param>
    /// <returns> True if the operation is successfull - False otherwise </returns>
    bool sendLocalBufferToOutput(const int& nbOfFrames, const int& pBuffer)
    {

        return callRemote<bool >("sendLocalBufferToOutput" , nbOfFrames, pBuffer);
    }


    /// <summary>
    /// This function allows a remote module to send sound onto the nao's loudpseakers
    ///
    /// You must pass to this function the stereo buffer you want to send as an ALValue converted to binary, and the number of frames per channel. The number of frames does not exceed 16384. For more information please see the red documentation
    /// </summary>
    /// <param name="nbOfFrames"> Number of 16 bits samples per channel to send. </param>
    /// <param name="pBuffer"> Buffer to send </param>
    /// <returns> True if the operation is successfull - False otherwise </returns>
    bool sendRemoteBufferToOutput(const int& nbOfFrames, const AL::ALValue& pBuffer)
    {

        return callRemote<bool >("sendRemoteBufferToOutput" , nbOfFrames, pBuffer);
    }


    /// <summary>
    /// Set AudioDevice Client preferences
    /// </summary>
    /// <param name="name"> name of the client </param>
    /// <param name="sampleRate"> sample rate of the microphones data sent to the process function - must be 16000 or 48000 </param>
    /// <param name="channelsConfiguration"> An int (defined in ALSoundExtractor) indicating which microphones data will be send to the process function. ALLCHANNELS, LEFTCHANNEL, RIGHTCHANNEL, FRONTCHANNEL, REARCHANNEL are the configuration currently supported. </param>
    /// <param name="deinterleaved"> indicates if the microphones data sent to the process function are interleaved or not - 0 : interleaved - 1 : deinterleaved </param>
    void setClientPreferences(const std::string& name, const int& sampleRate, const int& channelsConfiguration, const int& deinterleaved)
    {

        callVoidRemote("setClientPreferences" , name, sampleRate, channelsConfiguration, deinterleaved);
    }


    /// <summary>
    /// Set AudioDevice Client preferences. This function is deprecated, the use of the alternate 4 arguments setClientPreferences() is now prefered.
    /// </summary>
    /// <param name="name"> name of the client </param>
    /// <param name="sampleRate"> sample rate of the microphones data sent to the processSound or processSoundRemote functions - must be 16000 or 48000 </param>
    /// <param name="channelsVector"> ALValue containing a vector of int indicating which microphones data will be send to the processSound or processSoundRemote functions </param>
    /// <param name="deinterleaved"> indicates if the microphones data sent to the processSound or processSoundRemote functions are interleaved or not - 0 : interleaved - 1 : deinterleaved </param>
    /// <param name="timeStamp"> parameter indicating if audio timestamps are sent to the processSound or processSoundRemote functions - 0 : no - 1 : yes </param>
    void setClientPreferences(const std::string& name, const int& sampleRate, const AL::ALValue& channelsVector, const int& deinterleaved, const int& timeStamp)
    {

        callVoidRemote("setClientPreferences" , name, sampleRate, channelsVector, deinterleaved, timeStamp);
    }


    /// <summary>
    /// This method allows to send sound samples contained in a sound file at the input of ALAudioDevice, instead of the nao's microphones sound data. The sound file must be a .wav file containing 16bits / 4 channels / interleaved samples. Once the file has been read, microphones sound data will again taken as input
    /// </summary>
    /// <param name="pFileName"> Name of the input file. </param>
    void setFileAsInput(const std::string& pFileName)
    {

        callVoidRemote("setFileAsInput" , pFileName);
    }


    /// <summary>
    /// Sets the output sound level of the system.
    /// </summary>
    /// <param name="volume"> Volume [0-100]. </param>
    void setOutputVolume(const int& volume)
    {

        callVoidRemote("setOutputVolume" , volume);
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
    void setParameter(const std::string& pParamName, const int& pParamValue)
    {

        callVoidRemote("setParameter" , pParamName, pParamValue);
    }


    /// <summary>
    /// This method allows to record the signal collected on the nao's microphones. You can choose to record only the front microphone in a ogg file, or the 4 microphones in a wav file. In this last case the format of the file is 4 channels, 16 bits little endian, 48 KHz
    /// </summary>
    /// <param name="pFileName"> Name of the file where to record the sound. </param>
    void startMicrophonesRecording(const std::string& pFileName)
    {

        callVoidRemote("startMicrophonesRecording" , pFileName);
    }


    /// <summary>
    /// returns true if the method is currently running
    /// </summary>
    /// <param name="id"> the ID of the method to wait for </param>
    void stop(const int& id)
    {

        callVoidRemote("stop" , id);
    }


    /// <summary>
    /// This method calls a procedure to stop and clear the audio output buffers.
    /// </summary>
    void stopAudioOut()
    {

        callVoidRemote("stopAudioOut");
    }


    /// <summary>
    /// This method stops the recording of the sound collected by the microphones.
    /// </summary>
    void stopMicrophonesRecording()
    {

        callVoidRemote("stopMicrophonesRecording");
    }


    /// <summary>
    /// This function allows a module to subscribe to the ALAudioDevice module.For more informations see the audio part of the red documentation
    /// </summary>
    /// <param name="pModule"> Name of the module </param>
    void subscribe(const std::string& pModule)
    {

        callVoidRemote("subscribe" , pModule);
    }


    /// <summary>
    /// This function allows a remote module to subscribe to the ALAudioDevice module.
    ///
    /// Once your remote module is subscribed, the function 'processSoundRemote' of your module (you need to declare one) will be automatically and regularly called with raw data from microphones as inputs.
    ///
    /// This function must be declared as follow : processSoundRemote( const int &#38; pNbOfInputChannels, const int &#38; pNbrSamples, const ALValue &#38; pDataInterleaved).
    ///
    /// When she will be called, the received pDataInterleaved buffer will contain pNbrSamples 16 bits interleaved samples, ordered as follows : s1m1,s1m2,s1m3,s1m4,s2m1,s2m2, ... where simj is the sample number i of microphone j.
    ///
    /// The indices of microphones are the followings : 1 : left microphone / 2 : right microphone / 3 : front microphone / 4 : rear microphone.
    ///
    /// For more informations see the audio part of the red documentation
    /// </summary>
    /// <param name="pModule"> Name of the remote module </param>
    /// <returns> True if module has subscribed successfully - False otherwise </returns>
    bool subscribeRemoteModule(const std::string& pModule)
    {

        return callRemote<bool >("subscribeRemoteModule" , pModule);
    }


    /// <summary>
    /// This function unsubscribes a remote module (identified by its name) from the ALAudioDevice module
    /// </summary>
    /// <param name="pModule"> Name of the remote module to unsuscribe from ALAudioDevice </param>
    /// <returns> True if module has been unsubscribed successfully - False otherwise </returns>
    bool unSubscribeRemoteModule(const std::string& pModule)
    {

        return callRemote<bool >("unSubscribeRemoteModule" , pModule);
    }


    /// <summary>
    /// This function allows a module to subscribe to the ALAudioDevice module.For more informations see the audio part of the red documentation
    /// </summary>
    /// <param name="pModule"> Name of the module </param>
    void unsubscribe(const std::string& pModule)
    {

        callVoidRemote("unsubscribe" , pModule);
    }


    /// <summary>
    /// Returns the version of the module.
    /// </summary>
    /// <returns> A string containing the version of the module. </returns>
    std::string version()
    {

        return callRemote<std::string >("version");
    }


    /// <summary>
    /// Wait for the end of a long running method that was called using 'post'
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <param name="timeoutPeriod"> The timeout period in ms. To wait indefinately, use a timeoutPeriod of zero. </param>
    /// <returns> True if the timeout period terminated. False if the method returned. </returns>
    bool wait(const int& id, const int& timeoutPeriod)
    {

        return callRemote<bool >("wait" , id, timeoutPeriod);
    }


};

}
#endif // ALAUDIODEVICEPROXY_H_
