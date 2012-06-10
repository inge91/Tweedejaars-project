/*
** alremotemessage.h
** Login : <hcuche@hcuche-de>
** Started on  Tue Jun  7 11:49:15 2011 Herve Cuche
** $Id$
**
** Author(s):
**  - Herve Cuche <hcuche@aldebaran-robotics.com>
*/

#ifndef ALREMOTEMESSAGE_H_
# define ALREMOTEMESSAGE_H_

# include <qi/log.hpp>
# include <qi/os.hpp>

# define CAT_SIZE 64
# define FILE_SIZE 128
# define FUNC_SIZE 64
# define LOG_SIZE 2048

namespace AL
{
  class ALRemoteLogMessage
  {
  public:
    ALRemoteLogMessage() {};
    ALRemoteLogMessage(const qi::log::LogLevel  verb,
                       const qi::os::timeval    date,
                       const char               *file,
                       const char               *fct,
                       const char               *category,
                       const int                line,
                       const char               *msg);

    virtual ~ALRemoteLogMessage() {};

    qi::log::LogLevel   _logLevel;
    qi::os::timeval     _date;
    char                _category[CAT_SIZE];
    char                _file[FILE_SIZE];
    char                _function[FUNC_SIZE];
    int                 _line;
    char                _message[LOG_SIZE];
  };
}; // !AL

#endif // !ALREMOTEMESSAGE_H_
