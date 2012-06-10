/**
 * @author Aldebaran Robotics
 * Copyright (c) Aldebaran Robotics 2007, 2011 All Rights Reserved
 */

/** \file alvision/alvisionextractor.h
 *  \brief ALVisionExtractor
 */

/**
 * This class implements an extractor.
 * An extractor is a module which extracts
 * some information about the world.
 * It can be activated to produce information.
 */


#pragma once
#ifndef _LIBALVISION_ALVISION_ALVISIONEXTRACTOR_H_
#define _LIBALVISION_ALVISION_ALVISIONEXTRACTOR_H_

// Upstream opencv headers need this
#include <cstddef>

#include <alextractor/alextractor.h>
#include <alcommon/alproxy.h>
#include <alvision/alimage.h>

//opencv
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv/cvaux.h>

namespace AL
{

  class ALBroker;
  class ALMutex;
  class ALVideoDeviceProxy;
  class ALVisionExtractor: public ALExtractor
  {

  public :
    /**
     * Constructor
     * @param pBroker Module broker pointer
     * @param pName Module name
     */
    ALVisionExtractor(boost::shared_ptr<ALBroker> pBroker, const std::string& pName );


    /**
     * Destructor.
     */
    virtual ~ALVisionExtractor();

    /**
     * init Module initialization method
     */
    void init(void);

    /**
     * run  Main loop
     */
    void run();


    /**
     * initVision  Vision specific initialization
     */
    virtual void initVision(){};

    /**
     * process  user process method called from main loop acquisition
     */
    virtual void process(IplImage*) = 0;


    /**
     * getOutputNames  get extractor raised event name list
     * @return list of name
     */
    virtual std::vector<std::string> getOutputNames( );

    /**
     * @brief Allows setting BallDetection parameters
     * @param paramName, String name of the parameter to be set
     * @param paramValue, ALValue containing the parameter value
     */
    void setParam(const std::string &paramName, const ALValue &paramValue);


    /**
     * @brief Initialisation of several non-generic things
     */
    void xInitGenericStuff();

    /**
     * @brief Release of several non-generic things
     */
    void xReleaseGenericStuff();


    /**
     * @brief Initialisation of several non-generic things
     */
    void xInitSpecificStuff();

    /**
     * @brief Release of several non-generic things
     */
    void xReleaseSpecificStuff();



  protected:
    /**
     * xStartDetection. What the extractor shall do to start detection
     * this method is called only once : when the first module subscribes.
     */
    virtual void xStartDetection( const int pPeriod , const float pPrecision  );

    /**
     * xUpdateParam.
     * updates fCurrentParameters from fSubscribedList.
     * this method is called each time the parameters has changed
     * because of a new subscribtion or unsubscribtion or
     * when a module calls updatePeriod or updatePrecision.
     */
    virtual void xUpdateParameters( const int pPeriod , const float pPrecision  );

    /**
     * xStopDetection.
     * Stop detection
     */
    void xStopDetection(  );

  protected:
    boost::shared_ptr<AL::ALVideoDeviceProxy> xCamProxy;
    boost::shared_ptr<AL::ALProxy> xCamGenericProxy;
    std::string xGvmName;
    int xMode;
    int xResolution;
    int xColorSpace;
    int xImageWidth;
    int xImageHeight;
    int xImageNLayers;
    int xCurrentPeriod;
    int xPause;
    bool xRunOrder;
    bool xIsRunning;
    ALImage* xptr_ALImageRaw;
    IplImage* xptr_IplImageRaw;
    std::string xIplImageRawName;

  private:
    const boost::shared_ptr<ALMutex> xMyMutex;
  };


} // namespace AL



#endif  // _LIBALVISION_ALVISION_ALVISIONEXTRACTOR_H_

