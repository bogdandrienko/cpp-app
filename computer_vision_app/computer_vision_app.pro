QT       += core
QT       += widgets
QT       += gui
QT       += network
QT       += sql
QT       += concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cpp_main.cpp

HEADERS += \
    cpp_main.h

FORMS += \
    cpp_main.ui

TARGET = SMART
TEMPLATE = app

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# old
#win32:CONFIG(release, debug|release): LIBS += -LC:/Project/Envire/opencv-4.5.2/build/x64/vc15/lib/ -lopencv_world452
#else:win32:CONFIG(debug, debug|release): LIBS += -LC:/Project/Envire/opencv-4.5.2/build/x64/vc15/lib/ -lopencv_world452d
#else:unix: LIBS += -LC:/Project/Envire/opencv-4.5.2/build/x64/vc15/lib/ -lopencv_world452
#
#INCLUDEPATH += C:/Project/Envire/opencv-4.5.2/build/include
#DEPENDPATH += C:/Project/Envire/opencv-4.5.2/build/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/opencv-src/opencv_4_5_2/openvc_4_5_2_build/build/x64/vc15/lib/ -lopencv_world452
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/opencv-src/opencv_4_5_2/openvc_4_5_2_build/build/x64/vc15/lib/ -lopencv_world452d
else:unix: LIBS += -L$$PWD/opencv-src/opencv_4_5_2/openvc_4_5_2_build/build/x64/vc15/lib/ -lopencv_world452

INCLUDEPATH += $$PWD/opencv-src/opencv_4_5_2/openvc_4_5_2_build/build/include
DEPENDPATH += $$PWD/opencv-src/opencv_4_5_2/openvc_4_5_2_build/build/include
