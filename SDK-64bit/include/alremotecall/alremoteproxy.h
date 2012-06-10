/**
 * @author Aldebaran Robotics
 * Copyright (c) Aldebaran Robotics 2007, 2011 All Rights Reserved
 *
 */


#pragma once
#ifndef _LIB_ALREMOTECALL_ALREMOTECALL_ALREMOTEPROXY_H_
#define _LIB_ALREMOTECALL_ALREMOTECALL_ALREMOTEPROXY_H_

#include <alerror/alerror.h>
#include <alvalue/alvalue.h>
#include <alvalue/detail/alfunctorconvert.h>

namespace AL
{
  class ALProxyRemotePrivate;

  class ALProxyRemote
  {
  public:
    ALProxyRemote();
    ALProxyRemote(char *pModuleName, char *pIp, int pPort);
    ALProxyRemote(const std::string& pModuleName, const std::string& pIp, int pPort, int _unused = 0, int timeout = 0);
    virtual ~ALProxyRemote(void);

    // call with result, no parameters
    template <typename R>
    R callRemote(const std::string& pName)
    {
      AL::ALValue p, r;
      genericCall(pName, p, r);
      if( !r.isValid() )
      {
        throw ALERROR("ALProxy", "call", "Waiting for the result of a void function");
      }
      AL::detail::converter<R> conv;
      R resultConv = conv.convertFromALValue(r);
      return resultConv;
    }

    template <typename R, typename P1>
    R callRemote(const std::string& pName,  const P1 &p1)
    {
      AL::ALValue p, r;
      p.arraySetSize(1);
      p[0] = p1;

      genericCall(pName, p, r);
      if( !r.isValid() )
        throw ALERROR("ALProxy", "call", "Waiting for the result of a void function");

      AL::detail::converter<R> conv;
      R resultConv = conv.convertFromALValue(r);

      return resultConv;
    }

    template <typename R, typename P1, typename P2>
    R callRemote(const std::string& pName, const P1 &p1, const P2 &p2)
    {
      AL::ALValue p, r;
      p.arraySetSize(2);
      p[0] = p1;
      p[1] = p2;
      genericCall(pName, p, r);
      if( !r.isValid() )
        throw ALERROR("ALProxy", "call", "Waiting for the result of a void function");

      AL::detail::converter<R> conv;
      R resultConv = conv.convertFromALValue(r);
      return resultConv;
    }

    template <typename R, typename P1, typename P2, typename P3>
    R callRemote(const std::string& pName, const P1 &p1,  const P2 &p2, const P3 &p3)
    {
      AL::ALValue p, r;
      p.arraySetSize(3);
      p[0] = p1;
      p[1] = p2;
      p[2] = p3;
      genericCall(pName, p, r);
      if( !r.isValid() )
        throw ALERROR("ALProxy", "call", "Waiting for the result of a void function");
      AL::detail::converter<R> conv;
      R resultConv = conv.convertFromALValue(r);
      return resultConv;
    }

    template <typename R, typename P1, typename P2, typename P3, typename P4>
    R callRemote(const std::string& pName, const P1 &p1, const P2 &p2, const  P3 &p3,  const P4 &p4)
    {
      AL::ALValue p, r;
      p.arraySetSize(4);
      p[0] = p1;
      p[1] = p2;
      p[2] = p3;
      p[3] = p4;
      genericCall(pName, p, r);

      if( !r.isValid() )
        throw ALERROR("ALProxy", "call", "Waiting for the result of a void function");
      AL::detail::converter<R> conv;
      R resultConv = conv.convertFromALValue(r);
      return resultConv;
    }

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
    R callRemote(const std::string& pName, const  P1 &p1, const  P2 &p2, const  P3 &p3, const P4 &p4, const  P5 &p5)
    {
      AL::ALValue p, r;
      p.arraySetSize(5);
      p[0] = p1;
      p[1] = p2;
      p[2] = p3;
      p[3] = p4;
      p[4] = p5;
      genericCall(pName, p, r);
      if( !r.isValid() )
        throw ALERROR("ALProxy", "call", "Waiting for the result of a void function");
      AL::detail::converter<R> conv;
      R resultConv = conv.convertFromALValue(r);
      return resultConv;
    }

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    R callRemote(const std::string& pName,  const P1 &p1, const P2 &p2, const  P3 &p3, const  P4 &p4,  const P5 &p5, const P6 &p6)
    {
      AL::ALValue p, r;
      p.arraySetSize(6);
      p[0] = p1;
      p[1] = p2;
      p[2] = p3;
      p[3] = p4;
      p[4] = p5;
      p[5] = p6;

      genericCall(pName, p, r);
      if( !r.isValid() )
        throw ALERROR("ALProxy", "call", "Waiting for the result of a void function");
      AL::detail::converter<R> conv;
      R resultConv = conv.convertFromALValue(r);
      return resultConv;
    }

    void callVoidRemote(const std::string& pName)
    {
      AL::ALValue p, r;
      genericCall( pName, p, r );
      return;
    }

