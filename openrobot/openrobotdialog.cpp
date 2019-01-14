#include "openrobotdialog.h"
#include "ui_openrobotdialog.h"

OpenRobotDialog::OpenRobotDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenRobotDialog)
{
    ui->setupUi(this);
}

OpenRobotDialog::~OpenRobotDialog()
{
    delete ui;
}
