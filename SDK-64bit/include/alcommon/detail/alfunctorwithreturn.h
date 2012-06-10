/**
* @author Aldebaran Robotics
* Copyright (c) Aldebaran Robotics 2007, 2011 All Rights Reserved
*/



#pragma once
#ifndef _LIBALCOMMON_ALCOMMON_DETAIL_ALFUNCTORWITHRETURN_H_
#define _LIBALCOMMON_ALCOMMON_DETAIL_ALFUNCTORWITHRETURN_H_

#include <alvalue/detail/alfunctorconvert.h>

namespace AL
{
  namespace detail {

    template <typename C, typename R = ALVoid>
    class ALFunctor_0 : public ALFunctorBase {
    public:
      ALFunctor_0(C *pObject, R(C::*pFunction)())
        : fObject(pObject),
          fFunction(pFunction)
      {}

      R operator() () {
        return (R)(fObject->*fFunction)();
      }

      void call (const AL::ALValue&, AL::ALValue& pResult){
        AL::detail::converter<R> convResult;
        pResult = convResult.convertToALValue((R)(fObject->*fFunction)());
      };

    private:
      C *fObject;
      typedef R(C::*functionType) ();
      functionType fFunction;
    };

    template <typename C, typename P1, typename R = ALVoid>
    class ALFunctor_1 : public ALFunctorBase {
    public:
      ALFunctor_1(C *pObject, R(C::*pFunction) (const P1 &))
        : fObject(pObject),
          fFunction(pFunction)
      {}

      R operator() (const P1 &p1) {
        return (R)(fObject->*fFunction)(p1);
      }

      void call(const AL::ALValue& pParams, AL::ALValue& pResult)
      {
        AL::detail::converter<P1> conv;
        AL::detail::converter<R> convResult;
        P1 p1 = conv.convertFromALValue(pParams[0]);
        R sourceResult = (R)(fObject->*fFunction)(p1);
        pResult = convResult.convertToALValue(sourceResult);
      };

    private:
      C *fObject;
      typedef R (C::*functionType) (const P1 &);
      functionType fFunction;
    };

    template <typename C, typename P1, typename P2, typename R = ALVoid>
    class ALFunctor_2 : public ALFunctorBase {
    public:

      ALFunctor_2(C *pObject, R(C::*pFunction) (const P1 &, const P2 &))
        : fObject(pObject),
          fFunction (pFunction)
      {}

      R operator() (const P1 &p1, const P2 &p2) {
        return (R)(fObject->*fFunction)(p1, p2);
      }

      void call(const AL::ALValue& pParams, AL::ALValue& pResult) {
        AL::detail::converter<P1> conv1;
        AL::detail::converter<P2> conv2;
        P1 p1 = conv1.convertFromALValue(pParams[0]);
        P2 p2 = conv2.convertFromALValue(pParams[1]);
        pResult = (R)(fObject->*fFunction)(p1, p2);
      };

    private:
      C *fObject;
      typedef R(C::*functionType) (const P1 &, const P2 &);
      functionType fFunction;
    };

    template <typename C, typename P1, typename P2, typename P3, typename R = ALVoid>
    class ALFunctor_3 : public ALFunctorBase {
    public:

      ALFunctor_3(C *pObject, R(C::*pFunction) (const P1 &, const P2 &, const P3 &))
        : fObject(pObject),
          fFunction (pFunction)
      {}

      R operator() (const P1 &p1, const P2 &p2, const P3 &p3) {
        return (R)(fObject->*fFunction)(p1, p2, p3);
      }

      void call(const AL::ALValue& pParams, AL::ALValue& pResult)
      {
        AL::detail::converter<P1> conv1;
        AL::detail::converter<P2> conv2;
        AL::detail::converter<P3> conv3;
        P1 p1 = conv1.convertFromALValue(pParams[0]);
        P2 p2 = conv2.convertFromALValue(pParams[1]);
        P3 p3 = conv3.convertFromALValue(pParams[2]);
        pResult = (R)(fObject->*fFunction)(p1, p2, p3);
      };

    private:
      C *fObject;
      typedef R (C::*functionType) (const P1 &, const P2 &, const P3 &);
      functionType fFunction;
    };


    template <typename C, typename P1, typename P2, typename P3, typename P4, typename R = ALVoid>
    class ALFunctor_4 : public ALFunctorBase {
    public:

