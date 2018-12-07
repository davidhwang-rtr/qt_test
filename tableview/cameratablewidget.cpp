#include "cameratablewidget.h"
#include "ui_widget.h"
#include "QPushButton"
#include "QHBoxLayout"
#include "QLabel"
#include <QDebug>
#include <QRadioButton>
#include <QFileDialog>

CameraTableWidget::CameraTableWidget(QWidget *parent) :
  QWidget(parent),
  ui_config(new Ui::ConfigWidget)
{
  ui_config->setupUi(this);

  //
  // fake camera list
  //
  CameraNode camera1(QString("X Axis"), QString("Realsense D435"), CalbirationMode::ALL, true, false);
  CameraNode camera2(QString("Y Axis"), QString("Realsense D435"), CalbirationMode::STREREO, true, false);
  CameraNode camera3(QString("Z Axis"), QString("Realsense D415"), CalbirationMode::EXTRINSIC, false, true);
  CameraNode camera4(QString("Z Axis"), QString("Realsense D415"), CalbirationMode::EXTRINSIC, false, true);
  CameraNode camera5(QString("Z Axis"), QString("Realsense D415"), CalbirationMode::EXTRINSIC, false, true);



  // ----------------

  // set up table

  ui_config->tableWidget_Sensor->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
  ui_config->tableWidget_Sensor->horizontalHeader()->setStretchLastSection(true);
  ui_config->tableWidget_Sensor->resizeRowsToContents();
  ui_config->tableWidget_Sensor->horizontalHeader()->setVisible(true);
  ui_config->tableWidget_Sensor->verticalHeader()->setVisible(true);

  connect(ui_config->tableWidget_Sensor, SIGNAL(itemClicked(QTableWidgetItem *)), this, SLOT(TableItemClicked(QTableWidgetItem *)));
  connect(ui_config->tableWidget_Sensor, SIGNAL(cellClicked(int,int)), this, SLOT(TableCellClicked(int,int)));
  connect(ui_config->tableWidget_Sensor, SIGNAL(cellPressed(int,int)), this, SLOT(TableCellPressed(int,int)));
  connect(ui_config->tableWidget_Sensor, SIGNAL(cellChanged(int,int)), this, SLOT(TableCellChanged(int,int)));

  connect(ui_config->button_PacakgePath, SIGNAL(clicked()), this, SLOT(OnPackagePathClicked()));

  connect(ui_config->button_Connect,SIGNAL(clicked()),this, SLOT(OnConnectClicked()));

  config_.LoadRobotSettings(robot_);
  if(!config_.LoadSensorSettings(camera_map_))
    {
      camera_map_[QString("12344455")]= camera1;
      camera_map_[QString("10984455")]= camera2;
      camera_map_[QString("1234ABC5")]= camera3;
      camera_map_[QString("1234ABC6")]= camera4;
      camera_map_[QString("1234ABC7")]= camera5;
    }

  int idx = ui_config->comboBox_RobotType->findText(robot_.type_);
  if(idx != -1)
    {      ui_config->comboBox_RobotType->setCurrentIndex(idx);
      ui_config->lineEdit_RobotIp->setText(robot_.ip_);
      ui_config->lineEdit_PackagePath->setText(robot_.path_);
    }
  else
    {
      ui_config->comboBox_RobotType->setCurrentIndex(0);
      ui_config->lineEdit_RobotIp->setText("");
      ui_config->lineEdit_PackagePath->setText("");
    }
  idx = ui_config->comboBox_Plate->findText(robot_.plate_);
  if(idx != -1)
    ui_config->comboBox_Plate->setCurrentIndex(idx);
  else
    ui_config->comboBox_Plate->setCurrentIndex(0);

  // table header
  QStringList headerList;
  headerList << "Name" << "Serial Number" << "Model" << "Calibration Mode" << "Enable" << "Positioned" << "";
  ui_config->tableWidget_Sensor->setColumnCount(headerList.size());
  ui_config->tableWidget_Sensor->setHorizontalHeaderLabels(headerList);

  // populate table
  PopulateTable(camera_map_);

  // resize table
  // - max height - contain three cameras, min - # of cameras up to 3

  int tableHeight;
  int horizontalHeaderHeight=ui_config->tableWidget_Sensor->horizontalHeader()->height();
  int rowSectionHeight = 0;

  if(camera_map_.size())
  {
      rowSectionHeight=ui_config->tableWidget_Sensor->verticalHeader()->sectionSize(0);
  }

  if(camera_map_.size() >= 3)
  {
      tableHeight = horizontalHeaderHeight + rowSectionHeight*3;
  }
  else
  {
      tableHeight = horizontalHeaderHeight + rowSectionHeight*2;
  }

  QRect rect = ui_config->tableWidget_Sensor->geometry();

  ui_config->tableWidget_Sensor->setGeometry(rect.x(), rect.y(), rect.width(), tableHeight);

  // resize splitter - below table
  QList<int> sz = ui_config->splitter->sizes();
  int height = (rect.y()+tableHeight + 30);
  sz[0] = height;
  sz[1] = 768 -height;
  ui_config->splitter->setSizes(sz);
}

