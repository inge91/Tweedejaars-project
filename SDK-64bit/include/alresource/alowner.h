/**
* @author Aldebaran-Robotics
* Aldebaran Robotics (c) 2007 All Rights Reserved
*/

#pragma once

#ifndef _LIB_ALRESOURCE_ALRESOURCE_ALOWNER_H_
#define _LIB_ALRESOURCE_ALRESOURCE_ALOWNER_H_

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/smart_ptr/enable_shared_from_this.hpp>
#include <alcommon/alproxy.h>

namespace AL
{
  class ALBroker;
  class ALMutexRW;
  class ALMutex;
  class ALHierarchyOwner;

  /**
  * ALOwner is a resource owner
  */
  class ALOwner: public ::boost::enable_shared_from_this<ALOwner>
  {
  public:
    typedef boost::shared_ptr<ALOwner>       Ptr;
    typedef boost::shared_ptr<const ALOwner> ConstPtr;
    typedef boost::weak_ptr<ALOwner>         WeakPtr;
    typedef boost::weak_ptr<const ALOwner>   WeakConstPtr;

    inline boost::shared_ptr<ALOwner> getThis() {
      return ::boost::enable_shared_from_this<ALOwner>::shared_from_this();
    }

    inline boost::shared_ptr<const ALOwner> getThis() const {
      return ::boost::enable_shared_from_this<ALOwner>::shared_from_this();
    }

    // TODO: add ctor and virtual dtor.


    enum exitReasonEnum
    {
      eTimeout = 0,  // optionnal owner
      eEndWait = 1,
    } ;

    /**
    * isParent
    * @param pOwner pointer on owner that could be parent
    * @return true if pOwner is a parent
    */
    virtual bool conflict(const std::string &pResourceName, boost::shared_ptr<ALOwner> pOwner, int pTimeout) = 0;

    /**
    * getType
    * @return owner type
    */
    std::string getType(){return fStrType;};

    /**
    * getModuleName
    * @return owner module name (not unique)
    */
    inline std::string getModuleName() { return fModuleName; } ;

    /**
    * getUniqueID
    * @return owner module name (unique)
    */
    inline std::string getUniqueID() { return fID; } ;

    /**
    * getWaiter
    * @return string with owner that wait the same resource
    */
    std::string getWaiter(){return fWaiter;};

    /**
    * setParentBroker set pointer to broker
    * @param pBroker
    */
    void setParentBroker(boost::shared_ptr<ALBroker> pBroker);

    /**
    * freeResource force owner to free resource (nothing done by default)
    */
    virtual void freeResource(void) {};

    /**
    * Get owner wait timeout
    * @return timeout (string)
    */
    std::string getTimeout();

    /**
    * Is owner is parent of another
    * @return true if pOwner is parent of this
    */
    virtual bool isParent(boost::shared_ptr<ALOwner> pOwner){return false;};

    /**
    * getHierarchy get hierarchy information
    * @return pointer on hierarchy information
    */
    boost::shared_ptr<ALHierarchyOwner> getHierarchy(){return fHierarchy;};

    /**
    * isRelease return true if someone asked to the owner to end the conflict
    */
    bool isRelease(){return fRelease;};

    /**
    * setParentOwner
    * @param pOwner parent owner of the current owners
    */
    void setParentOwner(boost::shared_ptr<ALOwner> pOwner, const std::string &pResourceName);

    /**
    * parentOwner
    * @return  return the current owner parent.
    */
    boost::shared_ptr<ALOwner> getParentOwner(const std::string &pResource);

    // TODO: move this to private section.
    /**
    * we are not allowed to wait and release the same resource in the same time. Variable use from outside.
    * @return  return the current owner parent.
    */
    boost::shared_ptr<ALMutex> fWaitReleaseMutex;

    //void setNotifier(boost::shared_ptr<ALProxy> pProxy);
  protected:

    /*
    * We want to end the conflict between owner
    */
    bool fRelease;

    /*
    * Access to notifier (could be someone else than Choregraphe)
    */
    boost::shared_ptr<ALProxy> fChoregrapheProxy;

    /*
    * Unique ID of the owner
    */
    std::string fID;

    /*
    * Module name of the owner (optional)
    */
    std::string fModuleName;

    /*
    * Parent broker
    */
    boost::weak_ptr<ALBroker> fParentBroker;

    /*
    * We cannot destroy the owner while conflicting with another owner
    */
    boost::shared_ptr<ALMutexRW> fDestroyMutex;

    /*
    * Onwer Type
    */
    std::string fStrType;

    /*
    * Protect the debug string displayed in httpget
    */
    boost::shared_ptr<ALMutexRW> fWaiterMutex;

    /*
    * httpget string
    */
    std::string fWaiter;

    /*
    * Owner hierarchy
    */
    boost::shared_ptr<ALHierarchyOwner> fHierarchy;

    /*
    * List of parent that should get back the resources.
    */
    //std::vector< std::pair<boost::shared_ptr<ALOwner> , std::string> > fParentOwner;
    std::map<std::string , boost::weak_ptr<ALOwner> > fParentOwner;
    /*
    * Timeout
    */
    int fTimeout;
  };

}
#endif // RESOURCE_H
