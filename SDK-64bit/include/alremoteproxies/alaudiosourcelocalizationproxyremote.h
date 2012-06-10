// Generated for ALAudioSourceLocalization version 

#ifndef ALAUDIOSOURCELOCALIZATIONPROXYREMOTE_H_
#define ALAUDIOSOURCELOCALIZATIONPROXYREMOTE_H_
#include <alremoteproxies/alaudiosourcelocalizationproxyposthandlerremote.h>

namespace AL
{

/// <summary>This module computes the position (azimuth, elevation) of a sound source detected by ALSoundDetection.
    ///
    ///  When a sound is detected and located, an event is created.
    ///
    ///  This module requires ALSoundDetection and ALMotion modules to run correctly.
    ///
    ///  One event is created when nao locates a sound source : ALAudioSourceLocalization/SoundLocated.
    ///
    ///  ALAudioSourceLocalization/SoundLocated : [ [time(sec), time(usec)], [azimuth, elevation, confidence, (optional: energy)] , [Head Position[6D]] ]</summary>
class ALAudioSourceLocalizationProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALAudioSourceLocalizationProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALAudioSourceLocalization", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALAudioSourceLocalizationProxyPostHandlerRemote post;


    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit()
    {

        callVoidRemote("exit");
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
    /// Gets the current period.
    /// </summary>
    /// <returns> Refresh period (in milliseconds). </returns>
    int getCurrentPeriod()
    {

        return callRemote<int >("getCurrentPeriod");
    }


    /// <summary>
    /// Gets the current precision.
    /// </summary>
    /// <returns> Precision of the extractor. </returns>
    float getCurrentPrecision()
    {

        return callRemote<float >("getCurrentPrecision");
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
    /// Gets the period for a specific subscription.
    /// </summary>
    /// <param name="name"> Name of the module which has subscribed. </param>
    /// <returns> Refresh period (in milliseconds). </returns>
    int getMyPeriod(const std::string& name)
    {

        return callRemote<int >("getMyPeriod" , name);
    }


    /// <summary>
    /// Gets the precision for a specific subscription.
    /// </summary>
    /// <param name="name"> name of the module which has subscribed </param>
    /// <returns> precision of the extractor </returns>
    float getMyPrecision(const std::string& name)
    {

        return callRemote<float >("getMyPrecision" , name);
    }


    /// <summary>
    /// Get the list of values updated in ALMemory.
    /// </summary>
    /// <returns> Array of values updated by this extractor in ALMemory </returns>
    std::vector<std::string> getOutputNames()
    {

        return callRemote<std::vector<std::string> >("getOutputNames");
    }


    /// <summary>
    /// Gets the parameters given by the module.
    /// </summary>
    /// <returns> Array of names and parameters of all subscribers. </returns>
    AL::ALValue getSubscribersInfo()
    {

        return callRemote<AL::ALValue >("getSubscribersInfo");
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
    /// Returns true if the method is currently running.
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <returns> True if the method is currently running </returns>
    bool isRunning(const int& id)
    {

        return callRemote<bool >("isRunning" , id);
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
    /// enable/disable the printing of some debug information
    /// </summary>
    /// <param name="nbOfChannels"> Provides the number of channels of the buffer. </param>
    /// <param name="nbOfSamplesByChannel"> Provides the number of samples by channel. </param>
    /// <param name="timestamp"> Provides the timestamp of the buffer. </param>
    /// <param name="buffer"> Provides the audio buffer as an ALValue. </param>
    void processRemote(const int& nbOfChannels, const int& nbOfSamplesByChannel, const AL::ALValue& timestamp, const AL::ALValue& buffer)
    {

        callVoidRemote("processRemote" , nbOfChannels, nbOfSamplesByChannel, timestamp, buffer);
    }


    /// <summary>
    /// enable/disable the printing of some debug information
    /// </summary>
    /// <param name="nbOfChannels"> Provides the number of channels of the buffer. </param>
    /// <param name="nbOfSamplesByChannel"> Provides the number of samples by channel. </param>
    /// <param name="buffer"> Provides the audio buffer as an ALValue. </param>
    void processSoundRemote(const int& nbOfChannels, const int& nbOfSamplesByChannel, const AL::ALValue& buffer)
    {

        callVoidRemote("processSoundRemote" , nbOfChannels, nbOfSamplesByChannel, buffer);
    }


    /// <summary>
    /// enable/disable the printing of some debug information
    /// </summary>
    /// <param name="bSetOrUnset"> enable the functionnality when true. </param>
    void setDebugMode(const bool& bSetOrUnset)
    {

        callVoidRemote("setDebugMode" , bSetOrUnset);
    }


    /// <summary>
    /// Set the specified parameter.
    /// </summary>
    /// <param name="parameter"> Name of the parameter. \"Sensibility\" between 0 and 1 to adjust the capacity of NAO to locate quiet sounds. \"EnergyComputation\" (1 or 0) that activates the computation of the located source signal energy. This energy is added in the \"ALAudioSourceLocalization/SoundLocated\" ALMemory key. </param>
    /// <param name="value"> \"Sensibility\" : a float in [0,1]. \"EnergyComputation\" : (1 or 0). </param>
    void setParameter(const std::string& parameter, const AL::ALValue& value)
    {

        callVoidRemote("setParameter" , parameter, value);
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
    /// Subscribes to the extractor. This causes the extractor to start writing information to memory using the keys described by getOutputNames(). These can be accessed in memory using ALMemory.getData(\"keyName\"). In many cases you can avoid calling subscribe on the extractor by just calling ALMemory.subscribeToEvent() supplying a callback method. This will automatically subscribe to the extractor for you.
    /// </summary>
    /// <param name="name"> Name of the module which subscribes. </param>
    /// <param name="period"> Refresh period (in milliseconds) if relevant. </param>
    /// <param name="precision"> Precision of the extractor if relevant. </param>
    void subscribe(const std::string& name, const int& period, const float& precision)
    {

        callVoidRemote("subscribe" , name, period, precision);
    }


    /// <summary>
    /// Subscribes to the extractor. This causes the extractor to start writing information to memory using the keys described by getOutputNames(). These can be accessed in memory using ALMemory.getData(\"keyName\"). In many cases you can avoid calling subscribe on the extractor by just calling ALMemory.subscribeToEvent() supplying a callback method. This will automatically subscribe to the extractor for you.
    /// </summary>
    /// <param name="name"> Name of the module which subscribes. </param>
    void subscribe(const std::string& name)
    {

        callVoidRemote("subscribe" , name);
    }


    /// <summary>
    /// Unsubscribes from the extractor.
    /// </summary>
    /// <param name="name"> Name of the module which had subscribed. </param>
    void unsubscribe(const std::string& name)
    {

        callVoidRemote("unsubscribe" , name);
    }


    /// <summary>
    /// Updates the period if relevant.
    /// </summary>
    /// <param name="name"> Name of the module which has subscribed. </param>
    /// <param name="period"> Refresh period (in milliseconds). </param>
    void updatePeriod(const std::string& name, const int& period)
    {

        callVoidRemote("updatePeriod" , name, period);
    }


    /// <summary>
    /// Updates the precision if relevant.
    /// </summary>
    /// <param name="name"> Name of the module which has subscribed. </param>
    /// <param name="precision"> Precision of the extractor. </param>
    void updatePrecision(const std::string& name, const float& precision)
    {

        callVoidRemote("updatePrecision" , name, precision);
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
#endif // ALAUDIOSOURCELOCALIZATIONPROXY_H_