int CameraTableWidget::GetSizeOfViewToContents()
{
  int count=ui_config->tableWidget_Sensor->verticalHeader()->count();
  //    int scrollBarHeight=ui->tableWidget_Robot->horizontalScrollBar()->height();
  int horizontalHeaderHeight=ui_config->tableWidget_Sensor->horizontalHeader()->height();
  int rowTotalHeight=0;
  for (int i = 0; i < count; ++i) {
      // 2018-03 edit: only account for row if it is visible
      if (!ui_config->tableWidget_Sensor->verticalHeader()->isSectionHidden(i)) {
          rowTotalHeight+=ui_config->tableWidget_Sensor->verticalHeader()->sectionSize(i);
        }
    }

  return rowTotalHeight+horizontalHeaderHeight;
}

CameraTableWidget::~CameraTableWidget()
{
  delete ui_config;
}

//void CameraTableWidget::GetCameraInfo()
//{}

void CameraTableWidget::PopulateTable(const std::map<QString, CameraNode> & camera_list)
{
  ui_config->tableWidget_Sensor->setRowCount(static_cast<int>(camera_list.size()));

  std::map<QString, CameraNode>::const_iterator iter;
  int row;

  for(iter = camera_list.begin(), row=0; iter != camera_list.end(); iter++, row++)
    {
      CameraNode node = iter->second;

      for(int col=0 ; col< ui_config->tableWidget_Sensor->columnCount(); col++)
        {
          if(col==0) // qlineedit
            {
              QWidget* pWidget = new QWidget();
              QLineEdit *lineEdit_3 = new QLineEdit(ui_config->tableWidget_Sensor);
              lineEdit_3->setObjectName(QString("name_%1").arg(row));
              lineEdit_3->setText(node.alias_);
              connect(lineEdit_3,SIGNAL(editingFinished()),this, SLOT(OnTableContentChanged()));
              QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
              pLayout->addWidget(lineEdit_3);
              pLayout->setAlignment(Qt::AlignCenter);
              //              pLayout->setContentsMargins(0, 0, 0, 0);
              pWidget->setLayout(pLayout);
              ui_config->tableWidget_Sensor->setCellWidget(row, col, pWidget);
            }
          else if(col==1) // qstring
            {
              QTableWidgetItem *newItem = new QTableWidgetItem(iter->first);
              newItem->setFlags(newItem->flags()^ Qt::ItemIsEditable);
              ui_config->tableWidget_Sensor->setItem(row, col, newItem);
            }
          else if(col==2) // qstring
            {
              QTableWidgetItem *newItem = new QTableWidgetItem(node.model_);
              newItem->setFlags(newItem->flags()^ Qt::ItemIsEditable);
              ui_config->tableWidget_Sensor->setItem(row, col, newItem);
            }
          else if(col==3) // checkboxes
            {
              QWidget* pWidget = new QWidget();
              //                            QHBoxLayout *horizontalLayout;
              //              QRadioButton *radioButton;
              //              QRadioButton *radioButton_2;
              //              QRadioButton *radioButton_3;

              //              horizontalLayout = new QHBoxLayout(pWidget);
              //              horizontalLayout->setSpacing(3);
              //              horizontalLayout->setContentsMargins(3, 3,3,3); //,11,11,11);
              //              horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
              //              horizontalLayout->setContentsMargins(0, 0, 0, 0);


              //              radioButton = new QRadioButton();
              //              radioButton->setObjectName(QStringLiteral("radioButton"));
              //              horizontalLayout->addWidget(radioButton);
              //              radioButton->setText(QApplication::translate("Widget", "All", nullptr));

              //              radioButton_2 = new QRadioButton();
              //              radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
              //              horizontalLayout->addWidget(radioButton_2);
              //              radioButton_2->setText(QApplication::translate("Widget", "RGB", nullptr));

              //              radioButton_3 = new QRadioButton();
              //              radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
              //              horizontalLayout->addWidget(radioButton_3);
              //              radioButton_3->setText(QApplication::translate("Widget", "Stereo", nullptr));

              //              switch((*iter).mode_)
              //                {
              //                case CalbirationMode::ALL:
              //                  radioButton->setChecked(true);
              //                  break;
              //                case CalbirationMode::EXTRINSIC:
              //                  radioButton_2->setChecked(true);
              //                  break;
              //                case CalbirationMode::STREREO:
              //                  radioButton_3->setChecked(true);
              //                  break;
              //                }

              QComboBox *comboBox = new QComboBox(ui_config->tableWidget_Sensor);
              comboBox->addItem(QString("Stereo"));
              comboBox->addItem(QString("IR"));
              comboBox->addItem(QString("All"));
              comboBox->setObjectName(QStringLiteral("comboBox"));
              comboBox->setCurrentIndex(node.mode_);
              QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
              pLayout->addWidget(comboBox);
              pLayout->setAlignment(Qt::AlignCenter);
              pLayout->setContentsMargins(0, 0, 0, 0);
              pWidget->setLayout(pLayout);
              ui_config->tableWidget_Sensor->setCellWidget(row, col, pWidget); //groupBox);

            }
          else if(col==4) // qstring
            {
              QTableWidgetItem *newItem = new QTableWidgetItem("Enable");
              Qt::CheckState state = node.f_enable_ ? Qt::Checked : Qt::Unchecked;
              newItem->setCheckState(state);
              ui_config->tableWidget_Sensor->setItem(row, col, newItem);
            }
          else if(col==5) // qstring
            {
              QLabel *lbl_item = new QLabel(ui_config->tableWidget_Sensor);
              QIcon icon;
              if (node.f_isPositioned)
                icon.addFile(":/images/checkmark-2.png");
              else
                icon.addFile(":/images/cancel.png");

              lbl_item ->setPixmap(icon.pixmap(QSize(24,24)));
              lbl_item ->setAlignment(Qt::AlignHCenter);

              QWidget* pWidget = new QWidget();
              QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
              pLayout->addWidget(lbl_item);
              pLayout->setAlignment(Qt::AlignCenter);
              pLayout->setContentsMargins(0, 0, 0, 0);
              pWidget->setLayout(pLayout);

              ui_config->tableWidget_Sensor->setCellWidget(row, col, pWidget);
            }
          else if(col==6)
            {
              QWidget* pWidget = new QWidget();
              QPushButton* btn_edit = new QPushButton(ui_config->tableWidget_Sensor);
              btn_edit->setObjectName(QString("reposition_%1").arg(row));
              connect(btn_edit, SIGNAL(clicked()), this,    SLOT(OnRepositionButtonClicked()));
              btn_edit->setText("Re-Position");
              QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
              pLayout->addWidget(btn_edit);
              pLayout->setAlignment(Qt::AlignCenter);
              pLayout->setContentsMargins(0, 0, 0, 0);
              pWidget->setLayout(pLayout);
              ui_config->tableWidget_Sensor->setCellWidget(row, col, pWidget);
            }
        }
    }
}

