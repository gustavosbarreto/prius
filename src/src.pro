QT = gui widgets webenginewidgets

CONFIG += c++11

TARGET = prius

SOURCES += main.cpp \
    application.cpp \
    prius.cpp \
    platform.cpp

HEADERS += \
    application.hpp \
    prius.hpp \
    platform.hpp

include($$PWD/modules/modules.pri)
include($$PWD/htmlview/htmlview.pri)
include($$PWD/qmlview/qmlview.pri)
