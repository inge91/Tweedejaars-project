// Generated for ALBonjour version 1.12


#ifndef ALBONJOURPROXYPOSTHANDLERREMOTE_H_
#define ALBONJOURPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALBonjourProxyRemote;

/// <summary>Advertises the NAOqi service on the local network using the bonjour protocol. Users will not need to call any methods of this module. See the Apple developer documentation for further details about the protocol. http://developer.apple.com/networking/bonjour/</summary>
class ALBonjourProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALBonjourProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// Advertises the NAOqi service on the local network using the bonjour protocol. Users will not need to call any methods of this module. See the Apple developer documentation for further details about the protocol. http://developer.apple.com/networking/bonjour/
    /// ALBonjourPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALBonjourProxyPostHandlerRemote() : fParent(NULL)
    {}



    /// <summary>
    /// Declares the NAOqi service on the local network using the bonjour protocol.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int declare()
    {
      return fParent->pCall("declare");
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
#endif // ALBONJOURPROXYPOSTHANDLERREMOTE_H_

