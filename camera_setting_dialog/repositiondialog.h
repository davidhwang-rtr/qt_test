#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "ui_repositiondialog.h"

namespace Ui {
  class Dialog_Reposition;
}

class RepositionDialog : public QDialog
{
  Q_OBJECT

public:
  explicit RepositionDialog(QWidget *parent = nullptr);
  ~RepositionDialog();
  void SetCameraName(QString &);


private:
  Ui::Dialog_Reposition *ui;
};

#endif // DIALOG_H
