// Generated for ALLogger version 1.12

#ifndef ALLOGGERPROXYREMOTE_H_
#define ALLOGGERPROXYREMOTE_H_
#include <alremoteproxies/alloggerproxyposthandlerremote.h>

namespace AL
{

/// <summary>This module allows you log errors, warnings, and info stdout or a file. The verbosity level allow you to  customize the output.</summary>
class ALLoggerProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALLoggerProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALLogger", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALLoggerProxyPostHandlerRemote post;


    /// <summary>
    /// DEPRECATED. Use qiLogDebug instead. 
    ///
    ///  Log a debug message.
    /// </summary>
    /// <param name="moduleName"> Name of the module. </param>
    /// <param name="message"> Log Message. </param>
    void debug(const std::string& moduleName, const std::string& message)
    {

        callVoidRemote("debug" , moduleName, message);
    }


    /// <summary>
    /// DEPRECATED. Use qiLogError instead. 
    ///
    ///  Log an error.
    /// </summary>
    /// <param name="moduleName"> Name of the module. </param>
    /// <param name="message"> Log Message. </param>
    void error(const std::string& moduleName, const std::string& message)
    {

        callVoidRemote("error" , moduleName, message);
    }


    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit()
    {

        callVoidRemote("exit");
    }


    /// <summary>
    /// DEPRECATED. Use qiLogFatal instead. 
    ///
    ///  Log a fatal error.
    /// </summary>
    /// <param name="moduleName"> Name of the module. </param>
    /// <param name="message"> Log Message. </param>
    void fatal(const std::string& moduleName, const std::string& message)
    {

        callVoidRemote("fatal" , moduleName, message);
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
    /// Gets the method usage string. This summarise how to use the method.
    /// </summary>
    /// <param name="name"> The name of the method. </param>
    /// <returns> A string that summarises the usage of the method. </returns>
    std::string getUsage(const std::string& name)
    {

        return callRemote<std::string >("getUsage" , name);
    }


    /// <summary>
    /// DEPRECATED. Use qiLogInfo instead. 
    ///
    ///  Log a info message.
    /// </summary>
    /// <param name="moduleName"> Name of the module. </param>
    /// <param name="message"> Log Message. </param>
    void info(const std::string& moduleName, const std::string& message)
    {

        callVoidRemote("info" , moduleName, message);
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
    /// DEPRECATED. Create your own log handler with qilog and add it with qi::log::addHandler. See libqi documentation for more details. 
    ///
    ///  Allows the logger to store logs in a file. Warning: this is not recomended on Nao.
    /// </summary>
    /// <param name="fileName"> The fileName to use. Relative to the user naoqi folder. </param>
    void logInFile(const std::string& fileName)
    {

        callVoidRemote("logInFile" , fileName);
    }


    /// <summary>
    /// DEPRECATED. Should not be used. Publish logs to a Log Forwarder. Pass an empty string in order to use the default value:  \"tcp://localhost:50998\"
    /// </summary>
    /// <param name="inputAddress"> Desired input ZMQ address of the Log Forwarder. </param>
    void logInForwarder(const std::string& inputAddress)
    {

        callVoidRemote("logInForwarder" , inputAddress);
    }


    /// <summary>
    /// Removed: not implemented anymore.
    /// </summary>
    void logInStd()
    {

        callVoidRemote("logInStd");
    }


    /// <summary>
    /// Removed: not implemented anymore.
    /// </summary>
    void logInSys()
    {

        callVoidRemote("logInSys");
    }


    /// <summary>
    /// Same method as debug, which is deprecated itself.
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <param name="arg2"> arg </param>
    void lowDebug(const std::string& arg1, const std::string& arg2)
    {

        callVoidRemote("lowDebug" , arg1, arg2);
    }


    /// <summary>
    /// Same method as info, which is deprecated itself.
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <param name="arg2"> arg </param>
    void lowInfo(const std::string& arg1, const std::string& arg2)
    {

        callVoidRemote("lowInfo" , arg1, arg2);
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
    /// Do not use since we cannot add any handler with the API.
    /// </summary>
    /// <param name="arg1"> arg </param>
    void removeHandler(const std::string& arg1)
    {

        callVoidRemote("removeHandler" , arg1);
    }


    /// <summary>
    /// DEPRECATED. Can be easily replaced if needed.
    /// </summary>
    void separator()
    {

        callVoidRemote("separator");
    }


    /// <summary>
    /// Removed: not implemented anymore.
    /// </summary>
    /// <param name="arg1"> arg </param>
    void setFilter(const std::string& arg1)
    {

        callVoidRemote("setFilter" , arg1);
    }


    /// <summary>
    /// Removed: not implemented anymore.
    /// </summary>
    /// <param name="arg1"> arg </param>
    void setVerbosity(const std::string& arg1)
    {

        callVoidRemote("setVerbosity" , arg1);
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


    /// <summary>
    /// DEPRECATED: use qiLogWarning instead. Log a warning.
    /// </summary>
    /// <param name="moduleName"> Name of the module. </param>
    /// <param name="message"> Log Message. </param>
    void warn(const std::string& moduleName, const std::string& message)
    {

        callVoidRemote("warn" , moduleName, message);
    }


};

}
#endif // ALLOGGERPROXY_H_
