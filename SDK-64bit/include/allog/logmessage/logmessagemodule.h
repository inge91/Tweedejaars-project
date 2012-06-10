#pragma once

#ifndef _LIB_ALLOG_ALLOG_LOGMESSAGE_LOGMESSAGEMODULE_H_
#define _LIB_ALLOG_ALLOG_LOGMESSAGE_LOGMESSAGEMODULE_H_

#ifdef _MSC_VER
// Avoid warning when exporting external string fModule
# pragma warning( push )
# pragma warning( disable : 4251 )
#endif

#include <allog/logmessage/logmessagecode.h>

namespace AL
{
  /**
   * Struct used to store logs from NaoQi modules.
   */
  struct LIBSYSLOGAPI LogMessageModule : public LogMessageCode
  {
    /**
     * Default Constructor.
     */
    LogMessageModule();

    /**
     * Constructor.
     * @param pLevel The log level.
     * @param pMessage The log message.
     * @param pModule The module name from which the log was emmited.
     * @param pFileLiteral The file in const char* literal format.
     * @param pFile The file in string format - use if literal is not available.
     * @param pFunctionLiteral The function in const char* literal format.
     * @param pFunction The function in string format - use if literal is not
     * avaiable.
     * @param pLine The line were the log was emmited.
     */
    LogMessageModule(
      LogMessage::Level pLevel,
      const std::string& pMessage,
      const std::string& pModule,
      const char* pFileLiteral,
      const std::string& pFile,
      const char* pFunctionLiteral,
      const std::string& pFunction,
      unsigned long pLine);

    /**
     * Virtual function used to discover the log type.
     */
    virtual Type type() { return LOGMESSAGEMODULE; }

    /**
     * Convert log to standard format.
     * @param pVerbose Can define 3 levels of verbosity.
     * 0: LVL: ModuleName: Message
     * 1: LVL: ModuleName: Message
     * 2: LVL: Message
     *       - Module: ModuleName
     *       - File: FilePath
     *       - Function: FunctionName
     *       - Line: LineNo
     */
    virtual const std::string toString(int pVerbose = 0);

    /**
     * The module from where the log were called.
     */
    std::string fModule;
  };
}

#ifdef _MSC_VER
# pragma warning( pop )
#endif

#endif  // _LIB_ALLOG_ALLOG_LOGMESSAGE_LOGMESSAGEMODULE_H_
