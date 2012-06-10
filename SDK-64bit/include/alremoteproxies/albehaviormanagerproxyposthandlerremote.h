// Generated for ALBehaviorManager version 1.12


#ifndef ALBEHAVIORMANAGERPROXYPOSTHANDLERREMOTE_H_
#define ALBEHAVIORMANAGERPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALBehaviorManagerProxyRemote;

/// <summary>This module is intended to manage behaviors. With this module, you can load, start, stop behaviors, add default behaviors or remove them.</summary>
class ALBehaviorManagerProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALBehaviorManagerProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// This module is intended to manage behaviors. With this module, you can load, start, stop behaviors, add default behaviors or remove them.
    /// ALBehaviorManagerPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALBehaviorManagerProxyPostHandlerRemote() : fParent(NULL)
    {}



    /// <summary>
    /// Set the given behavior as default
    /// </summary>
    /// <param name="behavior"> Behavior name </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int addDefaultBehavior(const std::string& behavior)
    {
      return fParent->pCall("addDefaultBehavior" , behavior);
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
    /// Play default behaviors
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int playDefaultProject()
    {
      return fParent->pCall("playDefaultProject");
    }



    /// <summary>
    /// Remove the given behavior from the default behaviors
    /// </summary>
    /// <param name="behavior"> Behavior name </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int removeDefaultBehavior(const std::string& behavior)
    {
      return fParent->pCall("removeDefaultBehavior" , behavior);
    }

    /// <summary>
    /// Run a behavior
    /// </summary>
    /// <param name="behavior"> Behavior name </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int runBehavior(const std::string& behavior)
    {
      return fParent->pCall("runBehavior" , behavior);
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

    /// <summary>
    /// Stop all behaviors
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int stopAllBehaviors()
    {
      return fParent->pCall("stopAllBehaviors");
    }

    /// <summary>
    /// Stop a behavior
    /// </summary>
    /// <param name="behavior"> Behavior name </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int stopBehavior(const std::string& behavior)
    {
      return fParent->pCall("stopBehavior" , behavior);
    }



};

}
#endif // ALBEHAVIORMANAGERPROXYPOSTHANDLERREMOTE_H_

