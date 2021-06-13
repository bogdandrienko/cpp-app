#include "requestmanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RequestManager w;
    w.show();
    return a.exec();
}
