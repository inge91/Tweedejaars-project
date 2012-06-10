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
 *  \file SRC/QProblem.ipp
 *  \author Hans Joachim Ferreau
 *  \version 2.0
 *  \date 2007-2009
 *
 *  Implementation of inlined member functions of the QProblem class which
 *  is able to use the newly developed online active set strategy for
 *  parametric quadratic programming.
 */


#ifndef __DSPACE__
namespace qpOASES
{
#endif

/*****************************************************************************
 *  P U B L I C                                                              *
 *****************************************************************************/

/*
 *  g e t A
 */
inline returnValue QProblem::getA( Real* const _A ) const
{
  int i;
  int nV = getNV( );
  int nC = getNC( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  for ( i=0; i<nV*nC; ++i )
    _A[i] = A[i];

  return SUCCESSFUL_RETURN;
}


/*
 *  g e t A
 */
inline returnValue QProblem::getA( int number, Real* const row ) const
{
  int nV = getNV( );
  int nC = getNC( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  if ( ( number >= 0 ) && ( number < nC ) )
  {
    for ( int i=0; i<nV; ++i )
      row[i] = A[number*nV + i];

    return SUCCESSFUL_RETURN;
  }
  else
    return THROWERROR( RET_INDEX_OUT_OF_BOUNDS );
}


/*
 *  g e t L B A
 */
inline returnValue QProblem::getLBA( Real* const _lbA ) const
{
  int i;
  int nV = getNV( );
  int nC = getNC( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  for ( i=0; i<nC; ++i )
    _lbA[i] = lbA[i];

  return SUCCESSFUL_RETURN;
}


/*
 *  g e t L B A
 */
inline returnValue QProblem::getLBA( int number, Real& value ) const
{
  int nV = getNV( );
  int nC = getNC( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  if ( ( number >= 0 ) && ( number < nC ) )
  {
    value = lbA[number];
    return SUCCESSFUL_RETURN;
  }
  else
    return THROWERROR( RET_INDEX_OUT_OF_BOUNDS );
}


/*
 *  g e t U B A
 */
inline returnValue QProblem::getUBA( Real* const _ubA ) const
{
  int i;
  int nV = getNV( );
  int nC = getNC( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  for ( i=0; i<nC; ++i )
    _ubA[i] = ubA[i];

  return SUCCESSFUL_RETURN;
}


/*
 *  g e t U B A
 */
inline returnValue QProblem::getUBA( int number, Real& value ) const
{
  int nV = getNV( );
  int nC = getNC( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  if ( ( number >= 0 ) && ( number < nC ) )
  {
    value = ubA[number];
    return SUCCESSFUL_RETURN;
  }
  else
    return THROWERROR( RET_INDEX_OUT_OF_BOUNDS );
}


/*
 *  g e t C o n s t r a i n t s
 */
inline returnValue QProblem::getConstraints( Constraints& _constraints ) const
{
  int nV = getNV( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  _constraints = *constraints;

  return SUCCESSFUL_RETURN;
}



/*
 *  g e t N C
 */
inline int QProblem::getNC( ) const
{
  if ( constraints != 0 )
    return constraints->getNC( );
  else
    return 0;
}


/*
 *  g e t N E C
 */
inline int QProblem::getNEC( ) const
{
  if ( constraints != 0 )
    return constraints->getNEC( );
  else
    return 0;
}


/*
 *  g e t N A C
 */
inline int QProblem::getNAC( ) const
{
  if ( constraints != 0 )
    return constraints->getNAC( );
  else
    return 0;
}


/*
 *  g e t N I A C
 */
inline int QProblem::getNIAC( ) const
{
  if ( constraints != 0 )
    return constraints->getNIAC( );
  else
    return 0;
}


/*
 *  g e t N D C
 */
inline int QProblem::getNDC( ) const
{
  if ( constraints != 0 )
    return constraints->getDisabled( )->getLength( );
  else
    return 0;
}



/*****************************************************************************
 *  P R O T E C T E D                                                        *
 *****************************************************************************/


/*
 *  s e t A
 */
inline returnValue QProblem::setA( const Real* const A_new )
{
  int i, j;
  int nV = getNV( );
  int nC = getNC( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  if ( A_new == 0 )
    return THROWERROR( RET_INVALID_ARGUMENTS );

  /* Set constraint matrix AND update member AX. */
  for( j=0; j<nC; ++j )
  {
    Ax_l[j] = 0.0;
    for( i=0; i<nV; ++i )
    {
      A[j*nV + i] = A_new[j*nV + i];
      Ax_l[j] += A[j*nV + i] * x[i];
    }
    Ax_u[j] = ubA[j] - Ax_l[j];
    Ax_l[j] = Ax_l[j] - lbA[j];
  }

  return SUCCESSFUL_RETURN;
}


/*
 *  s e t A
 */
inline returnValue QProblem::setA( int number, const Real* const row )
{
  int i;
  int nV = getNV( );
  int nC = getNC( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  /* Set constraint matrix AND update member AX. */
  if ( ( number >= 0 ) && ( number < nC ) )
  {
    Ax_l[number] = 0.0;
    for( i=0; i<nV; ++i )
    {
      A[number*nV + i] = row[i];
      Ax_l[number] += A[number*nV + i] * x[i];
    }
    Ax_u[number] = ubA[number] - Ax_l[number];
    Ax_l[number] = Ax_l[number] - lbA[number];

    return SUCCESSFUL_RETURN;
  }
  else
    return THROWERROR( RET_INDEX_OUT_OF_BOUNDS );
}


/*
 *  s e t L B A
 */
inline returnValue QProblem::setLBA( const Real* const lbA_new )
{
  int i;
  int nV = getNV( );
  int nC = getNC( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  if ( lbA_new == 0 )
    return THROWERROR( RET_INVALID_ARGUMENTS );

  for( i=0; i<nC; ++i )
    lbA[i] = lbA_new[i];

  return SUCCESSFUL_RETURN;
}


/*
 *  s e t L B A
 */
inline returnValue QProblem::setLBA( int number, Real value )
{
  int nV = getNV( );
  int nC = getNC( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  if ( ( number >= 0 ) && ( number < nC ) )
  {
    lbA[number] = value;
    return SUCCESSFUL_RETURN;
  }
  else
    return THROWERROR( RET_INDEX_OUT_OF_BOUNDS );
}


/*
 *  s e t U B A
 */
inline returnValue QProblem::setUBA( const Real* const ubA_new )
{
  int i;
  int nV = getNV( );
  int nC = getNC( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  if ( ubA_new == 0 )
    return THROWERROR( RET_INVALID_ARGUMENTS );

  for( i=0; i<nC; ++i )
    ubA[i] = ubA_new[i];

  return SUCCESSFUL_RETURN;
}


/*
 *  s e t U B A
 */
inline returnValue QProblem::setUBA( int number, Real value )
{
  int nV = getNV( );
  int nC = getNC( );

  if ( nV == 0 )
    return THROWERROR( RET_QPOBJECT_NOT_SETUP );

  if ( ( number >= 0 ) && ( number < nC ) )
  {
    ubA[number] = value;
    return SUCCESSFUL_RETURN;
  }
  else
    return THROWERROR( RET_INDEX_OUT_OF_BOUNDS );
}


#ifndef __DSPACE__
} /* qpOASES */
#endif


/*
 *  end of file
 */
