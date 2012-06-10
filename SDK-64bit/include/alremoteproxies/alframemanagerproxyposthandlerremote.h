// Generated for ALFrameManager version 1.12


#ifndef ALFRAMEMANAGERPROXYPOSTHANDLERREMOTE_H_
#define ALFRAMEMANAGERPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALFrameManagerProxyRemote;

/// <summary>Frame manager is used to play choregraphe projects in naoqi. It needs Choregraphe projects in input and will return an ID for each project. It can also only read a given box/timeline in a complex behavior.</summary>
class ALFrameManagerProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALFrameManagerProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// Frame manager is used to play choregraphe projects in naoqi. It needs Choregraphe projects in input and will return an ID for each project. It can also only read a given box/timeline in a complex behavior.
    /// ALFrameManagerPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALFrameManagerProxyPostHandlerRemote() : fParent(NULL)
    {}



    /// <summary>
    /// Stop playing any behavior in FrameManager, and delete all of them.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int cleanBehaviors()
    {
      return fParent->pCall("cleanBehaviors");
    }

    /// <summary>
    /// It will play a behavior and block until the behavior is finished. Note that it can block forever if the behavior output is never called.
    /// </summary>
    /// <param name="id"> The id of the box. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int completeBehavior(const std::string& id)
    {
      return fParent->pCall("completeBehavior" , id);
    }


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
    /// Deletes a behavior (meaning a box). Stop the whole behavior contained in this box first.
    /// </summary>
    /// <param name="id"> The id of the box to delete. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int deleteBehavior(const std::string& id)
    {
      return fParent->pCall("deleteBehavior" , id);
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
    /// Exit the reading of a timeline contained in a given box
    /// </summary>
    /// <param name="id"> The id of the box. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int exitBehavior(const std::string& id)
    {
      return fParent->pCall("exitBehavior" , id);
    }









    /// <summary>
    /// Goes to a certain frame and continue playing
    /// </summary>
    /// <param name="id"> The id of the box containing the box. </param>
    /// <param name="frame"> The behavior frame name we want the timeline to go to. If will jump to the starting index of the name given. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int gotoAndPlay(const std::string& id, const std::string& frame)
    {
      return fParent->pCall("gotoAndPlay" , id, frame);
    }

    /// <summary>
    /// Goes to a certain frame and continue playing
    /// </summary>
    /// <param name="id"> The id of the box containing the box. </param>
    /// <param name="frame"> The frame we want the timeline to go to. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int gotoAndPlay(const std::string& id, const int& frame)
    {
      return fParent->pCall("gotoAndPlay" , id, frame);
    }

    /// <summary>
    /// Goes to a certain frame and pause
    /// </summary>
    /// <param name="id"> The id of the box containing the box. </param>
    /// <param name="frame"> The behavior frame name we want the timeline to go to. If will jump to the starting index of the name given. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int gotoAndStop(const std::string& id, const std::string& frame)
    {
      return fParent->pCall("gotoAndStop" , id, frame);
    }

    /// <summary>
    /// Goes to a certain frame and pause
    /// </summary>
    /// <param name="id"> The id of the box containing the box. </param>
    /// <param name="frame"> The frame we want the timeline to go to. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int gotoAndStop(const std::string& id, const int& frame)
    {
      return fParent->pCall("gotoAndStop" , id, frame);
    }





    /// <summary>
    /// Transmit Python error to Choregraphe or logger. Should not be called manually. DEPRECATED.
    /// </summary>
    /// <param name="boxname"> Name of the box raising the error </param>
    /// <param name="methodname"> Name of the method </param>
    /// <param name="error"> Error string </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int onPythonError(const std::string& boxname, const std::string& methodname, const std::string& error)
    {
      return fParent->pCall("onPythonError" , boxname, methodname, error);
    }

    /// <summary>
    /// Print Python message in Choregraphe or logger. Should not be called manually. DEPRECATED.
    /// </summary>
    /// <param name="message"> Message to print </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int onPythonPrint(const std::string& message)
    {
      return fParent->pCall("onPythonPrint" , message);
    }

    /// <summary>
    /// Transmit Ruby error to Choregraphe or logger. Should not be called manually. DEPRECATED.
    /// </summary>
    /// <param name="boxname"> Name of the box raising the error </param>
    /// <param name="methodname"> Name of the method </param>
    /// <param name="error"> Error string </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int onRubyError(const std::string& boxname, const std::string& methodname, const std::string& error)
    {
      return fParent->pCall("onRubyError" , boxname, methodname, error);
    }

    /// <summary>
    /// Print Ruby message in Choregraphe or logger. Should not be called manually. DEPRECATED.
    /// </summary>
    /// <param name="message"> Message to print </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int onRubyPrint(const std::string& message)
    {
      return fParent->pCall("onRubyPrint" , message);
    }

    /// <summary>
    /// Transmit Urbi error to Choregraphe or logger. Should not be called manually. DEPRECATED.
    /// </summary>
    /// <param name="boxname"> Name of the box raising the error </param>
    /// <param name="methodname"> Name of the method </param>
    /// <param name="location"> Location of the error </param>
    /// <param name="error"> Error string </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int onUrbiError(const std::string& boxname, const std::string& methodname, const std::string& location, const std::string& error)
    {
      return fParent->pCall("onUrbiError" , boxname, methodname, location, error);
    }

    /// <summary>
    /// Print Urbi message in Choregraphe or logger. Should not be called manually. DEPRECATED.
    /// </summary>
    /// <param name="message"> Message to print </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int onUrbiPrint(const std::string& message)
    {
      return fParent->pCall("onUrbiPrint" , message);
    }


    /// <summary>
    /// Starts a behavior
    /// </summary>
    /// <param name="id"> The id of the box. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int playBehavior(const std::string& id)
    {
      return fParent->pCall("playBehavior" , id);
    }

    /// <summary>
    /// Play default behavior; DEPRECATED: use ALBehaviorManager.playDefaultProject
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int playDefaultProject()
    {
      return fParent->pCall("playDefaultProject");
    }

    /// <summary>
    /// Starts playing a timeline contained in a given box. If the box is a flow diagram, it will look for the first onStart input of type Bang, and stimulate it !
    /// </summary>
    /// <param name="id"> The id of the box. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int playTimeline(const std::string& id)
    {
      return fParent->pCall("playTimeline" , id);
    }

    /// <summary>
    /// Sets the FPS of a given timeline
    /// </summary>
    /// <param name="id"> The id of the timeline. </param>
    /// <param name="fps"> The FPS to set. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setTimelineFps(const std::string& id, const int& fps)
    {
      return fParent->pCall("setTimelineFps" , id, fps);
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
    /// Stops playing a timeline contained in a given box, at the current frame
    /// </summary>
    /// <param name="id"> The id of the box. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int stopTimeline(const std::string& id)
    {
      return fParent->pCall("stopTimeline" , id);
    }



};

}
#endif // ALFRAMEMANAGERPROXYPOSTHANDLERREMOTE_H_

