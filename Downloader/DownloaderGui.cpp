#include "DownloaderGui.h"

#include <QtCore>
#include <QtWidgets>
#include <QtNetwork>
#include <QtSql>
#include <QtConcurrent>

#include <opencv2/opencv.hpp>

//DownloaderGui::DownloaderGui(QWidget *parent)
//    : QMainWindow(parent)
//{
//}

//DownloaderGui::~DownloaderGui()
//{
//}

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

DownloaderGui::DownloaderGui(QWidget* pwgt) : QWidget(pwgt)
{
    m_pdl = new Downloader(this);
    m_ppb = new QProgressBar;
    m_ptxt = new QLineEdit;
    m_pcmd = new QPushButton(tr("&Go"));


    QString strDownloadLink = "http://qt-book.com/pic.jpg";
    m_ptxt->setText(strDownloadLink);

    connect(m_pcmd, SIGNAL(clicked()), SLOT(slotGo()));
    connect(m_pdl, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(slotDownloadProgress(qint64, qint64)));
    connect(m_pdl, SIGNAL(done(const QUrl&, const QByteArray&)), this, SLOT(slotDone(const QUrl&, const QByteArray&)));

    QGridLayout* pLayout = new QGridLayout;
    pLayout->addWidget(m_ptxt, 0, 0);
    pLayout->addWidget(m_pcmd, 0, 1);
    pLayout->addWidget(m_ppb, 1, 0, 1, 1);
    setLayout(pLayout);
}

void DownloaderGui::slotGo()
{
    m_pdl->download(QUrl(m_ptxt->text()));
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

void DownloaderGui::slotDone(const QUrl& url, const QByteArray& ba)
{
//    cv::imshow("source", cv::imread("C:\\Users\\Bogdan\\Downloads\\pic.jpg", cv::IMREAD_COLOR));
    QPixmap qPixmap;
    QByteArray pData = ba;
    if(qPixmap.loadFromData(pData,"JPG"))
    {
        QImage qImage = qPixmap.toImage();
        cv::Mat mat(qImage.height(), qImage.width(), CV_8UC4, const_cast<uchar*>(qImage.bits()), static_cast<size_t>(qImage.bytesPerLine()));
        cv::imshow("render", mat);
    }

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
    connect(m_pnam, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(slotFinished(QNetworkReply*))
            );
}

void Downloader::download(const QUrl& url)
{
    QNetworkRequest request(url);
    QNetworkReply* pnr = m_pnam->get(request);
    connect(pnr, SIGNAL(downloadProgress(qint64, qint64)), this, SIGNAL(downloadProgress(qint64, qint64)));
}

void Downloader::slotFinished(QNetworkReply* pnr)
{
    if (pnr->error() != QNetworkReply::NoError) {
        emit error();
    }
    else {
        emit done(pnr->url(), pnr->readAll());
    }
    pnr->deleteLater();
}
