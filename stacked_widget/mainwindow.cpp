#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>
#include <QDebug>
#include "buttonlabel.h"
#include <QFrame>
#include <QString>
#include <QList>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

#define MAINWINDOW_WIDTH 1024
#define MAINWINDOW_HEIGHT 768
#define NAVIBAR_WIDTH MAINWINDOW_WIDTH
#define NAVIBAR_HEIGHT 60
#define TITLE_HEIGHT  50

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{

  QCoreApplication::setOrganizationName("Realtime Robotics");
  QCoreApplication::setOrganizationDomain("rtr.ai");
  QCoreApplication::setApplicationName("Camera Calibration");

  qRegisterMetaType<ConfigSettings>("ConfigSettings");
  qRegisterMetaTypeStreamOperators<ConfigSettings>("ConfigSettings");

  ui->setupUi(this);

//  config_.LoadSettings();

  resize(MAINWINDOW_WIDTH, MAINWINDOW_HEIGHT);

  //
  // add pages in stacked widget
  //

  ui->stackedWidget->setGeometry(QRect(0, TITLE_HEIGHT, width(), height()- NAVIBAR_HEIGHT - TITLE_HEIGHT));

  QWidget *page;
  QWidget *widget;
  QLabel *label;

  std::list<QString> page_names = {"Home", "Setting", "Calibration", "Report", "Exit"} ;

  std::list<QString>::iterator citr;

  for(citr = page_names.begin(); citr != page_names.end(); citr++)
    {
      page = new QWidget();
      page->setObjectName(*citr);
      page_map_[page->objectName()] = page;
      ui->stackedWidget->addWidget(page);
    }

  // create navigation bar
  //

  CreateNaviButton();

  // construct layout in homepage
  //  widget = new QWidget(page);
  //  widget->setObjectName(QStringLiteral("widget"));
  //  widget->setGeometry(QRect(190, 80, 120, 80));
  //  label = new QLabel(widget);
  //  label->setObjectName(QStringLiteral("label"));
  //  label->setGeometry(QRect(30, 20, 91, 17));

  SetupCameraUi(page_map_["Setting"]);
//  SetupRobotUi(page_map_["Robot"]);


  //  connect(ui->pushButton_next,SIGNAL(clicked()), this,SLOT(naviButtonClicked()));
  //  connect(ui->pushButton_previous,SIGNAL(clicked()), this,SLOT(naviButtonClicked()));

}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::SetupCameraUi(QWidget *widget)
{
    cameraTableWidget_ = new CameraTableWidget(widget);

}

void MainWindow::closeEvent(QCloseEvent *event)
{
  config_.SaveSettings();
  event->accept();
}


void MainWindow::CreateNaviButton()
{
  // get list of button list
  frame = new QFrame(ui->centralWidget);
  frame->setObjectName(QStringLiteral("frame"));
  QSize w_size = ui->centralWidget->size();
  qDebug() << "frame size: " << w_size.width() << "  " << w_size.height();

  frame->setGeometry(QRect(0, MAINWINDOW_HEIGHT - NAVIBAR_HEIGHT, NAVIBAR_WIDTH, NAVIBAR_HEIGHT)); //ToDo - flexible
//  frame->setFrameShape(QFrame::StyledPanel);
//  frame->setFrameShadow(QFrame::Raised);
  QHBoxLayout *horizontalLayout = new QHBoxLayout(frame);
  horizontalLayout->setSpacing(10);
//  horizontalLayout->setContentsMargins(11, 11, 11, 11);
  horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
  horizontalLayout->setContentsMargins(5, 5, 5, 5);

  QLabel *label_4 = new ButtonLabel(frame);
  label_4->setObjectName(QStringLiteral("label_4"));
  label_4->setText(page_map_["Home"]->objectName());
  horizontalLayout->addWidget(label_4);
  connect(label_4,SIGNAL(clicked(QString)), this,SLOT(naviButtonClicked(QString)));

  QLabel *label_5 = new ButtonLabel(frame);
  label_5->setObjectName(QStringLiteral("label_5"));
  label_5->setText(page_map_["Setting"]->objectName());
  horizontalLayout->addWidget(label_5);
  connect(label_5,SIGNAL(clicked(QString)), this,SLOT(naviButtonClicked(QString)));

  QSpacerItem *horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  horizontalLayout->addItem(horizontalSpacer);

  QLabel*label_3 = new ButtonLabel(frame);
  label_3->setObjectName(QStringLiteral("label_3"));
  label_3->setText(page_map_["Exit"]->objectName());
  horizontalLayout->addWidget(label_3);
  connect(label_3,SIGNAL(clicked(QString)), this,SLOT(naviButtonClicked(QString)));

}

void MainWindow::naviButtonClicked(QString buttonName)
{
  qDebug() << "Navibutton Clicked" << buttonName;

  QWidget *widget = page_map_[buttonName];
  ui->stackedWidget->setCurrentWidget(widget);


//  int index = ui->stackedWidget->currentIndex();
//  (index == 0) ? (++index) : index=0;

//  ui->stackedWidget->setCurrentIndex(index);

    int index = ui->stackedWidget->currentIndex();

//  page_ = index;
  config_.SaveSettings(); // ToDo: signal slot of saving configurations
}




