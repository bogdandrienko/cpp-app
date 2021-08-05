#ifndef UIMAINWINDOW_H
#define UIMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class UiMainWindow; }
QT_END_NAMESPACE

class UiMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    UiMainWindow(QWidget *parent = nullptr);
    ~UiMainWindow();

private:
    Ui::UiMainWindow *ui;
};
#endif // UIMAINWINDOW_H
