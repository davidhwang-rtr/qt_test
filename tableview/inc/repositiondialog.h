#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>

#include "defines.h"
#include "configrobotsensor.h"
#include "errormessage.h"
#include "rtr-control/inc/rtr-control/JointConfiguration.hpp"
#include "rtrslider.hpp"
#ifdef BACKEND_CONNECTED
#include "calibrationInterface.h"
#else
#include "GuiBackendInterface.h"
#endif
#include "flashingled.h"

namespace Ui {
  class Dialog_Reposition;
}

class RepositionDialog : public QDialog
{
  Q_OBJECT

public:
  explicit RepositionDialog(QWidget *parent = nullptr, BackendInterface *backendManager = nullptr);
  ~RepositionDialog();
      void SetCameraName(QString &);
      void SetCameraProperty(CameraNode &);
      void SetupJogSliders();
      void NudgeRobotConfig(QString& joint_name, float newValue);

private:
  Ui::Dialog_Reposition *ui_reposition;
  QString current_uid_;
#ifdef BACKEND_CONNECTED
  CalibrationInterface *calibrationInterface;
#else
    GuiBackendInterface *calibrationInterface;
#endif
      std::vector<RTRSlider*> sliders_;
      FlashingLed *led;
      QLabel *label_status;

signals:
  void skipped();
  void continued();
  void cancelled();

public slots:
  void on_Cancelled();
  void on_Skipped();
  void on_Continued();
  void on_received_fiducial(ErrorMessage msg);
  void on_received_status(bool status);
  void on_pushButton_accept_clicked();

signals:
  void findFiducial();
};

#endif // DIALOG_H
