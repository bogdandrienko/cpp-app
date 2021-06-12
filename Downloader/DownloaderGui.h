#ifndef DOWNLOADERGUI_H
#define DOWNLOADERGUI_H

#include <QtCore>
#include <QtWidgets>
#include <QtNetwork>
#include <QtSql>
#include <QtConcurrent>

class Downloader;
class QProgressBar;
class QLineEdit;
class QPushButton;

class QNetworkAccessManager;
class QNetworkReply;



class DownloaderGui : public QWidget
{

Q_OBJECT

private:
    Downloader* m_pdl;
    QProgressBar* m_ppb;
    QLineEdit* m_ptxt;
    QPushButton* m_pcmd;

    void showPic(const QString&);

public:
    DownloaderGui(QWidget* pwgt = 0);

private slots:
    void slotGo();
    void slotError();
    void slotDownloadProgress(qint64, qint64);
    void slotDone(const QUrl&, const QByteArray&);

};



class Downloader : public QObject
{

Q_OBJECT

private:
    QNetworkAccessManager* m_pnam;

public:
    Downloader(QObject* pobj = 0);

    void download(const QUrl&);

signals:
    void downloadProgress(qint64, qint64);
    void done(const QUrl&, const QByteArray&);
    void error();

private slots:
    void slotFinished(QNetworkReply*);

};

#endif // DOWNLOADERGUI_H
