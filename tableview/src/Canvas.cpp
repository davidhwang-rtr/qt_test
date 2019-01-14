#include "Canvas.hpp"
#include <QApplication>
#include <rtr-utils/Log.hpp>

using namespace std;

namespace rtr {

Canvas::Canvas(QWidget* parent) : QOpenGLWidget(parent) {
  // track mouse position even when no mouse button is pressed (for action on hover)
  setMouseTracking(true);
  // allow keyboard presses to be tracked
  setFocusPolicy(Qt::StrongFocus);

  link_mesh_mode_ = LinkMeshMode::VISUAL;
}

void Canvas::timerEvent(QTimerEvent*) {
  // calls paintGL
  update();
}

void Canvas::initializeGL() {
  context()->makeCurrent(context()->surface());

  camera_.reset(new Camera);
  scene_manager_.reset(new SceneManager);
  scene_manager_->Init();
  camera_axes_.Init(camera_);

  // run graphics at ~30 fps
  timer_.start(33, this);
}

////////////////////////////////////////////////////////////////////////////////
// Drawing
////////////////////////////////////////////////////////////////////////////////

void Canvas::paintGL() {
  context()->makeCurrent(context()->surface());
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
  glDisable(GL_COLOR_LOGIC_OP);
  glLogicOp(GL_COPY);
  glEnable(GL_MULTISAMPLE);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glViewport(0, 0, width_, height_);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  DrawGrid(10, 1.0);
  scene_manager_->CollideMouseRay(*camera_, mouse_x_, mouse_y_, active_mesh_name_, position_);

  DrawRobot();
  scene_manager_->DrawScene(*camera_);
  camera_axes_.Draw();
}

void Canvas::DrawGrid(int num_steps, float grid_size) {
  glPushMatrix();
  glMatrixMode(GL_MODELVIEW);
  glLoadMatrixf(camera_->GetViewProjectionMat().Transpose().GLMat());

  glColor4f(0.5, 0.5, 0.5, 1.0);
  glLineWidth(1.5);
  glBegin(GL_LINES);
  float x_max = grid_size * num_steps;
  for (int i = 1; i <= num_steps; i++) {
    float pos = i * ((float) grid_size);
    glVertex3f(-x_max, +pos, 0.0);
    glVertex3f(+x_max, +pos, 0.0);
    glVertex3f(-x_max, -pos, 0.0);
    glVertex3f(+x_max, -pos, 0.0);
    glVertex3f(+pos, -x_max, 0.0);
    glVertex3f(+pos, +x_max, 0.0);
    glVertex3f(-pos, -x_max, 0.0);
    glVertex3f(-pos, +x_max, 0.0);
  }
  // x-axis
  glVertex3f(-x_max, 0.0, 0.0);
  glVertex3f(0.0, 0.0, 0.0);
  // y-axis
  glVertex3f(0.0, -x_max, 0.0);
  glVertex3f(0.0, 0.0, 0.0);
  glEnd();

  glLineWidth(2.0);
  glBegin(GL_LINES);
  // x-axis
  glColor4f(1.0, 0.0, 0.0, 1.0);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(+x_max, 0.0, 0.0);
  // y-axis
  glColor4f(0.0, 1.0, 0.0, 1.0);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(0.0, +x_max, 0.0);
  // z-axis
  glColor4f(0.0, 0.0, 1.0, 1.0);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(0.0, 0.0, +x_max);
  glEnd();

  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
}

////////////////////////////////////////////////////////////////////////////////
// Robot Drawing
////////////////////////////////////////////////////////////////////////////////

void Canvas::RemoveRobot() {
  if (robot_is_connected_) {
    for (const pair<string, shared_ptr<Link> >& robot_link : robot_->GetLinkMap()) {
      RemoveLink(robot_link.second);
    }
  }
}

void Canvas::AddRobot(const shared_ptr<Robot> robot) {
  robot_ = robot;
  robot_is_connected_ = true;
  if (robot_is_connected_) {
    for (const pair<string, shared_ptr<Link> >& robot_link : robot_->GetLinkMap()) {
      AddLink(robot_link.second);
    }
  }
}

void Canvas::AddInterface(std::shared_ptr<RobotInterface> xface) {
  xface_ = xface;
}

void Canvas::AddLink(const shared_ptr<Link>& link) {
  for (size_t i = 0; i < link->visual_meshes.size(); i++) {
    string mesh_name = "VISUAL_" + link->name + "_" + to_string(i);
    scene_manager_->AddMesh(mesh_name, link->visual_meshes[i], false, false);
    scene_manager_->SetMeshColor(mesh_name, link->visual_colors[i]);
  }
  for (size_t i = 0; i < link->collision_meshes.size(); i++) {
    string mesh_name = "COLLISION_" + link->name + "_" + to_string(i);
    scene_manager_->AddMesh(mesh_name, link->collision_meshes[i], false, true);
    scene_manager_->SetMeshColor(mesh_name, link->collision_colors[i]);
  }
}

void Canvas::RemoveLink(const shared_ptr<Link>& link) {
  for (size_t i = 0; i < link->visual_meshes.size(); i++) {
    string mesh_name = "VISUAL_" + link->name + "_" + to_string(i);
    scene_manager_->RemoveMesh(mesh_name);
  }
  for (size_t i = 0; i < link->collision_meshes.size(); i++) {
    string mesh_name = "COLLISION_" + link->name + "_" + to_string(i);
    scene_manager_->RemoveMesh(mesh_name);
  }
}

void Canvas::DrawRobot() {
  if (!robot_) {
    return;
  }
  JointConfiguration curr_config = xface_->GetCurrentConfiguration();
  if (std::isnan(curr_config[0])) {
    std::cout << "Error caught nan!" << std::endl;
  } else {
    robot_->SetConfig(curr_config);
  }
  for (const pair<string, shared_ptr<Link> >& robot_link : robot_->GetLinkMap()) {
    const shared_ptr<Link> link = robot_link.second;
    for (size_t i = 0; i < link->visual_meshes.size(); i++) {
      string mesh_name = "VISUAL_" + robot_link.first + "_" + to_string(i);
      if (link_mesh_mode_ == LinkMeshMode::VISUAL) {
        scene_manager_->SetMeshTransform(mesh_name, link->pose);
        scene_manager_->ShowMesh(mesh_name);
      } else {
        scene_manager_->HideMesh(mesh_name);
      }
    }
    for (size_t i = 0; i < link->collision_meshes.size(); i++) {
      string mesh_name = "COLLISION_" + robot_link.first + "_" + to_string(i);
      if (link_mesh_mode_ == LinkMeshMode::COLLISION) {
        scene_manager_->SetMeshTransform(mesh_name, link->pose);
        scene_manager_->ShowMesh(mesh_name);
      } else {
        scene_manager_->HideMesh(mesh_name);
      }
    }
  }
}

////////////////////////////////////////////////////////////////////////////////
// Mouse Controls
////////////////////////////////////////////////////////////////////////////////

void Canvas::resizeGL(int width, int height) {
  width_ = width;
  height_ = height;
  camera_->SetScreenSize(width_, height_);
  camera_axes_.SetScreenSize(width_, height_);
}

void Canvas::mousePressEvent(QMouseEvent* event) {
  bool left = event->button() == Qt::LeftButton;
  bool center = event->button() == Qt::MidButton;
  bool right = event->button() == Qt::RightButton;
  camera_->MousePressed(event->x(), event->y(), left, center, right);
  if (left) {
    camera_axes_.MousePressed(event->x(), event->y());
  }
}

void Canvas::mouseReleaseEvent(QMouseEvent* event) {
  bool left = event->button() == Qt::LeftButton;
  bool center = event->button() == Qt::MidButton;
  bool right = event->button() == Qt::RightButton;
  camera_->MouseReleased(left, center, right);
}

void Canvas::mouseMoveEvent(QMouseEvent* event) {
  mouse_x_ = event->x();
  mouse_y_ = event->y();
  camera_->MouseMoved(mouse_x_, mouse_y_);
  camera_axes_.MouseMoved(mouse_x_, mouse_y_);
}

void Canvas::wheelEvent(QWheelEvent* event) {
  camera_->MouseScrolled(event->delta());
}

void Canvas::keyPressEvent(QKeyEvent* event) {
  QKeyEvent* key = static_cast<QKeyEvent*>(event);
  if (key->key() == Qt::Key_Shift) {
    camera_->ShiftPressed();
  }
}

void Canvas::keyReleaseEvent(QKeyEvent* event) {
  QKeyEvent* key = static_cast<QKeyEvent*>(event);
  if (key->key() == Qt::Key_Shift) {
    camera_->ShiftReleased();
  }
}

}  // namespace rtr
