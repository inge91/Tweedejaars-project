#pragma once

#ifndef _LIB_ALLOG_ALLOG_LOGMESSAGE_LOGMESSAGECODE_H_
#define _LIB_ALLOG_ALLOG_LOGMESSAGE_LOGMESSAGECODE_H_

#include <allog/logmessage/logmessage.h>

namespace AL
{
  /**
   * Struct used to store logs originating from code, containing the file, function and line.
   */
  struct LIBSYSLOGAPI LogMessageCode : public LogMessage
  {
    /**
     * Default Constructor.
     */
    LogMessageCode();

    /**
     * Constructor.
     * @param pLevel The log level.
     * @param pMessage The log message.
     * @param pFileLiteral The file in const char* literal format.
     * @param pFile The file in string format - use if literal is not available.
     * @param pFunctionLiteral The function in const char* literal format.
     * @param pFunction The function in string format - use if literal is not
     * avaiable.
     * @param pLine The line were the log was emmited.
     */
    LogMessageCode(
      LogMessage::Level pLevel,
      const std::string& pMessage,
      const char* pFileLiteral,
      const std::string& pFile,
      const char* pFunctionLiteral,
      const std::string& pFunction,
      unsigned long pLine);

    /**
     * Virtual function used to discover the log type.
     */
    virtual Type type() { return LOGMESSAGECODE; }

    /**
     * Convert log to standard format.
     * @param pVerbose Can define 3 levels of verbosity.
     * 0: LVL: Message
     * 1: LVL: FileName: LineNo: Message
     * 2: LVL: Message
     *       - File: FilePath
     *       - Function: FunctionName
     *       - Line: LineNo
     */
    virtual const std::string toString(int pVerbose = 0);

    /**
     * The file from where the log were called.
     */
    const char* fFileLiteral;

    /**
     * The file from where the log were called.
     */
    std::string fFile;

    /**
     * The function from where the log were called.
     */
    const char* fFunctionLiteral;

    /**
     * The function from where the log were called.
     */
    std::string fFunction;

    /**
     * The line from where the log were called.
     */
    unsigned long fLine;
  };
}

#endif  // _LIB_ALLOG_ALLOG_LOGMESSAGE_LOGMESSAGECODE_H_
