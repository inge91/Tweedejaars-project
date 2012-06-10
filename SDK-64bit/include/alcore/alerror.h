
/**
* @author Aldebaran Robotics
* Copyright (c) Aldebaran Robotics 2007, 2011 All Rights Reserved
*/

#pragma once

#ifndef _LIB_ALCORE_ALCORE_ALERROR_H_
#define _LIB_ALCORE_ALCORE_ALERROR_H_

#include <qi/macro.hpp>

QI_DEPRECATED_HEADER("To catch ALCommon exception use alerror")

#include <exception>
#include <assert.h>
#include <string>

#define ALERROR_PRINT_CATCHED(err) printf( "WARNING: Catching this error: '%s'\n", err.toString().c_str() )

// Help out windows:
#if defined( _DEBUG ) && !defined( DEBUG )
#define DEBUG
#endif

// moving AL_ASSERT from altools because of use of ALERROR
#define AL_ASSERT(b) assert(b);

// AL_VERIFY is like AL_ASSERT, except the expression is evaluated even in release and can have side effects
#define AL_VERIFY(b) AL_ASSERT(b)

#define AL_ERROR_EXIT_OK                  0
#define AL_ERROR_EXIT_CODE_NETWORK_BUSY -15

#include <alerror/alerror.h>
#include <alcore/alcatcherror.h>
#endif  // _LIB_ALCORE_ALCORE_ALERROR_H_
