/**
 * @author Aldebaran Robotics
 * Copyright (c) Aldebaran Robotics 2010, 2011 All Rights Reserved
 */



#pragma once
#ifndef _LIBALCOMMON_ALCOMMON_DETAIL_ALPCALL_H_
#define _LIBALCOMMON_ALCOMMON_DETAIL_ALPCALL_H_

#include <alcommon/alparamtype.h>
#include <alcommon/detail/altaskinfo.h>
#include <alcommon/detail/alpcallbase.h>

namespace AL
{

  class ALModuleCore;
  class ALBroker;
  class ALModule;
  namespace detail {
    class ALTaskInfo;
  }

  namespace detail {

    class _pcallScript : public PCallBase
    {
    public:
      _pcallScript(boost::shared_ptr<ALModuleCore> pModule,
                   const std::string& pMethod,
                   const AL::ALValue& pParams,
                   boost::shared_ptr<detail::ALTaskInfo> pID);

      virtual ~_pcallScript() { }
      void run();
    private:
      boost::shared_ptr<detail::ALTaskInfo>         fID;
      const boost::weak_ptr<ALModuleCore> fModule;
      const std::string                     fMethod;
      const AL::ALValue                     fParams;
    };

    class _pcall0 : public PCallBase
    {
    public:
      _pcall0(detail::ALFunctor_0<ALModule, ALVoid>* pFunctor,
              boost::shared_ptr<detail::ALTaskInfo> pID,
              boost::shared_ptr<ALModuleCore> notifyModule);

      _pcall0(detail::ALFunctor_0<ALModule, ALVoid>* pFunctor,
              boost::shared_ptr<ALModuleCore> notifyModule,
              boost::shared_ptr<detail::ALTaskInfo> pID);

      ~_pcall0() {}

      void run();

    private:
      detail::ALFunctor_0<ALModule, ALVoid>* fFunctor;
    };

    template <typename P1>
    class _pcall1 : public PCallBase
    {
    public:
      _pcall1(detail::ALFunctor_1<ALModule, P1, ALVoid>* pFunctor,
              P1 p1,
              boost::shared_ptr<ALModuleCore> pMod,
              boost::shared_ptr<detail::ALTaskInfo> pID);

      _pcall1(detail::ALFunctor_1<ALModule, P1, ALVoid>* pFunctor,
              P1 p1,
              boost::shared_ptr<ALModuleCore> pMod,
              boost::shared_ptr<detail::ALTaskInfo> pID,
              bool notify);

      ~_pcall1() {}

      void run();

    private:
      detail::ALFunctor_1<ALModule, P1, ALVoid>* fFunctor;
      P1                                 f1;
    };

    template <typename P1>
    _pcall1<P1>::_pcall1(detail::ALFunctor_1<ALModule, P1, ALVoid>* pFunctor,
                         P1 p1,
                         boost::shared_ptr<ALModuleCore> pMod,
                         boost::shared_ptr<detail::ALTaskInfo> pID)
      : PCallBase(false, pMod, pID),
        fFunctor(pFunctor),
        f1(p1)
    {
      monitorTask();
    }

    template <typename P1>
    _pcall1<P1>::_pcall1(detail::ALFunctor_1<ALModule, P1, ALVoid>* pFunctor,
                         P1 p1,
                         boost::shared_ptr<ALModuleCore> pMod,
                         boost::shared_ptr<detail::ALTaskInfo> pID,
                         bool notify)
      : PCallBase(true, pMod, pID),
        fFunctor(pFunctor),
        f1(p1)
    {
      monitorTask();
    }

    template <typename P1>
    void _pcall1<P1>::run()
    {
      startMonitor();
      (*fFunctor)(f1);
      stopMonitor();
    }

    template <typename P1, typename P2>
    class _pcall2 : public PCallBase
    {
    public:
      _pcall2(detail::ALFunctor_2<ALModule, P1, P2, ALVoid>* pFunctor,
              P1 p1, P2 p2,
              boost::shared_ptr<ALModuleCore> pMod,
              boost::shared_ptr<detail::ALTaskInfo> pID);

      _pcall2(detail::ALFunctor_1<ALModule, P1, ALVoid>* pFunctor,
              P1 p1, P2 p2,
              boost::shared_ptr<ALModuleCore> pMod,
              boost::shared_ptr<detail::ALTaskInfo> pID,
              bool notify);

      ~_pcall2() { }

      void run();

    private:
      detail::ALFunctor_2<ALModule, P1, P2, ALVoid>* fFunctor;
      P1 f1;
      P2 f2;
    };

    template <typename P1, typename P2>
    _pcall2<P1, P2>::_pcall2(detail::ALFunctor_2<ALModule, P1, P2, ALVoid>* pFunctor,
                             P1 p1, P2 p2,
                             boost::shared_ptr<ALModuleCore> pMod,
                             boost::shared_ptr<detail::ALTaskInfo> pID)
      : PCallBase(false, pMod, pID),
        fFunctor(pFunctor),
        f1(p1), f2(p2)
    {
      monitorTask();
    }

