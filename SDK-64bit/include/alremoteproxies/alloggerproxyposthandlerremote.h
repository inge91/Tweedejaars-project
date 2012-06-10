// Generated for ALLogger version 1.12


#ifndef ALLOGGERPROXYPOSTHANDLERREMOTE_H_
#define ALLOGGERPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALLoggerProxyRemote;

/// <summary>This module allows you log errors, warnings, and info stdout or a file. The verbosity level allow you to  customize the output.</summary>
class ALLoggerProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALLoggerProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// This module allows you log errors, warnings, and info stdout or a file. The verbosity level allow you to  customize the output.
    /// ALLoggerPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALLoggerProxyPostHandlerRemote() : fParent(NULL)
    {}



    /// <summary>
    /// DEPRECATED. Use qiLogDebug instead. 
    ///
    ///  Log a debug message.
    /// </summary>
    /// <param name="moduleName"> Name of the module. </param>
    /// <param name="message"> Log Message. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int debug(const std::string& moduleName, const std::string& message)
    {
      return fParent->pCall("debug" , moduleName, message);
    }

    /// <summary>
    /// DEPRECATED. Use qiLogError instead. 
    ///
    ///  Log an error.
    /// </summary>
    /// <param name="moduleName"> Name of the module. </param>
    /// <param name="message"> Log Message. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int error(const std::string& moduleName, const std::string& message)
    {
      return fParent->pCall("error" , moduleName, message);
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
    /// DEPRECATED. Use qiLogFatal instead. 
    ///
    ///  Log a fatal error.
    /// </summary>
    /// <param name="moduleName"> Name of the module. </param>
    /// <param name="message"> Log Message. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int fatal(const std::string& moduleName, const std::string& message)
    {
      return fParent->pCall("fatal" , moduleName, message);
    }






    /// <summary>
    /// DEPRECATED. Use qiLogInfo instead. 
    ///
    ///  Log a info message.
    /// </summary>
    /// <param name="moduleName"> Name of the module. </param>
    /// <param name="message"> Log Message. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int info(const std::string& moduleName, const std::string& message)
    {
      return fParent->pCall("info" , moduleName, message);
    }


    /// <summary>
    /// DEPRECATED. Create your own log handler with qilog and add it with qi::log::addHandler. See libqi documentation for more details. 
    ///
    ///  Allows the logger to store logs in a file. Warning: this is not recomended on Nao.
    /// </summary>
    /// <param name="fileName"> The fileName to use. Relative to the user naoqi folder. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int logInFile(const std::string& fileName)
    {
      return fParent->pCall("logInFile" , fileName);
    }

    /// <summary>
    /// DEPRECATED. Should not be used. Publish logs to a Log Forwarder. Pass an empty string in order to use the default value:  \"tcp://localhost:50998\"
    /// </summary>
    /// <param name="inputAddress"> Desired input ZMQ address of the Log Forwarder. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int logInForwarder(const std::string& inputAddress)
    {
      return fParent->pCall("logInForwarder" , inputAddress);
    }

    /// <summary>
    /// Removed: not implemented anymore.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int logInStd()
    {
      return fParent->pCall("logInStd");
    }

    /// <summary>
    /// Removed: not implemented anymore.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int logInSys()
    {
      return fParent->pCall("logInSys");
    }

    /// <summary>
    /// Same method as debug, which is deprecated itself.
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <param name="arg2"> arg </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int lowDebug(const std::string& arg1, const std::string& arg2)
    {
      return fParent->pCall("lowDebug" , arg1, arg2);
    }

    /// <summary>
    /// Same method as info, which is deprecated itself.
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <param name="arg2"> arg </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int lowInfo(const std::string& arg1, const std::string& arg2)
    {
      return fParent->pCall("lowInfo" , arg1, arg2);
    }


    /// <summary>
    /// Do not use since we cannot add any handler with the API.
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int removeHandler(const std::string& arg1)
    {
      return fParent->pCall("removeHandler" , arg1);
    }

    /// <summary>
    /// DEPRECATED. Can be easily replaced if needed.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int separator()
    {
      return fParent->pCall("separator");
    }

    /// <summary>
    /// Removed: not implemented anymore.
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setFilter(const std::string& arg1)
    {
      return fParent->pCall("setFilter" , arg1);
    }

    /// <summary>
    /// Removed: not implemented anymore.
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setVerbosity(const std::string& arg1)
    {
      return fParent->pCall("setVerbosity" , arg1);
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
    /// DEPRECATED: use qiLogWarning instead. Log a warning.
    /// </summary>
    /// <param name="moduleName"> Name of the module. </param>
    /// <param name="message"> Log Message. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int warn(const std::string& moduleName, const std::string& message)
    {
      return fParent->pCall("warn" , moduleName, message);
    }

};

}
#endif // ALLOGGERPROXYPOSTHANDLERREMOTE_H_

