#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QList>
#include <QGroupBox>
#include <QFileDialog>
#include <QProgressBar>
#include "defines.h"
#include "configrobotsensor.h"
#include "repositiondialog.h"
#include "createprofiledialog.h"
//#include "Canvas.hp"
#ifdef BACKEND_CONNECTED
#include "calibrationInterface.h"
#else
#include "GuiBackendInterface.h"
#endif

class MainWindow;

namespace Ui {
  class ConfigWidget;
}

class CameraTableWidget : public QWidget
{
  Q_OBJECT

  enum ColumnId {
    NICK_NAME,MODEL,MODE,
    ENABLE,TIMESTAMP,CALIBRATION_BUTTON,
    CALIBRATION_STATUS,SCORE_RESOLUTION,
    LAST_DUMMY,ColumnId_SIZE};

  enum CalibrationState {
    NOT_READY,BACKEND_CONNECTED, READY_TO_RUN,REPOSITION_PROCESSING,REPOSITION_DONE,
    READY_TO_CALIBRATE,CALIBRATIN_PROCESSING,CALIBRATION_DONE,
    CalibrationState_ELEMENT_SIZE};

public:
  explicit CameraTableWidget(QWidget *parent = nullptr);
  ~CameraTableWidget();

  void InitSensorUi();
  void InitRobotUi();
  void SetupSensorTable();
  bool GetCameraMap(CameraMap &) const;
  bool GetRobotConfig(RobotInfo &) const;
  void SaveSettings();
  void SetGuiSettings(GuiScreenSizeInfo &);
  void SetRobotSetting(RobotInfo &robot);
  void SetCameraSetting(CameraMap  &camera);
  void SaveGuiSettings(GuiScreenSizeInfo &);
  void SaveRobotSettings(RobotInfo& robot);
  void SaveCameraSettings(CameraMap& cameras);
  bool LoadSensorSettings();
  bool LoadRobotSettings();
  void OnCalibrateButtonClicked();
  std::vector<unsigned int> table_column_width_;

public slots:
  void TableItemClicked(QTableWidgetItem *);
  void TableCellClicked(int row, int col);
  void TableCellPressed(int row, int col);
  void TableCellChanged(int row, int col);
  void OnRepositionButtonClicked();
  void RefreshSensorConfig(QList<SensorInfo> &sensor_list);
  void OnCalibrationModeChanged(int index);
//  void SetRobotSelection(int index);
//  void SetPackagePath(QString input);
//  void SetIPAddress(QString input);
    void OnTableContentChanged();
    void receiveFrame(QPixmap pm);
    void ReceivedCalibrationProgress(int index);

private slots:
    void RepositionAccepted();
    void RepositionRejected();
    void CreateProfileAccepted();
    void CreateProfileRejected();
    void on_pushButton_home_clicked();

    void on_pushButton_fileSelect_clicked();
    void on_pushButton_fileNew_clicked();
    void on_lineEdit_fileName_returnPressed();
    void on_pushButton_connect_clicked();
    void on_finishedCalibration();

  signals:
    void robotSelectionChanged(int);
    void packagePathChanged(QString);
    void iPAddressChanged(QString);
    void TableItemUpdated(int);
    void FinishedCalibration();

private:
  Ui::ConfigWidget *ui_setting;
  CameraMap camera_map_;
  QMap<int,QString> table_node_;
  RobotInfo robot_;
  MainWindow *mainwindow_;
  GuiScreenSizeInfo  guiSizeInfo;
#ifndef BACKEND_CONNECTED
  GuiBackendInterface *calibrationInterface;
#else
  CalibrationInterface *calibrationInterface;
#endif

  void PopulateTable(const CameraMap &);
  int  GetSizeOfViewToContents();
  QString FindCameraNode(int);
  void GetSensorProfile(CameraNode &);
  QWidget *CreateSensorProfileWidget(CameraNode &node) const;
  void retranslateUi();
  void SetUpRobots();
  QString fileName; // project file name
  rtr::Robot::Ptr robot;
  rtr::RobotInterface::Ptr xface;
  QString current_uuid_;
  int max_image_size_;
  CalibrationState state_;
//  rtr::Canvas* canvas_;
  // To Do
  // ProjectSchema projectSchema_;

};

#endif // WIDGET_H
