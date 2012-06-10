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
 *  \file INCLUDE/QProblemB.hpp
 *  \author Hans Joachim Ferreau
 *  \version 2.0
 *  \date 2007-2009
 *
 *  Declaration of the QProblemB class which is able to use the newly
 *  developed online active set strategy for parametric quadratic programming
 *  for problems with (simple) bounds only.
 */



#ifndef QPOASES_QPROBLEMB_HPP
#define QPOASES_QPROBLEMB_HPP


#include <Bounds.hpp>


/** Defines if alternative Givens plane rotation requiring only three
 *  multiplications shall be used? */
#undef __USE_THREE_MULTS_GIVENS__


/** Forces to always include all implicitly fixed bounds and all equality constraints
 *  into the initial working set when setting up an auxiliary QP. */
#define __ALWAYS_INITIALISE_WITH_ALL_EQUALITIES__



#ifndef __DSPACE__
namespace qpOASES
{
#endif


class SolutionAnalysis;

/** Class for setting up and solving quadratic programs with (simple) bounds only.
 *  The main feature is the possibily to use the newly developed online active set strategy
 *  for parametric quadratic programming.
 *
 *  \author Hans Joachim Ferreau
 *  \version 2.0
 *  \date 2007-2009
 */
class QProblemB
{
  /* allow SolutionAnalysis class to access private members */
  friend class SolutionAnalysis;

  /*
   *  PUBLIC MEMBER FUNCTIONS
   */
  public:
    /** Default constructor. */
    QProblemB( );

    /** Constructor which takes the QP dimension only. */
    QProblemB(  int _nV            /**< Number of variables. */
          );

    /** Constructor which takes the QP dimension and Hessian type
     *  information. If the Hessian is the zero (i.e. HST_ZERO) or the
     *  identity matrix (i.e. HST_IDENTITY), respectively, no memory
     *  is allocated for it and a NULL pointer can be passed for it
     *  to the init() functions. */
    QProblemB(  int _nV,          /**< Number of variables. */
          HessianType _hessianType  /**< Type of Hessian matrix. */
          );

    /** Copy constructor (deep copy). */
    QProblemB(  const QProblemB& rhs  /**< Rhs object. */
          );

    /** Destructor. */
    virtual ~QProblemB( );

    /** Assignment operator (deep copy). */
    QProblemB& operator=(  const QProblemB& rhs  /**< Rhs object. */
                );


    /** Clears all data structures of QProblemB except for QP data.
     *  \return SUCCESSFUL_RETURN \n
          RET_RESET_FAILED */
    virtual returnValue reset( );


    /** Initialises a QProblemB with given QP data and solves it
     *  using an initial homotopy with empty working set (at most nWSR iterations).
     *  Note: This function internally calls solveInitialQP for initialisation!
     *  \return SUCCESSFUL_RETURN \n
          RET_INIT_FAILED \n
          RET_INIT_FAILED_CHOLESKY \n
          RET_INIT_FAILED_HOTSTART \n
          RET_INIT_FAILED_INFEASIBILITY \n
          RET_INIT_FAILED_UNBOUNDEDNESS \n
          RET_MAX_NWSR_REACHED \n
          RET_INVALID_ARGUMENTS */
    returnValue init(  const Real* const _H,   /**< Hessian matrix. \n
                               If Hessian matrix is trivial, a NULL pointer can be passed. */
              const Real* const _g,    /**< Gradient vector. */
              const Real* const _lb,  /**< Lower bounds (on variables). \n
                               If no lower bounds exist, a NULL pointer can be passed. */
              const Real* const _ub,  /**< Upper bounds (on variables). \n
                               If no upper bounds exist, a NULL pointer can be passed. */
              int& nWSR,           /**< Input: Maximum number of working set recalculations when using initial homotopy. \n
                               Output: Number of performed working set recalculations. */
               Real* const cputime    /**< Input: Maximum CPU time allowed for QP initialisation. \n
                               Output: CPU time spend for QP initialisation. */
              );

    /** Initialises a QProblemB with given QP data to be read from files and solves it
     *  using an initial homotopy with empty working set (at most nWSR iterations).
     *  Note: This function internally calls solveInitialQP for initialisation!
     *  \return SUCCESSFUL_RETURN \n
          RET_INIT_FAILED \n
          RET_INIT_FAILED_CHOLESKY \n
          RET_INIT_FAILED_HOTSTART \n
          RET_INIT_FAILED_INFEASIBILITY \n
          RET_INIT_FAILED_UNBOUNDEDNESS \n
          RET_MAX_NWSR_REACHED \n
          RET_UNABLE_TO_READ_FILE */
    returnValue init(  const char* const H_file,   /**< Name of file where Hessian matrix is stored. \n
                               If Hessian matrix is trivial, a NULL pointer can be passed. */
              const char* const g_file,    /**< Name of file where gradient vector is stored. */
              const char* const lb_file,   /**< Name of file where lower bound vector. \n
                               If no lower bounds exist, a NULL pointer can be passed. */
              const char* const ub_file,   /**< Name of file where upper bound vector. \n
                               If no upper bounds exist, a NULL pointer can be passed. */
              int& nWSR,           /**< Input: Maximum number of working set recalculations when using initial homotopy. \n
                               Output: Number of performed working set recalculations. */
               Real* const cputime    /**< Input: Maximum CPU time allowed for QP initialisation. \n
                               Output: CPU time spend for QP initialisation. */
              );

