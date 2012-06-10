/**
* @author Aldebaran-Robotics
* Aldebaran Robotics (c) 2009 All Rights Reserved
*/

#pragma once

#ifndef _LIB_ALBEHAVIORINFO_ALBEHAVIORLIST_H_
#define _LIB_ALBEHAVIORINFO_ALBEHAVIORLIST_H_

#include "albehaviorinfo.h"

#include <vector>
#include <string>
#include <map>

namespace AL
{
  class ALBehaviorList
  {
  public:
    void addBehavior(const std::string &pName, const std::vector<std::string> pResource, std::string pCondition);
    inline std::vector<ALBehaviorInfo> &getBehaviorList(void){ return fBehaviorList;}

  private:
    std::vector<ALBehaviorInfo> fBehaviorList;
  };
}
#endif  // _LIB_ALBEHAVIORINFO_ALBEHAVIORLIST_H_

