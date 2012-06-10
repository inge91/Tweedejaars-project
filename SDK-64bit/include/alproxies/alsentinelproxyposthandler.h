// Generated for ALSentinel version 1.12

#ifndef ALSENTINELPROXYPOSTHANDLER_H_
#define ALSENTINELPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALSentinelProxy;

/// <summary>
/// ALSentinel (ex-ALWatchDog) is a module that implements vital services for Nao:
    ///
    /// 	- Check Vitality of naoqi.
    ///
    /// 	- Check Battery.
    ///
    /// 	- Check press on chest Button (soft power off).
    ///
    /// 	- Warn about motor heating.
    ///
    /// ...
/// ALSentinelPostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALSentinelProxyPostHandler
{
  friend class ALSentinelProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// ALSentinel (ex-ALWatchDog) is a module that implements vital services for Nao:
    ///
    /// 	- Check Vitality of naoqi.
    ///
    /// 	- Check Battery.
    ///
    /// 	- Check press on chest Button (soft power off).
    ///
    /// 	- Warn about motor heating.
    ///
    /// ...
  /// ALSentinelPostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALSentinelProxyPostHandler();

  /// <summary>
  /// callback for internal use.
  /// </summary>
  /// <param name="dataName"> Name of the modified data </param>
  /// <param name="data"> value of the data </param>
  /// <param name="message"> associate message. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int batteryChargeCellVoltageMinChanged(const std::string& dataName, const AL::ALValue& data, const std::string& message);
  /// <summary>
  /// callback for internal use.
  /// </summary>
  /// <param name="dataName"> Name of the modified data </param>
  /// <param name="data"> value of the data </param>
  /// <param name="message"> associate message. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int batteryPowerPluggedChanged(const std::string& dataName, const AL::ALValue& data, const std::string& message);
  /// <summary>
  /// check the battery information, voltage and alarm flag
  /// </summary>
  /// <param name="enable"> true of false to respectively enable or disable (default: true) </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int enableBatteryMeasure(const bool& enable);
  /// <summary>
  /// check the remaining physical memory
  /// </summary>
  /// <param name="enable"> true of false to respectively enable or disable (default: true) </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int enableCheckRemainingRam(const bool& enable);
  /// <summary>
  /// enable or disable the \"ouch\" action after two pushes.
  /// </summary>
  /// <param name="enable"> true of false to respectively enable or disable </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int enableDefaultActionDoubleClick(const bool& enable);
  /// <summary>
  /// enable or disable the \"hello, i'm nao...\" after one short push of the Power button. In both cases the ALMemory ALSentinel/SimpleClickOccured key will be set to true, so users can read/registerOnChange it, then reset to false after handling the event.
  /// </summary>
  /// <param name="enable"> true of false to respectively enable or disable </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int enableDefaultActionSimpleClick(const bool& enable);
  /// <summary>
  /// enable or disable the \"restart naoqi\" action after three pushes.
  /// </summary>
  /// <param name="enable"> true of false to respectively enable or disable </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int enableDefaultActionTripleClick(const bool& enable);
  /// <summary>
  /// Enable or Disable heat monitoring.
  /// </summary>
  /// <param name="enable"> true to enable, false to disable, default: true </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int enableHeatMonitoring(const bool& enable);
  /// <summary>
  /// Enable or Disable power monitoring.
  /// </summary>
  /// <param name="enable"> true to enable, false to disable, default: true </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int enablePowerMonitoring(const bool& enable);
  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// exit naoqi (warning: it will really exit Naoqi)
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exitNaoqi();
  /// <summary>
  /// callback for internal use.
  /// </summary>
  /// <param name="dataName"> Name of the modified data </param>
  /// <param name="data"> value of the data </param>
  /// <param name="message"> associate message. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int onAccX(const std::string& dataName, const AL::ALValue& data, const std::string& message);
  /// <summary>
  /// callback for internal use.
  /// </summary>
  /// <param name="dataName"> Name of the modified data </param>
  /// <param name="data"> value of the data </param>
  /// <param name="message"> associate message. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int onAccY(const std::string& dataName, const AL::ALValue& data, const std::string& message);
  /// <summary>
  /// callback for internal use.
  /// </summary>
  /// <param name="dataName"> Name of the modified data </param>
  /// <param name="data"> value of the data </param>
  /// <param name="message"> associate message. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int onAccZ(const std::string& dataName, const AL::ALValue& data, const std::string& message);
  /// <summary>
  /// callback for internal use.
  /// </summary>
  /// <param name="dataName"> Name of the modified data </param>
  /// <param name="data"> value of the data </param>
  /// <param name="message"> associate message. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int onBatteryMeasure(const std::string& dataName, const AL::ALValue& data, const std::string& message);
  /// <summary>
  /// callback for change in battery power level. (internal use).
  /// </summary>
  /// <param name="dataName"> Name of the modified data </param>
  /// <param name="data"> value of the data </param>
  /// <param name="message"> associate message. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int onMotorError(const std::string& dataName, const AL::ALValue& data, const std::string& message);
  /// <summary>
  /// callback for change in battery power level. (internal use).
  /// </summary>
  /// <param name="dataName"> Name of the modified data </param>
  /// <param name="data"> value of the data </param>
  /// <param name="message"> associate message. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int onTemperatureMeasure(const std::string& dataName, const AL::ALValue& data, const std::string& message);
  /// <summary>
  /// callback when the power button is pressed. (internal use).
  /// </summary>
  /// <param name="dataName"> Name of the modified data </param>
  /// <param name="data"> value of the data </param>
  /// <param name="message"> associate message. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int powerButtonOnPress(const std::string& dataName, const AL::ALValue& data, const std::string& message);
  /// <summary>
  /// Launch a small presentation of Nao: name, ip, battery. It's the default behavior launched when user press on the chest
  /// </summary>
  /// <param name="enableFastCheckJoints"> if true, Nao will quickly check that his joints are moving properly. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int presentation(const bool& enableFastCheckJoints);
  /// <summary>
  /// Monitors buttons and Battery.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int run();
  /// <summary>
  /// Change the power threshold; below it, Nao will sit down and remove power from his motors.
  /// </summary>
  /// <param name="powerLimit"> power limit in percent, default: 0.07; 0.00 to disable this feature. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setPowerLimit(const float& powerLimit);
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
};

}
#endif // ALSENTINELPROXYPOSTHANDLER_H_

