// Generated for ALLogger version 1.12

#ifndef ALLOGGERPROXYPOSTHANDLER_H_
#define ALLOGGERPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALLoggerProxy;

/// <summary>
/// This module allows you log errors, warnings, and info stdout or a file. The verbosity level allow you to  customize the output.
/// ALLoggerPostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALLoggerProxyPostHandler
{
  friend class ALLoggerProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// This module allows you log errors, warnings, and info stdout or a file. The verbosity level allow you to  customize the output.
  /// ALLoggerPostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALLoggerProxyPostHandler();

  /// <summary>
  /// DEPRECATED. Use qiLogDebug instead. 
    ///
    ///  Log a debug message.
  /// </summary>
  /// <param name="moduleName"> Name of the module. </param>
  /// <param name="message"> Log Message. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int debug(const std::string& moduleName, const std::string& message);
  /// <summary>
  /// DEPRECATED. Use qiLogError instead. 
    ///
    ///  Log an error.
  /// </summary>
  /// <param name="moduleName"> Name of the module. </param>
  /// <param name="message"> Log Message. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int error(const std::string& moduleName, const std::string& message);
  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// DEPRECATED. Use qiLogFatal instead. 
    ///
    ///  Log a fatal error.
  /// </summary>
  /// <param name="moduleName"> Name of the module. </param>
  /// <param name="message"> Log Message. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int fatal(const std::string& moduleName, const std::string& message);
  /// <summary>
  /// DEPRECATED. Use qiLogInfo instead. 
    ///
    ///  Log a info message.
  /// </summary>
  /// <param name="moduleName"> Name of the module. </param>
  /// <param name="message"> Log Message. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int info(const std::string& moduleName, const std::string& message);
  /// <summary>
  /// DEPRECATED. Create your own log handler with qilog and add it with qi::log::addHandler. See libqi documentation for more details. 
    ///
    ///  Allows the logger to store logs in a file. Warning: this is not recomended on Nao.
  /// </summary>
  /// <param name="fileName"> The fileName to use. Relative to the user naoqi folder. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int logInFile(const std::string& fileName);
  /// <summary>
  /// DEPRECATED. Should not be used. Publish logs to a Log Forwarder. Pass an empty string in order to use the default value:  \"tcp://localhost:50998\"
  /// </summary>
  /// <param name="inputAddress"> Desired input ZMQ address of the Log Forwarder. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int logInForwarder(const std::string& inputAddress);
  /// <summary>
  /// Removed: not implemented anymore.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int logInStd();
  /// <summary>
  /// Removed: not implemented anymore.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int logInSys();
  /// <summary>
  /// Same method as debug, which is deprecated itself.
  /// </summary>
  /// <param name="arg1"> arg </param>
  /// <param name="arg2"> arg </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int lowDebug(const std::string& arg1, const std::string& arg2);
  /// <summary>
  /// Same method as info, which is deprecated itself.
  /// </summary>
  /// <param name="arg1"> arg </param>
  /// <param name="arg2"> arg </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int lowInfo(const std::string& arg1, const std::string& arg2);
  /// <summary>
  /// Do not use since we cannot add any handler with the API.
  /// </summary>
  /// <param name="arg1"> arg </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int removeHandler(const std::string& arg1);
  /// <summary>
  /// DEPRECATED. Can be easily replaced if needed.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int separator();
  /// <summary>
  /// Removed: not implemented anymore.
  /// </summary>
  /// <param name="arg1"> arg </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setFilter(const std::string& arg1);
  /// <summary>
  /// Removed: not implemented anymore.
  /// </summary>
  /// <param name="arg1"> arg </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setVerbosity(const std::string& arg1);
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
  /// <summary>
  /// DEPRECATED: use qiLogWarning instead. Log a warning.
  /// </summary>
  /// <param name="moduleName"> Name of the module. </param>
  /// <param name="message"> Log Message. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int warn(const std::string& moduleName, const std::string& message);
};

}
#endif // ALLOGGERPROXYPOSTHANDLER_H_

