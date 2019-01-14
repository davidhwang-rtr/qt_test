#include "cameratablewidget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QRadioButton>
#include <QComboBox>
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QPixmap>

#include <QLineEdit>
#include <QSurfaceFormat>
#include "mainwindow.h"

//
// fake camera list
//
CameraNode camera1(QString("X Axis"), QString("Realsense D435"), CameraNode::CalibrationMode::ALL, true, false);
CameraNode camera2(QString("Y Axis"), QString("Realsense D435"), CameraNode::CalibrationMode::STEREO, true, true);
CameraNode camera3(QString("Z Axis"), QString("Realsense D415"), CameraNode::CalibrationMode::EXTRINSICS, false, true);
CameraNode camera4(QString("Z Axis"), QString("Realsense D415"), CameraNode::CalibrationMode::EXTRINSICS, true, true);
CameraNode camera5(QString("Z Axis"), QString("Realsense D415"), CameraNode::CalibrationMode::EXTRINSICS, false, true);

CameraTableWidget::CameraTableWidget(QWidget* parent)
    : QWidget(parent), ui_setting(new Ui::ConfigWidget)
    ,robot(nullptr)
    ,xface(nullptr)
    ,max_image_size_(0)
    ,state_(CalibrationState::NOT_READY)
{
    mainwindow_ = dynamic_cast<MainWindow *>(parent);


    // initialize GUI
    ui_setting->setupUi(this);


  ui_setting->pushButton_home->setStyleSheet(
                                              QLatin1String("background-color: rgb(85, 87, 83);\n"
                                                            "color: rgb(255, 255, 255);"));
  ui_setting->pushButton_calibration->setStyleSheet(
                                              QLatin1String("background-color: rgb(85, 87, 83);\n"
                                                            "color: rgb(255, 255, 255);"));
  if(fileName.isEmpty())
    ui_setting->pushButton_connect->setEnabled(false);


  InitSensorUi();

  InitRobotUi();

  // TODO: remove these calls, just here to speed up testing
//  SetPackagePath(QString("/home/samtitle/Desktop/rtr_repos/rapidplan/src/robots"));
//  SetRobotSelection(3);
//  SetIPAddress(QString("1.1.1.1"));
//  SetFiducialSelection(0)

#ifndef BACKEND_CONNECTED
  calibrationInterface = new GuiBackendInterface();
#else
    calibrationInterface = new CalibrationInterface();
#endif

#ifdef GUI_SIMULATION
    SetUpRobots();
#endif
    // Setup 3d viewing canvas
    // Change some settings for smoother graphics
    QSurfaceFormat format;
    format.setSamples(2);
    QSurfaceFormat::setDefaultFormat(format);
//    canvas_= new rtr::Canvas();

//    QLayout *canvasLayout = ui_setting->frame->layout();
//    canvasLayout->addWidget(canvas_);

  connect(calibrationInterface, SIGNAL(sendFrame(QPixmap)),this,SLOT(receiveFrame(QPixmap)));
  connect(this,SIGNAL(FinishedCalibration()),this,SLOT(on_finishedCalibration()));

  // To Do
  connect(this,SIGNAL(robotSelectionChanged(int)),calibrationInterface, SLOT(SetRobotSelection(int)));
  connect(this,SIGNAL(packagePathChanged(QString)),calibrationInterface, SLOT(SetPackagePath(QString)));
  connect(this,SIGNAL(iPAddressChanged(QString)),calibrationInterface, SLOT(SetIPAddress(QString)));
}

CameraTableWidget::~CameraTableWidget() {
  delete ui_setting;
}

// pre-requisite: robot information

void CameraTableWidget::InitRobotUi() {

//  connect(ui_setting->lineEdit_PackagePath, SIGNAL(textEdited(QString)), this,
//          SLOT(SetPackagePath(QString)));

//  connect(ui_setting->lineEdit_RobotIp, SIGNAL(textEdited(QString)), this,
//          SLOT(SetIPAddress(QString)));

  ui_setting->frame_detail->hide();

}

void CameraTableWidget::InitSensorUi() {
    // set up table

//    ui_setting->tableSensor->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui_setting->tableSensor->horizontalHeader()->setStretchLastSection(true);
    ui_setting->tableSensor->resizeRowsToContents();
    ui_setting->tableSensor->horizontalHeader()->setVisible(true);
    ui_setting->tableSensor->verticalHeader()->setVisible(true);

    connect(ui_setting->tableSensor, SIGNAL(itemClicked(QTableWidgetItem*)), this,
            SLOT(TableItemClicked(QTableWidgetItem*)));
    connect(ui_setting->tableSensor, SIGNAL(cellClicked(int, int)), this,
            SLOT(TableCellClicked(int, int)));
    connect(ui_setting->tableSensor, SIGNAL(cellPressed(int, int)), this,
            SLOT(TableCellPressed(int, int)));
    connect(ui_setting->tableSensor, SIGNAL(cellChanged(int, int)), this,
            SLOT(TableCellChanged(int, int)));

    // table header
    QStringList headerList;
    headerList << "Name"
//               << "Serial Number"
               << "Model"
               << "Calibration Mode"
               << "Enable"
//               << "Seed Pose Status"
               << "Last Performed Date"
               << ""
               << "Status"
               << "Confidence"
//               << "Accuracy"
//               << "Projection"
               << ""; // dummy last column
    ui_setting->tableSensor->setColumnCount(headerList.size());
    ui_setting->tableSensor->setHorizontalHeaderLabels(headerList);
}

