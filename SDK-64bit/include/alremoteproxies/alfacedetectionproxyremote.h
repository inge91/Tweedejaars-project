// Generated for ALFaceDetection version 1.12

#ifndef ALFACEDETECTIONPROXYREMOTE_H_
#define ALFACEDETECTIONPROXYREMOTE_H_
#include <alremoteproxies/alfacedetectionproxyposthandlerremote.h>

namespace AL
{

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
class ALFaceDetectionProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALFaceDetectionProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALFaceDetection", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALFaceDetectionProxyPostHandlerRemote post;


    /// <summary>
    /// Remove all faces from the database.
    /// </summary>
    /// <returns> true if the operation succeeds </returns>
    bool clearDatabase()
    {

        return callRemote<bool >("clearDatabase");
    }


    /// <summary>
    /// enable/disable the recognition stageProcess will be faster when disabled when you don't need to recognize people
    /// </summary>
    /// <param name="enable"> True/False </param>
    void enableRecognition(const bool& enable)
    {

        callVoidRemote("enableRecognition" , enable);
    }


    /// <summary>
    /// (BETA) Choose to enable or disable tracking. Enabling tracking usually allows you to follow a face for a longer period of time. However, it can lead to more false detections.
    /// </summary>
    /// <param name="enable"> True/False </param>
    void enableTracking(const bool& enable)
    {

        callVoidRemote("enableTracking" , enable);
    }


    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit()
    {

        callVoidRemote("exit");
    }


    /// <summary>
    /// Delete from the database all faces instances of a person.
    /// </summary>
    /// <param name="pId"> The name of the person to forget </param>
    /// <returns> true if the operation succeeds </returns>
    bool forgetPerson(const std::string& pId)
    {

        return callRemote<bool >("forgetPerson" , pId);
    }


    /// <summary>
    /// Gets the name of the parent broker.
    /// </summary>
    /// <returns> The name of the parent broker. </returns>
    std::string getBrokerName()
    {

        return callRemote<std::string >("getBrokerName");
    }


    /// <summary>
    /// Gets the current period.
    /// </summary>
    /// <returns> Refresh period (in milliseconds). </returns>
    int getCurrentPeriod()
    {

        return callRemote<int >("getCurrentPeriod");
    }


    /// <summary>
    /// Gets the current precision.
    /// </summary>
    /// <returns> Precision of the extractor. </returns>
    float getCurrentPrecision()
    {

        return callRemote<float >("getCurrentPrecision");
    }


    /// <summary>
    /// Retrieves a method's description.
    /// </summary>
    /// <param name="methodName"> The name of the method. </param>
    /// <returns> A structure containing the method's description. </returns>
    AL::ALValue getMethodHelp(const std::string& methodName)
    {

        return callRemote<AL::ALValue >("getMethodHelp" , methodName);
    }


    /// <summary>
    /// Retrieves the module's method list.
    /// </summary>
    /// <returns> An array of method names. </returns>
    std::vector<std::string> getMethodList()
    {

        return callRemote<std::vector<std::string> >("getMethodList");
    }


    /// <summary>
    /// Retrieves the module's description.
    /// </summary>
    /// <returns> A structure describing the module. </returns>
    AL::ALValue getModuleHelp()
    {

        return callRemote<AL::ALValue >("getModuleHelp");
    }


    /// <summary>
    /// Gets the period for a specific subscription.
    /// </summary>
    /// <param name="name"> Name of the module which has subscribed. </param>
    /// <returns> Refresh period (in milliseconds). </returns>
    int getMyPeriod(const std::string& name)
    {

        return callRemote<int >("getMyPeriod" , name);
    }


    /// <summary>
    /// Gets the precision for a specific subscription.
    /// </summary>
    /// <param name="name"> name of the module which has subscribed </param>
    /// <returns> precision of the extractor </returns>
    float getMyPrecision(const std::string& name)
    {

        return callRemote<float >("getMyPrecision" , name);
    }


    /// <summary>
    /// Get the list of values updated in ALMemory.
    /// </summary>
    /// <returns> Array of values updated by this extractor in ALMemory </returns>
    std::vector<std::string> getOutputNames()
    {

        return callRemote<std::vector<std::string> >("getOutputNames");
    }


    /// <summary>
    /// Gets the parameters given by the module.
    /// </summary>
    /// <returns> Array of names and parameters of all subscribers. </returns>
    AL::ALValue getSubscribersInfo()
    {

        return callRemote<AL::ALValue >("getSubscribersInfo");
    }


