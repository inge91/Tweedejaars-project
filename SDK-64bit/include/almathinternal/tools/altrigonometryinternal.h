/*
** Author(s):
**  - Chris Kilner
**  - Cyrille Collette
**  - David Gouaillier
**
** Copyright (C) 2011 Aldebaran Robotics
*/


#pragma once

#ifndef _LIB_ALMATHINTERNAL_ALMATHINTERNAL_ALTRIGONOMETRYINTERNAL_H_
#define _LIB_ALMATHINTERNAL_ALMATHINTERNAL_ALTRIGONOMETRYINTERNAL_H_

#include <cmath>
#include <almath/tools/altrigonometry.h>


namespace AL {
  namespace Math {

    /****************************************************
    *****************************************************
    * *     COS, SIN, ACOS, ASIN LOOKUP TABLES :      * *
    *****************************************************
    ****************************************************/
    static const int inlineCosSinArraySize = 16384; // gives an approximation at 4.10-4 rad
    static const int inlineACosASinArraySize = 16384;

    extern float inlineCosArray[inlineCosSinArraySize];
    extern float inlineSinArray[inlineCosSinArraySize];
    extern float inlineACosArray[inlineACosASinArraySize];
    extern float inlineASinArray[inlineACosASinArraySize];

    static const float freqForInlineCosSin = (float)inlineCosSinArraySize / (_2_PI_ );
    static const float stepForInlineCosSin = _2_PI_ / (float)inlineCosSinArraySize;

    static const float freqForInlineACosASin = (float)inlineACosASinArraySize / (2.0f);
    static const float stepForInlineACosASin = (2.0f) / (float)inlineACosASinArraySize;

    extern bool inlineCosSinInitialized;
    extern bool inlineACosASinInitialized;

    /*
    * initialize the tables
    */
    void initInlineCosSin();
    void initInlineACosASin();

    /*
    * return cos(n) in rad
    */
    float inlineCos(float n);

    /*
    * return sin(n) in rad
    */
    float inlineSin(float n);

    /*
    * return ArcCos(n) if -1 <= n <= 1
    * return value between 0 and PI
    */
    float inlineACos(float n);

    /*
    * return ArcSin(n) if -1 <= n <= 1
    * return value between -PI_2 and +PI_2
    */
    float inlineASin(float n);

  }
}
#endif  // _LIB_ALMATHINTERNAL_ALMATHINTERNAL_ALTRIGONOMETRYINTERNAL_H_
