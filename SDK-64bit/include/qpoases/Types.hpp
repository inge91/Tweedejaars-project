/*
 *  This file is part of qpOASES.
 *
 *  qpOASES -- An Implementation of the Online Active Set Strategy.
 *  Copyright (C) 2007-2009 by Hans Joachim Ferreau et al. All rights reserved.
 *
 *  qpOASES is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  qpOASES is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with qpOASES; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


/**
 *  \file INCLUDE/Types.hpp
 *  \author Hans Joachim Ferreau
 *  \version 2.0
 *  \date 2007-2009
 *
 *  Declaration of all non-built-in types (except for classes).
 */


#ifndef QPOASES_TYPES_HPP
#define QPOASES_TYPES_HPP


#ifndef __DSPACE__
namespace qpOASES
{
#endif

#define REAL_IS_FLOAT

#ifdef REAL_IS_FLOAT
typedef float Real;
#define FLOAT_SUFFIX f
#else
typedef double Real;
#define FLOAT_SUFFIX
#endif

/** Summarises all possible logical values. */
enum BooleanType
{
  BT_FALSE,          /**< Logical value for "false". */
  BT_TRUE            /**< Logical value for "true". */
};


/** Summarises all possible print levels. Print levels are used to describe
 *  the desired amount of output during runtime of qpOASES. */
enum PrintLevel
{
  PL_NONE,          /**< No output. */
  PL_LOW,            /**< Print error messages only. */
  PL_MEDIUM,          /**< Print error and warning messages as well as concise info messages. */
  PL_HIGH            /**< Print all messages with full details. */
};


/** Defines visibility status of a message. */
enum VisibilityStatus
{
  VS_HIDDEN,          /**< Message not visible. */
  VS_VISIBLE          /**< Message visible. */
};


/** Summarises all possible states of the (S)QProblem(B) object during the
solution process of a QP sequence. */
enum QProblemStatus
{
  QPS_NOTINITIALISED,      /**< QProblem object is freshly instantiated or reset. */
  QPS_PREPARINGAUXILIARYQP,  /**< An auxiliary problem is currently setup, either at the very beginning
                 *   via an initial homotopy or after changing the QP matrices. */
  QPS_AUXILIARYQPSOLVED,    /**< An auxilary problem was solved, either at the very beginning
                 *   via an initial homotopy or after changing the QP matrices. */
  QPS_PERFORMINGHOMOTOPY,    /**< A homotopy according to the main idea of the online active
                 *   set strategy is performed. */
  QPS_HOMOTOPYQPSOLVED,    /**< An intermediate QP along the homotopy path was solved. */
  QPS_SOLVED          /**< The solution of the actual QP was found. */
};


/** Summarises all possible types of the QP's Hessian matrix. */
enum HessianType
{
  HST_ZERO,          /**< Hessian is zero matrix (i.e. LP formulation). */
  HST_IDENTITY,        /**< Hessian is identity matrix. */
//  HST_DIAGONAL,        /**< Hessian is a diagonal matrix with non-negative entries. */
  HST_POSDEF,          /**< Hessian is (strictly) positive definite. */
  HST_POSDEF_NULLSPACE,    /**< Hessian is positive definite on null space of active bounds/constraints. */
  HST_SEMIDEF,        /**< Hessian is positive semi-definite. */
  HST_UNKNOWN          /**< Hessian type is unknown. */
};


/** Summarises all possible types of bounds and constraints. */
enum SubjectToType
{
  ST_UNBOUNDED,    /**< Bound/constraint is unbounded. */
  ST_BOUNDED,      /**< Bound/constraint is bounded but not fixed. */
  ST_EQUALITY,    /**< Bound/constraint is fixed (implicit equality bound/constraint). */
  ST_UNKNOWN      /**< Type of bound/constraint unknown. */
};


/** Summarises all possible states of bounds and constraints. */
enum SubjectToStatus
{
  ST_INACTIVE,      /**< Bound/constraint is inactive. */
  ST_LOWER,        /**< Bound/constraint is at its lower bound. */
  ST_UPPER,        /**< Bound/constraint is at its upper bound. */
  ST_DISABLED,      /**< Bound/constraint is disabled (i.e. not included into QP formulation). */
  ST_DISABLING,      /**< Bound/constraint is to be disabled (i.e. to be removed from QP formulation). */
  ST_UNDEFINED      /**< Status of bound/constraint undefined. */
};


/** Summarises all possible cycling states of bounds and constraints. */
enum CyclingStatus
{
  CYC_NOT_INVOLVED,  /**< Bound/constraint is not involved in current cycling. */
  CYC_PREV_ADDED,    /**< Bound/constraint has previously been added during the current cycling. */
  CYC_PREV_REMOVED  /**< Bound/constraint has previously been removed during the current cycling. */
};

#ifndef __DSPACE__
} /* qpOASES */
#endif


#endif  /* QPOASES_TYPES_HPP */


/*
 *  end of file
 */
