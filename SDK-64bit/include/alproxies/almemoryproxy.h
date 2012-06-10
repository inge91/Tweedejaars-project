// Generated for ALMemory version 1.12

#ifndef ALMEMORYPROXY_H_
#define ALMEMORYPROXY_H_
#include <alproxies/almemoryproxyposthandler.h>

namespace AL
{
class ALBroker;
class ALProxy;

class ALMemoryProxyImpl;

/// <summary>ALMemory provides a centralized memory that can be used to store and retrieve named values. It also acts as a hub for the distribution of event notifications.</summary>
/// \ingroup ALProxies
class ALMemoryProxy
{
  private:
    boost::shared_ptr<ALMemoryProxyImpl> fImpl;
    void xInit();

  public:
    /// <summary>
    /// Default Constructor. If there is a broker in your process, which is always the case
    /// if you are in a module, then this will be found and used.
    /// </summary>
    ALMemoryProxy();

    /// <summary>
    /// Explicit Broker Constructor. If you have a smart pointer to a broker that you want
    /// to specify, then you can use this constructor. In most cases, the default constructor
    /// will do the work for you without passing a broker explicitly.
    /// </summary>
    /// <param name="broker">A smart pointer to your broker</param>
    ALMemoryProxy(boost::shared_ptr<ALBroker> broker);

    /// <summary>
    /// Remote Constructor. This constructor allows you to connect to a remote module by
    /// explicit IP address and port. This is useful if you are not within a process that
    /// has a broker, or want to connect to a remote instance of NAOqi such as another
    /// robot.
    /// </summary>
    /// <param name="ip">The IP address of the remote module you want to connect to</param>
    /// <param name="port">The port of the remote module, typically 9559</param>
    ALMemoryProxy(std::string ip, int port=9559);

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALMemoryProxyPostHandler post;

    // --- access to ALProxy ----

    /// <summary>
    /// Gets the underlying generic proxy
    /// </summary>
    boost::shared_ptr<ALProxy> getGenericProxy();

    // ------------------------------

    /// <summary>
    /// Declares an event to allow future subscriptions to the event
    /// </summary>
    /// <param name="eventName"> The name of the event </param>
    void declareEvent(const std::string& eventName);

    /// <summary>
    /// Declares an event to allow future subscriptions to the event
    /// </summary>
    /// <param name="eventName"> The name of the event </param>
    /// <param name="extractorName"> The name of the extractor capable of creating the event </param>
    void declareEvent(const std::string& eventName, const std::string& extractorName);

    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit();

    /// <summary>
    /// Gets the name of the parent broker.
    /// </summary>
    /// <returns> The name of the parent broker. </returns>
    std::string getBrokerName();

    /// <summary>
    /// Gets the value of a key-value pair stored in memory
    /// </summary>
    /// <param name="key"> Name of the value. </param>
    /// <returns> The data as an ALValue. This can often be cast transparently into the original type. </returns>
    AL::ALValue getData(const std::string& key);

    /// <summary>
    /// DEPRECATED - Gets the value of a key-value pair stored in memory. Please use the version of this method with no second parameter.
    /// </summary>
    /// <param name="key"> Name of the value. </param>
    /// <param name="deprecatedParameter"> DEPRECATED - This parameter has no effect, but is left for compatibility reason. </param>
    /// <returns> The data as an ALValue </returns>
    AL::ALValue getData(const std::string& key, const int& deprecatedParameter);

    /// <summary>
    /// Gets a list of all key names that contain a given string
    /// </summary>
    /// <param name="filter"> A string used as the search term </param>
    /// <returns> A list of all the data key names that contain the given string. </returns>
    std::vector<std::string> getDataList(const std::string& filter);

    /// <summary>
    /// Gets the key names for all the key-value pairs in memory
    /// </summary>
    /// <returns> A list containing the keys in memory </returns>
    std::vector<std::string> getDataListName();

    /// <summary>
    /// DEPRECATED - Blocks the caller until the value of a key changes
    /// </summary>
    /// <param name="key"> Name of the data. </param>
    /// <param name="deprecatedParameter"> DEPRECATED - this parameter has no effect </param>
    /// <returns> an array containing all the retrieved data </returns>
    AL::ALValue getDataOnChange(const std::string& key, const int& deprecatedParameter);

