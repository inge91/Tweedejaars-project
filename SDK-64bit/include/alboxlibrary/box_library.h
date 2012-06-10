/**
 * @author Jerome Vuarand
 * Copyright (c) 2010 Aldebaran Robotics  All Rights Reserved
 */
#ifndef BOX_LIBRARY_H
#define BOX_LIBRARY_H

#include <alfile/alpath.h>
#include <QObject>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/filesystem.hpp>

namespace AL
{
class ALProject;
class BoxLibraryNode;

class BoxLibrary : public QObject, public boost::enable_shared_from_this<BoxLibrary>
{
  Q_OBJECT
  friend class BoxLibraryNode;

public:
  typedef void ProjectAdapter(boost::shared_ptr<ALProject> project);
  enum LibraryFormat
  {
    LibraryFormat_Directory,
    LibraryFormat_CBL,
  };

public:
  // ctors
  static boost::shared_ptr<BoxLibrary> create(bool readOnly = false);
  static boost::shared_ptr<BoxLibrary> load(const QString& fileName, ProjectAdapter* projectAdapter, bool readOnly = false);
  static boost::shared_ptr<BoxLibrary> load(boost::shared_ptr<ALProject> project, bool readOnly = false); // take ownership of ALProject
  //static boost::shared_ptr<BoxLibrary> load(boost::shared_ptr<const ALProject> project, bool readOnly = false); // make a copy of ALProject

  // obsolete backward compatibility, DO NOT USE
  static boost::shared_ptr<BoxLibrary> create(const QString& fileName, ProjectAdapter* projectAdapter, bool readOnly = false);

  // basic getters
  boost::shared_ptr<BoxLibraryNode> boxRoot() { return a_boxRoot; }
  bool readOnly() const { return a_readOnly; }
  QString path() const;
  QString title() const;

  // advanced getters
  boost::shared_ptr<BoxLibraryNode> node(const QList<int>& path) const;

  // setters
  void setFormat(LibraryFormat value);
  void setPath(const QString& fileName);
  void setImportPath(const QString& fileName);

  // helper functions
  void save();
  void saveTo(const QString& fileName, LibraryFormat format);
  /// The project returned may no longer be valid if the library is modified. Clone it before modifying the library content.
  boost::shared_ptr<const ALProject> saveToProject();

Q_SIGNALS:
  void dataChanged(boost::shared_ptr<AL::BoxLibraryNode> node);

private:
  BoxLibrary(bool readOnly = false);
  BoxLibrary(boost::shared_ptr<ALProject> project, bool readOnly = false);
  boost::shared_ptr<BoxLibraryNode> node(const ALPath& path) const;
  boost::shared_ptr<ALProject> project() const { return a_project; }
  static bool projectUpToDate(boost::shared_ptr<ALProject> project);
  void setReadOnly(bool value) { a_readOnly = value; }

private:
  BoxLibrary(const BoxLibrary& other) { }
  boost::shared_ptr<BoxLibraryNode> a_boxRoot;

  bool a_readOnly;
  boost::shared_ptr<ALProject> a_project;
};

}

#endif
