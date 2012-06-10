/*
 * Copyright (c) 2012 Aldebaran Robotics. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the COPYING file.
 */

/** @file
 *  @brief
 */

#pragma once
#ifndef _LIBQI_QI_ERROR_HPP_
#define _LIBQI_QI_ERROR_HPP_

# include <qi/macro.hpp>
# include <qi/config.hpp>

# include <stdexcept>
# include <string>

namespace qi {
  namespace os {

    /** \class QiException error.hpp "qi/error.hpp"
     *  \brief Custom exception that may be thrown by QI methods.
     */
#ifdef _MSC_VER
# pragma warning( push )
# pragma warning( disable : 4251 )
#endif

    class QI_API QiException : public std::runtime_error
    {
    public:

      /**
       * \brief Constructor
       *
       * Create a message exception.
       *
       * \param message Exception message.
       */
      explicit QiException(const std::string &message)
        : std::runtime_error(message)
      {}

      /**
       * \brief Copy constructor.
       * \param message Exception message.
       */
      QiException(const QiException &e)
        : std::runtime_error(e.what())
      {}

      /** \brief Destructor */
      virtual ~QiException() throw()
      {}

#ifdef _MSC_VER
# pragma warning( pop )
#endif
    };
  }
}

#endif  // _LIBQI_QI_ERROR_HPP_
