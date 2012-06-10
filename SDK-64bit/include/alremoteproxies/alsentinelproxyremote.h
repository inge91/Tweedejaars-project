// Generated for ALSentinel version 1.12

#ifndef ALSENTINELPROXYREMOTE_H_
#define ALSENTINELPROXYREMOTE_H_
#include <alremoteproxies/alsentinelproxyposthandlerremote.h>

namespace AL
{

/// <summary>ALSentinel (ex-ALWatchDog) is a module that implements vital services for Nao:
    ///
    /// 	- Check Vitality of naoqi.
    ///
    /// 	- Check Battery.
    ///
    /// 	- Check press on chest Button (soft power off).
    ///
    /// 	- Warn about motor heating.
    ///
    /// ...</summary>
class ALSentinelProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALSentinelProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALSentinel", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALSentinelProxyPostHandlerRemote post;


    /// <summary>
    /// callback for internal use.
    /// </summary>
    /// <param name="dataName"> Name of the modified data </param>
    /// <param name="data"> value of the data </param>
    /// <param name="message"> associate message. </param>
    void batteryChargeCellVoltageMinChanged(const std::string& dataName, const AL::ALValue& data, const std::string& message)
    {

        callVoidRemote("batteryChargeCellVoltageMinChanged" , dataName, data, message);
    }


    /// <summary>
    /// callback for internal use.
    /// </summary>
    /// <param name="dataName"> Name of the modified data </param>
    /// <param name="data"> value of the data </param>
    /// <param name="message"> associate message. </param>
    void batteryPowerPluggedChanged(const std::string& dataName, const AL::ALValue& data, const std::string& message)
    {

        callVoidRemote("batteryPowerPluggedChanged" , dataName, data, message);
    }


    /// <summary>
    /// check the battery information, voltage and alarm flag
    /// </summary>
    /// <param name="enable"> true of false to respectively enable or disable (default: true) </param>
    void enableBatteryMeasure(const bool& enable)
    {

        callVoidRemote("enableBatteryMeasure" , enable);
    }


    /// <summary>
    /// check the remaining physical memory
    /// </summary>
    /// <param name="enable"> true of false to respectively enable or disable (default: true) </param>
    void enableCheckRemainingRam(const bool& enable)
    {

        callVoidRemote("enableCheckRemainingRam" , enable);
    }


    /// <summary>
    /// enable or disable the \"ouch\" action after two pushes.
    /// </summary>
    /// <param name="enable"> true of false to respectively enable or disable </param>
    void enableDefaultActionDoubleClick(const bool& enable)
    {

        callVoidRemote("enableDefaultActionDoubleClick" , enable);
    }


    /// <summary>
    /// enable or disable the \"hello, i'm nao...\" after one short push of the Power button. In both cases the ALMemory ALSentinel/SimpleClickOccured key will be set to true, so users can read/registerOnChange it, then reset to false after handling the event.
    /// </summary>
    /// <param name="enable"> true of false to respectively enable or disable </param>
    void enableDefaultActionSimpleClick(const bool& enable)
    {

        callVoidRemote("enableDefaultActionSimpleClick" , enable);
    }


    /// <summary>
    /// enable or disable the \"restart naoqi\" action after three pushes.
    /// </summary>
    /// <param name="enable"> true of false to respectively enable or disable </param>
    void enableDefaultActionTripleClick(const bool& enable)
    {

        callVoidRemote("enableDefaultActionTripleClick" , enable);
    }


    /// <summary>
    /// Enable or Disable heat monitoring.
    /// </summary>
    /// <param name="enable"> true to enable, false to disable, default: true </param>
    void enableHeatMonitoring(const bool& enable)
    {

        callVoidRemote("enableHeatMonitoring" , enable);
    }


    /// <summary>
    /// Enable or Disable power monitoring.
    /// </summary>
    /// <param name="enable"> true to enable, false to disable, default: true </param>
    void enablePowerMonitoring(const bool& enable)
    {

        callVoidRemote("enablePowerMonitoring" , enable);
    }


    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit()
    {

        callVoidRemote("exit");
    }


    /// <summary>
    /// exit naoqi (warning: it will really exit Naoqi)
    /// </summary>
    void exitNaoqi()
    {

        callVoidRemote("exitNaoqi");
    }


