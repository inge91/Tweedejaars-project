// Generated for ALPreferences version 1.12

#ifndef ALPREFERENCESPROXYPOSTHANDLER_H_
#define ALPREFERENCESPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALPreferencesProxy;

/// <summary>
/// ALPreferences allows access to xml preference files. 
    ///
    /// A preference is defined as follows : 
    ///
    /// pParams[0] Name of the preference; 
    ///
    /// pParams[1] Description of the preference; 
    ///
    /// pParams[2] The value of the preference (can contain other preferences); 
    ///
    /// pParams[3] (optional) The name of the data when inserted into memory.
/// ALPreferencesPostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALPreferencesProxyPostHandler
{
  friend class ALPreferencesProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// ALPreferences allows access to xml preference files. 
    ///
    /// A preference is defined as follows : 
    ///
    /// pParams[0] Name of the preference; 
    ///
    /// pParams[1] Description of the preference; 
    ///
    /// pParams[2] The value of the preference (can contain other preferences); 
    ///
    /// pParams[3] (optional) The name of the data when inserted into memory.
  /// ALPreferencesPostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALPreferencesProxyPostHandler();

  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
  /// <summary>
  /// Writes all preferences from ALValue to an xml file.
  /// </summary>
  /// <param name="fileName"> Name of the module associate to the preference. </param>
  /// <param name="prefs"> array reprenting the whole file. </param>
  /// <param name="ignoreMemoryNames"> If true all memory names will be removed before saving. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int writePrefFile(const std::string& fileName, const AL::ALValue& prefs, const bool& ignoreMemoryNames);
};

}
#endif // ALPREFERENCESPROXYPOSTHANDLER_H_

