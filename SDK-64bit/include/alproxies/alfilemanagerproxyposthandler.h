// Generated for ALFileManager version 1.12

#ifndef ALFILEMANAGERPROXYPOSTHANDLER_H_
#define ALFILEMANAGERPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALFileManagerProxy;

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
/// ALFileManagerPostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALFileManagerProxyPostHandler
{
  friend class ALFileManagerProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

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
  /// ALFileManagerPostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALFileManagerProxyPostHandler();

  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// Set a new value of the user shared folder path.
  /// </summary>
  /// <param name="fileName"> Name of the module associate to the preference. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setUserSharedFolderPath(const std::string& fileName);
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
};

}
#endif // ALFILEMANAGERPROXYPOSTHANDLER_H_

