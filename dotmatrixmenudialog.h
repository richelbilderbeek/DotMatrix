#ifndef TOOLDOTMATRIXMENUDIALOG_H
#define TOOLDOTMATRIXMENUDIALOG_H

#include <string>
#include <vector>

#include "menudialog.h"

namespace ribi {

///GUI independent ToolDotMatrix menu dialog
struct DotMatrixMenuDialog final : public MenuDialog
{
  DotMatrixMenuDialog();
  About GetAbout() const noexcept override;
  Help GetHelp() const noexcept override;
  std::string GetVersion() const noexcept override;
  std::vector<std::string> GetVersionHistory() const noexcept override;

  private:
  int ExecuteSpecific(const std::vector<std::string>& argv) noexcept override;

  #ifndef NDEBUG
  static void Test() noexcept;
  #endif
};

} //~namespace ribi

#endif // TOOLDOTMATRIXMENUDIALOG_H
