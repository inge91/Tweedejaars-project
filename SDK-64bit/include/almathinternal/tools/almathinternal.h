/*
** Author(s):
**  - Chris Kilner
**  - Cyrille Collette
**  - David Gouaillier
**
** Copyright (C) 2011 Aldebaran Robotics
*/

#pragma once

#ifndef _LIB_ALMATHINTERNAL_ALMATHINTERNAL_ALMATHINTERNAL_H_
#define _LIB_ALMATHINTERNAL_ALMATHINTERNAL_ALMATHINTERNAL_H_

#include <almath/types/alposition2d.h>
#include <almath/types/alposition6d.h>
#include <almath/types/alvelocity6d.h>
#include <almath/types/alaxismask.h>
#include <almathinternal/types/alrotation2d.h>

namespace AL {
namespace Math {

/**
  * If you want to avoid too small numbers (<5.10^-29 if using float):
  * a = small_one;
  * a += killDeNormalNumber;
  * make_operations(a);
  * a -= killDeNormalNumber;
  * it will save a LOT of cpu (a multiplication with a denormal operand takes about 170 cycles !!!)
  *
  * for your information : denormal number = (FLOAT_MIN*2^32) = 5.0486911077.10^(-29)
  * the killDeNormalNumber const is chosen bigger than this denormal number
  *clipData
  * for more informations, see : www.musicdsp.org/files/denormal.pdf
  */
//#define killDeNormalNumber 1e-20f

Position2D operator*(
  const Rotation2D& pR,
  const Position2D& pPos);

/**
* inlineFactoriel: return the factoriel of the given number
* @param pNumber the factoriel you want to compute
**/
inline unsigned int inlineFactorial(unsigned int pNumber)
{
  return pNumber> 1 ? (pNumber * inlineFactorial(pNumber-1)) : 1;
}

/**
* Function to compute the gradiant of a line 2D defined by 2 points
* This function avoid division by zero
*
* @param pPointA the first point of the line
* @param pPointB the second point of the line
* @return the gradiant of the line 2D
*/
float computeGradiant(
  const Position2D& pPointA,
  const Position2D& pPointB);


/**
* Function to compute the offset of a line
* from a point of the line and the gradiant
* @param pPointA the first point of the line
* @param pGradiant the gradiant of the line
* @return the offset of the line 2D
*/
float computeOffset(
  const Position2D& pPointA,
  const float&      pGradiant);

/**
* Function to compute the offset of a line 2D defined by 2 points
*
* @param pPointA the first point of the line
* @param pPointB the second point of the line
* @return the offset of the line 2D
*/
float computeOffset(
  const Position2D& pPointA,
  const Position2D& pPointB);

/**
* Function Diff Log : cette fonction calcule la differentielle du
* logarithme associe a une matrice de type 'Deplacement - matrice homogene' 4x4 (SE3).
* @param pM   (Velocity6D) : displacement vector 6D
* @param pIn  (Velocity6D) : multiply 6*6 pM by pIn
* @param pOut (Velocity6D) : Output solution of DiffLog(pM)*pIn
**/
void diffLog(
  const Velocity6D& pM,
  const Velocity6D& pIn,
  Velocity6D&       pOut);

/**
* Function Inv Diff Log : Inverse de Diff Log
* @param pM   (Velocity6D) : displacement vector 6D
* @param pIn  (Velocity6D) : multiply 6*6 inverse pM by pIn
* @param pOut (Velocity6D) : Output solution of inverse(DiffLog(pM))*pIn
**/
void invDiffLog(
  const Velocity6D& pM,
  const Velocity6D& pIn,
  Velocity6D&       pOut);

/// <summary> Private Function to create a trapzeoidale. </summary>
/// <param name="pNumSamples">      number of samples to compute. </param>
/// <param name="pHeight">          Height of the Trapezoid ans Sign. </param>
/// <param name="pAttackFraction">  the NumSamples to use for the attack phase. </param>
/// <param name="pDecayFraction">   the NumSamples to use for the decay phase. </param>
/// <returns> The Trapezoid Function </returns>
std::vector<float> smoothTrapezoid(
  const unsigned int& pNumSamples,
  const float&        pHeight,
  const unsigned int& pAttack,
  const unsigned int& pDecay);

/**
* Returns 1.0f if the value is greater
* or equal to zero, otherwise returns -1.0f
*/
float sign(const float& pValue);

bool sign(
  const float& pValue1,
  const float& pValue2);

/**
    * Filter a vector of Position6D in order to move only the axis controlled by the axis mask
    * @return          : Vector of Position6D filter
    * @param pXi       : Vector of Position6D of the different stay point of the Interpolation
    * @param pAxisMask : Axis controlled during SE(3) interpolation
    */
void filterPosition6D(
  const std::vector<AL::Math::Position6D>& pXi,
  const AL::Math::AXIS_MASK                pAxisMask,
  std::vector<AL::Math::Position6D>&       pOut);

std::vector<AL::Math::Position6D>  filterPosition6D(
  const std::vector<AL::Math::Position6D>& pXi,
  const AL::Math::AXIS_MASK                pAxisMask);


void axisMaskToPosition6DOn(
  const AL::Math::Position6D& pXi,
  const AL::Math::AXIS_MASK   pAxisMask,
  AL::Math::Position6D&       pOut);

AL::Math::Position6D axisMaskToPosition6DOn(
  const AL::Math::Position6D& pXi,
  const AL::Math::AXIS_MASK   pAxisMask);

void axisMaskToPosition6DOff(
  const AL::Math::Position6D& pXi,
  const AL::Math::AXIS_MASK   pAxisMask,
  AL::Math::Position6D&       pPos);

AL::Math::Position6D axisMaskToPosition6DOff(
  const AL::Math::Position6D& pXi,
  const AL::Math::AXIS_MASK   pAxisMask);

void axisMaskToVelocity6DOn(
  const AL::Math::Velocity6D& pXi,
  const AL::Math::AXIS_MASK   pAxisMask,
  AL::Math::Velocity6D&       pOut);

AL::Math::Velocity6D axisMaskToVelocity6DOn(
  const AL::Math::Velocity6D& pXi,
  const AL::Math::AXIS_MASK   pAxisMask);

} // namespace Math
} // namespace AL
#endif  // _LIB_ALMATHINTERNAL_ALMATHINTERNAL_ALMATHINTERNAL_H_
