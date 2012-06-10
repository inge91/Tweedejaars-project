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
 *  \file SRC/QProblemB.ipp
 *  \author Hans Joachim Ferreau
 *  \version 2.0
 *  \date 2007-2009
 *
 *  Implementation of inlined member functions of the QProblemB class which
 *  is able to use the newly developed online active set strategy for
 *  parametric quadratic programming.
 */


#include <math.h>


#ifndef __DSPACE__
namespace qpOASES
{
#endif

/*****************************************************************************
 *  P U B L I C                                                              *
 *****************************************************************************/

/*
 *  g e t H
 */
inline returnValue QProblemB::getH( Real* const _H ) const
{
  int i;
  int nV = getNV( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  switch ( hessianType )
  {
    case HST_ZERO:
      for ( i=0; i<nV*nV; ++i )
        _H[i] = 0.0;
      for ( i=0; i<nV; ++i )
        _H[i*nV+i] = eps;
      break;

    case HST_IDENTITY:
      for ( i=0; i<nV*nV; ++i )
        _H[i] = 0.0;
      for ( i=0; i<nV; ++i )
        _H[i*nV+i] = EXACTLYONE;
      break;

    default:
      for ( i=0; i<nV*nV; ++i )
        _H[i] = H[i];
      break;
  }

  return SUCCESSFUL_RETURN;
}


/*
 *  g e t G
 */
inline returnValue QProblemB::getG( Real* const _g ) const
{
  int i;
  int nV = getNV( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  for ( i=0; i<nV; ++i )
    _g[i] = g[i];

  return SUCCESSFUL_RETURN;
}


/*
 *  g e t L B
 */
inline returnValue QProblemB::getLB( Real* const _lb ) const
{
  int i;
  int nV = getNV( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  for ( i=0; i<nV; ++i )
    _lb[i] = lb[i];

  return SUCCESSFUL_RETURN;
}


/*
 *  g e t L B
 */
inline returnValue QProblemB::getLB( int number, Real& value ) const
{
  int nV = getNV( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  if ( ( number >= 0 ) && ( number < nV ) )
  {
    value = lb[number];
    return SUCCESSFUL_RETURN;
  }
  else
  {
    return THROWERROR( RET_INDEX_OUT_OF_BOUNDS );
  }
}


/*
 *  g e t U B
 */
inline returnValue QProblemB::getUB( Real* const _ub ) const
{
  int i;
  int nV = getNV( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  for ( i=0; i<nV; ++i )
    _ub[i] = ub[i];

  return SUCCESSFUL_RETURN;
}


/*
 *  g e t U B
 */
inline returnValue QProblemB::getUB( int number, Real& value ) const
{
  int nV = getNV( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  if ( ( number >= 0 ) && ( number < nV ) )
  {
    value = ub[number];
    return SUCCESSFUL_RETURN;
  }
  else
  {
    return THROWERROR( RET_INDEX_OUT_OF_BOUNDS );
  }
}


/*
 *  g e t B o u n d s
 */
inline returnValue QProblemB::getBounds( Bounds& _bounds ) const
{
  int nV = getNV( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  _bounds = *bounds;

  return SUCCESSFUL_RETURN;
}


/*
 *  g e t N V
 */
inline int QProblemB::getNV( ) const
{
  if ( bounds != 0 )
    return bounds->getNV( );
  else
    return 0;
}


/*
 *  g e t N F R
 */
inline int QProblemB::getNFR( ) const
{
  if ( bounds != 0 )
    return bounds->getNFR( );
  else
    return 0;
}


/*
 *  g e t N F X
 */
inline int QProblemB::getNFX( ) const
{
  if ( bounds != 0 )
    return bounds->getNFX( );
  else
    return 0;
}


/*
 *  g e t N F V
 */
inline int QProblemB::getNFV( ) const
{
  if ( bounds != 0 )
    return bounds->getNFV( );
  else
    return 0;
}


/*
 *  g e t S t a t u s
 */
inline QProblemStatus QProblemB::getStatus( ) const
{
  return status;
}


/*
 *  i s I n i t i a l i s e d
 */
inline BooleanType QProblemB::isInitialised( ) const
{
  if ( status == QPS_NOTINITIALISED )
    return BT_FALSE;
  else
    return BT_TRUE;
}


/*
 *  i s S o l v e d
 */
inline BooleanType QProblemB::isSolved( ) const
{
  if ( status == QPS_SOLVED )
    return BT_TRUE;
  else
    return BT_FALSE;
}


/*
 *  i s I n f e a s i b l e
 */
inline BooleanType QProblemB::isInfeasible( ) const
{
  return infeasible;
}


/*
 *  i s U n b o u n d e d
 */
inline BooleanType QProblemB::isUnbounded( ) const
{
  return unbounded;
}


/*
 *  g e t H e s s i a n T y p e
 */
inline HessianType QProblemB::getHessianType( ) const
{
  return hessianType;
}


/*
 *  s e t H e s s i a n T y p e
 */
inline returnValue QProblemB::setHessianType( HessianType _hessianType )
{
  hessianType = _hessianType;
  return SUCCESSFUL_RETURN;
}


/*
 *  u s i n g R e g u l a r i s a t i o n
 */
inline BooleanType QProblemB::usingRegularisation( ) const
{
  if ( eps > EPS )
    return BT_TRUE;
  else
    return BT_FALSE;
}



/*
 *  s e t E p s F o r R e g u l a r i s a t i o n
 */
inline returnValue QProblemB::setEpsForRegularisation( Real _eps )
{
  if ( _eps <= EPS )
    return THROWERROR( RET_EPS_MUST_BE_POSITVE );

  eps = -_eps; /* negative values for eps mean that regularisation is not yet used! */
  return SUCCESSFUL_RETURN;
}


/*
 *  s e t M a x N u m O f R e g u l a r i s a t i o n S t e p s
 */
inline returnValue QProblemB::setMaxNumOfRegularisationSteps( int _nRegSteps )
{
  if ( _nRegSteps < 0 )
    return THROWERROR( RET_REGSTEPS_MUST_BE_POSITVE );

  nRegSteps = _nRegSteps;
  return SUCCESSFUL_RETURN;
}



/*
 *  g e t P r i n t L e v e l
 */
inline PrintLevel QProblemB::getPrintLevel( ) const
{
  return printLevel;
}



/*****************************************************************************
 *  P R O T E C T E D                                                        *
 *****************************************************************************/


/*
 *  d e t e r m i n e E p s F o r R e g u l a r i s a t i o n
 */
inline Real QProblemB::determineEpsForRegularisation( ) const
{
  /* If eps has been specified by user via setEpsForRegularisation(), use it... */
  if ( eps < -ZERO )
    return -eps;

  /* ... otherwise use default value from global constant. */
  if ( hessianType != HST_ZERO )
    return   EPS_FOR_REGULARISATION;
  else
    return ( EPS_FOR_REGULARISATION / 100.0f );
}


/*
 *  s e t H
 */
inline returnValue QProblemB::setH( const Real* const H_new )
{
  /* if null pointer is passed, Hessian is set to zero matrix
   *                            (or stays identity matrix) */
  if ( H_new == 0 )
  {
    if ( hessianType == HST_IDENTITY )
      return SUCCESSFUL_RETURN;

    hessianType = HST_ZERO;

    if ( H != 0 )
      delete[] H;
    H = 0;
  }

  int i;
  int nV = getNV();

  for( i=0; i<nV*nV; ++i )
    H[i] = H_new[i];

  return SUCCESSFUL_RETURN;
}


/*
 *  s e t G
 */
inline returnValue QProblemB::setG( const Real* const g_new )
{
  int i;
  int nV = getNV( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  if ( g_new == 0 )
    return THROWERROR( RET_INVALID_ARGUMENTS );

  for( i=0; i<nV; ++i )
    g[i] = g_new[i];

  return SUCCESSFUL_RETURN;
}


/*
 *  s e t L B
 */
inline returnValue QProblemB::setLB( const Real* const lb_new )
{
  int i;
  int nV = getNV( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  if ( lb_new == 0 )
    return THROWERROR( RET_INVALID_ARGUMENTS );

  for( i=0; i<nV; ++i )
    lb[i] = lb_new[i];

  return SUCCESSFUL_RETURN;
}


/*
 *  s e t L B
 */
inline returnValue QProblemB::setLB( int number, Real value )
{
  int nV = getNV( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  if ( ( number >= 0 ) && ( number < nV ) )
  {
    lb[number] = value;
    return SUCCESSFUL_RETURN;
  }
  else
  {
    return THROWERROR( RET_INDEX_OUT_OF_BOUNDS );
  }
}


/*
 *  s e t U B
 */
inline returnValue QProblemB::setUB( const Real* const ub_new )
{
  int i;
  int nV = getNV( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  if ( ub_new == 0 )
    return THROWERROR( RET_INVALID_ARGUMENTS );

  for( i=0; i<nV; ++i )
    ub[i] = ub_new[i];

  return SUCCESSFUL_RETURN;
}


/*
 *  s e t U B
 */
inline returnValue QProblemB::setUB( int number, Real value )
{
  int nV = getNV( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  if ( ( number >= 0 ) && ( number < nV ) )
  {
    ub[number] = value;

    return SUCCESSFUL_RETURN;
  }
  else
  {
    return THROWERROR( RET_INDEX_OUT_OF_BOUNDS );
  }
}


/*
 *  c o m p u t e G i v e n s
 */
inline void QProblemB::computeGivens(  Real xold, Real yold, Real& xnew, Real& ynew,
                    Real& c, Real& s
                    ) const
{
  Real t, mu;

  if ( fabs( yold ) <= ZERO )
  {
    c = EXACTLYONE;
    s = EXACTLYZERO;

    xnew = xold;
    ynew = yold;
  }
  else
  {
    mu = fabs( xold );
    if ( fabs( yold ) > mu ) {
      mu = fabs( yold );
        t = mu;
        // CK: When xold is zero, there is no point taking the square root of 1.0f;
        if (xold != EXACTLYZERO) {
            Real xold_Mu = xold/mu;
            xold_Mu *= xold_Mu;
            t *= sqrt( xold_Mu + EXACTLYONE );
        }
    }
    else 
    {
        t = mu;
        // CK: When yold is zero, there is no point taking the square root of 1.0f;
        if (yold != EXACTLYZERO) {
            Real yold_Mu = yold/mu;
            yold_Mu *= yold_Mu;
            t *= sqrt( EXACTLYONE + yold_Mu );
        }
    }

    if ( xold < EXACTLYZERO ) {
        t = -t;
    }

    // CK see below
    //c = xold/t;
    //s = yold/t;
    xnew = t;
    ynew = EXACTLYZERO;
    
    // CK optimise:
    t = EXACTLYONE/t;
    c = xold * t;
    s = yold * t;
    
  }

  return;
}

/*
 *  c o m p u t e G i v e n s
 */
 /* ORIGINAL METHOD BEFORE OPTIMISATION CK
inline void QProblemB::computeGivens(  Real xold, Real yold, Real& xnew, Real& ynew,
                    Real& c, Real& s
                    ) const
{
  Real t, mu;

  if ( fabs( yold ) <= ZERO )
  {
    c = EXACTLYONE;
    s = EXACTLYZERO;

    xnew = xold;
    ynew = yold;
  }
  else
  {
    mu = fabs( xold );
    if ( fabs( yold ) > mu )
      mu = fabs( yold );

    t = mu * sqrt( (xold/mu)*(xold/mu) + (yold/mu)*(yold/mu) );

    if ( xold < EXACTLYZERO )
    t = -t;

    c = xold/t;
    s = yold/t;
    xnew = t;
    ynew = EXACTLYZERO;
  }

  return;
}
*/


/*
 *  a p p l y G i v e n s
 */
inline void QProblemB::applyGivens(  Real c, Real s, Real nu, Real xold, Real yold,
                  Real& xnew, Real& ynew
                  ) const
{
  #ifdef __USE_THREE_MULTS_GIVENS__

  /* Givens plane rotation requiring only three multiplications,
   * cf. Hammarling, S.: A note on modifications to the givens plane rotation.
   * J. Inst. Maths Applics, 13:215-218, 1974. */
  xnew = xold*c + yold*s;
  ynew = (xnew+xold)*nu - yold;

  #else

  /* Usual Givens plane rotation requiring four multiplications. */
  xnew =  c*xold + s*yold;
  ynew = -s*xold + c*yold;

  #endif

  return;
}


#ifndef __DSPACE__
} /* qpOASES */
#endif


/*
 *  end of file
 */
