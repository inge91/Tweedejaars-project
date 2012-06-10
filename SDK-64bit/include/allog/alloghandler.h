/**
 * @author Aldebaran Robotics
 * Copyright (c) Aldebaran Robotics 2010, 2011 All Rights Reserved
 *
 */

#pragma once

#ifndef _LIB_ALLOG_ALLOG_ALLOGHANDLER_H_
#define _LIB_ALLOG_ALLOG_ALLOGHANDLER_H_

#include <boost/filesystem.hpp>
#include <allog/allog.h>

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

namespace AL
{
#ifdef WIN32
 static void* fScreen;
#endif

  /**
   * Log to syslog (Linux only)
   * @param log. The log message.
   */
  void LIBSYSLOGAPI writeToSysLog(boost::shared_ptr<LogMessage> pLog);

  /**
   * Log to stdout with colors
   * @param log. The log message.
   */
  void LIBSYSLOGAPI writeToStdoutColor(boost::shared_ptr<LogMessage> pLog);

  class LIBSYSLOGAPI ALLogHandler
  {
  public:
    ~ALLogHandler();
    /**
     * Write logs to file.
     * Call removeHandler(filepath) to remove this handler.
     * NOTE: If you used an boost::filesystem::path as parameter, you must call .string() method
     * to use with the removeHandler function.
     * @param pFilePath absulte path to the log file.
     */
    static void logToFile(const boost::filesystem::path& pFilePath);

    /**
     * Send logs to sylog (Linux only)
     * Call removeHandler("logToSyslog") to remove this handler.
     * @param procname displayed in syslog
     */
    static void logToSyslog(const char *procname= "NaoQi");

    /**
     * Log to standard ouput.
     * Call removeHandler("logToStdout") to disable this handler.
     */
    static void logToStdout();

    /**
     * Add new function to the log signal.
     * @param handler Callable of LogSignal slot type.
     * @param id Name to use when registering this handler.
     */
    static void addHandler(
      const ALLog::LogSignal::slot_type& pHandler,
      const std::string& pId);

    /**
     * Remove the specified pID handler from the signal list.
     * @param id. Name used when registered the handler.
     */
    static void removeHandler(
      const std::string& pId);

    /**
     * Set this variable to true to make ALLogHandler functions more verbose.
     */
    static int fVerbose;
  };
}
#endif  // _LIB_ALLOG_ALLOG_ALLOGHANDLER_H_
