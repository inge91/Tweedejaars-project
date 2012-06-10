/**
* @author Aldebaran Robotics
* Copyright (c) Aldebaran Robotics 2007, 2011 All Rights Reserved
*/


#pragma once

#ifndef _LIB_ALCORE_ALCORE_ALPTR_H_
#define _LIB_ALCORE_ALCORE_ALPTR_H_

#include <qi/macro.hpp>

QI_DEPRECATED_HEADER(Please use boost::shared_ptr);

#include <boost/enable_shared_from_this.hpp>
#include <boost/make_shared.hpp>

namespace AL
{
//////////////////////////////////////////////////////////////////////////////

  // ALPtr definition
  template<class T>
  class ALPtr : public ::boost::shared_ptr<T>
  {
  public:
    template<class Y>
    ALPtr(const ::boost::shared_ptr<Y>& p): ::boost::shared_ptr<T>(p) {}

    template<class Y>
    explicit ALPtr(Y* p): ::boost::shared_ptr<T>(p) {}

    template<class Y, class D>
    ALPtr(Y* p, D d) : ::boost::shared_ptr<T>(p, d) {}

    template<class Y, class D, class A>
    ALPtr(Y* p, D d, A a) : ::boost::shared_ptr<T>(p, d, a) {}

    ALPtr() : ::boost::shared_ptr<T>() {}
  };

//////////////////////////////////////////////////////////////////////////////

  template<class T>
  ALPtr<T> makeALPtr(T* p)
  { return ALPtr<T>(p); }

  template<class T, class D>
  ALPtr<T> makeALPtr(T* p, D d)
  { return ALPtr<T>(p, d); }

  template<class T, class D, class A>
  ALPtr<T> makeALPtr(T* p, D d, A a)
  { return ALPtr<T>(p, d, a); }

//////////////////////////////////////////////////////////////////////////////

  template<typename T>
  ALPtr<T> makePtr()
  { return ::boost::make_shared<T>(); }
  template<typename T, typename Arg1>
  ALPtr<T> makePtr(const Arg1& arg1)
  { return ::boost::make_shared<T>(arg1); }
  template<typename T, typename Arg1, typename Arg2>
  ALPtr<T> makePtr(const Arg1& arg1, const Arg2& arg2)
  { return ::boost::make_shared<T>(arg1, arg2); }
  template<typename T, typename Arg1, typename Arg2, typename Arg3>
  ALPtr<T> makePtr(const Arg1& arg1, const Arg2& arg2, const Arg3& arg3)
  { return ::boost::make_shared<T>(arg1, arg2, arg3); }
  template<typename T, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
  ALPtr<T> makePtr(const Arg1& arg1, const Arg2& arg2, const Arg3& arg3, const Arg4& arg4)
  { return ::boost::make_shared<T>(arg1, arg2, arg3, arg4); }
  template<typename T, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
  ALPtr<T> makePtr(const Arg1& arg1, const Arg2& arg2, const Arg3& arg3, const Arg4& arg4, const Arg5& arg5)
  { return ::boost::make_shared<T>(arg1, arg2, arg3, arg4, arg5); }
  template<typename T, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
  ALPtr<T> makePtr(const Arg1& arg1, const Arg2& arg2, const Arg3& arg3, const Arg4& arg4, const Arg5& arg5, const Arg6& arg6)
  { return ::boost::make_shared<T>(arg1, arg2, arg3, arg4, arg5, arg6); }
  template<typename T, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
  ALPtr<T> makePtr(const Arg1& arg1, const Arg2& arg2, const Arg3& arg3, const Arg4& arg4, const Arg5& arg5, const Arg6& arg6, const Arg7& arg7)
  { return ::boost::make_shared<T>(arg1, arg2, arg3, arg4, arg5, arg6, arg7); }
  template<typename T, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8>
  ALPtr<T> makePtr(const Arg1& arg1, const Arg2& arg2, const Arg3& arg3, const Arg4& arg4, const Arg5& arg5, const Arg6& arg6, const Arg7& arg7, const Arg8& arg8)
  { return ::boost::make_shared<T>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8); }
  template<typename T, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9>
  ALPtr<T> makePtr(const Arg1& arg1, const Arg2& arg2, const Arg3& arg3, const Arg4& arg4, const Arg5& arg5, const Arg6& arg6, const Arg7& arg7, const Arg8& arg8, const Arg9& arg9)
  { return ::boost::make_shared<T>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9); }

  template<typename T, typename A>
  ALPtr<T> allocPtr(const A& a)
  { return ::boost::allocate_shared<T>(a); }
  template<typename T, typename A, typename Arg1>
  ALPtr<T> allocPtr(const A& a, const Arg1& arg1)
  { return ::boost::allocate_shared<T>(a, arg1); }
  template<typename T, typename A, typename Arg1, typename Arg2>
  ALPtr<T> allocPtr(const A& a, const Arg1& arg1, const Arg2& arg2)
  { return ::boost::allocate_shared<T>(a, arg1, arg2); }
  template<typename T, typename A, typename Arg1, typename Arg2, typename Arg3>
  ALPtr<T> allocPtr(const A& a, const Arg1& arg1, const Arg2& arg2, const Arg3& arg3)
  { return ::boost::allocate_shared<T>(a, arg1, arg2, arg3); }
  template<typename T, typename A, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
  ALPtr<T> allocPtr(const A& a, const Arg1& arg1, const Arg2& arg2, const Arg3& arg3, const Arg4& arg4)
  { return ::boost::allocate_shared<T>(a, arg1, arg2, arg3, arg4); }
  template<typename T, typename A, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
  ALPtr<T> allocPtr(const A& a, const Arg1& arg1, const Arg2& arg2, const Arg3& arg3, const Arg4& arg4, const Arg5& arg5)
  { return ::boost::allocate_shared<T>(a, arg1, arg2, arg3, arg4, arg5); }
  template<typename T, typename A, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
  ALPtr<T> allocPtr(const A& a, const Arg1& arg1, const Arg2& arg2, const Arg3& arg3, const Arg4& arg4, const Arg5& arg5, const Arg6& arg6)
  { return ::boost::allocate_shared<T>(a, arg1, arg2, arg3, arg4, arg5, arg6); }
  template<typename T, typename A, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
  ALPtr<T> allocPtr(const A& a, const Arg1& arg1, const Arg2& arg2, const Arg3& arg3, const Arg4& arg4, const Arg5& arg5, const Arg6& arg6, const Arg7& arg7)
  { return ::boost::allocate_shared<T>(a, arg1, arg2, arg3, arg4, arg5, arg6, arg7); }
  template<typename T, typename A, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8>
  ALPtr<T> allocPtr(const A& a, const Arg1& arg1, const Arg2& arg2, const Arg3& arg3, const Arg4& arg4, const Arg5& arg5, const Arg6& arg6, const Arg7& arg7, const Arg8& arg8)
  { return ::boost::allocate_shared<T>(a, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8); }
  template<typename T, typename A, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9>
  ALPtr<T> allocPtr(const A& a, const Arg1& arg1, const Arg2& arg2, const Arg3& arg3, const Arg4& arg4, const Arg5& arg5, const Arg6& arg6, const Arg7& arg7, const Arg8& arg8, const Arg9& arg9)
  { return ::boost::allocate_shared<T>(a, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9); }

