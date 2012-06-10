#pragma once

#ifndef ALLOGSUBSCRIBER_H_
# define ALLOGSUBSCRIBER_H_

# include <boost/shared_ptr.hpp>
# include <zmq.hpp>

# include <allogremote/alremotemessage.h>
# include <qi/log.hpp>
# include <qi/os.hpp>

namespace AL
{
  /**
   * This class implements a generic ALLogSubscriber.
   * You must inherit it and redefine the logMessageReady function.
   */
  class ALLogSubscriber
  {
  public:
    /**
     * Constructor.
     * @param pForwarderAddress Output ZMQ address of the LogForwarder.
     */
    ALLogSubscriber(const std::string& pForwarderAdress);

    /**
     * Destructor.
     */
    ~ALLogSubscriber();

    /**
     * This function is called every time a new log was received.
     * @param pLog New log value.
     */
    virtual void logMessageReady(const qi::log::LogLevel verb,
                                 const qi::os::timeval   date,
                                 const char              *category,
                                 const char              *msg,
                                 const char              *file = "",
                                 const char              *fct = "",
                                 const int               line = 0) = 0;

    /**
     * Call this to stop the thread execution.
     * This will block until the thread has completely finished!
     */
    bool stopLogging();

    /**
     * Thread loop, responsible for receiving from the LogForwarder.
     */
    void run();

    /**
     * Functor used to convert a ZMQ Message into a LogMessage.
     * @param The ZMQ Message to be converted.
     * @param pLog The LogMessage that will contain the log message.
     */
    class ConvertZMQMessageToLogMessage
    {
    public:
      ConvertZMQMessageToLogMessage(zmq::message_t& pMsg,
                                    boost::shared_ptr<ALRemoteLogMessage>& pLog);

    private:
      /**
       * Convert a unsigned long into a LogMessage::Level
       * @param level debug = 6, verbose = 5, info = 4, warning = 3, error = 2,
       * fatal = 1, silent = 0
       */
      qi::log::LogLevel intToLevel(unsigned long pLevel);


      template<typename T>
      T xRead();

      zmq::message_t* fMsg;
      unsigned long fPos;
    };

  private:
    /**
     * Boolean used to loop the thread. If it's false the thread finishes.
     */
    bool fKeepRunning;

    /**
     * Output ZMQ address of the LogForwarder.
     */
    std::string fForwarderAddress;

    /**
     * ZMQ context for the sockets.
     */
    boost::shared_ptr<zmq::context_t> fContext;

  };

  template<>
  unsigned long ALLogSubscriber::ConvertZMQMessageToLogMessage::xRead();

  template<>
  std::string ALLogSubscriber::ConvertZMQMessageToLogMessage::xRead();
}
#endif  // !ALLOGSUBSCRIBER_H_
