#pragma once

#ifndef ALLOGPUBLISHER_H_
# define ALLOGPUBLISHER_H_

# include <boost/circular_buffer.hpp>
# include <boost/thread/thread.hpp>
# include <boost/thread/condition_variable.hpp>
# include <zmq.hpp>

# include <qi/log.hpp>
# include <qi/os.hpp>
# include <allogremote/alremotemessage.h>

namespace AL
{
  /**
   * This class is responsible for sending the logs stocked in the buffer.
   * It waits until a new message is avaible to send it.
   * It's also responsible for thread safe access to the underlying buffer.
   */
  class ALLogPublisher
  {
  public:
    typedef boost::circular_buffer<boost::shared_ptr<ALRemoteLogMessage> > ContainerType;

    /**
     * Constructor.
     * @param pForwarderAddress Input ZMQ address of the LogForwarder.
     */
    ALLogPublisher(const std::string& pForwarderAddress);

    /**
     * Destructor.
     */
    ~ALLogPublisher();

    /**
     * Add new log to the buffer.
     * @param item. New log value.
     */
    void publishLogMessage(const qi::log::LogLevel verb,
                           const qi::os::timeval   date,
                           const char              *category,
                           const char              *msg,
                           const char              *file,
                           const char              *fct,
                           const int               line);

    /**
     * Call this to stop the thread execution.
     */
    bool stopLogging();

    /**
     * Thread loop, responsible for sending the logs stored in the buffer
     * to the LogForwarder.
     */
    void run();

    /**
     * Functor used to convert a LogMessage into a ZMQ Message.
     * @param pLog The LogMessage to be converted.
     * @param The ZMQ Message that will contain the log message.
     */
    class ConvertLogMessageToZMQMessage
    {
    public:
      ConvertLogMessageToZMQMessage(boost::shared_ptr<ALRemoteLogMessage>& pLog,
                                    zmq::message_t& pMsg);

    private:
      /**
       * Convert a LogMessage::Level into a unsigned long
       * @param level debug = 6, verbose = 5, info = 4, warning = 3, error = 2,
       * fatal = 1, silent = 0
       */
      unsigned long levelToInt(qi::log::LogLevel pLevel);


      void xWrite(unsigned long pValue);
      void xWrite(const char* pValue);
      void xWrite(const std::string& pValue);

      zmq::message_t* fMsg;
      unsigned long fPos;
    };

  private:
    /**
     * The buffer capacity.
     */
    static const int fCapacity;

    /**
     * Input ZMQ address of the LogForwarder.
     */
    std::string fForwarderAddress;

    /**
     * Boolean used to loop the thread. If it's false the thread finishes.
     */
    bool fKeepRunning;

    /**
     * The log buffer.
     */
    ContainerType fContainer;

    /**
     * Mutex used to control access to the underlying buffer.
     */
    boost::mutex               pubMutexWriteLock;


    /**
     * Condition used to wait until data is avaiable to send.
     */
    boost::condition_variable  pubReadyCond;

    /**
     * Thread used to do not block the main naoqi process
     */
    boost::thread  fThread;
  };
}
#endif  // !ALLOGPUBLISHER_H_