    /** Initialises a QProblemB with given QP data and solves it
     *  depending on the parameter constellation: \n
     *  1. 0,    0,    0 : start with xOpt = 0, yOpt = 0 and IB empty (or all implicit equality bounds), \n
     *  2. xOpt, 0,    0 : start with xOpt, yOpt = 0 and obtain IB by "clipping", \n
     *  3. 0,    yOpt, 0 : start with xOpt = 0, yOpt and obtain IB from yOpt != 0, \n
     *  4. 0,    0,    IB: start with xOpt = 0, yOpt = 0 and IB, \n
     *  5. xOpt, yOpt, 0 : start with xOpt, yOpt and obtain IB from yOpt != 0, \n
     *  6. xOpt, 0,    IB: start with xOpt, yOpt = 0 and IB, \n
     *  7. xOpt, yOpt, IB: start with xOpt, yOpt and IB (assume them to be consistent!)
     *  Note: This function internally calls solveInitialQP for initialisation!
     *  \return SUCCESSFUL_RETURN \n
          RET_INIT_FAILED \n
          RET_INIT_FAILED_CHOLESKY \n
          RET_INIT_FAILED_HOTSTART \n
          RET_INIT_FAILED_INFEASIBILITY \n
          RET_INIT_FAILED_UNBOUNDEDNESS \n
          RET_MAX_NWSR_REACHED \n
          RET_INVALID_ARGUMENTS */
    returnValue init(  const Real* const _H,       /**< Hessian matrix. \n
                                     If Hessian matrix is trivial, a NULL pointer can be passed. */
              const Real* const _g,        /**< Gradient vector. */
              const Real* const _lb,      /**< Lower bounds (on variables). \n
                                   If no lower bounds exist, a NULL pointer can be passed. */
              const Real* const _ub,      /**< Upper bounds (on variables). \n
                                   If no upper bounds exist, a NULL pointer can be passed. */
              int& nWSR,               /**< Input: Maximum number of working set recalculations when using initial homotopy. \n
                                   Output: Number of performed working set recalculations. */
               Real* const cputime,        /**< Input: Maximum CPU time allowed for QP initialisation. \n
                                    Output: CPU time spend for QP initialisation. */
              const Real* const xOpt,      /**< Optimal primal solution vector.
                                   A NULL pointer can be passed. */
              const Real* const yOpt,      /**< Optimal dual solution vector.
                                   A NULL pointer can be passed. */
              const Bounds* const guessedBounds  /**< Optimal working set for solution (xOpt,yOpt).
                                   A NULL pointer can be passed. */
              );

    /** Initialises a QProblemB with given QP data to be read from files and solves it
     *  depending on the parameter constellation: \n
     *  1. 0,    0,    0 : start with xOpt = 0, yOpt = 0 and IB empty (or all implicit equality bounds), \n
     *  2. xOpt, 0,    0 : start with xOpt, yOpt = 0 and obtain IB by "clipping", \n
     *  3. 0,    yOpt, 0 : start with xOpt = 0, yOpt and obtain IB from yOpt != 0, \n
     *  4. 0,    0,    IB: start with xOpt = 0, yOpt = 0 and IB, \n
     *  5. xOpt, yOpt, 0 : start with xOpt, yOpt and obtain IB from yOpt != 0, \n
     *  6. xOpt, 0,    IB: start with xOpt, yOpt = 0 and IB, \n
     *  7. xOpt, yOpt, IB: start with xOpt, yOpt and IB (assume them to be consistent!)
     *  Note: This function internally calls solveInitialQP for initialisation!
     *  \return SUCCESSFUL_RETURN \n
          RET_INIT_FAILED \n
          RET_INIT_FAILED_CHOLESKY \n
          RET_INIT_FAILED_HOTSTART \n
          RET_INIT_FAILED_INFEASIBILITY \n
          RET_INIT_FAILED_UNBOUNDEDNESS \n
          RET_MAX_NWSR_REACHED \n
          RET_UNABLE_TO_READ_FILE */
    returnValue init(  const char* const H_file,       /**< Name of file where Hessian matrix is stored. \n
                                     If Hessian matrix is trivial, a NULL pointer can be passed. */
              const char* const g_file,        /**< Name of file where gradient vector is stored. */
              const char* const lb_file,       /**< Name of file where lower bound vector. \n
                                   If no lower bounds exist, a NULL pointer can be passed. */
              const char* const ub_file,       /**< Name of file where upper bound vector. \n
                                   If no upper bounds exist, a NULL pointer can be passed. */
              int& nWSR,               /**< Input: Maximum number of working set recalculations when using initial homotopy. \n
                                   Output: Number of performed working set recalculations. */
               Real* const cputime,        /**< Input: Maximum CPU time allowed for QP initialisation. \n
                                    Output: CPU time spend for QP initialisation. */
              const Real* const xOpt,      /**< Optimal primal solution vector.
                                   A NULL pointer can be passed. */
              const Real* const yOpt,      /**< Optimal dual solution vector.
                                   A NULL pointer can be passed. */
              const Bounds* const guessedBounds  /**< Optimal working set for solution (xOpt,yOpt).
                                   A NULL pointer can be passed. */
              );


    /** Solves an initialised QProblemB using online active set strategy.
     *  Note: This function internally calls solveQP/solveRegularisedQP
     *        for solving an initialised QP!
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
    returnValue hotstart(  const Real* const g_new,  /**< Gradient of neighbouring QP to be solved. */
                const Real* const lb_new,  /**< Lower bounds of neighbouring QP to be solved. \n
                                  If no lower bounds exist, a NULL pointer can be passed. */
                const Real* const ub_new,  /**< Upper bounds of neighbouring QP to be solved. \n
                                  If no upper bounds exist, a NULL pointer can be passed. */
                int& nWSR,          /**< Input: Maximum number of working set recalculations; \n
                                 Output: Number of performed working set recalculations. */
                Real* const cputime    /**< Input: Maximum CPU time allowed for QP solution. \n
                                 Output: CPU time spend for QP solution (or to perform nWSR iterations). */
                );

