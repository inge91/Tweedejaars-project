/**
* @author Aldebaran Robotics
* Copyright (c) Aldebaran Robotics 2007 All Rights Reserved
*/


#pragma once

#ifndef _LIB_ALTOOLS_ALTOOLS_ALXPLATFORM_H_
#define _LIB_ALTOOLS_ALTOOLS_ALXPLATFORM_H_

#include <qi/macro.hpp>

QI_DEPRECATED_HEADER(Use stdtypes.h instead.)


#ifndef NDEBUG
# ifndef DEBUG
#    define DEBUG
# endif
# ifndef _DEBUG
#    define _DEBUG
# endif
#endif

// standard type definitions
#ifndef uint32_defined
# define uint32_defined
  typedef unsigned long uInt32;
  typedef signed long sInt32;
  typedef unsigned short uInt16;
  typedef signed short sInt16;
  typedef unsigned char uInt8;
  typedef signed char sInt8;
  typedef unsigned char uChar;
  typedef signed char sChar;
#endif // uint32_defined

#ifdef WIN32
# define strdup _strdup
# include "Windows.h" // for Sleep (Winbase.h)
# include <direct.h> // for _chdir
# define chdir _chdir
# define unlink _unlink
#else
# include <unistd.h> // for chdir
#endif

#if defined(__APPLE__) || defined(__linux__)
#  define SleepMs(millisec) usleep(millisec*1000)
#endif
#if defined(_WIN32)
#  define SleepMs(millisec) Sleep(millisec)
#endif

// Alma 08-04-03: Temporary addition TODO: is useful ?
#ifdef WIN32
# define ALRANDOM(maxExclus) (rand()%(int)(maxExclus))
#else
# define ALRANDOM(maxExclus) (rand()%(int)(maxExclus))
#endif

#endif  // _LIB_ALTOOLS_ALTOOLS_ALXPLATFORM_H_

