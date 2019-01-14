#include "GuiBackendInterface.h"
#include <vector>
#include <list>
#include "rtr-math/Mat4.hpp"


GuiBackendInterface::GuiBackendInterface(){

}

void GuiBackendInterface::SwitchSubscription(std::string uid) {
  Q_UNUSED(uid);
}

void GuiBackendInterface::GetCurrentConfiguration(std::vector<float> &state)
{
  for(size_t i=0;i<state.size();i++)
    state[i] = 5;
}

rtr::JointConfiguration GuiBackendInterface::NudgeRobotConfig(QString &joint_name, float newValue)
{
  rtr::JointConfiguration config(6,5.0);
  Q_UNUSED(joint_name);
  Q_UNUSED(newValue);


  return config;
}
void  GuiBackendInterface::ExitReposition()
{
  emit InitialPoseFinished(ErrorMessage::NO_ERROR);
}

std::vector<std::string> GuiBackendInterface::GetFiducialPlates()
{
  std::vector<std::string> plates;

  std::string p1("BIG_CHECKERBOARD");
  plates.push_back(p1);
  std::string p2("MED_CHECKERBOARD");
  plates.push_back(p2);

  return plates;
}

void GuiBackendInterface::ExitHandler() {

}

void GuiBackendInterface::SetFiducialSelection(int index) {
  Q_UNUSED(index);

}

void GuiBackendInterface::JoinWorkerThread() {

}

void GuiBackendInterface::GetRobotJointLimits(std::vector<float>& joint_min, std::vector<float>& joint_max)
{
  Q_UNUSED(joint_min);
  Q_UNUSED(joint_max);
}

//bool Connect(rtr::SupportedRobot robot_selection, std::string package_path, std::string ip_address, rtr::CalibrationPlate fiducial_plate);
bool GuiBackendInterface::Connect(const std::string &robot_selection, const std::string &package_path,
                                  const std::string &ip_address, const std::string &fiducial_plate)
{
  Q_UNUSED(robot_selection);
  Q_UNUSED(package_path);
  Q_UNUSED(ip_address);
  Q_UNUSED(fiducial_plate);

  return true;
}

void GuiBackendInterface::InitializeCalibrationManager() {

}


std::vector<std::string> GuiBackendInterface::GetRobotTypes()
{
  std::vector<std::string> foo;

  foo.push_back(std::string("FANUCLRMate200iD"));
  foo.push_back(std::string("UR5"));
  foo.push_back(std::string("UR3"));
  foo.push_back(std::string("DummyRobot"));
  foo.push_back(std::string("Custom"));

  return foo;
}

void GuiBackendInterface::InitRobot()
{
}

// returning uuid of sensors
std::vector<std::string> GuiBackendInterface::GetSensors(){
  std::vector<std::string> tmp;
  std::string uuid ;

  CameraNode camera1(QString("X Axis"), QString("Intel_Realsense_D435"), CameraNode::CalibrationMode::ALL, true, false);
  CameraNode &camera = camera1;
  uuid = camera.model_.toStdString() + std::string("_") + std::string("12344455");
  camera.uuid_ = QString(uuid.c_str());
  tmp.push_back(uuid);

  CameraNode camera2(QString("Y Axis"), QString("Intel_Realsense_D435"), CameraNode::CalibrationMode::STEREO, true, true);
  camera = camera2;
  uuid = camera.model_.toStdString() + std::string("_") + std::string("12344456");
  camera.uuid_ = QString(uuid.c_str());
  tmp.push_back(uuid);

  CameraNode camera3(QString("Z Axis"), QString("Intel_Realsense_D415"), CameraNode::CalibrationMode::EXTRINSICS, false, true);
  camera = camera3;
  uuid = camera.model_.toStdString() + std::string("_") + std::string("12344457");
  camera.uuid_ = QString(uuid.c_str());
  tmp.push_back(uuid);

  CameraNode camera4(QString("Z Axis"), QString("Intel_Realsense_D415"), CameraNode::CalibrationMode::EXTRINSICS, true, true);
  camera = camera4;
  uuid = camera.model_.toStdString() + std::string("_") + std::string("12344458");
  camera.uuid_ = QString(uuid.c_str());
  tmp.push_back(uuid);

  CameraNode camera5(QString("Z Axis"), QString("Intel_Realsense_D415"), CameraNode::CalibrationMode::EXTRINSICS, false, true);
  camera = camera5;
  uuid = camera.model_.toStdString() + std::string("_") + std::string("12344455");
  camera.uuid_ = QString(uuid.c_str());
  tmp.push_back(uuid);

  return tmp;
}

void GuiBackendInterface::GetRobot(rtr::Robot::Ptr& robot,
                                   rtr::RobotInterface::Ptr& xface)
{
  Q_UNUSED(robot);
  Q_UNUSED(xface);
};

void GuiBackendInterface::FindSeedPose(const std::string &uid)
{
  Q_UNUSED(uid);

  bool status = true;
    emit InitialPoseStatus(status);

//  emit InitialPoseFinished(ErrorMessage::NO_ERROR);
}

void GuiBackendInterface::SetRobotSelection(int) {
}

void GuiBackendInterface::SetPackagePath(QString) {
}

void GuiBackendInterface::SetIPAddress(QString) {
}

void GuiBackendInterface::DoCalibrate()
{

}

void GuiBackendInterface::SetCalibrationMode(const std::string &uid, CameraNode::CalibrationMode cal_mode)
{
  Q_UNUSED(uid);
  Q_UNUSED(cal_mode);
}

void GuiBackendInterface::SetSensorEnabled(const std::string &uid, bool enable)
{
  Q_UNUSED(uid);
  Q_UNUSED(enable);
}

int GuiBackendInterface::GetMaxCalibrationImageSet(const std::string &)
{
  return 15;
}

void GuiBackendInterface::GetCalibrationMetrics(const std::string &uuid,std::map<std::string, float> &metrics)
{
  Q_UNUSED(uuid);
  Q_UNUSED(metrics);
}
