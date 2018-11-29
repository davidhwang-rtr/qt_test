#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

namespace Ui {
  class MainWindow;
}


class Config
{
public:
  int getPage() const { return page;}
  void savePage(int value) {page = value;}

private:
  int page;
};

Q_DECLARE_METATYPE(Config)

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void SaveSettings();
  void LoadSettings();

public slots:
  void naviButtonClicked();

private:
  Ui::MainWindow *ui;
  Config config_;
};

#endif // MAINWINDOW_H
