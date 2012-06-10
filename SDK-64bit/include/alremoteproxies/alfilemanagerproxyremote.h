// Generated for ALFileManager version 1.12

#ifndef ALFILEMANAGERPROXYREMOTE_H_
#define ALFILEMANAGERPROXYREMOTE_H_
#include <alremoteproxies/alfilemanagerproxyposthandlerremote.h>

namespace AL
{

/// <summary>ALFileManager manages the user files stored in a shared folder.
    ///
    /// Note that FileManager starts to look in the shared folder, and if it does not find anything,
    ///
    /// then it looks in the data folder.
    ///
    /// Shared folder can be changed on the fly, and module will then be able to say which
    ///
    /// files are available in this folder, as well as return their complete path.</summary>
class ALFileManagerProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALFileManagerProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALFileManager", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALFileManagerProxyPostHandlerRemote post;


    /// <summary>
    /// Try to find if this file does exist on robot or not.
    /// </summary>
    /// <param name="fileName"> Name of the module associate to the preference. </param>
    /// <returns> True upon success </returns>
    bool dataFileExists(const std::string& fileName)
    {

        return callRemote<bool >("dataFileExists" , fileName);
    }


    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit()
    {

        callVoidRemote("exit");
    }


    /// <summary>
    /// Try to find if this file does exist on robot or not.
    /// </summary>
    /// <param name="fileName"> Name of the module associate to the preference. </param>
    /// <returns> True upon success </returns>
    bool fileExists(const std::string& fileName)
    {

        return callRemote<bool >("fileExists" , fileName);
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
    /// Returns the complete path of the file if it does exist. Starts by looking in user's shared folder, then in system folder.
    /// </summary>
    /// <param name="prefs"> array reprenting the whole file. </param>
    /// <returns> True upon success </returns>
    std::string getFileCompletePath(const std::string& prefs)
    {

        return callRemote<std::string >("getFileCompletePath" , prefs);
    }


    /// <summary>
    /// Returns the complete path of the file if it does exist. Starts by looking in user's shared folder, then in system folder.
    /// </summary>
    /// <param name="prefs"> array reprenting the whole file. </param>
    /// <returns> True upon success </returns>
    AL::ALValue getFileContents(const std::string& prefs)
    {

        return callRemote<AL::ALValue >("getFileContents" , prefs);
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
    /// Get the current system shared folder path.
    /// </summary>
    /// <returns> System shared folder path string. </returns>
    std::string getSystemSharedFolderPath()
    {

        return callRemote<std::string >("getSystemSharedFolderPath");
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
    /// Get the current user shared folder path.
    /// </summary>
    /// <returns> User shared folder path string. </returns>
    std::string getUserSharedFolderPath()
    {

        return callRemote<std::string >("getUserSharedFolderPath");
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
    /// Just a ping. Always returns true
    /// </summary>
    /// <returns> returns true </returns>
    bool ping()
    {

        return callRemote<bool >("ping");
    }


    /// <summary>
    /// Set a new value of the user shared folder path.
    /// </summary>
    /// <param name="fileName"> Name of the module associate to the preference. </param>
    void setUserSharedFolderPath(const std::string& fileName)
    {

        callVoidRemote("setUserSharedFolderPath" , fileName);
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
#endif // ALFILEMANAGERPROXY_H_
