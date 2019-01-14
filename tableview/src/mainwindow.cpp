#include "mainwindow.h"
#include <QDebug>
#include <QFrame>
#include <QLayout>
#include <QList>
#include <QString>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QMessageBox>
#include "buttonlabel.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  QCoreApplication::setOrganizationName("Realtime Robotics");
  QCoreApplication::setOrganizationDomain("rtr.ai");
  QCoreApplication::setApplicationName("Camera Calibration");

  qRegisterMetaType<ConfigSettings>("ConfigSettings");
  qRegisterMetaTypeStreamOperators<ConfigSettings>("ConfigSettings");

  ui->setupUi(this);

  homeWidget_ = new HomeWidget(this);
  page_map_["Home"] = homeWidget_;
  homeWidget_->setObjectName("Home");
  ui->stackedWidget->addWidget(homeWidget_);

  cameraTableWidget_ = new CameraTableWidget(this);
  page_map_["Setting"] = cameraTableWidget_;
  cameraTableWidget_->setObjectName("Setting");
  ui->stackedWidget->addWidget(cameraTableWidget_);

//  calibrationWidget_ = new CalibrationWidget(this);
//  page_map_["Calibrate"] = calibrationWidget_;
//  calibrationWidget_->setObjectName("Calibrate");
//  ui->stackedWidget->addWidget(calibrationWidget_);

  // create navigation bar
  //    CreateNaviButton();

  LoadSetting();

  SwitchPage("Home");
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::closeEvent(QCloseEvent* event) {
#ifdef BACKEND_CONNECTED
  cameraTableWidget_->ExitHandler();
#endif

  SaveGuiSettings();
  cameraTableWidget_->SaveSettings();
  event->accept();
}

void MainWindow::CreateNaviButton() {
  button_home = new ButtonLabel(ui->frame);
  button_home->setObjectName(QStringLiteral("button_home"));
  button_home->setText(page_map_["Home"]->objectName());
  button_home->hide();
  connect(button_home, SIGNAL(clicked(QString)), this, SLOT(SwitchPage(QString)));

  button_setting = new ButtonLabel(ui->frame);
  button_setting->setObjectName(QStringLiteral("button_setting"));
  button_setting->setText(page_map_["Setting"]->objectName());
  button_setting->hide();
  connect(button_setting, SIGNAL(clicked(QString)), this, SLOT(SwitchPage(QString)));

  button_calibration = new ButtonLabel(ui->frame);
  button_calibration->setObjectName(QStringLiteral("button_calibration"));
  button_calibration->setText(page_map_["Calibrate"]->objectName());
  button_calibration->hide();
  connect(button_calibration, SIGNAL(clicked(QString)), this, SLOT(SwitchPage(QString)));

  button_exit = new ButtonLabel(ui->frame);
  button_exit->setObjectName(QStringLiteral("button_exit"));
  button_exit->setText("Exit");  //(page_map_["Exit"]->objectName());
  button_exit->hide();
  connect(button_exit, SIGNAL(clicked(QString)), this, SLOT(SwitchPage(QString)));

  button_help = new ButtonLabel(ui->frame);
  button_help->setObjectName(QStringLiteral("button_help"));
  button_help->setText("Help");  //(page_map_["Exit"]->objectName());
  button_help->hide();
  connect(button_help, SIGNAL(clicked(QString)), this, SLOT(SwitchPage(QString)));
}

void MainWindow::naviButtonClicked(QString buttonName) {
  qDebug() << "Navibutton Clicked" << buttonName;

  if (page_map_.contains(buttonName)) {
    QWidget* widget = page_map_[buttonName];
    ui->stackedWidget->setCurrentWidget(widget);  // showing page widget

    //      widget->adjustSize();
    //      ui->stackedWidget->adjustSize();

    //      updateNaviButton(buttonName) {
  }
}

