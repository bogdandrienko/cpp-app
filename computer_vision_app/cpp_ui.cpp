#include "cpp_ui.h"
#include "ui_cpp_ui.h"
#include "cpp_main.h"

#include <iostream>
#include <string>
#include <map>

#include <QtWidgets>
#include <QtNetwork>
#include <QDataStream>

#include <opencv2/opencv.hpp>

#include "windows.h"

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

std::string getVal(std::map <std::string,std::string> Map_all, std::string keys){
    for (auto& map_elem : Map_all)
            if(map_elem.first == keys){
                return map_elem.second;
            }
}


void MainUiClass::on_START_btn_clicked()
{
    SettingsMap = {
        { "protocol_type", CustomConvertQtClass::QTextEdit(ui->protocol_type_Edit)},
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
    download_from_url();
}



void MainUiClass::download_from_url()
{
    connect(&qnam, &QNetworkAccessManager::authenticationRequired, this, &MainUiClass::authentication_to_access);
    reply.reset(qnam.get(QNetworkRequest(QString::fromStdString(url_v))));
//    connect(reply.get(), &QIODevice::readyRead, this, &MainUiClass::write_to_file);
    connect(reply.get(), &QNetworkReply::finished, this, &MainUiClass::write_to_file);


//    connect(reply.get(), &QNetworkReply::finished, [=]() {

//        if(reply->error() == QNetworkReply::NoError)
//        {
//            QByteArray response = reply->readAll();
//            cv::Mat image_source = cv::Mat(620, 496, CV_8UC3, response.data());
//            if (response.count() <= 0)
//                std::cout << "response not found!" << std::endl;
//            std::cout << "response count : " << response.count() << std::endl;
//            cv::imshow("render", image_source);
////            write_to_file();
//        }
//    });
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
    file = openFileForWrite(QString::fromStdString("./" + getVal(SettingsMap, "alias cam") + ".jpg"));
    if(reply->readAll().isNull())
        std::cout << "readAll not found!" << std::endl;
    file->write(reply->readAll());
    file->close();
    analyse_from_image();
}



cv::Mat qImage2Mat(const QImage& src)
{

    cv::Mat tmp(src.height(),src.width(), CV_16UC1,(uchar*)src.bits(),src.bytesPerLine());
    cv::Mat res;
    cv::cvtColor(tmp, res, cv::COLOR_RGB2GRAY);
    return res;
}

cv::Mat qimage_to_mat_cpy(QImage const &img, int format) {
    return cv::Mat(img.height(), img.width(), format,
                   const_cast<uchar*>(img.bits()),
                   img.bytesPerLine()).clone();
}

cv::Mat QImage2Mat(QImage const& src)
{
     cv::Mat tmp(src.height(),src.width(),CV_8UC3,(uchar*)src.bits(),src.bytesPerLine());
     cv::Mat result; // deep copy just in case (my lack of knowledge with open cv)
     cv::cvtColor(tmp, result,cv::COLOR_BGR2RGB);
     return result;
}

void MainUiClass::analyse_from_image()
{
//    for(auto& item : SettingsMap)
//    {
//        std::cout << item.first << " : " << item.second << std::endl; //Вывод ключей и значений
//    }

    cv::VideoCapture cap;
//    cap.set(cv::CAP_PROP_POS_FRAMES, 60.0);
    cap.set(cv::CAP_PROP_FPS , 1.0);
//    cap.set()
    cap.open("http://via.placeholder.com/1000.jpg");
    cv::Mat image_source;
    cap.read(image_source);
    cv::imshow("render", image_source);
    cv::waitKey(0);

//    QByteArray qbytearray = reply->readAll();
//    if (qbytearray.count() <= 0)
//        std::cout << "qbytearray not found!" << std::endl;
//    std::cout << "qbytearray count : " << qbytearray.count() << std::endl;

////    QImage qimg;
////    qimg.loadFromData(qbytearray.data());

//    cv::Mat image_source = cv::Mat(620, 496, CV_8UC3, qbytearray.data());
////    cv::Mat image_source1 = cv::Mat(qimg.height(), qimg.width(), CV_8UC(qimg.depth()/8), (uchar*)qimg.bits(), qimg.bytesPerLine());
//    cv::imshow("render", image_source);


//    QPixmap pixmap = QPixmap::fromImage(qimg);

//    cv::Mat image_source = cv::Mat(200, 200, CV_8UC4, reply->readAll());
//    cv::Mat image_source = cv::Mat(200, 200, CV_8UC4, qbytearray.data());
//    cv::imshow("render", image_source1);


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

    Sleep(250);
    download_from_url();
}
