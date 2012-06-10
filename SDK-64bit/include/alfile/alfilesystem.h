/**
* @author Aldebaran Robotics
* Copyright (c) Aldebaran Robotics 2007, 2011 All Rights Reserved
*/

/**
* This class encapsultate boost filesystem
*/


#pragma once

#ifndef _LIB_ALFILE_ALFILE_ALFILESYSTEM_H_
#define _LIB_ALFILE_ALFILE_ALFILESYSTEM_H_

#ifdef BOOST_FILESYSTEM_VERSION
#undef BOOST_FILESYSTEM_VERSION
#endif

#define BOOST_FILESYSTEM_VERSION 2

#include <qi/macro.hpp>
//QI_DEPRECATED_HEADER(Please use qi::path and boost::filesystem instead)
#include <exception>
#include <vector>
#include <alerror/alerror.h>
#include <altools/alsystem.h>
#include <ctime>
#include <alfile/alpath.h>

#include <sys/stat.h>
#ifndef WIN32
#include <fcntl.h>
#endif

namespace AL
{
  typedef boost::filesystem::basic_filesystem_error<ALPath> ALFileSystemError;

  class ALFileSystem
  {
  public:

    /**
     * Can be thrown by any method of ALFileSystem.
     */
    class Exception : public ALError {

      public:
        Exception (const std::string& method, const std::string& msg, const std::string& file, int line);

        virtual ~Exception () throw ();
    };

    typedef enum {
      DIRECTORY,
      REGULAR_FILE,
      UNKNOWN
    } FileType;

    /*
    * Creates a directory.
    * @param pPath directory path
    */
    static bool createDirectory(const ALPath& pPath);

    /*
    * Creates several directories to complete a given path.
    * @param pPath directory path
    */
    static bool createDirectories(const ALPath& pPath);

    /*
    * Change path to OS compatible path.
    * @param pPath path to convert
    */
    static std::string formatPath(const std::string& pPath);

    /*
    * Return file extention
    * @param pPath path to convert
    */
    static std::string getExtension(const ALPath& pPath);


    /*
    * get parent path
    * @param pPath path to get parent
    */
    static ALPath parentPath(const ALPath& pPath);

    /*
     * return a normalized, absolute path from whatever path.
     * @param pPath: refererence to the path to be normalized
     */
    static ALPath absolutePath(const ALPath& pPath);

    /*
    * check if file exist
    * @param full file path
    */
    static bool exists(const ALPath& pDir);

    /**
     * Check if path is a directory.
     * @param pPath the path to check.
     */
    static bool isDirectory (const ALPath& pPath);

    /**
     * Check if path is a regular file.
     * @param pPath the path to check.
     */
    static bool isRegularFile (const ALPath& pPath);

    /**
     * return filename in pPath
     * @param pPath the path to check.
     */
    static std::string fileName(const ALPath& pPath);

    /**
     * Check if path is of type type.
     * @param pPath the path to check.
     * @param pType the type of the path to check.
     */
    static bool isType(const ALPath& pPath, FileType pType);

    /**
     * List directory childs.
     * Put result in out vector.
     * Throws a ALFileSystem::Exception if directory not existing.
     * @param pDir the directory to list.
     * @param out the vector used to push strings.
     */
    static void listDirectory(const ALPath& pDir,
        std::vector<std::pair<FileType, std::string> >& out);

    /**
     * Remove a path.
     * same effect as POSIX remove.
     */
    static bool remove(const ALPath& pPath);

    /**
     * Remove directory and its childs.
     */
    static bool removeAll(const ALPath& pPath);

    static bool copyFile(const ALPath& pFromPath, const ALPath& pToPath);

    static bool rename(const ALPath& pFromPath, const ALPath& pToPath);

    /**
    * lastDate last modification date
    * @param pFile. Path + filename
    */
    static std::time_t lastDate(const ALPath& pFile);

    static ALPath deducePath(ALPath pSourcePath)
    {
      while (!pSourcePath.empty())
      {
        if (!ALFileSystem::exists(pSourcePath / "preferences" / "DCM.xml"))
        {
          pSourcePath = ALFileSystem::parentPath(pSourcePath);
        }
        else
        {
          return pSourcePath;
        }
      }
      return ALPath();
    }

