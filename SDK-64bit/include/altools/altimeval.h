/**
* @author Aldebaran Robotics
* Copyright (c) Aldebaran Robotics 2007 All Rights Reserved
*/


#pragma once

#ifndef _LIB_ALTOOLS_ALTOOLS_ALTIMEVAL_H_
#define _LIB_ALTOOLS_ALTOOLS_ALTIMEVAL_H_

#include <ostream>

#ifdef _MSC_VER

  #include <winsock2.h>  // included via windows.h (except when W32LEANANDMEAN is defined)

  int gettimeofday(struct timeval* t, void* timezone);

  struct ALSystemStartupTimeStorage {
      ALSystemStartupTimeStorage();

      bool usePerformanceCounter;

      // A timeval representing system start
      struct timeval systemStartTime;
      // special types when using perf counter
      LARGE_INTEGER systemStartTicks;
      LARGE_INTEGER systemTicksPerSecond;
  };
#else
  #include <sys/time.h>
#endif

/*
 * ALTimeval.h and ALTimeval.cpp contain a set of utility functions that
 * manipulate timestamps easily.
 * This is mostly about operator overloading and basic functions.
 * ALTimeval should be cross-platform, and implements gettimeofday on
 * Windows.
 */

// reset time to 0,0
inline void reset(struct timeval & t)
{
  t.tv_sec = 0;
  t.tv_usec = 0;
}

// is time set to (0,0) ?
inline bool isNull(struct timeval & t)
{
  return t.tv_sec == 0 && t.tv_usec == 0;
}


void AddMicroSec(struct timeval & t, unsigned int pnTimeInMicroSec);

struct timeval operator+(const struct timeval & t1, const struct timeval & t2);
struct timeval operator+(const struct timeval & t1, long t2);  // WARNING: t2 is in second !!!!!
struct timeval operator-(const struct timeval & t1, const struct timeval & t2);
struct timeval operator-(const struct timeval & t1, long t2);  // WARNING: t2 is in second !!!!!
bool operator==(const struct timeval & t1, const struct timeval & t2);
bool operator< (const struct timeval & t1, const struct timeval & t2);
bool operator> (const struct timeval & t1, const struct timeval & t2);
bool operator<=(const struct timeval & t1, const struct timeval & t2);
bool operator>=(const struct timeval & t1, const struct timeval & t2);

struct timeval now(void);
struct timeval epoch(void);
void printtv(const struct timeval & t);
std::ostream &operator<<(std::ostream& os, const struct timeval & st);

std::string toString(const struct timeval & t);

typedef struct timeval ALTimeval;



/**
 * \brief give duration time between two dates (in micro seconds)
 *
 * Take 2 dates and return the duration between then is us.
 *
 * @param begin starting date
 * @param end ending date
 *
 * @return duration between the two dates
 */

int duration(const struct timeval & begin, const struct timeval & end);
long long duration64(const struct timeval & begin, const struct timeval & end);
float durationSec(const struct timeval & begin, const struct timeval & end);

#endif  // _LIB_ALTOOLS_ALTOOLS_ALTIMEVAL_H_
