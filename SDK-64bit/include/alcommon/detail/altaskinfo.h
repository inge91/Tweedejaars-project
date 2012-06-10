/**
* @author Aldebaran Robotics
* Copyright (c) Aldebaran Robotics 2007, 2011 All Rights Reserved
*/


#pragma once
#ifndef _LIBALCOMMON_ALCOMMON_DETAIL_ALTASKINFO_H_
#define _LIBALCOMMON_ALCOMMON_DETAIL_ALTASKINFO_H_

#include <string>
#include <pthread.h>

namespace AL
{

  namespace detail {

    /**
    * This class stores information about a running task
    */
    class ALTaskInfo
    {
    private:
      int         fID;
      pthread_t   fThreadID;
      std::string fModuleName;
      std::string fMethodName;
      bool        fShouldStop;

    public:
      ALTaskInfo();

      /**
      * setID. set a unique id to each call method
      * @param pID unique task id
      */
      void setID(int pID);

      /**
      * getID. get a unique id to each call method
      * @return return unique task id
      */
      int getID(void);

      /**
      * setThread. set thread id (for exemple pthread ID)
      * @param pThreadID thread id
      */
      void setThreadID(pthread_t pThreadID);

      /**
      * getThreadID. get thread id (for exemple pthread ID)
      * @return pID unique task id
      */
      pthread_t getThreadID(void);

      /**
      * setModuleName. set module name that execute monitored function
      * @param pModuleName module name
      */
      void setModuleName(const std::string &pModuleName);

      /**
      * getModuleName. get module name
      * @return module name
      */
      std::string getModuleName(void);

      /**
      * setMethodName. set method name to monitor
      * @param pMethodname method name
      */
      void setMethodName(const std::string &pMethodname);

      /**
      * getMethodName. get method name
      * @return method name
      */
      std::string getMethodName(void);

      std::string getName(void);

      std::string toString();

      void setRequireStop(bool pRequire);

      bool isRequireStop(void);

      ~ALTaskInfo();
    };
  }
}

#endif  // _LIBALCOMMON_ALCOMMON_DETAIL_ALTASKINFO_H_
