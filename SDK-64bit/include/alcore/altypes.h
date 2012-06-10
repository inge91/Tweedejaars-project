/**
* @author Aldebaran Robotics
* Copyright (c) Aldebaran Robotics 2007, 2011 All Rights Reserved
*/
#pragma once

#ifndef _LIB_ALCORE_ALCORE_ALTYPES_H_
#define _LIB_ALCORE_ALCORE_ALTYPES_H_

#include <string>
#include <vector>

#ifndef SOAP_EOF
#define SOAP_EOF  EOF
#endif

#ifndef SOAP_ERR
#define SOAP_ERR  EOF
#endif

#ifndef SOAP_OK
#define SOAP_OK  0
#endif

// standard type definitions
#ifndef uint32_defined
#  define uint32_defined
//uint32_defined does not mean what it does... dont use it
#  ifndef ALTYPES_DEFINED
#    define ALTYPES_DEFINED
typedef unsigned long uInt32;
typedef signed long sInt32;
typedef unsigned short uInt16;
typedef signed short sInt16;
typedef unsigned char uInt8;
typedef signed char sInt8;
typedef unsigned char uChar;
typedef signed char sChar;
#  endif // ALTYPES_DEFINED
#endif // uint32_defined

// Operating systems
const int kLinux = 0;
const int kWindows = 1;
const int kMacOS = 2;
const int kOther = 3;

// Broker port
const int kBrokerPort = 9559;
const int kMemoryPort = 9560;

// Communication mode
const int kLocal = 0;
const int kPlugged = 0;
const int kRemote = 1;

// Other
const int kForever = -1;

// Vision
const sInt32 kDefaultImageWidth  = 640;
const sInt32 kDefaultImageHeight = 480;


// Class definitions
namespace AL
{

#ifndef ALVALUE_VERBOSITY
# define ALVALUE_VERBOSITY
  typedef enum _TVerbosity
  {
    VerbosityNone=0,
    VerbosityMini,
    VerbosityMedium,
    VerbosityFull
  }
  Verbosity;
#endif

  typedef enum _TLanguageID
  {
    Language_En = 0,  // anglais Britain
    Language_Us,      // anglais american
    Language_Fr,      // Francais
    Language_It,      // Italian
    Language_Sp,      // Spanish
    Language_Ge,      // German
    Language_Ch,      // Chinese
    Language_Ko,      // Korean
    Language_Jp,      // Japanese
    Language_Po,      // Portuguese
    Language_Number,  // the number of different language
    Language_Unknown
  }
  TLanguageID;

} // namespace AL

typedef std::vector<std::string>            TStringArray;
typedef std::vector<float>                  TFloatArray;
typedef std::vector<int>                    TIntArray;

typedef TStringArray::iterator              ITStringArray;
typedef TStringArray::const_iterator        CITStringArray;

typedef TFloatArray::iterator               ITFloatArray;
typedef TFloatArray::const_iterator         CITFloatArray;

typedef TIntArray::iterator                 ITIntArray;
typedef TIntArray::const_iterator           CITIntArray;

#define AL_OK SOAP_OK
#define AL_ERR SOAP_ERR

// alcommon options
//#define AL_PERF_CALCULATION
//#define DEBUG_TASK_VIEWER
//#define DEBUG_TASK_MSG(x);
#define DEBUG_TASK_MSG(x)
#endif  // _LIB_ALCORE_ALCORE_ALTYPES_H_