    template <typename P1, typename P2>
    _pcall2<P1, P2>::_pcall2(detail::ALFunctor_1<ALModule, P1, ALVoid>* pFunctor,
                             P1 p1, P2 p2,
                             boost::shared_ptr<ALModuleCore> pMod,
                             boost::shared_ptr<detail::ALTaskInfo> pID,
                             bool notify)
      : PCallBase(true, pMod, pID),
        fFunctor(pFunctor),
        f1(p1), f2(p2)
    {
      monitorTask();
    }

    template <typename P1, typename P2>
    void _pcall2<P1, P2>::run()
    {
      startMonitor();
      (*fFunctor)(f1, f2);
      stopMonitor();
    }

    template <typename P1, typename P2, typename P3>
    class _pcall3 : public PCallBase
    {
    public:
      _pcall3(detail::ALFunctor_3<ALModule, P1, P2, P3, ALVoid>* pFunctor,
              P1 p1, P2 p2, P3 p3,
              boost::shared_ptr<ALModuleCore> pMod,
              boost::shared_ptr<detail::ALTaskInfo> pID);

      _pcall3(detail::ALFunctor_1<ALModule, P1, ALVoid>* pFunctor,
              P1 p1, P2 p2, P3 p3,
              boost::shared_ptr<ALModuleCore> pMod,
              boost::shared_ptr<detail::ALTaskInfo> pID,
              bool notify);

      ~_pcall3() { }

      void run();

    private:
      detail::ALFunctor_3<ALModule, P1, P2, P3, ALVoid>* fFunctor;
      P1 f1;
      P2 f2;
      P3 f3;
    };

    template <typename P1, typename P2, typename P3>
    _pcall3<P1, P2, P3>::_pcall3(detail::ALFunctor_3<ALModule, P1, P2, P3, ALVoid>* pFunctor,
                                 P1 p1, P2 p2, P3 p3,
                                 boost::shared_ptr<ALModuleCore> pMod,
                                 boost::shared_ptr<detail::ALTaskInfo> pID)
      :  PCallBase(false, pMod, pID),
         fFunctor(pFunctor),
         f1(p1), f2(p2), f3(p3)
    {
      monitorTask();
    }

    template <typename P1, typename P2, typename P3>
    _pcall3<P1, P2, P3>::_pcall3(detail::ALFunctor_1<ALModule, P1, ALVoid>* pFunctor,
                                 P1 p1, P2 p2, P3 p3,
                                 boost::shared_ptr<ALModuleCore> pMod,
                                 boost::shared_ptr<detail::ALTaskInfo> pID,
                                 bool notify)
      : PCallBase(true, pMod, pID),
        fFunctor(pFunctor),
        f1(p1), f2(p2), f3(p3)
    {
      monitorTask();
    }

    template <typename P1, typename P2, typename P3>
    void _pcall3<P1, P2, P3>::run()
    {
      startMonitor();
      (*fFunctor)(f1, f2, f3);
      stopMonitor();
    }

    template <typename P1, typename P2, typename P3, typename P4>
    class _pcall4 : public PCallBase
    {
    public:
      _pcall4(detail::ALFunctor_4<ALModule, P1, P2, P3, P4, ALVoid>* pFunctor,
              P1 p1, P2 p2, P3 p3, P4 p4,
              boost::shared_ptr<ALModuleCore> pMod,
              boost::shared_ptr<detail::ALTaskInfo> pID);

      _pcall4(detail::ALFunctor_1<ALModule, P1, ALVoid>* pFunctor,
              P1 p1, P2 p2, P3 p3, P4 p4,
              boost::shared_ptr<ALModuleCore> pMod,
              boost::shared_ptr<detail::ALTaskInfo> pID);

      ~_pcall4() { }

      void run();

    private:
      detail::ALFunctor_4<ALModule, P1, P2, P3, P4, ALVoid>* fFunctor;
      P1 f1;
      P2 f2;
      P3 f3;
      P4 f4;
    };

    template <typename P1, typename P2, typename P3, typename P4>
    _pcall4<P1, P2, P3, P4>::_pcall4(detail::ALFunctor_4<ALModule, P1, P2, P3, P4, ALVoid>* pFunctor,
                                     P1 p1, P2 p2, P3 p3, P4 p4,
                                     boost::shared_ptr<ALModuleCore> pMod,
                                     boost::shared_ptr<detail::ALTaskInfo> pID)
      : PCallBase(false, pMod, pID),
        fFunctor(pFunctor),
        f1(p1), f2(p2), f3(p3), f4(p4)
    {
      monitorTask();
    }

    template <typename P1, typename P2, typename P3, typename P4>
    _pcall4<P1, P2, P3, P4>::_pcall4(detail::ALFunctor_1<ALModule, P1, ALVoid>* pFunctor,
                                     P1 p1, P2 p2, P3 p3, P4 p4,
                                     boost::shared_ptr<ALModuleCore> pMod,
                                     boost::shared_ptr<detail::ALTaskInfo> pID)
      : PCallBase(true, pMod, pID),
        fFunctor(pFunctor),
        f1(p1), f2(p2), f3(p3), f4(p4)
    {
      monitorTask();
    }

