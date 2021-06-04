#ifndef MAINUICLASS_H
#define MAINUICLASS_H

#include <QMainWindow>
#include <string>

#include <QObject>
#include <QStringList>
#include <QFile>
#include <QDir>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui { class MainUiClass; }
QT_END_NAMESPACE

class MainUiClass : public QMainWindow
{
    Q_OBJECT

public:
    MainUiClass(QWidget *parent = nullptr);
    ~MainUiClass();
    std::string GetData();

    void startDownload();

private slots:
    void on_START_btn_clicked();

    void on_STOP_btn_clicked();

    void on_QUIT_btn_clicked();


    void downloadFinished();


private:
    Ui::MainUiClass *ui;

    std::unique_ptr<QFile> openFileForWrite(const QString &fileName);
    QUrl url;
    QNetworkAccessManager qnam;
    QScopedPointer<QNetworkReply, QScopedPointerDeleteLater> reply;
    std::unique_ptr<QFile> file;
    bool httpRequestAborted = false;
};

#endif // MAINUICLASS_H
