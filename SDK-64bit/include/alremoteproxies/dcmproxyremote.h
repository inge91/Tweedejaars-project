// Generated for DCM version 

#ifndef DCMPROXYREMOTE_H_
#define DCMPROXYREMOTE_H_
#include <alremoteproxies/dcmproxyposthandlerremote.h>

namespace AL
{

/// <summary>Manage link with devices (sensors and actuators). See specific documentation.</summary>
class DCMProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    DCMProxyRemote(std::string pIP, int pPort) : ALProxyRemote("DCM", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    DCMProxyPostHandlerRemote post;


    /// <summary>
    /// Calibration of a joint
    /// </summary>
    /// <param name="calibrationInput"> A complex ALValue. See red documentation </param>
    void calibration(const AL::ALValue& calibrationInput)
    {

        callVoidRemote("calibration" , calibrationInput);
    }


    /// <summary>
    /// Create or change an alias (list of actuators)
    /// </summary>
    /// <param name="alias"> Alias name and description </param>
    /// <returns> Same as pParams, but with the name removed if the actuator is not found </returns>
    AL::ALValue createAlias(const AL::ALValue& alias)
    {

        return callRemote<AL::ALValue >("createAlias" , alias);
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
    /// Return the STM base name
    /// </summary>
    /// <returns> the STM base name for all device/sensors (1st string in the array) and all devices (2nd string in the array) </returns>
    AL::ALValue getPrefix()
    {

        return callRemote<AL::ALValue >("getPrefix");
    }


    /// <summary>
    /// Return the DCM time
    /// </summary>
    /// <param name="offset"> optional time in ms (signed) to add/remove </param>
    /// <returns> An integer (could be signed) with the DCM time </returns>
    int getTime(const int& offset)
    {

        return callRemote<int >("getTime" , offset);
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
    /// Save updated value from DCM in XML pref file
    /// </summary>
    /// <param name="action"> string : 'Save' 'Load' 'Add' </param>
    /// <param name="target"> string : 'Chest' 'Head' 'Main' 'All' </param>
    /// <param name="keyName"> The name of the key if action = 'Add'. </param>
    /// <param name="keyValue"> The ALVAlue of the key to add </param>
    /// <returns> Nothing </returns>
    int preferences(const std::string& action, const std::string& target, const std::string& keyName, const AL::ALValue& keyValue)
    {

        return callRemote<int >("preferences" , action, target, keyName, keyValue);
    }


    /// <summary>
    /// Call this function to send a timed-command list to an actuator
    /// </summary>
    /// <param name="commands"> AL::ALValue with all data </param>
    void set(const AL::ALValue& commands)
    {

        callVoidRemote("set" , commands);
    }


    /// <summary>
    /// Call this function to send timed-command list to an alias (list of actuators)
    /// </summary>
    /// <param name="commands"> AL::ALValue with all data </param>
    void setAlias(const AL::ALValue& commands)
    {

        callVoidRemote("setAlias" , commands);
    }


    /// <summary>
    /// Special DCM commands
    /// </summary>
    /// <param name="result"> one string and could be Reset, Version, Chain, Diagnostic, Config </param>
    void special(const std::string& result)
    {

        callVoidRemote("special" , result);
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
#endif // DCMPROXY_H_
