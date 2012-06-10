// Generated for ALSoundDetection version 


#ifndef ALSOUNDDETECTIONPROXYPOSTHANDLERREMOTE_H_
#define ALSOUNDDETECTIONPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALSoundDetectionProxyRemote;

/// <summary>This module detects in incoming audio buffers every sound with a significative level.</summary>
class ALSoundDetectionProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALSoundDetectionProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// This module detects in incoming audio buffers every sound with a significative level.
    /// ALSoundDetectionPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALSoundDetectionProxyPostHandlerRemote() : fParent(NULL)
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
    /// Set detection parameters
    /// </summary>
    /// <param name="paraDetect"> Name of the parameter. Please refer to the example below for the available parameters. </param>
    /// <param name="param"> Value of the parameter. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setParameter(const std::string& paraDetect, const float& param)
    {
      return fParent->pCall("setParameter" , paraDetect, param);
    }

    /// <summary>
    /// DEPRECATED - Set detection parameters
    /// </summary>
    /// <param name="type"> Name of detector. For now only one detector is available : \"soundDetection/SoundDetector\". </param>
    /// <param name="paraDetect"> Name of the parameter. Please refer to the example below for the available parameters. </param>
    /// <param name="param"> Value of the parameter. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setParameter(const std::string& type, const std::string& paraDetect, const float& param)
    {
      return fParent->pCall("setParameter" , type, paraDetect, param);
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
#endif // ALSOUNDDETECTIONPROXYPOSTHANDLERREMOTE_H_

