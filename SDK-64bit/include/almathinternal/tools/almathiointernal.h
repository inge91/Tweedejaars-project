/*
** Author(s):
**  - Chris Kilner
**  - Cyrille Collette
**  - David Gouaillier
**
** Copyright (C) 2011 Aldebaran Robotics
*/

#pragma once

#ifndef _LIB_ALMATHINTERNAL_ALMATHINTERNAL_ALMATHIOINTERNAL_H_
#define _LIB_ALMATHINTERNAL_ALMATHINTERNAL_ALMATHIOINTERNAL_H_

#include <iostream>
#include <sstream>

#include <almathinternal/types/alrotation2d.h>

/// The purpose of grouping ostream operations in one place, is to speed
/// compilation times when not requiring output.
namespace AL {
namespace Math {

/// <summary>
/// overloading of operator << for Rotation2D
///
/// </summary>
/// <param name="pStream"> the given ostream </param>
/// <param name="pRot"> the given Rotation2D </param>
/// <returns>
/// the Rotation2D print
/// </returns>
/// \ingroup Types
std::ostream& operator<< (std::ostream& pStream, const Rotation2D& pRot);

}
}
#endif  // _LIB_ALMATHINTERNAL_ALMATHINTERNAL_ALMATHIOINTERNAL_H_
