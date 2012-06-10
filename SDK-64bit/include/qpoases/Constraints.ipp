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
 *  \file SRC/Constraints.ipp
 *  \author Hans Joachim Ferreau
 *  \version 2.0
 *  \date 2007-2009
 *
 *  Declaration of inlined member functions of the Constraints class designed
 *  to manage working sets of constraints within a QProblem.
 */


#ifndef __DSPACE__
namespace qpOASES
{
#endif

/*****************************************************************************
 *  P U B L I C                                                              *
 *****************************************************************************/


/*
 *  g e t N C
 */
inline int Constraints::getNC( ) const
{
   return n;
}


/*
 *  g e t N E C
 */
inline int Constraints::getNEC( ) const
{
  return getNumberOfType( ST_EQUALITY );
}


/*
 *  g e t N I C
 */
inline int Constraints::getNIC( ) const
{
   return getNumberOfType( ST_BOUNDED );
}


/*
 *  g e t N U C
 */
inline int Constraints::getNUC( ) const
{
   return getNumberOfType( ST_UNBOUNDED );
}


/*
 *  g e t N A C
 */
inline int Constraints::getNAC( ) const
{
  if ( active != 0 )
     return active->getLength( );
  else
    return 0;
}


/*
 *  g e t N I A C
 */
inline int Constraints::getNIAC( ) const
{
   if ( inactive != 0 )
     return inactive->getLength( );
  else
    return 0;
}


/*
 *  g e t N D C
 */
inline int Constraints::getNDC( ) const
{
   if ( disabled != 0 )
     return disabled->getLength( );
  else
    return 0;
}


/*
 *  g e t A c t i v e
 */
inline Indexlist* Constraints::getActive( ) const
{
  return active;
}


/*
 *  g e t I n a c t i v e
 */
inline Indexlist* Constraints::getInactive( ) const
{
  return inactive;
}


/*
 *  g e t D i s a b l e d
 */
inline Indexlist* Constraints::getDisabled( ) const
{
  return disabled;
}



/*
 *  i s D i s a b l e d
 */
inline BooleanType Constraints::isDisabled( int number ) const
{
  if ( ( getStatus( number ) == ST_DISABLED ) || ( getStatus( number ) == ST_DISABLING ) )
    return BT_TRUE;
  else
    return BT_FALSE;
}


/*
 *  i s E n a b l e d
 */
inline BooleanType Constraints::isEnabled( int number ) const
{
  if ( isDisabled( number ) == BT_FALSE )
    return BT_TRUE;
  else
    return BT_FALSE;
}


#ifndef __DSPACE__
} /* qpOASES */
#endif


/*
 *  end of file
 */
