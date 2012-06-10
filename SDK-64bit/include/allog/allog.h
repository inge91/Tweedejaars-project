/**
 * @author Aldebaran Robotics
 * Aldebaran Robotics (c) 2010 All Rights Reserved
 */

#pragma once

#ifndef _LIB_ALLOG_ALLOG_ALLOG_H_
#define _LIB_ALLOG_ALLOG_ALLOG_H_

#ifdef _MSC_VER
/* The MVS compiler doesn't like that we export symbols using the boost library
 * becouse boost is compiled only as static lib and therefore code using ALLog
 * will use it's instance of boost to initialize the variables, and not the one
 * in ALLog.
 * TODO: Try to use a dll for boost!
 */
#pragma warning( push )
#pragma warning( disable : 4251 )
#endif

#include <sstream>
#include <map>

#include <boost/signal.hpp>
#include <boost/bind.hpp>
#include <boost/signals/connection.hpp>

#include <boost/shared_ptr.hpp>
#include <allog/logmessages.h>

#ifdef allog_EXPORTS

# ifdef _WIN32
#  define LIBSYSLOGAPI __declspec(dllexport)
# else
   // :TODO: use __attribute__((visibility("default"))) on compatible platforms
#  define LIBSYSLOGAPI
# endif

#elif defined(allog_IMPORTS)

# ifdef _WIN32
#  define LIBSYSLOGAPI __declspec(dllimport)
# else
   // :TODO: use __attribute__((visibility("hidden"))) on compatible platforms
#  define LIBSYSLOGAPI
# endif
#else
# define LIBSYSLOGAPI
#endif

// log macro, string version
#define alinfo(x) AL::getLogger()->log(AL::LogMessage::t_info, x, __FILE__, __FUNCTION__, __LINE__)
#define aldebug(x) AL::getLogger()->log(AL::LogMessage::t_debug, x, __FILE__, __FUNCTION__, __LINE__)
#define alwarning(x) AL::getLogger()->log(AL::LogMessage::t_warning, x, __FILE__, __FUNCTION__, __LINE__)
#define alerror(x) AL::getLogger()->log(AL::LogMessage::t_error, x, __FILE__, __FUNCTION__, __LINE__)
#define alfatal(x) AL::getLogger()->log(AL::LogMessage::t_fatal, x, __FILE__, __FUNCTION__, __LINE__)

// log macro, stream version
#define alsinfo AL::ALStreamLog(AL::LogMessage::t_info, __FILE__,__FUNCTION__, __LINE__).self()
#define alsdebug AL::ALStreamLog(AL::LogMessage::t_debug, __FILE__,__FUNCTION__, __LINE__).self()
#define alswarning AL::ALStreamLog(AL::LogMessage::t_warning, __FILE__,__FUNCTION__, __LINE__).self()
#define alserror AL::ALStreamLog(AL::LogMessage::t_error, __FILE__,__FUNCTION__, __LINE__).self()
#define alsfatal AL::ALStreamLog(AL::LogMessage::t_fatal, __FILE__,__FUNCTION__, __LINE__).self()

// log module macro, string version
#define almdebug(x) AL::getLogger()->log(AL::LogMessage::t_debug, x, getName(), __FILE__, __FUNCTION__, __LINE__)
#define alminfo(x) AL::getLogger()->log(AL::LogMessage::t_info, x, getName(), __FILE__, __FUNCTION__, __LINE__)
#define almwarning(x) AL::getLogger()->log(AL::LogMessage::t_warning, x, getName(), __FILE__, __FUNCTION__, __LINE__)
#define almerror(x) AL::getLogger()->log(AL::LogMessage::t_error, x, getName(), __FILE__, __FUNCTION__, __LINE__)
#define almfatal(x) AL::getLogger()->log(AL::LogMessage::t_fatal, x, getName(), __FILE__, __FUNCTION__, __LINE__)

// Scoped log macro.
// Generates a debug log when created and destroyed,
// informing a begin or end of scope.
#define SCOPEDLOG AL::ALScopedLog scopedLog(__FILE__,__FUNCTION__, __LINE__);

