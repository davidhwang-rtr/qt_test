#ifndef CONFIGROBOTSENSOR_H
#define CONFIGROBOTSENSOR_H
#include <QDataStream>
#include <QSettings>
#include <QMetaEnum>
#include <QVector>
#include <QDateTime>

#include "defines.h"
//#include "rtr_perc_calibration/CalibrationUtil.hpp"

#ifdef BACKEND_CONNECTED
#include "rtr_perc_calibration/CalibrationUtil.hpp"
using namespace rtr;
using namespace rtr::perception;
#else
//enum CalibrationMode {ALL, STEREO, EXTRINSICS};
#endif

struct CalibrationResult
{
  CalibrationResult() :
    reprojection_(0.0),
    accuracy_(0.0),
    resolution_(0.0),
    result_(false)
    {
  }
  double reprojection_;
  double accuracy_;
  double resolution_;
  bool  result_;
};

// internal camera info _class
class CameraNode {
//  Q_OBJECT
public:
enum CalibrationMode {ALL, STEREO, EXTRINSICS};
//Q_ENUM(CalibrationMode)

  CameraNode(){
    alias_ = QString();
    model_ = QString();

    mode_ = CameraNode::CalibrationMode::EXTRINSICS;
    f_enable_ = false;
    f_seedPose_ = false;
  }

  virtual ~CameraNode(){}

  CameraNode(QString alias, QString model, CameraNode::CalibrationMode mode,
             bool f_enable, bool f_isPosition)
  {
    alias_ = alias;
    model_ = model;
    mode_ = mode;
    f_enable_ = f_enable;
    f_seedPose_ = f_isPosition;
    timestamp = QDateTime::currentDateTime();
  }
  QString alias_;
  QString uuid_;
  QString model_;
  QString serial_;
  QString manufacturer_;
//  CalibrationMode mode_;
  CameraNode::CalibrationMode mode_;
  bool f_enable_;
  bool f_seedPose_;  // whether position was performe
  QDateTime timestamp;
  CalibrationResult calibrationResult_;
};

typedef QList<CameraNode> CameraList;
typedef QMap<QString, CameraNode> CameraMap;

Q_DECLARE_METATYPE(CameraNode)

// structure defined in backend
struct SensorInfo
{
  QString uuid_;
  QString model_;
  CameraNode::CalibrationMode mode_;
  bool f_enable_;
};

class RobotInfo
{
public:

  RobotInfo(){
    type_ = QString();
    ip_ = QString();
    plate_ = QString();
    path_ = QString();
  }

  QString type_;
  QString ip_;
  QString plate_;
  QString path_;
};

Q_DECLARE_METATYPE(RobotInfo)

class GuiScreenSizeInfo
{
public:
  int screen_width;
  int screen_height;
  int table_width;
  int table_height;
  QVector<int> table_columnWidth;
};

class ConfigSettings
{
public:
  ConfigSettings();
  ~ConfigSettings();
  ConfigSettings(const ConfigSettings &org){
    gui_config_.screen_width = org.gui_config_.screen_width;
    gui_config_.screen_height = org.gui_config_.screen_height;

  }

  void SaveSettings( RobotInfo &, CameraMap & );
  void SaveGuiSettings(GuiScreenSizeInfo&) ;
  bool LoadGuiSettings(GuiScreenSizeInfo &);
//  void SaveRobotSettings(RobotInfo &);
//  void SaveCameraSettings(CameraMap &);
  bool LoadRobotSettings(RobotInfo &);
  bool LoadSensorSettings(CameraMap &);

  friend QDataStream& operator<<(QDataStream& out, const ConfigSettings& v);
  friend QDataStream& operator>>(QDataStream& in, ConfigSettings& v);

private:
  GuiScreenSizeInfo gui_config_;
};

Q_DECLARE_METATYPE(ConfigSettings)


#endif // CONFIGROBOTSENSOR_H


