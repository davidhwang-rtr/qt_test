#include "repositiondialog.h"


RepositionDialog::RepositionDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Dialog_Reposition)
{
  ui->setupUi(this);
}

RepositionDialog::~RepositionDialog()
{
  delete ui;
}

void RepositionDialog::SetCameraName(QString &name)
{
  ui->label_name->setText(name);
}
