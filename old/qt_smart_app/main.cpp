#include "main.h"
#include "ui_main.h"

#include <QtCore>
#include <QtWidgets>
#include <QtNetwork>
#include <QtSql>
#include <QtConcurrent>


/* main */
int main(int argc, char *argv[])
{

    try {
        QApplication a(argc, argv);
        a.setStyle("fushion");
        UiMainWindow w;
        w.show();
        return a.exec();
    }  catch (std::string error) {
    }
}
/* main */



UiMainWindow::UiMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UiMainWindow)
{
    ui->setupUi(this);
}

UiMainWindow::~UiMainWindow()
{
    delete ui;
}

