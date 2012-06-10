// Generated for ALResourceManager version 1.12

#ifndef ALRESOURCEMANAGERPROXYPOSTHANDLER_H_
#define ALRESOURCEMANAGERPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALResourceManagerProxy;

/// <summary>
/// Manage robot resources: Synchronize movement, led, sound. Run specific actions when another behavior wants your resources
/// ALResourceManagerPostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALResourceManagerProxyPostHandler
{
  friend class ALResourceManagerProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// Manage robot resources: Synchronize movement, led, sound. Run specific actions when another behavior wants your resources
  /// ALResourceManagerPostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALResourceManagerProxyPostHandler();

  /// <summary>
  /// Create a resource
  /// </summary>
  /// <param name="resourceName"> Resource name to create </param>
  /// <param name="parentResourceName"> Parent resource name or empty string for root resource </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int createResource(const std::string& resourceName, const std::string& parentResourceName);
  /// <summary>
  /// Delete a root resource
  /// </summary>
  /// <param name="resourceName"> Resource name to delete </param>
  /// <param name="deleteChildResources"> Delete child resources if true </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int deleteResource(const std::string& resourceName, const bool& deleteChildResources);
  /// <summary>
  /// Enable or disable a state resource
  /// </summary>
  /// <param name="resourceName"> The name of the resource that you wish enable of disable. e.g. Standing </param>
  /// <param name="enabled"> True to enable, false to disable </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int enableStateResource(const std::string& resourceName, const bool& enabled);
  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// Release resource
  /// </summary>
  /// <param name="resourceName"> Resource name </param>
  /// <param name="ownerName"> Existing owner name </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int releaseResource(const std::string& resourceName, const std::string& ownerName);
  /// <summary>
  /// Release  resources list
  /// </summary>
  /// <param name="resourceNames"> Resource names </param>
  /// <param name="ownerName"> Owner name </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int releaseResources(const std::vector<std::string>& resourceNames, const std::string& ownerName);
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
  /// <summary>
  /// Wait resource
  /// </summary>
  /// <param name="ressourceName"> Resource name </param>
  /// <param name="ownerName"> Owner name </param>
  /// <param name="callbackName"> callback name </param>
  /// <param name="timeoutSeconds"> Timeout in seconds </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int waitForResource(const std::string& ressourceName, const std::string& ownerName, const std::string& callbackName, const int& timeoutSeconds);
};

}
#endif // ALRESOURCEMANAGERPROXYPOSTHANDLER_H_

