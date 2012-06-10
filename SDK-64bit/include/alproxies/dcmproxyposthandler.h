// Generated for DCM version 

#ifndef DCMPROXYPOSTHANDLER_H_
#define DCMPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class DCMProxy;

/// <summary>
/// Manage link with devices (sensors and actuators). See specific documentation.
/// DCMPostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class DCMProxyPostHandler
{
  friend class DCMProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// Manage link with devices (sensors and actuators). See specific documentation.
  /// DCMPostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  DCMProxyPostHandler();

  /// <summary>
  /// Calibration of a joint
  /// </summary>
  /// <param name="calibrationInput"> A complex ALValue. See red documentation </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int calibration(const AL::ALValue& calibrationInput);
  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// Call this function to send a timed-command list to an actuator
  /// </summary>
  /// <param name="commands"> AL::ALValue with all data </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int set(const AL::ALValue& commands);
  /// <summary>
  /// Call this function to send timed-command list to an alias (list of actuators)
  /// </summary>
  /// <param name="commands"> AL::ALValue with all data </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setAlias(const AL::ALValue& commands);
  /// <summary>
  /// Special DCM commands
  /// </summary>
  /// <param name="result"> one string and could be Reset, Version, Chain, Diagnostic, Config </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int special(const std::string& result);
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
};

}
#endif // DCMPROXYPOSTHANDLER_H_

