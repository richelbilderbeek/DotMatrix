#include <string>
#include <vector>

#pragma GCC diagnostic push


#include <boost/shared_ptr.hpp>
#include <boost/lexical_cast.hpp>
#include "dotmatrixmenudialog.h"

#pragma GCC diagnostic pop

int main(int argc, char* argv[])
{
  ribi::DotMatrixMenuDialog d;
  const std::vector<std::string> args { ribi::MenuDialog::ConvertArguments(argc,argv) };
  return d.Execute(args);
}
