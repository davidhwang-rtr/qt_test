#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>
#include <QDebug>
#include "buttonlabel.h"
#include <QFrame>


Q_DECLARE_METATYPE(ConfigSettings)

QDataStream& operator<<(QDataStream& out, const ConfigSettings& v) {
    out << v.page ;
    return out;
}

QDataStream& operator>>(QDataStream& in, ConfigSettings& v) {
    in >> v.page;
    return in;
}

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

//  widget = new QWidget(page);
//  widget->setObjectName(QStringLiteral("widget"));
//  widget->setGeometry(QRect(90, 110, 120, 80));
  connect(ui->pushButton_next,SIGNAL(clicked()), this,SLOT(naviButtonClicked()));
  connect(ui->pushButton_previous,SIGNAL(clicked()), this,SLOT(naviButtonClicked()));

  LoadSettings();

  ui->stackedWidget->setCurrentIndex(config_.getPage());

//  //  button.
  ButtonLabel *button_label = new ButtonLabel(ui->centralWidget);
//  button_label->setObjectName(QStringLiteral("home"));
//  button_label->setSizePolicy(QSizePolicy::Fixed, button_label->sizePolicy().verticalPolicy());

//  button_label->setGeometry(QRect(160, 120, 131, 17));

  CreateNaviButton();


}

void MainWindow::closeEvent(QCloseEvent *event)
{
  SaveSettings();
  event->accept();
}

void MainWindow::naviButtonClicked()
{
  qDebug() << "Navibutton Clicked" ;
  int index = ui->stackedWidget->currentIndex();
  // get object name
  (index == 0) ? (++index) : index=0;

  ui->stackedWidget->setCurrentIndex(index);

  // qsettings saving current page in QVariant
  config_.savePage(index);
//  page_ = index;
  SaveSettings(); // ToDo: signal slot of saving configurations
}

void MainWindow::SaveSettings()
{

  QVariant var;

  ConfigSettings   conf(config_);
  var.setValue(conf);

  QSettings settings("Realtime Robotics","Camera Calibration");
  settings.beginGroup("navigation");
  settings.setValue("page",var); //QVariant::fromValue<ConfigSettings>(conf));
  settings.endGroup();
}

void MainWindow::LoadSettings()
{
  QVariant var;
  ConfigSettings conf;

  QSettings settings("Realtime Robotics","Camera Calibration");
  settings.beginGroup("navigation");
  var = settings.value("page");
  settings.endGroup();
  conf = var.value<ConfigSettings>();
  config_ = conf;
//  page_ = var.value<int>();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::CreateNaviButton()
{
 QFrame *frame = new QFrame(ui->centralWidget);
frame->setObjectName(QStringLiteral("frame"));
frame->setGeometry(QRect(0, 250, 441, 45));
frame->setFrameShape(QFrame::StyledPanel);
frame->setFrameShadow(QFrame::Raised);
QHBoxLayout *horizontalLayout = new QHBoxLayout(frame);
horizontalLayout->setSpacing(10);
horizontalLayout->setContentsMargins(11, 11, 11, 11);
horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
horizontalLayout->setContentsMargins(5, 5, 5, 1);

QLabel *label_4 = new QLabel(frame);
label_4->setObjectName(QStringLiteral("label_4"));
label_4->setText("b1");
horizontalLayout->addWidget(label_4);

QLabel *label_5 = new QLabel(frame);
label_5->setObjectName(QStringLiteral("label_5"));
horizontalLayout->addWidget(label_5);

QSpacerItem *horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
horizontalLayout->addItem(horizontalSpacer);

QLabel*label_3 = new QLabel(frame);
label_3->setObjectName(QStringLiteral("label_3"));
horizontalLayout->addWidget(label_3);

}
