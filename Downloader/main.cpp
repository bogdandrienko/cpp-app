#include <QApplication>
#include "DownloaderGui.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DownloaderGui w;
    w.show();
    w.resize(280, 100);

    return a.exec();
}

