#pragma once

#ifndef _LIB_ALLOG_ALLOG_LOGMESSAGE_LOGMESSAGE_H_
#define _LIB_ALLOG_ALLOG_LOGMESSAGE_LOGMESSAGE_H_

// COPY FROM ALLOG
#ifdef allog_EXPORTS

#ifdef _WIN32
#define LIBSYSLOGAPI __declspec(dllexport)
#else
// :TODO: use __attribute__((visibility("default"))) on compatible platforms
#define LIBSYSLOGAPI
#endif

#else

#ifdef _WIN32
#define LIBSYSLOGAPI __declspec(dllimport)
#else
// :TODO: use __attribute__((visibility("hidden"))) on compatible platforms
#define LIBSYSLOGAPI
#endif

#endif

#include <string>

namespace AL
{
  /**
   * Structure used to hold a log message.
   */
  struct LIBSYSLOGAPI LogMessage
  {
    /**
     * Enum of accepted error types
     */
    enum Level
    {
      t_debug = 10,
      t_info = 20,
      t_warning = 30,
      t_error = 40,
      t_fatal = 50,
      t_silent = 100,
    };

    /**
     * Enum of the different log types
     */
    enum Type
    {
      LOGMESSAGE,
      LOGMESSAGECODE,
      LOGMESSAGEMODULE,
    };

    /**
     * Default Constructor.
     */
    LogMessage();

    /**
     * Constructor.
     * @param pLevel The log level.
     * @param pMessage The log message.
     */
    LogMessage(
      LogMessage::Level pLevel,
      const std::string& pMessage);

    /**
     * Convert a Level into a std::string.
     * @param level { t_debug, t_info, t_warning, t_error, t_fatal, t_silent }
     * @param abbreviation. If this option is true, return the abbreviated string
     * (e.g. "DBG" for "debug")
     */
    static const std::string levelToString(Level pLevel, bool pAbbreviation);

    /**
     * Convert a std::string into a Level.
     * @param levelString. Can be abbreviated ("DBG"), or not ("debug").
     */
    static const Level stringToLevel(const std::string& pLevelString);

    /**
     * Convert log to standard format.
     * @param This parameter may be used by the derivate classes to define
     * different levels of information detail to be shown as its format.
     */
    virtual const std::string toString(int pVerbose = 0);

    /**
     * Virtual function used to discover the log type.
     */
    virtual Type type() { return LOGMESSAGE; }

    /**
     * The level of the log message.
     */
    Level fLevel;

    /**
     * The message itself.
     */
    std::string fMessage;
  };
}
#endif  // _LIB_ALLOG_ALLOG_LOGMESSAGE_LOGMESSAGE_H_
