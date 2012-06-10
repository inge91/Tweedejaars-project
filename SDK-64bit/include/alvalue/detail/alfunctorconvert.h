
#pragma once
#ifndef _LIBALVALUE_ALVALUE_DETAIL_ALFUNCTORCONVERT_H_
#define _LIBALVALUE_ALVALUE_DETAIL_ALFUNCTORCONVERT_H_

#include <alvalue/alvalue.h>
#include <alerror/alerror.h>
#include <cassert>
#include <alvalue/config.h>

namespace AL
{
  namespace detail {

  template <class T>
  class converter
  {
  public:
    T convertFromALValue(const  ALValue &pVariant)
    {
      // This template seems pointless now,
      // only the specializations are used
      T pObject;
      return pObject;
    }

    ALValue convertToALValue(const T &param)
    {
      // This template seems pointless now,
      // only the specializations are used
      ALValue bData;
      return bData;
    }
  };


  template <> class converter<int>
  {
  public:
    int convertFromALValue(const ALValue &pVariant)
    {
      if ((pVariant.getType() != AL::ALValue::TypeInt))
      {
        std::string strError = "Parameter type is " + ALValue::TypeToString(pVariant.getType() ) + std::string(" instead of int");
        throw ALERROR("convertFromALValue", "convertFromALValue", strError);
      }
      return (int)pVariant;
    }

    ALValue convertToALValue(int val)
    {
      // use default ALValue constructor
      return val;
    }
  };


  /**
    * we support pointer in binded method. But only local call can use pointer,
    * so they could not be serialized.
    */
  template <typename T> class converter<T *>
  {
  public:
    T *convertFromALValue(const ALValue &pVariant)
    {
      assert(false && "pointer should not be serialized, it's only for local function");
      return (T *)0;
    }

    ALValue convertToALValue(T *val)
    {
      assert(false && "pointer should not be serialized, it's only for local function");
      ALValue valret;
      return valret;
    }
  };


  template <> class converter<std::string>
  {
  public:
    std::string convertFromALValue(const ALValue &pVariant)
    {
      if (pVariant.getType() != AL::ALValue::TypeString)
      {
        std::string strError = "Parameter type is " + ALValue::TypeToString(pVariant.getType() ) + std::string(" instead of string");
        throw ALERROR("convertFromALValue", "convertFromALValue", strError);
      }
      return (std::string)pVariant;
    }

    ALValue convertToALValue(const std::string &val)
    {
      // use default ALValue constructor
      return val;
    }
  };

  //// ck 1/1/2011 Why?
  //template <class Z> class converter<boost::shared_ptr<Z> >
  //{
  //public:
  //  boost::shared_ptr<Z> convertFromALValue(const ALValue &pVariant)
  //  {
  //    return boost::shared_ptr<Z>();
  //  }

  //};


  template <> class converter<ALValue >
  {
  public:
    ALValue convertFromALValue(const ALValue &pVariant)
    {
      return pVariant;
    }

    ALValue convertToALValue(const ALValue &val)
    {
      fflush(NULL);
      // use default ALValue constructor
      return val;
    }
  };

  template <> class converter<bool >
  {
  public:
    bool convertFromALValue(const ALValue &pVariant)
    {
      // EPOT 01/06/2010 Accept ints as well, as in Urbi, boolean does not exist...
      if (pVariant.getType() != AL::ALValue::TypeBool && pVariant.getType() != AL::ALValue::TypeInt)
      {
        std::string strError = "Parameter type is " + ALValue::TypeToString(pVariant.getType() ) + std::string(" instead of bool");
        throw ALERROR("convertFromALValue", "convertFromALValue", strError);
      }

      if(pVariant.getType() == AL::ALValue::TypeInt)
        return (int)pVariant != 0;

      return (bool)pVariant;
    }


    ALValue convertToALValue(bool val)
    {
      // use default ALValue constructor
      return val;
    }
  };

  template <> class converter<float >
  {
  public:
    float convertFromALValue(const ALValue &pVariant)
    {
      if ((pVariant.getType() != AL::ALValue::TypeFloat) && (pVariant.getType() != AL::ALValue::TypeInt))
      {
        std::string strError = "Parameter type is " + ALValue::TypeToString(pVariant.getType() ) + std::string(" instead of float");
        throw ALERROR("convertFromALValue", "convertFromALValue", strError);
      }
      return float(pVariant);
    }


    ALValue convertToALValue(float val)
    {
      // use default ALValue constructor
      return val;
    }
  };


  template <> class converter<std::vector<std::string> >
  {
  public:
    std::vector<std::string> convertFromALValue(const ALValue &pVariant)
    {
      if (pVariant.getType() != AL::ALValue::TypeArray)
      {
        std::string strError = "Parameter type is " + ALValue::TypeToString(pVariant.getType() ) + std::string(" instead of vector");
        throw ALERROR("convertFromALValue", "convertFromALValue", strError);
      }
      std::vector<std::string> retValue;
      pVariant.ToStringArray(retValue);
      return  retValue;
    }

    ALValue convertToALValue(std::vector<std::string> val)
    {
      // use default ALValue constructor
      return val;
    }
  };


  template <> class converter<std::vector<float> >
  {
  public:
    std::vector<float> convertFromALValue(const ALValue &pVariant)
    {
      if (pVariant.getType() != AL::ALValue::TypeArray)
      {
        std::string strError = "Parameter type is " + ALValue::TypeToString(pVariant.getType() ) + std::string(" instead of vector");
        throw ALERROR("convertFromALValue", "convertFromALValue", strError);
      }
      std::vector<float> retValue;
      pVariant.ToFloatArray(retValue);
      return retValue;
    }

    ALValue convertToALValue(std::vector<float> val)
    {
      // use default ALValue constructor
      return val;
    }
  };
}

}
#endif  // _LIBALVALUE_ALVALUE_DETAIL_ALFUNCTORCONVERT_H_

