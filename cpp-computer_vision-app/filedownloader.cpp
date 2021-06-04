#include "filedownloader.h"
#include <QDebug>
#include <QImage>
#include <iostream>
#include <string>
#include "windows.h"

FileDownloader::FileDownloader(QObject *parent) :
    QObject(parent),
    webCtrl(new QNetworkAccessManager(this))
{

}

FileDownloader::~FileDownloader()
{
    delete webCtrl;
}

void FileDownloader::downloadFile(QUrl url, QString id, QString dir_absolute_path)
{
//    QString url_string = url.toString();
    QString path = dir_absolute_path;
    QFile *file = new QFile(path, this);
    if(!file->open(QIODevice::WriteOnly))
    {
        return;
    }
    QNetworkRequest request(url);
    request.setRawHeader("User-Agent", userAgent);
//    QSslConfiguration sslConfiguration(QSslConfiguration::defaultConfiguration());
//    sslConfiguration.setPeerVerifyMode(QSslSocket::VerifyNone);
//    sslConfiguration.setProtocol(QSsl::AnyProtocol);
//    request.setSslConfiguration(sslConfiguration);
    QNetworkReply *reply = webCtrl->get(request);
    replytofile.insert(reply, file);
    replytopathid.insert(reply, QPair<QString, QString>(path, id));
    QObject::connect(reply, &QNetworkReply::finished, this, &FileDownloader::fileDownloaded);
    QObject::connect(reply, &QNetworkReply::readyRead, this, &FileDownloader::onReadyRead);
}

void FileDownloader::fileDownloaded()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    if (replytofile[reply]->isOpen())
    {
        replytofile[reply]->close();
        replytofile[reply]->deleteLater();
    }
    switch(reply->error())
    {
    case QNetworkReply::NoError:
        break;
    default:
        emit error(reply->errorString().toLatin1());
        break;
    }
    emit downloaded(replytopathid[reply].first, replytopathid[reply].second);
    replytofile.remove(reply);
    replytopathid.remove(reply);
    delete reply;
}

void FileDownloader::onReadyRead()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    replytofile[reply]->write(reply->readAll());
}