//////////////////////////////////////////////////////////////////////////////

  // ALWeakPtr definition
  template<class T>
  class ALWeakPtr : public ::boost::weak_ptr<T>
  {
  public:
    template<class Y>
    ALWeakPtr(ALPtr<Y> const & p) : ::boost::weak_ptr<T>(p) {}

    template<class Y>
    ALWeakPtr(::boost::shared_ptr<Y> const & p) : ::boost::weak_ptr<T>(p) {}

    template<class Y>
    ALWeakPtr(::boost::weak_ptr<Y> const & p) : ::boost::weak_ptr<T>(p) {}

    ALWeakPtr() : ::boost::weak_ptr<T>() {}

    ALPtr<T> lock() const
    {
      return ::boost::weak_ptr<T>::lock();
    }
  };

//////////////////////////////////////////////////////////////////////////////

  // You can use getThis to have access to a smart pointer of this
  template<class T>
  class EnableGetThis : public ::boost::enable_shared_from_this<T>
  {
  public:
    inline ALPtr<T> getThis()
    {
      return ::boost::enable_shared_from_this<T>::shared_from_this();
    }

    inline ALPtr<const T> getThis() const
    {
      return ::boost::enable_shared_from_this<T>::shared_from_this();
    }
  };

//////////////////////////////////////////////////////////////////////////////

  // add the typedef in your class for easier use
  template<class T>
  class TypeDefPtr
  {
  public:
    typedef ALPtr<T> Ptr;
    typedef ALPtr<const T> ConstPtr;
    typedef ALWeakPtr<T> WeakPtr;
    typedef ALWeakPtr<const T> WeakConstPtr;
  };

//////////////////////////////////////////////////////////////////////////////

  template <class T>
  class AnyPtr : public EnableGetThis<T>, public TypeDefPtr<T>
  {
  };

  template<class T, class U>
  ALPtr<T> static_ptr_cast(ALPtr<U> const & r)
  {
    return ::boost::static_pointer_cast<T>(r);
  }

  template<class T, class U>
  ALPtr<T> const_ptr_cast(ALPtr<U> const & r)
  {
    return ::boost::const_pointer_cast<T>(r);
  }

  template<class T, class U>
  ALPtr<T> dynamic_ptr_cast(ALPtr<U> const & r)
  {
    return ::boost::dynamic_pointer_cast<T>(r);
  }

//////////////////////////////////////////////////////////////////////////////
}
#endif  // _LIB_ALCORE_ALCORE_ALPTR_H_
