/**
 * @author Jerome Vuarand
 * Copyright (c) Aldebaran Robotics 2010, 2011 All Rights Reserved
 */

#pragma once

#ifndef _LIB_ALPROJECT_SRC_ALPROJECT_ALPROJECT_H_
#define _LIB_ALPROJECT_SRC_ALPROJECT_ALPROJECT_H_

#include <alfile/alpath.h>
#include <alfile/alfilesystem.h>

#include <string>
#include <list>
#include <map>
#include <boost/shared_ptr.hpp>
#include <alerror/alerror.h>
#include <alfile/alpath.h>
#include <boost/filesystem.hpp>
#include "alprojecterror.h"

#ifdef _MSC_VER
#  pragma warning( push )
#  pragma warning( disable : 4290 ) // for ignored throw spec except nothrow
#endif

/* Forward decl */
struct archive; // Libarchive

namespace AL
{

class ALProject
{
public:
  enum ArchiveFormat
  {
    ArchiveFormat_Directory = 0,
    ArchiveFormat_TAR,
    ArchiveFormat_ZIP,
    ArchiveFormat_TAR_GZ,
    ArchiveFormat_TAR_BZ2,
    ArchiveFormat_DEB,

    ArchiveFormat_Count, // upper bound to iterate over values

    // special values
    ArchiveFormat_Default = -1,
    ArchiveFormat_AutoDetect = -2
  };
private:
  ALProject() throw();
  ALProject(const ALProject&) throw();

  static ALPath xCreateTemporaryDirectory() throw(ALProjectError);
  static void xDeleteDirectory(const ALPath& path) throw(ALProjectError);
  static void xClearDirectory(const ALPath& path) throw(ALProjectError);
  static std::list<std::string> xListDirectory(const ALPath& path) throw();
  static std::list<ALPath> xRecursiveListDirectoryFiles(const ALPath& path) throw();
  static void xCleanPath(const ALPath& basePath, const ALPath& relativePath) throw(ALProjectError);
  static void xRemoveFile(const ALPath& path) throw(ALProjectError);
  static void xRemoveDirectory(const ALPath& path) throw(ALProjectError);
  static void xCopyFile(const ALPath& fromPath, const ALPath& toPath) throw(ALProjectError);
  static void xCopyDirectory(const ALPath& fromPath, const ALPath& toPath) throw(ALProjectError);

  static ArchiveFormat xDetectFormat(const ALPath& path) throw();
  static boost::shared_ptr<ALProject> xCreate(const ALPath& path, ArchiveFormat format, bool forceCache) throw(ALProjectError);
  static boost::shared_ptr<ALProject> xLoad(const ALPath& path, ArchiveFormat format, bool forceCache) throw(ALProjectError);
  static void xExtractSimpleArchive(struct archive* archive, const ALPath& pathOut);
  static void xExtractDebianArchive(struct archive* archive, const ALPath& pathOut);

  void xLoad() throw(ALProjectError);
  void xLoadDirectory() throw(ALProjectError);
  void xLoadSimpleArchive() throw(ALProjectError);
  void xLoadDebianPackage() throw(ALProjectError);
  void xSave(const ALPath& path, ArchiveFormat format) throw(ALProjectError);
  void xSaveDirectory(const ALPath& path, ArchiveFormat format) throw(ALProjectError);
  void xSaveSimpleArchive(const ALPath& path, ArchiveFormat format) throw(ALProjectError);
  void xSaveDebianPackage(const ALPath& path, ArchiveFormat format) throw(ALProjectError);

  void xParseMetaDataString(const std::string& str);

public:
  virtual ~ALProject() throw();

  // Check lib capabilities
  static bool canLoad(ArchiveFormat format) throw();
  static bool canSave(ArchiveFormat format) throw();