/* DEPRECATED!
 * Use this to replace the getLoggerProxy->debug(...). This does exact the same,
 * but doesn't need to make a proxy call. This macros were created to help in
 * the transaction to the new logging system.
 * FROM NOW ON USE ONLY ALM<level>, AL<level> OR ALS<level>!!
 * If a log is called from a module, use alm<level> macros. If not, use al<level>
 * or als<level> ones.
 * Note that this calls using allogger_<level> will be considered as logs called
 * from the module passed as parameter.
 * NOTE: You may want to use alm<level> outside a module when the function is
 * doing a work for the module even it doesn't belong to it. In that case,
 * there must be a function called getName() callable from within its scope.
 */
#define allogger_debug(module, x) AL::getLogger()->log(AL::LogMessage::t_debug, x, module)
#define allogger_info(module, x) AL::getLogger()->log(AL::LogMessage::t_info, x, module)
#define allogger_warning(module, x) AL::getLogger()->log(AL::LogMessage::t_warning, x, module)
#define allogger_error(module, x) AL::getLogger()->log(AL::LogMessage::t_error, x, module)
#define allogger_fatal(module, x) AL::getLogger()->log(AL::LogMessage::t_fatal, x, module)

// NO NEED FOR THIS ANYMORE!! DEPRACATED!!
#define LOGINFOBEGIN AL::ALStreamLog(AL::LogMessage::t_info, __FILE__,__FUNCTION__, __LINE__).self()
#define LOGDEBUGBEGIN AL::ALStreamLog(AL::LogMessage::t_debug, __FILE__,__FUNCTION__, __LINE__).self()
#define LOGWARNINGBEGIN AL::ALStreamLog(AL::LogMessage::t_warning, __FILE__,__FUNCTION__, __LINE__).self()
#define LOGERRORBEGIN AL::ALStreamLog(AL::LogMessage::t_error, __FILE__,__FUNCTION__, __LINE__).self()
#define LOGFATALBEGIN AL::ALStreamLog(AL::LogMessage::t_fatal, __FILE__,__FUNCTION__, __LINE__).self()
#define LOGBEGIN AL::ALStreamLog(AL::LogMessage::t_info, __FILE__,__FUNCTION__, __LINE__).self()

// NO NEED FOR THIS ANYMORE!! DEPRACATED!!
#define alslogend ""
#define LOGEND ""
#define L0GDEBUGEND ""
#define LOGERROREND ""
#define LOGWARNINGEND ""
#define LOGFATALEND ""
#define alsinfoend ""
#define alsdebugend ""
#define alswarningend ""
#define alserrorend ""

namespace AL
{
  class LIBSYSLOGAPI ALLog
  {
  public:
    /**
     * LogSignal. Callable receiving the following parameters:
     * @param log The log message.
     */
    typedef boost::signal<void (boost::shared_ptr<LogMessage> pLog) > LogSignal;

    /// Connection returned by signal.connect()
    typedef boost::signals::connection Connection;
    /// Map used to store and track current connections.
    typedef std::map<std::string, Connection> MapConnection;

    /**
     * Default Constructor
     */
    ALLog();

    virtual ~ALLog();

    /**
     * Log a string. Output (stdout, syslog...) depend on functors connected to
     * the log signal.
     * @param level { t_debug, t_info, t_warning, t_error, t_fatal, t_silent }
     * @param log string with log
     * @param file file, often __FILE__
     * @param function function, often __FUNCTION__ (depend on compilator)
     * @param line line of log, often __LINE__
     */
    void log(
        const LogMessage::Level& pLevel,
        const std::string& pMessage,
        const char* pFile = NULL,
        const char* pFunction = NULL,
        unsigned long pLine = 0);

    /**
     * Version using std::string for pFile and pFunction
     */
    void log(
        const LogMessage::Level& pLevel,
        const std::string& pMessage,
        const std::string& pFile,
        const std::string& pFunction,
        unsigned long pLine);

