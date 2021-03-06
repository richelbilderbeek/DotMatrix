


#include "qtdotmatrixmultilinemaindialog.h"

#include <cassert>
#include <QPainter>

#include <boost/algorithm/string/split.hpp>

#include "container.h"
#include "dotmatrixtext.h"
#include "testtimer.h"
#include "trace.h"

#include "ui_qtdotmatrixmultilinemaindialog.h"


ribi::QtDotMatrixMultiLineMainDialog::QtDotMatrixMultiLineMainDialog(QWidget *parent)
  : QtHideAndShowDialog(parent),
    ui(new Ui::QtDotMatrixMultiLineMainDialog),
    m_image{}
{
  #ifndef NDEBUG
  Test();
  #endif
  ui->setupUi(this);
}

ribi::QtDotMatrixMultiLineMainDialog::~QtDotMatrixMultiLineMainDialog()
{
  delete ui;
}

void ribi::QtDotMatrixMultiLineMainDialog::on_edit_textChanged()
{
  const auto v
    = Container().SeperateString(ui->edit->toPlainText().toStdString(),'\n');

  const DotMatrixText m(v,1);
  m_image = m.CreateImage();
  ui->image->setPixmap(QPixmap::fromImage(*m_image.get()));
}

#ifndef NDEBUG
void ribi::QtDotMatrixMultiLineMainDialog::Test() noexcept
{
  {
    static bool is_tested{false};
    if (is_tested) return;
    is_tested = true;
  }
  const TestTimer test_timer(__func__,__FILE__,1.0);
  QtDotMatrixMultiLineMainDialog d;
  d.ui->edit->setPlainText("Hello\n World");
  d.on_edit_textChanged();
}
#endif

