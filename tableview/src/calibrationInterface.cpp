#include "calibrationInterface.h"

CalibrationInterface::CalibrationInterface()
{
  // setup background worker thread
  connect(this, SIGNAL(WorkerThreadFinished()), this, SLOT(JoinWorkerThread()));

  callback_ = std::bind(&CalibrationInterface::ProcessFrame, this, std::placeholders::_1);
  canvas_ = nullptr;
  cal_mgr_ = nullptr;
  calmgr_inited_ = false;
  stream_active_ = false;
  robot_selected_ = false;
  package_path_set_ = false;
  ip_address_set_ = false;
  start_init_ = false;
  ready_to_add_bot_ = false;

  // Setup 3d viewing canvas
  // Change some settings for smoother graphics
//  QSurfaceFormat format;
//  format.setSamples(2);
//  QSurfaceFormat::setDefaultFormat(format);
//  canvas_ = new rtr::Canvas();

  //  ui_setting->horizontalLayout->addWidget(canvas_);

  // Setup calibrate button, to be removed later
  //  connect(ui_setting->generate_button, SIGNAL(pressed()), this, SLOT(OnCalibrateButtonClicked()));
  //  connect(ui_setting->start_cal_button, SIGNAL(pressed()), this, SLOT(OnStartButtoOnnClicked()));

  InitRobot();
}

CalibrationInterface::~CalibraionInterface()
{

  if (bg_thread_busy_) {
    bg_thread_.join();
    bg_thread_busy_ = false;
  }
  if (stream_active_) {
    sub_->stop();
  }

}

void CalibrationInterface::StartSubscription(std::string &uid) {
  rtr::perception::Sensor::OnSensorData callback =
      std::bind(&CalibraionInterface::ProcessFrame, this, std::placeholders::_1);
  ;
  sub_ =
      std::make_shared<SensorSubscriberQt>(BufferQueue::Ptr(new BufferQueue()), uid,
                                           SensorFrameType::SENSOR_FRAME_IMAGE_RGB, callback, "");
  sub_->start();  // starts the Qthread in SensorSubscriberQt, not the sensor
  stream_active_ = true;
}

void CalibrationInterface::LookForFiducial() {
  // TODO: fix this, the cal plate type needs to be passed to the reposition dialog somehow
  while (!cal_mgr_->FindInitGuess(uid_, rtr::perception::CalibrationTarget::BIG_CHECKERBOARD)
         && !request_exit_) {
    qDebug() << "No cal plate";
    //    std::cout << "request exit val : " << request_exit_ << std::endl;
    usleep(1000);
  }
  if (request_exit_) {
//    emit BackgroundThreadFinished();
    return;
  }
//  ui_reposition->label_status->setAlignment(Qt::AlignCenter);
//  ui_reposition->label_status->setStyleSheet("QLabel { background-color : green; color : white; }");
//  ui_reposition->label_status->setText(
//      QString("Status: Success! A frame has been latched with the fiducial plate in view."));
  qDebug() << "Found the calibration plate!";
  stream_active_ = false;
  sub_->stop();
  emit backgroundThreadFinished();
}

void CalibrationInterface::JoinBackgroundThread() {
  if (bg_thread_busy_) {
    bg_thread_.join();
    bg_thread_busy_ = false;
  }
  std::cout << "Joined background thread!" << std::endl;
  emit InitPoseFinished();
}


void CalibrationInterface::FindSeedPose(std::strin &uid)
{
  robot_mgr_ = RobotManager::getInstance();

  StartSubscription(uid/*uid_*/);

  connect(this, SIGNAL(backgroundThreadFinished()), this, SLOT(JoinBackgroundThread()));
  bg_thread_busy_ = true;
  request_exit_ = false;

  bg_thread_ = std::thread(std::bind(&RepositionDialog::LookForFiducial, this));
}

void CalibrationInterface::ExitReposition()
{
  request_exit_ = true;
}