int CameraTableWidget::GetSizeOfViewToContents() {
    int count = ui_setting->tableSensor->verticalHeader()->count();
    //    int scrollBarHeight=ui->tableWidget_Robot->horizontalScrollBar()->height();
    int horizontalHeaderHeight = ui_setting->tableSensor->horizontalHeader()->height();
    int rowTotalHeight = 0;
    for (int i = 0; i < count; ++i) {
        // 2018-03 edit: only account for row if it is visible
        if (!ui_setting->tableSensor->verticalHeader()->isSectionHidden(i)) {
            rowTotalHeight += ui_setting->tableSensor->verticalHeader()->sectionSize(i);
        }
    }

    return rowTotalHeight + horizontalHeaderHeight;
}

void CameraTableWidget::SetupSensorTable() {
    // populate table
    PopulateTable(camera_map_);
}

void CameraTableWidget::SetRobotSetting(RobotInfo &robot)
{
  robot_ = robot;
}

void CameraTableWidget::SetCameraSetting(CameraMap &camera)
{
  camera_map_ = camera;
}

bool CameraTableWidget::GetCameraMap(CameraMap& cameraMap) const {
  bool ret;

  if (camera_map_.size()) {
      cameraMap = camera_map_;
      ret = true;
    } else {
      ret = false;
    }

  return ret;
}

bool CameraTableWidget::GetRobotConfig(RobotInfo &robot) const
{
    bool ret;

    if(!robot_.type_.isEmpty())
    {
        robot = robot_;
        ret = true;
    }
    else
    {
        ret = false;
    }
    return ret;
}

