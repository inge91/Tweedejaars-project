// Generated for ALFileManager version 1.12


#ifndef ALFILEMANAGERPROXYPOSTHANDLERREMOTE_H_
#define ALFILEMANAGERPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALFileManagerProxyRemote;

/// <summary>ALFileManager manages the user files stored in a shared folder.
    ///
    /// Note that FileManager starts to look in the shared folder, and if it does not find anything,
    ///
    /// then it looks in the data folder.
    ///
    /// Shared folder can be changed on the fly, and module will then be able to say which
    ///
    /// files are available in this folder, as well as return their complete path.</summary>
class ALFileManagerProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALFileManagerProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// ALFileManager manages the user files stored in a shared folder.
    ///
    /// Note that FileManager starts to look in the shared folder, and if it does not find anything,
    ///
    /// then it looks in the data folder.
    ///
    /// Shared folder can be changed on the fly, and module will then be able to say which
    ///
    /// files are available in this folder, as well as return their complete path.
    /// ALFileManagerPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALFileManagerProxyPostHandlerRemote() : fParent(NULL)
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
    /// Set a new value of the user shared folder path.
    /// </summary>
    /// <param name="fileName"> Name of the module associate to the preference. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setUserSharedFolderPath(const std::string& fileName)
    {
      return fParent->pCall("setUserSharedFolderPath" , fileName);
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
#endif // ALFILEMANAGERPROXYPOSTHANDLERREMOTE_H_