    /** Solves an initialised QProblemB online active set strategy
     *  reading QP data from files.
     *  Note: This function internally calls solveQP/solveRegularisedQP
     *        for solving an initialised QP!
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
          RET_UNABLE_TO_READ_FILE \n
          RET_INVALID_ARGUMENTS */
    returnValue hotstart(  const char* const g_file,   /**< Name of file where gradient, of neighbouring QP to be solved, is stored. */
                const char* const lb_file,   /**< Name of file where lower bounds, of neighbouring QP to be solved, is stored. \n
                                  If no lower bounds exist, a NULL pointer can be passed. */
                const char* const ub_file,   /**< Name of file where upper bounds, of neighbouring QP to be solved, is stored. \n
                                  If no upper bounds exist, a NULL pointer can be passed. */
                int& nWSR,           /**< Input: Maximum number of working set recalculations; \n
                                 Output: Number of performed working set recalculations. */
                Real* const cputime    /**< Input: Maximum CPU time allowed for QP solution. \n
                                 Output: CPU time spend for QP solution (or to perform nWSR iterations). */
                );

    /** Solves an initialised QProblemB using online active set strategy (using an initialised homotopy).
     *  Note: This function internally calls solveQP/solveRegularisedQP
     *        for solving an initialised QP!
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
          RET_SETUP_AUXILIARYQP_FAILED */
    returnValue hotstart(  const Real* const g_new,      /**< Gradient of neighbouring QP to be solved. */
                const Real* const lb_new,      /**< Lower bounds of neighbouring QP to be solved. \n
                                      If no lower bounds exist, a NULL pointer can be passed. */
                const Real* const ub_new,      /**< Upper bounds of neighbouring QP to be solved. \n
                                      If no upper bounds exist, a NULL pointer can be passed. */
                int& nWSR,              /**< Input: Maximum number of working set recalculations; \n
                                     Output: Number of performed working set recalculations. */
                Real* const cputime,        /**< Input: Maximum CPU time allowed for QP solution. \n
                                      Output: CPU time spend for QP solution (or to perform nWSR iterations). */
                const Bounds* const guessedBounds  /**< Initial guess for working set of bounds.
                                   *   A null pointer corresponds to an empty working set! */
                );

    /** Solves an initialised QProblemB using online active set strategy (using an initialised homotopy)
     *  reading QP data from files.
     *  Note: This function internally calls solveQP/solveRegularisedQP
     *        for solving an initialised QP!
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
          RET_UNABLE_TO_READ_FILE \n
          RET_INVALID_ARGUMENTS \n
          RET_SETUP_AUXILIARYQP_FAILED */
    returnValue hotstart(  const char* const g_file,      /**< Name of file where gradient, of neighbouring QP to be solved, is stored. */
                const char* const lb_file,      /**< Name of file where lower bounds, of neighbouring QP to be solved, is stored. \n
                                      If no lower bounds exist, a NULL pointer can be passed. */
                const char* const ub_file,       /**< Name of file where upper bounds, of neighbouring QP to be solved, is stored. \n
                                      If no upper bounds exist, a NULL pointer can be passed. */
                int& nWSR,              /**< Input: Maximum number of working set recalculations; \n
                                     Output: Number of performed working set recalculations. */
                Real* const cputime,        /**< Input: Maximum CPU time allowed for QP solution. \n
                                      Output: CPU time spend for QP solution (or to perform nWSR iterations). */
                const Bounds* const guessedBounds  /**< Initial guess for working set of bounds.
                                   *   A null pointer corresponds to an empty working set! */
                );


    /** Returns Hessian matrix of the QP (deep copy).
      *  \return SUCCESSFUL_RETURN \n
            RET_QPOBJECT_NOT_SETUP */
    inline returnValue getH(  Real* const _H  /**< Array of appropriate dimension for copying Hessian matrix.*/
                  ) const;

    /** Returns gradient vector of the QP (deep copy).
      *  \return SUCCESSFUL_RETURN \n
            RET_QPOBJECT_NOT_SETUP */
    inline returnValue getG(  Real* const _g  /**< Array of appropriate dimension for copying gradient vector.*/
                  ) const;

    /** Returns lower bound vector of the QP (deep copy).
      *  \return SUCCESSFUL_RETURN \n
            RET_QPOBJECT_NOT_SETUP */
    inline returnValue getLB(  Real* const _lb  /**< Array of appropriate dimension for copying lower bound vector.*/
                  ) const;

    /** Returns single entry of lower bound vector of the QP.
      *  \return SUCCESSFUL_RETURN \n
            RET_QPOBJECT_NOT_SETUP \n
          RET_INDEX_OUT_OF_BOUNDS */
    inline returnValue getLB(  int number,    /**< Number of entry to be returned. */
                  Real& value  /**< Output: lb[number].*/
                  ) const;

    /** Returns upper bound vector of the QP (deep copy).
      *  \return SUCCESSFUL_RETURN \n
            RET_QPOBJECT_NOT_SETUP */
    inline returnValue getUB(  Real* const _ub  /**< Array of appropriate dimension for copying upper bound vector.*/
                  ) const;

    /** Returns single entry of upper bound vector of the QP.
      *  \return SUCCESSFUL_RETURN \n
            RET_QPOBJECT_NOT_SETUP \n
          RET_INDEX_OUT_OF_BOUNDS */
    inline returnValue getUB(  int number,    /**< Number of entry to be returned. */
                  Real& value  /**< Output: ub[number].*/
                  ) const;


