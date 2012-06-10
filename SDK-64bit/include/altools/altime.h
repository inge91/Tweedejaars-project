/**
* @author Aldebaran Robotics
* Copyright (c) Aldebaran Robotics 2007 All Rights Reserved
*/


/**
* Module that manage all system functionalities (linux, win32...)
*/

#pragma once

#ifndef _LIB_ALTOOLS_ALTOOLS_ALTIME_H_
#define _LIB_ALTOOLS_ALTOOLS_ALTIME_H_

#include <string>

namespace AL
{

  /*
  * ALTime manage high level time. Not real time function.
  */
  class ALTime
  {
  public:

    /**
    * getYear return year
    * @return year
    */
    inline int getYear() const
    {
      return wYear;
    }

    /**
    * getMonth return year
    * @return Month
    */
    inline int getMonth() const
    {
      return wMonth;
    }

    /**
    * getDay return day
    * @return day
    */
    inline int getDay() const
    {
      return wDay;
    }

    /**
    * getHour return hour
    * @return hour
    */
    inline int getHour() const
    {
      return wHour;
    }

    /**
    * getMinute return minutes
    * @return minutes
    */
    inline int getMinute() const
    {
      return wMinute;
    }

    /**
    * timeStamp string timestamp for log
    * @return timeStamp
    */
    static std::string timeStamp(void);

    /**
    * getSecond return seconds
    * @return seconds
    */
    inline int getSecond() const
    {
      return wSecond;
    }

    /**
    * getMs return wMilliseconds
    * @return wMilliseconds
    */
    inline int getMs() const
    {
      return wMilliseconds;
    }


  private:
    int wYear;
    int wMonth; // from 0 to 11, warning: human think of 1 to 12, so before stringify them for human, we must add one to month and day...
    int wDay; // from 0 to 27/29/30
    int wHour;
    int wMinute;
    int wSecond;
    int wMilliseconds;
    int wDayOfWeek; // not really used/dev (we put it at the end to speed up comparison)
    int wusec;
  public:


    /**
    * ALTime default constructor
    * @param pParams Initialisation parameters
    * @param pResult Result of the initialisation
    */
    ALTime();


    /**
    * ALTime
    * @param year year of the ALTime
    * @param month month of the ALTime
    * @param day day of the ALTime
    * @param hour hour of the ALTime
    * @param minute minute of the ALTime
    * @param second second of the ALTime
    * @param millisecond millisecond of the ALTime
    */
    ALTime( int year, int month, int day, int hour = 0, int minute = 0, int second = 0, int millisecond = 0 );

    /**
    * virtual destructor
    */
    virtual ~ALTime(){};

    /**
    * reset reset time to zero
    */
    void reset( void );



    /**
    * sup  true if this is strictly superior than base
    * @param base time to compare
    */
    bool sup(const ALTime& base) const;

    /**
    * operator>  true if this is strictly superior than base
    * @return   true if this is strictly superior than base
    */
    bool operator>( const ALTime& base ) const;

    /**
    * operator<=  true if this is inferior or equal than base
    * @return   true if this is inferior or equal than base
    */
    bool operator<=( const ALTime& base ) const;

    /**
    * operator<  true if this is strictly inferior than base
    * @return   true if this is strictly inferior than base
    */
    bool operator<( const ALTime& base ) const;

    /**
    * operator==  true if this is equal to base
    * @param   base ALTime time
    * @return   true if this is equal to base
    */
    bool operator==( const ALTime& base ) const;


    /**
    * operator=  set time to base
    * @param   strDate base
    */
    void operator=(const std::string &strDate);


    /**
    * operator+  add two ALTime
    * @param   base time
    * @return   time addition
    */
    ALTime operator+(const AL::ALTime &pTime);

    /**
    * getLocalTime will set the local time: month 0..11 and day 0..29/30
    */
    void getLocalTime(); // will return the local time: month 0..11 and day 0..29/30

    /**
    * toString return string date. This won't output a "human" date (because month is from 0 to 11)
    * @param strFormat output format
    * @return string date
    */
    std::string toString( const std::string& strFormat = "YYMMDD" ) const; // overload ALValue toString

    /**
    * toString return french string date.
    * @return string date
    */
    std::string toFrenchTime( bool pMs = false ) const; // overload ALValue toString


    /**
    * debug function
    */
    bool writeToFile( FILE* pfAlreadyOpen ) const;

    /**
    * debug function
    */
    bool readFromFile( FILE* pfAlreadyOpen );

    /**
    * isNull true if ALTime empty
    * @return true if ALTime empty
    */
    bool isNull() const;


  };
}


#endif  // _LIB_ALTOOLS_ALTOOLS_ALTIME_H_
