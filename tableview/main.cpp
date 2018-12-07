#include "cameratablewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  CameraTableWidget w;
  w.show();

  return a.exec();
}
