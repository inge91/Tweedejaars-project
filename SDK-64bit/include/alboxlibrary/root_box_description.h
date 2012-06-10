/**
 * @author Jerome Vuarand
 * Copyright (c) 2011 Aldebaran Robotics  All Rights Reserved
 */
#ifndef ROOT_BOX_DESCRIPTION_H
#define ROOT_BOX_DESCRIPTION_H

#include <QObject>
#include <QMap>
#include <boost/shared_ptr.hpp>
#include <boost/filesystem.hpp>

namespace AL
{
class ALProject;

class RootBoxDescription
{
public:
  RootBoxDescription(const std::string& name, boost::shared_ptr<const XmlElement> boxXml, boost::shared_ptr<BoxResourceList> resources = boost::shared_ptr<BoxResourceList>())
    : a_name(name)
    , a_boxXml(boxXml)
    , a_resources(resources)
  {
  }

  std::string name() const { return a_name; }
  boost::shared_ptr<const XmlElement> boxXml() const { return a_boxXml; }
  boost::shared_ptr<BoxResourceList> resources() const { return a_resources; }

private:
  std::string a_name;
  boost::shared_ptr<const XmlElement> a_boxXml;
  boost::shared_ptr<BoxResourceList> a_resources;
};

}

#endif
