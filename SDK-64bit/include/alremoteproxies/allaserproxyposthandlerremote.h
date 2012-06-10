// Generated for ALLaser version 1.12


#ifndef ALLASERPROXYPOSTHANDLERREMOTE_H_
#define ALLASERPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALLaserProxyRemote;

/// <summary>Allow control over Hokuyo laser when available on Nao's head.</summary>
class ALLaserProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALLaserProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// Allow control over Hokuyo laser when available on Nao's head.
    /// ALLaserPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALLaserProxyPostHandlerRemote() : fParent(NULL)
    {}



    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int exit()
    {
      return fParent->pCall("exit");
    }







    /// <summary>
    /// Disable laser light
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int laserOFF()
    {
      return fParent->pCall("laserOFF");
    }

    /// <summary>
    /// Enable laser light and sampling
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int laserON()
    {
      return fParent->pCall("laserON");
    }


    /// <summary>
    /// Set detection threshold of the laser
    /// </summary>
    /// <param name="length_min_l"> int containing the min length that the laser will detect(mm), this value must be upper than 20 mm </param>
    /// <param name="length_max_l"> int containing the max length that the laser will detect(mm), this value must be lower than 5600 mm </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setDetectingLength(const AL::ALValue& length_min_l, const AL::ALValue& length_max_l)
    {
      return fParent->pCall("setDetectingLength" , length_min_l, length_max_l);
    }

    /// <summary>
    /// Set openning angle of the laser
    /// </summary>
    /// <param name="angle_min_f"> float containing the min value in rad, this value must be upper than -2.35619449 </param>
    /// <param name="angle_max_f"> float containing the max value in rad, this value must be lower than 2.092349795 </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setOpeningAngle(const AL::ALValue& angle_min_f, const AL::ALValue& angle_max_f)
    {
      return fParent->pCall("setOpeningAngle" , angle_min_f, angle_max_f);
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
#endif // ALLASERPROXYPOSTHANDLERREMOTE_H_