    /// <summary>
    /// Get the battery level (0..5) 5: full 0: totally empty (never reached).
    /// </summary>
    /// <returns> the battery level (0..5): 5: full 0: totally empty (never reached) </returns>
    int getBatteryLevel()
    {

        return callRemote<int >("getBatteryLevel");
    }


    /// <summary>
    /// Get a text presentation of the battery level ('My battery is...').
    /// </summary>
    /// <returns> the sentence describing the battery level </returns>
    std::string getBatteryLevelDesc()
    {

        return callRemote<std::string >("getBatteryLevelDesc");
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
    /// get the remaining physical memory value (one shot)
    /// </summary>
    /// <returns> the remaining RAM in kb </returns>
    int getRemainingRam()
    {

        return callRemote<int >("getRemainingRam");
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
    /// callback for internal use.
    /// </summary>
    /// <param name="dataName"> Name of the modified data </param>
    /// <param name="data"> value of the data </param>
    /// <param name="message"> associate message. </param>
    void onAccX(const std::string& dataName, const AL::ALValue& data, const std::string& message)
    {

        callVoidRemote("onAccX" , dataName, data, message);
    }


    /// <summary>
    /// callback for internal use.
    /// </summary>
    /// <param name="dataName"> Name of the modified data </param>
    /// <param name="data"> value of the data </param>
    /// <param name="message"> associate message. </param>
    void onAccY(const std::string& dataName, const AL::ALValue& data, const std::string& message)
    {

        callVoidRemote("onAccY" , dataName, data, message);
    }


    /// <summary>
    /// callback for internal use.
    /// </summary>
    /// <param name="dataName"> Name of the modified data </param>
    /// <param name="data"> value of the data </param>
    /// <param name="message"> associate message. </param>
    void onAccZ(const std::string& dataName, const AL::ALValue& data, const std::string& message)
    {

        callVoidRemote("onAccZ" , dataName, data, message);
    }


    /// <summary>
    /// callback for internal use.
    /// </summary>
    /// <param name="dataName"> Name of the modified data </param>
    /// <param name="data"> value of the data </param>
    /// <param name="message"> associate message. </param>
    void onBatteryMeasure(const std::string& dataName, const AL::ALValue& data, const std::string& message)
    {

        callVoidRemote("onBatteryMeasure" , dataName, data, message);
    }


    /// <summary>
    /// callback for change in battery power level. (internal use).
    /// </summary>
    /// <param name="dataName"> Name of the modified data </param>
    /// <param name="data"> value of the data </param>
    /// <param name="message"> associate message. </param>
    void onMotorError(const std::string& dataName, const AL::ALValue& data, const std::string& message)
    {

        callVoidRemote("onMotorError" , dataName, data, message);
    }


    /// <summary>
    /// callback for change in battery power level. (internal use).
    /// </summary>
    /// <param name="dataName"> Name of the modified data </param>
    /// <param name="data"> value of the data </param>
    /// <param name="message"> associate message. </param>
    void onTemperatureMeasure(const std::string& dataName, const AL::ALValue& data, const std::string& message)
    {

        callVoidRemote("onTemperatureMeasure" , dataName, data, message);
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
    /// callback when the power button is pressed. (internal use).
    /// </summary>
    /// <param name="dataName"> Name of the modified data </param>
    /// <param name="data"> value of the data </param>
    /// <param name="message"> associate message. </param>
    void powerButtonOnPress(const std::string& dataName, const AL::ALValue& data, const std::string& message)
    {

        callVoidRemote("powerButtonOnPress" , dataName, data, message);
    }


    /// <summary>
    /// Launch a small presentation of Nao: name, ip, battery. It's the default behavior launched when user press on the chest
    /// </summary>
    /// <param name="enableFastCheckJoints"> if true, Nao will quickly check that his joints are moving properly. </param>
    void presentation(const bool& enableFastCheckJoints)
    {

        callVoidRemote("presentation" , enableFastCheckJoints);
    }


    /// <summary>
    /// Monitors buttons and Battery.
    /// </summary>
    void run()
    {

        callVoidRemote("run");
    }


    /// <summary>
    /// Change the power threshold; below it, Nao will sit down and remove power from his motors.
    /// </summary>
    /// <param name="powerLimit"> power limit in percent, default: 0.07; 0.00 to disable this feature. </param>
    void setPowerLimit(const float& powerLimit)
    {

        callVoidRemote("setPowerLimit" , powerLimit);
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
#endif // ALSENTINELPROXY_H_
