/*
** Author(s):
**  - Chris Kilner
**  - Cyrille Collette
**  - David Gouaillier
**
** Copyright (C) 2011 Aldebaran Robotics
*/

#pragma once

#ifndef _LIB_ALMATHINTERNAL_ALMATHINTERNAL_ALLINECOLLISIONS_H_
#define _LIB_ALMATHINTERNAL_ALMATHINTERNAL_ALLINECOLLISIONS_H_

#include <almath/types/alposition3d.h>
#include <vector>


namespace AL
{
  namespace Math
  {
    /**
    * Function to compute the shortest distance between a point and a line segment
    * We use dot product to compute this distance
    *
    * @param pA the start point of the line segment
    * @param pB the end point of the line segment
    * @param pC an other point
    * @param pSolution the distance
    */
    void distancePointToLineSegment3D(
        const Position3D& pA,
        const Position3D& pB,
        const Position3D& pC,
        float&            pSolution);

    /**
    * Function to compute the shortest distance between a point and a line segment
    * We use dot product to compute this distance
    *
    * @param pA the start point of the line segment
    * @param pB the end point of the line segment
    * @param pC an other point
    * @param pSolution closest point of the line 3D to pC
    */
    void closestPointOfLineSegment3D(
      const Position3D& pA,
      const Position3D& pB,
      const Position3D& pC,
      Position3D&       pSolution);

    /**
    * Function to compute the shortest distance between two line segments
    *
    * @param pA const the start point of the first line segment
    * @param pB const the end point of the first line segment
    * @param pC const the start point of the second line segment
    * @param pD const the end point of the second line segment
    * @param pPtInAB the closest point in AB
    * @param pPtInCD the closest point in CD
    *
    * http://softsurfer.com/Archive/algorithm_0106/algorithm_0106.htm
    *  Copyright 2001 - 2006, softSurfer (www.softsurfer.com)
    *  This code may be freely used and modified for any purpose
    *  providing that this copyright notice is included with it.
    *  SoftSurfer makes no warranty for this code, and cannot be held
    *  liable for any real or imagined damage resulting from its use.
    *  Users of this code must verify correctness for their application.
    */
    void detectionBetweenTwoLineSegment3D(
      const Position3D& pA,
      const Position3D& pB,
      const Position3D& pC,
      const Position3D& pD,
      Position3D&       pPtInAB,
      Position3D&       pPtInCD);

  } // namespace Math

} // namespace AL

#endif  // _LIB_ALMATHINTERNAL_ALMATHINTERNAL_ALLINECOLLISIONS_H_
