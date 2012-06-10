/*
** Author(s):
**  - Chris Kilner
**  - Cyrille Collette
**  - David Gouaillier
**
** Copyright (C) 2011 Aldebaran Robotics
*/


#pragma once
#ifndef _LIBALMATH_ALMATH_TYPES_ALPOSITIONANDVELOCITY_H_
#define _LIBALMATH_ALMATH_TYPES_ALPOSITIONANDVELOCITY_H_

namespace AL {
  namespace Math {

    /// <summary>
    /// Create and play with a PositionAndVelocity.
    ///
    /// A PositionAndVelocity is just defined by q and dq.
    /// </summary>
    /// \ingroup Types
    struct PositionAndVelocity
    {
      /// <summary> </summary>
      float q;
      /// <summary> </summary>
      float dq;

      /// <summary>
      /// Create a PositionAndVelocity initialize with explicit value.
      /**
       *
       * \f$ \left[\begin{array}{c}
       *         q \\
       *         dq
       *      \end{array}\right] =
       *      \left[\begin{array}{c}
       *         pq \\
       *         pdq
       *      \end{array}\right]\f$
       */
      /// </summary>
      /// <param name="pq"> the float value for q </param>
      /// <param name="pdq"> the float value for dq </param>
      PositionAndVelocity(
          const float pq = 0.0f,
          const float pdq = 0.0f);

      /// <summary>
      /// Check if the actual PositionAndVelocity is near the one
      /// give in argument.
      ///
      /// </summary>
      /// <param name="pDat2"> the second PositionAndVelocity </param>
      /// <param name="pEpsilon"> an optional epsilon distance (default = 0.0001f) </param>
      /// <returns>
      /// true if the difference of each float of the two PositionAndVelocity is less than pEpsilon
      /// </returns>
      bool isNear(
        const PositionAndVelocity& pDat2,
        const float&               pEpsilon=0.0001f) const;
    };

  }
}
#endif  // _LIBALMATH_ALMATH_TYPES_ALPOSITIONANDVELOCITY_H_