void CameraTableWidget::PopulateTable(const CameraMap & camera_list) {
    ui_setting->tableSensor->setRowCount(static_cast<int>(camera_list.size()));

    QMap<QString, CameraNode>::const_iterator iter;
    int row;

    for (iter = camera_list.begin(), row = 0; iter != camera_list.end(); iter++, row++) {
        CameraNode node = iter.value();

        for (int col = 0; col < ui_setting->tableSensor->columnCount(); col++) {
            if (col == ColumnId::NICK_NAME)  // qlineedit
            {
                QWidget* pWidget = new QWidget();
                QLineEdit* lineEdit_1 = new QLineEdit(ui_setting->tableSensor);
                lineEdit_1->setObjectName(QString("name_%1").arg(row));
                lineEdit_1->setText(node.alias_);
                connect(lineEdit_1, SIGNAL(editingFinished()), this, SLOT(OnTableContentChanged()));
                QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
                pLayout->addWidget(lineEdit_1);
                pLayout->setAlignment(Qt::AlignCenter);
                //              pLayout->setContentsMargins(0, 0, 0, 0);
                pWidget->setLayout(pLayout);
                ui_setting->tableSensor->setCellWidget(row, col, pWidget);

            } else if (col == ColumnId::MODEL)  // qstring
            {
//                QTableWidgetItem* newItem = new QTableWidgetItem(node.model_);
//                newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
//                ui_setting->tableSensor->setItem(row, col, newItem);

                table_node_[row] = node.uuid_;
                QWidget *newItem = CreateSensorProfileWidget(node);
                ui_setting->tableSensor->setCellWidget(row, col, newItem);
            } else if (col == ColumnId::MODE)  // checkboxes
            {
                QWidget* pWidget = new QWidget();
                QComboBox* comboBox = new QComboBox(ui_setting->tableSensor);
                comboBox->addItem(QString(DefineToText(ALL)));
                comboBox->addItem(QString(DefineToText(STEREO)));
                comboBox->addItem(QString(DefineToText(EXTRINSICS)));
                comboBox->setCurrentIndex(static_cast<int>(node.mode_));
                comboBox->setObjectName(QString("mode_%1").arg(row));
                // comboBox->setCurrentIndex(node.mode_);
                connect(comboBox, SIGNAL(currentIndexChanged(int)), this,
                        SLOT(OnCalibrationModeChanged(int)));
                QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
                pLayout->addWidget(comboBox);
                pLayout->setAlignment(Qt::AlignCenter);
                pLayout->setContentsMargins(0, 0, 0, 0);
                pWidget->setLayout(pLayout);
                ui_setting->tableSensor->setCellWidget(row, col, pWidget);  // groupBox);

            } else if (col == ColumnId::ENABLE)  // qstring
            {
                QTableWidgetItem* newItem = new QTableWidgetItem("Enable");
                Qt::CheckState state = node.f_enable_ ? Qt::Checked : Qt::Unchecked;
                newItem->setCheckState(state);
                ui_setting->tableSensor->setItem(row, col, newItem);
            }
//            else if (col == ColumnId::POSE_STATUS)  // qstring
//            {
//                QLabel* lbl_item = new QLabel(ui_setting->tableSensor);
//                QIcon icon;
//                if (node.f_seedPose_)
//                    icon.addFile(":/images/checkmark-2.png");
//                else
//                    icon.addFile(":/images/cancel.png");

//                lbl_item->setPixmap(icon.pixmap(QSize(24, 24)));
//                lbl_item->setAlignment(Qt::AlignHCenter);

//                QWidget* pWidget = new QWidget();
//                QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
//                pLayout->addWidget(lbl_item);
//                pLayout->setAlignment(Qt::AlignCenter);
//                pLayout->setContentsMargins(0, 0, 0, 0);
//                pWidget->setLayout(pLayout);

//                ui_setting->tableSensor->setCellWidget(row, col, pWidget);
//              }
              else if (col == ColumnId::TIMESTAMP) {
                QTableWidgetItem* newItem = new QTableWidgetItem(node.timestamp.toString());
                newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
                ui_setting->tableSensor->setItem(row, col, newItem);

              } else if (col == ColumnId::CALIBRATION_BUTTON) {
                QWidget* pWidget = new QWidget();
                QPushButton* btn_edit = new QPushButton(ui_setting->tableSensor);
                btn_edit->setObjectName(QString("reposition_%1").arg(row));
                connect(btn_edit, SIGNAL(clicked()), this, SLOT(OnRepositionButtonClicked()));
                btn_edit->setText("Calibrate");
                btn_edit->setEnabled(node.f_enable_);
                QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
                pLayout->addWidget(btn_edit);
                pLayout->setAlignment(Qt::AlignCenter);
                pLayout->setContentsMargins(10, 5, 10, 5);
                pLayout->setSpacing(10);
                pWidget->setLayout(pLayout);
                ui_setting->tableSensor->setCellWidget(row, col, pWidget);
            } else if (col == ColumnId::SCORE_RESOLUTION) {  // score
                QTableWidgetItem* newItem = new QTableWidgetItem("");
                newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
                ui_setting->tableSensor->setItem(row, col, newItem);

//            } else if (col == ColumnId::SCORE_ACCURACY) {  // score
//                QTableWidgetItem* newItem = new QTableWidgetItem("");
//                newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
//                ui_setting->tableSensor->setItem(row, col, newItem);

//            } else if (col == ColumnId::SCORE_PROJECTION) {  // score
//                QTableWidgetItem* newItem = new QTableWidgetItem("");
//                newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
//                ui_setting->tableSensor->setItem(row, col, newItem);

            } else if (col == ColumnId::CALIBRATION_STATUS) {  // calibration result
                QLabel* lbl_item = new QLabel(ui_setting->tableSensor);
                QIcon icon;
                if (node.f_seedPose_)
                    icon.addFile(":/images/checkmark-2.png");
                else
                    icon.addFile(":/images/cancel.png");

                lbl_item->setPixmap(icon.pixmap(QSize(24, 24)));
                lbl_item->setAlignment(Qt::AlignHCenter);

                QProgressBar *progressBar = new QProgressBar(ui_setting->tableSensor);
                progressBar->setRange(0,100);
                progressBar->setObjectName(QStringLiteral("progressBar"));
                progressBar->setValue(50);
                progressBar->setTextVisible(true);
                progressBar->setInvertedAppearance(false);

                QWidget* pWidget = new QWidget();
                QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
                pLayout->addWidget(progressBar);
                pLayout->addWidget(lbl_item);
                pLayout->setAlignment(Qt::AlignCenter);
                pLayout->setContentsMargins(10, 5, 10, 5);
                pLayout->setSpacing(10);
                pWidget->setLayout(pLayout);
                ui_setting->tableSensor->setCellWidget(row, col, pWidget);
          }
        }
    }
}

// cell clicked

