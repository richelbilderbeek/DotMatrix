# C++17
CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++17

QMAKE_CXXFLAGS += -Wall -Wextra -Werror

# Go ahead and use Qt.Core: it is about as platform-independent as
# the STL and Boost
QT += core

# Go ahead and use Qt.Gui: it is about as platform-independent as
# the STL and Boost. It is needed for QImage
QT += gui

# Don't define widgets: it would defy the purpose of this console
# application to work non-GUI
#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Debug and release mode
CONFIG   += debug_and_release

#
#
# Type of compile
#
#
CONFIG(release, debug|release) {
  DEFINES += NDEBUG
}

include(../RibiLibraries/Boost.pri)
include(../RibiClasses/CppAbout/CppAbout.pri)
include(../RibiClasses/CppFileIo/CppFileIo.pri)
include(../RibiClasses/CppHelp/CppHelp.pri)
include(../RibiClasses/CppMenuDialog/CppMenuDialog.pri)

#Specific, console
include(../RibiClasses/CppContainer/CppContainer.pri)
include(DotMatrix.pri)
include(../RibiClasses/CppFuzzy_equal_to/CppFuzzy_equal_to.pri)
include(../DotMatrix/DotMatrixConsole.pri)

SOURCES += main.cpp

# QResources give this error
QMAKE_CXXFLAGS += -Wno-unused-variable

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