    template <typename P1>
    void callVoidRemote(const std::string& pName, const P1 &p1)
    {
      AL::ALValue p, r;
      p.arraySetSize(1);
      AL::detail::converter<P1> conv;
      p[0] = conv.convertToALValue(p1);
      genericCall( pName, p, r );
      return;
    }

    template <typename P1, typename P2>
    void callVoidRemote(const std::string& pName, const P1 &p1,  const P2 &p2)
    {
      AL::ALValue p, r;
      p.arraySetSize(2);
      p[0] = p1;
      p[1] = p2;
      genericCall( pName, p, r );
      return;
    }

    template <typename P1, typename P2, typename P3>
    void callVoidRemote(const std::string& pName, const P1 &p1,  const P2 &p2, const P3 &p3)
    {
      AL::ALValue p, r;
      p.arraySetSize(3);
      p[0] = p1;
      p[1] = p2;
      p[2] = p3;
      genericCall( pName, p, r );
      return;
    }

    template <typename P1, typename P2, typename P3, typename P4>
    void callVoidRemote(const std::string& pName,  const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
    {
      AL::ALValue p, r;
      p.arraySetSize(4);
      p[0] = p1;
      p[1] = p2;
      p[2] = p3;
      p[3] = p4;
      genericCall(pName, p, r);
      return;
    }

    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    void callVoidRemote(const std::string& pName,  const P1 &p1, const  P2 &p2,  const P3 &p3, const P4 &p4, const P5 &p5)
    {
      AL::ALValue p, r;

      p.arraySetSize(5);
      p[0] = p1;
      p[1] = p2;
      p[2] = p3;
      p[3] = p4;
      p[4] = p5;
      genericCall( pName, p, r );
      return;
    }

    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    void callVoidRemote(const std::string& pName,  const P1 &p1, const  P2 &p2, const  P3 &p3, const  P4 &p4,  const P5 &p5, const  P6 &p6)
    {
      AL::ALValue p, r;
      p.arraySetSize(6);
      p[0] = p1;
      p[1] = p2;
      p[2] = p3;
      p[3] = p4;
      p[4] = p5;
      p[5] = p6;
      genericCall( pName, p, r );
      return;
    }

    int pCall(const std::string& pName)
    {
      AL::ALValue p,r;
      genericPost( pName, p, r );
      return r;
    }

    template <typename P1>
    int pCall(const std::string& pName, const P1 &p1)
    {
      AL::ALValue p, r;
      p.arraySetSize(1);
      AL::detail::converter<P1> conv;
      p[0] = conv.convertToALValue(p1);
      genericPost( pName, p, r );
      return r;
    }

    template <typename P1, typename P2>
    int pCall(const std::string& pName, const P1 &p1, const  P2 &p2)
    {
      AL::ALValue p, r;
      p.arraySetSize(2);
      p[0] = p1;
      p[1] = p2;
      genericPost( pName, p, r );
      return r;
    }

    template <typename P1, typename P2, typename P3>
    int pCall(const std::string& pName, const P1 &p1, const P2 &p2, const  P3 &p3)
    {
      AL::ALValue p, r;

      p.arraySetSize(3);
      p[0] = p1;
      p[1] = p2;
      p[2] = p3;
      genericPost( pName, p, r );
      return r;
    }

    template <typename P1, typename P2, typename P3, typename P4>
    int pCall(const std::string& pName, const P1 &p1, const  P2 &p2, const  P3 &p3, const  P4 &p4)
    {
      AL::ALValue p, r;
      p.arraySetSize(4);
      p[0] = p1;
      p[1] = p2;
      p[2] = p3;
      p[3] = p4;
      genericPost( pName, p, r );
      return r;
    }

    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    int pCall(const std::string& pName, const P1 &p1, const  P2 &p2, const  P3 &p3,  const P4 &p4, const P5 &p5)
    {
      AL::ALValue p, r;
      p.arraySetSize(5);
      p[0] = p1;
      p[1] = p2;
      p[2] = p3;
      p[3] = p4;
      p[4] = p5;
      genericPost( pName, p, r );
      return r;
    }

    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    int pCall(const std::string& pName,  const P1 &p1, const  P2 &p2, const P3 &p3, const  P4 &p4, const P5 &p5, const P6 &p6)
    {
      AL::ALValue p, r;
      p.arraySetSize(6);
      p[0] = p1;
      p[1] = p2;
      p[2] = p3;
      p[3] = p4;
      p[4] = p5;
      p[5] = p6;
      genericPost( pName, p, r );
      return r;
    }

    void genericCall(const std::string &szMethodName,const AL::ALValue &param, AL::ALValue &result);
    void genericPost(const std::string &szMethodName, const AL::ALValue &param, AL::ALValue & result);

  protected:
    void init(const std::string& pModuleName, const std::string& pIp, int pPort, int timeout = 0);

  private:
    ALProxyRemotePrivate *_private;
  };

} // namespace AL

#endif  // _LIB_ALREMOTECALL_ALREMOTECALL_ALREMOTEPROXY_H_
