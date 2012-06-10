/**
 * @author Aldebaran Robotics
 *
 */

#ifndef BONJOUR_DISCOVERY_H
#define BONJOUR_DISCOVERY_H

#include <boost/shared_ptr.hpp>
#include <map>
#include <list>
#include <string>

#include <boost/signal.hpp>
//#include <boost/bind.hpp>

namespace AL
{
  class ALMutexRW;
  class BonjourProfile;

  class BonjourDiscovery
  {
  public:
    typedef std::map<std::string, boost::shared_ptr<BonjourProfile> > TProfileMap;
    typedef TProfileMap::iterator                         ITProfileMap;
    typedef TProfileMap::const_iterator                   CITProfileMap;

    // If someone wants to add information in profile, such as IP, he's allowed to !
    // User should het the mutex before writing anything in the profile.
    typedef boost::signal<void (boost::shared_ptr<BonjourProfile>)> ProfileSignal;

  public:
    /**
     * Declare to bonjour on given port. Name used is host name
     * Returns true if restart is needed (always false on robot, as restart is automatic)
     */
    static bool sayBonjour(int port);

    /**
     * listen bonjour from another nao
     * @return True if ok
     */
    static bool startListening();

    /**
     * Stop the listen event loop of bonjour.
     */
    static void stopListening();

    /**
     * Stop the say event loop of bonjour.
     */
    static void stopSayBonjour();

    /**
     * Return the map of robots. Note that you have to lock the mutex before calling this method
     * Otherwise, something back could happen (crash ?)
     */
    static const TProfileMap& getMap();

    /**
     * Print number of services, and info on each service.
     */
    static void printServices();

    // add a service to a profile. Create a profile if needed
    static void addService(const std::string& pName,
        const std::string& pServiceName,
        int pPort);

    // remove a service from a profile. if pServiceName is a nao service, then just remove the whole profile
    static void removeService(const std::string& pName,
        const std::string& pServiceName,
        int pPort);

    // is this name a robot ? Meaning, has it been declared on nao service or not ?
    static bool isRobot(const std::string& pName);

    // does this name has already been declared on any service ?
    static bool hasProfile(const std::string& pName);

    /**
     * This mutex is needed if someone wants to do anything with fNaosMap,
     * or with the map returned by getMap(). Always use it in both case !!
     */
    static boost::shared_ptr<ALMutexRW> naosMapMutex() {
        return fNaosMapMutex;
    }

    static void atAddProfile(ProfileSignal::slot_function_type subscriber)
    {
        fAddProfile.connect(subscriber);
    }

    static void atRemoveProfile(ProfileSignal::slot_function_type subscriber)
    {
        fRemoveProfile.connect(subscriber);
    }

  private:
    /**
     * Store nao on network
     */
    static TProfileMap        fNaosMap;

    static boost::shared_ptr<ALMutexRW>   fNaosMapMutex;

    static ProfileSignal      fAddProfile;
    static ProfileSignal      fRemoveProfile;

  public:
    static const int fDefaultNaoQiPort; //used on Linux, because we do not seem to be able to get the port.
    static const int fDefaultNaoPort; //used on Linux, because we do not seem to be able to get the port.
    static const std::string fDomain;
    static const std::string fNaoQiServiceType;
    static const std::string fNaoServiceType;
  };
}

#endif // BONJOUR_DISCOVERY_H
