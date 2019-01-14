#ifndef CANVAS_H_
#define CANVAS_H_

#include <QBasicTimer>
#include <QDockWidget>
#include <QMouseEvent>
#include <QOpenGLWidget>
#include <memory>
#include "defines.h"
#include "rtr-geometry/MeshPrimitives.hpp"
#include "rtr-control/RobotInterface.hpp"
#include "rtr-core/Robot.hpp"
#include "rtr-rendering/Camera.hpp"
#include "rtr-rendering/CameraAxes.hpp"
#include "rtr-rendering/SceneManager.hpp"

namespace rtr {

enum LinkMeshMode { VISUAL, COLLISION };

class Canvas : public QOpenGLWidget {
  Q_OBJECT

 public:
  Canvas(QWidget* parent = nullptr);
  void Connect(std::shared_ptr<SceneManager> scene_manager, std::shared_ptr<Camera> camera);

  void AddRobot(const std::shared_ptr<Robot> robot);
  void AddInterface(std::shared_ptr<RobotInterface> xface);
  void RemoveRobot();
  void AddLink(const std::shared_ptr<Link>& link);
  void RemoveLink(const std::shared_ptr<Link>& link);

  void AddSensor(const std::string serial_no, const Mat4& tf);
  void RemoveSensor(const std::string serial_no);
  void CameraFrustumWireframe(const Mat4& model, float fov_x, float fov_y, float z_near,
                              float z_far);
  void DrawFrustums();

  void SetLinkMeshMode(int mode);

 public slots:
  void DrawRobot();

 protected:
  void timerEvent(QTimerEvent* event) override;
  void initializeGL() override;
  void paintGL() override;

  void resizeGL(int width, int height) override;
  void mousePressEvent(QMouseEvent* event) override;
  void mouseReleaseEvent(QMouseEvent* event) override;
  void mouseMoveEvent(QMouseEvent* event) override;
  void wheelEvent(QWheelEvent* event) override;
  void keyPressEvent(QKeyEvent* event) override;
  void keyReleaseEvent(QKeyEvent* event) override;

 private:
  void Clear(const Vec4& color);
  void DrawGrid(int num_steps, float grid_size);

  std::shared_ptr<Camera> camera_;
  CameraAxes camera_axes_;

  int mouse_x_, mouse_y_;
  int width_, height_;

  // timer for display update
  QBasicTimer timer_;

  // Link mesh mode (visual/collision)
  LinkMeshMode link_mesh_mode_;

  std::map<std::string, Mat4> frustum_transforms_;

  std::shared_ptr<SceneManager> scene_manager_;
  Vec3 position_;
  std::string active_mesh_name_;

  std::shared_ptr<Robot> robot_;
  rtr::RobotInterface::Ptr xface_;

  bool robot_is_connected_;
};

}  // namespace rtr

#endif  // CANVAS_H_
