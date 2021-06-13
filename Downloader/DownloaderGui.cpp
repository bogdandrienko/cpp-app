#include "DownloaderGui.h"
#include "requestmanager.h"

#include <QtCore>
#include <QtWidgets>
#include <QtNetwork>
#include <QtSql>
#include <QtConcurrent>

#include <opencv2/opencv.hpp>

std::string GetValueFromMap(std::map <std::string, std::string> Map, std::string Key)
{
    std::string value = "";
    for (auto& map_elem : Map)
        if(map_elem.first == Key){
            value = map_elem.second;
        }
    return value;
};

void DownloaderGui::showPic(const QString& strFileName)
{
    QPixmap pix(strFileName);
    pix = pix.scaled(
                pix.size() / 2,
                Qt::IgnoreAspectRatio,
                Qt::SmoothTransformation
                );
    QLabel* plbl = new QLabel;
    plbl->setPixmap(pix);
    plbl->setFixedSize(pix.size());
    plbl->show();

}

void DownloaderGui::showPic(QByteArray& ba, QString& alias)
{
    QPixmap qPixmap;
    QByteArray pData = ba;
    if(qPixmap.loadFromData(pData,"JPG"))
    {
        QImage qImage = qPixmap.toImage();
        cv::Mat mat(qImage.height(), qImage.width(), CV_8UC4, const_cast<uchar*>(qImage.bits()), static_cast<size_t>(qImage.bytesPerLine()));
        cv::resize(mat, mat, cv::Size(), 0.25, 0.25, cv::INTER_LINEAR);
        cv::imshow(alias.toStdString(), mat);
    }
}

DownloaderGui::DownloaderGui(QWidget* pwgt) : QWidget(pwgt)
{
    m_pdl = new Downloader(this);
    m_ppb = new QProgressBar;
    m_ptxt = new QLineEdit;
    m_pcmd = new QPushButton(tr("&Go"));

//    QString strDownloadLink = "http://192.168.15.203:80/ISAPI/Streaming/channels/101/picture?snapShotImageType=JPEG";
    QString strDownloadLink = "http://qt-book.com/pic.jpg";
    m_ptxt->setText(strDownloadLink);

    connect(m_pcmd, SIGNAL(clicked()), SLOT(slotGo()));
    connect(m_pdl, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(slotDownloadProgress(qint64, qint64)));
    connect(m_pdl, SIGNAL(done(const QUrl&, const QByteArray&, const QString&)), this, SLOT(slotDone(const QUrl&, const QByteArray&, const QString&)));

    QGridLayout* pLayout = new QGridLayout;
    pLayout->addWidget(m_ptxt, 0, 0);
    pLayout->addWidget(m_pcmd, 0, 1);
    pLayout->addWidget(m_ppb, 1, 0, 1, 1);
    setLayout(pLayout);
}

void DownloaderGui::slotGo()
{
    std::vector<std::map<std::string,std::string>> local_vector =
    {
        {
            { "alias_cam", "1" },
            { "ip_cam", "http://placehold.it/1000.jpg" },
        },
        {
            { "alias_cam", "2" },
            { "ip_cam", "http://placehold.it/700x400.jpg" },
        },
        {
            { "alias_cam", "3" },
            { "ip_cam", "http://qt-book.com/pic.jpg" },
        }
    };

//    while (true){

//    }
//    RequestManager reqObj;
//    for (auto& local_value : local_vector)
//    {
//        QUrl url = QString::fromStdString(GetValueFromMap(local_value, "ip_cam"));
//        QString alias = QString::fromStdString(GetValueFromMap(local_value, "alias_cam"));
////        m_pdl->download(url, alias);
//        reqObj.GET(url.toString());
//    };

//    Sleep(500);
//    slotGo();

//    m_pdl->download(QUrl(m_ptxt->text()));

    for (auto& local_value : local_vector)
    {
        QUrl url = QString::fromStdString(GetValueFromMap(local_value, "ip_cam"));
        QString alias = QString::fromStdString(GetValueFromMap(local_value, "alias_cam"));
        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        QNetworkReply* reply = manager->get(QNetworkRequest(url));
        QEventLoop loop;
        connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();
        QByteArray data = reply->readAll();
        DownloaderGui::showPic(data, alias);
        reply->deleteLater();
        manager->deleteLater();
    };
    Sleep(500);
    slotGo();



}

void DownloaderGui::slotError()
{
    QMessageBox::critical(0, tr("Error"), tr("An error while download is occured"));
}

void DownloaderGui::slotDownloadProgress(qint64 nReceived, qint64 nTotal)
{
    if (nTotal <= 0) {
        slotError();
        return;
    }
    m_ppb->setValue((100 * nReceived / nTotal));
}

void DownloaderGui::slotDone(const QUrl& url, const QByteArray& ba, const QString& alias)
{
//    cv::imshow("source", cv::imread("C:\\Users\\Bogdan\\Downloads\\pic.jpg", cv::IMREAD_COLOR));
    QPixmap qPixmap;
    QByteArray pData = ba;
    if(qPixmap.loadFromData(pData,"JPG"))
    {
        QImage qImage = qPixmap.toImage();
        cv::Mat mat(qImage.height(), qImage.width(), CV_8UC4, const_cast<uchar*>(qImage.bits()), static_cast<size_t>(qImage.bytesPerLine()));
        cv::resize(mat, mat, cv::Size(), 0.25, 0.25, cv::INTER_LINEAR);
//        cv::imshow(url.path().section("/", -1).toStdString(), mat);
        cv::imshow(alias.toStdString(), mat);
    }

//    slotGo();

    QString strFileName = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation) +
                          "/" + url.path().section("/", -1);
    QFile file(strFileName);
    if (file.open(QIODevice::WriteOnly)) {
        file.write((ba));
        file.close();

        if (strFileName.endsWith(".jpg") || strFileName.endsWith(".png")) {
//            showPic(strFileName);
        }
    }
}

Downloader::Downloader(QObject *pobj) : QObject(pobj)
{
    m_pnam = new QNetworkAccessManager(this);
}

void Downloader::slotAuthentication(QNetworkReply *, QAuthenticator* qauthenticator)
{
    qauthenticator->setUser(QString::fromStdString("admin"));
    qauthenticator->setPassword(QString::fromStdString("q1234567"));
}

void Downloader::download(const QUrl& url, const QString& alias)
{
    QNetworkRequest request(url);
    QNetworkReply* pnr = m_pnam->get(request);
    connect(pnr, SIGNAL(downloadProgress(qint64, qint64)), this, SIGNAL(downloadProgress(qint64, qint64)));
    connect(m_pnam, SIGNAL(authenticationRequired(QNetworkReply*, QAuthenticator*)), this, SLOT(slotAuthentication(QNetworkReply*, QAuthenticator*)));
//    connect(m_pnam, SIGNAL(finished(QNetworkReply*)), this, SLOT(slotFinished(QNetworkReply*)));

    std::cout << alias.toStdString() << std::endl;
    connect(m_pnam, SIGNAL(&pnr::finished), this, SLOT(slotFinished(QNetworkReply*, alias)));
}

void Downloader::slotFinished(QNetworkReply* pnr, const QString alias)
{
    if (pnr->error() != QNetworkReply::NoError) {
        emit error();
    }
    else {
        emit done(pnr->url(), pnr->readAll(), alias);
    }
//    pnr->deleteLater();
}


