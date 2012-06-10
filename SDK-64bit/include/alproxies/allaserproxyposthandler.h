// Generated for ALLaser version 1.12

#ifndef ALLASERPROXYPOSTHANDLER_H_
#define ALLASERPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALLaserProxy;

/// <summary>
/// Allow control over Hokuyo laser when available on Nao's head.
/// ALLaserPostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALLaserProxyPostHandler
{
  friend class ALLaserProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// Allow control over Hokuyo laser when available on Nao's head.
  /// ALLaserPostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALLaserProxyPostHandler();

  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// Disable laser light
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int laserOFF();
  /// <summary>
  /// Enable laser light and sampling
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int laserON();
  /// <summary>
  /// Set detection threshold of the laser
  /// </summary>
  /// <param name="length_min_l"> int containing the min length that the laser will detect(mm), this value must be upper than 20 mm </param>
  /// <param name="length_max_l"> int containing the max length that the laser will detect(mm), this value must be lower than 5600 mm </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setDetectingLength(const AL::ALValue& length_min_l, const AL::ALValue& length_max_l);
  /// <summary>
  /// Set openning angle of the laser
  /// </summary>
  /// <param name="angle_min_f"> float containing the min value in rad, this value must be upper than -2.35619449 </param>
  /// <param name="angle_max_f"> float containing the max value in rad, this value must be lower than 2.092349795 </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setOpeningAngle(const AL::ALValue& angle_min_f, const AL::ALValue& angle_max_f);
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
};

}
#endif // ALLASERPROXYPOSTHANDLER_H_