void CameraTableWidget::TableCellClicked(int row, int col) {
    qDebug() << "Cell Clicked: Column:" << col << " Row:" << row;
    if (col == ColumnId::ENABLE) {
        qDebug() << "enable checkbox clicked";

//        QString serial_no = ui_setting->tableSensor->item(row, 1)->text();
        // get cameraNode with uuid contains serial_no
        QString uuid;
        uuid = FindCameraNode(row);

        if(!uuid.isEmpty()) {
            // update date
            QTableWidgetItem *w;
            w = ui_setting->tableSensor->item(row,col);
            Qt::CheckState state = w->checkState();
            (state == Qt::Checked) ?  (camera_map_[uuid].f_enable_ = true) : (camera_map_[uuid].f_enable_ = false);

            // updaate gui
            // calibration button
            QPushButton* button;
            QWidget *cw;
            cw= ui_setting->tableSensor->cellWidget(row,ColumnId::CALIBRATION_BUTTON);
            QLayout *layout = cw->layout();
            QLayoutItem *item = layout->itemAt(0);
            button = dynamic_cast<QPushButton *>(item->widget());
            button->setEnabled(camera_map_[uuid].f_enable_);
          }

        calibrationInterface->SetSensorEnabled(uuid.toStdString(), camera_map_[uuid].f_enable_);

    }
}

//

void CameraTableWidget::TableItemClicked(QTableWidgetItem* item) {
  int col = ui_setting->tableSensor->currentColumn();

  qDebug() << "Current column " << col << "row: " << item->row();
}

// row cl

void CameraTableWidget::TableCellPressed(int row, int col) {
  qDebug() << "Cell Activated: Column:" << col << " Row:" << row;

//  QString serial_no = ui_setting->tableSensor->item(row, 1)->text();
  // get cameraNode with uuid contains serial_no
  QString uuid;
  uuid = FindCameraNode(row);

  calibrationInterface->SwitchSubscription(uuid.toStdString());
}

void CameraTableWidget::TableCellChanged(int row, int col) {
  qDebug() << "Cell Changed: Column:" << col << " Row:" << row;
}

// reposition button pressed

void CameraTableWidget::OnRepositionButtonClicked() {
  qDebug() << Q_FUNC_INFO;

  QPushButton* pb = qobject_cast<QPushButton*>(QObject::sender());

  QStringList parts = pb->objectName().split("_");
  int row = parts[1].toInt();

  qDebug() << "Reposition Button clicked: row:" << row;

    // aquiring cameara name
    QString alias;
    QLineEdit* edit;
    QWidget *w;
    w= ui_setting->tableSensor->cellWidget(row,0);
    QLayout *layout = w->layout();
    QLayoutItem *item = layout->itemAt(0);
    edit = dynamic_cast<QLineEdit *>(item->widget());
    alias = edit->text();

//    QString serial_no = ui_setting->tableSensor->item(row, 1)->text();
    // get cameraNode with uuid contains serial_no
    QString uuid;
    uuid = FindCameraNode(row);

    RepositionDialog repositionDialog(this,calibrationInterface);

    //    repositionDialog->SetName();
    connect(&repositionDialog, SIGNAL(accepted()), this, SLOT(RepositionAccepted()));
    connect(&repositionDialog, SIGNAL(rejected()), this, SLOT(RepositionRejected()));

    repositionDialog.setModal(true);
    repositionDialog.SetCameraProperty(camera_map_[uuid]);
    repositionDialog.exec();
}

void CameraTableWidget::RepositionAccepted() {
  // update camera is_positioned field & camera config
  qDebug() << Q_FUNC_INFO;

  // add camera to canvas

  // proceed calibration

  max_image_size_ = calibrationInterface->GetMaxCalibrationImageSet(current_uuid_.toStdString());

  connect(calibrationInterface,SIGNAL(CalibrationProgressUpdate(int)), this, SLOT(ReceivedCalibrationProgress(int)));

  calibrationInterface->DoCalibrate();
}

void CameraTableWidget::ReceivedCalibrationProgress(int index)
{
  if(index == (max_image_size_-1)){
      disconnect(calibrationInterface,SIGNAL(GetProgress(int)), this, SLOT(ReceivedCalibrationProgress(int)));

  // start progress if the first page
    emit FinishedCalibration();
  }
}

void CameraTableWidget::on_finishedCalibration()
{
  std::map<std::string,float> metrics;

  calibrationInterface->GetCalibrationMetrics(current_uuid_.toStdString(),metrics);
}

// cancel button pressed
void CameraTableWidget::RepositionRejected() {
  qDebug() << Q_FUNC_INFO;

  // do nothing yet
}

// alias changed

void CameraTableWidget::OnTableContentChanged() {
    QLineEdit* pb = qobject_cast<QLineEdit*>(QObject::sender());

    QString text = pb->text();
    qDebug() << "Alias changed to" << text;

    // change config info
    QStringList parts = pb->objectName().split("_");
    int row = parts[1].toInt();

//    QString serial_no = ui_setting->tableSensor->item(row, 1)->text();
    // get cameraNode with uuid contains serial_no
    QString uuid;
    uuid = FindCameraNode(row);
    if(!uuid.isEmpty()) {
         camera_map_[uuid].alias_ = text;
    }
}

