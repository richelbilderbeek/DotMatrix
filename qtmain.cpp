#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include "qtdotmatrixmenudialog.h"
#include <QApplication>
#pragma GCC diagnostic pop

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  ribi::QtDotMatrixMenuDialog w;
  w.show();
  return a.exec();
}
