/**
 * @author Pierre-Emmanuel VIEL
 * Copyright (c) Aldebaran Robotics 2008, 2011 All Rights Reserved
 */

#pragma once
#ifndef _LIBALVISION_ALVISION_ALVISIONDEFINITIONS_H_
#define _LIBALVISION_ALVISION_ALVISIONDEFINITIONS_H_

/** \file alvision/alvisiondefinitions.h
 *  \brief vision defines
 */

namespace AL
{
  #define TORAD  3.14f/180.0f

  /**
  *Camera ID
  */
  const int kOV7670  = 1;
  const int kMT9M114 = 2;

  /**
  *Cameras aperture
  */
  const float kApertureH_OV7670  = 47.8f;
  const float kApertureV_OV7670  = 36.8f;
  const float kApertureH_MT9M114 = 60.9f;
  const float kApertureV_MT9M114 = 47.6f;

  /**
  *Format of the image
  */
  const int k960p  = 3;  //1280*960
  const int k4VGA  = 3;  //1280*960
  const int kVGA   = 2;  // 640*480
  const int kQVGA  = 1;  // 320*240
  const int kQQVGA = 0;  // 160*120

  /**
  *ColorSpace
  */
  const int kYuvColorSpace = 0;
  const int kyUvColorSpace = 1;
  const int kyuVColorSpace = 2;
  const int kRgbColorSpace = 3;
  const int krGbColorSpace = 4;
  const int krgBColorSpace = 5;
  const int kHsyColorSpace = 6;
  const int khSyColorSpace = 7;
  const int khsYColorSpace = 8;
  const int kYUV422InterlacedColorSpace = 9; // deprecated
  const int kYUV422ColorSpace = 9;
  const int kYUVColorSpace = 10;
  const int kRGBColorSpace = 11;
  const int kHSYColorSpace = 12;
  const int kBGRColorSpace = 13;     // for opencv ease of use
  const int kYYCbCrColorSpace = 14;  // for tiff io implementation
  const int kH2RGBColorSpace = 15;   // H from HSY to RGB in fake colors
  const int kHSMixedColorSpace = 16; // HS and (H +S)/2

  /**
   *Standard Id (used for camera registers configuration)
   */
  const int kCameraBrightnessID       = 0;
  const int kCameraContrastID         = 1;
  const int kCameraSaturationID       = 2;
  const int kCameraHueID              = 3;
  const int kCameraRedChromaID        = 4;
  const int kCameraBlueChromaID       = 5;
  const int kCameraGainID             = 6;
  const int kCameraHFlipID            = 7;
  const int kCameraVFlipID            = 8;
  const int kCameraLensXID            = 9;
  const int kCameraLensYID            = 10;
  const int kCameraAutoExpositionID   = 11;
  const int kCameraAutoWhiteBalanceID = 12;
  const int kCameraAutoGainID         = 13;
  const int kCameraResolutionID       = 14;
  const int kCameraFrameRateID        = 15;
  const int kCameraBufferSizeID       = 16;
  const int kCameraExposureID         = 17;
  const int kCameraSelectID           = 18;
  const int kCameraSetDefaultParamsID = 19;
  const int kCameraColorSpaceID       = 20;
  const int kCameraExposureCorrectionID = 21;
  const int kCameraAecAlgorithmID     = 22;
  const int kCameraFastSwitchID       = 23;
  const int kCameraSharpnessID        = 24;
  const int kCameraAwbGreenGainID     = 25;
  const int kCameraAblcID             = 26;
  const int kCameraAblcTargetID       = 27;
  const int kCameraAblcStableRangeID  = 28;
  const int kCameraBlcBlueID          = 29;
  const int kCameraBlcRedID           = 30;
  const int kCameraBlcGbID            = 31;
  const int kCameraBlcGrID            = 32;
  const int kCameraWhiteBalanceID     = 33;
  const int kCameraBacklightCompensationID = 34;

  bool isResolutionValid(const int resIndex);
  void setSizeFromResolution(const int resIndex, int& outWidth, int& outHeight);
  int getResolutionFromSize(const int width, const int height);
  bool isColorSpaceValid(const int colorspace);
  int getNumLayersInColorSpace(const int colorSpace);
  inline float convertAngleValToNormalizedImgVal(const float& radValue,
                                                 const float& imageRadMin,
                                                 const float& imageRadMax)
    { return ( radValue / (imageRadMax-imageRadMin)); };

  inline float convertAnglePosToNormalizedImgPos(const float& radPosition,
                                                 const float& imageRadMin,
                                                 const float& imageRadMax)
    { return ((radPosition-imageRadMin) / (imageRadMax-imageRadMin)); };
} // namespace AL


#endif  // _LIBALVISION_ALVISION_ALVISIONDEFINITIONS_H_
