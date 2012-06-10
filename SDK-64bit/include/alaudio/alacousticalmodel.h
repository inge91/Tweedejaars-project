/**
* @author: Francony Bastien and Bertrand Decoster
*/


#pragma once
#ifndef _LIBALAUDIO_ALAUDIO_ALACOUSTICALMODEL_H_
#define _LIBALAUDIO_ALAUDIO_ALACOUSTICALMODEL_H_

#include <string>
#include <vector>
#include <alaudio/alacousticalspace.h>

/**
* ALAcousticalModel
* this class transform audio ITD data in angle of a sound source
* it is very important to keep an inversible model [ ITD <-> angle ]
*/
namespace AL
{
  class ALAcousticalModel : public ALAcousticalSpace
  {
  public:

    /// default constructor or destructor
    ALAcousticalModel(unsigned int nbMicrophones,
                      std::vector<Math::Position3D> microsPosition);
    ~ALAcousticalModel(){}

    /// compute angle of a sound source
    std::vector<float> computeAngle(const std::vector<int> itdValues, const std::string mod);

    /// getITDmax left/right
    void getITDmaxLR(int &ITD);

    /// getITDmax front/rear
    void getITDmaxFR(int &ITD);

    /// getITDmax model 6 microphones
    void getITDmaxV6(std::vector<int> &ITD);

    std::vector<float> forwardITD(const std::vector<int> &pITDValues, float &proba) const;

    /// getITDMatrix
    void getITDMatrix(std::vector< std::vector<int> > &vector) const;
    void getITDMatrixCalibration(std::vector< std::vector<int> > &vector) const;
    void getSoundSpeed(float & pSoundSpeed) const;
    void getSampleRate(float & pSampleRate) const;
    void getMicrosPosition(std::vector<Math::Position3D> & pMicrosPosition) const;
    float forwardITDUpdateValues(const std::vector<float> &ITDValuesOrig,std::vector<float> &ITDValues);
    void backwardITD(Math::Position3D pos, std::vector<int> &itdValues);

  private:

    /// is computation running
    bool fIsRunning;

    /// xAzimutalModel [only right/left]
    std::vector<float> xAzimutalModel(const std::vector<int> itdValues);
    /// xAzimutalModel [right/left + front/rear]
    std::vector<float> xAzimutalModelFR(const std::vector<int> itdValues);

    /// global model
    ///--- forward
    void xForwardITDInit();

    float xForwardITDUpdateValues(const std::vector<float>                                &ITDValuesOrig,
                                  std::vector<float>                                      &ITDValues,
                                  const std::vector< std::vector<float> >                 &ITDProjectionMatrix,
                                  const std::vector< std::vector<float> >                 &ITDProjectionMatrix2,
                                  const std::vector< std::vector< std::vector<float> > >  &ITDProjectionMatrixMini) const;

    Math::Position3D xForwardITDComputePosition(const std::vector<float>                &ITDValues,
                                                const std::vector<float>                &DistanceCouplesMicros,
                                                const std::vector<Math::Position3D> &DirectionsCouplesMicros,
                                                const std::vector<float>                &AnglesPaireDirection,
                                                const std::vector<Math::Position3D> &VecteurPlanPaireDirection,
                                                const std::vector<Math::Position3D> &VecteurOrthoPaireDirection) const;

    std::vector<float> xForwardITDComputeAngles(const Math::Position3D pPositionProbable) const;

    ///--- backward
    void xBackwardITD(Math::Position3D pos, std::vector<int> &itdValues);
    std::vector< std::vector<int> > fITDMatrix;
    std::vector< std::vector<int> > fITDMatrixCalib;
    std::vector<Math::Position3D> fMeshGridCalib;
    std::vector<Math::Position3D> fMeshGrid;

    /// model geo
    //std::vector<Math::Position3D> fMicrosPosition;
    //Math::Position3D fCenterPosition;
    std::vector<Math::Position3D> fDirectionsCouplesMicros;
    std::vector<float> fDistanceCouplesMicros;
    std::vector<float> fAnglesPaireDirection;
    std::vector<Math::Position3D> fVecteurPlanPaireDirection;
    std::vector<Math::Position3D> fVecteurOrthoPaireDirection;

    /// coherence
    // Projection orthogonale R6 dans R3 optimisee distance
    std::vector< std::vector<float> > fITDProjectionMatrix;
    // Projection "semi-orthogonale" R3 dans R3 empirique
    std::vector< std::vector<float> > fITDProjectionMatrix2;
    // Projection de R3 dans R1
    std::vector< std::vector< std::vector<float> > > fITDProjectionMatrixMini;

    /// minimum of ITD right/left
    const int fITDmaxRL;

    /// minimum of ITD front/rear
    const int fITDmaxFR;

    /// sample rate
    const float fSampleRate;

    /// distance between microphones
    const float fDistance;

    /// sound speed
    const float fSoundSpeed;

    /// model with 6 microphones
    std::vector<int> fITDmaxV6;

    unsigned int fNbMicrophones;
    unsigned int fNbCouplesMicros;
    unsigned int fNbPaireDirections;
    std::vector<Math::Position3D> fMicrosPosition;
  };
}
#endif  // _LIBALAUDIO_ALAUDIO_ALACOUSTICALMODEL_H_
