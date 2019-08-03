#ifndef QTDOTMATRIXMULTILINEMAINDIALOG_H
#define QTDOTMATRIXMULTILINEMAINDIALOG_H




#include <boost/shared_ptr.hpp>
#include "qthideandshowdialog.h"


struct QImage;

namespace Ui {
  class QtDotMatrixMultiLineMainDialog;
}

namespace ribi {

class QtDotMatrixMultiLineMainDialog : public QtHideAndShowDialog
{
  Q_OBJECT

public:
  explicit QtDotMatrixMultiLineMainDialog(QWidget *parent = 0);
  QtDotMatrixMultiLineMainDialog(const QtDotMatrixMultiLineMainDialog&) = delete;
  QtDotMatrixMultiLineMainDialog& operator=(const QtDotMatrixMultiLineMainDialog&) = delete;
  ~QtDotMatrixMultiLineMainDialog();

private slots:
  void on_edit_textChanged();

private:
  Ui::QtDotMatrixMultiLineMainDialog *ui;
  boost::shared_ptr<QImage> m_image;

  #ifndef NDEBUG
  static void Test() noexcept;
  #endif
};

} //~namespace ribi

#endif // QTDOTMATRIXMULTILINEMAINDIALOG_H
