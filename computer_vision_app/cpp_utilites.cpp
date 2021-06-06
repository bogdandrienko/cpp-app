#include "cpp_utilites.h"

#include <iostream>
#include <string>
#include <map>

#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QTextEdit>



std::string UtilitesClass::GetValueFromMap(std::map <std::string, std::string> Map, std::string Key)
{
    for (auto& map_elem : Map)
            if(map_elem.first == Key){
                return map_elem.second;
            }
}

std::string CustomConvertQtClass::QCheckBox_obj(QCheckBox *value){
    if (value->isChecked() == 1) {
        return "True";
    }
    return "False";
};

std::string CustomConvertQtClass::QSpinBox_obj(QSpinBox *value)
{
    return std::to_string(value->value());
};

std::string CustomConvertQtClass::QDoubleSpinBox_obj(QDoubleSpinBox *value)
{
    return std::to_string(value->value());
};

std::string CustomConvertQtClass::QTextEdit_obj(QTextEdit *value)
{
    return value->toPlainText().toStdString();
};
