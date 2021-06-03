#include <string>
#include <QString>

using namespace std;

string QCheckBox(int value)
{
    if (value == 1) {
        return "True";
    }
    return "False";
}

string QTextEdit(QString value)
{
    return "None";
}

string QSpinBox(int value)
{
    return "0";
}

string QDoubleSpinBox(double value)
{
    return "0.0";
}
