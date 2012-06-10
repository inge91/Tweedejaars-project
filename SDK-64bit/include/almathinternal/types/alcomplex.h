/*
** Author(s):
**  - Chris Kilner
**  - Cyrille Collette
**  - David Gouaillier
**
** Copyright (C) 2011 Aldebaran Robotics
*/

#pragma once

#ifndef _LIB_ALMATHINTERNAL_ALMATHINTERNAL_ALCOMPLEX_H_
#define _LIB_ALMATHINTERNAL_ALMATHINTERNAL_ALCOMPLEX_H_

#include <vector>

namespace AL {
namespace Math {

struct Complex
{
      float re;
      float im;

      Complex(
          const float pRe = 0.0f,
          const float pIm = 0.0f):
          re(pRe),
          im(pIm) {};

  bool isNear(
    const Complex& pCom,
    const float&   pEpsilon=0.0001f) const;
};

}
}
#endif  // _LIB_ALMATHINTERNAL_ALMATHINTERNAL_ALCOMPLEX_H_
