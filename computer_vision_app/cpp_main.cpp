#include "cpp_main.h"
#include "ui_cpp_main.h"

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



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainClass w;
    w.show();
    return a.exec();
}

MainClass::MainClass(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainClass)
{
    ui->setupUi(this);

    AutoImport();
    AutoPlay();
}

MainClass::~MainClass()
{
    delete ui;
}

void MainClass::AutoImport()
{

}

void MainClass::AutoPlay()
{
    if (UtilitesClass::GetConvertedQt_obj(ui->AutoPlay_checkBox) == "true") {
        Sleep(1000);
        on_START_btn_clicked();
    }
}

void MainClass::on_START_btn_clicked()
{
    on_STOP_btn_clicked();
    Playing = true;
    ui->Playing_radioButton->setChecked(Playing);
    while (Playing) {
        try {
                QCoreApplication::processEvents();
                std::map <std::string,std::string> AllSettingsMap = {
                    { "AutoPlay", UtilitesClass::GetConvertedQt_obj(ui->AutoPlay_checkBox) },
                    { "AutoImport", UtilitesClass::GetConvertedQt_obj(ui->AutoImport_checkBox) },
                    { "WriteToWidget", UtilitesClass::GetConvertedQt_obj(ui->WriteToWidget_checkBox) },
                    { "WriteToText", UtilitesClass::GetConvertedQt_obj(ui->WriteToText_checkBox) },
                    { "RenderSize", UtilitesClass::GetConvertedQt_obj(ui->RenderSize_horizontalSlider) },
                    { "RenderType", UtilitesClass::GetConvertedQt_obj(ui->RenderType_comboBox) },
                    { "TimeDelay", UtilitesClass::GetConvertedQt_obj(ui->TimeDelay_doubleSpinBox) },

                    { "ProtocolCam", UtilitesClass::GetConvertedQt_obj(ui->ProtocolCam_textEdit) },
                    { "PortCam", UtilitesClass::GetConvertedQt_obj(ui->PortCam_spinBox) },
                    { "LoginCam", UtilitesClass::GetConvertedQt_obj(ui->LoginCam_textEdit) },
                    { "PasswordCam", UtilitesClass::GetConvertedQt_obj(ui->PasswordCam_textEdit) },
                };
                QCoreApplication::processEvents();
                std::vector<std::map<std::string,std::string>> AllSettingsVector =
                {
                    {
                        { "AliasCam", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_textEdit_1) },
                        { "IpCam", UtilitesClass::GetConvertedQt_obj(ui->IpCam_textEdit_1) },
                        { "MaskCam", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_textEdit_1) },
                        { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_spinBox_1) },
                        { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_doubleSpinBox_1) },
                        { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_spinBox_1) },
                        { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_spinBox_1) },
                        { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_spinBox_1) },
                        { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_spinBox_1) },
                        { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_spinBox_1) },
                        { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_spinBox_1) },
                        { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_spinBox_1) },
                        { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_spinBox_1) },
                        { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_spinBox_1) },
                    },
                    {
                        { "AliasCam", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_textEdit_2) },
                        { "IpCam", UtilitesClass::GetConvertedQt_obj(ui->IpCam_textEdit_2) },
                        { "MaskCam", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_textEdit_2) },
                        { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_spinBox_2) },
                        { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_doubleSpinBox_2) },
                        { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_spinBox_2) },
                        { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_spinBox_2) },
                        { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_spinBox_2) },
                        { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_spinBox_2) },
                        { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_spinBox_2) },
                        { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_spinBox_2) },
                        { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_spinBox_2) },
                        { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_spinBox_2) },
                        { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_spinBox_2) },
                    },
                    {
                        { "AliasCam", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_textEdit_3) },
                        { "IpCam", UtilitesClass::GetConvertedQt_obj(ui->IpCam_textEdit_3) },
                        { "MaskCam", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_textEdit_3) },
                        { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_spinBox_3) },
                        { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_doubleSpinBox_3) },
                        { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_spinBox_3) },
                        { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_spinBox_3) },
                        { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_spinBox_3) },
                        { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_spinBox_3) },
                        { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_spinBox_3) },
                        { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_spinBox_3) },
                        { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_spinBox_3) },
                        { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_spinBox_3) },
                        { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_spinBox_3) },
                    },
                    {
                        { "AliasCam", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_textEdit_4) },
                        { "IpCam", UtilitesClass::GetConvertedQt_obj(ui->IpCam_textEdit_4) },
                        { "MaskCam", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_textEdit_4) },
                        { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_spinBox_4) },
                        { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_doubleSpinBox_4) },
                        { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_spinBox_4) },
                        { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_spinBox_4) },
                        { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_spinBox_4) },
                        { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_spinBox_4) },
                        { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_spinBox_4) },
                        { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_spinBox_4) },
                        { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_spinBox_4) },
                        { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_spinBox_4) },
                        { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_spinBox_4) },
                    },
                    {
                        { "AliasCam", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_textEdit_5) },
                        { "IpCam", UtilitesClass::GetConvertedQt_obj(ui->IpCam_textEdit_5) },
                        { "MaskCam", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_textEdit_5) },
                        { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_spinBox_5) },
                        { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_doubleSpinBox_5) },
                        { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_spinBox_5) },
                        { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_spinBox_5) },
                        { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_spinBox_5) },
                        { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_spinBox_5) },
                        { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_spinBox_5) },
                        { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_spinBox_5) },
                        { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_spinBox_5) },
                        { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_spinBox_5) },
                        { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_spinBox_5) },
                    },
                    {
                        { "AliasCam", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_textEdit_6) },
                        { "IpCam", UtilitesClass::GetConvertedQt_obj(ui->IpCam_textEdit_6) },
                        { "MaskCam", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_textEdit_6) },
                        { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_spinBox_6) },
                        { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_doubleSpinBox_6) },
                        { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_spinBox_6) },
                        { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_spinBox_6) },
                        { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_spinBox_6) },
                        { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_spinBox_6) },
                        { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_spinBox_6) },
                        { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_spinBox_6) },
                        { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_spinBox_6) },
                        { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_spinBox_6) },
                        { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_spinBox_6) },
                    },
                    {
                        { "AliasCam", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_textEdit_7) },
                        { "IpCam", UtilitesClass::GetConvertedQt_obj(ui->IpCam_textEdit_7) },
                        { "MaskCam", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_textEdit_7) },
                        { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_spinBox_7) },
                        { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_doubleSpinBox_7) },
                        { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_spinBox_7) },
                        { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_spinBox_7) },
                        { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_spinBox_7) },
                        { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_spinBox_7) },
                        { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_spinBox_7) },
                        { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_spinBox_7) },
                        { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_spinBox_7) },
                        { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_spinBox_7) },
                        { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_spinBox_7) },
                    },
                    {
                        { "AliasCam", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_textEdit_8) },
                        { "IpCam", UtilitesClass::GetConvertedQt_obj(ui->IpCam_textEdit_8) },
                        { "MaskCam", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_textEdit_8) },
                        { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_spinBox_8) },
                        { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_doubleSpinBox_8) },
                        { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_spinBox_8) },
                        { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_spinBox_8) },
                        { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_spinBox_8) },
                        { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_spinBox_8) },
                        { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_spinBox_8) },
                        { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_spinBox_8) },
                        { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_spinBox_8) },
                        { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_spinBox_8) },
                        { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_spinBox_8) },
                    },
                    {
                        { "AliasCam", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_textEdit_9) },
                        { "IpCam", UtilitesClass::GetConvertedQt_obj(ui->IpCam_textEdit_9) },
                        { "MaskCam", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_textEdit_9) },
                        { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_spinBox_9) },
                        { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_doubleSpinBox_9) },
                        { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_spinBox_9) },
                        { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_spinBox_9) },
                        { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_spinBox_9) },
                        { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_spinBox_9) },
                        { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_spinBox_9) },
                        { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_spinBox_9) },
                        { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_spinBox_9) },
                        { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_spinBox_9) },
                        { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_spinBox_9) },
                    },
                    {
                        { "AliasCam", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_textEdit_10) },
                        { "IpCam", UtilitesClass::GetConvertedQt_obj(ui->IpCam_textEdit_10) },
                        { "MaskCam", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_textEdit_10) },
                        { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_spinBox_10) },
                        { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_doubleSpinBox_10) },
                        { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_spinBox_10) },
                        { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_spinBox_10) },
                        { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_spinBox_10) },
                        { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_spinBox_10) },
                        { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_spinBox_10) },
                        { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_spinBox_10) },
                        { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_spinBox_10) },
                        { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_spinBox_10) },
                        { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_spinBox_10) },
                    },
                };
            QCoreApplication::processEvents();
            if (Playing){
                QCoreApplication::processEvents();
                MultiThreadClass::start(AllSettingsMap, AllSettingsVector, *ui);
                QCoreApplication::processEvents();
            }
            QCoreApplication::processEvents();
            Sleep(int (std::stod(UtilitesClass::GetValueFromMap(AllSettingsMap, "TimeDelay"))*1000));
            QCoreApplication::processEvents();
        }  catch (std::string error) {
            UtilitesClass::PrintValueToConsole(error);
        }
    }
}

