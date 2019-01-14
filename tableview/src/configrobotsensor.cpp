
#include "configrobotsensor.h"

ConfigSettings::ConfigSettings() {}

ConfigSettings::~ConfigSettings() {}


void ConfigSettings::SaveGuiSettings(GuiScreenSizeInfo& sizeInfo) {

      QSettings settings;

      settings.beginGroup("screen");
      settings.setValue("width", gui_config_.screen_width);
      settings.setValue("height", gui_config_.screen_height);
      settings.setValue("tableWidth", gui_config_.table_width);
      settings.setValue("tableHeight", gui_config_.table_height);

      for(int i=0; i < sizeInfo.table_columnWidth.size(); i++)
        {
          settings.setValue(QString("column") + QString::number(i), sizeInfo.table_columnWidth[i]);
        }
      settings.endGroup();
}

bool ConfigSettings::LoadGuiSettings(GuiScreenSizeInfo &sizeInfo) {

  QSettings settings;

  settings.beginGroup("screen");
    sizeInfo.screen_width = settings.value("width").toInt();
    sizeInfo.screen_height = settings.value("height").toInt();
    sizeInfo.screen_height = settings.value("tableWidth").toInt();
    sizeInfo.table_height = settings.value("tableHeight").toInt();
    // column width
    QStringList keys = settings.allKeys();
    QStringList column_keys = keys.filter("column");
    sizeInfo.table_columnWidth.resize(column_keys.size());
    for(int i=0;i < column_keys.size(); i++)
      {
        sizeInfo.table_columnWidth[i] = settings.value(column_keys.at(i) + QString::number(i)).toInt();
      }

  settings.endGroup();

  return true;
}

bool ConfigSettings::LoadRobotSettings(RobotInfo& robot) {
  QSettings settings;

//  if (!settings.contains("robot")) return false;

  settings.beginGroup("robot");
  robot.type_ = settings.value("type").toString();
  robot.ip_ = settings.value("ip").toString();
  robot.path_ = settings.value("path").toString();
  robot.plate_ = settings.value("plate").toString();
  settings.endGroup();

  return true;
}

bool ConfigSettings::LoadSensorSettings(CameraMap & cameras) {
  QVariant var;
  int mode_type;

  QSettings settings;

//  if (!settings.contains("sensor")) return false;

  settings.beginGroup("sensor");
  QStringList groups = settings.childGroups();

  QString key;
  foreach (key, groups) {
    CameraNode node;
    settings.beginGroup(key);
    node.uuid_ = settings.value("uuid").toString();
    node.alias_ = settings.value("alias").toString();
    node.model_ = settings.value("model").toString();
    //  node.mode_
    mode_type = settings.value("mode").toInt();
    node.mode_ = static_cast<CameraNode::CalibrationMode>(mode_type);
    node.f_enable_ = settings.value("enable").toBool();
    node.f_seedPose_ = settings.value("positioned").toBool();
    settings.endGroup();

    cameras[key] = node;
  }
  settings.endGroup();

  return true;
}

QDataStream& operator<<(QDataStream& out, const ConfigSettings& v) {
  out << v.gui_config_.screen_width;
  return out;
}

QDataStream& operator>>(QDataStream& in, ConfigSettings& v) {
  in >> v.gui_config_.screen_width;
  return in;
}
