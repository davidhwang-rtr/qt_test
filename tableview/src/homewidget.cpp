#include "homewidget.h"
#include "ui_homepage.h"
#include "mainwindow.h"

HomeWidget::HomeWidget(QWidget *parent) : QWidget(parent)
  , ui(new Ui::HomepageWidget){
    mainwindow_ = dynamic_cast<MainWindow *>(parent);
    ui->setupUi(this);
}

void HomeWidget::on_pushButton_calibration_clicked()
{
    mainwindow_->SwitchPage("Setting");
}
