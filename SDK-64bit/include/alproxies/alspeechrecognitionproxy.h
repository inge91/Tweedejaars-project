// Generated for ALSpeechRecognition version 

#ifndef ALSPEECHRECOGNITIONPROXY_H_
#define ALSPEECHRECOGNITIONPROXY_H_
#include <alproxies/alspeechrecognitionproxyposthandler.h>

namespace AL
{
class ALBroker;
class ALProxy;

class ALSpeechRecognitionProxyImpl;

/// <summary>ALSpeechRecognition gives access to the                        embedded voice recognition system. It can be                       dynamically modified. This class allows user                       to load the current words list that should be recognized.                       The result of the recognition engine is located in the ALMemory's key: \"WordRecognized\"                       The structure of the result is an array :  [ (string) word , (float) confidence ]</summary>
/// \ingroup ALProxies
class ALSpeechRecognitionProxy
{
  private:
    boost::shared_ptr<ALSpeechRecognitionProxyImpl> fImpl;
    void xInit();

  public:
    /// <summary>
    /// Default Constructor. If there is a broker in your process, which is always the case
    /// if you are in a module, then this will be found and used.
    /// </summary>
    ALSpeechRecognitionProxy();

    /// <summary>
    /// Explicit Broker Constructor. If you have a smart pointer to a broker that you want
    /// to specify, then you can use this constructor. In most cases, the default constructor
    /// will do the work for you without passing a broker explicitly.
    /// </summary>
    /// <param name="broker">A smart pointer to your broker</param>
    ALSpeechRecognitionProxy(boost::shared_ptr<ALBroker> broker);

    /// <summary>
    /// Remote Constructor. This constructor allows you to connect to a remote module by
    /// explicit IP address and port. This is useful if you are not within a process that
    /// has a broker, or want to connect to a remote instance of NAOqi such as another
    /// robot.
    /// </summary>
    /// <param name="ip">The IP address of the remote module you want to connect to</param>
    /// <param name="port">The port of the remote module, typically 9559</param>
    ALSpeechRecognitionProxy(std::string ip, int port=9559);

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALSpeechRecognitionProxyPostHandler post;

    // --- access to ALProxy ----

    /// <summary>
    /// Gets the underlying generic proxy
    /// </summary>
    boost::shared_ptr<ALProxy> getGenericProxy();

    // ------------------------------

    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit();

    /// <summary>
    /// Returns the list of the languages installed on the system.
    /// </summary>
    /// <returns> Array of strings that contains the list of the installed languages. </returns>
    std::vector<std::string> getAvailableLanguages();

    /// <summary>
    /// Gets the name of the parent broker.
    /// </summary>
    /// <returns> The name of the parent broker. </returns>
    std::string getBrokerName();

    /// <summary>
    /// Gets the current period.
    /// </summary>
    /// <returns> Refresh period (in milliseconds). </returns>
    int getCurrentPeriod();

    /// <summary>
    /// Gets the current precision.
    /// </summary>
    /// <returns> Precision of the extractor. </returns>
    float getCurrentPrecision();

    /// <summary>
    /// Returns the current language used by the speech recognition system.
    /// </summary>
    /// <returns> Current language used by the speech recognition engine. </returns>
    std::string getLanguage();

    /// <summary>
    /// Retrieves a method's description.
    /// </summary>
    /// <param name="methodName"> The name of the method. </param>
    /// <returns> A structure containing the method's description. </returns>
    AL::ALValue getMethodHelp(const std::string& methodName);

    /// <summary>
    /// Retrieves the module's method list.
    /// </summary>
    /// <returns> An array of method names. </returns>
    std::vector<std::string> getMethodList();

    /// <summary>
    /// Retrieves the module's description.
    /// </summary>
    /// <returns> A structure describing the module. </returns>
    AL::ALValue getModuleHelp();

    /// <summary>
    /// Gets the period for a specific subscription.
    /// </summary>
    /// <param name="name"> Name of the module which has subscribed. </param>
    /// <returns> Refresh period (in milliseconds). </returns>
    int getMyPeriod(const std::string& name);

    /// <summary>
    /// Gets the precision for a specific subscription.
    /// </summary>
    /// <param name="name"> name of the module which has subscribed </param>
    /// <returns> precision of the extractor </returns>
    float getMyPrecision(const std::string& name);

