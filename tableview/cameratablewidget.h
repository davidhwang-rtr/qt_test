#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QList>
#include <QGroupBox>
#include <QFileDialog>
#include "configrobotsensor.h"

namespace Ui {
  class ConfigWidget;
}

class CameraTableWidget : public QWidget
{
  Q_OBJECT

public:
  explicit CameraTableWidget(QWidget *parent = nullptr);
  ~CameraTableWidget();
  ConfigSettings config_;

public slots:
  void TableItemClicked(QTableWidgetItem *);
  void TableCellClicked(int row, int col);
  void TableCellPressed(int row, int col);
  void TableCellChanged(int row, int col);
  void OnRepositionButtonClicked();
  void RefreshSensorConfig(QList<SensorInfo> &sensor_list);

private:
  Ui::ConfigWidget *ui_config;
  std::map<QString, CameraNode> camera_map_;
  RobotInfo robot_;

  void PopulateTable(const std::map<QString, CameraNode> &);
  int  GetSizeOfViewToContents();

public slots:
  void OnPackagePathClicked();
  void OnConnectClicked();
    void OnTableContentChanged();
};

#endif // WIDGET_H
