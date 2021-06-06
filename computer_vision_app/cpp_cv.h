#ifndef CPP_CV_H
#define CPP_CV_H

#include <iostream>
#include <string>
#include <map>
#include <string>
#include <map>
#include <memory>


#include <QMainWindow>
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


#include <QObject>
#include <QStringList>
#include <QFile>
#include <QDir>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QApplication>
#include <QProgressDialog>
#include <QUrl>
#include <QString>
#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QTextEdit>



class ComputerVisionClass{
public:
    static void StartAnalyse_1(std::map <std::string, std::string> SettingsMap);
    static void AnalyseThread_2(std::map <std::string, std::string> OneSettingsMap);

private slots:
    bool DownloadImage_3(std::string Url);
    void AuthenticationCam_4(QNetworkReply *, QAuthenticator *authenticator);
    cv::Mat GetImage_4(std::string Path, int Flags);
    double AnalyseImage_5(std::map <std::string, std::string> Map);
    void WriteResult_6(double Value);

private:
    std::unique_ptr<QFile> openFileForWrite(const QString &fileName);
    QUrl url;
    QNetworkAccessManager qnam;
    QScopedPointer<QNetworkReply, QScopedPointerDeleteLater> reply;
    std::unique_ptr<QFile> file;

    QNetworkAccessManager qNetworkAccessManager;
    QScopedPointer<QNetworkReply, QScopedPointerDeleteLater> qNetworkReply;
    QAuthenticator qAuthenticator;
    QUrl qUrl;

    std::string Login = "admin";
    std::string Password = "q1234567";
};

//QT_BEGIN_NAMESPACE
//namespace Downloader { class DownloaderClass; }
//QT_END_NAMESPACE

class DownloaderClass
{

//    Q_OBJECT

public:
//    DownloaderClass(QWidget *parent = nullptr);
//    ~DownloaderClass();

    void downloading();

private slots:

    void authentication_to_access(QNetworkReply *, QAuthenticator *authenticator);
    void write_to_file();
    void analyse_from_image();

private:
    DownloaderClass *download;

    std::unique_ptr<QFile> openFileForWrite(const QString &fileName);
    std::map <std::string,std::string> SettingsMap;
    QUrl url;
    QNetworkAccessManager qnam;
    QScopedPointer<QNetworkReply, QScopedPointerDeleteLater> reply;
    std::unique_ptr<QFile> file;
    std::string url_v = "http://via.placeholder.com/1000.jpg";
};

#endif // CPP_CV_H