      ALFunctor_4(C *pObject, R(C::*pFunction) (const P1 &, const P2 &, const P3 &, const P4 &))
        : fObject(pObject),
          fFunction (pFunction)
      {}

      R operator() (const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4) {
        return (R)(fObject->*fFunction)(p1, p2, p3, p4);
      }

      void call (const AL::ALValue& pParams, AL::ALValue& pResult)
      {
        AL::detail::converter<P1> conv1;
        AL::detail::converter<P2> conv2;
        AL::detail::converter<P3> conv3;
        AL::detail::converter<P4> conv4;
        P1 p1 = conv1.convertFromALValue(pParams[0]);
        P2 p2 = conv2.convertFromALValue(pParams[1]);
        P3 p3 = conv3.convertFromALValue(pParams[2]);
        P4 p4 = conv4.convertFromALValue(pParams[3]);
        pResult = (R)(fObject->*fFunction)(p1, p2, p3, p4);
      };

    private:
      C *fObject;
      typedef R (C::*functionType) (const P1 &, const P2 &, const P3 &, const P4 &);
      functionType fFunction;
    };

    template <typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename R = ALVoid>
    class ALFunctor_5 : public ALFunctorBase {
    public:
      ALFunctor_5(C *pObject, R(C::*pFunction) (const P1 &, const  P2 &, const P3 &, const P4 &, const P5 &))
        : fObject(pObject),
          fFunction (pFunction)
      {}

      R operator() (const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5) {
        return (R)(fObject->*fFunction)(p1, p2, p3, p4, p5);
      }

      void call (const AL::ALValue& pParams, AL::ALValue& pResult)
      {
        AL::detail::converter<P1> conv1;
        AL::detail::converter<P2> conv2;
        AL::detail::converter<P3> conv3;
        AL::detail::converter<P4> conv4;
        AL::detail::converter<P5> conv5;
        P1 p1 = conv1.convertFromALValue(pParams[0]);
        P2 p2 = conv2.convertFromALValue(pParams[1]);
        P3 p3 = conv3.convertFromALValue(pParams[2]);
        P4 p4 = conv4.convertFromALValue(pParams[3]);
        P5 p5 = conv5.convertFromALValue(pParams[4]);
        pResult = (R)(fObject->*fFunction)(p1, p2, p3, p4, p5);
      };

    private:
      C *fObject;
      typedef R(C::*functionType) (const P1 &, const P2 &, const P3 &, const P4 &, const P5 &);
      functionType fFunction;
    };


    template <typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename R = ALVoid>
    class ALFunctor_6 : public ALFunctorBase {
    public:
      ALFunctor_6(C *pObject, R (C::*pFunction) (const P1 &, const  P2 &, const P3 &, const  P4 &, const  P5 &, const P6 &))
        : fObject(pObject),
          fFunction (pFunction)
      {}

      R operator() (const P1  &p1, const  P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6) {
        return (R)(fObject->*fFunction)(p1, p2, p3, p4, p5, p6);
      }

      void call (const AL::ALValue& pParams, AL::ALValue& pResult)
      {
        AL::detail::converter<P1> conv1;
        AL::detail::converter<P2> conv2;
        AL::detail::converter<P3> conv3;
        AL::detail::converter<P4> conv4;
        AL::detail::converter<P5> conv5;
        AL::detail::converter<P6> conv6;
        P1 p1 = conv1.convertFromALValue(pParams[0]);
        P2 p2 = conv2.convertFromALValue(pParams[1]);
        P3 p3 = conv3.convertFromALValue(pParams[2]);
        P4 p4 = conv4.convertFromALValue(pParams[3]);
        P5 p5 = conv5.convertFromALValue(pParams[4]);
        P6 p6 = conv6.convertFromALValue(pParams[5]);
        pResult = (R)(fObject->*fFunction)(p1, p2, p3, p4, p5, p6);
      };

    private:
      C *fObject;
      typedef R(C::*functionType) (const P1 &, const P2 &, const P3 &, const P4 &, const P5 &, const P6 &);
      functionType fFunction;
    };
  }
}
#endif  // _LIBALCOMMON_ALCOMMON_DETAIL_ALFUNCTORWITHRETURN_H_