void CameraTableWidget::OnCalibrationModeChanged(int index) {
    qDebug() << "Calibration mode index " << index;

    QComboBox* pb = qobject_cast<QComboBox*>(QObject::sender());

    CameraNode::CalibrationMode current_mode = static_cast<CameraNode::CalibrationMode>(pb->currentIndex()); //

    QStringList parts = pb->objectName().split("_");

     int row = parts[1].toInt(); // camera index

//     QString serial_no = ui_setting->tableSensor->item(row, 1)->text();
     // get cameraNode with uuid contains serial_no
     QString uuid;
     uuid = FindCameraNode(row);
     if(!uuid.isEmpty()) {
          camera_map_[uuid].mode_ = current_mode;

          calibrationInterface->SetCalibrationMode(uuid.toStdString(), camera_map_[uuid].mode_);
          //rtr::perception::CalibrationMode cal_mode);
       }

     qDebug() << "Calibration mode changed to " << current_mode << "of camera " << row ;
}

//void CameraTableWidget::OnPackagePathClicked() {
//      QString filename = QFileDialog::getExistingDirectory(
//          this, tr("Select a package directory"),
//          robot_.path_.isEmpty() ? QDir::currentPath() : robot_.path_,
//          QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

//      if (!filename.isNull()) {
//        ui_setting->lineEdit_PackagePath->setText(filename);
//    #ifdef CONNECTED_BACKEND
//        robot_config_.ros_package_path = filename.toStdString();
//        #endif
//        qDebug() << "selected file path : " << filename.toUtf8();
//      }
//}

void CameraTableWidget::on_pushButton_connect_clicked() {
#ifndef GUI_SIMULATION
  if(robot_.type_.isEmpty() || robot_.ip_.isEmpty() || robot_.plate_.isEmpty() || robot_.path_.isEmpty())
    {



      // error dialogbox
      QMessageBox msgBox;
      msgBox.setText(DefineToText(ErrorMessage::ROBOT_CONNECTION_FAIL));
      msgBox.setIcon(QMessageBox::Warning);
      msgBox.setInformativeText("Missing information");
      msgBox.setStandardButtons(QMessageBox::Ok);
      msgBox.exec();

      // To Do
//      QString detail;
//      DisplayMessageBox::Show(ErrorMessage::ROBOT_CONNECTION_FAIL,detail);

      return;
    }

#else
  robot_.type_ = ui_setting->comboBox_RobotType->currentText();
  robot_.path_ = ui_setting->lineEdit_PackagePath->text();
  robot_.ip_ = ui_setting->lineEdit_RobotIp->text();
  robot_.plate_ = ui_setting->comboBox_Plate->currentText();
#endif
  if(calibrationInterface->Connect(
       robot_.type_.toStdString(), robot_.path_.toStdString(),robot_.ip_.toStdString(), robot_.plate_.toStdString()))
    {
      state_ = CalibrationState::BACKEND_CONNECTED;

      std::vector<std::string> sensors;
      sensors = calibrationInterface->GetSensors();
      CameraMap temp_map;

      // Get robot
      calibrationInterface->GetRobot(robot, xface);

      // To Do
      // add to canvas

//      if(robot != nullptr){
//        canvas_->AddRobot(robot);
//      }
//      if(xface != nullptr){
//        canvas_->AddInterface(xface);
//      }

      if(!sensors.size())
        {
          // error: no camera found

          QMessageBox msgBox;
          msgBox.setText(DefineToText(ErrorMessage::SENSOR_CONNECTION_FAIL));
          msgBox.setIcon(QMessageBox::Warning);
          msgBox.setInformativeText("Cannot find sensors");
          msgBox.setStandardButtons(QMessageBox::Ok);
          msgBox.exec();

          return;
        }
      // fill in camera_map_
          for(size_t i=0; i<sensors.size(); i++)
            {
              CameraNode node;
               // find sensor in camera_map_
              QString uuid = QString(sensors[i].c_str());
              CameraMap::iterator itr = camera_map_.find(uuid);
              if(itr != camera_map_.end())
                { // retrieved saved camera information: alias
                   node = *itr;
                   QStringList fields = uuid.split("_");
                   node.model_ = fields[1] + " " + fields[2];
                   node.manufacturer_ = fields[0];
                   node.serial_ = fields[3];
                   node.mode_ = itr->mode_;
                   node.f_enable_ = itr->f_enable_;
                  GetSensorProfile(node); // acquire sensor information from xml file: mode, enable, timestamp
                  temp_map[itr->uuid_] = node;
                }
              else{
                  node.uuid_ = uuid;
                        QStringList fields = uuid.split("_");
                        node.model_ = fields[1] + " " + fields[2];
                        node.manufacturer_ = fields[0];
                        node.serial_ = fields[3];
                        node.mode_ = CameraNode::CalibrationMode::EXTRINSICS;
                        node.f_enable_ = false;
                  GetSensorProfile(node); // acquire sensor information from xml file: mode, enable, timestamp
                  temp_map[uuid] = node;
                }
            }
          camera_map_.clear();
          camera_map_ = temp_map;
    }

    SetupSensorTable();

    // select first available sensor
    for(int row = 0; row<ui_setting->tableSensor->rowCount(); row++)
      {
        QTableWidgetItem *w;
        w = ui_setting->tableSensor->item(row,ColumnId::ENABLE);

        if(w->checkState() == Qt::Checked)
          {
            TableCellClicked(row,0);

            break;
          }
      }
}

