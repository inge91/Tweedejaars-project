#pragma once

#ifndef ALLOGREMOTEHANDLER_H_
# define ALLOGREMOTEHANDLER_H_

# include <allogremote/allogpublisher.h>
# include <boost/shared_ptr.hpp>

namespace AL
{
  class ALLogRemoteHandler
  {
  public:
    /**
     * Default Deconstructor.
     */
    ~ALLogRemoteHandler();

    /**
     * This method create an ALLogPublisher and add it as a
     * handler for the ALLog.
     * @param pInputAddress Input ZMQ address of the LogForwarder.
     */
    void logToForwarder(const std::string& pInputAddress);

    static boost::shared_ptr<ALLogRemoteHandler> getInstance();

    static boost::shared_ptr<ALLogRemoteHandler> setInstance(boost::shared_ptr<ALLogRemoteHandler> pSingleton);

    static void kill();

  protected:
    /**
     * Default Constructor.
     */
    ALLogRemoteHandler() {};


  private:
    static boost::shared_ptr<ALLogRemoteHandler> _singleton;
    /**
     * The ALLogPublisher used by the handler.
     */
    boost::shared_ptr<ALLogPublisher> fPublisher;
  };
}
#endif  // !ALLOGREMOTEHANDLER_H_
