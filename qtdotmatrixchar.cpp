/*




#include "qtdotmatrixchar.h"

#include <cassert>

#include "dotmatrixchar.h"


ribi::QtDotMatrixChar::QtDotMatrixChar(const char c)
  : m_matrix(new DotMatrixChar(c))
{
  assert(m_matrix);
}

const boost::shared_ptr<QImage> ribi::QtDotMatrixChar::CreateImage() const noexcept
{
  return m_matrix->CreateImage();
}

*/
