// Generated for ALRobotPose version 1.12


#ifndef ALROBOTPOSEPROXYPOSTHANDLERREMOTE_H_
#define ALROBOTPOSEPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALRobotPoseProxyRemote;

/// <summary>This module give the estimated Nao PoseDetects. 
    ///
    /// .A MicroEvent is generated when the robot pose changed. A temporization of 500ms is apply before generated this MicroEvent.
    ///
    /// The ALMemory Key is robotPoseChanged, its a string corresponding to the actual robot Pose.
    ///
    /// Also some fast access Memory key are available : 
    ///
    ///  robotPose An integer in relation with the actual pose(use getPoseNames() to have a relation between int and string)
    ///
    ///  robotPoseSince A float corresponding to the time in second since the actual Pose is active.</summary>
class ALRobotPoseProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALRobotPoseProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// This module give the estimated Nao PoseDetects. 
    ///
    /// .A MicroEvent is generated when the robot pose changed. A temporization of 500ms is apply before generated this MicroEvent.
    ///
    /// The ALMemory Key is robotPoseChanged, its a string corresponding to the actual robot Pose.
    ///
    /// Also some fast access Memory key are available : 
    ///
    ///  robotPose An integer in relation with the actual pose(use getPoseNames() to have a relation between int and string)
    ///
    ///  robotPoseSince A float corresponding to the time in second since the actual Pose is active.
    /// ALRobotPosePostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALRobotPoseProxyPostHandlerRemote() : fParent(NULL)
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
#endif // ALROBOTPOSEPROXYPOSTHANDLERREMOTE_H_

