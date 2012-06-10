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
 *  \file INCLUDE/SQProblem.hpp
 *  \author Hans Joachim Ferreau
 *  \version 2.0
 *  \date 2007-2009
 *
 *  Declaration of the SQProblem class which is able to use the newly
 *  developed online active set strategy for parametric quadratic programming
 *  with varying matrices.
 */



#ifndef QPOASES_SQPROBLEM_HPP
#define QPOASES_SQPROBLEM_HPP


#include <QProblem.hpp>


#ifndef __DSPACE__
namespace qpOASES
{
#endif

/** A class for setting up and solving quadratic programs with varying QP matrices.
 *  The main feature is the possibily to use the newly developed online active set strategy
 *  for parametric quadratic programming.
 *
 *  \author Hans Joachim Ferreau
 *  \version 1.3
 *  \date 2007-2008
 */
class SQProblem : public QProblem
{
  /* allow SolutionAnalysis class to access private members */
  friend class SolutionAnalysis;

  /*
   *  PUBLIC MEMBER FUNCTIONS
   */
  public:
    /** Default constructor. */
    SQProblem( );

    /** Constructor which takes the QP dimensions only. */
    SQProblem(  int _nV,          /**< Number of variables. */
          int _nC            /**< Number of constraints. */
          );

    /** Constructor which takes the QP dimension and Hessian type
     *  information. If the Hessian is the zero (i.e. HST_ZERO) or the
     *  identity matrix (i.e. HST_IDENTITY), respectively, no memory
     *  is allocated for it and a NULL pointer can be passed for it
     *  to the init() functions. */
    SQProblem(  int _nV,            /**< Number of variables. */
          int _nC,            /**< Number of constraints. */
          HessianType _hessianType  /**< Type of Hessian matrix. */
          );

    /** Copy constructor (deep copy). */
    SQProblem(  const SQProblem& rhs  /**< Rhs object. */
          );

    /** Destructor. */
    virtual ~SQProblem( );

    /** Assignment operator (deep copy). */
    SQProblem& operator=(  const SQProblem& rhs  /**< Rhs object. */
                );


    /** Solves an initialised SQProblem using online active set strategy.
     *  \return SUCCESSFUL_RETURN \n
           RET_MAX_NWSR_REACHED \n
           RET_HOTSTART_FAILED_AS_QP_NOT_INITIALISED \n
          RET_HOTSTART_FAILED \n
          RET_MATRIX_SHIFT_FAILED \n
          RET_SHIFT_DETERMINATION_FAILED \n
          RET_STEPDIRECTION_DETERMINATION_FAILED \n
          RET_STEPLENGTH_DETERMINATION_FAILED \n
          RET_HOMOTOPY_STEP_FAILED \n
          RET_HOTSTART_STOPPED_INFEASIBILITY \n
          RET_HOTSTART_STOPPED_UNBOUNDEDNESS \n
          RET_SETUP_AUXILIARYQP_FAILED */
    returnValue hotstart(  const Real* const H_new,  /**< Hessian matrix of neighbouring QP to be solved. \n
                                 If Hessian matrix is trivial, a NULL pointer can be passed. */
                const Real* const g_new,  /**< Gradient of neighbouring QP to be solved. */
                const Real* const A_new,  /**< Constraint matrix of neighbouring QP to be solved. \n
                                 If QP sequence does not involve constraints, a NULL pointer can be passed. */
                const Real* const lb_new,  /**< Lower bounds of neighbouring QP to be solved. \n
                                   If no lower bounds exist, a NULL pointer can be passed. */
                const Real* const ub_new,  /**< Upper bounds of neighbouring QP to be solved. \n
                                   If no upper bounds exist, a NULL pointer can be passed. */
                const Real* const lbA_new,/**< Lower constraints' bounds of neighbouring QP to be solved. \n
                                   If no lower constraints' bounds exist, a NULL pointer can be passed. */
                const Real* const ubA_new,/**< Upper constraints' bounds of neighbouring QP to be solved. \n
                                   If no upper constraints' bounds exist, a NULL pointer can be passed. */
                int& nWSR,          /**< Input: Maximum number of working set recalculations; \n
                                 Output: Number of performed working set recalculations. */
                Real* const cputime    /**< Input: Maximum CPU time allowed for QP solution. \n
                                 Output: CPU time spend for QP solution (or to perform nWSR iterations). */
                );

