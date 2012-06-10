// Generated for ALInfrared version 1.12


#ifndef ALINFRAREDPROXYPOSTHANDLERREMOTE_H_
#define ALINFRAREDPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALInfraredProxyRemote;

/// <summary>This module works with Linux Infrared Remote Control (LIRC) in order to emit/receive IR remotes keys or to emit/receive IR information to/from an other Nao.</summary>
class ALInfraredProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALInfraredProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// This module works with Linux Infrared Remote Control (LIRC) in order to emit/receive IR remotes keys or to emit/receive IR information to/from an other Nao.
    /// ALInfraredPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALInfraredProxyPostHandlerRemote() : fParent(NULL)
    {}







    /// <summary>
    /// Rewrite the LIRC daemon configuration file (lircd.conf) with everyremotes configuration concatenated, and reload it in LIRC daemons
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int confRemoteRecordSave()
    {
      return fParent->pCall("confRemoteRecordSave");
    }

    /// <summary>
    /// Start remote record process.
    /// </summary>
    /// <param name="Rm_name"> Name of the remote control to reccord. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int confRemoteRecordStart(const std::string& Rm_name)
    {
      return fParent->pCall("confRemoteRecordStart" , Rm_name);
    }

    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int exit()
    {
      return fParent->pCall("exit");
    }






    /// <summary>
    /// Init IR reception (connect as a client to the LIRC daemon).
    /// </summary>
    /// <param name="RepeatThreshold"> Give the keep-pressing threshold after which the repetition of a key is taken into consideration. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int initReception(const int& RepeatThreshold)
    {
      return fParent->pCall("initReception" , RepeatThreshold);
    }



    /// <summary>
    /// Send 4 octets by IR.
    /// </summary>
    /// <param name="Data_IR"> 4 octets to send through IR. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int send32(const std::string& Data_IR)
    {
      return fParent->pCall("send32" , Data_IR);
    }

    /// <summary>
    /// Send 4 octets by IR.
    /// </summary>
    /// <param name="Octet1"> Octet 1 to send through IR. </param>
    /// <param name="Octet2"> Octet 2 to send through IR. </param>
    /// <param name="Octet3"> Octet 3 to send through IR. </param>
    /// <param name="Octet4"> Octet 4 to send through IR. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int send32(const int& Octet1, const int& Octet2, const int& Octet3, const int& Octet4)
    {
      return fParent->pCall("send32" , Octet1, Octet2, Octet3, Octet4);
    }

    /// <summary>
    /// Send 1 octet by IR.
    /// </summary>
    /// <param name="Octet"> octet to send through IR. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int send8(const int& Octet)
    {
      return fParent->pCall("send8" , Octet);
    }

    /// <summary>
    /// Send an IP by IR.
    /// </summary>
    /// <param name="IP"> IP adress to send through IR. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int sendIpAddress(const std::string& IP)
    {
      return fParent->pCall("sendIpAddress" , IP);
    }

    /// <summary>
    /// Simulate a remote control (Nao as a remote control).
    /// </summary>
    /// <param name="Remote"> IR remote control name. </param>
    /// <param name="Key"> IR remote control key name. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int sendRemoteKey(const std::string& Remote, const std::string& Key)
    {
      return fParent->pCall("sendRemoteKey" , Remote, Key);
    }

    /// <summary>
    /// Simulate a remote control (Nao as a remote control).
    /// </summary>
    /// <param name="Remote"> IR remote control name. </param>
    /// <param name="Key"> IR remote control key name. </param>
    /// <param name="pTimeMs"> The time in ms when the remote key must be send. 0 deals like sendRemoteKey </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int sendRemoteKeyWithTime(const std::string& Remote, const std::string& Key, const int& pTimeMs)
    {
      return fParent->pCall("sendRemoteKeyWithTime" , Remote, Key, pTimeMs);
    }

    /// <summary>
    /// returns true if the method is currently running
    /// </summary>
    /// <param name="id"> the ID of the method to wait for </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int stop(const int& id)
    {
      return fParent->pCall("stop" , id);
    }



};

}
#endif // ALINFRAREDPROXYPOSTHANDLERREMOTE_H_

