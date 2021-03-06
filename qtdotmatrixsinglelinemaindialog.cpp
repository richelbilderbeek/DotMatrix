


#include "qtdotmatrixsinglelinemaindialog.h"

#include <cassert>
#include <QPainter>

#include "dotmatrixstring.h"
#include "testtimer.h"
#include "trace.h"
#include "ui_qtdotmatrixsinglelinemaindialog.h"


ribi::QtDotMatrixSingleLineMainDialog::QtDotMatrixSingleLineMainDialog(QWidget *parent)
  : QtHideAndShowDialog(parent),
    ui(new Ui::QtDotMatrixSingleLineMainDialog),
    m_image{}
{
  #ifndef NDEBUG
  Test();
  #endif
  ui->setupUi(this);
}

ribi::QtDotMatrixSingleLineMainDialog::~QtDotMatrixSingleLineMainDialog() noexcept
{
  delete ui;
}

void ribi::QtDotMatrixSingleLineMainDialog::on_text_textChanged(const QString& text)
{
  const DotMatrixString m(text.toStdString(),1);
  m_image = m.CreateImage();
  ui->image->setPixmap(QPixmap::fromImage(*m_image.get()));
}

#ifndef NDEBUG
void ribi::QtDotMatrixSingleLineMainDialog::Test() noexcept
{
  {
    static bool is_tested{false};
    if (is_tested) return;
    is_tested = true;
  }
  {

  }
  const TestTimer test_timer(__func__,__FILE__,1.0);
  QtDotMatrixSingleLineMainDialog d;
  d.on_text_textChanged("Hello world");
}
#endif
