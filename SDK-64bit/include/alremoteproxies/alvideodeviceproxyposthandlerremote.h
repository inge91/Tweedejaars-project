// Generated for ALVideoDevice version 1.12


#ifndef ALVIDEODEVICEPROXYPOSTHANDLERREMOTE_H_
#define ALVIDEODEVICEPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALVideoDeviceProxyRemote;

/// <summary>ALVideoDevice, formerly called Video Input Module (V.I.M.), is architectured in order to provide every module related to vision, called Generic Video Module (G.V.M.), a direct access to raw images from video source, or an access to images transformed in the requested format.
    ///
    ///   Extension name of the methods providing images depends on wether modules are local (dynamic library) or remote (executable).</summary>
class ALVideoDeviceProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALVideoDeviceProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// ALVideoDevice, formerly called Video Input Module (V.I.M.), is architectured in order to provide every module related to vision, called Generic Video Module (G.V.M.), a direct access to raw images from video source, or an access to images transformed in the requested format.
    ///
    ///   Extension name of the methods providing images depends on wether modules are local (dynamic library) or remote (executable).
    /// ALVideoDevicePostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALVideoDeviceProxyPostHandlerRemote() : fParent(NULL)
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
    /// Callback when client is disconnected
    /// </summary>
    /// <param name="eventName"> The echoed event name </param>
    /// <param name="eventContents"> The name of the client that has disconnected </param>
    /// <param name="message"> The message give when subscribing. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int onClientDisconnected(const std::string& eventName, const AL::ALValue& eventContents, const std::string& message)
    {
      return fParent->pCall("onClientDisconnected" , eventName, eventContents, message);
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
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setParam(const int& param, const int& newValue)
    {
      return fParent->pCall("setParam" , param, newValue);
    }

    /// <summary>
    /// Sets a specific parameter for the video source at its default value.
    /// </summary>
    /// <param name="param"> Parameter's reference. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setParamDefault(const int& param)
    {
      return fParent->pCall("setParamDefault" , param);
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
    /// Used to unregister a G.V.M. from ALVideoDevice.
    /// </summary>
    /// <param name="id"> Name under which the G.V.M. is known from ALVideoDevice. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int unsubscribe(const std::string& id)
    {
      return fParent->pCall("unsubscribe" , id);
    }

    /// <summary>
    /// Used to unsubscribe all instances for a given G.V.M. (e.g. VisionModule and VisionModule_5) from ALVideoDevice.
    /// </summary>
    /// <param name="id"> Root name of the G.V.M. (e.g. with the example above this will be VisionModule). </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int unsubscribeAllInstances(const std::string& id)
    {
      return fParent->pCall("unsubscribeAllInstances" , id);
    }



};

}
#endif // ALVIDEODEVICEPROXYPOSTHANDLERREMOTE_H_

