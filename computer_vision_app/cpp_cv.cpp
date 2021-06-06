#include "cpp_cv.h"
#include "cpp_main.h"
#include "cpp_utilites.h"
#include "ui_cpp_ui.h"

#include <iostream>
#include <string>
#include <map>

#include <QObject>
#include <QStringList>
#include <QFile>
#include <QDir>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QApplication>
#include <QtWidgets>
#include <QtNetwork>
#include <QDataStream>

#include <opencv2/opencv.hpp>



//ComputerVisionClass::ComputerVisionClass(QWidget *parent)
//    : QMainWindow(parent)
//    , vision(new Vision::ComputerVisionClass)
//{
//    vision->setupVision(this);
//}

//ComputerVisionClass::~ComputerVisionClass()
//{
//    delete vision;
//}


void ComputerVisionClass::StartAnalyse_1(std::map <std::string, std::string> AllSettingsMap)
{
    std::cout << "StartAnalyse" << std::endl;

//    for(auto& item : AllSettingsMap)
//    {
//        std::cout << item.first << " : " << item.second << std::endl;
//    }

    std::string val[] = {
//        "15.202",
//        "15.206",
//        "15.207",
//        "15.208",
//        "15.209",
//        "15.210",
//        "15.211",
        "15.203",
//        "15.204",
//        "15.205",
    };
    for (auto ip : val){
        std::map <std::string, std::string> OneSettingsMap = {
            { "protocol_type", UtilitesClass::GetValueFromMap(AllSettingsMap, "protocol_type") },
            { "port_cam", UtilitesClass::GetValueFromMap(AllSettingsMap, "port_cam") },
            { "login_cam", UtilitesClass::GetValueFromMap(AllSettingsMap, "login_cam") },
            { "password_cam", UtilitesClass::GetValueFromMap(AllSettingsMap, "password_cam") },

            { "alias_cam", UtilitesClass::GetValueFromMap(AllSettingsMap, "alias_cam") },
            { "ip_cam", ip },
            { "mask_cam", UtilitesClass::GetValueFromMap(AllSettingsMap, "mask_cam") },
            { "sensetivity_cam", UtilitesClass::GetValueFromMap(AllSettingsMap, "sensetivity_cam") },
            { "alarm_level", UtilitesClass::GetValueFromMap(AllSettingsMap, "alarm_level") },
            { "correct_coefficient", UtilitesClass::GetValueFromMap(AllSettingsMap, "correct_coefficient") },

            { "write_now_sql", UtilitesClass::GetValueFromMap(AllSettingsMap, "write_now_sql") },
        };
        ComputerVisionClass::AnalyseThread_2(OneSettingsMap);
    }
};

void ComputerVisionClass::AnalyseThread_2(std::map <std::string, std::string> OneSettingsMap)
{
    std::cout << "AnalyseThread_2" << std::endl;

//    for(auto& item : OneSettingsMap)
//    {
//        std::cout << item.first << " : " << item.second << std::endl;
//    }
    std::string url_address;

    if (UtilitesClass::GetValueFromMap(OneSettingsMap, "protocol_type") == "http") {
//        "http://192.168.15.203:80/ISAPI/Streaming/channels/101/picture?snapShotImageType=JPEG";
        url_address = UtilitesClass::GetValueFromMap(OneSettingsMap, "protocol_type") + "://192.168." +
                UtilitesClass::GetValueFromMap(OneSettingsMap, "ip_cam") + ":" + UtilitesClass::GetValueFromMap(OneSettingsMap, "port_cam") +
                "/ISAPI/Streaming/channels/101/picture?snapShotImageType=JPEG";
//        std::cout << url_address << std::endl;
    }
    if (UtilitesClass::GetValueFromMap(OneSettingsMap, "protocol_type") == "rtsp") {
//        "rtsp://admin:q1234567@192.168.15.203:554";
        url_address = UtilitesClass::GetValueFromMap(OneSettingsMap, "protocol_type") + "://" +
                UtilitesClass::GetValueFromMap(OneSettingsMap, "login_cam") + ":" + UtilitesClass::GetValueFromMap(OneSettingsMap, "password_cam") +
                "@" + "192.168." + UtilitesClass::GetValueFromMap(OneSettingsMap, "ip_cam") + ":" + UtilitesClass::GetValueFromMap(OneSettingsMap, "port_cam");
//        std::cout << url_address << std::endl;
    }

    url_address = "http://via.placeholder.com/1000.jpg";
    ComputerVisionClass Downloader;
    Downloader.DownloadImage_3(url_address);

};

