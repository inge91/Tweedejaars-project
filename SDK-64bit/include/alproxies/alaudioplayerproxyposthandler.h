// Generated for ALAudioPlayer version 1.12

#ifndef ALAUDIOPLAYERPROXYPOSTHANDLER_H_
#define ALAUDIOPLAYERPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALAudioPlayerProxy;

/// <summary>
/// This module allows to play wav and mp3 files on NAO
/// ALAudioPlayerPostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALAudioPlayerProxyPostHandler
{
  friend class ALAudioPlayerProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// This module allows to play wav and mp3 files on NAO
  /// ALAudioPlayerPostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALAudioPlayerProxyPostHandler();

  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// Goes to a given position in a file which is playing.
  /// </summary>
  /// <param name="playId"> Id of the process which is playing the file </param>
  /// <param name="position"> Position in the file (in second) </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int goTo(const int& playId, const float& position);
  /// <summary>
  /// Pause a play back
  /// </summary>
  /// <param name="id"> Id of the process that is playing the file you want to put in pause </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int pause(const int& id);
  /// <summary>
  /// Starts the playback of a file preloaded with the loadFile function.
  /// </summary>
  /// <param name="id"> Id returned by the loadFile function </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int play(const int& id);
  /// <summary>
  /// Starts the playback of a file preloaded with the loadFile function, with specific volume and audio balance
  /// </summary>
  /// <param name="id"> Id returned by the loadFile function </param>
  /// <param name="volume"> volume of the sound file (must be between 0.0 and 1.0) </param>
  /// <param name="pan"> audio balance of the sound file (-1.0 : left / 1.0 : right) </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int play(const int& id, const float& volume, const float& pan);
  /// <summary>
  /// Plays a wav or mp3 file
  /// </summary>
  /// <param name="fileName"> Path of the sound file </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int playFile(const std::string& fileName);
  /// <summary>
  /// Plays a wav or mp3 file, with specific volume and audio balance
  /// </summary>
  /// <param name="fileName"> Path of the sound file </param>
  /// <param name="volume"> volume of the sound file (must be between 0.0 and 1.0) </param>
  /// <param name="pan"> audio balance of the sound file (-1.0 : left / 1.0 : right / 0.0 : centered) </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int playFile(const std::string& fileName, const float& volume, const float& pan);
  /// <summary>
  /// Plays a wav or mp3 file from a given position in the file.
  /// </summary>
  /// <param name="fileName"> Name of the sound file </param>
  /// <param name="position"> Position in second where the playing has to begin </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int playFileFromPosition(const std::string& fileName, const float& position);
  /// <summary>
  /// Plays a wav or mp3 file from a given position in the file, with specific volume and audio balance
  /// </summary>
  /// <param name="fileName"> Name of the sound file </param>
  /// <param name="position"> Position in second where the playing has to begin </param>
  /// <param name="volume"> volume of the sound file (must be between 0.0 and 1.0) </param>
  /// <param name="pan"> audio balance of the sound file (-1.0 : left / 1.0 : right) </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int playFileFromPosition(const std::string& fileName, const float& position, const float& volume, const float& pan);
  /// <summary>
  /// Plays a wav or mp3 file in loop
  /// </summary>
  /// <param name="fileName"> Path of the sound file </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int playFileInLoop(const std::string& fileName);
  /// <summary>
  /// Plays a wav or mp3 file in loop, with specific volume and audio balance
  /// </summary>
  /// <param name="fileName"> Path of the sound file </param>
  /// <param name="volume"> volume of the sound file (must be between 0.0 and 1.0) </param>
  /// <param name="pan"> audio balance of the sound file (-1.0 : left / 1.0 : right) </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int playFileInLoop(const std::string& fileName, const float& volume, const float& pan);
  /// <summary>
  /// Starts the playback in loop of a file preloaded with the loadFile function
  /// </summary>
  /// <param name="id"> Id returned by the loadFile function </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int playInLoop(const int& id);
  /// <summary>
  /// Plays a wav or mp3 file in loop, with specific volume and audio balance
  /// </summary>
  /// <param name="id"> Id returned by the loadFile function </param>
  /// <param name="volume"> volume of the sound file (must be between 0.0 and 1.0) </param>
  /// <param name="pan"> audio balance of the sound file (-1.0 : left / 1.0 : right) </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int playInLoop(const int& id, const float& volume, const float& pan);
  /// <summary>
  /// Play a sine wave which specified caracteristics.
  /// </summary>
  /// <param name="frequence"> Frequence in Hertz </param>
  /// <param name="gain"> Volume Gain between 0 and 100 </param>
  /// <param name="pan"> Stereo Pan set to either {-1,0,+1} </param>
  /// <param name="duration"> Duration of the sine wave in seconds </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int playSine(const int& frequence, const int& gain, const int& pan, const float& duration);
  /// <summary>
  /// Starts the playback of a wab audio stream
  /// </summary>
  /// <param name="streamName"> Path of the web audio stream </param>
  /// <param name="arg2"> arg </param>
  /// <param name="arg3"> arg </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int playWebStream(const std::string& streamName, const float& arg2, const float& arg3);
  /// <summary>
  /// Sets the master volume of the player
  /// </summary>
  /// <param name="volume"> Volume - range 0.0 to 1.0 </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setMasterVolume(const float& volume);
  /// <summary>
  /// sets the audio panorama : -1 for left speaker / 1 for right speaker
  /// </summary>
  /// <param name="arg1"> arg </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setPanorama(const float& arg1);
  /// <summary>
  /// Sets the volume of the player
  /// </summary>
  /// <param name="id"> Id of the process that is playing the file you want to put louder or less loud </param>
  /// <param name="volume"> Volume - range 0.0 to 1.0 </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setVolume(const int& id, const float& volume);
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
  /// <summary>
  /// Stops all the files that are currently playing.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stopAll();
  /// <summary>
  /// unloads all the files already loaded.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int unloadAllFiles();
  /// <summary>
  /// unloads a file previously loaded with the loadFile function
  /// </summary>
  /// <param name="id"> Id returned by the loadFile function </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int unloadFile(const int& id);
};

}
#endif // ALAUDIOPLAYERPROXYPOSTHANDLER_H_