    /// <summary>
    /// Get the list of values updated in ALMemory.
    /// </summary>
    /// <returns> Array of values updated by this extractor in ALMemory </returns>
    std::vector<std::string> getOutputNames();

    /// <summary>
    /// Gets a parameter of the speech recognition engine. Note that when the ASR engine language is set to Chinese, no parameter can be retrieved
    /// </summary>
    /// <param name="paramName"> Name of the parameter. </param>
    /// <returns> Value of the parameter. </returns>
    float getParameter(const std::string& paramName);

    /// <summary>
    /// This function allows you to get the phonetic transcription(s) used by the speech recognition engine when it is asked to recognize a word. Note that when the ASR engine language is set to Chinese, no phonetic transcription can be retrieved.
    /// </summary>
    /// <param name="word"> Word to phoneticize. </param>
    /// <returns> Phonetic transcription(s) of the word </returns>
    std::vector<std::string> getPhoneticTranscription(const std::string& word);

    /// <summary>
    /// Gets the parameters given by the module.
    /// </summary>
    /// <returns> Array of names and parameters of all subscribers. </returns>
    AL::ALValue getSubscribersInfo();

    /// <summary>
    /// Gets the method usage string. This summarise how to use the method.
    /// </summary>
    /// <param name="name"> The name of the method. </param>
    /// <returns> A string that summarises the usage of the method. </returns>
    std::string getUsage(const std::string& name);

    /// <summary>
    /// Returns true if the method is currently running.
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <returns> True if the method is currently running </returns>
    bool isRunning(const int& id);

    /// <summary>
    /// Loads the vocabulary to recognized contained in a .lxd file. This method is not available with the ASR engine language set to Chinese. For more informations see the red documentation
    /// </summary>
    /// <param name="vocabularyFile"> Name of the lxd file containing the vocabulary </param>
    void loadVocabulary(const std::string& vocabularyFile);

    /// <summary>
    /// Just a ping. Always returns true
    /// </summary>
    /// <returns> returns true </returns>
    bool ping();

    /// <summary>
    /// enable/disable the printing of some debug information
    /// </summary>
    /// <param name="nbOfChannels"> Provides the number of channels of the buffer. </param>
    /// <param name="nbOfSamplesByChannel"> Provides the number of samples by channel. </param>
    /// <param name="timestamp"> Provides the timestamp of the buffer. </param>
    /// <param name="buffer"> Provides the audio buffer as an ALValue. </param>
    void processRemote(const int& nbOfChannels, const int& nbOfSamplesByChannel, const AL::ALValue& timestamp, const AL::ALValue& buffer);

    /// <summary>
    /// enable/disable the printing of some debug information
    /// </summary>
    /// <param name="nbOfChannels"> Provides the number of channels of the buffer. </param>
    /// <param name="nbOfSamplesByChannel"> Provides the number of samples by channel. </param>
    /// <param name="buffer"> Provides the audio buffer as an ALValue. </param>
    void processSoundRemote(const int& nbOfChannels, const int& nbOfSamplesByChannel, const AL::ALValue& buffer);

    /// <summary>
    /// Enables or disables the playing of sounds indicating the state of the recognition engine. 
    ///
    /// If this option is enabled, a sound is played at the beginning of the recognition process (after a call to the subscribe method), and a sound is played when the user call the unsubscribe method
    /// </summary>
    /// <param name="setOrNot"> Enable (true) or disable it (false). </param>
    void setAudioExpression(const bool& setOrNot);

    /// <summary>
    /// enable/disable the printing of some debug information
    /// </summary>
    /// <param name="bSetOrUnset"> enable the functionnality when true. </param>
    void setDebugMode(const bool& bSetOrUnset);

    /// <summary>
    /// Sets the language used by the speech recognition engine.               The list of the available languages can be collected through the getAvailableLanguages method.               If you want to set a language as the default language (loading automatically at module launch), please refer to the web page of the robot.
    /// </summary>
    /// <param name="languageName"> Name of the language in English. </param>
    void setLanguage(const std::string& languageName);