    /** Returns current bounds object of the QP (deep copy).
      *  \return SUCCESSFUL_RETURN \n
            RET_QPOBJECT_NOT_SETUP */
    inline returnValue getBounds(  Bounds& _bounds  /** Output: Bounds object. */
                    ) const;


    /** Returns the number of variables.
     *  \return Number of variables. */
    inline int getNV( ) const;

    /** Returns the number of free variables.
     *  \return Number of free variables. */
    inline int getNFR( ) const;

    /** Returns the number of fixed variables.
     *  \return Number of fixed variables. */
    inline int getNFX( ) const;

    /** Returns the number of implicitly fixed variables.
     *  \return Number of implicitly fixed variables. */
    inline int getNFV( ) const;

    /** Returns the dimension of null space.
     *  \return Dimension of null space. */
    virtual int getNZ( ) const;


    /** Returns the optimal objective function value.
     *  \return finite value: Optimal objective function value (QP was solved) \n
           +infinity:    QP was not yet solved */
    Real getObjVal( ) const;

    /** Returns the objective function value at an arbitrary point x.
     *  \return Objective function value at point x */
    Real getObjVal(  const Real* const _x  /**< Point at which the objective function shall be evaluated. */
              ) const;

    /** Returns the primal solution vector.
     *  \return SUCCESSFUL_RETURN \n
          RET_QP_NOT_SOLVED */
    returnValue getPrimalSolution(  Real* const xOpt      /**< Output: Primal solution vector (if QP has been solved). */
                    ) const;

    /** Returns the dual solution vector.
     *  \return SUCCESSFUL_RETURN \n
          RET_QP_NOT_SOLVED */
    virtual returnValue getDualSolution(  Real* const yOpt  /**< Output: Dual solution vector (if QP has been solved). */
                        ) const;


    /** Returns status of the solution process.
     *  \return Status of solution process. */
    inline QProblemStatus getStatus( ) const;


    /** Returns if the QProblem object is initialised.
     *  \return BT_TRUE:  QProblemB initialised \n
           BT_FALSE: QProblemB not initialised */
    inline BooleanType isInitialised( ) const;

    /** Returns if the QP has been solved.
     *  \return BT_TRUE:  QProblemB solved \n
           BT_FALSE: QProblemB not solved */
    inline BooleanType isSolved( ) const;

    /** Returns if the QP is infeasible.
     *  \return BT_TRUE:  QP infeasible \n
           BT_FALSE: QP feasible (or not known to be infeasible!) */
    inline BooleanType isInfeasible( ) const;

    /** Returns if the QP is unbounded.
     *  \return BT_TRUE:  QP unbounded \n
           BT_FALSE: QP unbounded (or not known to be unbounded!) */
    inline BooleanType isUnbounded( ) const;


    /** Returns Hessian type flag (type is not determined due to this call!).
     *  \return Hessian type. */
    inline HessianType getHessianType( ) const;

    /** Changes the print level.
      *  \return SUCCESSFUL_RETURN */
    inline returnValue setHessianType(  HessianType _hessianType /**< New Hessian type. */
                      );

    /** Returns if the QP has been internally regularised.
     *  \return BT_TRUE:  Hessian is internally regularised for QP solution \n
           BT_FALSE: No internal Hessian regularisation is used for QP solution */
    inline BooleanType usingRegularisation( ) const;

    /** Sets scaling factor of identity matrix for regularising the Hessian.
     *  \return SUCCESSFUL_RETURN \n
          RET_EPS_MUST_BE_POSITIVE */
    inline returnValue setEpsForRegularisation(  Real _eps  /**< New scaling factor of identity matrix for regularising the Hessian. */
                          );

    /** Sets maximum number of successive regularisation steps.
     *  \return SUCCESSFUL_RETURN \n
          RET_REGSTEPS_MUST_BE_POSITIVE */
    inline returnValue setMaxNumOfRegularisationSteps(  int _nRegSteps  /**< New maximum number of successive regularisation steps. */
                              );

    /** Returns the print level.
     *  \return Print level. */
    inline PrintLevel getPrintLevel( ) const;

    /** Changes the print level.
      *  \return SUCCESSFUL_RETURN */
    returnValue setPrintLevel(  PrintLevel _printlevel  /**< New print level. */
                  );


    /** Prints concise list of properties of the current QP.
     *  \return  SUCCESSFUL_RETURN \n */
    virtual returnValue printProperties( );


  /*
   *  PROTECTED MEMBER FUNCTIONS
   */
  protected:
    /** If Hessian type has been set by the user, nothing is done.
     *  Otherwise the Hessian type is set to HST_IDENTITY, HST_ZERO, or
     *  HST_POSDEF (default), respectively.
     *  \return SUCCESSFUL_RETURN \n
          RET_HESSIAN_INDEFINITE */
    returnValue determineHessianType( );

    /** Determines type of existing constraints and bounds (i.e. implicitly fixed, unbounded etc.).
     *  \return SUCCESSFUL_RETURN \n
          RET_SETUPSUBJECTTOTYPE_FAILED */
    virtual returnValue setupSubjectToType( );

    /** Determines type of new constraints and bounds (i.e. implicitly fixed, unbounded etc.).
     *  \return SUCCESSFUL_RETURN \n
          RET_SETUPSUBJECTTOTYPE_FAILED */
    virtual returnValue setupSubjectToType(  const Real* const lb_new,  /**< New lower bounds. */
                        const Real* const ub_new  /**< New upper bounds. */
                        );

