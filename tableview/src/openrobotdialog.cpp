#include "openrobotdialog.h"
#include "ui_openrobotdialog.h"
#include <QFileDialog>
#include <QDir>


OpenRobotDialog::OpenRobotDialog(QWidget* parent) : QDialog(parent), ui(new Ui::OpenRobotDialog) {
  ui->setupUi(this);

  connect(ui->pushButton_openfile, SIGNAL(clicked()), this, SLOT(OnProfileOpenClicked()));
}

OpenRobotDialog::~OpenRobotDialog() {
  delete ui;
}


void OpenRobotDialog::OnProfileOpenClicked() {
//  QString filename = QFileDialog::getExistingDirectory(
//      this, tr("Select a package directory"),
//      robot_.path_.isEmpty() ? QDir::currentPath() : robot_.path_,
//      QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
#ifdef BACKEND_CONNECTED
    robot_config_.ros_package_path = filename.toStdString();
    #endif
//    qDebug() << "selected file path : " << filename.toUtf8();

    {
//      robot_.type_ = ui_setting->comboBox_RobotType->currentText();
//      robot_.plate_ = ui_setting->comboBox_Plate->currentText();
//      robot_.path_ = ui_setting->lineEdit_PackagePath->text();
//      robot_.ip_ = ui_setting->lineEdit_RobotIp->text();

//      config_.SaveRobotSettings(robot_);
    }
}
