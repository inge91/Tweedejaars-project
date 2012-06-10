// Generated for ALFaceTracker version 1.12


#ifndef ALFACETRACKERPROXYPOSTHANDLERREMOTE_H_
#define ALFACETRACKERPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALFaceTrackerProxyRemote;

/// <summary>This module is dedicated to track a face. When activated, Nao will move its head to follow the detected face.
    ///
    ///  This module relies on ALFaceDetection, so be sure it is loaded on your robot.</summary>
class ALFaceTrackerProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALFaceTrackerProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// This module is dedicated to track a face. When activated, Nao will move its head to follow the detected face.
    ///
    ///  This module relies on ALFaceDetection, so be sure it is loaded on your robot.
    /// ALFaceTrackerPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALFaceTrackerProxyPostHandlerRemote() : fParent(NULL)
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
    /// Start the tracker by Subscribing to Event FaceDetected from ALFaceDetection module.
    ///
    /// Then Wait Event FaceDetected from ALFaceDetection module.
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
    /// Start the tracker by Unsubscribing to Event FaceDetected from ALFaceDetection module.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int stopTracker()
    {
      return fParent->pCall("stopTracker");
    }



};

}
#endif // ALFACETRACKERPROXYPOSTHANDLERREMOTE_H_

