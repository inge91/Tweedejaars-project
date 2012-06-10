/**
* @author: Francony Bastien and Bertrand Decoster
*/


#pragma once
#ifndef _LIBALAUDIO_ALAUDIO_ALACOUSTICALSPACE_H_
#define _LIBALAUDIO_ALAUDIO_ALACOUSTICALSPACE_H_

#include <string>
#include <vector>

#include <almath/types/alposition3d.h>

/**
 * ALAcousticalSpace [ALL SPACE]
 * this class define acoustical space around Nao
 */
class ALAcousticalSpace
{
public:

  ///default constructor or destructor
  ALAcousticalSpace();
  ~ALAcousticalSpace();

  void getVertexMesh(std::vector<AL::Math::Position3D> &vector);
  void getVertexMeshCalibration(std::vector<AL::Math::Position3D> &vector);

private:
  void xInit();

  int fNbIteration;
  std::vector<AL::Math::Position3D> fVertexOctaedre;
  std::vector<AL::Math::Position3D> fVertexCalibration;
  std::vector<AL::Math::Position3D> fPlanOctaedre;
  float fDistancePlan;

  std::vector<AL::Math::Position3D> fMesh;
  std::vector<AL::Math::Position3D> fVertexMesh;
  std::vector<float> fMeshSurfaceInv;

  std::vector<float> fDot00;
  std::vector<float> fDot01;
  std::vector<float> fDot11;
  std::vector<float> fInvDenom;
};
#endif  // _LIBALAUDIO_ALAUDIO_ALACOUSTICALSPACE_H_

