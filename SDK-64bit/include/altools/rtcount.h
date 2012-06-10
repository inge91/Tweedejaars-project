/**
* @author Aldebaran Robotics
* Copyright (c) Aldebaran Robotics 2007 All Rights Reserved
*/

#include <altools/altime.h>

#include <qi/macro.hpp>

QI_DEPRECATED_HEADER(Just do not use...)


/**
* Module where to put all various common tools to aldebaran naoqi, naoqicore, modules...
* It's only some small functions not doing any network message / remote connection...
*/

#ifndef RTCOUNT_H
#define RTCOUNT_H

namespace AL
{
  class RTCount: public ALTime
  {
  public:
    RTCount();
    // return number of tic in duration
    int tic(const ALTime& pDuration);

  private:

    bool fStarted;
    ALTime fStartTime;
    int fTicCount;
  };
} // namespace AL


#endif
