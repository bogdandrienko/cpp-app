#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <iostream>
#include <string>
#include <map>

#include <QMainWindow>
#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QTextEdit>
#include <QProgressDialog>
#include <QUrl>
#include <QString>
#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QTextEdit>
#include <QComboBox>
#include <QSlider>
#include <QObject>
#include <QStringList>
#include <QFile>
#include <QDir>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QApplication>

#include <memory>

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
};



class UtilitesClass{
public:

    static void PrintValueToConsole(std::string Value);

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
