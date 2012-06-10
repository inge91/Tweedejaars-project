/**
* @author Aldebaran
*/

#ifndef ALPYTHONBRIDGEINTERPRETER_H
#define ALPYTHONBRIDGEINTERPRETER_H
#include <alpythontools/alpython.h>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>

namespace AL
{
  class ALBroker;

  class ALPythonBridgeInterpreter
  {
  protected:
    typedef boost::shared_ptr<ALPythonBridgeInterpreter> Ptr;

    /**
    * Default Constructor.
    */
    ALPythonBridgeInterpreter();

  public:
    /**
     * Smart pointer creation
     */

    static ALPythonBridgeInterpreter::Ptr createALPythonBridgeInterpreter(boost::shared_ptr<ALBroker> pBroker);

    /**
    * Destructor.
    */
    ~ALPythonBridgeInterpreter();

    /**
    * eval python script
    * @return True is all the tests passed
    */
    std::string eval(const std::string& pToEval);

    ALValue evalReturn(const std::string& pToEval);

    ALValue evalFull(const std::string& pToEval);

  private:
    PyThreadState* fSave;
    const std::string fName;
  };

} // namespace AL

#endif // ALPYTHONBRIDGEINTERPRETER_H
