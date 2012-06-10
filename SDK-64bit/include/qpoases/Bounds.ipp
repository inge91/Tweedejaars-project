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
 *  \file SRC/Bounds.ipp
 *  \author Hans Joachim Ferreau
 *  \version 2.0
 *  \date 2007-2009
 *
 *  Implementation of inlined member functions of the Bounds class designed
 *  to manage working sets of bounds within a QProblem.
 */


#ifndef __DSPACE__
namespace qpOASES
{
#endif

/*****************************************************************************
 *  P U B L I C                                                              *
 *****************************************************************************/

/*
 *  g e t N V
 */
inline int Bounds::getNV( ) const
{
   return n;
}


/*
 *  g e t N F V
 */
inline int Bounds::getNFV( ) const
{
   return getNumberOfType( ST_EQUALITY );
}


/*
 *  g e t N B V
 */
inline int Bounds::getNBV( ) const
{
   return getNumberOfType( ST_BOUNDED );
}


/*
 *  g e t N U V
 */
inline int Bounds::getNUV( ) const
{
  return getNumberOfType( ST_UNBOUNDED );
}


/*
 *  g e t N F R
 */
inline int Bounds::getNFR( ) const
{
  if ( freee != 0 )
     return freee->getLength( );
  else
    return 0;
}


/*
 *  g e t N F X
 */
inline int Bounds::getNFX( ) const
{
  if ( fixed != 0 )
     return fixed->getLength( );
  else
    return 0;
}


/*
 *  g e t F r e e
 */
inline Indexlist* Bounds::getFree( ) const
{
  return freee;
}


/*
 *  g e t F i x e d
 */
inline Indexlist* Bounds::getFixed( ) const
{
  return fixed;
}


#ifndef __DSPACE__
} /* qpOASES */
#endif


/*
 *  end of file
 */
