#ifndef RIBI_DOTMATRIXSTRING_H
#define RIBI_DOTMATRIXSTRING_H

#include <string>
#include <vector>





#include <boost/shared_ptr.hpp>


struct QImage;

namespace ribi {

struct DotMatrixChar;

///DotMatrixString creates a dot matrix 2D array of a string
struct DotMatrixString
{
  ///Give it a std::string and a spacing (number of pixels) between the characters
  DotMatrixString(const std::string& s = "", const int spacing = 0);

  boost::shared_ptr<QImage> CreateImage() const noexcept;

  ///Read back the string
  std::string GetString() const noexcept;

  ///Read if the coordinat is black/high or white/low
  bool GetMatrix(const int x, const int y) const noexcept;

  ///Get the matrix height
  int GetMatrixHeight() const noexcept;

  ///Get the matrix width
  int GetMatrixWidth() const noexcept;

  static std::string GetVersion() noexcept;
  static std::vector<std::string> GetVersionHistory() noexcept;

  private:
  const int m_spacing;
  const std::vector<boost::shared_ptr<const DotMatrixChar>> m_v;

  static std::vector<boost::shared_ptr<const DotMatrixChar>>
    CreateDotMatrixChars(const std::string& s) noexcept;

};

void TestDotMatrixString() noexcept;

std::ostream& operator<<(std::ostream& os, const DotMatrixString& m) noexcept;

} //~namespace ribi

#endif // RIBI_DOTMATRIXSTRING_H
