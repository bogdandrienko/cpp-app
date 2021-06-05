#include <QApplication>
#include <QDir>
#include <QScreen>

#include "httpwindow.h"
#ifdef REQUEST_PERMISSIONS_ON_ANDROID
#include <QtAndroid>

bool requestStoragePermission() {
    using namespace QtAndroid;

    QString permission = QStringLiteral("android.permission.WRITE_EXTERNAL_STORAGE");
    const QHash<QString, PermissionResult> results = requestPermissionsSync(QStringList({permission}));
    if (!results.contains(permission) || results[permission] == PermissionResult::Denied) {
        qWarning() << "Couldn't get permission: " << permission;
        return false;
    }

    return true;
}
#endif

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
#ifdef REQUEST_PERMISSIONS_ON_ANDROID
    if (!requestStoragePermission())
        return -1;
#endif
    HttpWindow httpWin;
    const QRect availableSize = httpWin.screen()->availableGeometry();
    httpWin.resize(availableSize.width() / 5, availableSize.height() / 5);
    httpWin.move((availableSize.width() - httpWin.width()) / 2, (availableSize.height() - httpWin.height()) / 2);
#ifdef Q_OS_ANDROID
    httpWin.showMaximized();
#else
    httpWin.show();
#endif

    return app.exec();
}
