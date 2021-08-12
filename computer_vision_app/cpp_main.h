#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QtCore>
#include <QtWidgets>
#include <QtGui>
#include <QtNetwork>
#include <QtSql>
#include <QtConcurrent>

#include "ui_cpp_main.h"

#include <opencv2/opencv.hpp>

#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include <map>



QT_BEGIN_NAMESPACE
namespace Ui { class MainClass; }
QT_END_NAMESPACE

class UiWidgetClass : public QMainWindow
{
    Q_OBJECT

public:
    UiWidgetClass(QWidget *parent = nullptr);
    ~UiWidgetClass();

private slots:
    void on_Login_Login_pushButton_clicked();
    void on_Logout_Login_pushButton_clicked();

    void on_START_CV_16_btn_clicked();
    void on_STOP_CV_16_btn_clicked();
    void on_TRAY_CV_16_btn_clicked();
    void on_CamShot_CV_16_DEBUG_pushButton_clicked();
    void on_ExportSettings_CV_16_DEBUG_pushButton_clicked();
    void on_ImportSettings_CV_16_DEBUG_pushButton_clicked();

    void on_CV_16_1_Resources_Path_Unlock_pushButton_clicked();

    void on_START_Video_CV_btn_clicked();
    void on_STOP_Video_CV_btn_clicked();
    void on_TRAY_Video_CV_btn_clicked();
    void on_UnlockResourcesPath_CV_Video_pushButton_clicked();

    void Tray();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void AutoLogin();
    void SaveOrDeleteAutoLogin(bool save);
    void AutoImport();
    void AutoPlay();

    void startAnalyse(std::map<std::string, std::string> AllSettingsMap,
                      std::vector<std::map<std::string,std::string>> AllSettingsVector,
                      Ui::MainClass *ui);
    std::pair<std::map<std::string,std::string>, std::vector<std::map<std::string,std::string>>> GetMapsFromSettings();

    void start_video_analiz();
    void filter_video(std::map<std::string, std::string> AllSettingsMap, std::map<std::string, std::string> OneSettingsMap, cv::VideoCapture cap);
    std::pair<std::map<std::string,std::string>, std::vector<std::map<std::string,std::string>>> GetMapsFrom_CV_Video_Settings();



private:
    Ui::MainClass *ui;
    bool Playing;
    QSystemTrayIcon *trayIcon;

protected:
    void closeEvent(QCloseEvent *event);
};

class SyncThreadClass : public QObject
{
    Q_OBJECT

public:
    explicit SyncThreadClass(std::map<std::string, std::string> AllSettingsMap,
                             std::map<std::string,std::string> OneSettingsMap,
                             Ui::MainClass *ui,
                             QWidget *parent = nullptr);
    virtual ~SyncThreadClass();

signals:

private slots:

private:
    std::map<std::string,std::string> AllSettings;
    std::map<std::string,std::string> OneSettings;
    Ui::MainClass *Gui;
};

class AsyncThreadClass : public QObject
{
    Q_OBJECT

public:
    explicit AsyncThreadClass(std::map<std::string,std::string> AllSettingsMap, std::map<std::string,std::string> OneSettingsMap, Ui::MainClass *, QWidget *parent = nullptr);
    virtual ~AsyncThreadClass();

private slots:
    void finishDownload();

private:
    std::map<std::string,std::string> AllSettings;
    std::map<std::string,std::string> OneSettings;
    Ui::MainClass *Gui;

    QNetworkAccessManager manager;
    QScopedPointer<QNetworkReply, QScopedPointerDeleteLater> reply;
};

class ComputerVisionClass{
public:

    static void RenderCvImage(cv::Mat Image, double renderSize, std::string name);

private:
};

class SQLClass{
public:

    static std::vector<std::vector<std::string>> GetValuesFromSQL(std::string sqlQuery = "SELECT * FROM grohot16_now_table;", std::string connectionString = "DRIVER={ODBC Driver 17 for SQL Server};SERVER=tcp:192.168.15.87\\DESKTOP-SM7K050\\COMPUTER_VISION,1433;DATABASE=analiz_16grohot;UID=computer_vision;PWD=vision12345678", QString connectionDriver = "QODBC");

    static void UpdateValuesToSQL(std::string device_row, double value_row, bool alarm_row, std::map<std::string, std::string> AllSettingsMap, QString connectionDriver = "QODBC");

    static void InsertValuesToSQL(std::string device_row, double value_row, bool alarm_row, std::map<std::string, std::string> AllSettingsMap, QString connectionDriver = "QODBC");

    static std::string GetValueFromMap(std::map <std::string, std::string> Map, std::string Key);

private:
};

class UtilitesClass{
public:

    static std::string GetValueFromMap(std::map <std::string, std::string> Map, std::string Key);

    static std::string GetUrlFromIp(std::map <std::string, std::string> Map, std::string Ip);

    static void PrintValueToConsole(std::string Value);

    static void WriteResultToTextFile(std::string Result);

    static void WriteTextErrorToLogFile(std::string Text);

    static std::string GetLocalTime();

    static std::string GetConvertedQt_obj(QCheckBox *value);
    static std::string GetConvertedQt_obj(QSpinBox *value);
    static std::string GetConvertedQt_obj(QDoubleSpinBox *value);
    static std::string GetConvertedQt_obj(QLineEdit *value);
    static std::string GetConvertedQt_obj(QTextEdit *value);
    static std::string GetConvertedQt_obj(QComboBox *value);
    static std::string GetConvertedQt_obj(QSlider *value);

    static void SetConvertedQt_obj(QCheckBox *value, QString text);
    static void SetConvertedQt_obj(QSpinBox *value, QString text);
    static void SetConvertedQt_obj(QDoubleSpinBox *value, QString text);
    static void SetConvertedQt_obj(QLineEdit *value, QString text);
    static void SetConvertedQt_obj(QTextEdit *value, QString text);
    static void SetConvertedQt_obj(QComboBox *value, QString text);
    static void SetConvertedQt_obj(QSlider *value, QString text);
private:
};

#endif // MAINCLASS_H
