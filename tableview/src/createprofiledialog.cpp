#include <QFileDialog>
#include <QDebug>
#include "createprofiledialog.h"
#include "ui_createprofiledialog.h"

CreateProfileDialog::CreateProfileDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::CreateProfileDialog) {
  ui->setupUi(this);
}

CreateProfileDialog::~CreateProfileDialog() {
  delete ui;
}

void CreateProfileDialog::SetSupportingPlate(QList<QString> &plates)
{
  ui->comboBox_Plate->clear();

  for(int i=0;i<plates.size();i++)
    ui->comboBox_Plate->insertItem(i, plates[i]);
}

void CreateProfileDialog::SetSupportingRobots(QList<QString> &robots)
{
    ui->comboBox_RobotType->clear();

    for(int i=0;i<robots.size();i++)
      ui->comboBox_RobotType->insertItem(i, robots[i]);
 }

void CreateProfileDialog::on_toolButton_packagePath_clicked()
{
  QString filename = QFileDialog::getExistingDirectory(
      this, tr("Select a package directory"),
      QDir::currentPath() ,
      QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

  if(!filename.isEmpty())
    ui->lineEdit_packagePath->setText(filename);
}

void CreateProfileDialog::on_toolButton_sceneUrdfFile_clicked()
{
  QString filename = QFileDialog::getExistingDirectory(
      this, tr("Select a package directory"),
      QDir::currentPath() ,
      QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

  if(!filename.isEmpty())
    ui->lineEdit_sceneUrdf->setText(filename);
}

void CreateProfileDialog::on_toolButton_robotUrdfFile_clicked()
{
  QString filename = QFileDialog::getExistingDirectory(
      this, tr("Select a package directory"),
      QDir::currentPath() ,
      QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

  if(!filename.isEmpty())
    ui->lineEdit_robotUrdf->setText(filename);
}


void CreateProfileDialog::on_comboBox_Plate_currentIndexChanged(const QString& arg1) {
  Q_UNUSED(arg1);
}

void CreateProfileDialog::on_comboBox_RobotType_currentIndexChanged(const QString& arg1) {
  // if robot is custom, disable
  if(arg1.contains(QString("Custom")))
    {
      ui->label_robotUrdf->setEnabled(false);
      ui->label_packagePath->setEnabled(false);
      ui->toolButton_robotUrdfFile->setEnabled(false);
      ui->toolButton_packagePath->setEnabled(false);
      ui->lineEdit_robotUrdf->setEnabled(false);
      ui->lineEdit_packagePath->setEnabled(false);
    }
  else{
      ui->label_robotUrdf->setEnabled(true);
      ui->label_packagePath->setEnabled(true);
      ui->toolButton_robotUrdfFile->setEnabled(true);
      ui->toolButton_packagePath->setEnabled(true);
      ui->lineEdit_robotUrdf->setEnabled(true);
      ui->lineEdit_packagePath->setEnabled(true);
    }
}

void CreateProfileDialog::on_pushButton_cancel_clicked()
{
  reject();
}

void CreateProfileDialog::on_pushButton_save_clicked()
{
  // close this dialog
  accept();
}

