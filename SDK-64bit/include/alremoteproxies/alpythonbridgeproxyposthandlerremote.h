// Generated for ALPythonBridge version 1.12


#ifndef ALPYTHONBRIDGEPROXYPOSTHANDLERREMOTE_H_
#define ALPYTHONBRIDGEPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALPythonBridgeProxyRemote;

/// <summary>This module evaluates python commands on the fly.</summary>
class ALPythonBridgeProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALPythonBridgeProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// This module evaluates python commands on the fly.
    /// ALPythonBridgePostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALPythonBridgeProxyPostHandlerRemote() : fParent(NULL)
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
#endif // ALPYTHONBRIDGEPROXYPOSTHANDLERREMOTE_H_

