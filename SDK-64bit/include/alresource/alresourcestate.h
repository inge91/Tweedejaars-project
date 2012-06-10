/**
* @author Aldebaran-Robotics.
* Aldebaran Robotics (c) 2007 All Rights Reserved
* Aldebaran Robotics (c) 2007 All Rights Reserved - This file is confidential.\n
*
* Version : $Id$
*/

#pragma once

#ifndef _LIB_ALRESOURCE_ALRESOURCE_ALRESOURCESTATE_H_
#define _LIB_ALRESOURCE_ALRESOURCE_ALRESOURCESTATE_H_

#include "alresource.h"
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <alresource/alowner.h>
#include <alresource/alownerweak.h>
#include <alresource/alownerstrong.h>
#include <althread/almutex.h>

namespace AL
{

  class ALResourceList;


  /**
  * The ALResource is a physical or logical resource
  * It is defined by a unique name and a parent
  */
  class ALResourceState: public ALResource
  {
  public:

    /**
    * Constructor
    * @param unique resource name
    * @param pointer on parent (or NULL)
    */
    ALResourceState(const std::string &pName, boost::shared_ptr<ALResource> pParent);
    ALResourceState(){};

    /**
    * virtual destructor 
    */
    virtual ~ALResourceState() {};

   
    bool isResourceFree();

    /**
    * waitFor. Wait a resource
    * @param pOwner owner that want resource
    * @param pCallbackName notification callback if someone want the resource
    * @param nTimeOutMillisec timeout we wait resource. -1 = no timeout
    */
    virtual void waitFor(boost::shared_ptr<ALOwner> pOwner, const std::string &pCallbackName, int nTimeOutMillisec);

    /**
    * release. Owner release a resource
    * @param pOwner owner that release the resource
    */
    virtual void release(boost::shared_ptr<ALOwner> pOwner);

    /**
    * httpGet. Return string for http get with resource name and owner name
    * @param level recursive level
    */
    virtual std::string httpGet(int level = 0);

    void releaseState();

    void setState(bool pState);
  protected:
    
    bool bStateActivated;

    std::vector< boost::shared_ptr<ALOwner> > fOwnerList;

    /*
    * Owner used to stop in waitfor if state not free
    */
    boost::shared_ptr<ALOwner> fStuckOwner;



    // cannot release and wait release in the same time
    /*
    * Owner manipulation protection
    */
    boost::shared_ptr<ALMutex> fOwnerListMutex;

    boost::shared_ptr<ALMutex> fStateMutex;


  };

}
#endif // RESOURCESTATE_H
