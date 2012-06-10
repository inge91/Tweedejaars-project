#pragma once

#ifndef _LIB_ALLOG_ALLOG_WRITETOFILE_H_
#define _LIB_ALLOG_ALLOG_WRITETOFILE_H_


#include <allog/alloghandler.h>
#include <boost/shared_ptr.hpp>
#include <stdio.h>
#include <altools/tools.h>
#include <boost/filesystem.hpp>
#include <qi/os.hpp>

namespace AL
{
  /**
   * This class is the handler used to write logs to files.
   */
  class WriteToFile
  {
  public:
    /**
     * Constructor
     * @param pFilePath The path of the file we want to log in.
     */
    WriteToFile(const boost::filesystem::path& pFilePath, int pVerbosity)
      : fVerbosity(pVerbosity)
    {
      // Create the directory!
      boost::filesystem::create_directories(pFilePath.parent_path());
      // Open the file.
      FILE* file = qi::os::fopen(pFilePath.string().c_str(), "w");
      // If it succeedded, create an boost::shared_ptr using fclose as destructor.
      if(file)
      {
        fFile = boost::shared_ptr<FILE>(file, fclose);
      }
    }

    /**
     * The function called each time a new log is avaiable.
     * @param pLog The log message we want to write.
     */
    void operator ()(boost::shared_ptr<LogMessage> pLog)
    {
      const std::string strLog = pLog->toString(fVerbosity);
      fprintf(fFile.get(), "%s: %s", ALTools::TimeStamp().c_str(), strLog.c_str());
    }

    /**
     * This can be used to test if it was successfully created.
     */
    bool fileIsOpen()
    {
      return (fFile.get() != NULL);
    }

  private:
    boost::shared_ptr<FILE> fFile;
    int fVerbosity;
  };

} // namespace AL

#endif  // _LIB_ALLOG_ALLOG_WRITETOFILE_H_
