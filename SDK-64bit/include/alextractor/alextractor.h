/**
 * @author Aldebaran Robotics
 * Copyright (c) Aldebaran Robotics 2007, 2011 All Rights Reserved
 */

/** @file
 *  @brief
 */

#pragma once
#ifndef _LIBALEXTRACTOR_ALEXTRACTOR_ALEXTRACTOR_H_
#define _LIBALEXTRACTOR_ALEXTRACTOR_ALEXTRACTOR_H_

# include <alcommon/almodule.h>
# include <alextractor/config.h>

# include <boost/scoped_ptr.hpp>

namespace AL
{
  class ALBroker;
  class ALExtractorPrivate;

  /**
   * \class ALExtractor alextractor.h "alextractor/alextractor.h"
   * \brief ALExtractor class implements an extractor.
   *
   * An extractor is a module which extracts some information
   * about the world. It can be activated to produce information.
   * \ingroup libalextractor
   */
  class ALEXTRACTOR_API ALExtractor: public ALModule
  {
  public:
    /**
     * \brief Constructor.
     *
     *        Create a extractor link to a broker.
     * \param pBroker pointer to the broker
     * \param pName name of the extractor
     */
    ALExtractor(boost::shared_ptr<ALBroker> pBroker,
                const std::string& pName);

    /** \brief Destructor. */
    virtual ~ALExtractor();

    /**
     * \brief Called by the "client" to tell that
     *        it is interested in the output values.
     * \param pSubscribedName Name of the client module
     * \param pPeriod period of the extractor
     * \param pPrecision precision of the extractor
     */
    virtual void subscribe(const std::string &pSubscribedName,
                           const int &pPeriod,
                           const float &pPrecision);

    /**
     * \brief Called by the "client" to tell that
     *        it is interested in the output values.
     * \param pSubscribedName Name of the client module
     */
    void subscribe(const std::string &pSubscribedName);


    /**
     * \brief Called by the "client" to update the periode.
     * \param pSubscribedName Name of the client module
     * \param pPeriod period of the extractor
     */
    virtual void updatePeriod(const std::string &pSubscribedName,
                              const int &pPeriod);

    /**
     * \brief Called by the "client" to update the precision.
     * \param pSubscribedName Name of the client module
     * \param pPrecision precision of the extractor
     */
    virtual void updatePrecision(const std::string &pSubscribedName,
                                 const float &pPrecision);

    /**
     * \brief Called by the "client" to tell that
     *        it is not interested anymore in the output values.
     * \param pSubscribedName Name of the client module
     */
    virtual void unsubscribe(const std::string &pSubscribedName);

    /**
     * \brief Called by the "client" to get the
     *        current period chosen by the Extractor.
     * \return current period
     */
    virtual int getCurrentPeriod();

    /**
     * \brief Called by the "client" to get the
     *        current precision chosen by the Extractor.
     * \return current precision
     */
    virtual float getCurrentPrecision();

    /**
     * \brief Called by the "client" to get the period.
     * \param pSubscribedName Name of the client module
     * \return period I required
     */
    virtual int getMyPeriod(const std::string &pSubscribedName);

    /**
     * \brief Called by the "client" to get the precision.
     * \param pSubscribedName Name of the client module
     * \return precision I required
     */
    virtual float getMyPrecision(const std::string &pSubscribedName);

    /**
     * \brief Called by the "client" to get the
     *        information of all the current subscribers.
     * \return info, names and parameters of all subscribers
     */
    ALValue getSubscribersInfo();

    /**
     * \brief Called by the broker webpage to detail the module.
     * \return an optional extra description of the module
     */
    virtual std::string httpGet();

  protected:

    /**
     * \brief What the extractor shall do to start detection.
     *
     *
     * This method is called only once: when the first module subscribes.
     * \param pPeriod period of the extractor
     * \param pPrecision precision of the extractor
     */
    virtual void xStartDetection(const int pPeriod,
                                 const float pPrecision) = 0;

    /**
     * \brief updates fCurrentParameters from fSubscribedList.
     *
     * This method is called each time the parameters has changed
     * because of a new subscribtion or unsubscription or
     * when a module calls updatePeriod or updatePrecision.
     * \param pPeriod period of the extractor
     * \param pPrecision precision of the extractor
     */
    virtual void xUpdateParameters(const int pPeriod, const float pPrecision);

    /**
     * \brief What the extractor shall do to stop detection.
     *
     * this method is called only once: when the last module unsubscribes.
     */
    virtual void xStopDetection() = 0;

    /**
     * \brief Which values this extractor updates in ALMemory.
     * \return vector of modified value
     */
    std::vector<std::string> getOutputNames(void);

  private:
    /** Pointer to ALExtractor private implementation */
    boost::scoped_ptr<ALExtractorPrivate> _private;
    /**
     * \brief updates fCurrentParameters from fSubscribedList.
     */
    void xUpdateParameters();
  };
} // namespace AL

#endif  // _LIBALEXTRACTOR_ALEXTRACTOR_ALEXTRACTOR_H_

