// Generated for ALPreferences version 1.12

#ifndef ALPREFERENCESPROXY_H_
#define ALPREFERENCESPROXY_H_
#include <alproxies/alpreferencesproxyposthandler.h>

namespace AL
{
class ALBroker;
class ALProxy;

class ALPreferencesProxyImpl;

/// <summary>ALPreferences allows access to xml preference files. 
    ///
    /// A preference is defined as follows : 
    ///
    /// pParams[0] Name of the preference; 
    ///
    /// pParams[1] Description of the preference; 
    ///
    /// pParams[2] The value of the preference (can contain other preferences); 
    ///
    /// pParams[3] (optional) The name of the data when inserted into memory.</summary>
/// \ingroup ALProxies
class ALPreferencesProxy
{
  private:
    boost::shared_ptr<ALPreferencesProxyImpl> fImpl;
    void xInit();

  public:
    /// <summary>
    /// Default Constructor. If there is a broker in your process, which is always the case
    /// if you are in a module, then this will be found and used.
    /// </summary>
    ALPreferencesProxy();

    /// <summary>
    /// Explicit Broker Constructor. If you have a smart pointer to a broker that you want
    /// to specify, then you can use this constructor. In most cases, the default constructor
    /// will do the work for you without passing a broker explicitly.
    /// </summary>
    /// <param name="broker">A smart pointer to your broker</param>
    ALPreferencesProxy(boost::shared_ptr<ALBroker> broker);

    /// <summary>
    /// Remote Constructor. This constructor allows you to connect to a remote module by
    /// explicit IP address and port. This is useful if you are not within a process that
    /// has a broker, or want to connect to a remote instance of NAOqi such as another
    /// robot.
    /// </summary>
    /// <param name="ip">The IP address of the remote module you want to connect to</param>
    /// <param name="port">The port of the remote module, typically 9559</param>
    ALPreferencesProxy(std::string ip, int port=9559);

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALPreferencesProxyPostHandler post;

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
    /// Gets the name of the parent broker.
    /// </summary>
    /// <returns> The name of the parent broker. </returns>
    std::string getBrokerName();

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
    /// Just a ping. Always returns true
    /// </summary>
    /// <returns> returns true </returns>
    bool ping();

    /// <summary>
    /// Reads all preferences from an xml files and stores them in an ALValue.
    /// </summary>
    /// <param name="fileName"> Name of the module associate to the preference. </param>
    /// <param name="autoGenerateMemoryNames"> If true a memory name will be generated for each non-array preference. </param>
    /// <returns> array reprenting the whole file. </returns>
    AL::ALValue readPrefFile(const std::string& fileName, const bool& autoGenerateMemoryNames);

    /// <summary>
    /// Writes all preferences from ALValue to an xml file.
    /// </summary>
    /// <param name="prefs"> array reprenting the whole file. </param>
    /// <returns> True upon success. </returns>
    bool saveToMemory(const AL::ALValue& prefs);

    /// <summary>
    /// returns true if the method is currently running
    /// </summary>
    /// <param name="id"> the ID of the method to wait for </param>
    void stop(const int& id);

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

    /// <summary>
    /// Writes all preferences from ALValue to an xml file.
    /// </summary>
    /// <param name="fileName"> Name of the module associate to the preference. </param>
    /// <param name="prefs"> array reprenting the whole file. </param>
    /// <param name="ignoreMemoryNames"> If true all memory names will be removed before saving. </param>
    void writePrefFile(const std::string& fileName, const AL::ALValue& prefs, const bool& ignoreMemoryNames);

};

}
#endif // ALPREFERENCESPROXY_H_

