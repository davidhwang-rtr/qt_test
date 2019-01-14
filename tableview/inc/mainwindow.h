#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QCloseEvent>
#include <QFrame>
#include <QLayout>
#include "cameratablewidget.h"
#include "configrobotsensor.h"
//#include "calibrationwidget.h"
#include "homewidget.h"
#include "buttonlabel.h"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  void CreateNaviButton();
  void updateNaviButton(QString buttonName);

//  GuiScreenSizeInfo gui_config_;

protected:
  void closeEvent(QCloseEvent *event);
public slots:
  void naviButtonClicked(QString);
  bool GetCameraMap(CameraMap&);
  void SwitchPage(QString);

private:

  void LoadSetting();
  void SaveGuiSettings();
  bool LoadGuiSettings(GuiScreenSizeInfo &sizeInfo);

  Ui::MainWindow *ui;
//  ConfigSettings config_;
  QMap<QString, QWidget *> page_map_; // object name - widget point
  QHBoxLayout *horizontalLayout;

  // navigation bar
  QFrame *frame;

  CameraTableWidget *cameraTableWidget_;
//  CalibrationWidget *calibrationWidget_;

  HomeWidget *homeWidget_;

  ButtonLabel* button_home;
  ButtonLabel* button_setting;
  ButtonLabel* button_calibration;
  ButtonLabel* button_exit;
  ButtonLabel* button_help;
};

#endif // MAINWINDOW_H
