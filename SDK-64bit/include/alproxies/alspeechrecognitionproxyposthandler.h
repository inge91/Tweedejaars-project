// Generated for ALSpeechRecognition version 

#ifndef ALSPEECHRECOGNITIONPROXYPOSTHANDLER_H_
#define ALSPEECHRECOGNITIONPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALSpeechRecognitionProxy;

/// <summary>
/// ALSpeechRecognition gives access to the                        embedded voice recognition system. It can be                       dynamically modified. This class allows user                       to load the current words list that should be recognized.                       The result of the recognition engine is located in the ALMemory's key: \"WordRecognized\"                       The structure of the result is an array :  [ (string) word , (float) confidence ]
/// ALSpeechRecognitionPostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALSpeechRecognitionProxyPostHandler
{
  friend class ALSpeechRecognitionProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// ALSpeechRecognition gives access to the                        embedded voice recognition system. It can be                       dynamically modified. This class allows user                       to load the current words list that should be recognized.                       The result of the recognition engine is located in the ALMemory's key: \"WordRecognized\"                       The structure of the result is an array :  [ (string) word , (float) confidence ]
  /// ALSpeechRecognitionPostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALSpeechRecognitionProxyPostHandler();

  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// Loads the vocabulary to recognized contained in a .lxd file. This method is not available with the ASR engine language set to Chinese. For more informations see the red documentation
  /// </summary>
  /// <param name="vocabularyFile"> Name of the lxd file containing the vocabulary </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int loadVocabulary(const std::string& vocabularyFile);
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
  /// Enables or disables the playing of sounds indicating the state of the recognition engine. 
    ///
    /// If this option is enabled, a sound is played at the beginning of the recognition process (after a call to the subscribe method), and a sound is played when the user call the unsubscribe method
  /// </summary>
  /// <param name="setOrNot"> Enable (true) or disable it (false). </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setAudioExpression(const bool& setOrNot);
  /// <summary>
  /// enable/disable the printing of some debug information
  /// </summary>
  /// <param name="bSetOrUnset"> enable the functionnality when true. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setDebugMode(const bool& bSetOrUnset);
  /// <summary>
  /// Sets the language used by the speech recognition engine.               The list of the available languages can be collected through the getAvailableLanguages method.               If you want to set a language as the default language (loading automatically at module launch), please refer to the web page of the robot.
  /// </summary>
  /// <param name="languageName"> Name of the language in English. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setLanguage(const std::string& languageName);
  /// <summary>
  /// Sets a parameter of the speech recognition engine. Note that when the ASR engine language is set to Chinese, no parameter can be set.               The parameters that can be set and the corresponding values are:               \"EarUseSpeechDetector\" - Values : 0 (No), 1 (Regular), or 2 (Cepstral) : type of speech detector used by the ASR engine - default value is 2.                \"EarSpeed\" - Values : 0 to 3 - 0 is slowest and most accurate. 3 is the fastest but may add some recognition errors, especially if you talk fast because some parts of the audio data is not processed. - default value is 2.                \"EarUseFilter\" : Values : 0 (no) or 1 (yes) - Applies a High-Pass filter on the input signal - default value is 0.
  /// </summary>
  /// <param name="paramName"> Name of the parameter. </param>
  /// <param name="paramValue"> Value of the parameter. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setParameter(const std::string& paramName, const float& paramValue);
  /// <summary>
  /// Enables or disables the leds animations showing the state of the recognition engine during the recognition process.
  /// </summary>
  /// <param name="setOrNot"> Enable (true) or disable it (false). </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setVisualExpression(const bool& setOrNot);
  /// <summary>
  /// Sets the list of words (vocabulary) that should be recognized by the speech recognition engine.
  /// </summary>
  /// <param name="vocabulary"> List of words that should be recognized </param>
  /// <param name="enabledWordSpotting"> If disabled, the engine expects to hear one of the specified words, nothing more, nothing less. If enabled, the specified words can be pronounced in the middle of a whole speech stream, the engine will try to spot them. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setVocabulary(const std::vector<std::string>& vocabulary, const bool& enabledWordSpotting);
  /// <summary>
  /// Sets the list of words (vocabulary) that should be recognized by the speech recognition engine.
  /// </summary>
  /// <param name="vocabulary"> List of words that should be recognized </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setWordListAsVocabulary(const std::vector<std::string>& vocabulary);
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
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
#endif // ALSPEECHRECOGNITIONPROXYPOSTHANDLER_H_

