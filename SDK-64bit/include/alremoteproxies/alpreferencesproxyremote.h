// Generated for ALPreferences version 1.12

#ifndef ALPREFERENCESPROXYREMOTE_H_
#define ALPREFERENCESPROXYREMOTE_H_
#include <alremoteproxies/alpreferencesproxyposthandlerremote.h>

namespace AL
{

/// <summary>ALPreferences allows access to xml preference files. 
    ///
    /// A preference is defined as follows : 
    ///
    /// pParams[0] Name of the preference; 
    ///
    /// pParams[1] Description of the preference; 
    ///
    /// pParams[2] The value of the preference (can contain other preferences); 
    ///
    /// pParams[3] (optional) The name of the data when inserted into memory.</summary>
class ALPreferencesProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALPreferencesProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALPreferences", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALPreferencesProxyPostHandlerRemote post;


    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit()
    {

        callVoidRemote("exit");
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
    /// Just a ping. Always returns true
    /// </summary>
    /// <returns> returns true </returns>
    bool ping()
    {

        return callRemote<bool >("ping");
    }


    /// <summary>
    /// Reads all preferences from an xml files and stores them in an ALValue.
    /// </summary>
    /// <param name="fileName"> Name of the module associate to the preference. </param>
    /// <param name="autoGenerateMemoryNames"> If true a memory name will be generated for each non-array preference. </param>
    /// <returns> array reprenting the whole file. </returns>
    AL::ALValue readPrefFile(const std::string& fileName, const bool& autoGenerateMemoryNames)
    {

        return callRemote<AL::ALValue >("readPrefFile" , fileName, autoGenerateMemoryNames);
    }


    /// <summary>
    /// Writes all preferences from ALValue to an xml file.
    /// </summary>
    /// <param name="prefs"> array reprenting the whole file. </param>
    /// <returns> True upon success. </returns>
    bool saveToMemory(const AL::ALValue& prefs)
    {

        return callRemote<bool >("saveToMemory" , prefs);
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


    /// <summary>
    /// Writes all preferences from ALValue to an xml file.
    /// </summary>
    /// <param name="fileName"> Name of the module associate to the preference. </param>
    /// <param name="prefs"> array reprenting the whole file. </param>
    /// <param name="ignoreMemoryNames"> If true all memory names will be removed before saving. </param>
    void writePrefFile(const std::string& fileName, const AL::ALValue& prefs, const bool& ignoreMemoryNames)
    {

        callVoidRemote("writePrefFile" , fileName, prefs, ignoreMemoryNames);
    }


};

}
#endif // ALPREFERENCESPROXY_H_
