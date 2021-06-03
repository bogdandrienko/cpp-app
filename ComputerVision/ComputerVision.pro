QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cpp_analysis.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    main.h \
    mainwindow.h \
    ui.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    ComputerVision_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Envire/opencv-4.5.2/opencv/build/x64/vc15/lib/ -lopencv_world452
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Envire/opencv-4.5.2/opencv/build/x64/vc15/lib/ -lopencv_world452d
else:unix: LIBS += -L$$PWD/../../../Envire/opencv-4.5.2/opencv/build/x64/vc15/lib/ -lopencv_world452

INCLUDEPATH += $$PWD/../../../Envire/opencv-4.5.2/opencv/build/include
DEPENDPATH += $$PWD/../../../Envire/opencv-4.5.2/opencv/build/include


#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Envire/opencv-4.5.2/opencv-4.5.2/opencv/build/x64/vc15/lib/ -lopencv_world452
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Envire/opencv-4.5.2/opencv-4.5.2/opencv/build/x64/vc15/lib/ -lopencv_world452d
#else:unix: LIBS += -L$$PWD/../../../Envire/opencv-4.5.2/opencv-4.5.2/opencv/build/x64/vc15/lib/ -lopencv_world452

#INCLUDEPATH += $$PWD/../../../Envire/opencv-4.5.2/opencv-4.5.2/opencv/build/include
#DEPENDPATH += $$PWD/../../../Envire/opencv-4.5.2/opencv-4.5.2/opencv/build/include
