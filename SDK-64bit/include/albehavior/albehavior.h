/**
* @author Aldebaran Robotics
* Aldebaran Robotics (c) 2007 All Rights Reserved
*/

/**
* The class that implements a Choregraphe box.
* A behavior is an entity that have inputs and outputs.
* So he can be enabled and produce events.
*/


#pragma once

#ifndef _LIB_ALBEHAVIOR_ALBEHAVIOR_ALBEHAVIOR_H_
#define _LIB_ALBEHAVIOR_ALBEHAVIOR_ALBEHAVIOR_H_

#include <alcommon/almodulecore.h>
#include <alvalue/alvalue.h>
#include <alresource/alhierarchyowner.h>
#include <list>

namespace AL
{
  class ALBroker;
  class ALMemoryProxy;
  class ALProxy;
  class ALMutexRW;
  class ALOwner;

  struct Parameter
  {
    ::AL::ALValue value;
    bool inheritFromParent;

    Parameter() : inheritFromParent(false) {}
    Parameter(const ::AL::ALValue& pValue, bool pInheritFromParent): value(pValue),
      inheritFromParent(pInheritFromParent) {}
  };

  class ALBehavior: public ALModuleCore, public ALHierarchyOwner
  {
  protected:

    // state of the behavior
    enum State
    {
      ENABLED,   // (all subscription done)
      DISABLED,  // (none done)
      PARTIAL    // (some of them done)
    };

  public :

    //
    // ALBehavior type definition
    //
    bool isParent(boost::shared_ptr<ALHierarchyOwner> pOwner);
    std::string getOwnerName(){return getName();}

    class IO
    {
      // a link/input/output class.
      // It stores the name of the IO, and the type.

    public:

      IO(const std::string & pName, bool pIsBang) : fName(pName),
        fIsBang(pIsBang)
      {
        // NOTHING
      }

      bool operator<(const ::AL::ALBehavior::IO& io) const {return fName < io.fName;}

    public:

      const std::string   fName;
      const bool          fIsBang; // always false for inputs !
    };

    typedef ::AL::ALBehavior::IO            TInput;
    typedef ::AL::ALBehavior::IO            TOutput;

    /**
    * for each input, keep a list of ALMemory's value to which
    * the input is subscribed.
    */
    typedef std::list<std::string>          TListValues;
    typedef TListValues::iterator           ITListValues;
    typedef TListValues::const_iterator     CITListValues;

    typedef std::map<TInput, TListValues>   TInputMap;
    typedef TInputMap::iterator             ITInputMap;
    typedef TInputMap::const_iterator       CITInputMap;

    typedef std::map<TOutput, TListValues>  TOutputMap;
    typedef TOutputMap::iterator            ITOutputMap;
    typedef TOutputMap::const_iterator      CITOutputMap;

    typedef std::map<std::string, Parameter>    TParameterMap;
    typedef TParameterMap::iterator             ITParameterMap;
    typedef TParameterMap::const_iterator       CITParameterMap;

    // do something a little different, as parameters are a lot less often subscribed to anything !
    // and it's easier to manipulate std::string for parameters, in order to use ALBehavior API.
    typedef std::map<std::string, TListValues>          TParameterSubscriptionMap;
    typedef TParameterSubscriptionMap::iterator         ITParameterSubscriptionMap;
    typedef TParameterSubscriptionMap::const_iterator   CITParameterSubscriptionMap;

    //
    // ALBehavior method definition
    //

  public :

    /*
    * Creates an ALModule. An ALModule has a name.
    * @param pName the behavior name
    */
    ALBehavior(boost::shared_ptr<ALBroker> pBroker, const std::string& pName);

    /**
    * Wait a resource
    * @param pList: resource name list
    * @param pCallback: callback if loose resource
    * @param pTimeout: timeout if wait resource
    * @param  pOwnerType (unused)
    */
    void waitFor(const std::vector<std::string>& pList , const char *pCallback , int pTimeout, int pOwnerType);

    /**
    * Wait his resource but never take resource to someone else
    */
    void waitResourceFree();

    /**
    * Wait box resources and take it if possible
    */
    void waitResources();

    /**
    * setResources
    * @param pList: resource name list to store
    */
    void setResources(const std::vector<std::string>& pList, const int &pTimeout);

    /**
    * isResourceFree
    * @param pList: resource name list
    * @return true if box resources free
    */
    bool isResourceFree(const std::vector<std::string>& pList);

    /**
    * releaseResource Release box resources

    */
    void releaseResource();

    /**
    * Exit method, overload ALModule::exit
    */
    virtual void exit();

    virtual void init();

    /**
    * Will enable or disable a behavior.
    * When switching from one state to another, all the subscription will be done/undone.
    */
    void setEnabled(const bool& pEnabled);

    /**
    * return true if state is ENABLED, false otherwise
    */
    bool isEnabled();

    /**
    * A behavior can have a parent (hierarchy in Choregraphe !)
    * Using a string (name) instead of a pointer as we can come from either Urbi or Python !
    */
    void setParentFromName(const std::string& p);

    /**
    * Returns the input/ouput names !
    */
    std::vector<std::string> getInputNames();
    std::vector<std::string> getOutputNames();

    /**
    * addInput. Add a new input to this behavior
    * @param pInputName input name !
    * @return true if input added (false if an in put with the same name already exists
    */
    bool addInput(const std::string & pInputName);

