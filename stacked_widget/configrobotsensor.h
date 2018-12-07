#ifndef CONFIGROBOTSENSOR_H
#define CONFIGROBOTSENSOR_H
#include <QDataStream>
#include <QSettings>



/*
 * Configuration parameter
 *
 *
<display>
-screen_width
-screen_heigh
-last_page

<robot>
-type
-plate
-ip
-pacakge_path
-urdf_path

<camera>
-alias
-serialNumber
-model
-mode
-isEenable
-isPositioned

*/

enum CalbirationMode {STREREO, EXTRINSIC, ALL};

// internal camera info class
class CameraNode {
public:
  CameraNode(){}
  CameraNode(QString alias, QString model, CalbirationMode mode,
    bool f_enable, bool f_isPosition)
{
  alias_ = alias;
  model_ = model;
  mode_ = mode;
  f_enable_ = f_enable;
  f_isPositioned = f_isPosition;  // whether position was performed
}

  QString model_;
  CalbirationMode mode_;
  bool f_enable_;
  QString alias_;
  bool f_isPositioned;  // whether position was performed
};

Q_DECLARE_METATYPE(CameraNode)

// structure defined in backend
struct SensorInfo
{
  QString uuid_;
  QString model_;
  CalbirationMode mode_;
  bool f_enable_;
};

class RobotInfo
{
public:
  QString type_;
  QString ip_;
  QString plate_;
  QString path_;
};

Q_DECLARE_METATYPE(RobotInfo)

class ConfigSettings
{
public:
  ConfigSettings();
  ~ConfigSettings();
  ConfigSettings(const ConfigSettings &org){
    screen_width = org.screen_width;
    screen_height = org.screen_height;
  }

  void SaveSettings();
  void SaveRobotSettings(RobotInfo &);
  void SaveCameraSettings(std::map<QString,CameraNode> &);
  void LoadRobotSettings(RobotInfo &);
  bool LoadSensorSettings(std::map<QString,CameraNode> &);

  friend QDataStream& operator<<(QDataStream& out, const ConfigSettings& v);
  friend QDataStream& operator>>(QDataStream& in, ConfigSettings& v);

private:
  int screen_width;
  int screen_height;
};

Q_DECLARE_METATYPE(ConfigSettings)


#endif // CONFIGROBOTSENSOR_H
