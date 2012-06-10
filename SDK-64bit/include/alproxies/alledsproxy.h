// Generated for ALLeds version 1.12

#ifndef ALLEDSPROXY_H_
#define ALLEDSPROXY_H_
#include <alproxies/alledsproxyposthandler.h>

namespace AL
{
class ALBroker;
class ALProxy;

class ALLedsProxyImpl;

/// <summary>This module allows you to control NAO's LEDs. It provides simple ways of setting or fading the intensity of single LEDs and groups of LEDs. 
    ///
    /// Groups of LEDs typically include face LEDs, ear LEDs, chest LEDs etc. It is also possible to control each LED separately (for example, each of the 8 LEDs in one NAO's eyes).
    ///
    /// There are three primary colors of LEDs available - red, green and blue, so it is possible to combine them to obtain different colors. The ears contain blue LEDs only.
    ///
    /// It is possible to control the LED's intensity (between 0 and 100%).</summary>
/// \ingroup ALProxies
class ALLedsProxy
{
  private:
    boost::shared_ptr<ALLedsProxyImpl> fImpl;
    void xInit();

  public:
    /// <summary>
    /// Default Constructor. If there is a broker in your process, which is always the case
    /// if you are in a module, then this will be found and used.
    /// </summary>
    ALLedsProxy();

    /// <summary>
    /// Explicit Broker Constructor. If you have a smart pointer to a broker that you want
    /// to specify, then you can use this constructor. In most cases, the default constructor
    /// will do the work for you without passing a broker explicitly.
    /// </summary>
    /// <param name="broker">A smart pointer to your broker</param>
    ALLedsProxy(boost::shared_ptr<ALBroker> broker);

    /// <summary>
    /// Remote Constructor. This constructor allows you to connect to a remote module by
    /// explicit IP address and port. This is useful if you are not within a process that
    /// has a broker, or want to connect to a remote instance of NAOqi such as another
    /// robot.
    /// </summary>
    /// <param name="ip">The IP address of the remote module you want to connect to</param>
    /// <param name="port">The port of the remote module, typically 9559</param>
    ALLedsProxy(std::string ip, int port=9559);

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALLedsProxyPostHandler post;

    // --- access to ALProxy ----

    /// <summary>
    /// Gets the underlying generic proxy
    /// </summary>
    boost::shared_ptr<ALProxy> getGenericProxy();

    // ------------------------------

    /// <summary>
    /// Makes a group name for ease of setting multiple LEDs.
    /// </summary>
    /// <param name="groupName"> The name of the group. </param>
    /// <param name="ledNames"> A vector of the names of the LEDs in the group. </param>
    void createGroup(const std::string& groupName, const std::vector<std::string>& ledNames);

    /// <summary>
    /// An animation to show a direction with the ears.
    /// </summary>
    /// <param name="degrees"> The angle you want to show in degrees (int). 0 is up, 90 is forwards, 180 is down and 270 is back. </param>
    /// <param name="duration"> The duration in seconds of the animation. </param>
    /// <param name="leaveOnAtEnd"> If true the last led is left on at the end of the animation. </param>
    void earLedsSetAngle(const int& degrees, const float& duration, const bool& leaveOnAtEnd);

    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit();

    /// <summary>
    /// Sets the intensity of a LED or Group of LEDs within a given time.
    /// </summary>
    /// <param name="name"> The name of the LED or Group. </param>
    /// <param name="intensity"> The intensity of the LED or Group (a value between 0 and 1). </param>
    /// <param name="duration"> The duration of the fade in seconds </param>
    void fade(const std::string& name, const float& intensity, const float& duration);

    /// <summary>
    /// Chain a list of color for a device, as the motion.doMove command.
    /// </summary>
    /// <param name="name"> The name of the LED or Group. </param>
    /// <param name="rgbList"> List of RGB led value, RGB as seen in hexa-decimal: 0x00RRGGBB. </param>
    /// <param name="timeList"> List of time to go to given intensity. </param>
    void fadeListRGB(const std::string& name, const AL::ALValue& rgbList, const AL::ALValue& timeList);