    /** Solves an initialised SQProblem using online active set strategy
     *  reading QP data from files.
     *  \return SUCCESSFUL_RETURN \n
           RET_MAX_NWSR_REACHED \n
           RET_HOTSTART_FAILED_AS_QP_NOT_INITIALISED \n
          RET_HOTSTART_FAILED \n
          RET_MATRIX_SHIFT_FAILED \n
          RET_SHIFT_DETERMINATION_FAILED \n
          RET_STEPDIRECTION_DETERMINATION_FAILED \n
          RET_STEPLENGTH_DETERMINATION_FAILED \n
          RET_HOMOTOPY_STEP_FAILED \n
          RET_HOTSTART_STOPPED_INFEASIBILITY \n
          RET_HOTSTART_STOPPED_UNBOUNDEDNESS \n
          RET_SETUP_AUXILIARYQP_FAILED \n
          RET_UNABLE_TO_READ_FILE \n
          RET_INVALID_ARGUMENTS */
    returnValue hotstart(  const char* const H_file,  /**< Name of file where Hessian matrix is stored. \n
                                 If Hessian matrix is trivial, a NULL pointer can be passed. */
                const char* const g_file,   /**< Name of file where gradient, of neighbouring QP to be solved, is stored. */
                const char* const A_file,  /**< Name of file where constraint matrix is stored. \n
                                 If QP sequence does not involve constraints, a NULL pointer can be passed. */
                const char* const lb_file,   /**< Name of file where lower bounds, of neighbouring QP to be solved, is stored. \n
                                  If no lower bounds exist, a NULL pointer can be passed. */
                const char* const ub_file,   /**< Name of file where upper bounds, of neighbouring QP to be solved, is stored. \n
                                  If no upper bounds exist, a NULL pointer can be passed. */
                const char* const lbA_file, /**< Name of file where lower constraints' bounds, of neighbouring QP to be solved, is stored. \n
                                  If no lower constraints' bounds exist, a NULL pointer can be passed. */
                const char* const ubA_file, /**< Name of file where upper constraints' bounds, of neighbouring QP to be solved, is stored. \n
                                  If no upper constraints' bounds exist, a NULL pointer can be passed. */
                int& nWSR,          /**< Input: Maximum number of working set recalculations; \n
                                 Output: Number of performed working set recalculations. */
                Real* const cputime    /**< Input: Maximum CPU time allowed for QP solution. \n
                                 Output: CPU time spend for QP solution (or to perform nWSR iterations). */
                );

    /** Solves an initialised SQProblem (without matrix shift) using online active set strategy.
     *  Note: This functions just forwards to the corresponding
     *      QProblem::hotstart member function.
     *  \return SUCCESSFUL_RETURN \n
           RET_MAX_NWSR_REACHED \n
           RET_HOTSTART_FAILED_AS_QP_NOT_INITIALISED \n
          RET_HOTSTART_FAILED \n
          RET_SHIFT_DETERMINATION_FAILED \n
          RET_STEPDIRECTION_DETERMINATION_FAILED \n
          RET_STEPLENGTH_DETERMINATION_FAILED \n
          RET_HOMOTOPY_STEP_FAILED \n
          RET_HOTSTART_STOPPED_INFEASIBILITY \n
          RET_HOTSTART_STOPPED_UNBOUNDEDNESS */
    returnValue hotstart(  const Real* const g_new,    /**< Gradient of neighbouring QP to be solved. */
                const Real* const lb_new,    /**< Lower bounds of neighbouring QP to be solved. \n
                                     If no lower bounds exist, a NULL pointer can be passed. */
                const Real* const ub_new,    /**< Upper bounds of neighbouring QP to be solved. \n
                                     If no upper bounds exist, a NULL pointer can be passed. */
                const Real* const lbA_new,  /**< Lower constraints' bounds of neighbouring QP to be solved. \n
                                     If no lower constraints' bounds exist, a NULL pointer can be passed. */
                const Real* const ubA_new,  /**< Upper constraints' bounds of neighbouring QP to be solved. \n
                                     If no upper constraints' bounds exist, a NULL pointer can be passed. */
                int& nWSR,            /**< Input: Maximum number of working set recalculations; \n
                                   Output: Number of performed working set recalculations. */
                Real* const cputime      /**< Input: Maximum CPU time allowed for QP solution. \n
                                   Output: CPU time spend for QP solution (or to perform nWSR iterations). */
                );

