#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

//  widget = new QWidget(page);
//  widget->setObjectName(QStringLiteral("widget"));
//  widget->setGeometry(QRect(90, 110, 120, 80));
  connect(ui->pushButton_next,SIGNAL(clicked()), this,SLOT(naviButtonClicked()));
  connect(ui->pushButton_previous,SIGNAL(clicked()), this,SLOT(naviButtonClicked()));
}

void MainWindow::naviButtonClicked()
{
  qDebug() << "Navibutton Clicked" ;
  int index = ui->stackedWidget->currentIndex();
  // get object name
  if(index == 0)
    ui->stackedWidget->setCurrentIndex(index++);
  else
    ui->stackedWidget->setCurrentIndex(index--);

  // qsettings saving current page in QVariant
  config_.savePage(index);
  SaveSettings(); // ToDo: signal slot of saving configurations
}

void MainWindow::SaveSettings()
{
  QSettings settings;
  settings.beginGroup("navigation");
  // convert config_ to QVariant var
  QVariant var;
  var.setValue(config_);
  settings.setValue("page",var);
  settings.endGroup();
}
void MainWindow::LoadSettings()
{
  QVariant var;
  Config conf;

  QSettings settings;
  settings.beginGroup("navigation");
  var = settings.value("page");
  settings.endGroup();
  conf = var.value<Config>();
  config_ = conf;

  ui->stackedWidget->setCurrentIndex(config_.getPage());
}

MainWindow::~MainWindow()
{
  delete ui;
}
