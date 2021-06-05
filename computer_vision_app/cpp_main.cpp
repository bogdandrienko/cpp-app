#include "cpp_ui.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainUiClass window;
    window.show();
    return app.exec();
}

void start_analyse_main_func()
{
    std::cout << "START\n";
}

void stop_analyse_main_func()
{
    std::cout << "STOP\n";
}

void quitApp_main_func()
{
    std::cout << "QUIT\n";
}
