/**
* @author Aldebaran Robotics
* Copyright (c) Aldebaran Robotics 2007, 2011 All Rights Reserved
*/



#pragma once
#ifndef _LIBALCOMMON_ALCOMMON_DETAIL_GETTYPE_H_
#define _LIBALCOMMON_ALCOMMON_DETAIL_GETTYPE_H_

// demangle on linux
#ifndef WIN32
  #include <cxxabi.h>
#endif

#include <alvalue/alvalue.h>

namespace AL
{

  namespace detail {

    enum ParamType
    {
      ParamError = 0,
      ParamVoid  = 1,
      ParamBool  = 2,
      ParamInt   = 3,
      ParamFloat = 4,
      ParamString = 5,
      ParamALValue = 6,
      ParamConstBool = 7,
      ParamConstInt = 8,
      ParamConstFloat = 9,
      ParamConstString = 10,
      ParamConstALValue = 11,
      ParamBoolRef = 12,
      ParamIntRef = 13,
      ParamFloatRef = 14,
      ParamStringRef = 15,
      ParamALValueRef = 16,
      ParamConstBoolRef = 17,
      ParamConstIntRef = 18,
      ParamConstFloatRef = 19,
      ParamConstStringRef = 20,
      ParamConstALValueRef = 21,
      ParamVectorBool = 22,
      ParamVectorInt = 23,
      ParamVectorFloat = 24,
      ParamVectorString = 25,
      ParamVectorALValue = 26,
      ParamPointer = 27
    };

    template <typename T>
    struct _get_type                            { enum {value = ParamError}; };

    template <>
    struct _get_type<bool>                      { enum {value = ParamBool}; };

    template <>
    struct _get_type<int>                       { enum {value = ParamInt}; };

    template <>
    struct _get_type<float>                     { enum {value = ParamFloat}; };

    template <>
    struct _get_type<std::string>               { enum {value = ParamString}; };

    template <>
    struct _get_type<AL::ALValue>               { enum {value = ParamALValue}; };

    template <>
    struct _get_type<void>                      { enum {value = ParamVoid}; };

    template <typename T>
    struct _get_type<T *>                       { enum {value = ParamPointer}; };

    template <>
    struct _get_type<std::vector<int> >         { enum {value = ParamVectorInt}; };

    template <>
    struct _get_type<std::vector<float> >       { enum {value = ParamVectorFloat}; };

    template <>
    struct _get_type<std::vector<std::string> > { enum {value = ParamVectorString}; };

    template <typename T>
    struct _get_type <const T>                  { enum {value = _get_type<T>::value}; };

    template <typename T>
    struct _get_type <T&>                       { enum {value = _get_type<T>::value}; };
  }

}

#endif  // _LIBALCOMMON_ALCOMMON_DETAIL_GETTYPE_H_
