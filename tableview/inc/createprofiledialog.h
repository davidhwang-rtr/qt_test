#ifndef CREATEPROFILEDIALOG_H
#define CREATEPROFILEDIALOG_H

#include <QDialog>

namespace Ui {
class CreateProfileDialog;
}

class CreateProfileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateProfileDialog(QWidget *parent = nullptr);
    ~CreateProfileDialog();
    void on_comboBox_Plate_currentIndexChanged(const QString& );
    void SetSupportingPlate(QList<QString> &plates);
    void SetSupportingRobots(QList<QString> &robots);

private slots:

  void on_toolButton_packagePath_clicked();
  void on_toolButton_sceneUrdfFile_clicked();
  void on_toolButton_robotUrdfFile_clicked();
  void on_pushButton_cancel_clicked();
  void on_pushButton_save_clicked();
  void on_comboBox_RobotType_currentIndexChanged(const QString& arg1);

private:
    Ui::CreateProfileDialog *ui;
};

#endif // CREATEPROFILEDIALOG_H
