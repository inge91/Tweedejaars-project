// Generated for ALAudioRecorder version 

#ifndef ALAUDIORECORDERPROXYPOSTHANDLER_H_
#define ALAUDIORECORDERPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALAudioRecorderProxy;

/// <summary>
/// This module records NAO's microphones signals into sound files.
/// ALAudioRecorderPostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALAudioRecorderProxyPostHandler
{
  friend class ALAudioRecorderProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// This module records NAO's microphones signals into sound files.
  /// ALAudioRecorderPostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALAudioRecorderProxyPostHandler();

  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// enable/disable the printing of some debug information
  /// </summary>
  /// <param name="nbOfChannels"> Provides the number of channels of the buffer. </param>
  /// <param name="nbOfSamplesByChannel"> Provides the number of samples by channel. </param>
  /// <param name="timestamp"> Provides the timestamp of the buffer. </param>
  /// <param name="buffer"> Provides the audio buffer as an ALValue. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int processRemote(const int& nbOfChannels, const int& nbOfSamplesByChannel, const AL::ALValue& timestamp, const AL::ALValue& buffer);
  /// <summary>
  /// enable/disable the printing of some debug information
  /// </summary>
  /// <param name="nbOfChannels"> Provides the number of channels of the buffer. </param>
  /// <param name="nbOfSamplesByChannel"> Provides the number of samples by channel. </param>
  /// <param name="buffer"> Provides the audio buffer as an ALValue. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int processSoundRemote(const int& nbOfChannels, const int& nbOfSamplesByChannel, const AL::ALValue& buffer);
  /// <summary>
  /// enable/disable the printing of some debug information
  /// </summary>
  /// <param name="bSetOrUnset"> enable the functionnality when true. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setDebugMode(const bool& bSetOrUnset);
  /// <summary>
  /// This method allows to record the signal collected on the nao's microphones. You can choose to record only the front microphone in a ogg file, or the 4 microphones in a wav file.
  /// </summary>
  /// <param name="filename"> Name of the file where to record the sound. </param>
  /// <param name="type"> wav or ogg. </param>
  /// <param name="samplerate"> Required sample rate. </param>
  /// <param name="channels"> vector of booleans. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int startMicrophonesRecording(const std::string& filename, const std::string& type, const int& samplerate, const AL::ALValue& channels);
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
  /// <summary>
  /// This method stops the recording of the sound collected by the microphones.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stopMicrophonesRecording();
  /// <summary>
  /// Subscribes to the extractor. This causes the extractor to start writing information to memory using the keys described by getOutputNames(). These can be accessed in memory using ALMemory.getData(\"keyName\"). In many cases you can avoid calling subscribe on the extractor by just calling ALMemory.subscribeToEvent() supplying a callback method. This will automatically subscribe to the extractor for you.
  /// </summary>
  /// <param name="name"> Name of the module which subscribes. </param>
  /// <param name="period"> Refresh period (in milliseconds) if relevant. </param>
  /// <param name="precision"> Precision of the extractor if relevant. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int subscribe(const std::string& name, const int& period, const float& precision);
  /// <summary>
  /// Subscribes to the extractor. This causes the extractor to start writing information to memory using the keys described by getOutputNames(). These can be accessed in memory using ALMemory.getData(\"keyName\"). In many cases you can avoid calling subscribe on the extractor by just calling ALMemory.subscribeToEvent() supplying a callback method. This will automatically subscribe to the extractor for you.
  /// </summary>
  /// <param name="name"> Name of the module which subscribes. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int subscribe(const std::string& name);
  /// <summary>
  /// Unsubscribes from the extractor.
  /// </summary>
  /// <param name="name"> Name of the module which had subscribed. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int unsubscribe(const std::string& name);
  /// <summary>
  /// Updates the period if relevant.
  /// </summary>
  /// <param name="name"> Name of the module which has subscribed. </param>
  /// <param name="period"> Refresh period (in milliseconds). </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int updatePeriod(const std::string& name, const int& period);
  /// <summary>
  /// Updates the precision if relevant.
  /// </summary>
  /// <param name="name"> Name of the module which has subscribed. </param>
  /// <param name="precision"> Precision of the extractor. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int updatePrecision(const std::string& name, const float& precision);
};

}
#endif // ALAUDIORECORDERPROXYPOSTHANDLER_H_

