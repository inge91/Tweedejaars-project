// Generated for ALBattery version 1.12


#ifndef ALBATTERYPROXYPOSTHANDLERREMOTE_H_
#define ALBATTERYPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALBatteryProxyRemote;

/// <summary>Deals with Battery informations.
    ///
    /// A event name BatteryChargeCellVoltageMinChanged is raised when the cell voltage Min (int) of the battery changed.
    ///
    /// A event name BatteryChargingFlagChanged is raised when the flag battery is charging (bool) changed.
    ///
    /// A event name BatteryFullChargedFlagChanged is raised when the flag battery is full charged (bool) changed.
    ///
    /// A event name BatteryDisChargingFlagChanged is raised when the flag battery is disCharging (bool) changed.
    ///
    /// A event name BatteryLevelChanged is raised when the battery level percentage (int) changed.</summary>
class ALBatteryProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALBatteryProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

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
    /// ALBatteryPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALBatteryProxyPostHandlerRemote() : fParent(NULL)
    {}



    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int exit()
    {
      return fParent->pCall("exit");
    }








    /// <summary>
    /// returns true if the method is currently running
    /// </summary>
    /// <param name="id"> the ID of the method to wait for </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int stop(const int& id)
    {
      return fParent->pCall("stop" , id);
    }



};

}
#endif // ALBATTERYPROXYPOSTHANDLERREMOTE_H_

