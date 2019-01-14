
#include <QApplication>

#include "mainwindow.h"

// using namespace rtr::perception;

int main(int argc, char* argv[]) {
  // Start the application and main window
//  Q_INIT_RESOURCE(shaders);
  Q_INIT_RESOURCE(resources);
  QApplication app(argc, argv);
  QCoreApplication::setApplicationName("Sensor Calibration");
  MainWindow mw /*(app.activeWindow(), path)*/;
  mw.show();
  return app.exec();
}
