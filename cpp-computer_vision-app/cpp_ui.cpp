#include "cpp_ui.h"
#include "ui_cpp_ui.h"
#include "cpp_main.h"
#include "cpp_utilites.h"
#include <iostream>
#include <string>
#include <QMessageBox>
#include <QNetworkReply>
#include <map>

using namespace std;

MainUiClass::MainUiClass(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainUiClass)
{
    ui->setupUi(this);
}


MainUiClass::~MainUiClass()
{
    delete ui;
}


map <string,string> GetData(Ui::MainUiClass *ui){
    map <string,string> SettingsMap = {
        { "protocol_type", CustomConvertQtClass::QTextEdit(ui->protocol_type_Edit) },
        { "port_cam", CustomConvertQtClass::QSpinBox(ui->port_cam_spinBox) },
        { "write_now_sql", CustomConvertQtClass::QCheckBox(ui->write_now_sql_checkBox) },
        { "correct_coefficient_1", CustomConvertQtClass::QDoubleSpinBox(ui->correct_coefficient_1_doubleSpinBox) }
    };
    for (auto it = SettingsMap.begin(); it != SettingsMap.end(); ++it)
    {
        cout << it->first << " : " << it->second << endl;
    }
    return SettingsMap;
}

void MainUiClass::on_START_btn_clicked()
{
    map <string,string> SettingsMap = {
        { "protocol_type", CustomConvertQtClass::QTextEdit(ui->protocol_type_Edit) },
        { "port_cam", CustomConvertQtClass::QSpinBox(ui->port_cam_spinBox) },
        { "login cam", CustomConvertQtClass::QTextEdit(ui->login_cam_Edit) },
        { "password cam", CustomConvertQtClass::QTextEdit(ui->password_cam_Edit) },

        { "alias cam", CustomConvertQtClass::QTextEdit(ui->alias_cam_1_Edit) },
        { "ip cam", CustomConvertQtClass::QTextEdit(ui->ip_cam_1_Edit) },
        { "mask cam", CustomConvertQtClass::QTextEdit(ui->mask_cam_1_Edit) },
        { "sensetivity cam", CustomConvertQtClass::QSpinBox(ui->sensetivity_cam_1_Edit) },
        { "alarm level", CustomConvertQtClass::QSpinBox(ui->alarm_level_1_SpinBox) },
        { "correct_coefficient", CustomConvertQtClass::QDoubleSpinBox(ui->correct_coefficient_1_doubleSpinBox) },

        { "write_now_sql", CustomConvertQtClass::QCheckBox(ui->write_now_sql_checkBox) },
    };
//    start_analyse_main_func(SettingsMap);
//    start_analyse_main_func(GetData());
    MainUiClass downloader;
    downloader.startDownload();
}



void MainUiClass::startDownload()
{
    std::cout << "START startDownload" << std::endl;
    url = "http://via.placeholder.com/300.jpg";
    httpRequestAborted = false;

    reply.reset(qnam.get(QNetworkRequest(url)));
    connect(reply.get(), &QIODevice::readyRead, this, &MainUiClass::downloadFinished);

    std::cout << "FINISH startDownload" << std::endl;
}

void MainUiClass::downloadFinished()
{
    std::cout << "START downloadFinished" << std::endl;

    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

    QFile *files = new QFile("C:/Images/2.txt", this);
    files->open(QIODevice::WriteOnly);
    files->write(reply->readAll());

    QImage* img = new QImage();
    img->loadFromData(reply->readAll());
    img->save("C:/Images/2.jpg", "JPG");

    std::cout << "FINISH downloadFinished" << std::endl;
    reply->deleteLater();
}





void MainUiClass::on_STOP_btn_clicked()
{
    stop_analyse_main_func();
}


void MainUiClass::on_QUIT_btn_clicked()
{
    quitApp_main_func();
}
