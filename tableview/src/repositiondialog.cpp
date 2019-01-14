#include <QDebug>
#include <QMessageBox>
#include <QDialog>
#include <QSpacerItem>

#include "repositiondialog.h"
#include "ui_repositiondialog.h"


#ifdef  BACKEND_CONNECTED
#include "calibrationInterface.h"
#else
#include "GuiBackendInterface.h"
#endif

RepositionDialog::RepositionDialog(QWidget* parent, BackendInterface *backendManager)
  : QDialog(parent), ui_reposition(new Ui::Dialog_Reposition)
{
  ui_reposition->setupUi(this);

  ui_reposition->pushButton_accept->setVisible(false);

  led = new FlashingLed();
  ui_reposition->horizontalLayout_status->insertWidget(0,led);

  ui_reposition->label_status->setText("Repositon Not Started");

//  label_status = new QLabel();
//  ui_reposition->horizontalLayout_status->addWidget(label_status);

//  QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
//  ui_reposition->horizontalLayout_status->addItem(spacer);

#ifdef  BACKEND_CONNECTED
  calibrationInterface =  dynamic_cast<CalibrationInterface *>(backendManager);
#else
  calibrationInterface = dynamic_cast<GuiBackendInterface *>(backendManager);
#endif

  connect(calibrationInterface, SIGNAL(InitialPoseFinished(ErrorMessage)),this, SLOT(on_received_fiducial(ErrorMessage)));
  connect(calibrationInterface, SIGNAL(InitialPoseStatus(bool)),this, SLOT(on_received_status(bool)));

  connect(ui_reposition->pushButton_skip, SIGNAL(clicked()), SLOT(on_Skipped()));
  connect(ui_reposition->pushButton_cancel, SIGNAL(clicked()), SLOT(on_Cancelled()));
  connect(ui_reposition->pushButton_continue, SIGNAL(clicked()), SLOT(on_Continued()));
}

RepositionDialog::~RepositionDialog() {
  delete ui_reposition;
  if(led) delete led;
}

//void RepositionDialog::ProcessFrame(QImage &curr_frame) {
//  QPixmap pm = QPixmap::fromImage(
//      curr_frame.scaledToHeight(250).rgbSwapped());  // TODO: ask David about properly showing this
//  if (!pm.isNull()) {
//    ui_reposition->label_view->setPixmap(pm);
//  }
//}

//! Method for constructing the joint jog panel with joint limits from the URDF
//! Method for constructing the joint jog panel with joint limits from the URDF
void RepositionDialog::SetupJogSliders() {
  std::vector<std::string> joint_names = {"shoulder_pan_joint", "shoulder_lift_joint",
                                          "elbow_joint",        "wrist_1_joint",
                                          "wrist_2_joint",      "wrist_3_joint"};

  size_t no_joint = joint_names.size();

  std::vector<float> joint_max(no_joint) ;
//  rtr::JointConfiguration joint_min_ ;
  std::vector<float> joint_min(no_joint);
  std::vector<float> state(no_joint);
  calibrationInterface->GetRobotJointLimits(joint_min, joint_max);

  calibrationInterface->GetCurrentConfiguration(state);
//  if(calibrationInterface->SetupJogSliders(joint_min_, joint_max_))
    {

  qDebug()  << "Setting joint limits...";
  // Setup Joint Slider Panel
  if (joint_max.size() > 0 && joint_min.size() > 0) // && state.Size() > 0) {
    std::stringstream ss;
    for (size_t i = 0; i < joint_max.size(); i++) {
//      std::stringstream ss = std::stringstream();
//      ss << "J" << static_cast<int>(i + 1) << std::endl;
      QString joint_name = QString("J") + QString::number(i+1);
      RTRSlider* new_slider =
          new RTRSlider(this, joint_name /*QString::fromStdString(ss.str())*/, rtr::RtoD(joint_min[i]),
                        rtr::RtoD(joint_max[i]), state[i], true, true);
      QLayout *layout = ui_reposition->frame_robot->layout();
      layout->addWidget(new_slider);
      connect(new_slider, SIGNAL(valueChanged(QString&, float)), this,
              SLOT(NudgeRobotConfig(QString&, float)));
      sliders_.push_back(new_slider);
    }
//  } else {
//    qDebug() << "Error: Joint limits could not be set! "; // ToDo: implement register to RTR_LOG_ERROR
//      //    RTR_LOG_ERROR("Error: Joint limits could not be set! ");
  }
}


void RepositionDialog::NudgeRobotConfig(QString& joint_name, float newValue) {
  rtr::JointConfiguration config;

  config = calibrationInterface->NudgeRobotConfig(joint_name, newValue);

  // ToDo: this needs to be done inside slider class
//  for (size_t i = 0; i < config.Size(); i++) {
//    if (sliders_.size() > 0) {
//      sliders_[i]->SetValue(config[i]);
//    }
//  }
}

void RepositionDialog::SetCameraProperty(CameraNode &node)
{

  current_uid_ = node.uuid_;

  if(!node.alias_.isEmpty())
    ui_reposition->label_camera->setText(node.alias_);

  if(!node.f_seedPose_)
    {
      ui_reposition->pushButton_skip->hide();
    }

}

void RepositionDialog::on_Cancelled()
{
  reject();
}


void RepositionDialog::on_Skipped()
{
  accept();
}

void RepositionDialog::on_Continued()
{
  qDebug() << Q_FUNC_INFO;
  // proceed reposition process;

  // information message box
  QMessageBox msgBox;
  msgBox.setText("Position a calibration plate");
  msgBox.setIcon(QMessageBox::Information);
  msgBox.setInformativeText("Please move plate manually or using Jog tool. For information about connecting a plate, press \"Help\" buton");
  QAbstractButton *helpButton =
      msgBox.addButton(tr("Help"), QMessageBox::ActionRole);
  msgBox.setStandardButtons(QMessageBox::Ok);
  int ret = msgBox.exec();

  if (msgBox.clickedButton() == helpButton) {
    // open panel installation page
    }

  switch(ret)
    {
    case QMessageBox::Ok:

      // disable buttons

      if(!   ui_reposition->pushButton_skip->isHidden())
        {
          ui_reposition->pushButton_skip->setEnabled(false);
        }
      ui_reposition->pushButton_continue->setEnabled(false);
      ui_reposition->pushButton_cancel->setEnabled(true);

      ui_reposition->label_status->setText("Starting ...");

      // start repositioning

      calibrationInterface->FindSeedPose(current_uid_.toStdString());
      break;

    default:
      break;
    }
}

void RepositionDialog::on_received_fiducial(ErrorMessage msg)
{
  // show status messagebox

  if(msg == ErrorMessage::NO_ERROR)
    {
      ui_reposition->label_status->setText("Successfully found initial pose.");

      // update table , message to parent
      accept();
    }
  else {
      // error messagebox

      // update table

      // udate canvas
      //      Mat4 pose(a);
      //      if (!pose.IsIdentity()) {
      //          canvas_->AddSensor(curr_uid, pose);
      //        }

    }
}

void RepositionDialog::on_received_status(bool status)
{
  if(status)
    {
      ui_reposition->label_status->setText("Plate is identified");
      led->setState(true);
      led->setColor(Qt::cyan);
      led->startFlashing();

      // display "Accept" button
      ui_reposition->pushButton_accept->setVisible(true);
    }
  else {
      ui_reposition->label_status->setText("Finding plate ...");
      ui_reposition->pushButton_accept->setVisible(false);
    }
}

void RepositionDialog::on_pushButton_accept_clicked()
{
  calibrationInterface->ExitReposition();
}
