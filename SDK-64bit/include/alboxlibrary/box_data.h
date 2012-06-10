/**
 * @author Jerome Vuarand
 * Copyright (c) 2010 Aldebaran Robotics  All Rights Reserved
 */
#ifndef BOX_DATA_H
#define BOX_DATA_H

#include <QObject>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

namespace AL
{
class BoxLibraryNode;
class XmlElement;

class BoxData : public QObject
{
  Q_OBJECT

  friend class BoxLibraryNode;

public:
  boost::shared_ptr<BoxData> clone(boost::shared_ptr<BoxLibraryNode> boxLibraryNode) const;

  boost::shared_ptr<const XmlElement> xml() const { return load(); }
  QByteArray xmlData() const;

  QString tooltip() const { return a_tooltip; }
  void setTooltip(const QString& value);

  QList<QString> bitmaps() const { return a_bitmaps; }
  void setBitmaps(const QList<QString>& value);

  bool bitmapExpanded() const { return a_bitmapExpanded; }
  void setBitmapExpanded(bool value);

  bool isBehavior() const { return a_isBehavior; }

  void updateData(
    const QString& name,
    const QString& tooltip,
    const QList<QString>& bitmaps,
    bool bitmapExpanded);

  static bool isBehavior(boost::shared_ptr<const XmlElement> xml);

Q_SIGNALS:
  void tooltipChanged(const QString& newValue);
  void bitmapsChanged(const QList<QString>& newValue);
  void bitmapExpandedChanged(bool newValue);

private:
  BoxData() { }
  BoxData(boost::shared_ptr<BoxLibraryNode> boxLibraryNode, boost::shared_ptr<const XmlElement> xml);
  boost::shared_ptr<XmlElement> load() const;
  void save(boost::shared_ptr<XmlElement>);
  void saveName(const std::string& value);

private:
  BoxData(const BoxData& other); // not implemented

  boost::weak_ptr<BoxLibraryNode> a_boxLibraryNode;

  QString a_tooltip;
  QList<QString> a_bitmaps;
  bool a_bitmapExpanded;
  bool a_isBehavior;
};

}

#endif
