// Generated for ALLeds version 1.12


#ifndef ALLEDSPROXYPOSTHANDLERREMOTE_H_
#define ALLEDSPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALLedsProxyRemote;

/// <summary>This module allows you to control NAO's LEDs. It provides simple ways of setting or fading the intensity of single LEDs and groups of LEDs. 
    ///
    /// Groups of LEDs typically include face LEDs, ear LEDs, chest LEDs etc. It is also possible to control each LED separately (for example, each of the 8 LEDs in one NAO's eyes).
    ///
    /// There are three primary colors of LEDs available - red, green and blue, so it is possible to combine them to obtain different colors. The ears contain blue LEDs only.
    ///
    /// It is possible to control the LED's intensity (between 0 and 100%).</summary>
class ALLedsProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALLedsProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// This module allows you to control NAO's LEDs. It provides simple ways of setting or fading the intensity of single LEDs and groups of LEDs. 
    ///
    /// Groups of LEDs typically include face LEDs, ear LEDs, chest LEDs etc. It is also possible to control each LED separately (for example, each of the 8 LEDs in one NAO's eyes).
    ///
    /// There are three primary colors of LEDs available - red, green and blue, so it is possible to combine them to obtain different colors. The ears contain blue LEDs only.
    ///
    /// It is possible to control the LED's intensity (between 0 and 100%).
    /// ALLedsPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALLedsProxyPostHandlerRemote() : fParent(NULL)
    {}



    /// <summary>
    /// Makes a group name for ease of setting multiple LEDs.
    /// </summary>
    /// <param name="groupName"> The name of the group. </param>
    /// <param name="ledNames"> A vector of the names of the LEDs in the group. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int createGroup(const std::string& groupName, const std::vector<std::string>& ledNames)
    {
      return fParent->pCall("createGroup" , groupName, ledNames);
    }

    /// <summary>
    /// An animation to show a direction with the ears.
    /// </summary>
    /// <param name="degrees"> The angle you want to show in degrees (int). 0 is up, 90 is forwards, 180 is down and 270 is back. </param>
    /// <param name="duration"> The duration in seconds of the animation. </param>
    /// <param name="leaveOnAtEnd"> If true the last led is left on at the end of the animation. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int earLedsSetAngle(const int& degrees, const float& duration, const bool& leaveOnAtEnd)
    {
      return fParent->pCall("earLedsSetAngle" , degrees, duration, leaveOnAtEnd);
    }

    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int exit()
    {
      return fParent->pCall("exit");
    }

    /// <summary>
    /// Sets the intensity of a LED or Group of LEDs within a given time.
    /// </summary>
    /// <param name="name"> The name of the LED or Group. </param>
    /// <param name="intensity"> The intensity of the LED or Group (a value between 0 and 1). </param>
    /// <param name="duration"> The duration of the fade in seconds </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int fade(const std::string& name, const float& intensity, const float& duration)
    {
      return fParent->pCall("fade" , name, intensity, duration);
    }

    /// <summary>
    /// Chain a list of color for a device, as the motion.doMove command.
    /// </summary>
    /// <param name="name"> The name of the LED or Group. </param>
    /// <param name="rgbList"> List of RGB led value, RGB as seen in hexa-decimal: 0x00RRGGBB. </param>
    /// <param name="timeList"> List of time to go to given intensity. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int fadeListRGB(const std::string& name, const AL::ALValue& rgbList, const AL::ALValue& timeList)
    {
      return fParent->pCall("fadeListRGB" , name, rgbList, timeList);
    }

    /// <summary>
    /// Sets the intensity of a led. If the name matches an RGB led, all channels are set to the same value.
    /// </summary>
    /// <param name="name"> The name of the LED or Group. </param>
    /// <param name="rgb"> The RGB value led, RGB as seen in hexa-decimal: 0x00RRGGBB. </param>
    /// <param name="duration"> Time used to fade in seconds. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int fadeRGB(const std::string& name, const int& rgb, const float& duration)
    {
      return fParent->pCall("fadeRGB" , name, rgb, duration);
    }












    /// <summary>
    /// Switch to a minimum intensity a LED or Group of LEDs.
    /// </summary>
    /// <param name="name"> The name of the LED or Group. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int off(const std::string& name)
    {
      return fParent->pCall("off" , name);
    }

    /// <summary>
    /// Switch to a maximum intensity a LED or Group of LEDs.
    /// </summary>
    /// <param name="name"> The name of the LED or Group. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int on(const std::string& name)
    {
      return fParent->pCall("on" , name);
    }


    /// <summary>
    /// Launch a random animation in eyes
    /// </summary>
    /// <param name="duration"> Approximate duration of the animation in seconds. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int randomEyes(const float& duration)
    {
      return fParent->pCall("randomEyes" , duration);
    }

    /// <summary>
    /// Launch a green/yellow/red rasta animation on all body.
    /// </summary>
    /// <param name="duration"> Approximate duration of the animation in seconds. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int rasta(const float& duration)
    {
      return fParent->pCall("rasta" , duration);
    }

    /// <summary>
    /// Launch a rotation using the leds of the eyes.
    /// </summary>
    /// <param name="rgb"> the RGB value led, RGB as seen in hexa-decimal: 0x00RRGGBB. </param>
    /// <param name="timeForRotation"> Approximate time to make one turn. </param>
    /// <param name="totalDuration"> Approximate duration of the animation in seconds. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int rotateEyes(const int& rgb, const float& timeForRotation, const float& totalDuration)
    {
      return fParent->pCall("rotateEyes" , rgb, timeForRotation, totalDuration);
    }

    /// <summary>
    /// Sets the intensity of a LED or Group of LEDs.
    /// </summary>
    /// <param name="name"> The name of the LED or Group. </param>
    /// <param name="intensity"> The intensity of the LED or Group (a value between 0 and 1). </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setIntensity(const std::string& name, const float& intensity)
    {
      return fParent->pCall("setIntensity" , name, intensity);
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
#endif // ALLEDSPROXYPOSTHANDLERREMOTE_H_

