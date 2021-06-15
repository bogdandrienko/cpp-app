#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QtCore>
#include <QtWidgets>
#include <QtNetwork>
#include <QtSql>
#include <QtConcurrent>

#include <opencv2/opencv.hpp>

#include <memory>
#include <iostream>
#include <string>
#include <map>

class FileDownloader;

QT_BEGIN_NAMESPACE
namespace Ui { class MainClass; }
QT_END_NAMESPACE

class MainClass : public QMainWindow
{
    Q_OBJECT

public:
    MainClass(QWidget *parent = nullptr);
    ~MainClass();

    int counter = 1;

private slots:
    void on_START_btn_clicked();
    void on_STOP_btn_clicked();
    void on_QUIT_btn_clicked();

    void start();

    static double startThread(std::map<std::string,std::string> AllSettingsMap, std::map<std::string,std::string> OneSettingsMap);
    void startSync(std::map<std::string,std::string> AllSettingsMap, std::map<std::string,std::string> OneSettingsMap);

    void loadImage();

private:
    Ui::MainClass *ui;

    bool Playing;

    FileDownloader* m_pImgCtrl;

};



class FileDownloader : public QObject
{
Q_OBJECT
public:
    explicit FileDownloader(std::map<std::string,std::string> OneSettingsMap, QUrl imageUrl, QObject *parent = 0);
    virtual ~FileDownloader();
    QByteArray downloadedData();
    std::map<std::string,std::string> OneSettingsMapData();

signals:
    void downloaded();

private slots:
    void fileDownloaded(QNetworkReply* pReply);

private:
    QNetworkAccessManager m_WebCtrl;
    QByteArray m_DownloadedData;
    std::map<std::string,std::string> OneSettingsMap;
};



class ThreadClass : public QObject
{
    Q_OBJECT

public:
    ThreadClass(QWidget *parent = nullptr);
    ~ThreadClass();

    static double startThread(std::map<std::string,std::string> AllSettingsMap, std::map<std::string,std::string> OneSettingsMap);

private slots:

private:
};



class MultiThreadClass : public QObject
{
Q_OBJECT
public:
    explicit MultiThreadClass(std::map<std::string,std::string> AllSettingsMap, std::map<std::string,std::string> OneSettingsMap, QWidget *parent = nullptr);
    virtual ~MultiThreadClass();

    std::map<std::string,std::string> AllSettings;
    std::map<std::string,std::string> OneSettings;

    static void start(std::map<std::string, std::string> AllSettingsMap,
                      std::vector<std::map<std::string,std::string>> AllSettingsVector);

signals:
//    void finish();

private slots:
    void downloadFinished(QNetworkReply*);

private:
    QNetworkAccessManager manager;
    QNetworkReply* reply;
    QEventLoop* loop;
    QByteArray* data;

};



class UtilitesClass{
public:

    static void PrintValueToConsole(std::string Value);

    static std::vector<std::vector<std::string>> GetValuesFromSQL(std::string sqlQuery = "SELECT * FROM grohot16_now_table;", std::string connectionString = "DRIVER={ODBC Driver 17 for SQL Server};SERVER=tcp:192.168.15.87\\DESKTOP-SM7K050\\COMPUTER_VISION,1433;DATABASE=analiz_16grohot;UID=computer_vision;PWD=vision12345678", QString connectionDriver = "QODBC");

    static void SetValuesToSQL(std::string device_row = "16/1", double value_row = 100.0, bool alarm_row = 1, std::string sqlQuery = "", std::string connectionString = "DRIVER={ODBC Driver 17 for SQL Server};SERVER=tcp:192.168.15.87\\DESKTOP-SM7K050\\COMPUTER_VISION,1433;DATABASE=analiz_16grohot;UID=computer_vision;PWD=vision12345678", QString connectionDriver = "QODBC");

    static std::string GetValueFromMap(std::map <std::string, std::string> Map, std::string Key);

    static std::string GetUrlFromIp(std::map <std::string, std::string> Map, std::string Ip);

    static std::string GetLocalTime();

    static std::string GetConvertedQt_obj(QCheckBox *value);
    static std::string GetConvertedQt_obj(QSpinBox *value);
    static std::string GetConvertedQt_obj(QDoubleSpinBox *value);
    static std::string GetConvertedQt_obj(QTextEdit *value);
    static std::string GetConvertedQt_obj(QComboBox *value);
    static std::string GetConvertedQt_obj(QSlider *value);


private:
};
#endif // MAINCLASS_H