    /** Computes the Cholesky decomposition R of the (simply projected) Hessian
     *  (i.e. R^T*R = Z^T*H*Z). It only works in the case where Z is a simple
     *  projection matrix!
     *  Note: If Hessian turns out not to be positive definite, the Hessian type
     *      is set to HST_SEMIDEF accordingly.
     *  \return SUCCESSFUL_RETURN \n
     *      RET_HESSIAN_NOT_SPD \n
     *      RET_INDEXLIST_CORRUPTED */
    returnValue setupCholeskyDecomposition( );


    /** Obtains the desired working set for the auxiliary initial QP in
     *  accordance with the user specifications
     *  \return SUCCESSFUL_RETURN \n
          RET_OBTAINING_WORKINGSET_FAILED \n
          RET_INVALID_ARGUMENTS */
    returnValue obtainAuxiliaryWorkingSet(  const Real* const xOpt,      /**< Optimal primal solution vector.
                                           *   If a NULL pointer is passed, all entries are assumed to be zero. */
                        const Real* const yOpt,      /**< Optimal dual solution vector.
                                           *   If a NULL pointer is passed, all entries are assumed to be zero. */
                        const Bounds* const guessedBounds,  /**< Guessed working set for solution (xOpt,yOpt). */
                        Bounds* auxiliaryBounds        /**< Input: Allocated bound object. \n
                                           *   Ouput: Working set for auxiliary QP. */
                        ) const;


    /** Solves the system Ra = b or R^Ta = b where R is an upper triangular matrix.
     *  \return SUCCESSFUL_RETURN \n
          RET_DIV_BY_ZERO */
    returnValue backsolveR(  const Real* const b,  /**< Right hand side vector. */
                BooleanType transposed,  /**< Indicates if the transposed system shall be solved. */
                Real* const a     /**< Output: Solution vector */
                ) const;

    /** Solves the system Ra = b or R^Ta = b where R is an upper triangular matrix. \n
     *  Special variant for the case that this function is called from within "removeBound()".
     *  \return SUCCESSFUL_RETURN \n
          RET_DIV_BY_ZERO */
    returnValue backsolveR(  const Real* const b,    /**< Right hand side vector. */
                BooleanType transposed,    /**< Indicates if the transposed system shall be solved. */
                BooleanType removingBound,  /**< Indicates if function is called from "removeBound()". */
                Real* const a       /**< Output: Solution vector */
                ) const;


    /** Determines step direction of the shift of the QP data.
     *  \return SUCCESSFUL_RETURN */
    returnValue determineDataShift(  const int* const FX_idx,   /**< Index array of fixed variables. */
                    const Real* const g_new,  /**< New gradient vector. */
                    const Real* const lb_new,  /**< New lower bounds. */
                    const Real* const ub_new,  /**< New upper bounds. */
                    Real* const delta_g,     /**< Output: Step direction of gradient vector. */
                    Real* const delta_lb,     /**< Output: Step direction of lower bounds. */
                    Real* const delta_ub,     /**< Output: Step direction of upper bounds. */
                    BooleanType& Delta_bB_isZero/**< Output: Indicates if active bounds are to be shifted. */
                    ) const;


    /** Checks if lower/upper bounds remain consistent
     *  (i.e. if lb <= ub) during the current step.
     *  \return BT_TRUE iff bounds remain consistent
     */
    BooleanType areBoundsConsistent(  const Real* const delta_lb,    /**< Step direction of lower bounds. */
                      const Real* const delta_ub    /**< Step direction of upper bounds. */
                      ) const;


    /** Setups internal QP data. If the current Hessian is trivial
     *  (i.e. HST_ZERO or HST_IDENTITY) but a non-trivial one is given,
     *  memory for Hessian is allocated and it is set to the given one.
     *  \return SUCCESSFUL_RETURN \n
          RET_INVALID_ARGUMENTS \n
          RET_NO_HESSIAN_SPECIFIED */
    returnValue setupQPdata(  const Real* const _H,   /**< Hessian matrix. \n
                                     If Hessian matrix is trivial,a NULL pointer can be passed. */
                  const Real* const _g,    /**< Gradient vector. */
                  const Real* const _lb,  /**< Lower bounds (on variables). \n
                                   If no lower bounds exist, a NULL pointer can be passed. */
                  const Real* const _ub    /**< Upper bounds (on variables). \n
                                   If no upper bounds exist, a NULL pointer can be passed. */
                  );

    /** Setups internal QP data by loading it from files. If the current Hessian
     *  is trivial (i.e. HST_ZERO or HST_IDENTITY) but a non-trivial one is given,
     *  memory for Hessian is allocated and it is set to the given one.
     *  \return SUCCESSFUL_RETURN \n
          RET_UNABLE_TO_OPEN_FILE \n
          RET_UNABLE_TO_READ_FILE \n
          RET_INVALID_ARGUMENTS \n
          RET_NO_HESSIAN_SPECIFIED */
    returnValue setupQPdataFromFile(  const char* const H_file,   /**< Name of file where Hessian matrix, of neighbouring QP to be solved, is stored. \n
                                          If Hessian matrix is trivial,a NULL pointer can be passed. */
                      const char* const g_file,   /**< Name of file where gradient, of neighbouring QP to be solved, is stored. */
                      const char* const lb_file,   /**< Name of file where lower bounds, of neighbouring QP to be solved, is stored. \n
                                         If no lower bounds exist, a NULL pointer can be passed. */
                      const char* const ub_file   /**< Name of file where upper bounds, of neighbouring QP to be solved, is stored. \n
                                         If no upper bounds exist, a NULL pointer can be passed. */
                      );