// return sensor information
// - enable/disable
// - timestamp
// - calibration mode
void CameraTableWidget::GetSensorProfile(CameraNode &node)
{
#ifdef GUI_SIMULATION
  // acquire info using sensor xml
  node.timestamp = QDateTime::currentDateTime();
//  node.mode_ = CameraNode::CalibrationMode::EXTRINSICS;
//  node.f_enable_ = false;
#else
//  if(!camera_map_.size())
//    {
//    // Load test camera
//    camera_map_[QString("12344455")]= camera1;
//    camera_map_[QString("10984455")]= camera2;
//    camera_map_[QString("1234ABC5")]= camera3;
//    camera_map_[QString("1234ABC6")]= camera4;
//    camera_map_[QString("1234ABC7")]= camera5;
//    }
#endif
}
//
// Refresh setting's sensor list
// This function is called when sensors list is received from backend
//
// param camera_list - camera list received from backend
//
void CameraTableWidget::RefreshSensorConfig(QList<SensorInfo>& sensor_list) {
    QList<SensorInfo>::const_iterator sensor_iter;
    CameraMap::iterator iter;

    for (sensor_iter = sensor_list.begin(); sensor_iter != sensor_list.end(); sensor_iter++) {
        // findd camera with uuid
        iter = camera_map_.find((*sensor_iter).uuid_);
        if (iter != camera_map_.end()) {
            // iter->second.mode_ = sensor_iter->mode_; //ToDo: mode need to be translated
            iter.value().model_ = sensor_iter->model_;
            iter.value().f_enable_ = sensor_iter->f_enable_;
        } else {
            CameraNode node;
            node.alias_ = QString("");
            node.model_ = sensor_iter->model_;
            node.mode_ = sensor_iter->mode_;
            node.f_enable_ = true;
            node.f_seedPose_ = true;  // whether position was performed

            camera_map_[sensor_iter->uuid_] = node;
        }
    }
}

void CameraTableWidget::CreateProfileAccepted() {
  // update camera is_positioned field & camera config
  qDebug() << Q_FUNC_INFO;

  QString fileNameAs = QFileDialog::getSaveFileName(this, tr("Save File"),
                             "/home/jana/untitled.png",
                             tr("Images (*.png *.xpm *.jpg)"));

  if(!fileNameAs.isEmpty())
  {
     fileName = fileNameAs;
     ui_setting->lineEdit_fileName->setText(QFileInfo(fileName).fileName());

  // create file


  // parse xml file and display details


  // ready to connect
  ui_setting->pushButton_connect->setEnabled(true);
    ui_setting->pushButton_connect->setFocus();
}

}

void CameraTableWidget::CreateProfileRejected() {
  qDebug() << Q_FUNC_INFO;

  // do nothing yet
}

void CameraTableWidget::OnCalibrateButtonClicked() {
  calibrationInterface->DoCalibrate();
}

void CameraTableWidget::on_pushButton_home_clicked() {
  mainwindow_->SwitchPage("Home");
}

//void CameraTableWidget::on_button_Connect_clicked() {
//  QString filename = QFileDialog::getExistingDirectory(
//        this, tr("Select a package directory"),
//        robot_.path_.isEmpty() ? QDir::currentPath() : robot_.path_,
//        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
//#ifdef BACKEND_CONNECTED
//  robot_config_.ros_package_path = filename.toStdString();
//#endif
//  qDebug() << "selected file path : " << filename.toUtf8();

//  {
//    //      robot_.type_ = ui_setting->comboBox_RobotType->currentText();
//    //      robot_.plate_ = ui_setting->comboBox_Plate->currentText();
//    //      robot_.path_ = ui_setting->lineEdit_PackagePath->text();
//    //      robot_.ip_ = ui_setting->lineEdit_RobotIp->text();

//    //      config_.SaveRobotSettings(robot_);
//  }
//}

void CameraTableWidget::on_lineEdit_fileName_returnPressed()
{
  qDebug() << Q_FUNC_INFO;

  fileName = ui_setting->lineEdit_fileName->text();

  if(!fileName.isEmpty())
    {
      ui_setting->lineEdit_fileName->setText(QFileInfo(fileName).fileName());

      // check if file exists
      QFile file(fileName);
      if(QFileInfo::exists(fileName))
        {
          // parse xml file and display details
          ui_setting->frame_detail->show();


          // ready to connect
          ui_setting->pushButton_connect->setEnabled(true);
          ui_setting->pushButton_connect->setFocus();
        }
      else
        {
          // error message box
          QMessageBox msgBox;
          msgBox.setText(DefineToText(ErrorMessage::FILE_NOT_EXIST));
          msgBox.setIcon(QMessageBox::Warning);
          msgBox.setInformativeText("Failed to find a selected file");
          msgBox.setStandardButtons(QMessageBox::Ok);
          msgBox.exec();

          ui_setting->lineEdit_fileName->setText("");
          fileName.clear();
        }
    }
}

