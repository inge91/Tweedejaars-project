/*
** Author(s):
**  - Chris Kilner
**  - Cyrille Collette
**  - David Gouaillier
**
** Copyright (C) 2011 Aldebaran Robotics
** code from http://marknelson.us/2007/08/22/convex/
*/

#pragma once

#ifndef _LIB_ALMATHINTERNAL_ALMATHINTERNAL_CONVEXHULL_GRAHAM_H_
#define _LIB_ALMATHINTERNAL_ALMATHINTERNAL_CONVEXHULL_GRAHAM_H_

#include <almath/types/alposition2d.h>
#include <vector>

namespace AL
{
  namespace Math
  {
    std::vector<AL::Math::Position2D> getConvexHullGraham(
      const std::vector<AL::Math::Position2D>& pPoints);

    bool sortFunction(
      AL::Math::Position2D p0,
      AL::Math::Position2D p1);

    void xPartitionPoints(
      std::vector<AL::Math::Position2D>&  pPoints,
      std::vector<AL::Math::Position2D>&  pUpperPartitionPoints,
      std::vector<AL::Math::Position2D>&  pLowerPartitionPoints,
      AL::Math::Position2D&               pLeft,
      AL::Math::Position2D&               pRight);

    float xDirection(
      const AL::Math::Position2D& p0,
      const AL::Math::Position2D& p1,
      const AL::Math::Position2D& p2);

    void xGetHalfConvexHull(
      std::vector<AL::Math::Position2D>   pInputs,
      std::vector<AL::Math::Position2D>&  pOutputs,
      const float&                        pfactor,
      const AL::Math::Position2D&         pLeft,
      const AL::Math::Position2D&         pRight);
  } // namespace Math
} // namespace AL

#endif  // _LIB_ALMATHINTERNAL_ALMATHINTERNAL_CONVEXHULL_GRAHAM_H_