    static ALPath getALPath(void)
    {
      ALPath result = deducePath(ALPath(ALSystem::getCurrentDir()));
      if (result.empty())
      {
        return deducePath(ALSystem::getEnv("AL_DIR"));
      }
      if (result.empty())
      {
        // will only check the first entry in pythonpath, this is ninja magic
        return deducePath(ALSystem::getEnv("PYTHONPATH"));
      }
      return result;

    }

    /**
     * Assuming you are in a executable in sdk/bin/foo, get the
     * absolute path to sdk, using argv[0].
     */
    static ALPath getSDKPath(const std::string& pArgvZero);


    static ALPath getFileCompletePath(const ALPath& pFileRelativePath)
    {
      ALPath completePath;
      if(!xGetCompletePath(pFileRelativePath, completePath))
      {
        std::stringstream ss;
        ss << "File \"" << pFileRelativePath << "\" does not exist in path \""
          << getHomePath() << " or in " <<  getALPath() <<  "\".";
        return ALPath();
      }

      return completePath;
    }



    static bool xGetCompletePath(const ALPath& pFileRelativePath, ALPath& pCompletePath)
    {
      //ALPath pCompletePath = completePath;
      ALPath completePath = getUserNaoQiPath() / pFileRelativePath;
      if(ALFileSystem::exists(completePath))
      {
        pCompletePath = completePath;
        return true;
      }
      completePath = getALPath() / pFileRelativePath;
      if(ALFileSystem::exists(completePath))
      {
        pCompletePath = completePath;
        return true;
      }

      return false; // file does not exist !
    }

    /**
     * Returns home path where files can be written with current user's permissions.
     */
    static ALPath getHomePath(void);

        /**
     * Returns tmp path where temporary files can be written with current user's permissions.
     * create folder if not exist
     */
    static ALPath getTmpPath(void);

    /**
     * Returns naoqi path in home path
     */
    static ALPath getUserNaoQiPath(void);

    /**
     * Returns the path where the user can write configuration files for his modules
     * Deprecated, please use getUserNaoqiPath or getALPath
     */
    static ALPath getNaoQiConfigPath(void);

    /**
     * Returns the path where behaviors are stored.
     */
    static ALPath getBehaviorsPath(void);

    /**
     * Returns the path where box libraries are stored.
     */
    static ALPath getBoxLibrariesPath(void);

    static inline FILE* fopen(const ALPath& pFilename, const std::string& pMode);
    static inline int open(const ALPath& pFilename, int pFlags, int pMode);
    static inline int stat(const ALPath& pFilename, struct stat* pStat);
  };

  FILE* ALFileSystem::fopen(const ALPath& pFilename, const std::string& pMode)
  {
#ifdef _WIN32
    return ::_wfopen(pFilename.external_file_string().c_str(), ALPathTraits::to_external(pFilename, pMode).c_str());
#else
    return ::fopen(pFilename.external_file_string().c_str(), ALPathTraits::to_external(pFilename, pMode).c_str());
#endif
  }

  int ALFileSystem::open(const ALPath& pFilename, int pFlags, int pMode)
  {
#ifdef _WIN32
    return ::_wopen(pFilename.external_file_string().c_str(), pFlags, pMode);
#else
    return ::open(pFilename.external_file_string().c_str(), pFlags, pMode);
#endif
  }

  int ALFileSystem::stat(const ALPath& pFilename, struct stat* pStat)
  {
#ifdef _WIN32
    struct _stat buffer;
    int result = ::_wstat(pFilename.external_file_string().c_str(), &buffer);
    pStat->st_gid = buffer.st_gid;
    pStat->st_atime = buffer.st_atime;
    pStat->st_ctime = buffer.st_ctime;
    pStat->st_dev = buffer.st_dev;
    pStat->st_ino = buffer.st_ino;
    pStat->st_mode = buffer.st_mode;
    pStat->st_mtime = buffer.st_mtime;
    pStat->st_nlink = buffer.st_nlink;
    pStat->st_rdev = buffer.st_rdev;
    pStat->st_size = buffer.st_size;
    pStat->st_uid = buffer.st_uid;
    return result;
#else
    return ::stat(pFilename.external_file_string().c_str(), pStat);
#endif
  }

} // namespace AL

#endif  // _LIB_ALFILE_ALFILE_ALFILESYSTEM_H_