    template <typename P1, typename P2, typename P3, typename P4>
    void _pcall4<P1, P2, P3, P4>::run()
    {
      startMonitor();
      (*fFunctor)(f1, f2, f3, f4);
      stopMonitor();
    }

    /////////////////////////////////////////////////////////////////

    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    class _pcall5 : public PCallBase
    {
    public:
      _pcall5(detail::ALFunctor_5<ALModule, P1, P2, P3, P4, P5, ALVoid>* pFunctor,
              P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
              boost::shared_ptr<ALModuleCore> pMod,
              boost::shared_ptr<detail::ALTaskInfo> pID);

      _pcall5(detail::ALFunctor_1<ALModule, P1, ALVoid>* pFunctor,
              P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
              boost::shared_ptr<ALModuleCore> pMod,
              boost::shared_ptr<detail::ALTaskInfo> pID);

      ~_pcall5() { }

      void run();

    private:
      detail::ALFunctor_5<ALModule, P1, P2, P3, P4, P5, ALVoid>* fFunctor;
      P1 f1;
      P2 f2;
      P3 f3;
      P4 f4;
      P5 f5;
    };

    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    _pcall5<P1, P2, P3, P4, P5>::_pcall5(detail::ALFunctor_5<ALModule, P1, P2, P3, P4, P5, ALVoid>* pFunctor,
                                         P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
                                         boost::shared_ptr<ALModuleCore> pMod,
                                         boost::shared_ptr<detail::ALTaskInfo> pID)
      : PCallBase(false, pMod, pID),
        fFunctor(pFunctor),
        f1(p1), f2(p2), f3(p3), f4(p4), f5(p5)
    {
      monitorTask();
    }

    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    _pcall5<P1, P2, P3, P4, P5>::_pcall5(detail::ALFunctor_1<ALModule, P1, ALVoid>* pFunctor,
                                         P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
                                         boost::shared_ptr<ALModuleCore> pMod,
                                         boost::shared_ptr<detail::ALTaskInfo> pID)
      : PCallBase(true, pMod, pID),
        fFunctor(pFunctor),
        f1(p1), f2(p2), f3(p3), f4(p4), f5(p5)
    {
      monitorTask();
    }

    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    void _pcall5<P1, P2, P3, P4, P5>::run()
    {
      startMonitor();
      (*fFunctor)(f1, f2, f3, f4, f5);
      stopMonitor();
    }

    ///////////////////////////////////////////////////////////////

    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    class _pcall6 : public PCallBase
    {
    public:
      _pcall6(detail::ALFunctor_6<ALModule, P1, P2, P3, P4, P5, P6, ALVoid>* pFunctor,
              P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
              boost::shared_ptr<ALModuleCore> pMod,
              boost::shared_ptr<detail::ALTaskInfo> pID);

      _pcall6(detail::ALFunctor_1<ALModule, P1, ALVoid>* pFunctor,
              P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
              boost::shared_ptr<ALModuleCore> pMod,
              boost::shared_ptr<detail::ALTaskInfo> pID);

      ~_pcall6() { }

      void run();

    private:
      detail::ALFunctor_6<ALModule, P1, P2, P3, P4, P5, P6, ALVoid>* fFunctor;
      P1 f1;
      P2 f2;
      P3 f3;
      P4 f4;
      P5 f5;
      P6 f6;
    };

    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    _pcall6<P1, P2, P3, P4, P5, P6>::_pcall6(detail::ALFunctor_6<ALModule, P1, P2, P3, P4, P5, P6, ALVoid>* pFunctor,
                                             P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                             boost::shared_ptr<ALModuleCore> pMod,
                                             boost::shared_ptr<detail::ALTaskInfo> pID)
      : PCallBase(false, pMod, pID),
        fFunctor(pFunctor),
        f1(p1), f2(p2), f3(p3), f4(p4), f5(p5), f6(p6)
    {
      monitorTask();
    }

    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    _pcall6<P1, P2, P3, P4, P5, P6>::_pcall6(detail::ALFunctor_1<ALModule, P1, ALVoid>* pFunctor,
                                             P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                             boost::shared_ptr<ALModuleCore> pMod,
                                             boost::shared_ptr<detail::ALTaskInfo> pID)
      : PCallBase(true, pMod, pID),
        fFunctor(pFunctor),
        f1(p1), f2(p2), f3(p3), f4(p4), f5(p5), f6(p6)
    {
      monitorTask();
    }

    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    void _pcall6<P1, P2, P3, P4, P5, P6>::run()
    {
      startMonitor();
      (*fFunctor)(f1, f2, f3, f4, f5, f6);
      stopMonitor();
    }


  }

}

#endif  // _LIBALCOMMON_ALCOMMON_DETAIL_ALPCALL_H_