    /// <summary>
    /// Gets a pointer to 32 a bit data item. Beware, the pointer will only be valid during the lifetime of the ALMemory object. Use with care, at initialization, not every loop.
    /// </summary>
    /// <param name="key"> Name of the data. </param>
    /// <returns> A pointer converted to int </returns>
    void * getDataPtr(const std::string& key);

    /// <summary>
    /// Gets a list containing the names of all the declared events
    /// </summary>
    /// <returns> A list containing the names of all events </returns>
    std::vector<std::string> getEventList();

    /// <summary>
    /// Gets the list of all events generated by a given extractor
    /// </summary>
    /// <param name="extractorName"> The name of the extractor </param>
    /// <returns> A list containing the names of the events associated with the given extractor </returns>
    std::vector<std::string> getExtractorEvent(const std::string& extractorName);

    /// <summary>
    /// Gets the values associated with the given list of keys. This is more efficient than calling getData many times, especially over the network.
    /// </summary>
    /// <param name="keyList"> An array containing the key names. </param>
    /// <returns> An array containing all the values corresponding to the given keys. </returns>
    AL::ALValue getListData(const AL::ALValue& keyList);

    /// <summary>
    /// Retrieves a method's description.
    /// </summary>
    /// <param name="methodName"> The name of the method. </param>
    /// <returns> A structure containing the method's description. </returns>
    AL::ALValue getMethodHelp(const std::string& methodName);

    /// <summary>
    /// Retrieves the module's method list.
    /// </summary>
    /// <returns> An array of method names. </returns>
    std::vector<std::string> getMethodList();

    /// <summary>
    /// Gets a list containing the names of all the declared micro events
    /// </summary>
    /// <returns> A list containing the names of all the microEvents </returns>
    std::vector<std::string> getMicroEventList();

    /// <summary>
    /// Retrieves the module's description.
    /// </summary>
    /// <returns> A structure describing the module. </returns>
    AL::ALValue getModuleHelp();

    /// <summary>
    /// Gets a list containing the names of subscribers to an event.
    /// </summary>
    /// <param name="name"> Name of the event or micro-event </param>
    /// <returns> List of subscriber names </returns>
    std::vector<std::string> getSubscribers(const std::string& name);

    /// <summary>
    /// Gets the storage class of the stored data. This is not the underlying POD type.
    /// </summary>
    /// <param name="key"> Name of the variable </param>
    /// <returns> String type: Data, Event, MicroEvent </returns>
    std::string getType(const std::string& key);

    /// <summary>
    /// Gets the method usage string. This summarise how to use the method.
    /// </summary>
    /// <param name="name"> The name of the method. </param>
    /// <returns> A string that summarises the usage of the method. </returns>
    std::string getUsage(const std::string& name);

    /// <summary>
    /// Inserts a key-value pair into memory, where value is an int
    /// </summary>
    /// <param name="key"> Name of the value to be inserted. </param>
    /// <param name="value"> The int to be inserted </param>
    void insertData(const std::string& key, const int& value);

    /// <summary>
    /// Inserts a key-value pair into memory, where value is a float
    /// </summary>
    /// <param name="key"> Name of the value to be inserted. </param>
    /// <param name="value"> The float to be inserted </param>
    void insertData(const std::string& key, const float& value);

    /// <summary>
    /// Inserts a key-value pair into memory, where value is a string
    /// </summary>
    /// <param name="key"> Name of the value to be inserted. </param>
    /// <param name="value"> The string to be inserted </param>
    void insertData(const std::string& key, const std::string& value);

    /// <summary>
    /// Inserts a key-value pair into memory, where value is an ALValue
    /// </summary>
    /// <param name="key"> Name of the value to be inserted. </param>
    /// <param name="data"> The ALValue to be inserted. This could contain a basic type, or a more complex array. See the ALValue documentation for more information. </param>
    void insertData(const std::string& key, const AL::ALValue& data);

    /// <summary>
    /// Inserts a list of key-value pairs into memory.
    /// </summary>
    /// <param name="list"> An ALValue list of the form [[Key, Value],...]. Each item will be inserted. </param>
    void insertListData(const AL::ALValue& list);

    /// <summary>
    /// Returns true if the method is currently running.
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <returns> True if the method is currently running </returns>
    bool isRunning(const int& id);

    /// <summary>
    /// Just a ping. Always returns true
    /// </summary>
    /// <returns> returns true </returns>
    bool ping();

