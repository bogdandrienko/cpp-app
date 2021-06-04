QT += network widgets
android: qtHaveModule(androidextras) {
    QT += androidextras
    DEFINES += REQUEST_PERMISSIONS_ON_ANDROID
}

HEADERS += httpwindow.h
SOURCES += httpwindow.cpp \
           main.cpp
FORMS += authenticationdialog.ui

# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/http
INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -LC:/Project/Envire/opencv-4.5.2/build/x64/vc15/lib/ -lopencv_world452
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/Project/Envire/opencv-4.5.2/build/x64/vc15/lib/ -lopencv_world452d
else:unix: LIBS += -LC:/Project/Envire/opencv-4.5.2/build/x64/vc15/lib/ -lopencv_world452

INCLUDEPATH += C:/Project/Envire/opencv-4.5.2/build/include
DEPENDPATH += C:/Project/Envire/opencv-4.5.2/build/include
