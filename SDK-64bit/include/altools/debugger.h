/*
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2010 Aldebaran Robotics
*/

#pragma once

#ifndef _LIB_ALTOOLS_ALTOOLS_DEBUGGER_H_
#define _LIB_ALTOOLS_ALTOOLS_DEBUGGER_H_

#include <qi/macro.hpp>

QI_DEPRECATED_HEADER(Use qi::os::check_debugger instead.)

namespace AL {
  /* return true if we are running in a debugger */
  int check_debugger();
};

#endif  // _LIB_ALTOOLS_ALTOOLS_DEBUGGER_H_
