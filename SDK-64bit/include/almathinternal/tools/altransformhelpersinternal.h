/*
** Author(s):
**  - Chris Kilner
**  - Cyrille Collette
**  - David Gouaillier
**
** Copyright (C) 2011 Aldebaran Robotics
*/

#pragma once

#ifndef _LIB_ALMATHINTERNAL_ALMATHINTERNAL_ALTRANSFORMHELPERSINTERNAL_H_
#define _LIB_ALMATHINTERNAL_ALMATHINTERNAL_ALTRANSFORMHELPERSINTERNAL_H_

#include <almathinternal/types/alrotation2d.h>
#include <almath/types/altransform.h>
#include <almath/types/alposition3d.h>
#include <almath/types/alaxismask.h>

namespace AL {
  namespace Math {

    Rotation2D rotation2DFromTransformZ(const Transform& pH);

    // OK
    void axisRotationToTransform(
        const Position3D& pAxisRotation,
        const float&      Ca,
        const float&      Sa,
        Transform&        pHOut);

    void diffAxisToAntiSynmetric(
        const Position3D& pA,
        const Position3D& pB,
        Transform&        HOut);

    bool findRotationBest(
        const Position3D& pAxisInit,
        const Position3D& pAxisFinal,
        Transform&        pHOut);

    void findRotation(
        const Position3D& pAxisInit,
        const Position3D& pAxisFinal,
        Transform&        pHOut);


    std::vector<Transform> filterTransform(
      const std::vector<Transform>& pHi,
      const AXIS_MASK               pAxisMask);

    Transform axisMaskToTransformOn(
      const Transform& pHi,
      const AXIS_MASK  pAxisMask);

    void computeMixTransformWithAxisMask(
      const Transform& pDesired,
      const Transform& pReference,
      const AXIS_MASK& pAxisMask,
      Transform&       pResult);

  } // namespace Math
} // namespace AL
#endif  // _LIB_ALMATHINTERNAL_ALMATHINTERNAL_ALTRANSFORMHELPERSINTERNAL_H_
