#ifndef MAINUICLASS_H
#define MAINUICLASS_H

#include <QMainWindow>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainUiClass; }
QT_END_NAMESPACE

class MainUiClass : public QMainWindow
{
    Q_OBJECT

public:
    MainUiClass(QWidget *parent = nullptr);
    ~MainUiClass();
    std::string GetData();

private slots:
    void on_START_btn_clicked();

    void on_STOP_btn_clicked();

    void on_QUIT_btn_clicked();

private:
    Ui::MainUiClass *ui;

};

#endif // MAINUICLASS_H
