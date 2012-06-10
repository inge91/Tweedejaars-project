// Generated for ALVisionToolbox version 1.12

#ifndef ALVISIONTOOLBOXPROXYPOSTHANDLER_H_
#define ALVISIONTOOLBOXPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALVisionToolboxProxy;

/// <summary>
/// This module contains different vision functionalities, like picture taking, video recording, white balance setting, etc ... Picture and videos are both saved in /home/nao/.local/share/naoqi/vision.
/// ALVisionToolboxPostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALVisionToolboxProxyPostHandler
{
  friend class ALVisionToolboxProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// This module contains different vision functionalities, like picture taking, video recording, white balance setting, etc ... Picture and videos are both saved in /home/nao/.local/share/naoqi/vision.
  /// ALVisionToolboxPostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALVisionToolboxProxyPostHandler();

  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// Prepare camera for shooting (like the auto-focus on standard and digital cameras)
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int halfPress();
  /// <summary>
  /// Print in the logger the info for an instance of takePictureRegurarly()
  /// </summary>
  /// <param name="instanceNumber"> number of the instance we want to  get info on </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int logTPRInstanceInfo(const int& instanceNumber);
  /// <summary>
  /// Set white balance by using Nao's white hands as reference.
  /// </summary>
  /// <param name="camera"> Camera we want to set white balance to : [0] top - [1] bottom - [2] both </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setWhiteBalance(const int& camera);
  /// <summary>
  /// Start recording a video. The .avi video is stored on the robot in the /home/nao/.local/share/naoqi/vision folder. The record should be stopped by calling stopVideoRecord(). Resolution: 320*240, MJPG format, frame rate ~10-15 fps. Please note that only one record at a time can be made.
  /// </summary>
  /// <param name="videoName"> Name of the video file to be recorded. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int startVideoRecord(const std::string& videoName);
  /// <summary>
  /// Start recording a video, with advanced options. Please note that only one record at a time can be made.
  /// </summary>
  /// <param name="videoName"> Name of the video file to be recorded. </param>
  /// <param name="framerate"> Record frame rate [0.1-50.0]. Warning: MJPG format requires framerate greater than 2.0. </param>
  /// <param name="format"> ARV = raw YUV422 format; IYUV = raw avi, MJPG = compressed avi. </param>
  /// <param name="resIndex"> Resolution index. 0 = 160*120, 1 = 320*240, 2 = 640*480 </param>
  /// <param name="numFrames"> Number of frames to record. If less than 0, it records until stopVideoRecord() is called. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int startVideoRecord_adv(const std::string& videoName, const float& framerate, const std::string& format, const int& resIndex, const int& numFrames);
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
  /// <summary>
  /// Stop an instance of takePictureRegularly()
  /// </summary>
  /// <param name="pathAndNameRoot"> path and name root of the file we want to stop recording </param>
  /// <param name="imageRecordFormat"> formats of the file we want to stop recording </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stopTPR(const std::string& pathAndNameRoot, const std::string& imageRecordFormat);
  /// <summary>
  /// Shoot 3 successives pictures and place them in the /home/nao/.local/share/naoqi/vision folder. If halfPress has not been called before, it will take longer between click and shoot.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int takePicture();
  /// <summary>
  /// Shoot regularly a picture to follow Nao's evolution in his environment
  /// </summary>
  /// <param name="secondsBetweenTwoShots"> how many seconds between two pictures? </param>
  /// <param name="pathAndNameRoot"> path and the root of the name for the picture </param>
  /// <param name="overwriteImage"> do we need to overwrite the picture, or do we add a timestamp to the name? </param>
  /// <param name="imageRecordFormat"> such as jpeg, bmp, png, etc. </param>
  /// <param name="resolution"> resolution for the image (e.g. kQQVGA, kQVGA) </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int takePictureRegularly(const float& secondsBetweenTwoShots, const std::string& pathAndNameRoot, const bool& overwriteImage, const std::string& imageRecordFormat, const int& resolution);
};

}
#endif // ALVISIONTOOLBOXPROXYPOSTHANDLER_H_

