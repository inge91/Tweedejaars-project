// Generated for ALRedBallTracker version 1.12

#ifndef ALREDBALLTRACKERPROXYREMOTE_H_
#define ALREDBALLTRACKERPROXYREMOTE_H_
#include <alremoteproxies/alredballtrackerproxyposthandlerremote.h>

namespace AL
{

/// <summary>This module is dedicated to Track a Red Ball expressed in NAO_SPACE.
    ///
    /// This module need ALRedBallDetection module to run.
    ///
    /// Use StartTracker() API to launch the tracking.</summary>
class ALRedBallTrackerProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALRedBallTrackerProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALRedBallTracker", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALRedBallTrackerProxyPostHandlerRemote post;


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
    /// Return the position of the red ball in NAO_SPACE.
    /// </summary>
    /// <returns> An Array of float containing the red ball position [x, y, z]. </returns>
    std::vector<float> getPosition()
    {

        return callRemote<std::vector<float> >("getPosition");
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
    /// Return true if the red Ball Tracker is running.
    /// </summary>
    /// <returns> true if the red Ball Tracker is running. </returns>
    bool isActive()
    {

        return callRemote<bool >("isActive");
    }


    /// <summary>
    /// Return true if a new Red Ball was detected since the last getPosition().
    /// </summary>
    /// <returns> true if a new Red Ball was detected since the last getPosition(). </returns>
    bool isNewData()
    {

        return callRemote<bool >("isNewData");
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
    /// if true, the tracking will be through a Whole Body Process.
    /// </summary>
    /// <param name="pWholeBodyOn"> The whole Body state </param>
    void setWholeBodyOn(const bool& pWholeBodyOn)
    {

        callVoidRemote("setWholeBodyOn" , pWholeBodyOn);
    }


    /// <summary>
    /// Start the tracker by Subscribing to Event redBallDetected from ALRedBallDetection module.
    ///
    /// Then Wait Event redBallDetected from ALRedBallDetection module.
    ///
    /// And finally send information to motion for head tracking.
    ///
    /// NOTE : Stiffness of Head must be set to 1.0 to move!
    /// </summary>
    void startTracker()
    {

        callVoidRemote("startTracker");
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
    /// Start the tracker by Unsubscribing to Event redBallDetected from ALRedBallDetection module.
    /// </summary>
    void stopTracker()
    {

        callVoidRemote("stopTracker");
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
#endif // ALREDBALLTRACKERPROXY_H_
