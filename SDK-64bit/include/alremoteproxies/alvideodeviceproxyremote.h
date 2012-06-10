// Generated for ALVideoDevice version 1.12

#ifndef ALVIDEODEVICEPROXYREMOTE_H_
#define ALVIDEODEVICEPROXYREMOTE_H_
#include <alremoteproxies/alvideodeviceproxyposthandlerremote.h>

namespace AL
{

/// <summary>ALVideoDevice, formerly called Video Input Module (V.I.M.), is architectured in order to provide every module related to vision, called Generic Video Module (G.V.M.), a direct access to raw images from video source, or an access to images transformed in the requested format.
    ///
    ///   Extension name of the methods providing images depends on wether modules are local (dynamic library) or remote (executable).</summary>
class ALVideoDeviceProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALVideoDeviceProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALVideoDevice", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALVideoDeviceProxyPostHandlerRemote post;


    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit()
    {

        callVoidRemote("exit");
    }


    /// <summary>
    /// Get the active camera
    /// </summary>
    /// <returns> 0: top camera - 1: bottom camera </returns>
    int getActiveCamera()
    {

        return callRemote<int >("getActiveCamera");
    }


    /// <summary>
    /// Returns angles relative to camera axis given a normalized position in the image.
    /// </summary>
    /// <param name="imgPos"> normalized position in the image [0.0 - 1.0] </param>
    /// <returns> corresponding angles values in radians. </returns>
    std::vector<float> getAngPosFromImgPos(const std::vector<float>& imgPos)
    {

        return callRemote<std::vector<float> >("getAngPosFromImgPos" , imgPos);
    }