    /**
    * addOutput. Add a new output to this behavior
    * @param pOutputName output name !
    * @param pbIsBang is it a bang type ?
    * @return true if input added (false if an in put with the same name already exists
    */
    bool addOutput(const std::string & pOutputName, bool pIsBang);

    /**
    * addParameter. Add a new parameter to this behavior
    * @param pParameterName parameter name !
    * @param pValue value of parameter
    * @param pInheritFromParent do we want to inherit from parent
    */
    void addParameter(const std::string & pParameterName, const ::AL::ALValue& pValue, const bool& pInheritFromParent);

    /**
    * Returns current value of a given parameter.
    * Throw an exception if parameter does not exist.
    * Method is bound, and thus cannot be const :-(
    */
    ALValue getParameter(const std::string& pParameterName);

    /**
    * Returns the list of parameters.
    */
    std::vector<std::string> getParametersList();

    /**
    * Returns true if box has a parameter of this name, false otherwise.
    */
    bool hasParameter(const std::string& pParameterName);

    /**
    * Set a given parameter to a new value.
    * Throw an exception if parameter does not exist.
    */
    void setParameter(const std::string& pParameterName, const ::AL::ALValue& pValue);

    /**
    * We can set several Parameters at the same time.
    * The ALValue needs to be [[name, value]]
    */
    void setParameters(const ::AL::ALValue& pValue);



    /**
    * addLink. Add a connection between an ALMemory value and one input, it's a kind of trigger for this behavior: when a value in ALMemory change, the value is send to an input of this behavior.
    * @param pInputName name of an input
    * @param pALMemoryValueName name of the ALMemory that will
    * throw an exception if something goes wrong
    */
    void addLink(const std::string & pInputName,
      const std::string & pALMemoryValueName);

    /**
    * addLink. Add a connection between an ALMemory value and one parameter.
    * Any change to given value will update parameter accordingly.
    * @param pParameterName name of a parameter
    * @param pALMemoryValueName name of the ALMemory that will
    * throw an exception if something goes wrong
    */
    void addParameterLink(const std::string & pParameterName,
      const std::string & pALMemoryValueName);

    /**
    * removeLink. remove a link created by the addLink method. It does not unsubscribe to anything.
    * It is up to the other to call setEnabled afterwards !
    * @param pInputName name of an input
    * @param pALMemoryValueName name of the ALMemory that will be removed
    * throw an exception if something goes wrong
    */
    void removeLink(const std::string & pInputName,
      const std::string & pALMemoryValueName);


    bool isResourceOwnedByParent(const std::vector<std::string>& pList, std::string &parentName);

    /**
    * addOutputLink. Add a link between an inner value and an output.
    * Whenever the value changed, the matching output is stimulated.
    * @param pOutputName name of an output
    * @param pALMemoryValueName name of the ALMemory that will be removed
    * throw an exception if something goes wrong
    */
    void addOutputLink(const std::string & pOutputName,
      const std::string & pALMemoryValueName);

    /**
    * removeOutputLink. remove a link created by the addOutputLink method.
    * Unsubscribe to the value before deleting it !
    * @param pOutputName name of an output
    * @param pALMemoryValueName name of the ALMemory that will be removed
    * throw an exception if something goes wrong
    */
    void removeOutputLink(const std::string & pOutputName,
      const std::string & pALMemoryValueName);

    /**
    * dataChanged. Called by stm when subcription
    * has been modified.
    * @param pDataName Name of the modified data
    * @param pValue Name of the modified data
    * @param pMessage Name of the modified data
    */
    virtual void dataChanged(const std::string& pDataName,
      const ::AL::ALValue& pValue,
      const std::string& pMessage);

    virtual std::string httpGet();

    virtual void httpPut(const std::string& pValue);

  protected:
    /**
    * Subscribe or unsubscribe all
    */
    void xSubscribe(bool pSubs);

    //
    // ALBehavior attribut definition
    //

  private:
    boost::weak_ptr<ALBehavior> fParent;
    boost::weak_ptr<ALOwner> fOwner;

  protected:
    boost::shared_ptr<ALMemoryProxy>      fStm;
    boost::shared_ptr<ALProxy>            fToMe;

    // list of inputs & mutex
    TInputMap                 fInputList;
    boost::shared_ptr<ALMutexRW>          fInputListMutex;
    // same for outputs
    TOutputMap                fOutputList;
    boost::shared_ptr<ALMutexRW>          fOutputListMutex;
    // params
    TParameterMap             fParametersMap;
    boost::shared_ptr<ALMutexRW>          fParametersMapMutex;

    // params subscription, separately
    TParameterSubscriptionMap fParametersSubsMap;
    boost::shared_ptr<ALMutexRW>          fParametersSubsMapMutex;

    // store list of values subscribed to, so we can unsubscribe when removing a link.
    // can contain a value twice, if 2 links are connected to an IO.
    std::list<std::string>    fSubscriptions;
    boost::shared_ptr<ALMutexRW>          fSubscriptionsMutex;

    // store ALBehavior current state : enabled, partial or disabled.
    State                     fState;
    boost::shared_ptr<ALMutexRW>          fStateMutex;

    // name of the parent that own my resource
    std::string fParentName;

    // true if someone asked to release resources
    bool fReleaseAsked;

    // box resource list
    std::vector<std::string> fResourceNameList;
    // box resource timeout
    int fTimeoutResource;

    // a string that can hold any data and that will be served on the behavior web page
    std::string fHttpData;
  };

}  // namespace AL

#endif  // _LIB_ALBEHAVIOR_ALBEHAVIOR_ALBEHAVIOR_H_

