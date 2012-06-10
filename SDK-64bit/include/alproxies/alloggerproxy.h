// Generated for ALLogger version 1.12

#ifndef ALLOGGERPROXY_H_
#define ALLOGGERPROXY_H_
#include <alproxies/alloggerproxyposthandler.h>

namespace AL
{
class ALBroker;
class ALProxy;

class ALLoggerProxyImpl;

/// <summary>This module allows you log errors, warnings, and info stdout or a file. The verbosity level allow you to  customize the output.</summary>
/// \ingroup ALProxies
class ALLoggerProxy
{
  private:
    boost::shared_ptr<ALLoggerProxyImpl> fImpl;
    void xInit();

  public:
    /// <summary>
    /// Default Constructor. If there is a broker in your process, which is always the case
    /// if you are in a module, then this will be found and used.
    /// </summary>
    ALLoggerProxy();

    /// <summary>
    /// Explicit Broker Constructor. If you have a smart pointer to a broker that you want
    /// to specify, then you can use this constructor. In most cases, the default constructor
    /// will do the work for you without passing a broker explicitly.
    /// </summary>
    /// <param name="broker">A smart pointer to your broker</param>
    ALLoggerProxy(boost::shared_ptr<ALBroker> broker);

    /// <summary>
    /// Remote Constructor. This constructor allows you to connect to a remote module by
    /// explicit IP address and port. This is useful if you are not within a process that
    /// has a broker, or want to connect to a remote instance of NAOqi such as another
    /// robot.
    /// </summary>
    /// <param name="ip">The IP address of the remote module you want to connect to</param>
    /// <param name="port">The port of the remote module, typically 9559</param>
    ALLoggerProxy(std::string ip, int port=9559);

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALLoggerProxyPostHandler post;

    // --- access to ALProxy ----

    /// <summary>
    /// Gets the underlying generic proxy
    /// </summary>
    boost::shared_ptr<ALProxy> getGenericProxy();

    // ------------------------------

    /// <summary>
    /// DEPRECATED. Use qiLogDebug instead. 
    ///
    ///  Log a debug message.
    /// </summary>
    /// <param name="moduleName"> Name of the module. </param>
    /// <param name="message"> Log Message. </param>
    void debug(const std::string& moduleName, const std::string& message);

    /// <summary>
    /// DEPRECATED. Use qiLogError instead. 
    ///
    ///  Log an error.
    /// </summary>
    /// <param name="moduleName"> Name of the module. </param>
    /// <param name="message"> Log Message. </param>
    void error(const std::string& moduleName, const std::string& message);

    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit();

    /// <summary>
    /// DEPRECATED. Use qiLogFatal instead. 
    ///
    ///  Log a fatal error.
    /// </summary>
    /// <param name="moduleName"> Name of the module. </param>
    /// <param name="message"> Log Message. </param>
    void fatal(const std::string& moduleName, const std::string& message);

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
    /// DEPRECATED. Use qiLogInfo instead. 
    ///
    ///  Log a info message.
    /// </summary>
    /// <param name="moduleName"> Name of the module. </param>
    /// <param name="message"> Log Message. </param>
    void info(const std::string& moduleName, const std::string& message);

    /// <summary>
    /// Returns true if the method is currently running.
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <returns> True if the method is currently running </returns>
    bool isRunning(const int& id);

    /// <summary>
    /// DEPRECATED. Create your own log handler with qilog and add it with qi::log::addHandler. See libqi documentation for more details. 
    ///
    ///  Allows the logger to store logs in a file. Warning: this is not recomended on Nao.
    /// </summary>
    /// <param name="fileName"> The fileName to use. Relative to the user naoqi folder. </param>
    void logInFile(const std::string& fileName);

    /// <summary>
    /// DEPRECATED. Should not be used. Publish logs to a Log Forwarder. Pass an empty string in order to use the default value:  \"tcp://localhost:50998\"
    /// </summary>
    /// <param name="inputAddress"> Desired input ZMQ address of the Log Forwarder. </param>
    void logInForwarder(const std::string& inputAddress);

    /// <summary>
    /// Removed: not implemented anymore.
    /// </summary>
    void logInStd();

    /// <summary>
    /// Removed: not implemented anymore.
    /// </summary>
    void logInSys();

    /// <summary>
    /// Same method as debug, which is deprecated itself.
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <param name="arg2"> arg </param>
    void lowDebug(const std::string& arg1, const std::string& arg2);

    /// <summary>
    /// Same method as info, which is deprecated itself.
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <param name="arg2"> arg </param>
    void lowInfo(const std::string& arg1, const std::string& arg2);

    /// <summary>
    /// Just a ping. Always returns true
    /// </summary>
    /// <returns> returns true </returns>
    bool ping();

    /// <summary>
    /// Do not use since we cannot add any handler with the API.
    /// </summary>
    /// <param name="arg1"> arg </param>
    void removeHandler(const std::string& arg1);

    /// <summary>
    /// DEPRECATED. Can be easily replaced if needed.
    /// </summary>
    void separator();

    /// <summary>
    /// Removed: not implemented anymore.
    /// </summary>
    /// <param name="arg1"> arg </param>
    void setFilter(const std::string& arg1);

    /// <summary>
    /// Removed: not implemented anymore.
    /// </summary>
    /// <param name="arg1"> arg </param>
    void setVerbosity(const std::string& arg1);

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
    /// DEPRECATED: use qiLogWarning instead. Log a warning.
    /// </summary>
    /// <param name="moduleName"> Name of the module. </param>
    /// <param name="message"> Log Message. </param>
    void warn(const std::string& moduleName, const std::string& message);

};

}
#endif // ALLOGGERPROXY_H_

