// Generated for ALRobotPose version 1.12

#ifndef ALROBOTPOSEPROXYPOSTHANDLER_H_
#define ALROBOTPOSEPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALRobotPoseProxy;

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
/// ALRobotPosePostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALRobotPoseProxyPostHandler
{
  friend class ALRobotPoseProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

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
  /// ALRobotPosePostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALRobotPoseProxyPostHandler();

  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
};

}
#endif // ALROBOTPOSEPROXYPOSTHANDLER_H_

