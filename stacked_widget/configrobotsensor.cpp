
#include "configrobotsensor.h"

ConfigSettings::ConfigSettings()
{

}

ConfigSettings::~ConfigSettings()
{

}

void ConfigSettings::SaveSettings()
{
  QSettings settings;
  settings.beginGroup("screen");
  settings.setValue("width",screen_width); //QVariant::fromValue<ConfigSettings>(conf));
  settings.setValue("height",screen_height); //QVariant::fromValue<ConfigSettings>(conf));
  settings.endGroup();
}

void ConfigSettings::SaveRobotSettings(RobotInfo &robot)
{
  QVariant var;

  var.setValue(robot);

  QSettings settings;
  settings.beginGroup("robot");
  settings.setValue("type",robot.type_);
  settings.setValue("ip",robot.ip_);
  settings.setValue("path",robot.path_);
  settings.setValue("plate",robot.plate_);
  settings.endGroup();
}



void ConfigSettings::LoadRobotSettings(RobotInfo &robot)
{
  QSettings settings;
  settings.beginGroup("robot");
  robot.type_ = settings.value("type").toString();
  robot.ip_ = settings.value("ip").toString();
  robot.path_ = settings.value("path").toString();
  robot.plate_ = settings.value("plate").toString();
  settings.endGroup();
}

void ConfigSettings::SaveCameraSettings(std::map<QString,CameraNode> & cameras)
{
  QSettings settings;
  settings.beginGroup("sensor");

  std::map<QString,CameraNode>::iterator iter;

  for(iter=cameras.begin(); iter != cameras.end(); iter++)
    {
      QString key =iter->first;
      CameraNode node = iter->second;
      settings.beginGroup(key);
      settings.setValue("alias", node.alias_);
      settings.setValue("model", node.model_);
      settings.setValue("mode", node.mode_);
      settings.setValue("enable", node.f_enable_);
      settings.setValue("positioned", node.f_isPositioned);
      settings.endGroup();
    }
  settings.endGroup();
}

bool ConfigSettings::LoadSensorSettings(std::map<QString,CameraNode> & cameras )
{
  QVariant var;

  QSettings settings;

  if(!settings.contains("sensor"))
    return false;

  settings.beginGroup("sensor");
  QStringList groups = settings.childGroups();

  QString key;
  foreach(key, groups)
    {
      CameraNode node;
      settings.beginGroup(key);
      node.alias_ = settings.value("alias").toString();
      node.model_ = settings.value("model").toString();
      //  node.mode_ = settings.value("mode").toInt();  // need to convert
      node.f_enable_ = settings.value("enable").toBool();
      node.f_isPositioned = settings.value("positioned").toBool();
      settings.endGroup();

      cameras[key] = node;
    }
  settings.endGroup();

  return true;
}

QDataStream& operator<<(QDataStream& out, const ConfigSettings& v) {
  out << v.screen_width ;
  return out;
}

QDataStream& operator>>(QDataStream& in, ConfigSettings& v) {
  in >> v.screen_width;
  return in;
}
