
/**
* @author Aldebaran Robotics
* Copyright (c) Aldebaran Robotics 2007, 2011 All Rights Reserved
*
*/

#pragma once

#ifndef _LIB_ALCORE_ALCORE_ALCATCHERROR_H_
#define _LIB_ALCORE_ALCORE_ALCATCHERROR_H_

#include <qi/macro.hpp>

QI_DEPRECATED_HEADER(AL_CATCH_ERR is deprecated)

#include <sstream>
#include <iostream>
#include <alerror/alerror.h>


// TODO ... does this really have "raison d'etre" ?
#define AL_CATCH_ERR(commandToExecuteAfterPrintingError) \
  catch (const AL::ALError& err ) { \
    std::stringstream ss; \
    std::string strNumLine; \
    ss << __LINE__; \
    ss >> strNumLine; \
    std::cout << "WARNING: Exception caught: " << err.toString() << \
      " from " << __FILE__ << ":" << strNumLine << std::endl; \
    commandToExecuteAfterPrintingError; \
  }
#endif  // _LIB_ALCORE_ALCORE_ALCATCHERROR_H_
