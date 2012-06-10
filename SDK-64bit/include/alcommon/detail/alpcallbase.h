/**
* @author Aldebaran Robotics
* Copyright (c) Aldebaran Robotics 2010, 2011 All Rights Reserved
*/



#pragma once
#ifndef _LIBALCOMMON_ALCOMMON_DETAIL_ALPCALLBASE_H_
#define _LIBALCOMMON_ALCOMMON_DETAIL_ALPCALLBASE_H_

#include <boost/shared_ptr.hpp>

namespace AL
{
  class ALModuleCore;

  namespace detail {
    class ALTaskInfo;

    class PCallBase
    {
    public:
      PCallBase();

      PCallBase(bool pShouldNotify,
                boost::shared_ptr<ALModuleCore> pModCorePtr,
                boost::shared_ptr<ALTaskInfo> pTaskInfoPtr);
      virtual void run() = 0;

    protected:
      void monitorTask();
      void startMonitor();
      void stopMonitor();

      bool                            shouldNotify;
      boost::shared_ptr<ALModuleCore> fMod;
      boost::shared_ptr<ALTaskInfo>   fID;
    };

  }
}

#endif  // _LIBALCOMMON_ALCOMMON_DETAIL_ALPCALLBASE_H_

