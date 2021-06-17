QT       += core
QT       += gui
QT       += network
QT       += sql
QT       += widgets
QT       += concurrent


HEADERS += httpwindow.h
SOURCES += httpwindow.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/http
INSTALLS += target
