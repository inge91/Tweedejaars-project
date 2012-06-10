/**
 * @author Aldebaran Robotics
 * Copyright (c) Aldebaran Robotics 2007, 2011 All Rights Reserved
 */

/** @file
 *  @brief
 */

#pragma once
#ifndef _LIBALCOMMON_ALCOMMON_ALPARAMTYPE_H_
#define _LIBALCOMMON_ALCOMMON_ALPARAMTYPE_H_

# include <alcommon/detail/gettype.h>
# include <cstdlib>
# include <typeinfo>

// demangle on linux
#ifndef _WIN32
# include <cxxabi.h>
#endif

/**
 * \ingroup Signature
 */
namespace AL
{
  /**
   * \brief Return a string with the type name of parameters.
   * \return "bool", "int", "float", "string", "array", "vector<int>",
   *         "vector<float>", "vector<string>", "void", "void *",
   *         "???" (= ParamError), "unknown"
   * \ingroup Signature
   */
  std::string getTypeString(int type);

  /**
   * \brief Return a string with the OS type name of parameters.
   * \return "bool", "int", "float", "string", "array", "vector<int>",
   *         "vector<float>", "vector<string>", "void", "void *",
   *         "???" (= ParamError), "unknown"
   * \ingroup Signature
   */
  template <typename T>
  std::string getParamStrType() {
    int iType = detail::_get_type<T>::value;
    if (iType != 0)
      return getTypeString(iType);
#ifndef _WIN32
    const       std::type_info &info = typeid(T);
    int         status;
    char*       realname = abi::__cxa_demangle(info.name(), 0, 0, &status);
    std::string realname_str = std::string(realname);
    free(realname);
    return realname_str;
#else
    const std::type_info &info = typeid(T);
    return info.name();
#endif
  }
}

#endif  // _LIBALCOMMON_ALCOMMON_ALPARAMTYPE_H_
