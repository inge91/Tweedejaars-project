// Generated for ALMemory version 1.12

#ifndef ALMEMORYPROXYPOSTHANDLER_H_
#define ALMEMORYPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALMemoryProxy;

/// <summary>
/// ALMemory provides a centralized memory that can be used to store and retrieve named values. It also acts as a hub for the distribution of event notifications.
/// ALMemoryPostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALMemoryProxyPostHandler
{
  friend class ALMemoryProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// ALMemory provides a centralized memory that can be used to store and retrieve named values. It also acts as a hub for the distribution of event notifications.
  /// ALMemoryPostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALMemoryProxyPostHandler();

  /// <summary>
  /// Declares an event to allow future subscriptions to the event
  /// </summary>
  /// <param name="eventName"> The name of the event </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int declareEvent(const std::string& eventName);
  /// <summary>
  /// Declares an event to allow future subscriptions to the event
  /// </summary>
  /// <param name="eventName"> The name of the event </param>
  /// <param name="extractorName"> The name of the extractor capable of creating the event </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int declareEvent(const std::string& eventName, const std::string& extractorName);
  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// Inserts a key-value pair into memory, where value is an int
  /// </summary>
  /// <param name="key"> Name of the value to be inserted. </param>
  /// <param name="value"> The int to be inserted </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int insertData(const std::string& key, const int& value);
  /// <summary>
  /// Inserts a key-value pair into memory, where value is a float
  /// </summary>
  /// <param name="key"> Name of the value to be inserted. </param>
  /// <param name="value"> The float to be inserted </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int insertData(const std::string& key, const float& value);
  /// <summary>
  /// Inserts a key-value pair into memory, where value is a string
  /// </summary>
  /// <param name="key"> Name of the value to be inserted. </param>
  /// <param name="value"> The string to be inserted </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int insertData(const std::string& key, const std::string& value);
  /// <summary>
  /// Inserts a key-value pair into memory, where value is an ALValue
  /// </summary>
  /// <param name="key"> Name of the value to be inserted. </param>
  /// <param name="data"> The ALValue to be inserted. This could contain a basic type, or a more complex array. See the ALValue documentation for more information. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int insertData(const std::string& key, const AL::ALValue& data);
  /// <summary>
  /// Inserts a list of key-value pairs into memory.
  /// </summary>
  /// <param name="list"> An ALValue list of the form [[Key, Value],...]. Each item will be inserted. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int insertListData(const AL::ALValue& list);
  /// <summary>
  /// Publishes the given data to all subscribers.
  /// </summary>
  /// <param name="name"> Name of the event to raise. </param>
  /// <param name="value"> The data associated with the event. This could contain a basic type, or a more complex array. See the ALValue documentation for more information. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int raiseEvent(const std::string& name, const AL::ALValue& value);
  /// <summary>
  /// Publishes the given data to all subscribers.
  /// </summary>
  /// <param name="name"> Name of the event to raise. </param>
  /// <param name="value"> The data associated with the event. This could contain a basic type, or a more complex array. See the ALValue documentation for more information. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int raiseMicroEvent(const std::string& name, const AL::ALValue& value);
  /// <summary>
  /// Removes a key-value pair from memory
  /// </summary>
  /// <param name="key"> Name of the data to be removed. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int removeData(const std::string& key);
  /// <summary>
  /// Removes a micro event from memory and unsubscribes any exiting subscribers.
  /// </summary>
  /// <param name="name"> Name of the event to remove. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int removeMicroEvent(const std::string& name);
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
  /// <summary>
  /// Subscribes to an event and automaticaly launches the module that declared itself as the generator of the event if required.
  /// </summary>
  /// <param name="name"> The name of the event to subscribe to </param>
  /// <param name="callbackModule"> Name of the module to call with notifications </param>
  /// <param name="callbackMethod"> Name of the module's method to call when a data is changed </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int subscribeToEvent(const std::string& name, const std::string& callbackModule, const std::string& callbackMethod);
  /// <summary>
  /// DEPRECATED Subscribes to event and automaticaly launches the module capable of generating the event if it is not already running. Please use the version without the callbackMessage parameter.
  /// </summary>
  /// <param name="name"> The name of the event to subscribe to </param>
  /// <param name="callbackModule"> Name of the module to call with notifications </param>
  /// <param name="callbackMessage"> DEPRECATED Message included in the notification. </param>
  /// <param name="callbacMethod"> Name of the module's method to call when a data is changed </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int subscribeToEvent(const std::string& name, const std::string& callbackModule, const std::string& callbackMessage, const std::string& callbacMethod);
  /// <summary>
  /// Subscribes to a microEvent. Subscribed modules are notified on theircallback method whenever the data is updated, even if the new value is the same as the old value.
  /// </summary>
  /// <param name="name"> Name of the data. </param>
  /// <param name="callbackModule"> Name of the module to call with notifications </param>
  /// <param name="callbackMessage"> Message included in the notification. This can be used to disambiguate multiple subscriptions. </param>
  /// <param name="callbackMethod"> Name of the module's method to call when a data is changed </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int subscribeToMicroEvent(const std::string& name, const std::string& callbackModule, const std::string& callbackMessage, const std::string& callbackMethod);
  /// <summary>
  /// Informs ALMemory that a module doesn't exist anymore.
  /// </summary>
  /// <param name="moduleName"> Name of the departing module. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int unregisterModuleReference(const std::string& moduleName);
  /// <summary>
  /// Unsubscribes a module from the given event. No further notifications will be received.
  /// </summary>
  /// <param name="name"> The name of the event </param>
  /// <param name="callbackModule"> The name of the module that was given when subscribing. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int unsubscribeToEvent(const std::string& name, const std::string& callbackModule);
  /// <summary>
  /// Unsubscribes from the given event. No further notifications will be received.
  /// </summary>
  /// <param name="name"> Name of the event. </param>
  /// <param name="callbackModule"> The name of the module that was given when subscribing. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int unsubscribeToMicroEvent(const std::string& name, const std::string& callbackModule);
};

}
#endif // ALMEMORYPROXYPOSTHANDLER_H_

