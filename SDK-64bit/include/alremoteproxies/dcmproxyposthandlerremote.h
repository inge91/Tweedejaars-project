// Generated for DCM version 


#ifndef DCMPROXYPOSTHANDLERREMOTE_H_
#define DCMPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class DCMProxyRemote;

/// <summary>Manage link with devices (sensors and actuators). See specific documentation.</summary>
class DCMProxyPostHandlerRemote : public ALProxyRemote
{
    friend class DCMProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// Manage link with devices (sensors and actuators). See specific documentation.
    /// DCMPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    DCMProxyPostHandlerRemote() : fParent(NULL)
    {}



    /// <summary>
    /// Calibration of a joint
    /// </summary>
    /// <param name="calibrationInput"> A complex ALValue. See red documentation </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int calibration(const AL::ALValue& calibrationInput)
    {
      return fParent->pCall("calibration" , calibrationInput);
    }


    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int exit()
    {
      return fParent->pCall("exit");
    }











    /// <summary>
    /// Call this function to send a timed-command list to an actuator
    /// </summary>
    /// <param name="commands"> AL::ALValue with all data </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int set(const AL::ALValue& commands)
    {
      return fParent->pCall("set" , commands);
    }

    /// <summary>
    /// Call this function to send timed-command list to an alias (list of actuators)
    /// </summary>
    /// <param name="commands"> AL::ALValue with all data </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setAlias(const AL::ALValue& commands)
    {
      return fParent->pCall("setAlias" , commands);
    }

    /// <summary>
    /// Special DCM commands
    /// </summary>
    /// <param name="result"> one string and could be Reset, Version, Chain, Diagnostic, Config </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int special(const std::string& result)
    {
      return fParent->pCall("special" , result);
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
#endif // DCMPROXYPOSTHANDLERREMOTE_H_

