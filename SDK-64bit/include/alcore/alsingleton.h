/**
* @author Aldebaran Robotics
* Copyright (c) Aldebaran Robotics 2007 All Rights Reserved
*/

#pragma once

#ifndef _LIB_ALCORE_ALCORE_ALSINGLETON_H_
#define _LIB_ALCORE_ALCORE_ALSINGLETON_H_

#include <boost/shared_ptr.hpp>

namespace AL
{
  template <typename T>
  class ALSingleton
  {
  protected:

    ALSingleton() {}
    ~ALSingleton() {}

  public:
    static boost::shared_ptr<T> getInstance()
    {
      if (NULL == _singleton)
      {
        _singleton = boost::shared_ptr<T>(new T);
      }
      return _singleton;
    }

    static boost::shared_ptr<T> setInstance(boost::shared_ptr<T> pSingleton)
    {
      if (pSingleton != _singleton)
      {
        kill();
        _singleton = pSingleton;
      }
      return _singleton;
    }

    static void kill()
    {
      if (NULL != _singleton)
      {
         _singleton = boost::shared_ptr<T>();
      }
    }

  private:
    static boost::shared_ptr<T> _singleton;
  };

  template <typename T>
  boost::shared_ptr<T> ALSingleton<T>::_singleton = boost::shared_ptr<T>();
}

#endif  // _LIB_ALCORE_ALCORE_ALSINGLETON_H_
