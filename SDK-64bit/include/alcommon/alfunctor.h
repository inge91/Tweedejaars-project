/**
 * @author Aldebaran Robotics
 * Copyright (c) Aldebaran Robotics 2007, 2011 All Rights Reserved
 */

/** @file
 *  @brief
 */

#pragma once
#ifndef _LIBALCOMMON_ALCOMMON_ALFUNCTOR_H_
#define _LIBALCOMMON_ALCOMMON_ALFUNCTOR_H_

# include <alvalue/alvalue.h>
# include <boost/shared_ptr.hpp>
# include <sstream>

/// \ingroup Functor
namespace AL
{
  /**
   * \typedef ALVoid
   * \brief Type def to void.
   * \ingroup Functor
   */
  typedef void ALVoid;

  /**
   * \class ALFunctorBase alfunctor.h "alcommon/alfunctor.h"
   * \brief ALFunctorBase is a generic functor class for pointer management.
   * \ingroup Functor
   */
  class ALFunctorBase
  {
  public:
    /**
     * \brief Generic call to a bound module's method.
     * \param pParams input parameter
     * \param pResult output result
     */
    virtual void call(const ALValue& pParams, ALValue& pResult) = 0;

    /** \brief Destructor. */
    virtual ~ALFunctorBase() {}
  };
}

#include <alcommon/detail/alfunctorwithreturn.h>
#include <alcommon/detail/alfunctorwithoutreturn.h>

namespace AL {


  template <typename C, typename R>
  boost::shared_ptr<ALFunctorBase> createFunctor(C *obj, R (C::*f) ()) {
    return boost::shared_ptr<ALFunctorBase> (new detail::ALFunctor_0<C, R>(obj, f));
  }

  template <typename C, typename P1, typename R>
  boost::shared_ptr<ALFunctorBase> createFunctor(C *obj, R (C::*f) (const P1 &)) {
    return boost::shared_ptr<ALFunctorBase>(new detail::ALFunctor_1<C, P1, R>(obj, f));
  }

  template <typename C, typename P1, typename P2, typename R>
  boost::shared_ptr<ALFunctorBase> createFunctor(C *obj, R (C::*f) (const P1 &, const P2 &)) {
    return boost::shared_ptr<ALFunctorBase>(new detail::ALFunctor_2<C, P1, P2, R>(obj, f));
  }

  template <typename C, typename P1, typename P2, typename P3, typename R>
  boost::shared_ptr<ALFunctorBase> createFunctor(C *obj, R (C::*f) (const P1 &, const P2 &, const  P3 &)) {
    return boost::shared_ptr<ALFunctorBase>(new detail::ALFunctor_3<C, P1, P2, P3, R>(obj, f));
  }

  template <typename C, typename P1, typename P2, typename P3, typename P4, typename R>
  boost::shared_ptr<ALFunctorBase> createFunctor(C *obj, R (C::*f) (const P1 &, const P2 &, const P3 &, const P4 &)) {
    return boost::shared_ptr<ALFunctorBase>(new detail::ALFunctor_4<C, P1, P2, P3, P4, R>(obj, f));
  }

  template <typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename R>
  boost::shared_ptr<ALFunctorBase> createFunctor(C *obj, R (C::*f) (const P1 &, const P2 &, const P3 &, const P4 &, const P5 &)) {
    return boost::shared_ptr<ALFunctorBase>(new detail::ALFunctor_5<C, P1, P2, P3, P4, P5, R>(obj, f));
  }

  template <typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename R>
  boost::shared_ptr<ALFunctorBase> createFunctor(C *obj, R (C::*f) (const P1 &, const P2 &, const P3  &, const P4 &, const P5 &, const P6 &)) {
    return boost::shared_ptr<ALFunctorBase>(new detail::ALFunctor_6<C, P1, P2, P3, P4, P5, P6, R>(obj, f));
  }

}

#endif  // _LIBALCOMMON_ALCOMMON_ALFUNCTOR_H_