void MainClass::on_STOP_btn_clicked()
{
    Playing = false;
    cv::destroyAllWindows();
    ui->Playing_radioButton->setChecked(Playing);
}

void MainClass::on_QUIT_btn_clicked()
{
    on_STOP_btn_clicked();
    this->close();
}

void MainClass::on_CamShot_pushButton_clicked()
{
    std::map <std::string,std::string> CamShotSettingsMap = {
        { "IpCamShot", UtilitesClass::GetConvertedQt_obj(ui->IpCamShot_textEdit) },
        { "PortCamShot", UtilitesClass::GetConvertedQt_obj(ui->PortCamShot_textEdit) },
        { "LoginCamShot", UtilitesClass::GetConvertedQt_obj(ui->LoginCamShot_textEdit) },
        { "PasswordCamShot", UtilitesClass::GetConvertedQt_obj(ui->PasswordCamShot_textEdit) },
        { "ImageNameShot", UtilitesClass::GetConvertedQt_obj(ui->ImageNameShot_textEdit) },
    };
    QUrl url = QString::fromStdString("http://192.168." +
                                      UtilitesClass::GetValueFromMap(CamShotSettingsMap, "IpCamShot") + ":" +
                                      UtilitesClass::GetValueFromMap(CamShotSettingsMap, "PortCamShot") +
                                      "/ISAPI/Streaming/channels/101/picture?snapShotImageType=JPEG");
    url.setUserName(QString::fromStdString(UtilitesClass::GetValueFromMap(CamShotSettingsMap, "LoginCamShot")));
    url.setPassword(QString::fromStdString(UtilitesClass::GetValueFromMap(CamShotSettingsMap, "PasswordCamShot")));
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply* reply = manager->get(QNetworkRequest(url));
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    emit QByteArray data = reply->readAll();
    cv::Mat image_source;
    QPixmap qPixmap;
    if (qPixmap.loadFromData(data, "JPG")) {
        QImage qImage = qPixmap.toImage();
        image_source = cv::Mat(qImage.height(), qImage.width(), CV_8UC4, const_cast<uchar*>(qImage.bits()), static_cast<size_t>(qImage.bytesPerLine()));
        cv::imwrite(UtilitesClass::GetValueFromMap(CamShotSettingsMap, "ImageNameShot"), image_source);
    }
    reply->deleteLater();
    manager->deleteLater();

}

