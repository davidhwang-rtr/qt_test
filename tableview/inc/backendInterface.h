#ifndef BACKENDINTERFACE_H
#define BACKENDINTERFACE_H
#include <QObject>

class BackendInterface : public QObject
{
  Q_OBJECT

public:
  BackendInterface();
  virtual ~BackendInterface(){}

  virtual void InitializeCalibrationManager() = 0;

private:
  std::string active_uid_;
  bool start_init_;
  bool ready_to_add_bot_;

  bool calmgr_inited_;
  bool stream_active_;
  bool work_thread_busy_;

  bool robot_selected_;
  bool package_path_set_;
  bool ip_address_set_;
};
#endif // CALIBRAIONINTERFACE_H
