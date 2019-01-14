#ifndef OPENROBOTDIALOG_H
#define OPENROBOTDIALOG_H

#include <QDialog>

namespace Ui {
class OpenRobotDialog;
}

class OpenRobotDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OpenRobotDialog(QWidget *parent = 0);
    ~OpenRobotDialog();

private:
    Ui::OpenRobotDialog *ui;
};

#endif // OPENROBOTDIALOG_H
