// Generated for ALBehaviorManager version 1.12

#ifndef ALBEHAVIORMANAGERPROXYREMOTE_H_
#define ALBEHAVIORMANAGERPROXYREMOTE_H_
#include <alremoteproxies/albehaviormanagerproxyposthandlerremote.h>

namespace AL
{

/// <summary>This module is intended to manage behaviors. With this module, you can load, start, stop behaviors, add default behaviors or remove them.</summary>
class ALBehaviorManagerProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALBehaviorManagerProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALBehaviorManager", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALBehaviorManagerProxyPostHandlerRemote post;


    /// <summary>
    /// Set the given behavior as default
    /// </summary>
    /// <param name="behavior"> Behavior name </param>
    void addDefaultBehavior(const std::string& behavior)
    {

        callVoidRemote("addDefaultBehavior" , behavior);
    }


    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit()
    {

        callVoidRemote("exit");
    }


    /// <summary>
    /// Get behaviors
    /// </summary>
    /// <returns> Returns the list of behaviors prefixed by their type (User/ or System/). DEPRECATED </returns>
    std::vector<std::string> getBehaviorNames()
    {

        return callRemote<std::vector<std::string> >("getBehaviorNames");
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
    /// Get default behaviors
    /// </summary>
    /// <returns> Return default behaviors </returns>
    std::vector<std::string> getDefaultBehaviors()
    {

        return callRemote<std::vector<std::string> >("getDefaultBehaviors");
    }


    /// <summary>
    /// Get installed behaviors directories names
    /// </summary>
    /// <returns> Returns the behaviors list </returns>
    std::vector<std::string> getInstalledBehaviors()
    {

        return callRemote<std::vector<std::string> >("getInstalledBehaviors");
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
    /// Get running behaviors
    /// </summary>
    /// <returns> Return running behaviors </returns>
    std::vector<std::string> getRunningBehaviors()
    {

        return callRemote<std::vector<std::string> >("getRunningBehaviors");
    }


    /// <summary>
    /// Get system behaviors
    /// </summary>
    /// <returns> Returns the list of system behaviors prefixed by System/. </returns>
    std::vector<std::string> getSystemBehaviorNames()
    {

        return callRemote<std::vector<std::string> >("getSystemBehaviorNames");
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
    /// Get user's behaviors
    /// </summary>
    /// <returns> Returns the list of user's behaviors prefixed by User/. DEPRECATED. </returns>
    std::vector<std::string> getUserBehaviorNames()
    {

        return callRemote<std::vector<std::string> >("getUserBehaviorNames");
    }


    /// <summary>
    /// Tell if supplied name corresponds to a behavior that has been installed
    /// </summary>
    /// <param name="name"> The behavior directory name </param>
    /// <returns> Returns true if it is a valid behavior </returns>
    bool isBehaviorInstalled(const std::string& name)
    {

        return callRemote<bool >("isBehaviorInstalled" , name);
    }


    /// <summary>
    /// Tell if the supplied namecorresponds to an existing behavior.
    /// </summary>
    /// <param name="prefixedBehavior"> Prefixed behavior or just behavior's name (latter usage deprecated, in this case the behavior is searched for amongst user's behaviors, then in system behaviors) DEPRECATED. </param>
    /// <returns> Returns true if it is an existing behavior </returns>
    bool isBehaviorPresent(const std::string& prefixedBehavior)
    {

        return callRemote<bool >("isBehaviorPresent" , prefixedBehavior);
    }


    /// <summary>
    /// Tell if supplied name corresponds to a running behavior
    /// </summary>
    /// <param name="behavior"> Behavior name </param>
    /// <returns> Returns true if it is a running behavior </returns>
    bool isBehaviorRunning(const std::string& behavior)
    {

        return callRemote<bool >("isBehaviorRunning" , behavior);
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
    /// Play default behaviors
    /// </summary>
    void playDefaultProject()
    {

        callVoidRemote("playDefaultProject");
    }


    /// <summary>
    /// Load a behavior
    /// </summary>
    /// <param name="behavior"> Behavior name </param>
    /// <returns> Returns true if it was successfully loaded. </returns>
    bool preloadBehavior(const std::string& behavior)
    {

        return callRemote<bool >("preloadBehavior" , behavior);
    }


    /// <summary>
    /// Remove a behavior from the filesystem
    /// </summary>
    /// <param name="behavior"> Behavior name </param>
    /// <returns> Return true if succeeded, else false </returns>
    bool removeBehavior(const std::string& behavior)
    {

        return callRemote<bool >("removeBehavior" , behavior);
    }


    /// <summary>
    /// Remove the given behavior from the default behaviors
    /// </summary>
    /// <param name="behavior"> Behavior name </param>
    void removeDefaultBehavior(const std::string& behavior)
    {

        callVoidRemote("removeDefaultBehavior" , behavior);
    }


    /// <summary>
    /// Run a behavior
    /// </summary>
    /// <param name="behavior"> Behavior name </param>
    void runBehavior(const std::string& behavior)
    {

        callVoidRemote("runBehavior" , behavior);
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
    /// Stop all behaviors
    /// </summary>
    void stopAllBehaviors()
    {

        callVoidRemote("stopAllBehaviors");
    }


    /// <summary>
    /// Stop a behavior
    /// </summary>
    /// <param name="behavior"> Behavior name </param>
    void stopBehavior(const std::string& behavior)
    {

        callVoidRemote("stopBehavior" , behavior);
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
#endif // ALBEHAVIORMANAGERPROXY_H_
