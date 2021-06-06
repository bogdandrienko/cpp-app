#include "cpp_ui.h"
#include "ui_cpp_ui.h"
#include "cpp_main.h"
#include "cpp_utilites.h"

#include <iostream>
#include <string>
#include <map>

#include <QtWidgets>
#include <QtNetwork>
#include <QDataStream>

#include <opencv2/opencv.hpp>



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

void MainUiClass::on_START_btn_clicked()
{
    std::cout << "on_START_btn_clicked" << std::endl;

    std::map <std::string, std::string> AllSettingsMap = {
        { "protocol_type", CustomConvertQtClass::QTextEdit_obj(ui->protocol_type_Edit)},
        { "port_cam", CustomConvertQtClass::QSpinBox_obj(ui->port_cam_spinBox) },
        { "login_cam", CustomConvertQtClass::QTextEdit_obj(ui->login_cam_Edit) },
        { "password_cam", CustomConvertQtClass::QTextEdit_obj(ui->password_cam_Edit) },

        { "alias_cam", CustomConvertQtClass::QTextEdit_obj(ui->alias_cam_1_Edit) },
        { "ip_cam", CustomConvertQtClass::QTextEdit_obj(ui->ip_cam_1_Edit) },
        { "mask_cam", CustomConvertQtClass::QTextEdit_obj(ui->mask_cam_1_Edit) },
        { "sensetivity_cam", CustomConvertQtClass::QSpinBox_obj(ui->sensetivity_cam_1_Edit) },
        { "alarm_level", CustomConvertQtClass::QSpinBox_obj(ui->alarm_level_1_SpinBox) },
        { "correct_coefficient", CustomConvertQtClass::QDoubleSpinBox_obj(ui->correct_coefficient_1_doubleSpinBox) },

        { "write_now_sql", CustomConvertQtClass::QCheckBox_obj(ui->write_now_sql_checkBox) },
    };
//    MainAppClass::start_analyse_main_func(AllSettingsMap);
    download_from_url();
}



void MainUiClass::download_from_url()
{
    connect(&qnam, &QNetworkAccessManager::authenticationRequired, this, &MainUiClass::authentication_to_access);
    reply.reset(qnam.get(QNetworkRequest(QString::fromStdString(url_v))));
    connect(reply.get(), &QNetworkReply::finished, this, &MainUiClass::write_to_file);
}

void MainUiClass::authentication_to_access(QNetworkReply *, QAuthenticator *authenticator)
{
    authenticator->setUser("admin");
    authenticator->setPassword("q1234567");
}

std::unique_ptr<QFile> MainUiClass::openFileForWrite(const QString &fileName)
{
    std::unique_ptr<QFile> file = std::make_unique<QFile>(fileName);
    if (!file->open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Error"),
                                 tr("Unable to save the file %1: %2.")
                                 .arg(QDir::toNativeSeparators(fileName),
                                      file->errorString()));
        return nullptr;
    }
    return file;
}

void MainUiClass::write_to_file()
{
    std::cout << "write_to_file" << std::endl;
    file = openFileForWrite(QString::fromStdString("./16_8.jpg"));
    file->write(reply->readAll());
    file->close();

    analyse_from_image();
}

void MainUiClass::analyse_from_image()
{
    std::cout << "analyse_from_image" << std::endl;
    cv::Mat image = cv::imread("16_9.jpg", cv::IMREAD_COLOR);
    cv::imshow("render", image);
//    for(auto& item : SettingsMap)
//    {
//        std::cout << item.first << " : " << item.second << std::endl; //Вывод ключей и значений
//    }

//    std::string val[] = {
//        "15.202",
//        "15.206",
//        "15.207",
//        "15.208",
//        "15.209",
//        "15.210",
//        "15.211",
//        "15.203",
//        "15.204",
//        "15.205",
//    };

//    cv::VideoCapture cap;
////    cap.set(cv::CAP_PROP_FPS , 15.0);
//    cv::Mat image_source;

//    for (auto ip : val){
//        cap.open("rtsp://admin:q1234567@192.168." + ip + ":554");
//        cap.read(image_source);
//        cv::imshow("render"+ ip, image_source);
//        cv::waitKey(1);
//    }


//    cv::Mat image_source = cv::imread(getVal(SettingsMap, "alias cam")+".jpg", cv::IMREAD_COLOR);
//    cv::Mat mask = cv::imread(getVal(SettingsMap, "mask cam"), 0);
//    cv::Mat bitwise_and;
//    cv::bitwise_and(image_source, image_source, bitwise_and, mask);
//    cv::Mat cvtcolor;
//    cv::cvtColor(bitwise_and, cvtcolor, cv::COLOR_BGR2HSV);
//    cv::Mat inrange;
//    cv::inRange(cvtcolor, cv::Scalar(0, 0, 150), cv::Scalar(255, 150 , 255), inrange);
////    inrange.setTo(255, mask > 0);
//    cv::Mat final;
//    cv::resize(inrange, final, cv::Size(), 0.8, 0.8, cv::INTER_LINEAR);
//    int image_white_pixels = cv::countNonZero(inrange > 120);
//    int mask_white_pixels = cv::countNonZero(mask);
//    time_t t = time(NULL);
//    cv::putText(final, asctime(localtime(&t)),
//                cv::Point(150, 50), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
//    cv::putText(final, std::to_string(double(image_white_pixels) / double(mask_white_pixels) * 100) + "%",
//                cv::Point(150, 100), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
//    cv::namedWindow("render", cv::WINDOW_AUTOSIZE);
//    cv::imshow("render", final);

    Sleep(200);
    download_from_url();
}
