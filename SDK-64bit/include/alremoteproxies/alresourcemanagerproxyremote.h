// Generated for ALResourceManager version 1.12

#ifndef ALRESOURCEMANAGERPROXYREMOTE_H_
#define ALRESOURCEMANAGERPROXYREMOTE_H_
#include <alremoteproxies/alresourcemanagerproxyposthandlerremote.h>

namespace AL
{

/// <summary>Manage robot resources: Synchronize movement, led, sound. Run specific actions when another behavior wants your resources</summary>
class ALResourceManagerProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALResourceManagerProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALResourceManager", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALResourceManagerProxyPostHandlerRemote post;


    /// <summary>
    /// True if resources free
    /// </summary>
    /// <param name="resourceNames"> Resource names </param>
    /// <returns> True if all the specify resources are free </returns>
    bool areResourcesFree(const std::vector<std::string>& resourceNames)
    {

        return callRemote<bool >("areResourcesFree" , resourceNames);
    }


    /// <summary>
    /// True if all the specified resources are owned by the owner
    /// </summary>
    /// <param name="resourceNameList"> Resource name </param>
    /// <param name="ownerName"> Owner pointer with hierarchy </param>
    /// <returns> True if all the specify resources are owned by the owner </returns>
    bool areResourcesOwnedBy(const std::vector<std::string>& resourceNameList, const std::string& ownerName)
    {

        return callRemote<bool >("areResourcesOwnedBy" , resourceNameList, ownerName);
    }


    /// <summary>
    /// Create a resource
    /// </summary>
    /// <param name="resourceName"> Resource name to create </param>
    /// <param name="parentResourceName"> Parent resource name or empty string for root resource </param>
    void createResource(const std::string& resourceName, const std::string& parentResourceName)
    {

        callVoidRemote("createResource" , resourceName, parentResourceName);
    }


    /// <summary>
    /// Delete a root resource
    /// </summary>
    /// <param name="resourceName"> Resource name to delete </param>
    /// <param name="deleteChildResources"> Delete child resources if true </param>
    void deleteResource(const std::string& resourceName, const bool& deleteChildResources)
    {

        callVoidRemote("deleteResource" , resourceName, deleteChildResources);
    }


    /// <summary>
    /// Enable or disable a state resource
    /// </summary>
    /// <param name="resourceName"> The name of the resource that you wish enable of disable. e.g. Standing </param>
    /// <param name="enabled"> True to enable, false to disable </param>
    void enableStateResource(const std::string& resourceName, const bool& enabled)
    {

        callVoidRemote("enableStateResource" , resourceName, enabled);
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
    /// True if a resource is in another parent resource
    /// </summary>
    /// <param name="resourceGroupName"> Group name. Ex: Arm </param>
    /// <param name="resourceName"> Resource name </param>
    /// <returns>  </returns>
    bool isInGroup(const std::string& resourceGroupName, const std::string& resourceName)
    {

        return callRemote<bool >("isInGroup" , resourceGroupName, resourceName);
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
    /// Release resource
    /// </summary>
    /// <param name="resourceName"> Resource name </param>
    /// <param name="ownerName"> Existing owner name </param>
    void releaseResource(const std::string& resourceName, const std::string& ownerName)
    {

        callVoidRemote("releaseResource" , resourceName, ownerName);
    }


    /// <summary>
    /// Release  resources list
    /// </summary>
    /// <param name="resourceNames"> Resource names </param>
    /// <param name="ownerName"> Owner name </param>
    void releaseResources(const std::vector<std::string>& resourceNames, const std::string& ownerName)
    {

        callVoidRemote("releaseResources" , resourceNames, ownerName);
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
    /// Wait resource
    /// </summary>
    /// <param name="ressourceName"> Resource name </param>
    /// <param name="ownerName"> Owner name </param>
    /// <param name="callbackName"> callback name </param>
    /// <param name="timeoutSeconds"> Timeout in seconds </param>
    void waitForResource(const std::string& ressourceName, const std::string& ownerName, const std::string& callbackName, const int& timeoutSeconds)
    {

        callVoidRemote("waitForResource" , ressourceName, ownerName, callbackName, timeoutSeconds);
    }


};

}
#endif // ALRESOURCEMANAGERPROXY_H_
