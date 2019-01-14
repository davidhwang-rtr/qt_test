#include <QApplication>
#include "repositiondialog.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  RepositionDialog w;
  w.show();

  return a.exec();
}
