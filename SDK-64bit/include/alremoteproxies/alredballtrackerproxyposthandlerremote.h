// Generated for ALRedBallTracker version 1.12


#ifndef ALREDBALLTRACKERPROXYPOSTHANDLERREMOTE_H_
#define ALREDBALLTRACKERPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALRedBallTrackerProxyRemote;

/// <summary>This module is dedicated to Track a Red Ball expressed in NAO_SPACE.
    ///
    /// This module need ALRedBallDetection module to run.
    ///
    /// Use StartTracker() API to launch the tracking.</summary>
class ALRedBallTrackerProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALRedBallTrackerProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// This module is dedicated to Track a Red Ball expressed in NAO_SPACE.
    ///
    /// This module need ALRedBallDetection module to run.
    ///
    /// Use StartTracker() API to launch the tracking.
    /// ALRedBallTrackerPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALRedBallTrackerProxyPostHandlerRemote() : fParent(NULL)
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
    /// if true, the tracking will be through a Whole Body Process.
    /// </summary>
    /// <param name="pWholeBodyOn"> The whole Body state </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setWholeBodyOn(const bool& pWholeBodyOn)
    {
      return fParent->pCall("setWholeBodyOn" , pWholeBodyOn);
    }

    /// <summary>
    /// Start the tracker by Subscribing to Event redBallDetected from ALRedBallDetection module.
    ///
    /// Then Wait Event redBallDetected from ALRedBallDetection module.
    ///
    /// And finally send information to motion for head tracking.
    ///
    /// NOTE : Stiffness of Head must be set to 1.0 to move!
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int startTracker()
    {
      return fParent->pCall("startTracker");
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
    /// Start the tracker by Unsubscribing to Event redBallDetected from ALRedBallDetection module.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int stopTracker()
    {
      return fParent->pCall("stopTracker");
    }



};

}
#endif // ALREDBALLTRACKERPROXYPOSTHANDLERREMOTE_H_

