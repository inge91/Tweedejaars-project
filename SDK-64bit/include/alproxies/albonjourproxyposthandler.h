// Generated for ALBonjour version 1.12

#ifndef ALBONJOURPROXYPOSTHANDLER_H_
#define ALBONJOURPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALBonjourProxy;

/// <summary>
/// Advertises the NAOqi service on the local network using the bonjour protocol. Users will not need to call any methods of this module. See the Apple developer documentation for further details about the protocol. http://developer.apple.com/networking/bonjour/
/// ALBonjourPostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALBonjourProxyPostHandler
{
  friend class ALBonjourProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// Advertises the NAOqi service on the local network using the bonjour protocol. Users will not need to call any methods of this module. See the Apple developer documentation for further details about the protocol. http://developer.apple.com/networking/bonjour/
  /// ALBonjourPostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALBonjourProxyPostHandler();

  /// <summary>
  /// Declares the NAOqi service on the local network using the bonjour protocol.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int declare();
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
#endif // ALBONJOURPROXYPOSTHANDLER_H_