// cell clicked

void CameraTableWidget::TableCellClicked(int row, int col)
{
  qDebug() << "Cell Clicked: Column:" << col << " Row:" << row;
}
//

void CameraTableWidget::TableItemClicked(QTableWidgetItem *item)
{
  int col = ui_config->tableWidget_Sensor->currentColumn();
  qDebug() << "Current Column" << col;
}
// row cl

void CameraTableWidget::TableCellPressed(int row, int col)
{
  qDebug() << "Cell Activated: Column:" << col << " Row:" << row;
}

void CameraTableWidget::TableCellChanged(int row, int col)
{
  qDebug() << "Cell Changed: Column:" << col << " Row:" << row;
}

void CameraTableWidget::OnRepositionButtonClicked()
{
  QPushButton *pb = qobject_cast<QPushButton *>(QObject::sender());

  QStringList parts = pb->objectName().split("_");
  int row = parts[1].toInt();
  qDebug() << "Button clicked: row:" << row;
}


void CameraTableWidget::OnTableContentChanged()
{
  qDebug() << "Alias changed" ;

  QLineEdit *pb = qobject_cast<QLineEdit *>(QObject::sender());

  QString text = pb->text();
  qDebug() << "Alias changed to" << text ;


  // change config info
  QStringList parts = pb->objectName().split("_");
  int row = parts[1].toInt();

  QString uuid = ui_config->tableWidget_Sensor->item(row,1)->text();
  camera_map_[uuid].alias_ = text;;

}