    /// <summary>
    /// Publishes the given data to all subscribers.
    /// </summary>
    /// <param name="name"> Name of the event to raise. </param>
    /// <param name="value"> The data associated with the event. This could contain a basic type, or a more complex array. See the ALValue documentation for more information. </param>
    void raiseEvent(const std::string& name, const AL::ALValue& value);

    /// <summary>
    /// Publishes the given data to all subscribers.
    /// </summary>
    /// <param name="name"> Name of the event to raise. </param>
    /// <param name="value"> The data associated with the event. This could contain a basic type, or a more complex array. See the ALValue documentation for more information. </param>
    void raiseMicroEvent(const std::string& name, const AL::ALValue& value);

    /// <summary>
    /// Removes a key-value pair from memory
    /// </summary>
    /// <param name="key"> Name of the data to be removed. </param>
    void removeData(const std::string& key);

    /// <summary>
    /// Removes a micro event from memory and unsubscribes any exiting subscribers.
    /// </summary>
    /// <param name="name"> Name of the event to remove. </param>
    void removeMicroEvent(const std::string& name);

    /// <summary>
    /// returns true if the method is currently running
    /// </summary>
    /// <param name="id"> the ID of the method to wait for </param>
    void stop(const int& id);

    /// <summary>
    /// Subscribes to an event and automaticaly launches the module that declared itself as the generator of the event if required.
    /// </summary>
    /// <param name="name"> The name of the event to subscribe to </param>
    /// <param name="callbackModule"> Name of the module to call with notifications </param>
    /// <param name="callbackMethod"> Name of the module's method to call when a data is changed </param>
    void subscribeToEvent(const std::string& name, const std::string& callbackModule, const std::string& callbackMethod);

    /// <summary>
    /// DEPRECATED Subscribes to event and automaticaly launches the module capable of generating the event if it is not already running. Please use the version without the callbackMessage parameter.
    /// </summary>
    /// <param name="name"> The name of the event to subscribe to </param>
    /// <param name="callbackModule"> Name of the module to call with notifications </param>
    /// <param name="callbackMessage"> DEPRECATED Message included in the notification. </param>
    /// <param name="callbacMethod"> Name of the module's method to call when a data is changed </param>
    void subscribeToEvent(const std::string& name, const std::string& callbackModule, const std::string& callbackMessage, const std::string& callbacMethod);

    /// <summary>
    /// Subscribes to a microEvent. Subscribed modules are notified on theircallback method whenever the data is updated, even if the new value is the same as the old value.
    /// </summary>
    /// <param name="name"> Name of the data. </param>
    /// <param name="callbackModule"> Name of the module to call with notifications </param>
    /// <param name="callbackMessage"> Message included in the notification. This can be used to disambiguate multiple subscriptions. </param>
    /// <param name="callbackMethod"> Name of the module's method to call when a data is changed </param>
    void subscribeToMicroEvent(const std::string& name, const std::string& callbackModule, const std::string& callbackMessage, const std::string& callbackMethod);

    /// <summary>
    /// Informs ALMemory that a module doesn't exist anymore.
    /// </summary>
    /// <param name="moduleName"> Name of the departing module. </param>
    void unregisterModuleReference(const std::string& moduleName);

    /// <summary>
    /// Unsubscribes a module from the given event. No further notifications will be received.
    /// </summary>
    /// <param name="name"> The name of the event </param>
    /// <param name="callbackModule"> The name of the module that was given when subscribing. </param>
    void unsubscribeToEvent(const std::string& name, const std::string& callbackModule);

    /// <summary>
    /// Unsubscribes from the given event. No further notifications will be received.
    /// </summary>
    /// <param name="name"> Name of the event. </param>
    /// <param name="callbackModule"> The name of the module that was given when subscribing. </param>
    void unsubscribeToMicroEvent(const std::string& name, const std::string& callbackModule);

    /// <summary>
    /// Returns the version of the module.
    /// </summary>
    /// <returns> A string containing the version of the module. </returns>
    std::string version();

    /// <summary>
    /// Wait for the end of a long running method that was called using 'post'
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <param name="timeoutPeriod"> The timeout period in ms. To wait indefinately, use a timeoutPeriod of zero. </param>
    /// <returns> True if the timeout period terminated. False if the method returned. </returns>
    bool wait(const int& id, const int& timeoutPeriod);

};

}
#endif // ALMEMORYPROXY_H_