//! Method for constructing the joint jog panel with joint limits from the URDF
bool CalibrationInterface::SetupJogSliders(rtr::JointConfiguration &joint_max_, rtr::JointConfiguration &joint_max_) {
  std::vector<std::string> joint_names = {"shoulder_pan_joint", "shoulder_lift_joint",
                                          "elbow_joint",        "wrist_1_joint",
                                          "wrist_2_joint",      "wrist_3_joint"};
  joint_max_ = rtr::JointConfiguration(joint_names.size());
  joint_min_ = rtr::JointConfiguration(joint_names.size());
//  robot_xface_ = robot_mgr_->GetRobotInterface();
//  pos_ctrlr_ = robot_mgr_->GetPositionController();
  rtr::JointConfiguration state = robot_xface_->GetCurrentConfiguration();
  rtr::Robot::JointMap joint_map = robot_mgr_->GetRobot()->GetJointMap();
  for (size_t i = 0; i < joint_names.size(); i++) {
    joint_max_[i] = joint_map[joint_names[i]]->max_q;
    joint_min_[i] = joint_map[joint_names[i]]->min_q;
  }
}

rtr::JointConfiguration CalibrationInterface::NudgeRobotConfig(QString& joint_name, float newValue) {
  rtr::JointConfiguration config = rtr::JointConfiguration(joint_min_.Size());
  config = robot_xface_->GetCurrentConfiguration();
  size_t dof = config.Size();

  size_t active_joint_index = 0;
  for (size_t i = 1; i <= config.Size(); i++) {
    std::stringstream ss;
    ss << "J" << static_cast<int>(i) << std::endl;
    if (joint_name.toStdString().compare(ss.str()) == 0) {
      active_joint_index = i;
    }
  }

  //  RTR_LOG_INFO("Starting in config: " << config);
  //  RTR_LOG_DEBUG("Trajectory: " << std::endl);
  // Execute the command
  rtr::Trajectory traj;
  traj.t.push_back(1);  // one second to execute
  rtr::JointConfiguration q(dof);
  rtr::JointConfiguration qdot(dof);
  rtr::JointConfiguration qddot(dof);
  for (size_t i = 0; i < config.Size(); i++) {
    if (i == active_joint_index - 1) {
      q[i] = newValue;
      if (q[i] > joint_max_[i] || q[i] < joint_min_[i]) {
        RTR_LOG_ERROR("Error: Ignoring infeasible command, execution would violate joint limits."
                      << std::endl);
        return;
      }
    } else {
      q[i] = config[i];
    }
    qdot[i] = 0.0;
    qddot[i] = 0.0;
  }
  //  RTR_LOG_DEBUG(q << std::endl);
  traj.q.push_back(q);
  traj.qdot.push_back(qdot);
  traj.qddot.push_back(qddot);

  pos_ctrlr_->SetTrajectory(traj);
  while (!pos_ctrlr_->IsFinished()) {
    usleep(10000);
  }
  config = robot_xface_->GetCurrentConfiguration();

  return config;
}


void CalibrationInterface::SwitchSubscription(std::string uid) {
  if (stream_active_) {
      sub_->switchStream(uid, SensorFrameType::SENSOR_FRAME_IMAGE_IR_UNRECTIFIED_1);
    } else {
      sub_ = std::make_shared<SensorSubscriberQt>(
            BufferQueue::Ptr(new BufferQueue()), uid,
            SensorFrameType::SENSOR_FRAME_IMAGE_IR_UNRECTIFIED_1, callback_, "");
      sub_->start();  // starts the Qthread in SensorSubscriberQt, not the sensor
      stream_active_ = true;
    }
}

