// Generated for ALLauncher version 1.12


#ifndef ALLAUNCHERPROXYPOSTHANDLERREMOTE_H_
#define ALLAUNCHERPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALLauncherProxyRemote;

/// <summary>ALlauncher allows to link dynamicaly with library, run executable, unload library, check if module is loaded...</summary>
class ALLauncherProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALLauncherProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// ALlauncher allows to link dynamicaly with library, run executable, unload library, check if module is loaded...
    /// ALLauncherPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALLauncherProxyPostHandlerRemote() : fParent(NULL)
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
#endif // ALLAUNCHERPROXYPOSTHANDLERREMOTE_H_

