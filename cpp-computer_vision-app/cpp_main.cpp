#include "cpp_ui.h"
#include "cpp_cv.h"
#include <QApplication>
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainUiClass window;
    window.show();
    return app.exec();
}

void start_analyse_main_func(map <string,string> SettingsMap)
{
    std::cout << "START\n";
    startAnalyse(SettingsMap);
}

void stop_analyse_main_func()
{
    std::cout << "STOP\n";
//    startAnalyse();
}

void quitApp_main_func()
{
    std::cout << "QUIT\n";
//    startAnalyse();
}