void CalibrationInterface::ProcessFrame(rtr::perception::SensorFrame::ConstPtr imgin) {
  // std::cout << "Top of ProcessFrame" << std::endl;
  rtr::perception::SensorFrameImage::ConstPtr img =
      std::dynamic_pointer_cast<const SensorFrameImage>(imgin);


  cv::Mat frame16(img->image().rows, img->image().cols, CV_16UC1, img->image().data,
                  img->image().step);
  double minVal, maxVal;
  cv::minMaxLoc(frame16, &minVal, &maxVal);
  cv::Mat frame8;
  frame16.convertTo(frame8, CV_8U, 255.0 / maxVal, -minVal * 255.0 / maxVal);
  QImage curr_frame(
        frame8.data, frame8.cols, frame8.rows, frame8.step,
        QImage::Format_Grayscale8);  // is there a better way to do this than allocating
  // and deallocating QImage? TODO: fix this
  QPixmap pm = QPixmap::fromImage(curr_frame.scaledToHeight(250));

  emit sendFrame(pm);

//  if (!pm.isNull()) {
//      ui_setting->cameraView->setPixmap(pm);
//    }
}

void CalibrationInterface::ExitHandler() {
  if (stream_active_) {
      sub_->stop();
    }
}

void CalibrationInterface::SetFiducialSelection(int &index) {
  if (index == 0) {
      // Medium Fiducial
      cal_params_.target_type = rtr::perception::CalibrationTarget::Type::BIG_CHECKERBOARD;
    } else {
      // Big Fiducial
      cal_params_.target_type = rtr::perception::CalibrationTarget::Type::MED_CHECKERBOARD;
    }
  RTR_LOG_DEBUG("Fiducial selection set to " << cal_params_.target_type << std::endl);
}

void CalibrationInterface::JoinWorkerThread() {
  std::cout << "The worker thread is joining in thread: " << std::this_thread::get_id()
            << std::endl;
  std::cout << "Joining worker" << std::endl;
  if (work_thread_busy_) {
      worker_thread_.join();
    }
}

void CalibrationInterface::onConnectClicked()
{
  if (calmgr_inited_) {
      qDebug() << "TODO: implement changing of calmgr params on connect click";
      return;
    }

  std::cout << "This window's thread is : " << std::this_thread::get_id() << std::endl;
  if (!(robot_selected_ and package_path_set_ and ip_address_set_)) {
      qDebug() << "ERROR! Failed to initialize the calibration manager. "
               << "Did you set a robot, package path, and IP address?";
      return;
    } else {
      //    ui_setting->button_Connect->setText("Connecting...");
    }

  work_thread_busy_ = true;
  worker_thread_ = std::thread([this]() { InitializeCalibrationManager(); });

  {
    std::lock_guard<std::mutex> lk(m_);
    start_init_ = true;
  }
  cv_.notify_one();

  // wait for a response from the worker
  {
    std::unique_lock<std::mutex> lk(m_);
    cv_.wait(lk, [this] { return ready_to_add_bot_; });
  }
  std::cout
      << "Worker has finished initializing the calibration manager, now adding robot to canvas"
      << std::endl;

//  // TODO: make sure this behaves correctly when the calmgr fails to initialize
//  //  ui_setting->button_Connect->setText("Connected!");

//  // TODO: improve the setup time for initializing the connection
//  // Adding GUI items needs to happen in main thread, so Setup Sensor Table goes here for now
//  SetupSensorTable();
//  // Adding robot to the OpenGL canvas also needs to happen in main thread
//  AddRobotToCanvas();
}

