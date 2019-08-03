#ifndef QTDOTMATRIXSTRING_H
#define QTDOTMATRIXSTRING_H

/*

#include <string>
#include <vector>




#include <boost/shared_ptr.hpp>
//#include <QPixmap>


struct QImage;

namespace ribi {

struct DotMatrixString;

///QtDotMatrix creates a dot matrix QImage of a character
struct QtDotMatrixString
{
  QtDotMatrixString(const std::string& s, const int spacing);

  ///Read back the dot matrix info
  const boost::shared_ptr<const DotMatrixString> GetMatrix() const noexcept { return m_matrix; }

  ///Create a QImage from the character
  const boost::shared_ptr<QImage> CreateImage() const noexcept;

  private:
  const boost::shared_ptr<DotMatrixString> m_matrix;
};

} //~namespace ribi
*/

#endif // QTDOTMATRIXSTRING_H
