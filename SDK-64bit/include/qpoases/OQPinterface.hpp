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
 *  \file INCLUDE/EXTRAS/OQPinterface.hpp
 *  \author Hans Joachim Ferreau
 *  \version 2.0
 *  \date 2008-2009
 *
 *  Declaration of an interface comprising several utility functions
 *  for solving test problems from the Online QP Benchmark Collection
 *  (see http://homes.esat.kuleuven.be/~optec/software/onlineQP/).
 */


#ifndef QPOASES_OQPINTERFACE_HPP
#define QPOASES_OQPINTERFACE_HPP


#include <Utils.hpp>


namespace qpOASES
{

/** Reads dimensions of an Online QP Benchmark problem from file.
 * \return SUCCESSFUL_RETURN \n
       RET_UNABLE_TO_READ_FILE \n
       RET_FILEDATA_INCONSISTENT */
returnValue readOQPdimensions(  const char* path,  /**< Full path of the data files (without trailing slash!). */
                int& nQP,      /**< Output: Number of QPs. */
                int& nV,      /**< Output: Number of variables. */
                int& nC,      /**< Output: Number of constraints. */
                int& nEC      /**< Output: Number of equality constraints. */
                );

/** Reads data of an Online QP Benchmark problem from file.
 *  This function allocates the required memory for all data; after successfully calling it,
 *  you have to free this memory yourself!
 * \return SUCCESSFUL_RETURN \n
       RET_INVALID_ARGUMENTS \n
       RET_UNABLE_TO_READ_FILE \n
       RET_FILEDATA_INCONSISTENT */
returnValue readOQPdata(  const char* path,  /**< Full path of the data files (without trailing slash!). */
              int& nQP,      /**< Output: Number of QPs. */
              int& nV,      /**< Output: Number of variables. */
              int& nC,      /**< Output: Number of constraints. */
              int& nEC,      /**< Output: Number of equality constraints. */
              Real** H,       /**< Output: Hessian matrix. */
              Real** g,       /**< Output: Sequence of gradient vectors. */
              Real** A,       /**< Output: Constraint matrix. */
              Real** lb,    /**< Output: Sequence of lower bound vectors (on variables). */
              Real** ub,    /**< Output: Sequence of upper bound vectors (on variables). */
              Real** lbA,    /**< Output: Sequence of lower constraints' bound vectors. */
              Real** ubA,    /**< Output: Sequence of upper constraints' bound vectors. */
              Real** xOpt,    /**< Output: Sequence of primal solution vectors
                         *           (not read if a null pointer is passed). */
              Real** yOpt,    /**< Output: Sequence of dual solution vectors
                         *           (not read if a null pointer is passed). */
              Real** objOpt    /**< Output: Sequence of optimal objective function values
                         *           (not read if a null pointer is passed). */
              );


/** Solves an Online QP Benchmark problem as specified by the arguments.
 *  The maximum deviations from the given optimal solution as well as the
 *  maximum CPU time to solve each QP are determined.
 * \return SUCCESSFUL_RETURN \n
        RET_BENCHMARK_ABORTED */
returnValue solveOQPbenchmark(  int nQP,          /**< Number of QPs. */
                int nV,            /**< Number of variables. */
                int nC,            /**< Number of constraints. */
                int nEC,          /**< Number of equality constraints. */
                const Real* const H,    /**< Hessian matrix. */
                const Real* const g,    /**< Sequence of gradient vectors. */
                const Real* const A,    /**< Constraint matrix. */
                const Real* const lb,    /**< Sequence of lower bound vectors (on variables). */
                const Real* const ub,    /**< Sequence of upper bound vectors (on variables). */
                const Real* const lbA,  /**< Sequence of lower constraints' bound vectors. */
                const Real* const ubA,  /**< Sequence of upper constraints' bound vectors. */
                const Real* const xOpt,  /**< Sequence of primal solution vectors. */
                const Real* const yOpt,  /**< Sequence of dual solution vectors. */
                const Real* const objOpt,  /**< Sequence of optimal objective function values. */
                int& nWSR,           /**< Input: Maximum number of working set recalculations; \n
                                 Output: Maximum number of performed working set recalculations. */
                Real& maxCPUtime,      /**< Maximum CPU time required for solving each QP. */
                Real& maxPrimalDeviation,  /**< Maximum deviation of primal solution vector. */
                Real& maxDualDeviation,  /**< Maximum deviation of dual solution vector. */
                Real& maxObjDeviation    /**< Maximum deviation of optimal objective function value. */
                );

/** Solves an Online QP Benchmark problem (without constraints) as specified
 *  by the arguments. The maximum deviations from the given optimal solution
 *  as well as the maximum CPU time to solve each QP are determined.
 * \return SUCCESSFUL_RETURN \n
        RET_BENCHMARK_ABORTED */
returnValue solveOQPbenchmark(  int nQP,          /**< Number of QPs. */
                int nV,            /**< Number of variables. */
                const Real* const H,    /**< Hessian matrix. */
                const Real* const g,    /**< Sequence of gradient vectors. */
                const Real* const lb,    /**< Sequence of lower bound vectors (on variables). */
                const Real* const ub,    /**< Sequence of upper bound vectors (on variables). */
                const Real* const xOpt,  /**< Sequence of primal solution vectors. */
                const Real* const yOpt,  /**< Sequence of dual solution vectors. */
                const Real* const objOpt,  /**< Sequence of optimal objective function values. */
                int& nWSR,           /**< Input: Maximum number of working set recalculations; \n
                                 Output: Maximum number of performed working set recalculations. */
                Real& maxCPUtime,      /**< Maximum CPU time required for solving each QP. */
                Real& maxPrimalDeviation,  /**< Maximum deviation of primal solution vector. */
                Real& maxDualDeviation,  /**< Maximum deviation of dual solution vector. */
                Real& maxObjDeviation    /**< Maximum deviation of optimal objective function value. */
                );


/** Runs an Online QP Benchmark problem and determines the maximum
 *  deviations from the given optimal solution as well as the
 *  maximum CPU time to solve each QP.
 * \return SUCCESSFUL_RETURN \n
       RET_UNABLE_TO_READ_BENCHMARK \n
        RET_BENCHMARK_ABORTED */
returnValue runOQPbenchmark(  const char* path,      /**< Full path of the benchmark files (without trailing slash!). */
                int& nWSR,           /**< Input: Maximum number of working set recalculations; \n
                                 Output: Maximum number of performed working set recalculations. */
                Real& maxCPUtime,      /**< Maximum CPU time required for solving each QP. */
                Real& maxPrimalDeviation,  /**< Maximum deviation of primal solution vector. */
                Real& maxDualDeviation,  /**< Maximum deviation of dual solution vector. */
                Real& maxObjDeviation    /**< Maximum deviation of optimal objective function value. */
                );

} /* qpOASES */

#endif  /* QPOASES_OQPINTERFACE_HPP */


/*
 *  end of file
 */