void CameraTableWidget::on_pushButton_fileSelect_clicked()
{
    qDebug() << Q_FUNC_INFO;

  // open file browser
  fileName = QFileDialog::getOpenFileName(this,
      tr("Open Project File"), ".", tr("All (*.*)"));

  // display filename
  if(!fileName.isEmpty())
    {
    ui_setting->lineEdit_fileName->setText(QFileInfo(fileName).fileName());

  // parse xml file and display details


  // ready to connect
  ui_setting->pushButton_connect->setEnabled(true);
  ui_setting->pushButton_connect->setFocus();
  }
}

void CameraTableWidget::on_pushButton_fileNew_clicked()
{
  qDebug() << Q_FUNC_INFO;

  CreateProfileDialog profileDialog(this);

  std::vector<std::string> robots;
  robots = calibrationInterface->GetRobotTypes();
  QList<QString> qrobots;
  for(size_t i=0;i<robots.size();i++)
    qrobots.append(QString(robots[i].c_str()));

  std::vector<std::string> plates;
  QList<QString> qplates;
  plates = calibrationInterface->GetFiducialPlates();
  for(size_t i=0;i<plates.size();i++)
    qplates.append(QString(plates[i].c_str()));


  profileDialog.SetSupportingPlate(qplates);
  profileDialog.SetSupportingRobots(qrobots);

  // update ui

  //    repositionDialog->SetName();
  connect(&profileDialog, SIGNAL(accepted()), this, SLOT(CreateProfileAccepted()));
  connect(&profileDialog, SIGNAL(rejected()), this, SLOT(CreateProfileRejected()));

  profileDialog.setModal(true);
  profileDialog.exec();
}

QString CameraTableWidget::FindCameraNode(int row /*QString &key*/)
{
  QString uuid;
//  QList<QString> uuids =  camera_map_.keys();

//  QList<QString>::iterator itr;
//  for(itr = uuids.begin(); itr != uuids.end(); itr++)
//  {
//      if(itr->contains(key))
//        uuid = camera_map_[*itr].uuid_;
//   }

    QMap<int,QString>::iterator itr;
    itr =  table_node_.find(row);
    if(itr != table_node_.end())
    {
      uuid = table_node_[row];
     }

  return uuid;
}

void CameraTableWidget::SaveSettings()
{
  GuiScreenSizeInfo sizeInfo;

  int columnCount = ui_setting->tableSensor->columnCount();
  sizeInfo.table_columnWidth.resize(columnCount);
  for(int i=0; i<columnCount; i++)
    {
      int width = ui_setting->tableSensor->columnWidth(i);
      sizeInfo.table_columnWidth[i] = width;
    }
  sizeInfo.table_width = ui_setting->tableSensor->width();
  sizeInfo.table_height = ui_setting->tableSensor->height();

  SaveGuiSettings(sizeInfo);
  SaveRobotSettings(robot_);
  SaveCameraSettings(camera_map_);
}

void CameraTableWidget::SaveGuiSettings(GuiScreenSizeInfo& sizeInfo) {

      QSettings settings;

      settings.beginGroup("screen");
      settings.setValue("tableWidth", sizeInfo.table_width);
      settings.setValue("tableHeight", sizeInfo.table_height);

      for(int i=0; i < sizeInfo.table_columnWidth.size(); i++)
        {
          settings.setValue(QString("column") + QString::number(i), sizeInfo.table_columnWidth[i]);
        }
      settings.endGroup();
}

void CameraTableWidget::SetGuiSettings(GuiScreenSizeInfo& sizeInfo) {
guiSizeInfo = sizeInfo;
  // table size
  for(int i=0; i<sizeInfo.table_columnWidth.size();i++ )
    {
      ui_setting->tableSensor->setColumnWidth(i,sizeInfo.table_columnWidth[i]);
  }
}

void CameraTableWidget::SaveRobotSettings(RobotInfo& robot) {
  QVariant var;

  if(!robot.type_.isEmpty())
  {
  var.setValue(robot);

  QSettings settings;
  settings.beginGroup("robot");
  settings.setValue("type", robot.type_);
  settings.setValue("ip", robot.ip_);
  settings.setValue("path", robot.path_);
  settings.setValue("plate", robot.plate_);
  settings.endGroup();
  }
}

