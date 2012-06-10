// Generated for ALLandMarkDetection version 1.12

#ifndef ALLANDMARKDETECTIONPROXYPOSTHANDLER_H_
#define ALLANDMARKDETECTIONPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALLandMarkDetectionProxy;

/// <summary>
/// ALLandMarkDetection is a module which detects and recognizes Naomarks. The output value is written in ALMemory in the LandmarkDetected variable.
    ///
    ///  It contains an array of tags, with the following format: 
    ///
    ///  
    ///
    /// [ [timestamp_seconds, timestamp_microseconds], [mark_info_0, mark_info_1, .. , mark_info_N] ] 
    ///
    ///  
    ///
    /// with as many mark_info tags as marks currently detected. 
    ///
    /// mark_info_x = [ [shape, alpha, beta, sizeX, sizeY, heading], [markID] ]. 
    ///
    /// - alpha and beta represent the Naomark's location in terms of camera angles 
    ///
    /// - sizeX and sizeY are the mark's size in camera angles 
    ///
    /// - the heading angle describes how the Naomark is oriented about the vertical axis with regards to Nao's head. 
    ///
    /// - Mark ID is the number written on the naomark and which corresponds to its pattern.
/// ALLandMarkDetectionPostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALLandMarkDetectionProxyPostHandler
{
  friend class ALLandMarkDetectionProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// ALLandMarkDetection is a module which detects and recognizes Naomarks. The output value is written in ALMemory in the LandmarkDetected variable.
    ///
    ///  It contains an array of tags, with the following format: 
    ///
    ///  
    ///
    /// [ [timestamp_seconds, timestamp_microseconds], [mark_info_0, mark_info_1, .. , mark_info_N] ] 
    ///
    ///  
    ///
    /// with as many mark_info tags as marks currently detected. 
    ///
    /// mark_info_x = [ [shape, alpha, beta, sizeX, sizeY, heading], [markID] ]. 
    ///
    /// - alpha and beta represent the Naomark's location in terms of camera angles 
    ///
    /// - sizeX and sizeY are the mark's size in camera angles 
    ///
    /// - the heading angle describes how the Naomark is oriented about the vertical axis with regards to Nao's head. 
    ///
    /// - Mark ID is the number written on the naomark and which corresponds to its pattern.
  /// ALLandMarkDetectionPostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALLandMarkDetectionProxyPostHandler();

  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// protected method
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int run();
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
  /// <summary>
  /// Subscribes to the extractor. This causes the extractor to start writing information to memory using the keys described by getOutputNames(). These can be accessed in memory using ALMemory.getData(\"keyName\"). In many cases you can avoid calling subscribe on the extractor by just calling ALMemory.subscribeToEvent() supplying a callback method. This will automatically subscribe to the extractor for you.
  /// </summary>
  /// <param name="name"> Name of the module which subscribes. </param>
  /// <param name="period"> Refresh period (in milliseconds) if relevant. </param>
  /// <param name="precision"> Precision of the extractor if relevant. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int subscribe(const std::string& name, const int& period, const float& precision);
  /// <summary>
  /// Subscribes to the extractor. This causes the extractor to start writing information to memory using the keys described by getOutputNames(). These can be accessed in memory using ALMemory.getData(\"keyName\"). In many cases you can avoid calling subscribe on the extractor by just calling ALMemory.subscribeToEvent() supplying a callback method. This will automatically subscribe to the extractor for you.
  /// </summary>
  /// <param name="name"> Name of the module which subscribes. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int subscribe(const std::string& name);
  /// <summary>
  /// Unsubscribes from the extractor.
  /// </summary>
  /// <param name="name"> Name of the module which had subscribed. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int unsubscribe(const std::string& name);
  /// <summary>
  /// Updates the period if relevant.
  /// </summary>
  /// <param name="name"> Name of the module which has subscribed. </param>
  /// <param name="period"> Refresh period (in milliseconds). </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int updatePeriod(const std::string& name, const int& period);
  /// <summary>
  /// Updates the precision if relevant.
  /// </summary>
  /// <param name="name"> Name of the module which has subscribed. </param>
  /// <param name="precision"> Precision of the extractor. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int updatePrecision(const std::string& name, const float& precision);
};

}
#endif // ALLANDMARKDETECTIONPROXYPOSTHANDLER_H_

