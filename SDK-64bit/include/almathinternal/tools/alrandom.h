/*
** Author(s):
**  - Chris Kilner
**  - Cyrille Collette
**  - David Gouaillier
**
** Copyright (C) 2011 Aldebaran Robotics
*/

#pragma once

#ifndef _LIB_ALMATHINTERNAL_ALMATHINTERNAL_ALRANDOM_H_
#define _LIB_ALMATHINTERNAL_ALMATHINTERNAL_ALRANDOM_H_

#include <time.h>
#include <almathinternal/tools/altrigonometryinternal.h>
#include <almathinternal/tools/mersennetwister.h>

namespace AL {
  namespace Math {


  /**
   * initRandom: init the seed of the random
   * DON'T FORGET TO CALL THE INIT BEFORE USING RAND
   **/
  inline void initRandom()
  {
    mersennetwister::init_genrand((unsigned long) time(NULL));
  }

  /**
   * inlineRand: return a random between fLowerBound and fHigherBound
   * @param fLowerBound the lower bound of the random number you want
   * @param fHigherBound the higher bound of the random number you want
   **/

  inline float inlineRand(float pLowerBound, float pHigherBound)
  {
    return pLowerBound + (pHigherBound-pLowerBound)*((float)mersennetwister::genrand_real1());
  }

  /**
   * inlineRand: return a random integer between fLowerBound and fHigherBound
   * @param fLowerBound the lower bound of the random number you want
   * @param fHigherBound the higher bound of the random number you want
   **/
  inline unsigned int inlineRand(int pLowerBound, int pHigherBound)
  {
    return pLowerBound + ((unsigned int) mersennetwister::genrand_int32()) % ( pHigherBound - pLowerBound  +1 );
  }

  /**
   * inlineRandGauss: random gaussian generation
   * @param mu mean of the distribution
   * @param sigma standard deviation
   **/
  inline float inlineRandGauss(float pMu, float pSigma)
  {
    return (pMu+pSigma*(
              sqrtf(-2.0f*logf((float)mersennetwister::genrand_real1()))*
              AL::Math::inlineCos(_2_PI_*(float)mersennetwister::genrand_real1())));
  }



  }
}
#endif  // _LIB_ALMATHINTERNAL_ALMATHINTERNAL_ALRANDOM_H_
