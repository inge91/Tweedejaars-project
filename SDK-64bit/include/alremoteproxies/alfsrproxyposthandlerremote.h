// Generated for ALFsr version 1.12


#ifndef ALFSRPROXYPOSTHANDLERREMOTE_H_
#define ALFSRPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALFsrProxyRemote;

/// <summary>Deals with FSR sensors.
    ///
    ///  A MicroEvent is generated when the foot contact changed.
    ///
    /// The ALMemory Key is footContactChanged, its a boolean which is set to \"True\" if one of the foot touched the ground
    ///
    /// Also some fast access Memory key are available : 
    ///
    ///  footContact (1.0f if one of the foot touched the ground)
    ///
    ///  leftFootContact (1.0f if the left foot touched the ground)
    ///
    ///  rightFootContact (1.0f if the right foot touched the ground)
    ///
    ///  leftFootTotalWeight (the average weight on the left foot in Kg)
    ///
    ///  rightFootTotalWeight (the average weight on the right foot in Kg)</summary>
class ALFsrProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALFsrProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// Deals with FSR sensors.
    ///
    ///  A MicroEvent is generated when the foot contact changed.
    ///
    /// The ALMemory Key is footContactChanged, its a boolean which is set to \"True\" if one of the foot touched the ground
    ///
    /// Also some fast access Memory key are available : 
    ///
    ///  footContact (1.0f if one of the foot touched the ground)
    ///
    ///  leftFootContact (1.0f if the left foot touched the ground)
    ///
    ///  rightFootContact (1.0f if the right foot touched the ground)
    ///
    ///  leftFootTotalWeight (the average weight on the left foot in Kg)
    ///
    ///  rightFootTotalWeight (the average weight on the right foot in Kg)
    /// ALFsrPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALFsrProxyPostHandlerRemote() : fParent(NULL)
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
#endif // ALFSRPROXYPOSTHANDLERREMOTE_H_