void CalibraionInterface::InitializeCalibrationManager() {
  std::cout << "The cal_mgr is being inited in thread: " << std::this_thread::get_id() << std::endl;
  std::unique_lock<std::mutex> lk(m_);
  cv_.wait(lk, [this] { return start_init_; });

  cal_mgr_ = new CalibrationManager();

  CalibrationSetupConfig setup_config;
  setup_config.ros_package_path = robot_config_.ros_package_path;
  setup_config.robot_urdf_path = robot_config_.urdf_path;
  setup_config.scene_urdf_path =
      "";  // still assuming robot, scene, and fiducial are combined for now
  setup_config.robot_type = robot_config_.robot_type;
  setup_config.ip_address = robot_config_.ip_address;
  try {
    if (!cal_mgr_->Init(setup_config)) {
        // catch calibration manager failed initialization
        qDebug() << "ERROR! Calibration Manager initialization failure!";
        calmgr_inited_ = false;
        return;
      } else {
        // report successful initialization
        qDebug() << "Calibration Manager initialization success!";
        calmgr_inited_ = true;
      }
  } catch (std::exception& e) {
    std::cout << e.what() << '\n';
    return;
  }
  std::cout << "Enabling calibrators" << std::endl;
  cal_mgr_->EnableCalibrators();
  robot_mgr_ = RobotManager::getInstance();
  pos_ctrlr_ = robot_mgr_->GetPositionController();
  robot_xface_ = robot_mgr_->GetRobotInterface();
//  std::cout << "Getting connected sensors" << std::endl;
//  std::set<std::string> discovered_uids = cal_mgr_->GetConnectedSensors();
//  for (auto s : discovered_uids) {
//      sensor_uids_.push_back(s);
//      QString sens_str = QString::fromStdString(s);
//      QStringList fields = sens_str.split("_");
//      CameraNode camera(sens_str, fields[0] + " " + fields[1] + " " + fields[2],
//          rtr::perception::CalibrationMode::ALL, false, false);
//      camera_map_[fields[3]] = camera;
//    }

  ready_to_add_bot_ = true;
  lk.unlock();
  cv_.notify_one();

  emit WorkerThreadFinished();
}


std::vector<std::string> CalibrationInterface::GetSupportedRobot()
{
    //------------------------------
    // Setup Robot Selection ComboBox
      int i = 0;
      std::list<std::string> robots;

      std::string bot_type = rtr::GetRobotTypeString(static_cast<rtr::SupportedRobot>(i));
      while (bot_type != "N/A") {
        robots.push_back(bot_type);
        i++;
        bot_type = GetRobotTypeString(static_cast<rtr::SupportedRobot>(i));
      }
      return robots;
}

void CalibrationInterface::InitRobot()
{
  cal_params_.mode = rtr::perception::CalibrationMode::ALL;
  cal_params_.num_images = 15;
  cal_params_.image_width = 1280;
  cal_params_.image_height = 800;
  cal_params_.rgb_image_width = 1920;
  cal_params_.rgb_image_height = 1080;
  //  cal_params_.fixed_frame = "base_link";
  //  cal_params_.fiducial_frame = "robotiq_85";
  //  cal_params_.fiducial_frame = "robotiq_85";
  cal_params_.compute_intrinsics = false;
  cal_params_.add_test_set = false;
  cal_params_.use_test_set = false;
  cal_params_.run_test_set = false;
  cal_params_.cal_dir = "";
  cal_params_.debug_dir = "";
  cal_params_.test_set = "";

  robot_config_.end_effector_link = "robotiq_85";

  cal_params_.config = robot_config_;
}

//void CalibraionInterface::RepositionAccepted()
//{
//  for (size_t i = 0; i < sensor_uids_.size(); i++) {
//      std::string curr_uid = sensor_uids_[i];
//      Eigen::Affine3f guess = cal_mgr_->GetInitGuess(curr_uid);
//      float a[16];
//      int count = 0;
//      for (int i = 0; i < 4; i++) {
//          for (int j = 0; j < 4; j++) {
//              a[count] = guess(i, j);
//              count++;
//            }
//        }
//      Mat4 pose(a);
//      if (!pose.IsIdentity()) {
//          canvas_->AddSensor(curr_uid, pose);
//        }
//    }

//  // TODO: get live stream to resume once the dialog is closed
//}