    /** Solves an initialised SQProblem (without matrix shift) using online active set strategy
     *  reading QP data from files.
     *  Note: This functions just forwards to the corresponding
     *      QProblem::hotstart member function.
     *  \return SUCCESSFUL_RETURN \n
           RET_MAX_NWSR_REACHED \n
           RET_HOTSTART_FAILED_AS_QP_NOT_INITIALISED \n
          RET_HOTSTART_FAILED \n
          RET_SHIFT_DETERMINATION_FAILED \n
          RET_STEPDIRECTION_DETERMINATION_FAILED \n
          RET_STEPLENGTH_DETERMINATION_FAILED \n
          RET_HOMOTOPY_STEP_FAILED \n
          RET_HOTSTART_STOPPED_INFEASIBILITY \n
          RET_HOTSTART_STOPPED_UNBOUNDEDNESS \n
          RET_UNABLE_TO_READ_FILE */
    returnValue hotstart(  const char* const g_file,   /**< Name of file where gradient, of neighbouring QP to be solved, is stored. */
                const char* const lb_file,   /**< Name of file where lower bounds, of neighbouring QP to be solved, is stored. \n
                                  If no lower bounds exist, a NULL pointer can be passed. */
                const char* const ub_file,   /**< Name of file where upper bounds, of neighbouring QP to be solved, is stored. \n
                                  If no upper bounds exist, a NULL pointer can be passed. */
                const char* const lbA_file, /**< Name of file where lower constraints' bounds, of neighbouring QP to be solved, is stored. \n
                                  If no lower constraints' bounds exist, a NULL pointer can be passed. */
                const char* const ubA_file, /**< Name of file where upper constraints' bounds, of neighbouring QP to be solved, is stored. \n
                                  If no upper constraints' bounds exist, a NULL pointer can be passed. */
                int& nWSR,           /**< Input: Maximum number of working set recalculations; \n
                                 Output: Number of performed working set recalculations. */
                Real* const cputime    /**< Input: Maximum CPU time allowed for QP solution. \n
                                 Output: CPU time spend for QP solution (or to perform nWSR iterations). */
                );

    /** Solves an initialised SQProblem (without matrix shift) using online active set strategy
     *  (using an initialised homotopy).
     *  Note: This functions just forwards to the corresponding
     *      QProblem::hotstart member function.
     *  \return SUCCESSFUL_RETURN \n
           RET_MAX_NWSR_REACHED \n
           RET_HOTSTART_FAILED_AS_QP_NOT_INITIALISED \n
          RET_HOTSTART_FAILED \n
          RET_SHIFT_DETERMINATION_FAILED \n
          RET_STEPDIRECTION_DETERMINATION_FAILED \n
          RET_STEPLENGTH_DETERMINATION_FAILED \n
          RET_HOMOTOPY_STEP_FAILED \n
          RET_HOTSTART_STOPPED_INFEASIBILITY \n
          RET_HOTSTART_STOPPED_UNBOUNDEDNESS \n
          RET_WORKINGSET_UPDATE_FAILED */
    returnValue hotstart(  const Real* const g_new,          /**< Gradient of neighbouring QP to be solved. */
                const Real* const lb_new,          /**< Lower bounds of neighbouring QP to be solved. \n
                                           If no lower bounds exist, a NULL pointer can be passed. */
                const Real* const ub_new,          /**< Upper bounds of neighbouring QP to be solved. \n
                                           If no upper bounds exist, a NULL pointer can be passed. */
                const Real* const lbA_new,        /**< Lower constraints' bounds of neighbouring QP to be solved. \n
                                           If no lower constraints' bounds exist, a NULL pointer can be passed. */
                const Real* const ubA_new,        /**< Upper constraints' bounds of neighbouring QP to be solved. \n
                                          If no upper constraints' bounds exist, a NULL pointer can be passed. */
                int& nWSR,                  /**< Input: Maximum number of working set recalculations; \n
                                         Output: Number of performed working set recalculations. */
                Real* const cputime,            /**< Input: Maximum CPU time allowed for QP solution. \n
                                           Output: CPU time spend for QP solution (or to perform nWSR iterations). */
                const Bounds* const guessedBounds,      /**< Initial guess for working set of bounds.
                                       *   A null pointer corresponds to an empty working set! */
                const Constraints* const guessedConstraints  /**< Initial guess for working set of constraints.
                                       *   A null pointer corresponds to an empty working set! */
                );

