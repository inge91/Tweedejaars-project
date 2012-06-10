/**
 * @author Aldebaran-Robotics
 * Aldebaran Robotics (c) 2007 All Rights Reserved
 */

#pragma once

#ifndef _LIB_ALRESOURCE_ALRESOURCE_ALHIERARCHYOWNER_H_
#define _LIB_ALRESOURCE_ALRESOURCE_ALHIERARCHYOWNER_H_


#include <string>
#include <boost/shared_ptr.hpp>

namespace AL
{
  /**
  * ALHierarchyOwner is an abstract class. Owner that want hierarchy should define it (for exemple Choregraphe boxes)
  * It is defined by a unique name and a parent
  */
  class ALHierarchyOwner
  {
  public:
    /**
    * isParent
    * @param pOwner pointer on owner that could be parent
    * @return true if pOwner is a parent
    */
    virtual bool isParent(boost::shared_ptr<ALHierarchyOwner> pOwner){return false;};

    /**
    * getOwnerName
    * @return owner name
    */
    virtual std::string getOwnerName() = 0;

  };

}
#endif // RESOURCE_H