    /** Loads new QP vectors from files (internal members are not affected!).
     *  \return SUCCESSFUL_RETURN \n
          RET_UNABLE_TO_OPEN_FILE \n
          RET_UNABLE_TO_READ_FILE \n
          RET_INVALID_ARGUMENTS */
    returnValue loadQPvectorsFromFile(  const char* const g_file,   /**< Name of file where gradient, of neighbouring QP to be solved, is stored. */
                      const char* const lb_file,   /**< Name of file where lower bounds, of neighbouring QP to be solved, is stored. \n
                                         If no lower bounds exist, a NULL pointer can be passed. */
                      const char* const ub_file,   /**< Name of file where upper bounds, of neighbouring QP to be solved, is stored. \n
                                         If no upper bounds exist, a NULL pointer can be passed. */
                      Real* const g_new,    /**< Output: Gradient of neighbouring QP to be solved. */
                      Real* const lb_new,    /**< Output: Lower bounds of neighbouring QP to be solved */
                      Real* const ub_new    /**< Output: Upper bounds of neighbouring QP to be solved */
                      ) const;


    /** Determines if next QP iteration can be performed within given CPU time limit.
     *  \return BT_TRUE: CPU time limit is exceeded, stop QP solution. \n
          BT_FALSE: Sufficient CPU time for next QP iteration. */
    BooleanType isCPUtimeLimitExceeded(  const Real* const cputime,  /**< Maximum CPU time allowed for QP solution. */
                      Real starttime,        /**< Start time of current QP solution. */
                      int nWSR            /**< Number of working set recalculations performed so far. */
                      ) const;


    /** Regularise Hessian matrix by adding a scaled identity matrix to it.
     *  \return SUCCESSFUL_RETURN \n
          RET_HESSIAN_ALREADY_REGULARISED */
    returnValue regulariseHessian( );

    /** Determines scaling factor of identity matrix for regularising the Hessian.
     *  \return Scaling factor of identity matrix for regularisation (eps) */
    inline Real determineEpsForRegularisation( ) const;


    /** Sets Hessian matrix of the QP.
     *  If a null pointer is passed and
     *  a) hessianType is HST_IDENTITY, nothing is done,
     *  b) hessianType is not HST_IDENTITY, Hessian matrix is set to zero.
     *  \return SUCCESSFUL_RETURN */
    inline returnValue setH(  const Real* const H_new  /**< New Hessian matrix (with correct dimension!). */
                  );

    /** Changes gradient vector of the QP.
     *  \return SUCCESSFUL_RETURN \n
     *      RET_INVALID_ARGUMENTS */
    inline returnValue setG(  const Real* const g_new  /**< New gradient vector (with correct dimension!). */
                  );

    /** Changes lower bound vector of the QP.
     *  \return SUCCESSFUL_RETURN \n
     *      RET_INVALID_ARGUMENTS */
    inline returnValue setLB(  const Real* const lb_new  /**< New lower bound vector (with correct dimension!). */
                  );

    /** Changes single entry of lower bound vector of the QP.
     *  \return SUCCESSFUL_RETURN  \n
          RET_INDEX_OUT_OF_BOUNDS */
    inline returnValue setLB(  int number,    /**< Number of entry to be changed. */
                  Real value  /**< New value for entry of lower bound vector. */
                  );

    /** Changes upper bound vector of the QP.
     *  \return SUCCESSFUL_RETURN \n
     *      RET_INVALID_ARGUMENTS */
    inline returnValue setUB(  const Real* const ub_new  /**< New upper bound vector (with correct dimension!). */
                  );

    /** Changes single entry of upper bound vector of the QP.
     *  \return SUCCESSFUL_RETURN  \n
          RET_INDEX_OUT_OF_BOUNDS */
    inline returnValue setUB(  int number,    /**< Number of entry to be changed. */
                  Real value  /**< New value for entry of upper bound vector. */
                  );


    /** Computes parameters for the Givens matrix G for which [x,y]*G = [z,0]
     *  \return SUCCESSFUL_RETURN */
    inline void computeGivens(  Real xold,  /**< Matrix entry to be normalised. */
                  Real yold,  /**< Matrix entry to be annihilated. */
                  Real& xnew,  /**< Output: Normalised matrix entry. */
                  Real& ynew,  /**< Output: Annihilated matrix entry. */
                  Real& c,    /**< Output: Cosine entry of Givens matrix. */
                  Real& s     /**< Output: Sine entry of Givens matrix. */
                  ) const;

    /** Applies Givens matrix determined by c and s (cf. computeGivens).
     *  \return SUCCESSFUL_RETURN */
    inline void applyGivens(  Real c,    /**< Cosine entry of Givens matrix. */
                  Real s,    /**< Sine entry of Givens matrix. */
                  Real nu,     /**< Further factor: s/(1+c). */
                  Real xold,  /**< Matrix entry to be transformed corresponding to
                           *   the normalised entry of the original matrix. */
                  Real yold,   /**< Matrix entry to be transformed corresponding to
                           *   the annihilated entry of the original matrix. */
                  Real& xnew,  /**< Output: Transformed matrix entry corresponding to
                           *   the normalised entry of the original matrix. */
                  Real& ynew  /**< Output: Transformed matrix entry corresponding to
                           *   the annihilated entry of the original matrix. */
                  ) const;


