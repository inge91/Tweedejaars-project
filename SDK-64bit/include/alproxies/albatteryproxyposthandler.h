// Generated for ALBattery version 1.12

#ifndef ALBATTERYPROXYPOSTHANDLER_H_
#define ALBATTERYPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALBatteryProxy;

/// <summary>
/// Deals with Battery informations.
    ///
    /// A event name BatteryChargeCellVoltageMinChanged is raised when the cell voltage Min (int) of the battery changed.
    ///
    /// A event name BatteryChargingFlagChanged is raised when the flag battery is charging (bool) changed.
    ///
    /// A event name BatteryFullChargedFlagChanged is raised when the flag battery is full charged (bool) changed.
    ///
    /// A event name BatteryDisChargingFlagChanged is raised when the flag battery is disCharging (bool) changed.
    ///
    /// A event name BatteryLevelChanged is raised when the battery level percentage (int) changed.
/// ALBatteryPostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALBatteryProxyPostHandler
{
  friend class ALBatteryProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// Deals with Battery informations.
    ///
    /// A event name BatteryChargeCellVoltageMinChanged is raised when the cell voltage Min (int) of the battery changed.
    ///
    /// A event name BatteryChargingFlagChanged is raised when the flag battery is charging (bool) changed.
    ///
    /// A event name BatteryFullChargedFlagChanged is raised when the flag battery is full charged (bool) changed.
    ///
    /// A event name BatteryDisChargingFlagChanged is raised when the flag battery is disCharging (bool) changed.
    ///
    /// A event name BatteryLevelChanged is raised when the battery level percentage (int) changed.
  /// ALBatteryPostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALBatteryProxyPostHandler();

  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
};

}
#endif // ALBATTERYPROXYPOSTHANDLER_H_

