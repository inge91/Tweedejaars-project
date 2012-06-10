/**
 * @author Aldebaran Robotics
 *
 */

#ifndef BONJOUR_PROFILE_H
#define BONJOUR_PROFILE_H

#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <list>
#include <string>

namespace AL
{
  class ALMutexRW;

  /**
   * Create a profile.
   * Has a host name that can be different from its name. Host name has to be used to resolve through DNS !
   */
  class BonjourProfile
  {
  public:
    typedef boost::shared_ptr<BonjourProfile>       Ptr;
    typedef std::list<std::pair<std::string, int> > TServiceList;
    typedef TServiceList::iterator                  ITServiceList;
    typedef TServiceList::const_iterator            CITServiceList;

  protected:
    BonjourProfile(const std::string& pName);
  public:
    static BonjourProfile::Ptr createBonjourProfile(const std::string& pName);
    virtual ~BonjourProfile();

    void addService(const std::string& pName, int pPort);

    // if port = -1, remove all services !
    void removeService(const std::string& pName, int pPort);

    inline void setIP(const std::string& IP);

    const AL::ALValue& getBitmapBinary() const;
    bool hasBitmapBinary() const;
    void setBitmapBinary(const AL::ALValue& bitmap);

    /**
     * Returns true if it has any service, false otherwise
     */
    inline bool hasService() const;

    /**
     * Returns true if it has the given service, false otherwise
     */
    bool hasService(const std::string& pName) const;

    /**
     * Returns an iterator to the given service. Can be fServices.end if services is not present.
     */
    CITServiceList getServiceIterator(const std::string& pName) const;

    /**
     * Returns a string describing this profile.
     */
    std::string toString() const;

    inline const std::string& name() const;
    inline const std::string& IP() const;
    inline const TServiceList& services() const;

  private:
    const std::string fName;
    std::string       fIP;
    TServiceList      fServices;

    AL::ALValue           fBitmapBinary;
  public:
    // HAS to be locked manually when using getBitmapBinary
    // more painful to use, but avoid unnecessary copies.
    boost::shared_ptr<ALMutexRW>  fBitmapBinaryMutex;
  };
  inline void BonjourProfile::setIP(const std::string& IP) {fIP = IP;}
  inline bool BonjourProfile::hasService() const {return !fServices.empty();}
  inline const std::string& BonjourProfile::name() const {return fName;}
  inline const std::string& BonjourProfile::IP() const {return fIP;}
  inline const BonjourProfile::TServiceList& BonjourProfile::services() const {return fServices;}

  inline std::ostream& operator<< (std::ostream& pStream, const BonjourProfile& p)
  {
    pStream << p.toString();
    return pStream;
  }
}

#endif // BONJOUR_PROFILE_H