    /// <summary>
    /// Gets the method usage string. This summarise how to use the method.
    /// </summary>
    /// <param name="name"> The name of the method. </param>
    /// <returns> A string that summarises the usage of the method. </returns>
    std::string getUsage(const std::string& name)
    {

        return callRemote<std::string >("getUsage" , name);
    }


    /// <summary>
    /// Returns true if the method is currently running.
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <returns> True if the method is currently running </returns>
    bool isRunning(const int& id)
    {

        return callRemote<bool >("isRunning" , id);
    }


    /// <summary>
    /// (BETA) Returns if tracking is enabled.
    /// </summary>
    /// <returns> True/False </returns>
    bool isTrackingEnabled()
    {

        return callRemote<bool >("isTrackingEnabled");
    }


    /// <summary>
    /// Add a new face in the database.
    /// </summary>
    /// <param name="pId"> The name of the person to save </param>
    /// <returns> true if the operation succeeds </returns>
    bool learnFace(const std::string& pId)
    {

        return callRemote<bool >("learnFace" , pId);
    }


    /// <summary>
    /// Just a ping. Always returns true
    /// </summary>
    /// <returns> returns true </returns>
    bool ping()
    {

        return callRemote<bool >("ping");
    }


    /// <summary>
    /// use in a new learning process     the latest images where a face has been wrongly recognized
    /// </summary>
    /// <param name="pId"> The name of the person to save </param>
    /// <returns> true if the operation succeeds </returns>
    bool reLearnFace(const std::string& pId)
    {

        return callRemote<bool >("reLearnFace" , pId);
    }


    /// <summary>
    /// returns true if the method is currently running
    /// </summary>
    /// <param name="id"> the ID of the method to wait for </param>
    void stop(const int& id)
    {

        callVoidRemote("stop" , id);
    }


    /// <summary>
    /// Subscribes to the extractor. This causes the extractor to start writing information to memory using the keys described by getOutputNames(). These can be accessed in memory using ALMemory.getData(\"keyName\"). In many cases you can avoid calling subscribe on the extractor by just calling ALMemory.subscribeToEvent() supplying a callback method. This will automatically subscribe to the extractor for you.
    /// </summary>
    /// <param name="name"> Name of the module which subscribes. </param>
    /// <param name="period"> Refresh period (in milliseconds) if relevant. </param>
    /// <param name="precision"> Precision of the extractor if relevant. </param>
    void subscribe(const std::string& name, const int& period, const float& precision)
    {

        callVoidRemote("subscribe" , name, period, precision);
    }


    /// <summary>
    /// Subscribes to the extractor. This causes the extractor to start writing information to memory using the keys described by getOutputNames(). These can be accessed in memory using ALMemory.getData(\"keyName\"). In many cases you can avoid calling subscribe on the extractor by just calling ALMemory.subscribeToEvent() supplying a callback method. This will automatically subscribe to the extractor for you.
    /// </summary>
    /// <param name="name"> Name of the module which subscribes. </param>
    void subscribe(const std::string& name)
    {

        callVoidRemote("subscribe" , name);
    }


    /// <summary>
    /// Unsubscribes from the extractor.
    /// </summary>
    /// <param name="name"> Name of the module which had subscribed. </param>
    void unsubscribe(const std::string& name)
    {

        callVoidRemote("unsubscribe" , name);
    }


    /// <summary>
    /// Updates the period if relevant.
    /// </summary>
    /// <param name="name"> Name of the module which has subscribed. </param>
    /// <param name="period"> Refresh period (in milliseconds). </param>
    void updatePeriod(const std::string& name, const int& period)
    {

        callVoidRemote("updatePeriod" , name, period);
    }


    /// <summary>
    /// Updates the precision if relevant.
    /// </summary>
    /// <param name="name"> Name of the module which has subscribed. </param>
    /// <param name="precision"> Precision of the extractor. </param>
    void updatePrecision(const std::string& name, const float& precision)
    {

        callVoidRemote("updatePrecision" , name, precision);
    }


    /// <summary>
    /// Returns the version of the module.
    /// </summary>
    /// <returns> A string containing the version of the module. </returns>
    std::string version()
    {

        return callRemote<std::string >("version");
    }


    /// <summary>
    /// Wait for the end of a long running method that was called using 'post'
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <param name="timeoutPeriod"> The timeout period in ms. To wait indefinately, use a timeoutPeriod of zero. </param>
    /// <returns> True if the timeout period terminated. False if the method returned. </returns>
    bool wait(const int& id, const int& timeoutPeriod)
    {

        return callRemote<bool >("wait" , id, timeoutPeriod);
    }


};

}
#endif // ALFACEDETECTIONPROXY_H_
