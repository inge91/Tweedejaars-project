// Generated for ALFaceDetection version 1.12


#ifndef ALFACEDETECTIONPROXYPOSTHANDLERREMOTE_H_
#define ALFACEDETECTIONPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALFaceDetectionProxyRemote;

/// <summary>ALFaceDetection is the Module which detects faces. 
    ///
    /// This module detects if there is one, several or no face in Nao's field of view. Better results are obtained when facing Nao. 
    ///
    /// The output value is written in ALMemory in the FaceDetected variable. 
    ///
    ///  The output value is organized as follows: 
    ///
    ///  
    ///
    /// [ [ TimeStampField ] [ Face_info_0 , Face_info_1, . . . , Face_info_N-1, Time_Filtered_Reco_info ] [ Camera_position_info ] ] 
    ///
    /// with 
    ///
    /// - TimeStampField = [ TimeStamp_seconds, Timestamp_microseconds ]. This field is the time stamp of the image                                                                         that was used to perform the detection. 
    ///
    /// - Face_info = [ ShapeInfo, ExtraInfo ]. For each detected face, we have one Face_info field. 
    ///
    ///   &gt; ShapeInfo = [ 0, alpha, beta, sizeX, sizeY ]. 
    ///
    ///      - alpha and beta represent the face's location in terms of camera angles 
    ///
    ///      - sizeX and sizeY are the face's size in camera angle 
    ///
    ///   &gt; ExtraInfo = [ Reco_info_0, Reco_info_1, ..., Reco_info_M ] 
    ///
    ///    with Reco_info_0 = [ faceID, score_reco, face_label, left_eye_points, right_eye_points,                                left_eyebrow_points, right_eyebrow_points, nose_points, mouth_points ] 
    ///
    ///    and 
    ///
    ///    ==&gt; faceID the ID number for the face 
    ///
    ///    ==&gt; score_reco the score returned by the rocognition process (the higher the better) 
    ///
    ///    ==&gt; face_label the name of the recognized face 
    ///
    ///    ==&gt; xxxx_eye_points = [ eyeCenter_x, eyeCenter_y, noseSideLimit_x, noseSideLimit_y, earSideLimit_x, earSideLimit_y,                                   topLimit_x, topLimit_y, bottomLimit_x, bottomLimit_y, midTopEarLimit_x, midTopEarLimit_y,                                   midTopNoseLimit_x, midTopNoseLimit_y ] 
    ///
    ///    ==&gt; xxxx_eyebrow_points = [ noseSideLimit_x, noseSideLimit_y, center_x, center_y, earSideLimit_x, earSideLimit_y ] 
    ///
    ///    ==&gt; nose_points = [ bottomCenterLimit_x, bottomCenterLimit_y, bottomLeftLimit_x, bottomLeftLimit_y,                               bottomRightLimit_x, bottomRightLimit_y ] 
    ///
    ///    ==&gt; mouth_points = [ leftLimit_x, leftLimit_y, rightLimit_x, rightLimit_y, topLimit_x, topLimit_y, bottomLimit_x,                                bottomLimit_y, midTopLeftLimit_x, midTopLeftLimit_y, midTopRightLimit_x, midTopRightLimit_y,                                midBottomRightLimit_x, midBottomRightLimit_y, midBottomLeftLimit_x, midBottomLeftLimit_y ] 
    ///
    ///    ...all these coordinates are given in camera angles. 
    ///
    /// - Time_Filtered_Reco_info can be equal to 
    ///
    ///   &gt; [] if there is nothing new 
    ///
    ///   &gt; [ 2 [ face_label ] ] if there is one face recognized 
    ///
    ///   &gt; [ 3 [ face_label_0, ..., face_label_P ] ] if there are several recognized faces 
    ///
    ///   &gt; [ 4 ] if a face has been detected for more than 8 seconds without being recognized. Getting this result is a            suggestion to learn this face if desired, but keep in mind that recognition only works for faces looking towards NAO. 
    ///
    /// - Camera_position_info is a set of 6 float values obtained from the getPosition() method of a motion proxy.</summary>
class ALFaceDetectionProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALFaceDetectionProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// ALFaceDetection is the Module which detects faces. 
    ///
    /// This module detects if there is one, several or no face in Nao's field of view. Better results are obtained when facing Nao. 
    ///
    /// The output value is written in ALMemory in the FaceDetected variable. 
    ///
    ///  The output value is organized as follows: 
    ///
    ///  
    ///
    /// [ [ TimeStampField ] [ Face_info_0 , Face_info_1, . . . , Face_info_N-1, Time_Filtered_Reco_info ] [ Camera_position_info ] ] 
    ///
    /// with 
    ///
    /// - TimeStampField = [ TimeStamp_seconds, Timestamp_microseconds ]. This field is the time stamp of the image                                                                         that was used to perform the detection. 
    ///
    /// - Face_info = [ ShapeInfo, ExtraInfo ]. For each detected face, we have one Face_info field. 
    ///
    ///   &gt; ShapeInfo = [ 0, alpha, beta, sizeX, sizeY ]. 
    ///
    ///      - alpha and beta represent the face's location in terms of camera angles 
    ///
    ///      - sizeX and sizeY are the face's size in camera angle 
    ///
    ///   &gt; ExtraInfo = [ Reco_info_0, Reco_info_1, ..., Reco_info_M ] 
    ///
    ///    with Reco_info_0 = [ faceID, score_reco, face_label, left_eye_points, right_eye_points,                                left_eyebrow_points, right_eyebrow_points, nose_points, mouth_points ] 
    ///
    ///    and 
    ///
    ///    ==&gt; faceID the ID number for the face 
    ///
    ///    ==&gt; score_reco the score returned by the rocognition process (the higher the better) 
    ///
    ///    ==&gt; face_label the name of the recognized face 
    ///
    ///    ==&gt; xxxx_eye_points = [ eyeCenter_x, eyeCenter_y, noseSideLimit_x, noseSideLimit_y, earSideLimit_x, earSideLimit_y,                                   topLimit_x, topLimit_y, bottomLimit_x, bottomLimit_y, midTopEarLimit_x, midTopEarLimit_y,                                   midTopNoseLimit_x, midTopNoseLimit_y ] 
    ///
    ///    ==&gt; xxxx_eyebrow_points = [ noseSideLimit_x, noseSideLimit_y, center_x, center_y, earSideLimit_x, earSideLimit_y ] 
    ///
    ///    ==&gt; nose_points = [ bottomCenterLimit_x, bottomCenterLimit_y, bottomLeftLimit_x, bottomLeftLimit_y,                               bottomRightLimit_x, bottomRightLimit_y ] 
    ///
    ///    ==&gt; mouth_points = [ leftLimit_x, leftLimit_y, rightLimit_x, rightLimit_y, topLimit_x, topLimit_y, bottomLimit_x,                                bottomLimit_y, midTopLeftLimit_x, midTopLeftLimit_y, midTopRightLimit_x, midTopRightLimit_y,                                midBottomRightLimit_x, midBottomRightLimit_y, midBottomLeftLimit_x, midBottomLeftLimit_y ] 
    ///
    ///    ...all these coordinates are given in camera angles. 
    ///
    /// - Time_Filtered_Reco_info can be equal to 
    ///
    ///   &gt; [] if there is nothing new 
    ///
    ///   &gt; [ 2 [ face_label ] ] if there is one face recognized 
    ///
    ///   &gt; [ 3 [ face_label_0, ..., face_label_P ] ] if there are several recognized faces 
    ///
    ///   &gt; [ 4 ] if a face has been detected for more than 8 seconds without being recognized. Getting this result is a            suggestion to learn this face if desired, but keep in mind that recognition only works for faces looking towards NAO. 
    ///
    /// - Camera_position_info is a set of 6 float values obtained from the getPosition() method of a motion proxy.
    /// ALFaceDetectionPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALFaceDetectionProxyPostHandlerRemote() : fParent(NULL)
    {}




    /// <summary>
    /// enable/disable the recognition stageProcess will be faster when disabled when you don't need to recognize people
    /// </summary>
    /// <param name="enable"> True/False </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int enableRecognition(const bool& enable)
    {
      return fParent->pCall("enableRecognition" , enable);
    }

    /// <summary>
    /// (BETA) Choose to enable or disable tracking. Enabling tracking usually allows you to follow a face for a longer period of time. However, it can lead to more false detections.
    /// </summary>
    /// <param name="enable"> True/False </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int enableTracking(const bool& enable)
    {
      return fParent->pCall("enableTracking" , enable);
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
    /// returns true if the method is currently running
    /// </summary>
    /// <param name="id"> the ID of the method to wait for </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int stop(const int& id)
    {
      return fParent->pCall("stop" , id);
    }

    /// <summary>
    /// Subscribes to the extractor. This causes the extractor to start writing information to memory using the keys described by getOutputNames(). These can be accessed in memory using ALMemory.getData(\"keyName\"). In many cases you can avoid calling subscribe on the extractor by just calling ALMemory.subscribeToEvent() supplying a callback method. This will automatically subscribe to the extractor for you.
    /// </summary>
    /// <param name="name"> Name of the module which subscribes. </param>
    /// <param name="period"> Refresh period (in milliseconds) if relevant. </param>
    /// <param name="precision"> Precision of the extractor if relevant. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int subscribe(const std::string& name, const int& period, const float& precision)
    {
      return fParent->pCall("subscribe" , name, period, precision);
    }

    /// <summary>
    /// Subscribes to the extractor. This causes the extractor to start writing information to memory using the keys described by getOutputNames(). These can be accessed in memory using ALMemory.getData(\"keyName\"). In many cases you can avoid calling subscribe on the extractor by just calling ALMemory.subscribeToEvent() supplying a callback method. This will automatically subscribe to the extractor for you.
    /// </summary>
    /// <param name="name"> Name of the module which subscribes. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int subscribe(const std::string& name)
    {
      return fParent->pCall("subscribe" , name);
    }

    /// <summary>
    /// Unsubscribes from the extractor.
    /// </summary>
    /// <param name="name"> Name of the module which had subscribed. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int unsubscribe(const std::string& name)
    {
      return fParent->pCall("unsubscribe" , name);
    }

    /// <summary>
    /// Updates the period if relevant.
    /// </summary>
    /// <param name="name"> Name of the module which has subscribed. </param>
    /// <param name="period"> Refresh period (in milliseconds). </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int updatePeriod(const std::string& name, const int& period)
    {
      return fParent->pCall("updatePeriod" , name, period);
    }

    /// <summary>
    /// Updates the precision if relevant.
    /// </summary>
    /// <param name="name"> Name of the module which has subscribed. </param>
    /// <param name="precision"> Precision of the extractor. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int updatePrecision(const std::string& name, const float& precision)
    {
      return fParent->pCall("updatePrecision" , name, precision);
    }



};

}
#endif // ALFACEDETECTIONPROXYPOSTHANDLERREMOTE_H_

