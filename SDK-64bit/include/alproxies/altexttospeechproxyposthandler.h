// Generated for ALTextToSpeech version 1.12

#ifndef ALTEXTTOSPEECHPROXYPOSTHANDLER_H_
#define ALTEXTTOSPEECHPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALTextToSpeechProxy;

/// <summary>
/// This module embeds a speech synthetizer whose role is to convert text commands into sound waves that are then either sent to Nao's loudspeakers or written into a file. This service supports several languages and some parameters of the synthetizer can be tuned to change each language's synthetic voice.
/// ALTextToSpeechPostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALTextToSpeechProxyPostHandler
{
  friend class ALTextToSpeechProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// This module embeds a speech synthetizer whose role is to convert text commands into sound waves that are then either sent to Nao's loudspeakers or written into a file. This service supports several languages and some parameters of the synthetizer can be tuned to change each language's synthetic voice.
  /// ALTextToSpeechPostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALTextToSpeechProxyPostHandler();

  /// <summary>
  /// Disables the notifications puted in ALMemory during the synthesis (TextStarted, TextDone, CurrentBookMark, CurrentWord, ...)
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int disableNotifications();
  /// <summary>
  /// Enables the notifications puted in ALMemory during the synthesis (TextStarted, TextDone, CurrentBookMark, CurrentWord, ...)
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int enableNotifications();
  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// Loads a set of voice parameters defined in a xml file contained in the preferences folder.The name of the xml file must begin with ALTextToSpeech_Voice_
  /// </summary>
  /// <param name="pPreferenceName"> Name of the voice preference. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int loadVoicePreference(const std::string& pPreferenceName);
  /// <summary>
  /// Performs the text-to-speech operations : it takes a std::string as input and outputs a sound in both speakers. It logs an error if the std::string is empty. String encoding must be UTF8.
  /// </summary>
  /// <param name="stringToSay"> Text to say, encoded in UTF-8. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int say(const std::string& stringToSay);
  /// <summary>
  /// Performs the text-to-speech operations: it takes a std::string as input and outputs the corresponding audio signal in the specified file.
  /// </summary>
  /// <param name="pStringToSay"> Text to say, encoded in UTF-8. </param>
  /// <param name="pFileName"> RAW file where to store the generated signal. The signal is encoded with a sample rate of 22050Hz, format S16_LE, 2 channels. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int sayToFile(const std::string& pStringToSay, const std::string& pFileName);
  /// <summary>
  /// This method performs the text-to-speech operations: it takes a std::string, outputs the synthesis resulting audio signal in a file, and then plays the audio file. The file is deleted afterwards. It is useful when you want to perform a short synthesis, when few CPU is available. Do not use it if you want a low-latency synthesis or to synthesize a long std::string.
  /// </summary>
  /// <param name="pStringToSay"> Text to say, encoded in UTF-8. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int sayToFileAndPlay(const std::string& pStringToSay);
  /// <summary>
  /// Changes the language used by the Text-to-Speech engine. It automatically changes the voice used since each of them is related to a unique language. If you want that change to take effect automatically after reboot of your robot, refer to the robot web page (setting page).
  /// </summary>
  /// <param name="pLanguage"> Language name. Must belong to the languages available in TTS (can be obtained with the getAvailableLanguages method).  It should be an identifier std::string. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setLanguage(const std::string& pLanguage);
  /// <summary>
  /// Changes the parameters of the voice. The available parameters are: 
    ///
    ///  	 pitchShift: applies a pitch shifting to the voice. The value indicates the ratio between the new fundamental frequencies and the old ones (examples: 2.0: an octave above, 1.5: a quint above). Correct range is (1.0 -- 4), or 0 to disable effect.
    ///
    ///  	 doubleVoice: adds a second voice to the first one. The value indicates the ratio between the second voice fundamental frequency and the first one. Correct range is (1.0 -- 4), or 0 to disable effect 
    ///
    ///  	 doubleVoiceLevel: the corresponding value is the level of the double voice (1.0: equal to the main voice one). Correct range is (0 -- 4). 
    ///
    ///  	 doubleVoiceTimeShift: the corresponding value is the delay between the double voice and the main one. Correct range is (0 -- 0.5) 
    ///
    ///  If the effect value is not available, the effect parameter remains unchanged.
  /// </summary>
  /// <param name="pEffectName"> Name of the parameter. </param>
  /// <param name="pEffectValue"> Value of the parameter. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setParameter(const std::string& pEffectName, const float& pEffectValue);
  /// <summary>
  /// Changes the voice used by the text-to-speech engine. The voice identifier must belong to the installed voices, that can be listed using the 'getAvailableVoices' method. If the voice is not available, it remains unchanged. No exception is thrown in this case.
  /// </summary>
  /// <param name="pVoiceID"> The voice (as a std::string). </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setVoice(const std::string& pVoiceID);
  /// <summary>
  /// Sets the volume of text-to-speech output.
  /// </summary>
  /// <param name="volume"> Volume (between 0.0 and 1.0). </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setVolume(const float& volume);
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
  /// <summary>
  /// This method stops the current and all the pending tasks immediately.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stopAll();
};

}
#endif // ALTEXTTOSPEECHPROXYPOSTHANDLER_H_

