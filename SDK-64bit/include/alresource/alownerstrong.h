/**
 * @author jerome Monceaux
 * Aldebaran Robotics (c) 2007 All Rights Reserved
 */

#pragma once

#ifndef _LIB_ALRESOURCE_ALRESOURCE_ALOWNERSTRONG_H_
#define _LIB_ALRESOURCE_ALRESOURCE_ALOWNERSTRONG_H_

#include "alowner.h"
#include "alhierarchyowner.h"

namespace AL
{

  /**
  * ALOwnerStrong. Exclusive owner on resource.
  */
  class ALOwnerStrong: public ALOwner
 {
 public:

   /**
   * Constructor
   * @param pName Unique Owner name
   * @param pModuleName Module that use the owner
   * @param pNotifier Module to notify (could be Choregraphe)
   * @param pHierarchy Hierarchy information
   */
   ALOwnerStrong(const std::string &pName, const std::string &pModuleName, boost::shared_ptr<ALProxy> pNotifier, boost::shared_ptr<ALHierarchyOwner> pHierarchy);

   /**
   * conflict Conflict with another owner Exclusive use of the resource
   * @param pResourceName Resource name that pOwner want
   * @param pOwner Owner that want the pResourceName
   * @param pTimeout the time pOwner accept to wait
   * @return true if timeout
   */
   bool conflict(const std::string &pResourceName, boost::shared_ptr<ALOwner> pOwner, int pTimeout);

   /**
   * notifyConflictChoregraphe notifiy a module when someone want a resource
   * @param pOwner owner that want the resource
   * @param pTimeout timeout
   */
   void notifyConflictChoregraphe(boost::shared_ptr<ALOwner> pOwner, int pTimeout);

   /**
   * notifyConflictChoregraphe notifiy end of conflict
   * @param pOwner owner that want the resource
   * @param pTimeout timeout
   */
   void notifyEndConflictChoregraphe(boost::shared_ptr<ALOwner> pOwner, int pTimeout);

   /**
   * addWaiter. Create a waiter list for httpget
   * @param pOwner owner that want the resource
   * @param pTimeout timeout
   */
   void addWaiter(boost::shared_ptr<ALOwner> pOwner, int pTimeout);

   /**
   * notifyConflictOwner. Notify current owner (this) that someone want his resources
   * @param pResourceName Resource name 
   * @param pOwner Owner that wants the resource
   * @param pTimeout timeout
   */
   void notifyConflictOwner(const std::string &pResourceName, boost::shared_ptr<ALOwner> pOwner, int pTimeout);

   /**
   * isParent. Is pOwner parent of current owner
   * @param pOwner Owner that could be the parent
   * @return true if pOwner is parent
   */
   bool isParent(boost::shared_ptr<ALOwner> pOwner);

   /**
   * freeResource. Free resource event if we are in confict
   */
   void freeResource(void);

    ~ALOwnerStrong();

 };

}
#endif // RESOURCE_H
