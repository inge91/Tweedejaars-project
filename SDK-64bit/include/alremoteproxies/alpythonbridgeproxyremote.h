// Generated for ALPythonBridge version 1.12

#ifndef ALPYTHONBRIDGEPROXYREMOTE_H_
#define ALPYTHONBRIDGEPROXYREMOTE_H_
#include <alremoteproxies/alpythonbridgeproxyposthandlerremote.h>

namespace AL
{

/// <summary>This module evaluates python commands on the fly.</summary>
class ALPythonBridgeProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALPythonBridgeProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALPythonBridge", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALPythonBridgeProxyPostHandlerRemote post;


    /// <summary>
    /// eval script
    /// </summary>
    /// <param name="stringToEvaluate"> string to eval </param>
    /// <returns> if the evaluation has gone wrong </returns>
    std::string eval(const std::string& stringToEvaluate)
    {

        return callRemote<std::string >("eval" , stringToEvaluate);
    }


    /// <summary>
    /// evaluates script and returns an informative array.
    /// </summary>
    /// <param name="stringToEvaluate"> string to eval </param>
    /// <returns> an array containing [return value, exceptions, stdout, stderr] </returns>
    AL::ALValue evalFull(const std::string& stringToEvaluate)
    {

        return callRemote<AL::ALValue >("evalFull" , stringToEvaluate);
    }


    /// <summary>
    /// eval script and return result. evalReturn(2+2) will return 4
    /// </summary>
    /// <param name="stringToEvaluate"> string to eval </param>
    /// <returns> the result of the evaluation </returns>
    AL::ALValue evalReturn(const std::string& stringToEvaluate)
    {

        return callRemote<AL::ALValue >("evalReturn" , stringToEvaluate);
    }


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


};

}
#endif // ALPYTHONBRIDGEPROXY_H_
