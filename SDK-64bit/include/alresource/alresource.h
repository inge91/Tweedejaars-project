/**
* @author Aldebaran-Robotics.
* Aldebaran Robotics (c) 2007 All Rights Reserved
*/

#pragma once

#ifndef _LIB_ALRESOURCE_ALRESOURCE_ALRESOURCE_H_
#define _LIB_ALRESOURCE_ALRESOURCE_ALRESOURCE_H_

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
  class ALResource
  {
  public:

    /**
    * Constructor
    * @param unique resource name
    * @param pointer on parent (or NULL)
    */
    ALResource(const std::string &pName, boost::shared_ptr<ALResource> pParent);

    // TODO: initialize members => call init().
    ALResource(){};

    /**
    * Init members
    * @param unique resource name
    * @param pointer on parent (or NULL)
    */
    void init(const std::string &pName, boost::shared_ptr<ALResource> pParent);


    /**
    * virtual destructor 
    */
    virtual ~ALResource() {};

    /**
    * createOwner. Create a owner for the resource
    * @param fOwnerType owner type (unused)
    * @param pName owner name
    * @param pModule. Module that use the owner (for notification)
    * @param pNotifier. Pointer on Choregraphe
    * @param pHierarchy. Hierarchy information
    * @return pointer on owner
    */
    static boost::shared_ptr<ALOwner> createOwner(int fOwnerType, const std::string &pName, const std::string &pModule, boost::shared_ptr<ALProxy> pNotifier, boost::shared_ptr<ALHierarchyOwner> pHierarchy);

    /**
    * waitFor. Wait a resource
    * @param pOwner owner that want resource
    * @param pCallbackName notification callback if someone want the resource
    * @param nTimeOutMillisec timeout we wait resource. -1 = no timeout
    */
    virtual void waitFor(boost::shared_ptr<ALOwner> pOwner, const std::string &pCallbackName, int nTimeOutMillisec);

    /**
    * switchOwner. Switch owner without conflict (for exemple for parent/children)
    * @param pOwner owner that want resource
    * @param pCallbackName notification callback if someone want the resource
    * @param nTimeOutMillisec timeout we wait resource. -1 = no timeout
    */
    virtual void switchOwner(boost::shared_ptr<ALOwner> pOwner, const std::string &pCallbackName, int nTimeOutMillisec);

    /**
    * release. Owner release a resource
    * @param pOwner owner that release the resource
    */
    virtual void release(boost::shared_ptr<ALOwner> pOwner);

    /**
    * getName. Get resource name
    * @return resource name
    */

    inline std::string getName() { return fName;};

    /**
    * isResourceFree. Is resource free
    * @return true if resource is free
    */
    virtual bool isResourceFree();

    /**
    * getOwner. Return the resource owner
    * @return resource owner
    */
    inline boost::shared_ptr<ALOwner> getOwner() { return fOwner; };

    /**
    * addResource: Add a resource in a resource
    * @param pointer on resource to add
    */
    virtual void addResource(boost::shared_ptr<ALResource> pResource);

    /**
    * isInGroup: is pResourceName in resource
    * @param pResourceName resource name
    */
    virtual bool isInGroup(const std::string &pName);

    /**
    * deleteResource: delete a resource 
    * @param pName resource name
    */
    virtual void deleteResource(const std::string &pName);

    /**
    * isResourceOwned. Is resource owned by specific owner
    * @param pointer on owner
    */
    virtual bool isResourceOwned(const std::string &pOwner);

    /**
    * httpGet. Return string for http get with resource name and owner name
    * @param level recursive level
    */
    virtual std::string httpGet(int level = 0);

    /**
    * stopWait. Ask to stop waiting a resource. For exemple if you wait a list of resource and one of the resource is lost.
    * @param pointer on owner
    */
    virtual void stopWait();

    /**
    * setNotifier. Define a module to inform conflict.
    * @param pointer on proxy to module to notify (for exemple Choregraphe)
    */
    void setNotifier(boost::shared_ptr<ALProxy> pProxy);

  protected:


    /*
    * Module to notify when conflict
    */
    boost::shared_ptr<ALProxy> fChoregrapheProxy;

    /*
    * Resource name
    */
    std::string fName;

    /*
    * Resource owner
    */
    boost::shared_ptr<ALOwner> fOwner;

    // cannot release and wait release in the same time
    /*
    * Owner manipulation protection
    */
    boost::shared_ptr<ALMutex> fOwnerMutex;

    /* 
    * No owner mean emptyOwner
    */
    boost::shared_ptr<ALOwnerWeak> fEmptyOwner;

    /*
    * two owner cannot take the same resource in the same time
    */
    boost::shared_ptr<ALMutex> fExclusiveOwner;  

    /*
    * protect the owner afectation
    */
    boost::shared_ptr<ALMutexRW> fOwnerPointerMutex;  

    /*
    * Parent resource.
    */
    boost::weak_ptr<ALResource> fParent;

    /*
    * Allow to check if we want to stop to wait a resource list
    */
    bool fStopWait;

  };

}
#endif // RESOURCE_H
