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
    std::string url_v = "http://via.placeholder.com/1000.jpg";
};

#endif // MAINUICLASS_H
