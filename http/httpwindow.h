#ifndef HTTPWINDOW_H
#define HTTPWINDOW_H

#include <QtWidgets>
#include <QtNetwork>

class HttpWindow : public QObject
{
    Q_OBJECT

public:
    explicit HttpWindow(QWidget *parent = nullptr);
    ~HttpWindow();

    void startRequest();

private slots:
    void httpFinished();

private:
    QUrl url;
    QNetworkAccessManager qnam;
    QScopedPointer<QNetworkReply, QScopedPointerDeleteLater> reply;
};

#endif
