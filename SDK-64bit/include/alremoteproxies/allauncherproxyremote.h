// Generated for ALLauncher version 1.12

#ifndef ALLAUNCHERPROXYREMOTE_H_
#define ALLAUNCHERPROXYREMOTE_H_
#include <alremoteproxies/allauncherproxyposthandlerremote.h>

namespace AL
{

/// <summary>ALlauncher allows to link dynamicaly with library, run executable, unload library, check if module is loaded...</summary>
class ALLauncherProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALLauncherProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALLauncher", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALLauncherProxyPostHandlerRemote post;


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
    /// get the list of modules loaded on the robot and connected on the robot
    /// </summary>
    /// <returns> array of present modules </returns>
    std::vector<std::string> getGlobalModuleList()
    {

        return callRemote<std::vector<std::string> >("getGlobalModuleList");
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
    /// Tests the existence of an active module in the global system (in same executable or in another executable of the distributed system)
    /// </summary>
    /// <param name="strPartOfModuleName"> a part of the name of the module to test existence </param>
    /// <returns> the returned value is true if this module is present </returns>
    bool isModulePresent(const std::string& strPartOfModuleName)
    {

        return callRemote<bool >("isModulePresent" , strPartOfModuleName);
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
    /// runs an executable and connect it to current broker (executable)
    /// </summary>
    /// <param name="moduleName"> the name of the module to launch or the name of the script file to execute </param>
    /// <returns> true if ok </returns>
    bool launchExecutable(const std::string& moduleName)
    {

        return callRemote<bool >("launchExecutable" , moduleName);
    }


    /// <summary>
    /// Loads dynamicaly a module
    /// </summary>
    /// <param name="moduleName"> the name of the module to launch or the name of the python script to evaluate </param>
    /// <returns> list of modules loaded </returns>
    std::vector<std::string> launchLocal(const std::string& moduleName)
    {

        return callRemote<std::vector<std::string> >("launchLocal" , moduleName);
    }


    /// <summary>
    /// Import a python module
    /// </summary>
    /// <param name="moduleName"> the name of the module to launch </param>
    /// <returns> true if ok </returns>
    bool launchPythonModule(const std::string& moduleName)
    {

        return callRemote<bool >("launchPythonModule" , moduleName);
    }


    /// <summary>
    /// runs a script connected the current broker
    /// </summary>
    /// <param name="moduleName"> the name of the script to launch (python) </param>
    /// <returns> true if ok </returns>
    bool launchScript(const std::string& moduleName)
    {

        return callRemote<bool >("launchScript" , moduleName);
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
#endif // ALLAUNCHERPROXY_H_