void CameraTableWidget::SaveCameraSettings(CameraMap& cameras) {
  QSettings settings;

  if(cameras.size())
    {
  settings.beginGroup("sensor");

  CameraMap::iterator iter;

  for (iter = cameras.begin(); iter != cameras.end(); iter++) {
    QString key = iter.key();
    CameraNode node= iter.value();
    settings.beginGroup(key);
    if(node.uuid_.isEmpty())
      node.uuid_ = key;
    settings.setValue("uuid", node.uuid_);
    settings.setValue("alias", node.alias_);
    settings.setValue("model", node.model_);
    settings.setValue("mode", static_cast<int>(node.mode_));
    settings.setValue("enable", node.f_enable_);
    settings.setValue("positioned", node.f_seedPose_);
    settings.endGroup();
  }
  settings.endGroup();
  }
}

bool CameraTableWidget::LoadRobotSettings() {
  QSettings settings;

//  if (!settings.contains("robot")) return false;

  settings.beginGroup("robot");
  robot_.type_ = settings.value("type").toString();
  robot_.ip_ = settings.value("ip").toString();
  robot_.path_ = settings.value("path").toString();
  robot_.plate_ = settings.value("plate").toString();
  settings.endGroup();

  return true;
}

bool CameraTableWidget::LoadSensorSettings() {
  QVariant var;
  int mode_type;

  QSettings settings;

//  if (!settings.contains("sensor")) return false;

  settings.beginGroup("sensor");
  QStringList groups = settings.childGroups();

  QString key;
  foreach (key, groups) {
    CameraNode node;
    settings.beginGroup(key);
    node.uuid_ = settings.value("uuid").toString();
    node.alias_ = settings.value("alias").toString();
    node.model_ = settings.value("model").toString();
    //  node.mode_
    mode_type = settings.value("mode").toInt();
    node.mode_ = static_cast<CameraNode::CalibrationMode>(mode_type);
    node.f_enable_ = settings.value("enable").toBool();
    node.f_seedPose_ = settings.value("positioned").toBool();
    settings.endGroup();

    camera_map_[key] = node;
  }
  settings.endGroup();

  return true;
}

void CameraTableWidget::receiveFrame(QPixmap pm) {
  if (!pm.isNull()) {
      ui_setting->cameraView->setPixmap(pm);
    }
}

// temporary function for connecting robot
void CameraTableWidget::SetUpRobots()
{
  std::vector<std::string> robots;
  robots = calibrationInterface->GetRobotTypes();
  QList<QString> qrobots;
  for(size_t i=0; i<robots.size(); i++)
    qrobots.append(QString(robots[i].c_str()));

    ui_setting->comboBox_RobotType->clear();

   for(unsigned int i=0;i<robots.size();i++)
      ui_setting->comboBox_RobotType->insertItem(static_cast<int>(i), qrobots[i]);

std::vector<std::string> plates;
QList<QString> qplates;
plates = calibrationInterface->GetFiducialPlates();
for(size_t i=0;i<plates.size();i++)
  qplates.append(QString(plates[i].c_str()));

ui_setting->comboBox_Plate->clear();

for(unsigned int i=0;i<plates.size();i++)
  ui_setting->comboBox_Plate->insertItem(static_cast<int>(i), qplates[i]);
}

QWidget *CameraTableWidget::CreateSensorProfileWidget(CameraNode &node) const
{
  QWidget *formLayoutWidget;
  QVBoxLayout *formLayout;
  QFont font;;
  QLabel *label_model, *label_serial, *label_manufacturer;

  font.setPointSize(9);

formLayoutWidget = new QWidget();
formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
formLayout = new QVBoxLayout(formLayoutWidget);
formLayout->setSpacing(6);
formLayout->setObjectName(QStringLiteral("formLayout"));
//formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
//formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
//formLayout->setHorizontalSpacing(2);
//formLayout->setVerticalSpacing(1);
formLayout->setContentsMargins(5, 5, 5, 5);
formLayout->setSpacing(1);

label_manufacturer = new QLabel(formLayoutWidget);
label_manufacturer->setObjectName(QStringLiteral("label_projection"));
label_manufacturer->setFont(font);
label_manufacturer->setText(node.manufacturer_);
//formLayout->setWidget(0, QFormLayout::FieldRole, label_manufacturer);
formLayout->addWidget(label_manufacturer);
label_model = new QLabel(formLayoutWidget);
label_model->setObjectName(QStringLiteral("label_accuracy"));
label_model->setFont(font);
label_model->setText(node.model_);
//formLayout->setWidget(1, QFormLayout::FieldRole, label_model);
formLayout->addWidget(label_model);
label_serial = new QLabel(formLayoutWidget);
label_serial->setObjectName(QStringLiteral("label_resolution"));
label_serial->setFont(font);
label_serial->setText(node.serial_);
//formLayout->setWidget(2, QFormLayout::FieldRole, label_serial);
formLayout->addWidget(label_serial);
label_model->setText(node.model_);
label_serial->setText(node.serial_);
label_manufacturer->setText(node.manufacturer_);

return formLayoutWidget;
}

void CameraTableWidget::retranslateUi()
{

} // retranslateUi
