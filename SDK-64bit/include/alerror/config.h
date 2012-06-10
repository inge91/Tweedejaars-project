/**
 * Author(s):
 *  - Cedric GESTES <gestes@aldebaran-robotics.com>
 *
 * Copyright (C) 2011 Aldebaran Robotics
 */

/** @file
 *  @brief dll import/export
 */

#pragma once
#ifndef _LIBALERROR_ALERROR_CONFIG_H_
#define _LIBALERROR_ALERROR_CONFIG_H_

#if defined _WIN32 || defined __CYGWIN__
#  define ALERROR_EXPORT_API __declspec(dllexport)
#  if defined _WINDLL
#    define ALERROR_IMPORT_API __declspec(dllimport)
#  else
#    define ALERROR_IMPORT_API
#  endif
#elif __GNUC__ >= 4
#  define ALERROR_EXPORT_API __attribute__ ((visibility("default")))
#  define ALERROR_IMPORT_API __attribute__ ((visibility("default")))
#else
#  define ALERROR_EXPORT_API
#  define ALERROR_IMPORT_API
#endif

#ifdef alerror_EXPORTS
# define ALERROR_API ALERROR_EXPORT_API
#elif defined(alerror_IMPORTS)
# define ALERROR_API ALERROR_IMPORT_API
#else
# define ALERROR_API
#endif

// Deprecated
#if defined(__GNUC__) && defined(WITH_DEPRECATED) && !defined(QI_NO_API_DEPRECATED)
#  define QI_API_DEPRECATED __attribute__((deprecated))
#elif defined(_MSC_VER) && defined(WITH_DEPRECATED) && !defined(QI_NO_API_DEPRECATED)
#  define QI_API_DEPRECATED __declspec(deprecated)
#else
#  define QI_API_DEPRECATED
#endif

#endif  // _LIBALERROR_ALERROR_CONFIG_H_