    /// <summary>
    /// Sets a parameter of the speech recognition engine. Note that when the ASR engine language is set to Chinese, no parameter can be set.               The parameters that can be set and the corresponding values are:               \"EarUseSpeechDetector\" - Values : 0 (No), 1 (Regular), or 2 (Cepstral) : type of speech detector used by the ASR engine - default value is 2.                \"EarSpeed\" - Values : 0 to 3 - 0 is slowest and most accurate. 3 is the fastest but may add some recognition errors, especially if you talk fast because some parts of the audio data is not processed. - default value is 2.                \"EarUseFilter\" : Values : 0 (no) or 1 (yes) - Applies a High-Pass filter on the input signal - default value is 0.
    /// </summary>
    /// <param name="paramName"> Name of the parameter. </param>
    /// <param name="paramValue"> Value of the parameter. </param>
    void setParameter(const std::string& paramName, const float& paramValue);

    /// <summary>
    /// Enables or disables the leds animations showing the state of the recognition engine during the recognition process.
    /// </summary>
    /// <param name="setOrNot"> Enable (true) or disable it (false). </param>
    void setVisualExpression(const bool& setOrNot);

    /// <summary>
    /// Sets the list of words (vocabulary) that should be recognized by the speech recognition engine.
    /// </summary>
    /// <param name="vocabulary"> List of words that should be recognized </param>
    /// <param name="enabledWordSpotting"> If disabled, the engine expects to hear one of the specified words, nothing more, nothing less. If enabled, the specified words can be pronounced in the middle of a whole speech stream, the engine will try to spot them. </param>
    void setVocabulary(const std::vector<std::string>& vocabulary, const bool& enabledWordSpotting);

    /// <summary>
    /// Sets the list of words (vocabulary) that should be recognized by the speech recognition engine.
    /// </summary>
    /// <param name="vocabulary"> List of words that should be recognized </param>
    void setWordListAsVocabulary(const std::vector<std::string>& vocabulary);

    /// <summary>
    /// returns true if the method is currently running
    /// </summary>
    /// <param name="id"> the ID of the method to wait for </param>
    void stop(const int& id);

    /// <summary>
    /// Subscribes to the extractor. This causes the extractor to start writing information to memory using the keys described by getOutputNames(). These can be accessed in memory using ALMemory.getData(\"keyName\"). In many cases you can avoid calling subscribe on the extractor by just calling ALMemory.subscribeToEvent() supplying a callback method. This will automatically subscribe to the extractor for you.
    /// </summary>
    /// <param name="name"> Name of the module which subscribes. </param>
    /// <param name="period"> Refresh period (in milliseconds) if relevant. </param>
    /// <param name="precision"> Precision of the extractor if relevant. </param>
    void subscribe(const std::string& name, const int& period, const float& precision);

    /// <summary>
    /// Subscribes to the extractor. This causes the extractor to start writing information to memory using the keys described by getOutputNames(). These can be accessed in memory using ALMemory.getData(\"keyName\"). In many cases you can avoid calling subscribe on the extractor by just calling ALMemory.subscribeToEvent() supplying a callback method. This will automatically subscribe to the extractor for you.
    /// </summary>
    /// <param name="name"> Name of the module which subscribes. </param>
    void subscribe(const std::string& name);

    /// <summary>
    /// Unsubscribes from the extractor.
    /// </summary>
    /// <param name="name"> Name of the module which had subscribed. </param>
    void unsubscribe(const std::string& name);

    /// <summary>
    /// Updates the period if relevant.
    /// </summary>
    /// <param name="name"> Name of the module which has subscribed. </param>
    /// <param name="period"> Refresh period (in milliseconds). </param>
    void updatePeriod(const std::string& name, const int& period);

    /// <summary>
    /// Updates the precision if relevant.
    /// </summary>
    /// <param name="name"> Name of the module which has subscribed. </param>
    /// <param name="precision"> Precision of the extractor. </param>
    void updatePrecision(const std::string& name, const float& precision);

    /// <summary>
    /// Returns the version of the module.
    /// </summary>
    /// <returns> A string containing the version of the module. </returns>
    std::string version();

    /// <summary>
    /// Wait for the end of a long running method that was called using 'post'
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <param name="timeoutPeriod"> The timeout period in ms. To wait indefinately, use a timeoutPeriod of zero. </param>
    /// <returns> True if the timeout period terminated. False if the method returned. </returns>
    bool wait(const int& id, const int& timeoutPeriod);

};

}
#endif // ALSPEECHRECOGNITIONPROXY_H_

