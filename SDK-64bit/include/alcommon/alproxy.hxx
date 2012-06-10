/**
 * @author Aldebaran Robotics
 * Copyright (c) Aldebaran Robotics 2010, 2011 All Rights Reserved
 */


#pragma once
#ifndef _LIBALCOMMON_ALCOMMON_ALPROXY_HXX_
#define _LIBALCOMMON_ALCOMMON_ALPROXY_HXX_

#include <alcommon/detail/alpcall.h>

namespace AL
{

#define CHECK_RESULT()                                                  \
  if (getParamStrType<R>() != lDesc->returnInfo.strType)                \
  {                                                                     \
    throw ALERROR("ALProxy", "call",                                    \
                  std::string("wrong return type for function '") +     \
                  pName + "'" +                                         \
                  " type is '" + getParamStrType<R>() + "'" +           \
                  " instead of '" + lDesc->returnInfo.strType);         \
  }

#define CHECK_PARAM(x)                                                  \
  if (getParamStrType<P ## x>() != lDesc->parameters[x-1].strType)      \
  {                                                                     \
    throw ALERROR("ALProxy", "call/pCall",                              \
                  std::string("When trying to call module '") +         \
                  xGetModuleName() + "'"                                \
                  " function '" + pName + "' parameter #" +             \
                  (char) (x + '0') +                                    \
                  " is of type " + getParamStrType<P ## x>() +          \
                  " instead of type " +                                 \
                  lDesc->parameters[x-1].strType);                      \
  }

  template <typename R>
  R ALProxy::call(const std::string& pName)
  {
    if (isLocal())
    {
      if (isScript())
      {
        AL::ALValue param;
        AL::ALValue result;
        xExecute(pName, param, result);
        AL::detail::converter<R> conv;
        return conv.convertFromALValue(result);
      }
      ALMethodInfo *lDesc = xLookupMethod(pName);
      if (!lDesc)
      {
        std::vector<std::string> param;
        lDesc = xLookupMethod(pName, param, true);
      }
      CHECK_RESULT();
      return (*(detail::ALFunctor_0<ALModule, R> *)(lDesc->getFunction()))();
    }
    AL::ALValue p, r;
    CALL_METHODS(pName, p, r);
    if (!r.isValid())
      throw ALERROR("ALProxy", "call", "Waiting for the result of a void function");
    AL::detail::converter<R> conv;
    return conv.convertFromALValue(r);
  }

  template <typename R, typename P1>
  R ALProxy::call(const std::string& pName, const P1 &p1)
  {
    if (isLocal())
    {
      if (isScript())
      {
        AL::ALValue param;
        AL::ALValue result;
        param.arraySetSize(1);
        param[0] = p1;
        xExecute(pName, param, result);
        AL::detail::converter<R> conv;
        R resultConv = conv.convertFromALValue(result);
        return resultConv;
      }
      ALMethodInfo *lDesc = xLookupMethod(pName);
      if (!lDesc)
      {
        std::vector<std::string> param;
        param.push_back(getParamStrType<P1>());
        lDesc = xLookupMethod(pName, param,false);
      }
      CHECK_RESULT();
      CHECK_PARAM(1);
      return (*(detail::ALFunctor_1<ALModule, P1, R> *)(lDesc->getFunction()))(p1);
    }
    AL::ALValue p, r;
    p.arraySetSize(1);
    p[0] = p1;
    CALL_METHODS(pName, p, r);
    if ( !r.isValid() )
    {
      std::string error = std::string("Waiting for the result of a void function ") + pName + std::string(" ") + p.toString(VerbosityMini) + std::string("   ") + r.toString(VerbosityMini);
      throw ALERROR("ALProxy", "call", error);
    }
    AL::detail::converter<R> conv;
    R resultConv = conv.convertFromALValue(r);
    return resultConv;
  }


  template <typename R, typename P1, typename P2>
  R ALProxy::call(const std::string& pName, const P1 &p1, const P2 &p2)
  {
    if (isLocal())
    {
      if (isScript())
      {
        AL::ALValue param;
        AL::ALValue result;
        param.arraySetSize(2);
        param[0] = p1;
        param[1] = p2;
        xExecute(pName, param, result);
        return result;
      }
      ALMethodInfo *lDesc = xLookupMethod(pName);
      if (!lDesc)
      {
        std::vector<std::string> param;
        param.push_back(getParamStrType<P1>());
        param.push_back(getParamStrType<P2>());
        lDesc = xLookupMethod(pName, param,false);
      }
      CHECK_RESULT();
      CHECK_PARAM(1);
      CHECK_PARAM(2);
      return (*(detail::ALFunctor_2<ALModule, P1, P2, R> *)(lDesc->getFunction()))(p1, p2);
    }
    AL::ALValue p, r;
    p.arraySetSize(2);
    p[0] = p1;
    p[1] = p2;
    CALL_METHODS(pName, p, r);
    if ( !r.isValid() )
      throw ALERROR("ALProxy", "call", "Waiting for the result of a void function");
    AL::detail::converter<R> conv;
    R resultConv = conv.convertFromALValue(r);
    return resultConv;
  }


  template <typename R, typename P1, typename P2, typename P3>
  R ALProxy::call(const std::string& pName, const P1 &p1, const P2 &p2, const P3 &p3)
  {
    if (isLocal())
    {
      if (isScript())
      {
        AL::ALValue param;
        AL::ALValue result;
        param.arraySetSize(3);
        param[0] = p1;
        param[1] = p2;
        param[2] = p3;
        xExecute(pName, param, result);
        return result;
      }
      ALMethodInfo *lDesc = xLookupMethod(pName);
      if (!lDesc)
      {
        std::vector<std::string> param;
        param.push_back(getParamStrType<P1>());
        param.push_back(getParamStrType<P2>());
        param.push_back(getParamStrType<P3>());
        lDesc = xLookupMethod(pName, param, false);
      }
      CHECK_RESULT();
      CHECK_PARAM(1);
      CHECK_PARAM(2);
      CHECK_PARAM(3);
      return (*(detail::ALFunctor_3<ALModule, P1, P2, P3, R> *)(lDesc->getFunction()))(p1, p2, p3);
    }
    AL::ALValue p, r;
    p.arraySetSize(3);
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;

    CALL_METHODS(pName, p, r);
    if ( !r.isValid() )
      throw ALERROR("ALProxy", "call", "Waiting for the result of a void function");
    AL::detail::converter<R> conv;
    R resultConv = conv.convertFromALValue(r);
    return resultConv;
  }


  template <typename R, typename P1, typename P2, typename P3, typename P4>
  R ALProxy::call(const std::string& pName, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
  {
    if (isLocal())
    {
      if (isScript())
      {
        AL::ALValue param;
        AL::ALValue result;
        param.arraySetSize(4);
        param[0] = p1;
        param[1] = p2;
        param[2] = p3;
        param[3] = p4;
        xExecute(pName, param, result);
        return result;
      }
      ALMethodInfo *lDesc = xLookupMethod(pName);
      if (!lDesc)
      {
        std::vector<std::string> param;
        param.push_back(getParamStrType<P1>());
        param.push_back(getParamStrType<P2>());
        param.push_back(getParamStrType<P3>());
        param.push_back(getParamStrType<P4>());
        lDesc = xLookupMethod(pName, param, false);
      }
      CHECK_RESULT();
      CHECK_PARAM(1);
      CHECK_PARAM(2);
      CHECK_PARAM(3);
      CHECK_PARAM(4);
      return (*(detail::ALFunctor_4<ALModule, P1, P2, P3, P4, R> *)(lDesc->getFunction()))(p1, p2, p3, p4);
    }
    AL::ALValue p, r;
    p.arraySetSize(4);
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    CALL_METHODS(pName, p, r);
    if ( !r.isValid() )
      throw ALERROR("ALProxy", "call", "Waiting for the result of a void function");
    AL::detail::converter<R> conv;
    R resultConv = conv.convertFromALValue(r);
    return resultConv;
  }


  template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
  R ALProxy::call(const std::string& pName, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
  {
    if (isLocal())
    {
      if (isScript())
      {
        AL::ALValue param;
        AL::ALValue result;
        param.arraySetSize(5);
        param[0] = p1;
        param[1] = p2;
        param[2] = p3;
        param[3] = p4;
        param[4] = p5;
        xExecute(pName, param, result);
        return result;
      }
      ALMethodInfo *lDesc = xLookupMethod(pName);
      if (!lDesc)
      {
        std::vector<std::string> param;
        param.push_back(getParamStrType<P1>());
        param.push_back(getParamStrType<P2>());
        param.push_back(getParamStrType<P3>());
        param.push_back(getParamStrType<P4>());
        param.push_back(getParamStrType<P5>());
        lDesc = xLookupMethod(pName, param, false);
      }
      CHECK_RESULT();
      CHECK_PARAM(1);
      CHECK_PARAM(2);
      CHECK_PARAM(3);
      CHECK_PARAM(4);
      CHECK_PARAM(5);
      return (*(detail::ALFunctor_5<ALModule, P1, P2, P3, P4, P5, R> *)(lDesc->getFunction()))(p1, p2, p3, p4, p5);
    }
    AL::ALValue p, r;
    p.arraySetSize(5);
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    p[4] = p5;
    CALL_METHODS(pName, p, r);
    if ( !r.isValid() )
      throw ALERROR("ALProxy", "call", "Waiting for the result of a void function");
    AL::detail::converter<R> conv;
    R resultConv = conv.convertFromALValue(r);
    return resultConv;
  }


  template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
  R ALProxy::call(const std::string& pName, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
  {
    if (isLocal())
    {
      if (isScript())
      {
        AL::ALValue param;
        AL::ALValue result;
        param.arraySetSize(6);
        param[0] = p1;
        param[1] = p2;
        param[2] = p3;
        param[3] = p4;
        param[4] = p5;
        param[5] = p6;
        xExecute(pName, param, result);
        return result;
      }

      ALMethodInfo *lDesc = xLookupMethod(pName);
      if (!lDesc)
        throw ALERROR("ALProxy", "call", "Function does not exist");
      CHECK_RESULT();
      CHECK_PARAM(1);
      CHECK_PARAM(2);
      CHECK_PARAM(3);
      CHECK_PARAM(4);
      CHECK_PARAM(5);
      CHECK_PARAM(6);
      return (*(detail::ALFunctor_6<ALModule, P1, P2, P3, P4, P5, P6, R> *)(lDesc->getFunction()))(p1, p2, p3, p4, p5, p6);
    }
    AL::ALValue p, r;
    p.arraySetSize(6);
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    p[4] = p5;
    p[5] = p6;
    CALL_METHODS(pName, p, r);
    if ( !r.isValid() )
      throw ALERROR("ALProxy", "call", "Waiting for the result of a void function");
    AL::detail::converter<R> conv;
    R resultConv = conv.convertFromALValue(r);
    return resultConv;
  }

  inline
  void ALProxy::callVoid(const std::string& pName)
  {
    if (isLocal())
    {
      if (isScript())
      {
        AL::ALValue param;
        AL::ALValue result;
        xExecute(pName, param, result);
        return;
      }
      ALMethodInfo *lDesc = xLookupMethod(pName);
      if (!lDesc)
        throw ALERROR("ALProxy", "getMethodInfo", std::string("Function ") + pName + " does not exist in module " + xGetModuleName() );
      (*(detail::ALFunctor_0<ALModule, ALVoid> *)(xLookupMethod(pName)->ptrOnMethod.get()))();
      return;
    }
    AL::ALValue p, r;
    CALL_METHODS(pName, p, r);
    return;
  }

  template <typename P1>
  void ALProxy::callVoid(const std::string& pName, const P1 &p1)
  {
    if (isLocal())
    {
      if (isScript())
      {
        AL::ALValue param;
        AL::ALValue result;
        param.arraySetSize(1);
        AL::detail::converter<P1> conv;
        param[0] = conv.convertToALValue(p1);
        xExecute(pName, param, result);
        return;
      }
      ALMethodInfo *lDesc = xLookupMethod(pName);
      if (!lDesc)
      {
        std::vector<std::string> param;
        param.push_back(getParamStrType<P1>());
        lDesc = xLookupMethod(pName, param, false);
      }
      CHECK_PARAM(1);
      (*(detail::ALFunctor_1<ALModule, P1, void> *)(lDesc->getFunction()))(p1);
      return;
    }
    AL::ALValue p, r;
    p.arraySetSize(1);
    AL::detail::converter<P1> conv;
    p[0] = conv.convertToALValue(p1);
    CALL_METHODS(pName, p, r);
    return;
  }

  template <typename P1, typename P2>
  void ALProxy::callVoid(const std::string& pName, const P1 &p1, const P2 &p2)
  {
    if (isLocal())
    {
      if (isScript())
      {
        AL::ALValue param;
        AL::ALValue result;
        param.arraySetSize(2);
        param[0] = p1;
        param[1] = p2;
        xExecute(pName, param, result);
        return;
      }
      ALMethodInfo *lDesc = xLookupMethod(pName);
      if (!lDesc)
      {
        std::vector<std::string> param;
        param.push_back(getParamStrType<P1>());
        param.push_back(getParamStrType<P2>());
        lDesc = xLookupMethod(pName, param, false);
      }
      CHECK_PARAM(1);
      CHECK_PARAM(2);
      (*(detail::ALFunctor_2<ALModule, P1, P2, void> *)(lDesc->getFunction()))(p1, p2);
      return;
    }
    AL::ALValue p, r;
    p.arraySetSize(2);
    p[0] = p1;
    p[1] = p2;
    CALL_METHODS(pName, p, r);
  }

  template <typename P1, typename P2, typename P3>
  void ALProxy::callVoid(const std::string& pName, const P1 &p1, const P2 &p2, const P3 &p3)
  {
    if (isLocal())
    {
      if (isScript())
      {
        AL::ALValue param;
        AL::ALValue result;
        param.arraySetSize(3);
        param[0] = p1;
        param[1] = p2;
        param[2] = p3;
        xExecute(pName, param, result);
        return;
      }
      ALMethodInfo *lDesc = xLookupMethod(pName);
      if (!lDesc)
      {
        std::vector<std::string> param;
        param.push_back(getParamStrType<P1>());
        param.push_back(getParamStrType<P2>());
        param.push_back(getParamStrType<P3>());
        lDesc = xLookupMethod(pName, param, false);
      }
      CHECK_PARAM(1);
      CHECK_PARAM(2);
      CHECK_PARAM(3);
      (*(detail::ALFunctor_3<ALModule, P1, P2, P3, void> *)(lDesc->getFunction()))(p1, p2, p3);
      return;
    }
    AL::ALValue p, r;
    p.arraySetSize(3);
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    CALL_METHODS(pName, p, r);
  }

  template <typename P1, typename P2, typename P3, typename P4>
  void ALProxy::callVoid(const std::string& pName, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
  {
    if (isLocal())
    {
      if (isScript())
      {
        AL::ALValue param;
        AL::ALValue result;
        param.arraySetSize(4);
        param[0] = p1;
        param[1] = p2;
        param[2] = p3;
        param[3] = p4;
        xExecute(pName, param, result);
        return;
      }
      ALMethodInfo *lDesc = xLookupMethod(pName);
      if (!lDesc)
      {
        std::vector<std::string> param;
        param.push_back(getParamStrType<P1>());
        param.push_back(getParamStrType<P2>());
        param.push_back(getParamStrType<P3>());
        param.push_back(getParamStrType<P4>());
        lDesc = xLookupMethod(pName, param, false);
      }
      CHECK_PARAM(1);
      CHECK_PARAM(2);
      CHECK_PARAM(3);
      CHECK_PARAM(4);
      (*(detail::ALFunctor_4<ALModule, P1, P2, P3, P4, ALVoid> *)(lDesc->getFunction()))(p1, p2, p3, p4);
      return;
    }
    AL::ALValue p, r;
    p.arraySetSize(4);
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    CALL_METHODS(pName, p, r);
  }

  template <typename P1, typename P2, typename P3, typename P4, typename P5>
  void ALProxy::callVoid(const std::string& pName, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
  {
    if (isLocal())
    {
      if (isScript())
      {
        AL::ALValue param;
        AL::ALValue result;
        param.arraySetSize(5);
        param[0] = p1;
        param[1] = p2;
        param[2] = p3;
        param[3] = p4;
        param[4] = p5;
        xExecute(pName, param, result);
        return;
      }
      ALMethodInfo *lDesc = xLookupMethod(pName);
      if (!lDesc)
      {
        std::vector<std::string> param;
        param.push_back(getParamStrType<P1>());
        param.push_back(getParamStrType<P2>());
        param.push_back(getParamStrType<P3>());
        param.push_back(getParamStrType<P4>());
        param.push_back(getParamStrType<P5>());
        lDesc = xLookupMethod(pName, param, false);
      }
      CHECK_PARAM(1);
      CHECK_PARAM(2);
      CHECK_PARAM(3);
      CHECK_PARAM(4);
      CHECK_PARAM(5);
      (*(detail::ALFunctor_5<ALModule, P1, P2, P3, P4, P5, ALVoid> *)(lDesc->getFunction()))(p1, p2, p3, p4, p5);
      return;
    }
    AL::ALValue p, r;
    p.arraySetSize(5);
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    p[4] = p5;
    CALL_METHODS(pName, p, r);
  }


  template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
  void ALProxy::callVoid(const std::string& pName, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
  {
    if (isLocal())
    {
      if (isScript())
      {
        AL::ALValue param;
        AL::ALValue result;
        param.arraySetSize(6);
        param[0] = p1;
        param[1] = p2;
        param[2] = p3;
        param[3] = p4;
        param[4] = p5;
        param[5] = p6;

        xExecute(pName, param, result);
        return;
      }
      ALMethodInfo *lDesc = xLookupMethod(pName);
      if (!lDesc)
        throw ALERROR("ALProxy", "call", "Function does not exist");
      CHECK_PARAM(1);
      CHECK_PARAM(2);
      CHECK_PARAM(3);
      CHECK_PARAM(4);
      CHECK_PARAM(5);
      CHECK_PARAM(6);
      (*(detail::ALFunctor_6<ALModule, P1, P2, P3, P4, P5, P6, ALVoid> *)(lDesc->getFunction()))(p1, p2, p3, p4, p5, p6);
      return;
    }
    AL::ALValue p, r;
    p.arraySetSize(6);
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    p[4] = p5;
    p[5] = p6;
    CALL_METHODS(pName, p, r);
  }

  inline
  int ALProxy::pCall(const std::string& pName)
  {
    if (isLocal())
    {
      if (isScript())
      {
        AL::ALValue param;
        return xPCallScript(pName, param);
      }
      ALMethodInfo *lDesc = xLookupMethod(pName);
      if (!lDesc)
        throw ALERROR("ALProxy", "getMethodInfo", std::string("Function ") + pName + " does not exist in module " + xGetModuleName() );
      boost::shared_ptr<detail::ALTaskInfo> r = xCreateTaskInfo(pName);
      detail::PCallBase *pcall(new detail::_pcall0((detail::ALFunctor_0<ALModule, ALVoid> *)(lDesc->getFunction()),r,getModuleCore()));
      xAddTask(r->toString(), pcall);
      return r->getID();
    }
    AL::ALValue p,r;
    PCALL_METHODS(pName, p, r);
    return r;
  }


  template <typename P1>
  int ALProxy::pCall(const std::string& pName, const P1 &p1)
  {
    if (isLocal())
    {
      if (isScript())
      {
        AL::ALValue param;
        param.arraySetSize(1);
        AL::detail::converter<P1> conv;
        param[0] = conv.convertToALValue(p1);
        return xPCallScript(pName, param);
      }
      ALMethodInfo *lDesc = xLookupMethod(pName);
      if (!lDesc)
      {
        std::vector<std::string> param;
        param.push_back(getParamStrType<P1>());
        lDesc = xLookupMethod(pName, param, true);
      }
      CHECK_PARAM(1);
      boost::shared_ptr<detail::ALTaskInfo> r = xCreateTaskInfo(pName);
      detail::PCallBase *task(new detail::_pcall1<P1>((detail::ALFunctor_1<ALModule, P1, ALVoid> *)(lDesc->getFunction()), p1,getModuleCore(),r ));
      xAddTask(r->toString(), task);
      return r->getID();
    }
    AL::ALValue p, r;
    p.arraySetSize(1);
    AL::detail::converter<P1> conv;
    p[0] = conv.convertToALValue(p1);
    PCALL_METHODS(pName, p, r);
    return r;
  }


  template <typename P1, typename P2>
  int ALProxy::pCall(const std::string& pName, const P1 &p1, const P2 &p2)
  {
    if (isLocal())
    {
      if (isScript())
      {
        AL::ALValue param;
        param.arraySetSize(2);
        param[0] = p1;
        param[1] = p2;
        return xPCallScript(pName, param);
      }
      ALMethodInfo *lDesc = xLookupMethod(pName);
      if (!lDesc)
      {
        std::vector<std::string> param;
        param.push_back(getParamStrType<P1>());
        param.push_back(getParamStrType<P2>());
        lDesc = xLookupMethod(pName, param, true);
      }
      CHECK_PARAM(1);
      CHECK_PARAM(2);
      boost::shared_ptr<detail::ALTaskInfo> r = xCreateTaskInfo(pName);
      detail::PCallBase *task(new detail::_pcall2<P1, P2>((detail::ALFunctor_2<ALModule, P1, P2, ALVoid> *)(lDesc->getFunction()), p1, p2, getModuleCore(), r));
      xAddTask(r->toString(), task);
      return r->getID();
    }
    AL::ALValue p, r;
    p.arraySetSize(2);
    p[0] = p1;
    p[1] = p2;
    PCALL_METHODS(pName, p, r);
    return r;
  }

  template <typename P1, typename P2, typename P3>
  int ALProxy::pCall(const std::string& pName, const P1 &p1, const P2 &p2, const P3 &p3)
  {
    if (isLocal())
    {
      if (isScript())
      {
        AL::ALValue param;
        param.arraySetSize(3);
        param[0] = p1;
        param[1] = p2;
        param[2] = p3;
        return xPCallScript(pName, param);
      }
      ALMethodInfo *lDesc = xLookupMethod(pName);
      if (!lDesc)
      {
        std::vector<std::string> param;
        param.push_back(getParamStrType<P1>());
        param.push_back(getParamStrType<P2>());
        param.push_back(getParamStrType<P3>());
        lDesc = xLookupMethod(pName, param, true);
      }
      CHECK_PARAM(1);
      CHECK_PARAM(2);
      CHECK_PARAM(3);
      boost::shared_ptr<detail::ALTaskInfo> r  = xCreateTaskInfo(pName);
      detail::PCallBase *task(new detail::_pcall3<P1, P2, P3>((detail::ALFunctor_3<ALModule, P1, P2, P3, ALVoid> *)(lDesc->getFunction()), p1, p2, p3,getModuleCore(),r));
      xAddTask(r->toString(), task);
      return r->getID();
    }
    AL::ALValue p, r;
    p.arraySetSize(3);
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    PCALL_METHODS(pName, p, r);
    return r;
  }

  template <typename P1, typename P2, typename P3, typename P4>
  int ALProxy::pCall(const std::string& pName, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
  {
    if (isLocal())
    {
      if (isScript())
      {
        AL::ALValue param;
        param.arraySetSize(4);
        param[0] = p1;
        param[1] = p2;
        param[2] = p3;
        param[3] = p4;
        return xPCallScript(pName, param);
      }
      ALMethodInfo *lDesc = xLookupMethod(pName);
      if (!lDesc)
      {
        std::vector<std::string> param;
        param.push_back(getParamStrType<P1>());
        param.push_back(getParamStrType<P2>());
        param.push_back(getParamStrType<P3>());
        param.push_back(getParamStrType<P4>());
        lDesc = xLookupMethod(pName, param, true);
      }
      CHECK_PARAM(1);
      CHECK_PARAM(2);
      CHECK_PARAM(3);
      CHECK_PARAM(4);
      boost::shared_ptr<detail::ALTaskInfo> r  = xCreateTaskInfo(pName);
      detail::PCallBase *task(new detail::_pcall4<P1, P2, P3, P4>((detail::ALFunctor_4<ALModule, P1, P2, P3, P4, ALVoid> *)(lDesc->getFunction()), p1, p2, p3, p4,getModuleCore(), r ));
      xAddTask(r->toString(), task);
      return r->getID();
    }
    AL::ALValue p, r;
    p.arraySetSize(4);
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    PCALL_METHODS(pName, p, r);
    return r;
  }

  template <typename P1, typename P2, typename P3, typename P4, typename P5>
  int ALProxy::pCall(const std::string& pName, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
  {
    if (isLocal())
    {
      if (isScript())
      {
        AL::ALValue param;
        param.arraySetSize(5);
        param[0] = p1;
        param[1] = p2;
        param[2] = p3;
        param[3] = p4;
        param[4] = p5;
        return xPCallScript(pName, param);
      }
      ALMethodInfo *lDesc = xLookupMethod(pName);
      if (!lDesc)
      {
        std::vector<std::string> param;
        param.push_back(getParamStrType<P1>());
        param.push_back(getParamStrType<P2>());
        param.push_back(getParamStrType<P3>());
        param.push_back(getParamStrType<P4>());
        param.push_back(getParamStrType<P5>());
        lDesc = xLookupMethod(pName, param, false);
      }
      CHECK_PARAM(1);
      CHECK_PARAM(2);
      CHECK_PARAM(3);
      CHECK_PARAM(4);
      CHECK_PARAM(5);
      boost::shared_ptr<detail::ALTaskInfo> r = xCreateTaskInfo(pName);
      detail::PCallBase *task(new detail::_pcall5<P1, P2, P3, P4, P5>((detail::ALFunctor_5<ALModule, P1, P2, P3, P4, P5, ALVoid> *)(lDesc->getFunction()), p1, p2, p3, p4, p5, getModuleCore(), r));
      xAddTask(r->toString(), task);
      return r->getID();
    }
    AL::ALValue p, r;
    p.arraySetSize(5);
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    p[4] = p5;
    PCALL_METHODS(pName, p, r);
    return r;
  }


  template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
  int ALProxy::pCall(const std::string& pName, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
  {
    if (isLocal())
    {
      if (isScript())
      {
        AL::ALValue param;
        param.arraySetSize(6);
        param[0] = p1;
        param[1] = p2;
        param[2] = p3;
        param[3] = p4;
        param[4] = p5;
        param[5] = p6;
        return xPCallScript(pName, param);
      }
      ALMethodInfo *lDesc = xLookupMethod(pName);
      if (!lDesc)
        throw ALERROR("ALProxy", "call", "Function does not exist");
      CHECK_PARAM(1);
      CHECK_PARAM(2);
      CHECK_PARAM(3);
      CHECK_PARAM(4);
      CHECK_PARAM(5);
      CHECK_PARAM(6);
      boost::shared_ptr<detail::ALTaskInfo> r = xCreateTaskInfo(pName);
      detail::PCallBase *task(new detail::_pcall6<P1, P2, P3, P4, P5, P6>((detail::ALFunctor_6<ALModule, P1, P2, P3, P4, P5, P6, ALVoid> *)(lDesc->getFunction()), p1, p2, p3, p4, p5, p6, getModuleCore(), r));
      xAddTask(r->toString(), task);
      return r->getID();
    }
    AL::ALValue p, r;
    p.arraySetSize(6);
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    p[4] = p5;
    p[5] = p6;
    PCALL_METHODS(pName, p, r);
    return r;
  }
}

#endif  // _LIBALCOMMON_ALCOMMON_ALPROXY_HXX_

