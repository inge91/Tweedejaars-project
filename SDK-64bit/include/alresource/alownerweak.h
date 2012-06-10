/**
* @author jerome Monceaux
* Aldebaran Robotics (c) 2007 All Rights Reserved
*/

#pragma once

#ifndef _LIB_ALRESOURCE_ALRESOURCE_ALOWNERWEAK_H_
#define _LIB_ALRESOURCE_ALRESOURCE_ALOWNERWEAK_H_

#include "alowner.h"

namespace AL
{

  /**
  * ALOwnerWeak. ALOwnerWeak wants peace and never conflict with other, just let them take their resources
  * No resource is an empty resource (every body can take it)
  */
  class ALOwnerWeak: public ALOwner
  {
  public:

    /**
    * Constructor
    * @param pName Unique Owner name
    * @param pModuleName Module that use the owner
    * @param pNotifier Module to notify (could be Choregraphe)
    * @param pHierarchy Hierarchy information
    */
    ALOwnerWeak(const std::string &pName, const std::string &pModuleName, boost::shared_ptr<ALProxy> pNotifier);

    /**
    * conflict. Conflict method (nothing inside because weak owner do nothing in case of conflict)
    * @param pName Unique Owner name
    * @param pModuleName Module that use the owner
    * @param pNotifier Module to notify (could be Choregraphe)
    * @param pHierarchy Hierarchy information
    * @return false
    */
    bool conflict(const std::string &pResourceName, boost::shared_ptr<ALOwner> pOwner, int pTimeout);

    /**
    * destructor

    */
    ~ALOwnerWeak();
  };

}
#endif // RESOURCE_H
