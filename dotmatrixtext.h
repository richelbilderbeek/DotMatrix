#ifndef RIBI_DOTMATRIXTEXT_H
#define RIBI_DOTMATRIXTEXT_H

#include <string>
#include <vector>
#include <memory>

struct QImage;

namespace ribi {

struct DotMatrixString;

///DotMatrixString creates a dot matrix 2D array of a string
struct DotMatrixText
{
  enum class ColorSystem { normal, inverted };
  ///Give it a std::string and a spacing (number of pixels) between the characters
  DotMatrixText(
    const std::vector<std::string>& s,
    const int spacing,
    const ColorSystem color_system = ColorSystem::normal
  );

  QImage CreateImage() const noexcept;

  ///Read back the string
  std::vector<std::string> GetText() const noexcept;

  ///Read if the coordinat is black/high or white/low
  bool GetMatrix(const int x, const int y) const noexcept;

  ///Get the matrix height
  int GetMatrixHeight() const noexcept;

  ///Get the matrix width
  int GetMatrixWidth() const noexcept;

  private:
  const ColorSystem m_color_system;
  const int m_spacing;
  const std::vector<DotMatrixString> m_v;

  static std::vector<DotMatrixString>
    CreateDotMatrixText(const std::vector<std::string>& s, const int spacing) noexcept;
};

std::ostream& operator<<(std::ostream& os, const DotMatrixText& m) noexcept;

} //~namespace ribi


#endif // RIBI_DOTMATRIXTEXT_H
