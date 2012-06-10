// Generated for ALBehaviorManager version 1.12

#ifndef ALBEHAVIORMANAGERPROXYPOSTHANDLER_H_
#define ALBEHAVIORMANAGERPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALBehaviorManagerProxy;

/// <summary>
/// This module is intended to manage behaviors. With this module, you can load, start, stop behaviors, add default behaviors or remove them.
/// ALBehaviorManagerPostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALBehaviorManagerProxyPostHandler
{
  friend class ALBehaviorManagerProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// This module is intended to manage behaviors. With this module, you can load, start, stop behaviors, add default behaviors or remove them.
  /// ALBehaviorManagerPostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALBehaviorManagerProxyPostHandler();

  /// <summary>
  /// Set the given behavior as default
  /// </summary>
  /// <param name="behavior"> Behavior name </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int addDefaultBehavior(const std::string& behavior);
  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// Play default behaviors
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int playDefaultProject();
  /// <summary>
  /// Remove the given behavior from the default behaviors
  /// </summary>
  /// <param name="behavior"> Behavior name </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int removeDefaultBehavior(const std::string& behavior);
  /// <summary>
  /// Run a behavior
  /// </summary>
  /// <param name="behavior"> Behavior name </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int runBehavior(const std::string& behavior);
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
  /// <summary>
  /// Stop all behaviors
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stopAllBehaviors();
  /// <summary>
  /// Stop a behavior
  /// </summary>
  /// <param name="behavior"> Behavior name </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stopBehavior(const std::string& behavior);
};

}
#endif // ALBEHAVIORMANAGERPROXYPOSTHANDLER_H_

