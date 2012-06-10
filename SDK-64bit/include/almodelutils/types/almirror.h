/**
* Copyright (c) Aldebaran Robotics 2011 All Rights Reserved
*/
#pragma once

#ifndef _LIB_ALMOTION_ALMOTION_TYPES_ALMIRROR_H_
#define _LIB_ALMOTION_ALMOTION_TYPES_ALMIRROR_H_

namespace AL {
  namespace Motion {

    enum MIRROR_TYPE
    {
      MIRROR_NONE,
      MIRROR_SYMMETRIC,
      MIRROR_ANTISYMMETRIC
    };

    struct Mirror {
      MIRROR_TYPE state;
      std::string name;

      // Default constructor
      Mirror(
          const MIRROR_TYPE& pState = MIRROR_NONE,
          const std::string& pName = "") :
          state(pState),
          name(pName){};
    };


  }
}
#endif  // _LIB_ALMOTION_ALMOTION_TYPES_ALMIRROR_H_
