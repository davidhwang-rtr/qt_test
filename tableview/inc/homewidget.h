#ifndef HOMEWIDGET_H
#define HOMEWIDGET_H

#include <QWidget>

class MainWindow;

namespace Ui {
class HomepageWidget;
}

class HomeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HomeWidget(QWidget *parent = nullptr);

protected:
//  virtual QSize sizeHint() const override;

signals:

public slots:

private slots:
  void on_pushButton_calibration_clicked();

private:
    Ui::HomepageWidget *ui;
    MainWindow *mainwindow_;
};

#endif // HOMEWIDGET_H
