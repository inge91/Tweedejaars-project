/**
* @author Aldebaran Robotics
* Copyright (c) Aldebaran Robotics 2007, 2011 All Rights Reserved
*/


/**
* Module that manage all system functionalities (linux, win32...)
*/

#pragma once

#ifndef _LIB_ALTOOLS_ALTOOLS_ALSYSTEM_H_
#define _LIB_ALTOOLS_ALTOOLS_ALSYSTEM_H_

#include <iostream>
#include <fstream>
#include <sstream>

#include <cstdlib>
#include <stdio.h>

#include <qi/macro.hpp>

QI_DEPRECATED_HEADER(Please use qi::os instead);

#define MAXDIRSIZE 1000

namespace AL
{

  const std::string strModulePath = "/lib/naoqi/";
  const std::string strModuleBinPath = "/bin/";
  const std::string strBinPath = "/bin/";

  class ALSystem
  {
  public:

    static std::string getHostName();

    static FILE * fOpen(const std::string & pathLib,
        const char * mode);

    static std::string getCurrentDir(void);

    static std::string getEnv(const std::string& pStrEnv);

    static void setEnv (const std::string& pStrEnv,
        const std::string& pStrValue);

    static void setEnvForce (const std::string& pStrEnv,
        const std::string& pStrValue,
        bool pForce);

    // Return the eth0 mac adress. Linux only.
    // Return 0 on error or not available, and hwaddr[0] = 0;
    static int getEthernetMacAddr(char hwaddr[18]);
  };
}


#endif  // _LIB_ALTOOLS_ALTOOLS_ALSYSTEM_H_
