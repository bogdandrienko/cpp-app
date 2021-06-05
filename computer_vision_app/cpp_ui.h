#ifndef MAINUICLASS_H
#define MAINUICLASS_H

#include <QMainWindow>
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

#include <QProgressDialog>
#include <QUrl>
#include <QString>
#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QTextEdit>

#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainUiClass; }
QT_END_NAMESPACE

class MainUiClass : public QMainWindow
{
    Q_OBJECT

public:
    MainUiClass(QWidget *parent = nullptr);
    ~MainUiClass();

    void download_from_url();

private slots:
    void on_START_btn_clicked();

    void authentication_to_access(QNetworkReply *, QAuthenticator *authenticator);
    void write_to_file();
    void analyse_from_image();

private:
    Ui::MainUiClass *ui;

    std::unique_ptr<QFile> openFileForWrite(const QString &fileName);
    std::map <std::string,std::string> SettingsMap;
    QUrl url;
    QNetworkAccessManager qnam;
    QScopedPointer<QNetworkReply, QScopedPointerDeleteLater> reply;
    std::unique_ptr<QFile> file;
    bool httpRequestAborted = false;
//    std::string url_v = "http://via.placeholder.com/1000.jpg";
    std::string url_v = "http://2.bp.blogspot.com/-G_BQbLpOKtM/VL0FG0zSmkI/AAAAAAAAw-g/g3JZMK0yGCA/w620/1%2B%D0%BA%D1%80%D0%B0%D1%81%D0%B8%D0%B2%D1%8B%D0%B5%2B%D1%84%D0%BE%D1%82%D0%BE.jpg";
//    std::string url_v = "http://192.168.15.203:80/ISAPI/Streaming/channels/101/picture?snapShotImageType=JPEG";
//    std::string url_v = "http:admin:q1234567@//192.168.15.203:80/ISAPI/Streaming/channels/101/picture?snapShotImageType=JPEG";
//    "http://admin:q1234567@192.168.15.203:80/ISAPI/Streaming/channels/101/picture?snapShotImageType=JPEG"
//    "http:/192.168.15.203:80/ISAPI/Streaming/channels/101/picture"
//    "http://admin:q1234567@192.168.15.203:80/ISAPI/Streaming/channels/101/picture?snapShotImageType=JPEG"
};


class CustomConvertQtClass{
public:

    static std::string QCheckBox(QCheckBox *value){
        if (value->isChecked() == 1) {
            return "True";
        }
        return "False";
    };

    static std::string QSpinBox(QSpinBox *value)
    {
        return std::to_string(value->value());
    };

    static std::string QDoubleSpinBox(QDoubleSpinBox *value)
    {
        return std::to_string(value->value());
    };

    static std::string QTextEdit(QTextEdit *value)
    {
        return value->toPlainText().toStdString();
    };

private:
};

#endif // MAINUICLASS_H
