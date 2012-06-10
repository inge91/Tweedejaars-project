// Generated for ALAudioPlayer version 1.12


#ifndef ALAUDIOPLAYERPROXYPOSTHANDLERREMOTE_H_
#define ALAUDIOPLAYERPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALAudioPlayerProxyRemote;

/// <summary>This module allows to play wav and mp3 files on NAO</summary>
class ALAudioPlayerProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALAudioPlayerProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// This module allows to play wav and mp3 files on NAO
    /// ALAudioPlayerPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALAudioPlayerProxyPostHandlerRemote() : fParent(NULL)
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
    /// Goes to a given position in a file which is playing.
    /// </summary>
    /// <param name="playId"> Id of the process which is playing the file </param>
    /// <param name="position"> Position in the file (in second) </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int goTo(const int& playId, const float& position)
    {
      return fParent->pCall("goTo" , playId, position);
    }



    /// <summary>
    /// Pause a play back
    /// </summary>
    /// <param name="id"> Id of the process that is playing the file you want to put in pause </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int pause(const int& id)
    {
      return fParent->pCall("pause" , id);
    }


    /// <summary>
    /// Starts the playback of a file preloaded with the loadFile function.
    /// </summary>
    /// <param name="id"> Id returned by the loadFile function </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int play(const int& id)
    {
      return fParent->pCall("play" , id);
    }

    /// <summary>
    /// Starts the playback of a file preloaded with the loadFile function, with specific volume and audio balance
    /// </summary>
    /// <param name="id"> Id returned by the loadFile function </param>
    /// <param name="volume"> volume of the sound file (must be between 0.0 and 1.0) </param>
    /// <param name="pan"> audio balance of the sound file (-1.0 : left / 1.0 : right) </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int play(const int& id, const float& volume, const float& pan)
    {
      return fParent->pCall("play" , id, volume, pan);
    }

    /// <summary>
    /// Plays a wav or mp3 file
    /// </summary>
    /// <param name="fileName"> Path of the sound file </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int playFile(const std::string& fileName)
    {
      return fParent->pCall("playFile" , fileName);
    }

    /// <summary>
    /// Plays a wav or mp3 file, with specific volume and audio balance
    /// </summary>
    /// <param name="fileName"> Path of the sound file </param>
    /// <param name="volume"> volume of the sound file (must be between 0.0 and 1.0) </param>
    /// <param name="pan"> audio balance of the sound file (-1.0 : left / 1.0 : right / 0.0 : centered) </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int playFile(const std::string& fileName, const float& volume, const float& pan)
    {
      return fParent->pCall("playFile" , fileName, volume, pan);
    }

    /// <summary>
    /// Plays a wav or mp3 file from a given position in the file.
    /// </summary>
    /// <param name="fileName"> Name of the sound file </param>
    /// <param name="position"> Position in second where the playing has to begin </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int playFileFromPosition(const std::string& fileName, const float& position)
    {
      return fParent->pCall("playFileFromPosition" , fileName, position);
    }

    /// <summary>
    /// Plays a wav or mp3 file from a given position in the file, with specific volume and audio balance
    /// </summary>
    /// <param name="fileName"> Name of the sound file </param>
    /// <param name="position"> Position in second where the playing has to begin </param>
    /// <param name="volume"> volume of the sound file (must be between 0.0 and 1.0) </param>
    /// <param name="pan"> audio balance of the sound file (-1.0 : left / 1.0 : right) </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int playFileFromPosition(const std::string& fileName, const float& position, const float& volume, const float& pan)
    {
      return fParent->pCall("playFileFromPosition" , fileName, position, volume, pan);
    }

    /// <summary>
    /// Plays a wav or mp3 file in loop
    /// </summary>
    /// <param name="fileName"> Path of the sound file </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int playFileInLoop(const std::string& fileName)
    {
      return fParent->pCall("playFileInLoop" , fileName);
    }

    /// <summary>
    /// Plays a wav or mp3 file in loop, with specific volume and audio balance
    /// </summary>
    /// <param name="fileName"> Path of the sound file </param>
    /// <param name="volume"> volume of the sound file (must be between 0.0 and 1.0) </param>
    /// <param name="pan"> audio balance of the sound file (-1.0 : left / 1.0 : right) </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int playFileInLoop(const std::string& fileName, const float& volume, const float& pan)
    {
      return fParent->pCall("playFileInLoop" , fileName, volume, pan);
    }

    /// <summary>
    /// Starts the playback in loop of a file preloaded with the loadFile function
    /// </summary>
    /// <param name="id"> Id returned by the loadFile function </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int playInLoop(const int& id)
    {
      return fParent->pCall("playInLoop" , id);
    }

    /// <summary>
    /// Plays a wav or mp3 file in loop, with specific volume and audio balance
    /// </summary>
    /// <param name="id"> Id returned by the loadFile function </param>
    /// <param name="volume"> volume of the sound file (must be between 0.0 and 1.0) </param>
    /// <param name="pan"> audio balance of the sound file (-1.0 : left / 1.0 : right) </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int playInLoop(const int& id, const float& volume, const float& pan)
    {
      return fParent->pCall("playInLoop" , id, volume, pan);
    }

    /// <summary>
    /// Play a sine wave which specified caracteristics.
    /// </summary>
    /// <param name="frequence"> Frequence in Hertz </param>
    /// <param name="gain"> Volume Gain between 0 and 100 </param>
    /// <param name="pan"> Stereo Pan set to either {-1,0,+1} </param>
    /// <param name="duration"> Duration of the sine wave in seconds </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int playSine(const int& frequence, const int& gain, const int& pan, const float& duration)
    {
      return fParent->pCall("playSine" , frequence, gain, pan, duration);
    }

    /// <summary>
    /// Starts the playback of a wab audio stream
    /// </summary>
    /// <param name="streamName"> Path of the web audio stream </param>
    /// <param name="arg2"> arg </param>
    /// <param name="arg3"> arg </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int playWebStream(const std::string& streamName, const float& arg2, const float& arg3)
    {
      return fParent->pCall("playWebStream" , streamName, arg2, arg3);
    }

    /// <summary>
    /// Sets the master volume of the player
    /// </summary>
    /// <param name="volume"> Volume - range 0.0 to 1.0 </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setMasterVolume(const float& volume)
    {
      return fParent->pCall("setMasterVolume" , volume);
    }

    /// <summary>
    /// sets the audio panorama : -1 for left speaker / 1 for right speaker
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setPanorama(const float& arg1)
    {
      return fParent->pCall("setPanorama" , arg1);
    }

    /// <summary>
    /// Sets the volume of the player
    /// </summary>
    /// <param name="id"> Id of the process that is playing the file you want to put louder or less loud </param>
    /// <param name="volume"> Volume - range 0.0 to 1.0 </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setVolume(const int& id, const float& volume)
    {
      return fParent->pCall("setVolume" , id, volume);
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
    /// Stops all the files that are currently playing.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int stopAll()
    {
      return fParent->pCall("stopAll");
    }

    /// <summary>
    /// unloads all the files already loaded.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int unloadAllFiles()
    {
      return fParent->pCall("unloadAllFiles");
    }

    /// <summary>
    /// unloads a file previously loaded with the loadFile function
    /// </summary>
    /// <param name="id"> Id returned by the loadFile function </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int unloadFile(const int& id)
    {
      return fParent->pCall("unloadFile" , id);
    }



};

}
#endif // ALAUDIOPLAYERPROXYPOSTHANDLERREMOTE_H_

