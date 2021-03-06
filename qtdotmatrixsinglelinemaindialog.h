#ifndef QTTOOLDOTMATRIXMAINDIALOG_H
#define QTTOOLDOTMATRIXMAINDIALOG_H




#include <boost/shared_ptr.hpp>
#include "qthideandshowdialog.h"


namespace Ui {
  class QtDotMatrixSingleLineMainDialog;
}

struct QImage;

namespace ribi {

class QtDotMatrixSingleLineMainDialog : public QtHideAndShowDialog
{
  Q_OBJECT

public:
  explicit QtDotMatrixSingleLineMainDialog(QWidget *parent = 0);
  QtDotMatrixSingleLineMainDialog(const QtDotMatrixSingleLineMainDialog&) = delete;
  QtDotMatrixSingleLineMainDialog& operator=(const QtDotMatrixSingleLineMainDialog&) = delete;
  ~QtDotMatrixSingleLineMainDialog() noexcept;

private slots:
  void on_text_textChanged(const QString &arg1);

private:
  Ui::QtDotMatrixSingleLineMainDialog *ui;
  boost::shared_ptr<QImage> m_image;

  #ifndef NDEBUG
  static void Test() noexcept;
  #endif
};

} //~namespace ribi

#endif // QTTOOLDOTMATRIXMAINDIALOG_H
