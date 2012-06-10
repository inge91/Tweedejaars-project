// Generated for ALLaser version 1.12

#ifndef ALLASERPROXYREMOTE_H_
#define ALLASERPROXYREMOTE_H_
#include <alremoteproxies/allaserproxyposthandlerremote.h>

namespace AL
{

/// <summary>Allow control over Hokuyo laser when available on Nao's head.</summary>
class ALLaserProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALLaserProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALLaser", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALLaserProxyPostHandlerRemote post;


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
    /// Disable laser light
    /// </summary>
    void laserOFF()
    {

        callVoidRemote("laserOFF");
    }


    /// <summary>
    /// Enable laser light and sampling
    /// </summary>
    void laserON()
    {

        callVoidRemote("laserON");
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
    /// Set detection threshold of the laser
    /// </summary>
    /// <param name="length_min_l"> int containing the min length that the laser will detect(mm), this value must be upper than 20 mm </param>
    /// <param name="length_max_l"> int containing the max length that the laser will detect(mm), this value must be lower than 5600 mm </param>
    void setDetectingLength(const AL::ALValue& length_min_l, const AL::ALValue& length_max_l)
    {

        callVoidRemote("setDetectingLength" , length_min_l, length_max_l);
    }


    /// <summary>
    /// Set openning angle of the laser
    /// </summary>
    /// <param name="angle_min_f"> float containing the min value in rad, this value must be upper than -2.35619449 </param>
    /// <param name="angle_max_f"> float containing the max value in rad, this value must be lower than 2.092349795 </param>
    void setOpeningAngle(const AL::ALValue& angle_min_f, const AL::ALValue& angle_max_f)
    {

        callVoidRemote("setOpeningAngle" , angle_min_f, angle_max_f);
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
#endif // ALLASERPROXY_H_
