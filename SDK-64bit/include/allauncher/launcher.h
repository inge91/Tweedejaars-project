#pragma once
/* -*- Mode: C++;  -*- */
/*
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2011 Cedric GESTES
*/


#ifndef _LIB_ALLAUNCHER_ALLAUNCHER_LAUNCHER_H_
#define _LIB_ALLAUNCHER_ALLAUNCHER_LAUNCHER_H_

#include <map>
#include <string>
#include <vector>

#include <boost/shared_ptr.hpp>

namespace AL
{
  class ALSharedLibrary;
  class ALBroker;


  /**
   * A class to use to launch/remove module at demand
   *
   * FIXME: add a unloadLibrary() function?
   */
  class Launcher
  {
  public:
    Launcher(const boost::shared_ptr<AL::ALBroker> pBroker);

    typedef std::map< std::string, std::vector<std::string> > AutoLoadMap;


    /**
     * Parse the user autoload.ini (/home/nao/naoqi/preferences/autoload.ini)
     * file and try to launch everything.
     * Errors are caught and printed: does not throw on error.
     */
    void loadUserAutoload(const std::vector<std::string> &blacklist = std::vector<std::string>());

    /**
     * Parse the autoload.ini file and try to launch everything.
     * Errors are caught and printed: does not throw on error.
     */
    void loadAutoload(const std::vector<std::string> &blacklist = std::vector<std::string>());

    /**
     * Load a library inside the broker.
     * Throw on error.
     */
    void loadLibrary(const std::string &moduleName);
    int loadProgram(const std::string &programPath);
    int loadPython(const std::string &scriptPath);

  private:
    AutoLoadMap parseIni(const std::string &filename);
    void loadSection(AutoLoadMap amap, const std::string &name, const std::vector<std::string> &blacklist);

  private:
    boost::shared_ptr<AL::ALBroker>     _broker;
    std::vector<std::string>            _sdkPrefix;
  };

} // namespace AL

#endif  // _LIB_ALLAUNCHER_ALLAUNCHER_LAUNCHER_H_
