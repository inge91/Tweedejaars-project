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
#ifndef _LIBNAOQICLIENT_NAOQICLIENT_API_H_
#define _LIBNAOQICLIENT_NAOQICLIENT_API_H_

#include <qi/macro.hpp>

#ifdef naoqiclient_EXPORTS
# define NAOQICLIENT_API QI_EXPORT_API
#else
# define NAOQICLIENT_API QI_IMPORT_API
#endif

#endif  // _LIBNAOQICLIENT_NAOQICLIENT_API_H_