bool ComputerVisionClass::DownloadImage_3(std::string Url)
{
     std::cout << "DownloadImage_3" << std::endl;

//     QNetworkAccessManager qNetworkAccessManager;
//     QScopedPointer<QNetworkReply, QScopedPointerDeleteLater> qNetworkReply;
//     QAuthenticator qAuthenticator;
//     QUrl qUrl;

//    qAuthenticator::setUser(QString::fromStdString(Login))
//    qAuthenticator::setUser(QString::fromStdString(Login))

//     qNetworkReply->connect(&qNetworkAccessManager, &QNetworkAccessManager::authenticationRequired, this, &ComputerVisionClass::AuthenticationCam_4);
////     QObject::connect(&qNetworkAccessManager, &QNetworkAccessManager::authenticationRequired, this, &ComputerVisionClass::AuthenticationCam_4);
//     qNetworkReply.reset(qNetworkAccessManager.get(QNetworkRequest(QString::fromStdString(Url))));
//     auto val = qNetworkAccessManager.get(QNetworkRequest(QString::fromStdString(Url)));

//     std::cout << qNetworkReply->size() << std::endl;
//     QObject::connect(reply.get(), &QNetworkReply::finished, this, &ComputerVisionClass::GetImage_4);

     DownloaderClass downloaded;
     downloaded.downloading();

     return true;
//     cv::Mat image = GetImage_4("16_8.jpg", cv::IMREAD_COLOR);
};

void ComputerVisionClass::AuthenticationCam_4(QNetworkReply *, QAuthenticator *authenticator)
{
    std::cout << "AuthenticationCam_4" << std::endl;

    authenticator->setUser(QString::fromStdString(Login));
    authenticator->setPassword(QString::fromStdString(Password));
};


cv::Mat ComputerVisionClass::GetImage_4(std::string Path, int Flags)
{
    std::cout << "GetImage_4" << std::endl;

    cv::Mat image_source = cv::imread(Path, Flags);
    return image_source;
};

double ComputerVisionClass::AnalyseImage_5(std::map <std::string, std::string> Map)
{
    std::cout << "AnalyseImage_5" << std::endl;

    double value = 0.0;

    return value;
};

void ComputerVisionClass::WriteResult_6(double Value)
{
    std::cout << "WriteResult_6" << std::endl;

    std::cout << "Final Value : " << Value << std::endl;
}






//DownloaderClass::DownloaderClass(QWidget *parent)
//    : QMainWindow(parent)
//    , download(new DownloaderClass)
//{
//    std::cout << "DownloaderClass" << std::endl;
////    download->on_START_btn_clicked();
////    download->setupUi(this);
//}

//DownloaderClass::~DownloaderClass()
//{
//    delete download;
//}





void DownloaderClass::downloading()
{
    std::cout << "download" << std::endl;
//    QObject::connect(&qnam, &QNetworkAccessManager::authenticationRequired, this, &DownloaderClass::authentication_to_access);
//    reply.reset(qnam.get(QNetworkRequest(QString::fromStdString(url_v))));
//    QObject::connect(reply.get(), &QNetworkReply::finished, this, &DownloaderClass::write_to_file);
}

void DownloaderClass::authentication_to_access(QNetworkReply *, QAuthenticator *authenticator)
{
    authenticator->setUser("admin");
    authenticator->setPassword("q1234567");
}

std::unique_ptr<QFile> DownloaderClass::openFileForWrite(const QString &fileName)
{
    std::unique_ptr<QFile> file = std::make_unique<QFile>(fileName);
    if (!file->open(QIODevice::WriteOnly)) {
//        QMessageBox::information(this, tr("Error"),
//                                 tr("Unable to save the file %1: %2.")
//                                 .arg(QDir::toNativeSeparators(fileName),
//                                      file->errorString()));
        return nullptr;
    }
    return file;
}

void DownloaderClass::write_to_file()
{
    file = openFileForWrite(QString::fromStdString("./" + UtilitesClass::GetValueFromMap(SettingsMap, "alias cam") + ".jpg"));
    if(reply->readAll().isNull())
        std::cout << "readAll not found!" << std::endl;
    file->write(reply->readAll());
    file->close();
    analyse_from_image();
}

void DownloaderClass::analyse_from_image()
{
    cv::imshow("render", cv::imread("16_8.jpg", cv::IMREAD_COLOR));

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
}
