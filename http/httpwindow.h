#ifndef HTTPWINDOW_H
#define HTTPWINDOW_H

#include <QProgressDialog>
#include <QNetworkAccessManager>
#include <QUrl>

#include <memory>

QT_BEGIN_NAMESPACE
class QFile;
class QLabel;
class QLineEdit;
class QPushButton;
class QSslError;
class QAuthenticator;
class QNetworkReply;
class QCheckBox;

QT_END_NAMESPACE

class HttpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HttpWindow(QWidget *parent = nullptr);
    ~HttpWindow();
    void download_from_url();

private slots:
    void authentication_to_access(QNetworkReply *, QAuthenticator *authenticator);
    void write_to_file();
    void analyse_from_image();

private:
    QPushButton *downloadButton;

    std::unique_ptr<QFile> openFileForWrite(const QString &fileName);
    QUrl url;
    QNetworkAccessManager qnam;
    QScopedPointer<QNetworkReply, QScopedPointerDeleteLater> reply;
    std::unique_ptr<QFile> file;
    bool httpRequestAborted = false;

    //    std::string url_v = "http://via.placeholder.com/1000.jpg";
    std::string url_v = "http://192.168.15.203:80/ISAPI/Streaming/channels/101/picture?snapShotImageType=JPEG";
    std::string path_source_v = "C:\\Images\\1.jpg";
    std::string path_mask_v = "C:\\Images\\2.jpg";

};

#endif
