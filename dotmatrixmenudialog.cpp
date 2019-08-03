#include "dotmatrixmenudialog.h"

#include <cassert>
#include <iostream>
#include <iterator>
#include <sstream>




#include <boost/shared_ptr.hpp>
#include <boost/lexical_cast.hpp>

#include <QImage>

#include "container.h"
#include "dotmatrixstring.h"
#include "fileio.h"




ribi::DotMatrixMenuDialog::DotMatrixMenuDialog()
{
  #ifndef NDEBUG
  Test();
  #endif
}

int ribi::DotMatrixMenuDialog::ExecuteSpecific(const std::vector<std::string>& args) noexcept
{
  const int argc = static_cast<int>(args.size());
  if (argc == 1)
  {
    std::cout << GetHelp() << '\n';
    return 1;
  }

  bool silent{false};
  if (std::count(args.begin(),args.end(),"-i") || std::count(args.begin(),args.end(),"--silent"))
  {
    silent = true;
  }

  std::string text = "";
  for (int i=0; i!=argc-1; ++i) //-1 because next argument will be used
  {
    if (args[i] == "-t" || args[i] == "--text")
    {
      text = args[i + 1];
      break;
    }
  }
  if (text.empty())
  {
    if (!silent)
    {
      std::cout
        << "Please supply a text and supply it correctly,\n"
        << "for example:\n"
        << "  DotMatrix -t my_text\n"
      ;
    }
    return 1;
  }
  int spacing = 1;
  for (int i=0; i!=argc-1; ++i) //-1 because next argument will be used
  {
    if (args[i] == "-s" || args[i] == "--spacing")
    {
      const std::string s = args[i + 1];
      try
      {
        spacing = boost::lexical_cast<int>(s);
        if (spacing < 0)
        {
          if (!silent)
          {
            std::cout << "Spacing must be zero or a positive number\n";
          }
          return 1;
        }
      }
      catch (boost::bad_lexical_cast&)
      {
        if (!silent)
        {
          std::cout << "Spacing must be a number\n";
        }
        return 1;
      }
      break;
    }
  }
  std::string filename = "";
  for (int i=0; i!=argc-1; ++i) //-1 because next argument will be used
  {
    if (args[i] == "-f" || args[i] == "--filename")
    {
      filename = args[i + 1];
      break;
    }
  }

  const boost::shared_ptr<const ribi::DotMatrixString> m {
    new ribi::DotMatrixString(text,spacing)
  };

  if (!filename.empty())
  {
    m->CreateImage()->save(filename.c_str());
  }

  if (!silent)
  {
    std::cout << *m << '\n';
  }

  return 0;
}

ribi::About ribi::DotMatrixMenuDialog::GetAbout() const noexcept
{
  About a(
    "Richel Bilderbeek",
    "DotMatrix",
    "generates a dot matrix font",
    "October 28th 2016",
    "2013-2016",
    "http://www.richelbilderbeek.nl/ToolDotMatrix.htm",
    GetVersion(),
    GetVersionHistory()
  );
  a.AddLibrary("Container version: " + Container().GetVersion());
  a.AddLibrary("FileIo version: " + fileio::FileIo().GetVersion());
  return a;
}

ribi::Help ribi::DotMatrixMenuDialog::GetHelp() const noexcept
{
  return ribi::Help(
    GetAbout().GetFileTitle(),
    GetAbout().GetFileDescription(),
    {
      Help::Option('f',"filename","Save the text to an image file"),
      Help::Option('t',"text","The text to convert to file or ASCII art"),
      Help::Option('s',"spacing","Set the spacing in pixels, default: 1"),
      Help::Option('e',"silent","Produce no output"),
    },
    {
      "DotMatrix -t \"Hello world\"",
      "DotMatrix --text \"Hello world\" -s 0",
      "DotMatrix -t \"Hello world\" -f myfile.png",
      "DotMatrix -t \"Hello world\" --filename myfile.png --spacing 0",
    }
  );
}

std::string ribi::DotMatrixMenuDialog::GetVersion() const noexcept
{
  return "3.1";
}

std::vector<std::string> ribi::DotMatrixMenuDialog::GetVersionHistory() const noexcept
{
  return {
    "2009-xx-xx: version 1.0: initial VCL desktop version",
    "2013-10-11: version 2.0: port to Qt",
    "2013-11-01: version 2.1: improved console version",
    "2014-02-10: version 2.2: added multi-line version",
    "2016-01-10: version 3.0: moved to own GitHub",
    "2016-10-28: version 3.1: added Travis CI"
  };
}

#ifndef NDEBUG
void ribi::DotMatrixMenuDialog::Test() noexcept
{
  {
    static bool is_tested{false};
    if (is_tested) return;
    is_tested = true;
  }
  {
    Container();
    fileio::FileIo();
    const boost::shared_ptr<const DotMatrixString> m {
      new DotMatrixString("",0)
    };
  }
  //Command line tests
  {
    DotMatrixMenuDialog d;
    const std::string filename { fileio::FileIo().GetTempFileName(".png") };
    d.Execute( { "DotMatrix", "-t", "\"Hello world\"", "--silent" } );
    d.Execute( { "DotMatrix", "--text", "\"Hello world\"", "-s", "0", "--silent" } );

    assert(!fileio::FileIo().IsRegularFile(filename));
    d.Execute( { "DotMatrix", "-t", "\"Hello world\"", "-f", filename, "--silent" } );
    assert(fileio::FileIo().IsRegularFile(filename));

    fileio::FileIo().DeleteFile(filename);

    assert(!fileio::FileIo().IsRegularFile(filename));
    d.Execute( { "DotMatrix", "--text", "\"Hello world\"", "-f", filename, "--spacing", "1", "--silent" } );
    assert(fileio::FileIo().IsRegularFile(filename));

    fileio::FileIo().DeleteFile(filename);
  }
}
#endif
