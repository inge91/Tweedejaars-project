// Generated for ALMotionRecorder version 1.12


#ifndef ALMOTIONRECORDERPROXYPOSTHANDLERREMOTE_H_
#define ALMOTIONRECORDERPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALMotionRecorderProxyRemote;

/// <summary>ALMotionRecorder is a module giving the possibility to record Nao's motors poses. A first possibility is to record periodically, ie. a pose is stored every t seconds. Another possibility is to use an interactive mode where the user choses when a poses must be stored.</summary>
class ALMotionRecorderProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALMotionRecorderProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// ALMotionRecorder is a module giving the possibility to record Nao's motors poses. A first possibility is to record periodically, ie. a pose is stored every t seconds. Another possibility is to use an interactive mode where the user choses when a poses must be stored.
    /// ALMotionRecorderPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALMotionRecorderProxyPostHandlerRemote() : fParent(NULL)
    {}



    /// <summary>
    /// Called by ALMemory when subcription data is updated. INTERNAL
    /// </summary>
    /// <param name="dataName"> Name of the subscribed data. </param>
    /// <param name="data"> Value of the the subscribed data </param>
    /// <param name="message"> The message give when subscribing. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int dataChanged(const std::string& dataName, const AL::ALValue& data, const std::string& message)
    {
      return fParent->pCall("dataChanged" , dataName, data, message);
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
    /// Start recording the motion in an interactive mode
    /// </summary>
    /// <param name="jointsToRecord"> Names of joints that must be recorded </param>
    /// <param name="nbPoses"> Default number of poses to record </param>
    /// <param name="extensionAllowed"> Set to true to ignore nbPoses and keep recording new poses as long as record is not manually stopped </param>
    /// <param name="mode"> Indicates which interactive mode must be used. 1 : Use right bumper to enslave and left bumper to store the pose 2 : Use chest button to store the pose </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int startInteractiveRecording(const std::vector<std::string>& jointsToRecord, const int& nbPoses, const bool& extensionAllowed, const int& mode)
    {
      return fParent->pCall("startInteractiveRecording" , jointsToRecord, nbPoses, extensionAllowed, mode);
    }

    /// <summary>
    /// Start recording the motion in a periodic mode
    /// </summary>
    /// <param name="jointsToRecord"> Names of joints that must be recorded </param>
    /// <param name="nbPoses"> Default number of poses to record </param>
    /// <param name="extensionAllowed"> set to true to ignore nbPoses and keep recording new poses as long as record is not manually stopped </param>
    /// <param name="timeStep"> Time in seconds to wait between two poses </param>
    /// <param name="jointsToReplay"> Names of joints that must be replayed </param>
    /// <param name="replayData"> An ALValue holding data for replayed joints. It holds two ALValues. The first one is an ALValue where each line corresponds to a joint, and column elements are times of control points The second one is also an ALValue where each line corresponds to a joint, but column elements are arrays containing [float angle, Handle1, Handle2] elements, where Handle is [int InterpolationType, float dAngle, float dTime] describing the handle offsets relative to the angle and time of the point. The first bezier param describes the handle that controls the curve preceding the point, the second describes the curve following the point. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int startPeriodicRecording(const std::vector<std::string>& jointsToRecord, const int& nbPoses, const bool& extensionAllowed, const float& timeStep, const std::vector<std::string>& jointsToReplay, const AL::ALValue& replayData)
    {
      return fParent->pCall("startPeriodicRecording" , jointsToRecord, nbPoses, extensionAllowed, timeStep, jointsToReplay, replayData);
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
#endif // ALMOTIONRECORDERPROXYPOSTHANDLERREMOTE_H_

