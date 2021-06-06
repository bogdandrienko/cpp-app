#ifndef CPP_MAIN_H
#define CPP_MAIN_H



#include <iostream>
#include <string>
#include <map>






class MainAppClass{
public:

    static void start_analyse_main_func(std::map <std::string, std::string> AllSettingsMap);
    void stop_analyse_main_func();
    void quitApp_main_func();

private:
};

#endif // CPP_MAIN_H
