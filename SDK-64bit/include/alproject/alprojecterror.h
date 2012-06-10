/**
 * @author Jerome Vuarand
 * Copyright (c) Aldebaran Robotics 2010 All Rights Reserved
 */

#pragma once

#ifndef _LIB_ALPROJECT_SRC_ALPROJECT_ALPROJECTERROR_H_
#define _LIB_ALPROJECT_SRC_ALPROJECT_ALPROJECTERROR_H_

#include <alerror/alerror.h>

namespace AL
{

class ALProjectError : public ALError
{
public:
  ALProjectError(const std::string& pModuleName, const std::string& pMethod, const std::string& pDescription, const char* pszFilename = 0, const int pnNumLine = 0)
    : ALError(pModuleName, pMethod, pDescription, pszFilename, pnNumLine)
    , fDescription(pDescription)
  { }
  ~ALProjectError() throw() { }

  std::string description() const { return fDescription; }

private:
  std::string fDescription;
};

#define ALPROJECTERROR(module,methode,description) AL::ALProjectError(module,methode,description,__FILE__,__LINE__)

}


#endif  // _LIB_ALPROJECT_SRC_ALPROJECT_ALPROJECTERROR_H_