void MainWindow::updateNaviButton(QString buttonName) {
  if(page_map_.contains(buttonName))
    {
      QLayout* horizontalLayout =ui->frame->layout();
      // clear navibar
      if(!horizontalLayout->isEmpty())
        {
          QLayoutItem *item;

          while ((item = horizontalLayout->takeAt(0)) != 0)  {
              if(item->widget())
                {
                  //                delete item->widget();
                  QWidget *w = item->widget();
                  horizontalLayout->removeWidget(w);

                }
              else
                delete item;
            }
          horizontalLayout->update();

        }
      if(buttonName.contains("Home"))
        {
          button_setting = new ButtonLabel(ui->frame);
          button_setting->setObjectName(QStringLiteral("button_setting"));
          button_setting->setText(page_map_["Setting"]->objectName());
          horizontalLayout->addWidget(button_setting);
          connect(button_setting, SIGNAL(clicked(QString)), this, SLOT(SwitchPage(QString)));


          QSpacerItem* horizontalSpacer =
              new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
          horizontalLayout->addItem(horizontalSpacer);

          //              horizontalLayout->addWidget(button_exit);
          //              button_exit->show();
          button_exit = new ButtonLabel(ui->frame);
          button_exit->setObjectName(QStringLiteral("button_exit"));
          button_exit->setText("Exit"); //(page_map_["Exit"]->objectName());
          horizontalLayout->addWidget(button_exit);
          connect(button_exit, SIGNAL(clicked(QString)), this, SLOT(SwitchPage(QString)));
        }
      else if(buttonName.contains("Setting"))
        {

          button_home  = new ButtonLabel(ui->frame);
          button_home->setObjectName(QStringLiteral("button_home"));
          button_home->setText(page_map_["Home"]->objectName());
          horizontalLayout->addWidget(button_home);
          connect(button_home, SIGNAL(clicked(QString)), this, SLOT(SwitchPage(QString)));

          QSpacerItem* horizontalSpacer =
              new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
          horizontalLayout->addItem(horizontalSpacer);

          button_calibration= new ButtonLabel(ui->frame);
          button_calibration->setObjectName(QStringLiteral("button_calibration"));
          button_calibration->setText(page_map_["Calibrate"]->objectName());
          horizontalLayout->addWidget(button_calibration);
          connect(button_calibration, SIGNAL(clicked(QString)), this, SLOT(SwitchPage(QString)));


          horizontalSpacer =
              new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
          horizontalLayout->addItem(horizontalSpacer);

          button_exit = new ButtonLabel(ui->frame);
          button_exit->setObjectName(QStringLiteral("button_exit"));
          button_exit->setText("Exit"); //(page_map_["Exit"]->objectName());
          horizontalLayout->addWidget(button_exit);
          connect(button_exit, SIGNAL(clicked(QString)), this, SLOT(SwitchPage(QString)));


        }
      else if(buttonName.contains("Calibrate"))
        {
          button_setting = new ButtonLabel(ui->frame);
          button_setting->setObjectName(QStringLiteral("button_setting"));
          button_setting->setText(page_map_["Setting"]->objectName());
          horizontalLayout->addWidget(button_setting);
          connect(button_setting, SIGNAL(clicked(QString)), this, SLOT(SwitchPage(QString)));


          QSpacerItem* horizontalSpacer =
              new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
          horizontalLayout->addItem(horizontalSpacer);

          //              horizontalLayout->addWidget(button_exit);
          //              button_exit->show();
          button_exit = new ButtonLabel(ui->frame);
          button_exit->setObjectName(QStringLiteral("button_exit"));
          button_exit->setText("Exit"); //(page_map_["Exit"]->objectName());
          horizontalLayout->addWidget(button_exit);
          connect(button_exit, SIGNAL(clicked(QString)), this, SLOT(SwitchPage(QString)));
        }
    }
  else
    {
      if(buttonName.contains("Exit"))
        {


        }
      else if(buttonName.contains("Help"))
        {

        }
    }
}

void MainWindow::SwitchPage(QString buttonName) {

//  if(buttonName.contains("Calibrate"))
//    {
//      CameraMap cameraMap;

//      if(GetCameraMap(cameraMap)){
//          calibrationWidget_->populateTable(cameraMap);
//        }
//      else
//        {
//          // error message box
//          QMessageBox msgBox;
//          msgBox.setText(DefineToText(ErrorMessage::SENSOR_NOT_CONNECTED));
//          msgBox.setIcon(QMessageBox::Warning);
//          msgBox.setInformativeText("Please check sensors");
//          msgBox.setStandardButtons(QMessageBox::Ok);
//          int ret = msgBox.exec();

//          return;
//        }
//    }

  naviButtonClicked(buttonName);
}

bool MainWindow::GetCameraMap(CameraMap &cameraMap)
{
  if(cameraTableWidget_->GetCameraMap(cameraMap))
    return true;
  else
    return false;
}

void MainWindow::LoadSetting() {
  GuiScreenSizeInfo gui_config;

  LoadGuiSettings(gui_config);
  resize(gui_config.screen_width, gui_config.screen_height);

  cameraTableWidget_->SetGuiSettings(gui_config);
  cameraTableWidget_->LoadRobotSettings();
  cameraTableWidget_->LoadSensorSettings();
}

void MainWindow::SaveGuiSettings() {

      QSettings settings;
      GuiScreenSizeInfo sizeInfo;
      sizeInfo.screen_width = this->width(); //ui->centralWidget->width();
      sizeInfo.screen_height = this->height(); //ui->centralWidget->height();

      settings.beginGroup("screen");
      settings.setValue("width", sizeInfo.screen_width);
      settings.setValue("height", sizeInfo.screen_height);
//      settings.setValue("tableWidth", gui_config_.table_width);
//      settings.setValue("tableHeight", gui_config_.table_height);

//      for(int i=0; i < sizeInfo.table_columnWidth.size(); i++)
//        {
//          settings.setValue(QString("column") + QString::number(i), sizeInfo.table_columnWidth[i]);
//        }
      settings.endGroup();

//      cameraTableWidget_->SaveSettings();
}

bool MainWindow::LoadGuiSettings(GuiScreenSizeInfo &sizeInfo) {

  QSettings settings;

  settings.beginGroup("screen");
    sizeInfo.screen_width = settings.value("width").toInt();
    sizeInfo.screen_height = settings.value("height").toInt();
    sizeInfo.table_width = settings.value("tableWidth").toInt();
    sizeInfo.table_height = settings.value("tableHeight").toInt();
    // column width
    QStringList keys = settings.allKeys();
    QStringList column_keys = keys.filter("column");
    sizeInfo.table_columnWidth.resize(column_keys.size());
    for(int i=0;i < column_keys.size(); i++)
      {
        int column = column_keys[i].mid(QString("column").size()).toInt();
        sizeInfo.table_columnWidth[column] = settings.value("column" + QString::number(column)).toInt();
      }

  settings.endGroup();

  return true;
}
