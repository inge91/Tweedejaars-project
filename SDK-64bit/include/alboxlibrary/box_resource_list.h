/**
 * @author Jerome Vuarand
 * Copyright (c) 2010 Aldebaran Robotics  All Rights Reserved
 */
#ifndef BOX_RESOURCE_LIST_H
#define BOX_RESOURCE_LIST_H

#include <QObject>
#include <QMap>
#include <boost/shared_ptr.hpp>
#include <boost/filesystem.hpp>

namespace AL
{
class ALProject;

class BoxResourceList
{
public:
  BoxResourceList(boost::shared_ptr<ALProject> project, const ALPath& resourceRoot, const QList<ALPath>& resources)
    : a_project(project)
    , a_resourceRoot(resourceRoot)
    , a_resources(resources)
  {
  }

  boost::shared_ptr<ALProject> project() const { return a_project; }
  ALPath resourceRoot() const { return a_resourceRoot; }
  QList<ALPath> resources() const { return a_resources; }

private:
  boost::shared_ptr<ALProject> a_project;
  ALPath a_resourceRoot;
  QList<ALPath> a_resources;
};

}

#endif