MultiThreadClass::MultiThreadClass(std::map<std::string, std::string> AllSettingsMap,
                                   std::map<std::string,std::string> OneSettingsMap, Ui::MainClass ui,
                                   QWidget *parent) : QObject(parent)
{
//    UtilitesClass::PrintValueToConsole("object created");

    try {
        AllSettings = AllSettingsMap;
        OneSettings = OneSettingsMap;
        Gui = &ui;
        connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finish(QNetworkReply*)));
        QUrl url = QString::fromStdString(UtilitesClass::GetUrlFromIp(AllSettingsMap, UtilitesClass::GetValueFromMap(OneSettingsMap, "IpCam")));
        url.setUserName(QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettingsMap, "LoginCam")));
        url.setPassword(QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettingsMap, "PasswordCam")));
        QNetworkRequest request(url);
        manager.get(request);
    }  catch (std::string error) {
        UtilitesClass::PrintValueToConsole(error);
    }
}

MultiThreadClass::~MultiThreadClass()
{

}

void MultiThreadClass::start(std::map<std::string, std::string> AllSettingsMap,
                             std::vector<std::map<std::string,std::string>> AllSettingsVector,
                             Ui::MainClass ui)
{
//    UtilitesClass::PrintValueToConsole("MultiThreadClass started");

    for (auto& OneSettingsMap : AllSettingsVector)
    {
        try {
            MultiThreadClass* obj = new MultiThreadClass(AllSettingsMap, OneSettingsMap, ui);
            obj->deleteLater();
        }  catch (std::string error) {
            UtilitesClass::PrintValueToConsole(error);
        }
    }
}

