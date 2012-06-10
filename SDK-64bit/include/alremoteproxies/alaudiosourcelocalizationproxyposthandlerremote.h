// Generated for ALAudioSourceLocalization version 


#ifndef ALAUDIOSOURCELOCALIZATIONPROXYPOSTHANDLERREMOTE_H_
#define ALAUDIOSOURCELOCALIZATIONPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALAudioSourceLocalizationProxyRemote;

/// <summary>This module computes the position (azimuth, elevation) of a sound source detected by ALSoundDetection.
    ///
    ///  When a sound is detected and located, an event is created.
    ///
    ///  This module requires ALSoundDetection and ALMotion modules to run correctly.
    ///
    ///  One event is created when nao locates a sound source : ALAudioSourceLocalization/SoundLocated.
    ///
    ///  ALAudioSourceLocalization/SoundLocated : [ [time(sec), time(usec)], [azimuth, elevation, confidence, (optional: energy)] , [Head Position[6D]] ]</summary>
class ALAudioSourceLocalizationProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALAudioSourceLocalizationProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// This module computes the position (azimuth, elevation) of a sound source detected by ALSoundDetection.
    ///
    ///  When a sound is detected and located, an event is created.
    ///
    ///  This module requires ALSoundDetection and ALMotion modules to run correctly.
    ///
    ///  One event is created when nao locates a sound source : ALAudioSourceLocalization/SoundLocated.
    ///
    ///  ALAudioSourceLocalization/SoundLocated : [ [time(sec), time(usec)], [azimuth, elevation, confidence, (optional: energy)] , [Head Position[6D]] ]
    /// ALAudioSourceLocalizationPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALAudioSourceLocalizationProxyPostHandlerRemote() : fParent(NULL)
    {}



    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int exit()
    {
      return fParent->pCall("exit");
    }














    /// <summary>
    /// enable/disable the printing of some debug information
    /// </summary>
    /// <param name="nbOfChannels"> Provides the number of channels of the buffer. </param>
    /// <param name="nbOfSamplesByChannel"> Provides the number of samples by channel. </param>
    /// <param name="timestamp"> Provides the timestamp of the buffer. </param>
    /// <param name="buffer"> Provides the audio buffer as an ALValue. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int processRemote(const int& nbOfChannels, const int& nbOfSamplesByChannel, const AL::ALValue& timestamp, const AL::ALValue& buffer)
    {
      return fParent->pCall("processRemote" , nbOfChannels, nbOfSamplesByChannel, timestamp, buffer);
    }

    /// <summary>
    /// enable/disable the printing of some debug information
    /// </summary>
    /// <param name="nbOfChannels"> Provides the number of channels of the buffer. </param>
    /// <param name="nbOfSamplesByChannel"> Provides the number of samples by channel. </param>
    /// <param name="buffer"> Provides the audio buffer as an ALValue. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int processSoundRemote(const int& nbOfChannels, const int& nbOfSamplesByChannel, const AL::ALValue& buffer)
    {
      return fParent->pCall("processSoundRemote" , nbOfChannels, nbOfSamplesByChannel, buffer);
    }

    /// <summary>
    /// enable/disable the printing of some debug information
    /// </summary>
    /// <param name="bSetOrUnset"> enable the functionnality when true. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setDebugMode(const bool& bSetOrUnset)
    {
      return fParent->pCall("setDebugMode" , bSetOrUnset);
    }

    /// <summary>
    /// Set the specified parameter.
    /// </summary>
    /// <param name="parameter"> Name of the parameter. \"Sensibility\" between 0 and 1 to adjust the capacity of NAO to locate quiet sounds. \"EnergyComputation\" (1 or 0) that activates the computation of the located source signal energy. This energy is added in the \"ALAudioSourceLocalization/SoundLocated\" ALMemory key. </param>
    /// <param name="value"> \"Sensibility\" : a float in [0,1]. \"EnergyComputation\" : (1 or 0). </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setParameter(const std::string& parameter, const AL::ALValue& value)
    {
      return fParent->pCall("setParameter" , parameter, value);
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
    /// Subscribes to the extractor. This causes the extractor to start writing information to memory using the keys described by getOutputNames(). These can be accessed in memory using ALMemory.getData(\"keyName\"). In many cases you can avoid calling subscribe on the extractor by just calling ALMemory.subscribeToEvent() supplying a callback method. This will automatically subscribe to the extractor for you.
    /// </summary>
    /// <param name="name"> Name of the module which subscribes. </param>
    /// <param name="period"> Refresh period (in milliseconds) if relevant. </param>
    /// <param name="precision"> Precision of the extractor if relevant. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int subscribe(const std::string& name, const int& period, const float& precision)
    {
      return fParent->pCall("subscribe" , name, period, precision);
    }

    /// <summary>
    /// Subscribes to the extractor. This causes the extractor to start writing information to memory using the keys described by getOutputNames(). These can be accessed in memory using ALMemory.getData(\"keyName\"). In many cases you can avoid calling subscribe on the extractor by just calling ALMemory.subscribeToEvent() supplying a callback method. This will automatically subscribe to the extractor for you.
    /// </summary>
    /// <param name="name"> Name of the module which subscribes. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int subscribe(const std::string& name)
    {
      return fParent->pCall("subscribe" , name);
    }

    /// <summary>
    /// Unsubscribes from the extractor.
    /// </summary>
    /// <param name="name"> Name of the module which had subscribed. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int unsubscribe(const std::string& name)
    {
      return fParent->pCall("unsubscribe" , name);
    }

    /// <summary>
    /// Updates the period if relevant.
    /// </summary>
    /// <param name="name"> Name of the module which has subscribed. </param>
    /// <param name="period"> Refresh period (in milliseconds). </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int updatePeriod(const std::string& name, const int& period)
    {
      return fParent->pCall("updatePeriod" , name, period);
    }

    /// <summary>
    /// Updates the precision if relevant.
    /// </summary>
    /// <param name="name"> Name of the module which has subscribed. </param>
    /// <param name="precision"> Precision of the extractor. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int updatePrecision(const std::string& name, const float& precision)
    {
      return fParent->pCall("updatePrecision" , name, precision);
    }



};

}
#endif // ALAUDIOSOURCELOCALIZATIONPROXYPOSTHANDLERREMOTE_H_