  /*
   *  PRIVATE MEMBER FUNCTIONS
   */
  private:
    /** Solves a QProblemB whose QP data is assumed to be stored in the member variables.
     *  A guess for its primal/dual optimal solution vectors and the corresponding
     *  optimal working set can be provided.
     *  Note: This function is internally called by all init functions!
     *  \return SUCCESSFUL_RETURN \n
          RET_INIT_FAILED \n
          RET_INIT_FAILED_CHOLESKY \n
          RET_INIT_FAILED_HOTSTART \n
          RET_INIT_FAILED_INFEASIBILITY \n
          RET_INIT_FAILED_UNBOUNDEDNESS \n
          RET_MAX_NWSR_REACHED */
    returnValue solveInitialQP(  const Real* const xOpt,      /**< Optimal primal solution vector.
                                     *   A NULL pointer can be passed. */
                  const Real* const yOpt,      /**< Optimal dual solution vector.
                                     *   A NULL pointer can be passed. */
                  const Bounds* const guessedBounds,  /**< Guessed working set for solution (xOpt,yOpt).
                                     *   A NULL pointer can be passed. */
                  int& nWSR,               /**< Input: Maximum number of working set recalculations; \n
                                      *   Output: Number of performed working set recalculations. */
                  Real* const cputime        /**< Input: Maximum CPU time allowed for QP solution. \n
                                        Output: CPU time spend for QP solution (or to perform nWSR iterations). */
                  );

