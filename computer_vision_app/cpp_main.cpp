#include "cpp_main.h"
#include "cpp_ui.h"
#include "cpp_cv.h"

#include <QApplication>
#include <iostream>
#include <map>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainUiClass window;
    window.show();
    return app.exec();
}

void MainAppClass::start_analyse_main_func(std::map <std::string, std::string> AllSettingsMap)
{
    std::cout << "start_analyse_main_func" << std::endl;

    ComputerVisionClass::StartAnalyse_1(AllSettingsMap);
}

//void stop_analyse_main_func()
//{
//    cout << "stop_analyse_main_func" << endl;
//}

//void quitApp_main_func()
//{
//    cout << "quitApp_main_func" << endl;
//}