void CameraTableWidget::OnPackagePathClicked()
{
  QString filename =  QFileDialog::getExistingDirectory(
        this,
        tr("Select a package directory"),
        robot_.path_.isEmpty() ? QDir::currentPath() : robot_.path_,
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

  if( !filename.isNull() )
    {
      ui_config->lineEdit_PackagePath->setText(filename);
      qDebug() << "selected file path : " << filename.toUtf8();
    }
}

void CameraTableWidget::OnConnectClicked()
{
  // connect robot


  // save in setting
  //  if (connection was successful)
  {
    robot_.type_ = ui_config->comboBox_RobotType->currentText();
    robot_.plate_ = ui_config->comboBox_Plate->currentText();
    robot_.path_ = ui_config->lineEdit_PackagePath->text();
    robot_.ip_ = ui_config->lineEdit_RobotIp->text();

    config_.SaveRobotSettings(robot_);
  }
}


//
// Refresh setting's sensor list
// This function is called when sensors list is received from backend
//
// param camera_list - camera list received from backend
//
void CameraTableWidget::RefreshSensorConfig(QList<SensorInfo> &sensor_list)
{
   QList<SensorInfo>::const_iterator sensor_iter;
   std::map<QString, CameraNode>::iterator iter;

  for(sensor_iter = sensor_list.begin(); sensor_iter != sensor_list.end(); sensor_iter++)
    {
      // findd camera with uuid
      iter = camera_map_.find((*sensor_iter).uuid_);
      if(iter != camera_map_.end())
      {
          //iter->second.mode_ = sensor_iter->mode_; //ToDo: mode need to be translated
          iter->second.model_ = sensor_iter->model_;
          iter->second.f_enable_ = sensor_iter->f_enable_;
        }
      else
      {
          CameraNode node;
          node.alias_ = QString("");
          node.model_ = sensor_iter->model_;
          node.mode_ = sensor_iter->mode_;
          node.f_enable_ = true;
          node.f_isPositioned = true;  // whether position was performed

          camera_map_[sensor_iter->uuid_] = node;
      }
      config_.SaveCameraSettings(camera_map_);
    }
}

