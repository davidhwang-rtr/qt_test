#ifndef CALIBRAIONINTERFACE_H
#define CALIBRAIONINTERFACE_H

#include <thread>
#include <mutex>
#include <condition_variable>
#include <exception>

#include "Canvas.hpp"
#include <opencv2/core/core.hpp>
#include "backendInterface.hpp"

#include "rtr_perc_calibration/CalibrationManager.hpp"
#include "rtr_perc_sensors/SensorManager.hpp"
#include "rtr_perc_sensors/SensorFrame.hpp"
#include "rtr-control/RobotManager.hpp"
#include "rtr_perc_ui/SensorSubscriberQt.hpp"

class CalibrationInterface : public BackendInterface
{
  Q_OBJECT

public:
  CalibrationInterface();
  virtual ~CalibrationInterface();

  virtual void InitializeCalibrationManager();
  void InitRobot();
  void ProcessFrame(rtr::perception::SensorFrame::ConstPtr imgin);
  void SwitchSubscription(std::string uid);
  void AddRobotToCanvas();
  void FindInitGuess();

private:
//  rtr::Canvas* canvas_;
  rtr::RuntimeRobotConfig robot_config_;
  rtr::perception::CalibrationParameters cal_params_;
  rtr::perception::CalibrationManager* cal_mgr_;
  rtr::RobotManager::Ptr robot_mgr_;
  rtr::PositionController::Ptr pos_ctrlr_;
  rtr::RobotInterface::Ptr robot_xface_;
  rtr::perception::SensorManager::Ptr sens_mgr_;
  rtr::perception::Sensor::OnSensorData callback_;
  std::vector<std::string> sensor_uids_;
  rtr::perception::SensorSubscriberQt::Ptr sub_;

  std::string active_uid_;

  std::thread worker_thread_;
  std::condition_variable cv_;
  std::mutex m_;
  bool start_init_;
  bool ready_to_add_bot_;

  bool calmgr_inited_;
  bool stream_active_;
  bool work_thread_busy_;

  bool robot_selected_;
  bool package_path_set_;
  bool ip_address_set_;

  // from repositioning
  std::string uid_;


  rtr::JointConfiguration joint_min_;
  rtr::JointConfiguration joint_max_;

  bool stream_active_;
  bool bg_thread_busy_;
  bool request_exit_;
  std::thread bg_thread_; //background thread, used for checking for fiducial plate
}
#endif // CALIBRAIONINTERFACE_H