    /** Solves an initialised SQProblem (without matrix shift) using online active set strategy
     * (using an initialised homotopy) reading QP data from files.
     *  Note: This functions just forwards to the corresponding
     *      QProblem::hotstart member function.
     *  \return SUCCESSFUL_RETURN \n
           RET_MAX_NWSR_REACHED \n
           RET_HOTSTART_FAILED_AS_QP_NOT_INITIALISED \n
          RET_HOTSTART_FAILED \n
          RET_SHIFT_DETERMINATION_FAILED \n
          RET_STEPDIRECTION_DETERMINATION_FAILED \n
          RET_STEPLENGTH_DETERMINATION_FAILED \n
          RET_HOMOTOPY_STEP_FAILED \n
          RET_HOTSTART_STOPPED_INFEASIBILITY \n
          RET_HOTSTART_STOPPED_UNBOUNDEDNESS \n
          RET_WORKINGSET_UPDATE_FAILED \n
          RET_UNABLE_TO_READ_FILE */
    returnValue hotstart(  const char* const g_file,           /**< Name of file where gradient, of neighbouring QP to be solved, is stored. */
                const char* const lb_file,           /**< Name of file where lower bounds, of neighbouring QP to be solved, is stored. \n
                                          If no lower bounds exist, a NULL pointer can be passed. */
                const char* const ub_file,           /**< Name of file where upper bounds, of neighbouring QP to be solved, is stored. \n
                                          If no upper bounds exist, a NULL pointer can be passed. */
                const char* const lbA_file,         /**< Name of file where lower constraints' bounds, of neighbouring QP to be solved, is stored. \n
                                          If no lower constraints' bounds exist, a NULL pointer can be passed. */
                const char* const ubA_file,         /**< Name of file where upper constraints' bounds, of neighbouring QP to be solved, is stored. \n
                                          If no upper constraints' bounds exist, a NULL pointer can be passed. */
                int& nWSR,                  /**< Input: Maximum number of working set recalculations; \n
                                          Output: Number of performed working set recalculations. */
                Real* const cputime,            /**< Input: Maximum CPU time allowed for QP solution. \n
                                           Output: CPU time spend for QP solution (or to perform nWSR iterations). */
                const Bounds* const guessedBounds,      /**< Initial guess for working set of bounds.
                                       *   A null pointer corresponds to an empty working set! */
                const Constraints* const guessedConstraints  /**< Initial guess for working set of constraints.
                                       *   A null pointer corresponds to an empty working set! */
                );


  /*
   *  PROTECTED MEMBER FUNCTIONS
   */
  protected:
    /** Sets new matrices and calculates their factorisations. If the
     *  current Hessian is trivial (i.e. HST_ZERO or HST_IDENTITY) but a
     *  non-trivial one is given, memory for Hessian is allocated and
     *  it is set to the given one. Afterwards, all QP vectors are
     *  transformed in order to start from an optimal solution.
     *  \return SUCCESSFUL_RETURN \n
     *      RET_MATRIX_FACTORISATION_FAILED \n
     *       RET_NO_HESSIAN_SPECIFIED */
    virtual returnValue setupAuxiliaryQP(  const Real* const H_new,  /**< New Hessian matrix. \n
                                             If Hessian matrix is trivial, a NULL pointer can be passed. */
                        const Real* const A_new  /**< New constraint matrix. \n
                                             If QP sequence does not involve constraints, a NULL pointer can be passed. */
                        );


  /*
   *  PROTECTED MEMBER VARIABLES
   */
  protected:

};

#ifndef __DSPACE__
} /* qpOASES */
#endif

#include <SQProblem.ipp>

#endif  /* QPOASES_SQPROBLEM_HPP */


/*
 *  end of file
 */
