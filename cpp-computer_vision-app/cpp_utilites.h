#ifndef CPP_UTILITES_H
#define CPP_UTILITES_H
#include <string>
#include <QString>
#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QTextEdit>

using namespace std;

class CustomConvertQtClass{
public:

    static string QCheckBox(QCheckBox *value){
        if (value->isChecked() == 1) {
            return "True";
        }
        return "False";
    };

    static string QSpinBox(QSpinBox *value)
    {
        return to_string(value->value());
    };

    static string QDoubleSpinBox(QDoubleSpinBox *value)
    {
        return to_string(value->value());
    };

    static string QTextEdit(QTextEdit *value)
    {
        return value->toPlainText().toStdString();
    };

private:
};

#endif // CPP_UTILITES_H
