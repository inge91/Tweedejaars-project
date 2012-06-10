/**
 * @author Jerome Vuarand
 * Copyright (c) 2010 Aldebaran Robotics  All Rights Reserved
 */
#ifndef BOX_LIBRARY_NODE_H
#define BOX_LIBRARY_NODE_H

#include <alfile/alpath.h>
#include <QObject>
#include <QMap>
#include <boost/shared_ptr.hpp>
#include <boost/filesystem.hpp>
#include <boost/enable_shared_from_this.hpp>

namespace AL
{
class ALProject;
class BoxData;
class BoxLibrary;
class BoxResourceList;
class RootBoxDescription;
class XmlElement;

class BoxLibraryNode : public QObject, public boost::enable_shared_from_this<BoxLibraryNode>
{
  Q_OBJECT

public:
  static boost::shared_ptr<BoxLibraryNode> create(boost::shared_ptr<BoxLibrary> library); // a root

  // basic getters
  std::string name() const;
  std::string fileName() const;
  boost::shared_ptr<BoxLibraryNode> parent() const { return a_parent.lock(); }
  bool expanded() const { return a_expanded; }
  int childCount() const { return a_children.size(); }
  QList<boost::shared_ptr<BoxLibraryNode> > children() const { return a_children; }
  boost::shared_ptr<BoxData> boxData() const { return a_boxData; }

  // advanced getters
  int index() const;
  QList<int> path() const;
  ALPath filePath() const;
  int childIndex(boost::shared_ptr<const BoxLibraryNode> child) const;
  boost::shared_ptr<BoxLibraryNode> child(int index) const;
  boost::shared_ptr<BoxLibraryNode> child(const std::string& name) const;
  bool isDir() const { return !a_boxData; }
  boost::shared_ptr<XmlElement> loadBox() const;
  QByteArray loadBoxData() const;
  boost::shared_ptr<BoxLibrary> library() const;
  boost::shared_ptr<BoxResourceList> resources() const;

  // setters
  void setName(const std::string& value);
  void setExpanded(bool value);
  void saveBox(boost::shared_ptr<XmlElement> xml, bool isBehavior);

  boost::shared_ptr<BoxLibraryNode> appendChild(boost::shared_ptr<BoxLibraryNode> child, bool move/* = false*/); // if move, steal the resources from child
  boost::shared_ptr<BoxLibraryNode> appendChild(const RootBoxDescription& description); // a new box
  boost::shared_ptr<BoxLibraryNode> appendChild(const std::string& name, bool expanded); // a new directory

  boost::shared_ptr<BoxLibraryNode> insertChild(int index, boost::shared_ptr<BoxLibraryNode> child, bool move/* = false*/); // if move, steal the resources from child
  boost::shared_ptr<BoxLibraryNode> insertChild(int index, const RootBoxDescription& description); // a new box
  boost::shared_ptr<BoxLibraryNode> insertChild(int index, const std::string& name, bool expanded); // a new directory

  void removeChild(int index);

  static std::string numberName(const std::string& name, int n);
  static std::string unNumberName(const std::string& name);
  static std::string escapeFileName(const std::string& filename);
  static std::string unEscapeFileName(const std::string& filename);

Q_SIGNALS:
  void dataChanged(boost::shared_ptr<AL::BoxLibraryNode> node);

private Q_SLOTS:
  void onBoxDataChanged();

private:
  BoxLibraryNode();
  boost::shared_ptr<BoxLibraryNode> clone(boost::shared_ptr<BoxLibraryNode> parent) const;
  void init(boost::shared_ptr<BoxLibraryNode> node, bool move);
  void init(const RootBoxDescription& description);
  void init(const std::string& name, bool expanded);
  boost::shared_ptr<BoxLibraryNode> appendChildFromProject(const std::string& fileName);
  void initFromProject();
  void unInit();
  void initName(const std::string& desiredName);
  void setBoxDataInternal(boost::shared_ptr<BoxData> value);
  boost::shared_ptr<ALProject> project() const;
  void saveFolder();

private:
  BoxLibraryNode(const BoxLibraryNode& other); // declared to prevent compiler-defined one, not implemented to prevent its use

  boost::weak_ptr<BoxLibrary> a_library;
  std::string a_name;
  std::string a_fileName;
  boost::weak_ptr<BoxLibraryNode> a_parent;
  bool a_expanded;
  QList<boost::shared_ptr<BoxLibraryNode> > a_children;
  boost::shared_ptr<BoxData> a_boxData;
};

}

#endif