    /// <summary>
    /// Sets the intensity of a led. If the name matches an RGB led, all channels are set to the same value.
    /// </summary>
    /// <param name="name"> The name of the LED or Group. </param>
    /// <param name="rgb"> The RGB value led, RGB as seen in hexa-decimal: 0x00RRGGBB. </param>
    /// <param name="duration"> Time used to fade in seconds. </param>
    void fadeRGB(const std::string& name, const int& rgb, const float& duration);

    /// <summary>
    /// Gets the name of the parent broker.
    /// </summary>
    /// <returns> The name of the parent broker. </returns>
    std::string getBrokerName();

    /// <summary>
    /// Gets the intensity of a LED or device
    /// </summary>
    /// <param name="name"> The name of the LED or Group. </param>
    /// <returns> The intensity of the LED or Group. </returns>
    AL::ALValue getIntensity(const std::string& name);

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
    /// Retrieves the module's description.
    /// </summary>
    /// <returns> A structure describing the module. </returns>
    AL::ALValue getModuleHelp();

    /// <summary>
    /// Gets the method usage string. This summarise how to use the method.
    /// </summary>
    /// <param name="name"> The name of the method. </param>
    /// <returns> A string that summarises the usage of the method. </returns>
    std::string getUsage(const std::string& name);

    /// <summary>
    /// Returns true if the method is currently running.
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <returns> True if the method is currently running </returns>
    bool isRunning(const int& id);

    /// <summary>
    /// Lists the devices in the group.
    /// </summary>
    /// <param name="groupName"> The name of the Group. </param>
    /// <returns> A vector of string device names. </returns>
    std::vector<std::string> listGroup(const std::string& groupName);

    /// <summary>
    /// Lists available group names.
    /// </summary>
    /// <returns> A vector of group names. </returns>
    std::vector<std::string> listGroups();

    /// <summary>
    /// Lists the devices aliased by a short LED name.
    /// </summary>
    /// <param name="name"> The name of the LED to list </param>
    /// <returns> A vector of device names. </returns>
    std::vector<std::string> listLED(const std::string& name);

    /// <summary>
    /// Lists the short LED names.
    /// </summary>
    /// <returns> A vector of LED names. </returns>
    std::vector<std::string> listLEDs();

    /// <summary>
    /// Switch to a minimum intensity a LED or Group of LEDs.
    /// </summary>
    /// <param name="name"> The name of the LED or Group. </param>
    void off(const std::string& name);

    /// <summary>
    /// Switch to a maximum intensity a LED or Group of LEDs.
    /// </summary>
    /// <param name="name"> The name of the LED or Group. </param>
    void on(const std::string& name);

    /// <summary>
    /// Just a ping. Always returns true
    /// </summary>
    /// <returns> returns true </returns>
    bool ping();

    /// <summary>
    /// Launch a random animation in eyes
    /// </summary>
    /// <param name="duration"> Approximate duration of the animation in seconds. </param>
    void randomEyes(const float& duration);

    /// <summary>
    /// Launch a green/yellow/red rasta animation on all body.
    /// </summary>
    /// <param name="duration"> Approximate duration of the animation in seconds. </param>
    void rasta(const float& duration);

    /// <summary>
    /// Launch a rotation using the leds of the eyes.
    /// </summary>
    /// <param name="rgb"> the RGB value led, RGB as seen in hexa-decimal: 0x00RRGGBB. </param>
    /// <param name="timeForRotation"> Approximate time to make one turn. </param>
    /// <param name="totalDuration"> Approximate duration of the animation in seconds. </param>
    void rotateEyes(const int& rgb, const float& timeForRotation, const float& totalDuration);

    /// <summary>
    /// Sets the intensity of a LED or Group of LEDs.
    /// </summary>
    /// <param name="name"> The name of the LED or Group. </param>
    /// <param name="intensity"> The intensity of the LED or Group (a value between 0 and 1). </param>
    void setIntensity(const std::string& name, const float& intensity);

    /// <summary>
    /// returns true if the method is currently running
    /// </summary>
    /// <param name="id"> the ID of the method to wait for </param>
    void stop(const int& id);

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
#endif // ALLEDSPROXY_H_

