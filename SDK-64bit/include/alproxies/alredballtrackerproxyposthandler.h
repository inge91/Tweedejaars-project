// Generated for ALRedBallTracker version 1.12

#ifndef ALREDBALLTRACKERPROXYPOSTHANDLER_H_
#define ALREDBALLTRACKERPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALRedBallTrackerProxy;

/// <summary>
/// This module is dedicated to Track a Red Ball expressed in NAO_SPACE.
    ///
    /// This module need ALRedBallDetection module to run.
    ///
    /// Use StartTracker() API to launch the tracking.
/// ALRedBallTrackerPostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALRedBallTrackerProxyPostHandler
{
  friend class ALRedBallTrackerProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// This module is dedicated to Track a Red Ball expressed in NAO_SPACE.
    ///
    /// This module need ALRedBallDetection module to run.
    ///
    /// Use StartTracker() API to launch the tracking.
  /// ALRedBallTrackerPostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALRedBallTrackerProxyPostHandler();

  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// if true, the tracking will be through a Whole Body Process.
  /// </summary>
  /// <param name="pWholeBodyOn"> The whole Body state </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setWholeBodyOn(const bool& pWholeBodyOn);
  /// <summary>
  /// Start the tracker by Subscribing to Event redBallDetected from ALRedBallDetection module.
    ///
    /// Then Wait Event redBallDetected from ALRedBallDetection module.
    ///
    /// And finally send information to motion for head tracking.
    ///
    /// NOTE : Stiffness of Head must be set to 1.0 to move!
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int startTracker();
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
  /// <summary>
  /// Start the tracker by Unsubscribing to Event redBallDetected from ALRedBallDetection module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stopTracker();
};

}
#endif // ALREDBALLTRACKERPROXYPOSTHANDLER_H_