double MultiThreadClass::getResult()
{
    return result;
}

void MultiThreadClass::finish(QNetworkReply *reply)
{
//    UtilitesClass::PrintValueToConsole("Download finished");

    try {
        QByteArray data = reply->readAll();
        cv::Mat image_source;
        QPixmap qPixmap;
        if (qPixmap.loadFromData(data, "JPG")) {
            QImage qImage = qPixmap.toImage();
            image_source = cv::Mat(qImage.height(), qImage.width(), CV_8UC4, const_cast<uchar*>(qImage.bits()), static_cast<size_t>(qImage.bytesPerLine()));
            cv::Mat mask = cv::imread(UtilitesClass::GetValueFromMap(OneSettings, "MaskCam"), 0);
            cv::Mat bitwise_and;
            cv::bitwise_and(image_source, image_source, bitwise_and, mask);
            cv::Mat cvtcolor;
            cv::cvtColor(bitwise_and, cvtcolor, cv::COLOR_BGR2HSV);
            cv::Mat final;
            cv::inRange(cvtcolor, cv::Scalar(std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "Point_1_1")),
                                             std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "Point_1_2")),
                                             std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "Point_1_3"))),
                        cv::Scalar(std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "Point_2_1")),
                                   std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "Point_2_2")),
                                   std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "Point_2_3"))), final);
            final.setTo(std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "InRangeSetTo")), final >= std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "InRangeSetFrom")));
            result = double(cv::countNonZero(final > std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "CountNotZero")))) / double(cv::countNonZero(mask)) * 100 * std::stod(UtilitesClass::GetValueFromMap(OneSettings, "CorrectCoefficient"));
            if (result > 100)
            {
                result = 100.0;
            }
            else if(result < 0)
            {
                result = 0.0;
            }
            else
            {
                float pow_10 = pow(10.0f, (float)2);
                result = round(result * pow_10) / pow_10;
            }
            if (result > std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "AlarmLevel"))){
                UtilitesClass::SetValuesToSQL(UtilitesClass::GetValueFromMap(OneSettings, "AliasCam").substr(0,2) + "/" + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam").substr(3), result, 1);
            } else {
                UtilitesClass::SetValuesToSQL(UtilitesClass::GetValueFromMap(OneSettings, "AliasCam").substr(0,2) + "/" + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam").substr(3), result, 0);
            }

            if (UtilitesClass::GetValueFromMap(AllSettings, "RenderType") == "none") {
            } else if (UtilitesClass::GetValueFromMap(AllSettings, "RenderType") ==  "source") {
                UtilitesClass::RenderCvImage(image_source, std::stoi(UtilitesClass::GetValueFromMap(AllSettings, "RenderSize")) / 80.0, "source " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"));
            } else if (UtilitesClass::GetValueFromMap(AllSettings, "RenderType") == "final") {
                cv::putText(final, UtilitesClass::GetLocalTime(), cv::Point(150, 50), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
                cv::putText(final, UtilitesClass::GetValueFromMap(OneSettings, "IpCam") + " | " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"), cv::Point(150, 100), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
                if (result > std::stoi((UtilitesClass::GetValueFromMap(OneSettings, "AlarmLevel")))) {
                    cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(255, 255, 255), 2);
                }
                else {
                    cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(128, 128, 128), 1);
                }
                UtilitesClass::RenderCvImage(final, std::stoi(UtilitesClass::GetValueFromMap(AllSettings, "RenderSize")) / 80.0, "final" + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"));
            } else if (UtilitesClass::GetValueFromMap(AllSettings, "RenderType") == "extended") {
                UtilitesClass::RenderCvImage(image_source, std::stoi(UtilitesClass::GetValueFromMap(AllSettings, "RenderSize")) / 80.0, "source " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"));
                cv::putText(final, UtilitesClass::GetLocalTime(), cv::Point(150, 50), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
                cv::putText(final, UtilitesClass::GetValueFromMap(OneSettings, "IpCam") + " | " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"), cv::Point(150, 100), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
                if (result > std::stoi((UtilitesClass::GetValueFromMap(OneSettings, "AlarmLevel")))) {
                    cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(255, 255, 255), 2);
                }
                else {
                    cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(128, 128, 128), 1);
                }
                UtilitesClass::RenderCvImage(final, std::stoi(UtilitesClass::GetValueFromMap(AllSettings, "RenderSize")) / 80.0, "final" + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"));
            } else if (UtilitesClass::GetValueFromMap(AllSettings, "RenderType") == "all") {
                UtilitesClass::RenderCvImage(image_source, std::stoi(UtilitesClass::GetValueFromMap(AllSettings, "RenderSize")) / 80.0, "source " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"));
                UtilitesClass::RenderCvImage(mask, std::stoi(UtilitesClass::GetValueFromMap(AllSettings, "RenderSize")) / 80.0, "mask " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"));
                cv::putText(final, UtilitesClass::GetLocalTime(), cv::Point(150, 50), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
                cv::putText(final, UtilitesClass::GetValueFromMap(OneSettings, "IpCam") + " | " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"), cv::Point(150, 100), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
                if (result > std::stoi((UtilitesClass::GetValueFromMap(OneSettings, "AlarmLevel")))) {
                    cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(255, 255, 255), 2);
                }
                else {
                    cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(128, 128, 128), 1);
                }
                UtilitesClass::RenderCvImage(final, std::stoi(UtilitesClass::GetValueFromMap(AllSettings, "RenderSize")) / 80.0, "final" + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"));
            }
            if (UtilitesClass::GetValueFromMap(AllSettings, "WriteToWidget") == "true") {
                Gui->Time_label->setText(QString::fromStdString(UtilitesClass::GetLocalTime()));
                Gui->Info_label->setText(QString::fromStdString(UtilitesClass::GetValueFromMap(OneSettings, "IpCam") + " | " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam")));
                Gui->Result_progressBar->setValue(result);
                Gui->LcdNumber->display(result);
                if (result > std::stoi((UtilitesClass::GetValueFromMap(OneSettings, "AlarmLevel")))) {
                    QString danger = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #FF0350,stop: 0.4999 #FF0020,stop: 0.5 #FF0019,stop: 1 #FF0000 );border-bottom-right-radius: 5px;border-bottom-left-radius: 5px;border: .px solid black;}";
                    Gui->Result_progressBar->setStyleSheet(danger);
                }
                else {
                    QString safe= "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #78d,stop: 0.4999 #46a,stop: 0.5 #45a,stop: 1 #238 );border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;border: 1px solid black;}";
                    Gui->Result_progressBar->setStyleSheet(safe);
                }
            }
            if (UtilitesClass::GetValueFromMap(AllSettings, "WriteToText") == "true") {
                UtilitesClass::PrintValueToConsole("RESULT " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam") + " IS : " + std::to_string(result) + "%" + " | " + UtilitesClass::GetLocalTime());
            }
        }
    }  catch (std::string error) {
        UtilitesClass::PrintValueToConsole(error);
    }

}

void UtilitesClass::PrintValueToConsole(std::string Value)
{
    std::cout << Value << std::endl;
};

void UtilitesClass::RenderCvImage(cv::Mat Image, double RenderSize, std::string name)
{
    cv::Mat source = Image.clone();
    cv::resize(source, source, cv::Size(), RenderSize, RenderSize, cv::INTER_LINEAR);
    cv::namedWindow(name, cv::WINDOW_AUTOSIZE);
    cv::imshow(name, source);
    cv::waitKey(1);
};


std::vector<std::vector<std::string>> UtilitesClass::GetValuesFromSQL(std::string sqlQuery, std::string connectionString, QString connectionDriver)
{
    QSqlDatabase qdb = QSqlDatabase::addDatabase(connectionDriver);
    qdb.setDatabaseName(QString::fromStdString(connectionString));
    if (qdb.open()) {
        UtilitesClass::PrintValueToConsole("good to open sql");
        QSqlQuery query(qdb);
        query.exec(QString::fromStdString(sqlQuery));
        std::vector<std::vector<std::string>> global_vector;
        int rows_count = 0;
        while(query.next())
        {
            std::vector<std::string> local_vector;
            std::string local_request;
            if (query.at() == 0){
                while (true) {
                    if (query.value(rows_count).isNull()){
                        UtilitesClass::PrintValueToConsole("rows_count succefull finded");
                        break;
                    } else {
                        rows_count++;
                    }
                }
            }
            for (int i=0;i<rows_count;i++) {
                local_vector.push_back(query.value(i).toString().toStdString());
            }
            global_vector.push_back(local_vector);
        }
        qdb.close();
        return global_vector;
    } else {
        UtilitesClass::PrintValueToConsole("error to open sql");
        std::vector<std::vector<std::string>> global_vector = {};
        return global_vector;
    }
}

void UtilitesClass::SetValuesToSQL(std::string device_row, double value_row, bool alarm_row, std::string sqlQuery, std::string connectionString, QString connectionDriver)
{
    QSqlDatabase qdb = QSqlDatabase::addDatabase(connectionDriver);
    qdb.setDatabaseName(QString::fromStdString(connectionString));
    if (qdb.open()) {
//        UtilitesClass::PrintValueToConsole("good to open sql");
        QSqlQuery query(qdb);
        query.prepare("UPDATE grohot16_now_table "
                      "SET value_row = :value, alarm_row = :alarm, datetime_row =  GETDATE() "
                      "WHERE device_row = :device");
        query.bindValue(":value", value_row);
        query.bindValue(":alarm", alarm_row);
        query.bindValue(":device", QString::fromStdString(device_row));

        query.exec();
        qdb.close();
    } else {
        UtilitesClass::PrintValueToConsole("error to open sql");
    }
}

std::string UtilitesClass::GetValueFromMap(std::map <std::string, std::string> Map, std::string Key)
{
    std::string value = "";
    for (auto& map_elem : Map)
        if(map_elem.first == Key){
            value = map_elem.second;
        }
    return value;
};

std::string UtilitesClass::GetUrlFromIp(std::map <std::string, std::string> Map, std::string Ip)
{
    std::string url = "";
    if (UtilitesClass::GetValueFromMap(Map, "ProtocolCam") == "http") {
//        "http://192.168.15.203:80/ISAPI/Streaming/channels/101/picture?snapShotImageType=JPEG";
        url = UtilitesClass::GetValueFromMap(Map, "ProtocolCam") + "://192.168." + Ip + ":" +
                UtilitesClass::GetValueFromMap(Map, "PortCam") + "/ISAPI/Streaming/channels/101/picture?snapShotImageType=JPEG";
    }
    if (UtilitesClass::GetValueFromMap(Map, "ProtocolCam") == "rtsp") {
//        "rtsp://admin:q1234567@192.168.15.203:554";
        url = UtilitesClass::GetValueFromMap(Map, "ProtocolCam") + "://" + UtilitesClass::GetValueFromMap(Map, "LoginCam") + ":" +
                UtilitesClass::GetValueFromMap(Map, "PasswordCam") + "@" + "192.168." + Ip + ":" + UtilitesClass::GetValueFromMap(Map, "PortCam");
    }
    if (UtilitesClass::GetValueFromMap(Map, "ProtocolCam") == "test") {
        url = "http://via.placeholder.com/1000.jpg";
    }
    return url;
};

std::string UtilitesClass::GetLocalTime(){
    QDateTime time;
    return time.currentDateTime().toString().toStdString();
};

std::string UtilitesClass::GetConvertedQt_obj(QCheckBox *value) {
    if (value->isChecked() == 1) {
        return "true";
    }
    return "false";
};
std::string UtilitesClass::GetConvertedQt_obj(QSpinBox *value) {
    return std::to_string(value->value());
};
std::string UtilitesClass::GetConvertedQt_obj(QDoubleSpinBox *value) {
    return std::to_string(value->value());
};
std::string UtilitesClass::GetConvertedQt_obj(QTextEdit *value) {
    return value->toPlainText().trimmed().toStdString();
};
std::string UtilitesClass::GetConvertedQt_obj(QComboBox *value) {
    return value->currentText().toStdString();
};
std::string UtilitesClass::GetConvertedQt_obj(QSlider *value) {
    return std::to_string(value->value());
};
