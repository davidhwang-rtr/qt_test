#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidgetItem>

namespace Ui {
  class Widget;
}

class CameraTableWidget : public QWidget
{
  Q_OBJECT

public:
  explicit CameraTableWidget(QWidget *parent = nullptr);
  ~CameraTableWidget();

public slots:
  void tableItemClicked(QTableWidgetItem *);
  void tableCellClicked(int row, int col);
  void tableCellPressed(int row, int col);
  void CellButtonClicked();
private:
  Ui::Widget *ui;
};

#endif // WIDGET_H
