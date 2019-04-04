

# C++14
CONFIG += c++14
QMAKE_CXXFLAGS += -std=c++14

# All errors
QMAKE_CXXFLAGS += -Wall -Wextra -Werror

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets svg
CONFIG += debug_and_release

include(../RibiLibraries/DesktopApplicationNoWeffcpp.pri)
include(../RibiLibraries/Boost.pri)
include(../RibiLibraries/GeneralConsole.pri)
include(../RibiLibraries/GeneralDesktop.pri)

include(../RibiClasses/CppContainer/CppContainer.pri)
include(DotMatrix.pri)
include(../RibiClasses/CppFuzzy_equal_to/CppFuzzy_equal_to.pri)
include(QtDotMatrix.pri)

include(DotMatrixDesktop.pri)

SOURCES += qtmain.cpp

# QResources give this error
QMAKE_CXXFLAGS += -Wno-unused-variable

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