    /// <summary>
    /// Returns angles relative to camera axis given a normalized position in the image.
    /// </summary>
    /// <param name="imgSize"> normalized position in the image [0.0 - 1.0] </param>
    /// <returns> corresponding angles values in radians. </returns>
    std::vector<float> getAngSizeFromImgSize(const std::vector<float>& imgSize)
    {

        return callRemote<std::vector<float> >("getAngSizeFromImgSize" , imgSize);
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
    /// Retrieve the camera model
    /// </summary>
    /// <returns> 1(kOV7670): VGA camera - 2(kMT9M114): HD camera </returns>
    int getCameraModelID()
    {

        return callRemote<int >("getCameraModelID");
    }




    /// <summary>
    /// Fills pFrameOut with data coming directly from raw buffer (no format conversion).
    ///
    /// No need to call releaseDirectRawImage() because it is done automatically at the end of data transmission.
    /// </summary>
    /// <param name="id"> Name under which the G.V.M. is known from ALVideoDevice. </param>
    /// <returns> Array containing image informations : 
    ///
    ///     [0] : width;
    ///
    ///     [1] : height;
    ///
    ///     [2] : number of layers;
    ///
    ///     [3] : ColorSpace;
    ///
    ///     [4] : time stamp (highest 32 bits);
    ///
    ///     [5] : time stamp (lowest 32 bits);
    ///
    ///     [6] : array of size height * width * nblayers containing image data;
    ///
    ///     [7] : cameraID;
    ///
    ///     [8] : left angle;
    ///
    ///     [9] : top angle;
    ///
    ///     [10] : right angle;
    ///
    ///     [11] : bottom angle; </returns>
    AL::ALValue getDirectRawImageRemote(const std::string& id)
    {

        return callRemote<AL::ALValue >("getDirectRawImageRemote" , id);
    }


    /// <summary>
    /// Get the color space of the requested G.V.M.
    /// </summary>
    /// <param name="id"> Name under which the G.V.M. is known from ALVideoDevice. </param>
    /// <returns> { 0 = kYuv, 9 = kYUV422, 10 = kYUV, 11 = kRGB, 12 = kHSY, 13 = kBGR } -1: can't access video source </returns>
    int getGVMColorSpace(const std::string& id)
    {

        return callRemote<int >("getGVMColorSpace" , id);
    }


    /// <summary>
    /// Get the frame rate of the requested G.V.M.
    /// </summary>
    /// <param name="id"> Name under which the G.V.M. is known from ALVideoDevice. </param>
    /// <returns> { 5, 10, 15, 30 }  -1: can't access video source </returns>
    int getGVMFrameRate(const std::string& id)
    {

        return callRemote<int >("getGVMFrameRate" , id);
    }


    /// <summary>
    /// Get the resolution of the requested G.V.M.
    /// </summary>
    /// <param name="id"> Name under which the G.V.M. is known from ALVideoDevice. </param>
    /// <returns> { 0 = kQQVGA, 1 = kQVGA, 2 = kVGA }  -1: can't access video source </returns>
    int getGVMResolution(const std::string& id)
    {

        return callRemote<int >("getGVMResolution" , id);
    }




    /// <summary>
    /// Applies transformations to the last image from video source and fills pFrameOut.
    /// </summary>
    /// <param name="id"> Name under which the G.V.M. is known from ALVideoDevice. </param>
    /// <returns> Array containing image informations : 
    ///
    ///     [0] : width;
    ///
    ///     [1] : height;
    ///
    ///     [2] : number of layers;
    ///
    ///     [3] : ColorSpace;
    ///
    ///     [4] : time stamp (highest 32 bits);
    ///
    ///     [5] : time stamp (lowest 32 bits);
    ///
    ///     [6] : array of size height * width * nblayers containing image data;
    ///
    ///     [7] : cameraID;
    ///
    ///     [8] : left angle;
    ///
    ///     [9] : top angle;
    ///
    ///     [10] : right angle;
    ///
    ///     [11] : bottom angle; </returns>
    AL::ALValue getImageRemote(const std::string& id)
    {

        return callRemote<AL::ALValue >("getImageRemote" , id);
    }


    /// <summary>
    /// Returns normalized image info from angles info in radians (as returned by vision extractors).
    /// </summary>
    /// <param name="angles"> camera angle values in radians. </param>
    /// <returns> corresponding normalized position info. </returns>
    std::vector<float> getImgInfoFromAngInfo(const std::vector<float>& angles)
    {

        return callRemote<std::vector<float> >("getImgInfoFromAngInfo" , angles);
    }


    /// <summary>
    /// Returns image info from angles info in radians (as returned by vision extractors). Express image info in the requested resolution.
    /// </summary>
    /// <param name="angInfo"> camera angle values in radians. </param>
    /// <param name="arg2"> arg </param>
    /// <returns> corresponding position info. </returns>
    std::vector<float> getImgInfoFromAngInfoWithRes(const std::vector<float>& angInfo, const int& arg2)
    {

        return callRemote<std::vector<float> >("getImgInfoFromAngInfoWithRes" , angInfo, arg2);
    }


    /// <summary>
    /// Returns normalized image position from camera angles in radians.
    /// </summary>
    /// <param name="angPos"> camera angle values in radians. </param>
    /// <returns> corresponding normalized position in the image [0.0 - 1.0] </returns>
    std::vector<float> getImgPosFromAngPos(const std::vector<float>& angPos)
    {

        return callRemote<std::vector<float> >("getImgPosFromAngPos" , angPos);
    }


    /// <summary>
    /// Returns normalized image position from camera angles in radians.
    /// </summary>
    /// <param name="angSize"> camera angle values in radians. </param>
    /// <returns> corresponding normalized position in the image [0.0 - 1.0] </returns>
    std::vector<float> getImgSizeFromAngSize(const std::vector<float>& angSize)
    {

        return callRemote<std::vector<float> >("getImgSizeFromAngSize" , angSize);
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
    /// Get the value of a video source specific parameter.
    /// </summary>
    /// <param name="pParam"> Parameter's reference among kCameraBrightnessID,
    ///
    ///  kCameraContrastID,
    ///
    ///  kCameraSaturationID,
    ///
    ///  kCameraHueID,
    ///
    ///  kCameraRedChromaID,
    ///
    ///  kCameraBlueChromaID,
    ///
    ///  kCameraGainID,
    ///
    ///  kCameraHFlipID,
    ///
    ///  kCameraVFlipID,
    ///
    ///  kCameraLensXID,
    ///
    ///  kCameraLensYID,
    ///
    ///  kCameraAutoExpositionID,
    ///
    ///  kCameraAecAlgorithmID [0:average-based; 1:histogram-based],
    ///
    ///  kCameraExposureCorrectionID [-6; 6] (correction by n/3 IL, switch automatically in average-based AEC algorithm if n!=0 and back to histogram-based for n=0),
    ///
    ///  kCameraExposureID,
    ///
    ///  kCameraAutoWhiteBalanceID,
    ///
    ///  kCameraAutoGainID,
    ///
    ///  kCameraSelectID [0:top camera; 1:bottom camera],
    ///
    ///  kCameraResolutionID,
    ///
    ///  kCameraFrameRateID,
    ///
    ///  kCameraBufferSizeID,
    ///
    ///  kCameraFastSwitchID (need both camera to run same format/ parameter value has no signification),
    ///
    ///  kCameraSharpnessID (0-1: no sharpness - 2: medium sharpness - 3-5: high sharpness) </param>
    /// <returns> Parameter's value. </returns>
    int getParam(const int& pParam)
    {

        return callRemote<int >("getParam" , pParam);
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
    /// Get the color space of the video source image.
    /// </summary>
    /// <returns> { 0 = kYuv, 9 = kYUV422, 10 = kYUV, 11 = kRGB, 12 = kHSY, 13 = kBGR }  -1 can't access video source </returns>
    int getVIMColorSpace()
    {

        return callRemote<int >("getVIMColorSpace");
    }


    /// <summary>
    /// Get the frame rate of the video source image.
    /// </summary>
    /// <returns> { 5, 10, 15, 30 }   -1: can't access video source </returns>
    int getVIMFrameRate()
    {

        return callRemote<int >("getVIMFrameRate");
    }


    /// <summary>
    /// Get the resolution of the video source image.
    /// </summary>
    /// <returns> { 0 = kQQVGA, 1 = kQVGA, 2 = kVGA }  -1: can't access video source </returns>
    int getVIMResolution()
    {

        return callRemote<int >("getVIMResolution");
    }


    /// <summary>
    /// Advanced method that asks if the framegrabber is off.
    /// </summary>
    /// <returns> true if off </returns>
    int isFrameGrabberOff()
    {

        return callRemote<int >("isFrameGrabberOff");
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
    /// Callback when client is disconnected
    /// </summary>
    /// <param name="eventName"> The echoed event name </param>
    /// <param name="eventContents"> The name of the client that has disconnected </param>
    /// <param name="message"> The message give when subscribing. </param>
    void onClientDisconnected(const std::string& eventName, const AL::ALValue& eventContents, const std::string& message)
    {

        callVoidRemote("onClientDisconnected" , eventName, eventContents, message);
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
    /// BETA - background record of an .arv raw format video from the images processed by a G.V.M.
    /// </summary>
    /// <param name="id"> Name under which the G.V.M. is known from the V.I.M. </param>
    /// <param name="path"> path/name of the video to be recorded </param>
    /// <param name="totalNumber"> number of images to be recorded. 0xFFFFFFFF for \"unlimited\" </param>
    /// <param name="period"> one image recorded every pPeriod images </param>
    /// <returns> true if success </returns>
    bool recordVideo(const std::string& id, const std::string& path, const int& totalNumber, const int& period)
    {

        return callRemote<bool >("recordVideo" , id, path, totalNumber, period);
    }




    /// <summary>
    /// Release image buffer locked by getImageLocal().
    ///
    /// If G.V.M. had no locked image buffer, does nothing.
    /// </summary>
    /// <param name="id"> Name under which the G.V.M. is known from ALVideoDevice. </param>
    /// <returns> true if success </returns>
    int releaseImage(const std::string& id)
    {

        return callRemote<int >("releaseImage" , id);
    }


    /// <summary>
    /// return the width and the height of a resolution
    /// </summary>
    /// <param name="resolution"> { 0 = kQQVGA, 1 = kQVGA, 2 = kVGA } </param>
    /// <returns> array of sizes: (return [-1;-1] if the format is invalid)  
    ///
    ///     [0] : width;
    ///
    ///     [1] : height; </returns>
    AL::ALValue resolutionToSizes(const int& resolution)
    {

        return callRemote<AL::ALValue >("resolutionToSizes" , resolution);
    }


    /// <summary>
    /// Set the colorspace of the output image.
    /// </summary>
    /// <param name="id"> Name under which the G.V.M. is known from ALVideoDevice. </param>
    /// <param name="colorSpace"> { 0 = kYuv, 9 = kYUV422, 10 = kYUV, 11 = kRGB, 12 = kHSY, 13 = kBGR } </param>
    /// <returns> true if success </returns>
    bool setColorSpace(const std::string& id, const int& colorSpace)
    {

        return callRemote<bool >("setColorSpace" , id, colorSpace);
    }


    /// <summary>
    /// Set the required frame rate.
    /// </summary>
    /// <param name="id"> Name under which the G.V.M. is known from ALVideoDevice. </param>
    /// <param name="frameRate"> images per seconds { 5, 10, 15, 30 } </param>
    /// <returns> true if success </returns>
    bool setFrameRate(const std::string& id, const int& frameRate)
    {

        return callRemote<bool >("setFrameRate" , id, frameRate);
    }


    /// <summary>
    /// Sets the value of a specific parameter for the video source.
    /// </summary>
    /// <param name="param"> Parameter's reference among:
    ///
    ///  kCameraBrightnessID,
    ///
    ///  kCameraContrastID,
    ///
    ///  kCameraSaturationID,
    ///
    ///  kCameraHueID,
    ///
    ///  kCameraRedChromaID,
    ///
    ///  kCameraBlueChromaID,
    ///
    ///  kCameraGainID,
    ///
    ///  kCameraHFlipID,
    ///
    ///  kCameraVFlipID,
    ///
    ///  kCameraLensXID (not managed by camera),
    ///
    ///  kCameraLensYID (not managed by camera),
    ///
    ///  kCameraAutoExpositionID,
    ///
    ///  kCameraAecAlgorithmID [0:average-based; 1:histogram-based],
    ///
    ///  kCameraExposureCorrectionID [-6; 6] (correction by n/3 EV, switch automatically in average-based AEC algorithm if n!=0 and back to histogram-based for n=0),
    ///
    ///  kCameraExposureID,
    ///
    ///  kCameraAutoWhiteBalanceID,
    ///
    ///  kCameraAutoGainID,
    ///
    ///  kCameraSelectID [0:top camera; 1:bottom camera],
    ///
    ///  kCameraResolutionID,
    ///
    ///  kCameraFrameRateID (not managed currently),
    ///
    ///  kCameraBufferSizeID,
    ///
    ///  kCameraSharpnessID (0-1: no sharpness - 2: medium sharpness - 3-5: high sharpness),
    ///
    ///  kCameraFastSwitchID : advanced method that needs both camera to run same format. Parameter value has no meaning.
    ///
    ///     Remarks: Disabled camera (freezed actually) will get back to auto gain/exposure/white balance settings after a while. This is a camera issue.
    ///
    ///              Fast switch usually switchs between cameras in 66ms (33ms for waked up sensor exposure + 33ms for data transfer) after previous image completion. However, sometimes we can observe a clipped image from the former camera after 66ms. This is an electronical issue and so we suggest to considere only images after 100ms </param>
    /// <param name="newValue"> Parameter's new value. </param>
    void setParam(const int& param, const int& newValue)
    {

        callVoidRemote("setParam" , param, newValue);
    }


    /// <summary>
    /// Sets a specific parameter for the video source at its default value.
    /// </summary>
    /// <param name="param"> Parameter's reference. </param>
    void setParamDefault(const int& param)
    {

        callVoidRemote("setParamDefault" , param);
    }


    /// <summary>
    /// Set the size of the output image.
    /// </summary>
    /// <param name="id"> Name under which the G.V.M. is known from ALVideoDevice. </param>
    /// <param name="size"> { 0 = kQQVGA, 1 = kQVGA, 2 = kVGA } </param>
    /// <returns> true if success </returns>
    bool setResolution(const std::string& id, const int& size)
    {

        return callRemote<bool >("setResolution" , id, size);
    }


    /// <summary>
    /// return the resolution from sizes
    /// </summary>
    /// <param name="width"> width of the image </param>
    /// <param name="height"> height of the image </param>
    /// <returns> { 0 = kQQVGA, 1 = kQVGA, 2 = kVGA }  or -1 if the inputs are invalid </returns>
    int sizesToResolution(const int& width, const int& height)
    {

        return callRemote<int >("sizesToResolution" , width, height);
    }


    /// <summary>
    /// Advanced method that opens and initialize video source device if it was not before.
    ///
    /// Note that the first module subscribing to ALVideoDevice will launch it automatically.
    /// </summary>
    /// <returns> true if success </returns>
    int startFrameGrabber()
    {

        return callRemote<int >("startFrameGrabber");
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
    /// Advanced method that close video source device.
    /// </summary>
    /// <returns> true if success </returns>
    int stopFrameGrabber()
    {

        return callRemote<int >("stopFrameGrabber");
    }


    /// <summary>
    /// BETA - stop writing the video sequence
    /// </summary>
    /// <param name="id"> Name under which the G.V.M. is known from ALVideoDevice. </param>
    /// <returns> true if success </returns>
    bool stopVideo(const std::string& id)
    {

        return callRemote<bool >("stopVideo" , id);
    }


    /// <summary>
    /// Register to ALVideoDevice (formerly Video Input Module/V.I.M.). When a General Video Module(G.V.M.) registers to ALVideoDevice, a buffer of the requested image format is added to the buffers list.
    ///
    /// Returns the name under which the G.V.M. is registered to ALVideoDevice (useful when two G.V.M. try to register using the same name
    /// </summary>
    /// <param name="gvmName"> Name of the subscribing G.V.M. </param>
    /// <param name="resolution"> Resolution requested. { 0 = kQQVGA, 1 = kQVGA, 2 = kVGA } </param>
    /// <param name="colorSpace"> Colorspace requested. { 0 = kYuv, 9 = kYUV422, 10 = kYUV, 11 = kRGB, 12 = kHSY, 13 = kBGR } </param>
    /// <param name="fps"> Fps (frames per second) requested. { 5, 10, 15, 30 } </param>
    /// <returns> Name under which the G.V.M. is known from ALVideoDevice, 0 if failed. </returns>
    std::string subscribe(const std::string& gvmName, const int& resolution, const int& colorSpace, const int& fps)
    {

        return callRemote<std::string >("subscribe" , gvmName, resolution, colorSpace, fps);
    }


    /// <summary>
    /// Used to unregister a G.V.M. from ALVideoDevice.
    /// </summary>
    /// <param name="id"> Name under which the G.V.M. is known from ALVideoDevice. </param>
    void unsubscribe(const std::string& id)
    {

        callVoidRemote("unsubscribe" , id);
    }


    /// <summary>
    /// Used to unsubscribe all instances for a given G.V.M. (e.g. VisionModule and VisionModule_5) from ALVideoDevice.
    /// </summary>
    /// <param name="id"> Root name of the G.V.M. (e.g. with the example above this will be VisionModule). </param>
    void unsubscribeAllInstances(const std::string& id)
    {

        callVoidRemote("unsubscribeAllInstances" , id);
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
#endif // ALVIDEODEVICEPROXY_H_
