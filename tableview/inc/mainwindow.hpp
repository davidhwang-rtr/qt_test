#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <thread>

#include <QImage>
#include <QMainWindow>
#include <QScrollArea>
#include <QStandardItem>

#include <rtr-control/RobotManager.hpp>

#include <rtr-utils/Log.hpp>
#include <rtr-utils/Timer.hpp>

#include <rtr-ui/rtrslider.hpp>

#include <rtr_perc_calibration/CalibrationManager.hpp>

#include <rtr_perc_ui/CalibrationConfigEntry.hpp>
#include <rtr_perc_ui/SensorSubscriberQt.hpp>

#include <rtr_perc_sensors/SensorFrame.hpp>

#include "Canvas.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  void InitializeAbstractionConnections();
  void RobotStateCallback(const rtr::JointConfiguration& joint_config);
  void PrintJointConfig(rtr::JointConfiguration& vec);
  void ParseSensors(std::set<std::string> sensor_set);
  void SetupJointPanel();
  void ProcessFrame(rtr::perception::SensorFrame::ConstPtr img);
  QImage FrameToQImage(rtr::perception::SensorFrame::ConstPtr imgin);
  ~MainWindow();

 public slots:
  void SetRobotSelection(int index);
  void SetFiducialSelection(int index);
  void SetPackagePath(QString input);
  void SetIPAddress(QString input);
  void SwitchSubscription(const QModelIndex& ind);
  void LaunchCalibrationManager();
  void AddRobotToXface();
  void AddSensorsToXface();
  void SwitchToolboxPage(int index);
  void JoinWorkerThread();
  //  void LaunchNudge(QString& joint_name, float newValue);
  void NudgeRobotConfig(QString& joint_name, float newValue);

 signals:
  void WorkerThreadFinished();
  void CalMgrInitialized();

 private:
  Ui::MainWindow* ui;
  rtr::Canvas* canvas_;
  std::thread worker_thread_;
  bool work_thread_busy_;
  bool cal_mgr_inited_;

  rtr::Timer timer_;

  // Calibration Manager and Parameters
  rtr::perception::CalibrationManager* cal_mgr_;
  rtr::perception::CalibrationParameters cal_params_;
  rtr::RuntimeRobotConfig cal_config_;

  // Robot Abstraction
  rtr::RobotManager::Ptr robot_mgr_;
  rtr::PositionController::Ptr pos_ctrlr_;
  rtr::RobotInterface::Ptr robot_xface_;
  rtr::JointConfiguration joint_max_;
  rtr::JointConfiguration joint_min_;
  rtr::JointConfiguration state_;
  std::mutex state_mutex_;
  std::vector<RTRSlider*> sliders_;

  // Sensor Abstraction
  rtr::perception::SensorManager::Ptr smgr_;
  std::vector<rtr::perception::CalibrationConfigEntry*> cces_;
  QStandardItemModel sensors_;
  rtr::perception::SensorSubscriberQt::Ptr sub_;
  rtr::perception::Sensor::OnSensorData callback_;
  std::set<std::string> sensors_to_calibrate_;
  QPixmap pm_;
  cv::Mat corners_;  // matrix for checking chessboard
  bool sensor_active_;
};

#endif  // MAINWINDOW_HPP
