#ifndef GUIBACKENDINTERFACE_H
#define GUIBACKENDINTERFACE_H
#include "backendInterface.h"
#include <QString>
#include <QObject>
#include <QPixmap>
#include <memory>

#include "rtr-control/inc/rtr-control/RobotInterface.hpp"
#include "rtr-core/inc/rtr-core/Robot.hpp"
//#include "rtr_perc_calibration/CalibrationUtil.hpp"
#include "configrobotsensor.h"
#include "errormessage.h"

class GuiBackendInterface : public BackendInterface
{
  Q_OBJECT

public:
  GuiBackendInterface();
  virtual ~GuiBackendInterface(){}

  virtual void InitializeCalibrationManager();
  void InitRobot();

  std::vector<std::string> GetRobotTypes();

    bool Connect(const std::string &robot_selection, const std::string &package_path,
                          const std::string &ip_address, const std::string &fiducial_plate);
    std::vector<std::string> GetSensors();
    void GetRobot(rtr::Robot::Ptr& robot, rtr::RobotInterface::Ptr& xface);
    void SwitchSubscription(std::string uid);
    void SetCalibrationMode(const std::string &uid, CameraNode::CalibrationMode cal_mode);
    void SetSensorEnabled(const std::string &uid, bool enable);
    void FindSeedPose(const std::string &uid);
    void GetRobotJointLimits(std::vector<float>& joint_min, std::vector<float>& joint_max);
    void GetCurrentConfiguration(std::vector<float>& joint_min);
    rtr::JointConfiguration NudgeRobotConfig(QString& joint_name, float newValue);
    void ExitReposition(); //returns the value of GetInitGuess on that uid
    void DoCalibrate();

    std::vector<std::string> GetFiducialPlates();
    int GetMaxCalibrationImageSet(const std::string &uuid);
    void GetCalibrationMetrics(const std::string &uuid,std::map<std::string, float> &metrics);
private:


public slots:
  void ExitHandler();
  void SetFiducialSelection(int index);
  void JoinWorkerThread();
  void SetRobotSelection(int);
  void SetPackagePath(QString);
  void SetIPAddress(QString);

signals:
 void sendFrame(QPixmap);
 void WorkerThreadFinished();
 void backgroundThreadFinished();
 void InitialPoseFinished(ErrorMessage);  // ErrorMessage: defined in cal_manager
// void GetInitialGuess(Mat4 &);  // To Do
 void InitialPoseStatus(bool);  //
 void CalibrationProgressUpdate(int curr_index);  // returns processing image index
};
#endif // CALIBRAIONINTERFACE_H

