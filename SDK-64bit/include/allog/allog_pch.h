
#pragma once

#ifndef _LIB_ALLOG_ALLOG_ALLOG_PCH_H_
#define _LIB_ALLOG_ALLOG_ALLOG_PCH_H_

// only do this when using an MS compiler
#if _MSC_VER > 1000

#pragma message( "Using pre-compiled headers\n" )

// Include files that are used in many places and change infrequently.

// Reduce the size of the winAPI: no comm, no sound
//#define WIN32_LEAN_AND_MEAN

// MS Stuff
#include "crtdefs.h"
#include "assert.h"



#endif // _MSC_VER

#endif  // _LIB_ALLOG_ALLOG_ALLOG_PCH_H_