//void CalibraionInterface::AddRobotToCanvas() {
//  std::cout << "The robot is being added in thread: " << std::this_thread::get_id() << std::endl;
//  // May cause bugs if moved to another thread -----------------------
//  RTR_LOG_INFO("Adding robot to 3d canvas..." << std::endl);
////  canvas_->AddRobot(robot_mgr_->GetRobot());
////  canvas_->AddInterface(robot_xface_);
//  //-----------------------------------------------------------------
//}

void CalibraionInterface::GetRobot(rtr::Robot::Ptr &robot, rtr::RobotInterface::Ptr &interface) {
  std::cout << "The robot is being added in thread: " << std::this_thread::get_id() << std::endl;
  // May cause bugs if moved to another thread -----------------------
  RTR_LOG_INFO("Adding robot to 3d canvas..." << std::endl);

//  canvas_->AddRobot(robot_mgr_->GetRobot());
//  canvas_->AddInterface(robot_xface_);
  //-----------------------------------------------------------------

  robot = robot_mgr_->GetRobot();
  interface  = robot_xface_;
}

bool CalibraionInterface::FindInitGuess(Mat4 &pose)
{
  bool ret = false;

for (size_t i = 0; i < sensor_uids_.size(); i++) {
    std::string curr_uid = sensor_uids_[i];
    Eigen::Affine3f guess = cal_mgr_->GetInitGuess(curr_uid);
    float a[16];
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            a[count] = guess(i, j);
            count++;
          }
      }
//    Mat4 pose(a);
    pose = a;
    if (!pose.IsIdentity()) {
//        canvas_->AddSensor(curr_uid, pose);
        ret = true;
      }
  }
  return ret;
}

void CalibraionInterface::SetRobotSelection(int &index) {
  robot_config_.robot_type = static_cast<rtr::SupportedRobot>(index);
  //  qDebug() << "Robot selection set as " << rtr::GetRobotTypeString(robot_config_.robot_type);

}

void CalibrationInterface::SetPackagePath(QString &input) {

  robot_config_.ros_package_path = input.toStdString();
  std::cout << "ROS pkg path set as " << robot_config_.ros_package_path << std::endl;

  if (robot_config_.robot_type == rtr::SupportedRobot::FANUCLRMate200iD) {
      robot_config_.urdf_path =
          robot_config_.ros_package_path
          + "/robot_models/fanuc_lrmate200id_7l/urdf/fanuc7l_big_fiducial_new_perception_stack.urdf";
    } else if (robot_config_.robot_type == rtr::SupportedRobot::UR3) {
      // TODO: input a urdf_path_ for the UR3 here
      robot_config_.urdf_path =
          robot_config_.ros_package_path + "/robot_models/ur3/urdf/ur3_med_fiducial_benchmark.urdf";
    } else {
      // UR5 or DummyRobot
      robot_config_.urdf_path =
          robot_config_.ros_package_path + "/robot_models/ur5/urdf/ur5_big_fiducial.urdf";
    }
  robot_selected_ = true;
}

void CalibrationInterface::SetIPAddress(QString &input) {
  robot_config_.ip_address = input.toStdString();
  std::cout << "IP address set as " << robot_config_.ip_address << std::endl;
}

void CalibrationInterface::DoCalibrate()
{
  std::cout << "Attempting calibration with camera : " << active_uid_ << std::endl;
  Eigen::Affine3f guess = cal_mgr_->GetInitGuess(active_uid_);
  float a[16];
  int count = 0;
  for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
          a[count] = guess(i, j);
          count++;
        }
    }
  Mat4 pose(a);
  if (pose.IsIdentity()) {
      std::cout << "Error: the camera you have selected for calibration"
                << " does not have a valid seed pose yet. Use the reposition "
                << " dialog to seed pose generation, then try again..." << std::endl;
      return;
    } else {
      std::cout << "Beginning calibration" << std::endl;
      // TODO: use the enabled calibrators and selected cal modes
      cal_mgr_->SetupCalibrationRoutine(active_uid_, CalibrationMode::EXTRINSICS);
    }


}