    /** Solves an initialised QProblemB using online active set strategy.
     *  Note: This function is internally called by all hotstart functions!
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
    returnValue solveQP(  const Real* const g_new,  /**< Gradient of neighbouring QP to be solved. */
                const Real* const lb_new,  /**< Lower bounds of neighbouring QP to be solved. \n
                                  If no lower bounds exist, a NULL pointer can be passed. */
                const Real* const ub_new,  /**< Upper bounds of neighbouring QP to be solved. \n
                                  If no upper bounds exist, a NULL pointer can be passed. */
                int& nWSR,          /**< Input: Maximum number of working set recalculations; \n
                                 Output: Number of performed working set recalculations. */
                Real* const cputime,    /**< Input: Maximum CPU time allowed for QP solution. \n
                                 Output: CPU time spend for QP solution (or to perform nWSR iterations). */
                int  nWSRperformed      /**< Number of working set recalculations already performed to solve
                                 this QP within previous solveQP() calls. This number is
                                 always zero, except for successive calls from solveRegularisedQP(). */
                );


    /** Solves an initialised QProblemB using online active set strategy.
     *  Note: This function is internally called by all hotstart functions!
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
    returnValue solveRegularisedQP(  const Real* const g_new,  /**< Gradient of neighbouring QP to be solved. */
                    const Real* const lb_new,  /**< Lower bounds of neighbouring QP to be solved. \n
                                      If no lower bounds exist, a NULL pointer can be passed. */
                    const Real* const ub_new,  /**< Upper bounds of neighbouring QP to be solved. \n
                                      If no upper bounds exist, a NULL pointer can be passed. */
                    int& nWSR,          /**< Input: Maximum number of working set recalculations; \n
                                     Output: Number of performed working set recalculations. */
                    Real* const cputime    /**< Input: Maximum CPU time allowed for QP solution. \n
                                     Output: CPU time spend for QP solution (or to perform nWSR iterations). */
                    );


    /** Setups bound data structure according to auxiliaryBounds.
     *  (If the working set shall be setup afresh, make sure that
     *  bounds data structure has been resetted!)
     *  \return SUCCESSFUL_RETURN \n
          RET_SETUP_WORKINGSET_FAILED \n
          RET_INVALID_ARGUMENTS \n
          RET_UNKNOWN BUG */
    returnValue setupAuxiliaryWorkingSet(  const Bounds* const auxiliaryBounds,  /**< Working set for auxiliary QP. */
                        BooleanType setupAfresh          /**< Flag indicating if given working set shall be
                                             *    setup afresh or by updating the current one. */
                        );

    /** Setups the optimal primal/dual solution of the auxiliary initial QP.
     *  \return SUCCESSFUL_RETURN */
    returnValue setupAuxiliaryQPsolution(  const Real* const xOpt,      /**< Optimal primal solution vector.
                                           *   If a NULL pointer is passed, all entries are set to zero. */
                        const Real* const yOpt      /**< Optimal dual solution vector.
                                           *   If a NULL pointer is passed, all entries are set to zero. */
                        );

    /** Setups gradient of the auxiliary initial QP for given
     *  optimal primal/dual solution and given initial working set
     *  (assumes that members X, Y and BOUNDS have already been initialised!).
     *  \return SUCCESSFUL_RETURN */
    returnValue setupAuxiliaryQPgradient( );

    /** Setups bounds of the auxiliary initial QP for given
     *  optimal primal/dual solution and given initial working set
     *  (assumes that members X, Y and BOUNDS have already been initialised!).
     *  \return SUCCESSFUL_RETURN \n
          RET_UNKNOWN BUG */
    returnValue setupAuxiliaryQPbounds( BooleanType useRelaxation  /**< Flag indicating if inactive bounds shall be relaxed. */
                      );


    /** Updates QP vectors, working sets and internal data structures in order to
      start from an optimal solution corresponding to initial guesses of the working
      set for bounds
     *  \return SUCCESSFUL_RETURN \n
     *      RET_SETUP_AUXILIARYQP_FAILED */
    returnValue setupAuxiliaryQP(  const Bounds* const guessedBounds  /**< Initial guess for working set of bounds. */
                    );

    /** Determines step direction of the homotopy path.
     *  \return SUCCESSFUL_RETURN \n
           RET_STEPDIRECTION_FAILED_CHOLESKY */
    returnValue determineStepDirection(  const int* const FR_idx,     /**< Index array of free variables. */
                      const int* const FX_idx,     /**< Index array of fixed variables. */
                      const Real* const delta_g,  /**< Step direction of gradient vector. */
                      const Real* const delta_lb,  /**< Step direction of lower bounds. */
                      const Real* const delta_ub,  /**< Step direction of upper bounds. */
                      BooleanType Delta_bB_isZero,  /**< Indicates if active bounds are to be shifted. */
                      Real* const delta_xFX,     /**< Output: Primal homotopy step direction of fixed variables. */
                      Real* const delta_xFR,     /**< Output: Primal homotopy step direction of free variables. */
                      Real* const delta_yFX     /**< Output: Dual homotopy step direction of fixed variables' multiplier. */
                      ) const;

    /** Determines the maximum possible step length along the homotopy path.
     *  \return SUCCESSFUL_RETURN */
    returnValue determineStepLength(  const int* const FR_idx,     /**< Index array of free variables. */
                      const int* const FX_idx,     /**< Index array of fixed variables. */
                      const Real* const delta_lb,  /**< Step direction of lower bounds. */
                      const Real* const delta_ub,  /**< Step direction of upper bounds. */
                      const Real* const delta_xFR,  /**< Primal homotopy step direction of free variables. */
                      const Real* const delta_yFX,  /**< Dual homotopy step direction of fixed variables' multiplier. */
                      int& BC_idx,           /**< Output: Index of blocking constraint. */
                      SubjectToStatus& BC_status    /**< Output: Status of blocking constraint. */
                      );

    /** Performs a step along the homotopy path (and updates active set).
     *  \return  SUCCESSFUL_RETURN \n
            RET_OPTIMAL_SOLUTION_FOUND \n
            RET_REMOVE_FROM_ACTIVESET_FAILED \n
           RET_ADD_TO_ACTIVESET_FAILED \n
           RET_QP_INFEASIBLE */
    returnValue performStep(  const int* const FR_idx,       /**< Index array of free variables. */
                  const int* const FX_idx,       /**< Index array of fixed variables. */
                  const Real* const delta_g,     /**< Step direction of gradient vector. */
                  const Real* const delta_lb,     /**< Step direction of lower bounds. */
                  const Real* const delta_ub,     /**< Step direction of upper bounds. */
                  const Real* const delta_xFX,     /**< Primal homotopy step direction of fixed variables. */
                  const Real* const delta_xFR,     /**< Primal homotopy step direction of free variables. */
                  const Real* const delta_yFX,     /**< Dual homotopy step direction of fixed variables' multiplier. */
                  int BC_idx,             /**< Index of blocking constraint. */
                  SubjectToStatus BC_status       /**< Status of blocking constraint. */
                  );


    /** Determines if it is more efficient to refactorise the matrices when
     *  hotstarting or not (i.e. better to update the existing factorisations).
     *  \return BT_TRUE iff matrices shall be refactorised afresh
     */
    BooleanType shallRefactorise(  const Bounds* const guessedBounds  /**< Guessed new working set. */
                    ) const;


    /** Adds a bound to active set (specialised version for the case where no constraints exist).
     *  \return SUCCESSFUL_RETURN \n
           RET_ADDBOUND_FAILED */
    returnValue addBound(  int number,          /**< Number of bound to be added to active set. */
                SubjectToStatus B_status,  /**< Status of new active bound. */
                BooleanType updateCholesky  /**< Flag indicating if Cholesky decomposition shall be updated. */
                );

    /** Removes a bounds from active set (specialised version for the case where no constraints exist).
     *  \return SUCCESSFUL_RETURN \n
          RET_HESSIAN_NOT_SPD \n
          RET_REMOVEBOUND_FAILED */
    returnValue removeBound(  int number,          /**< Number of bound to be removed from active set. */
                  BooleanType updateCholesky  /**< Flag indicating if Cholesky decomposition shall be updated. */
                  );


    /** Prints concise information on the current iteration.
     *  \return  SUCCESSFUL_RETURN \n */
    returnValue printIteration(  int iteration,        /**< Number of current iteration. */
                  int BC_idx,         /**< Index of blocking bound. */
                  SubjectToStatus BC_status  /**< Status of blocking bound. */
                  );


  /*
   *  PROTECTED MEMBER VARIABLES
   */
  protected:
    Real* H;          /**< Hessian matrix. */
    Real* g;          /**< Gradient. */
    Real* lb;          /**< Lower bound vector (on variables). */
    Real* ub;          /**< Upper bound vector (on variables). */

    Bounds* bounds;        /**< Data structure for problem's bounds. */

    Real* R;          /**< Cholesky decomposition of H (i.e. H = R^T*R). */

    Real* x;          /**< Primal solution vector. */
    Real* y;          /**< Dual solution vector. */

    Real tau;          /**< Last homotopy step length. */

    Real eps;          /**< Scaling factor of identity matrix for regularising the Hessian. */
    int nRegSteps;        /**< Maximum number of successive regularisation steps. */

    QProblemStatus status;    /**< Current status of the solution process. */

    BooleanType infeasible;    /**< QP infeasible? */
    BooleanType unbounded;    /**< QP unbounded? */

    HessianType hessianType;  /**< Type of Hessian matrix. */

    PrintLevel printLevel;    /**< Print level. */

    int count;          /**< Counts the number of hotstart function calls (internal usage only!). */
};

#ifndef __DSPACE__
} /* qpOASES */
#endif

#include <QProblemB.ipp>

#endif  /* QPOASES_QPROBLEMB_HPP */


/*
 *  end of file
 */
