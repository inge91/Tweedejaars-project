/**
* @author Aldebaran-Robotics
* Aldebaran Robotics (c) 2009 All Rights Reserved
*/

#pragma once

#ifndef _LIB_ALBEHAVIORINFO_ALBEHAVIORINFO_H_
#define _LIB_ALBEHAVIORINFO_ALBEHAVIORINFO_H_

#include <string>
#include <vector>
#include <map>

namespace AL
{
  class ALBehaviorInfo
  {
  public:

    ALBehaviorInfo(const std::string &pName, const std::vector<std::string> pResource, std::string pCondition);
    // accessor
    inline void setName(const std::string &pName){ fName = pName;}
    inline std::string getName(void){return fName;}

    // accessor
    inline void setResources(const std::vector<std::string> pResource){fResources = pResource;}
    inline std::vector< std::string> getResources(void){ return fResources;}


    inline void setCondition(const std::string &pcondition){ fCondition = pcondition;}
    inline std::string getCondition(void){ return fCondition;}

    void setNote(float pNote);
    inline float getNote(void) { return fNote;}
    inline void initNote(void){ fNote = 0; }

    friend bool operator < (const ALBehaviorInfo & lhs, const ALBehaviorInfo & rhs)
    {
      return (lhs.fNote < rhs.fNote ? true : false);
    }

    friend bool operator > (const ALBehaviorInfo & lhs, const ALBehaviorInfo & rhs)
    {
      return (lhs.fNote > rhs.fNote ? true : false);
    }

  private:
    std::string fName;
    std::string fCondition;
    std::vector <std::string> fResources;
    std::map<std::string, float> fPluginNote;
    float fNote;
  };


}
#endif  // _LIB_ALBEHAVIORINFO_ALBEHAVIORINFO_H_

