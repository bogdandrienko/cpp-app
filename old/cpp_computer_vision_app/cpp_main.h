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



QT_BEGIN_NAMESPACE
namespace Ui { class MainClass; }
QT_END_NAMESPACE

class MainClass : public QMainWindow
{
    Q_OBJECT

public:
    MainClass(QWidget *parent = nullptr);
    ~MainClass();

    void download_from_url();
    static void Thread_download_from_url(std::map <std::string,std::string> AllSettingsMap, std::map <std::string, std::string> OneSettingsMap);
    static void Thread_write_to_file(std::map <std::string,std::string> AllSettingsMap, std::map <std::string, std::string> OneSettingsMap);

private slots:
    void on_START_btn_clicked();

    void authentication_to_access(QNetworkReply *, QAuthenticator *qauthenticator);
    void write_to_file();
    void analyse_from_image();

    void on_STOP_btn_clicked();

    void on_QUIT_btn_clicked();

private:
    Ui::MainClass *ui;

    std::unique_ptr<QFile> openFileForWrite(const QString &fileName);
    std::unique_ptr<QFile> file;

    QNetworkAccessManager qnam;
    QScopedPointer<QNetworkReply, QScopedPointerDeleteLater> qreply;

    std::map <std::string,std::string> AllSettingsMap;
    std::map <std::string, std::string> OneSettingsMap;
    bool Playing;

    QByteArray qbytearray;
};



class DownloaderClass : public QObject
{
    Q_OBJECT

public:
    DownloaderClass(QWidget *parent = nullptr);
    ~DownloaderClass();

private slots:

private:
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