/**
* @author Aldebaran-robotics
* Aldebaran Robotics (c) 2007 All Rights Reserved
*/

#pragma once

#ifndef _LIB_ALRESOURCE_ALRESOURCE_ALRESOURCELIST_H_
#define _LIB_ALRESOURCE_ALRESOURCE_ALRESOURCELIST_H_


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

  /**
  * The ALResourceList is list of ALResource
  */
  class ALResourceList: public ALResource
  {
  public:

    /**
    * Constructor
    * @param unique resource name
    * @param pointer on parent (or NULL)
    */
    ALResourceList(const std::string &pName, boost::shared_ptr<ALResource> pParent);

    /**
    * waitFor. Wait a resource
    * @param pOwner owner that want resource
    * @param pCallbackName notification callback if someone want the resource
    * @param nTimeOutMillisec timeout we wait resource. -1 = no timeout
    */
    void waitFor(boost::shared_ptr<ALOwner> pOwner, const std::string &pCallbackName, int nTimeOutMillisec);

    /**
    * switchOwner. Switch owner without conflict (for exemple for parent/children)
    * @param pOwner owner that want resource
    * @param pCallbackName notification callback if someone want the resource
    * @param nTimeOutMillisec timeout we wait resource. -1 = no timeout
    */
    void switchOwner(boost::shared_ptr<ALOwner> pOwner, const std::string &pCallbackName, int nTimeOutMillisec);

    /**
    * release. Owner release a resource
    * @param pOwner owner that release the resource
    */
    void release(boost::shared_ptr<ALOwner> pOwner);

    /**
    * addResource: Add a resource in a resource
    * @param pointer on resource to add
    */
    void addResource(boost::shared_ptr<ALResource> pResource);

    /**
    * isInGroup: is pResourceName in resource
    * @param pResourceName resource name
    */
    bool isInGroup(const std::string &pName);

    /**
    * deleteResource: delete a resource
    * @param pResourceName: resource name
    */
    void deleteResource(const std::string &pResourceName);

    /**
    * isResourceOwned. Is resource owned by specific owner
    * @param pointer on owner
    */
    bool isResourceOwned(const std::string &pOwner);

    /**
    * isResourceFree. Is resource free
    * @return true if resource is free
    */
    bool isResourceFree();

    /**
    * httpGet. Return string for http get with resource name and owner name
    * @param level recursive level
    */
    std::string httpGet(int level = 0);

    /**
    * stopWait. Ask to stop waiting a resource. For exemple if you wait a list of resource and one of the resource is lost.
    * @param pointer on owner
    */
    void stopWait();

   /**
    * getResourceList
    * @return vector of resource
    */
    std::vector<boost::shared_ptr<ALResource> > getResourceList();

  protected:

    /*
    * Resource list
    */
    std::vector<boost::shared_ptr<ALResource> > fList;

    /*
    * List manipulation protection
    */
    boost::shared_ptr<ALMutexRW> fResourceMutex;

    /*
    * stop waiting all resource if one resource is lost
    */
    bool fIsResourceLost;
  };

}
#endif // RESOURCE_H
