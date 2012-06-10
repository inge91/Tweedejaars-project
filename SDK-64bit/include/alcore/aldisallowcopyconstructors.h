/**
 * Aldebaran Robotics (c) 2011 All Rights Reserved
 */

#pragma once

#ifndef _LIB_ALCORE_ALCORE_ALDISALLOWCOPYCONSTRUCTORS_H_
#define _LIB_ALCORE_ALCORE_ALDISALLOWCOPYCONSTRUCTORS_H_

#include <qi/macro.hpp>

QI_DEPRECATED_HEADER(Please use boost::noncopyable instead)

// Use this macro in the private section of your class to disallow the use of
// copy constructor and assignment operator.
// If your class has pointer attributes, you should either use this macro to
// prevent dangerous pointer sharing, or define proper copy constructors that
// take good care of it.
//
// More details here:
// http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml#Copy_Constructors
//
// Usage:
//
// class MyClass
// {
// public:
//   MyClass();
//   ~MyClass();
// private:
//   AL_DISALLOW_COPY_CONSTRUCTORS(MyClass);
// };

#undef AL_DISALLOW_COPY_CONSTRUCTORS
#define AL_DISALLOW_COPY_CONSTRUCTORS(ClassName)   \
  ClassName(const ClassName&);                     \
  void operator=(const ClassName&)


#endif  // _LIB_ALCORE_ALCORE_ALDISALLOWCOPYCONSTRUCTORS_H_

