#include <string>
#include <vector>




#include <boost/shared_ptr.hpp>
#include <boost/lexical_cast.hpp>
#include "dotmatrixmenudialog.h"



int main(int argc, char* argv[])
{
  ribi::DotMatrixMenuDialog d;
  const std::vector<std::string> args { ribi::MenuDialog::ConvertArguments(argc,argv) };
  return d.Execute(args);
}
