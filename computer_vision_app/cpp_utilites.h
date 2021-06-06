#ifndef CPP_UTILITES_H
#define CPP_UTILITES_H

#include <iostream>
#include <string>
#include <map>

#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QTextEdit>


class UtilitesClass{
public:

    static std::string GetValueFromMap(std::map <std::string, std::string> Map, std::string Key);


private:
};



class CustomConvertQtClass{
public:

    static std::string QCheckBox_obj(QCheckBox *value);

    static std::string QSpinBox_obj(QSpinBox *value);

    static std::string QDoubleSpinBox_obj(QDoubleSpinBox *value);

    static std::string QTextEdit_obj(QTextEdit *value);

private:
};

#endif // CPP_UTILITES_H
