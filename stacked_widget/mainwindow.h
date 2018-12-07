#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QCloseEvent>
#include <QFrame>
#include "cameratablewidget.h"
#include "configrobotsensor.h"

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
  void SetupCameraUi(QWidget *);
protected:
  void closeEvent(QCloseEvent *event);
public slots:
  void naviButtonClicked(QString);

private:
  Ui::MainWindow *ui;
  ConfigSettings config_;
  QMap<QString, QWidget *> page_map_; // object name - widget point

  // navigation bar
  QFrame *frame;

  CameraTableWidget *cameraTableWidget_;

};

#endif // MAINWINDOW_H