    /**
     * Log a module message.
     * @param level { t_debug, t_info, t_warning, t_error, t_fatal, t_silent }
     * @param log string with log
     * @param module name of the module
     * @param file name of the file from within it's called.
     * @param function name of the function from within it's called.
     * @param line line number.
     */
    void log(
        const LogMessage::Level& pLevel,
        const std::string& pMessage,
        const std::string& pModule,
        const std::string& pFile,
        const std::string& pFunction,
        unsigned long pLine);

    /**
     * Version using const char* for file and function.
     */
    void log(
        const LogMessage::Level& pLevel,
        const std::string& pMessage,
        const std::string& pModule,
        const char* pFile = NULL,
        const char* pFunction = NULL,
        unsigned long pLine = 0);

    /**
     * Connect new functor to the log signal.
     * @param functor that take a const LogMessage& as parameter
     * @param id used to register functor and to be able to disconnect it later
     */
    void connect(const LogSignal::slot_type& pLogFunction, const std::string& pId);

    /**
     * Remove the supplied handler id from it's notifiers
     * @param id used to register functor
     */
    void disconnect(const std::string& id);

    /**
     * Sets the log level
     * @param level { t_debug, t_info, t_warning, t_error, t_fatal, t_silent }
     */
    void setLogLevel(const LogMessage::Level& level);

    /**
     * @return the current log level
     */
    LogMessage::Level logLevel() const { return fLogLevel; }

    /**
     * setFilter.
     * @param pFilter display only log with pFilter string. Pass empty string
     * to disable this feature.
     */
    void setFilter(const std::string& pFilter);

  private:
    /**
     * Verbosity level of the logger.
     */
    LogMessage::Level fLogLevel;

    /**
     * Display only the logs containing fFilter.
     */
    std::string fFilter;

    /**
     * Signal on log function
     */
    LogSignal flogSignal;

    /**
    * Used to keep trace of current functions used by the logger;
    */
    MapConnection fConnections;

  private:
#ifdef WIN32
    /**
     * xTextColor Have fun with windows output
     * @param fontcolor font color
     * @param backgroundcolor background color
     * @param screenHandle screenHandle
     */
    void xTextColor(int fontcolor, int backgroundcolor, void * screenHandle);
#endif
  };

  extern LIBSYSLOGAPI ALLog* getLogger(void);

  // Note: VS2010 does not accept having an STL base class on an exported class.
  // This is the reason for all the pass-through methods to the stringstream member.
  class LIBSYSLOGAPI ALStreamLog
  {
  public:
    /**
    * ALStreamLog. Will log at object destruction.
    * @param pLevel { t_debug, t_info, t_warning, t_error, t_fatal, t_silent}
    * @param pFile __FILE__
    * @param pFunction __FUNCTION__
    * @param pLine __LINE__
    */
    ALStreamLog(
                const LogMessage::Level& pLevel,
                const char* pFile,
                const char* pFunction,
                int pLine);

    virtual ~ALStreamLog();

    template <typename T>
      ALStreamLog& operator<< (T& val ) { fStream << val; return self(); }

    template <typename T>
      ALStreamLog& operator<< (const T& val ) { fStream << val; return self(); }

    ALStreamLog& operator<< (ALStreamLog& val) { fStream << val.fStream.str(); return self(); }
    ALStreamLog& operator<< ( std::ostream& (*f)(std::ostream&) ) { fStream << f; return self(); }

    // necessary to have sinfo et al. work with an anonymous object
    ALStreamLog& self() { return *this; }

  protected:
    LogMessage::Level fLevel;
    const char* fFile;
    const char* fFunction;
    int fLine;
    std::stringstream fStream;
  };


  class LIBSYSLOGAPI ALScopedLog : public ALStreamLog
  {
  public:
    /**
    *
    * @param pLevel { t_debug, t_info, t_warning, t_error, t_fatal, t_silent}
    * @param pFile __FILE__
    * @param pFunction __FUNCTION__
    * @param pLine __LINE__
    */
    ALScopedLog(
      const char* pFile,
      const char* pFunction,
      int pLine);

    virtual ~ALScopedLog();
  };

}

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif  // _LIB_ALLOG_ALLOG_ALLOG_H_