  // Create projects
  static boost::shared_ptr<ALProject> create(const ALPath& path = ALPath(), ArchiveFormat format = ArchiveFormat_Default) throw(ALProjectError);
  static boost::shared_ptr<ALProject> load(const ALPath& path, ArchiveFormat format = ArchiveFormat_AutoDetect) throw(ALProjectError);
  static boost::shared_ptr<const ALProject> loadReadOnly(const ALPath& path, ArchiveFormat format = ArchiveFormat_AutoDetect) throw(ALProjectError);
  static void extract(const ALPath& fileIn, const ALPath& pathOut, ArchiveFormat format = ArchiveFormat_AutoDetect);
  boost::shared_ptr<ALProject> clone() const throw(ALProjectError);

  // Attributes
  ArchiveFormat format() const throw();
  void setFormat(ArchiveFormat value) throw(ALProjectError);
  ALPath path() const throw();
  void setPath(const ALPath& value) throw(ALProjectError);

  // Metadata are named non-empty strings (use HTTP header syntax, but case-sensitive)
  void setMetaData(const std::string& name, const std::string& value, bool save = true) throw(ALProjectError); // empty value to unset, value charset is free
  std::string getMetaData(const std::string& name) const throw(); // empty value if not set, value charset is undefined
  std::map<std::string, std::string> getSavedMetaDatas() const throw();

  // File paths starting with a '.' are reserved
  std::list<ALPath> getFileList(const ALPath& fromRoot = ALPath()) const throw();
  void setFileContent(const ALPath& relativePath, void* content, size_t length) throw(ALProjectError); // pass NULL to delete file
  void setFileContent(const ALPath& relativePath, const ALPath& localPath) throw(ALProjectError); // file will be copied
  void renameFile(const ALPath& fromRelativePath, const ALPath& toRelativePath) throw(ALProjectError);
  void copyFile(const ALPath& fromRelativePath, const ALPath& toRelativePath) throw(ALProjectError);
  void copyFile(const ALProject& fromProject, const ALPath& fromRelativePath, const ALPath& toRelativePath) throw(ALProjectError);
  static void copyFile(const ALProject& fromProject, const ALPath& fromRelativePath, ALProject& toProject, const ALPath& toRelativePath) throw(ALProjectError);
  bool hasFile(const ALPath& relativePath) const throw();
  size_t getFileContent(const ALPath& relativePath, void* buffer, size_t bufferLength) const throw(ALProjectError); // return content length, 0 if not found
  void getFileContent(const ALPath& relativePath, const ALPath& localPath) const throw(ALProjectError); // file will be copied
  ALPath getFileLocalPath(const ALPath& relativePath) const throw(ALProjectError); // empty if not found
  FILE* fopen(const ALPath& relativePath, const std::string& mode) const throw(ALProjectError); // NULL on read if not found, exception otherwise (write forbidden)
  FILE* fopen(const ALPath& relativePath, const std::string& mode) throw(ALProjectError); // NULL on read if not found, exception otherwise (ie. write will never return NULL)
  void clear() throw(ALProjectError);

  // Directory manipulation helpers
  std::list<std::string> listDirectory(const ALPath& directory) const throw();
  void removeDirectory(const ALPath& relativePath) throw(ALProjectError);
  void renameDirectory(const ALPath& fromRelativePath, const ALPath& toRelativePath) throw(ALProjectError);
  void copyDirectory(const ALPath& fromRelativePath, const ALPath& toRelativePath) throw(ALProjectError);
  void copyDirectory(const ALProject& fromProject, const ALPath& fromRelativePath, const ALPath& toRelativePath) throw(ALProjectError);
  static void copyDirectory(const ALProject& fromProject, const ALPath& fromRelativePath, ALProject& toProject, const ALPath& toRelativePath) throw(ALProjectError);

  // Save operations
  void discardChanges() throw(ALProjectError); // reload content from disk
  void save() throw(ALProjectError);
  void saveTo(const ALPath& path, ArchiveFormat format, bool keepValues = false) throw(ALProjectError);

private:
  ALPath fPath;
  ArchiveFormat fFormat;

  bool fUseCache;
  ALPath fTempRoot;
  std::map<std::string, std::string> fRunTimeMetaData;
  std::map<std::string, std::string> fMetaData;

  static const size_t fBlocksize;
};

}

#ifdef _MSC_VER
#  pragma warning( pop )
#endif

#endif  // _LIB_ALPROJECT_SRC_ALPROJECT_ALPROJECT_H_
