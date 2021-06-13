#ifndef REQUESTMANAGER_H
#define REQUESTMANAGER_H

#include <QtCore>
#include <QtWidgets>
#include <QtNetwork>
#include <QtSql>
#include <QtConcurrent>

#include <QMainWindow>

class RequestManager : public QMainWindow
{
    Q_OBJECT
private:
    QProgressBar* m_ppb;
    QLineEdit* m_ptxt;
    QPushButton* m_pcmd;

public:
    RequestManager(QWidget *parent = nullptr);
    ~RequestManager();
};
#endif // REQUESTMANAGER_H
