#pragma once

#ifndef ALFORWARDER_H_
# define ALFORWARDER_H_

# include <boost/thread/thread.hpp>
# include <string>

namespace AL
{
  /**
   * ALForwarder
   * This class is responsible for forwarding ZMQ messages
   * from the connected publishers to the subscribers.
   */
  class ALForwarder
  {
  public:
    /**
     * Constructor.
     * @param pInAddress ZMQ Address for publishers connections.
     * @param pOutAddress ZMQ Address for subscribers connections.
     */
    ALForwarder(const std::string& pInAddress,
                const std::string& pOutAddress);

    /**
     * Thread loop, responsible for forwarding ZMQ messages.
     */
    void run();

  private:
    /**
     * Address for publishers connections.
     */
    std::string fInputAddress;

    /**
     * Address for subscribers connections.
     */
    std::string fOutputAddress;

    /**
     * Thread used to do not block the main naoqi process
     */
    boost::thread  fThread;
  };
}
#endif  // !ALFORWARDER_H_
