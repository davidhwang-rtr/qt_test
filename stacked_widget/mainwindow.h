#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QCloseEvent>
#include <QDataStream>

namespace Ui {
  class MainWindow;
}


class ConfigSettings
{
public:
  ConfigSettings(){}
  ~ConfigSettings(){}
  ConfigSettings(const ConfigSettings &org){
    page = org.page;
  }
  int getPage() const { return page;}
  void savePage(int value) {page = value;}

  friend QDataStream& operator<<(QDataStream& out, const ConfigSettings& v);
  friend QDataStream& operator>>(QDataStream& in, ConfigSettings& v);

private:
  int page;
};



class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void SaveSettings();
  void LoadSettings();
  void CreateNaviButton();
protected:
  void closeEvent(QCloseEvent *event);
public slots:
  void naviButtonClicked();

private:
  Ui::MainWindow *ui;
  ConfigSettings config_;
    int page_;
};

#endif // MAINWINDOW_H
