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
    if (UtilitesClass::GetConvertedQt_obj(ui->AutoImport_checkBox) == "true") {
        Sleep(500);
        on_ImportSettings_pushButton_clicked();
    }
}

void MainClass::AutoPlay()
{
    if (UtilitesClass::GetConvertedQt_obj(ui->AutoPlay_checkBox) == "true") {
        Sleep(500);
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
                        { "ActiveCam", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_checkBox_1) },
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
                        { "ActiveCam", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_checkBox_2) },
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
                        { "ActiveCam", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_checkBox_3) },
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
                        { "ActiveCam", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_checkBox_4) },
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
                        { "ActiveCam", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_checkBox_5) },
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
                        { "ActiveCam", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_checkBox_6) },
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
                        { "ActiveCam", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_checkBox_7) },
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
                        { "ActiveCam", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_checkBox_8) },
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
                        { "ActiveCam", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_checkBox_9) },
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
                        { "ActiveCam", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_checkBox_10) },
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

void MainClass::on_ExportSettings_pushButton_clicked()
{
    UtilitesClass::PrintValueToConsole("export settings");

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

        { "ActiveCam_1", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_checkBox_1) },
        { "AliasCam_1", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_textEdit_1) },
        { "IpCam_1", UtilitesClass::GetConvertedQt_obj(ui->IpCam_textEdit_1) },
        { "MaskCam_1", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_textEdit_1) },
        { "AlarmLevel_1", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_spinBox_1) },
        { "CorrectCoefficient_1", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_doubleSpinBox_1) },
        { "InRangeSetFrom_1", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_spinBox_1) },
        { "InRangeSetTo_1", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_spinBox_1) },
        { "CountNotZero_1", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_spinBox_1) },
        { "Point_1_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_spinBox_1) },
        { "Point_1_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_spinBox_1) },
        { "Point_1_3_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_spinBox_1) },
        { "Point_2_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_spinBox_1) },
        { "Point_2_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_spinBox_1) },
        { "Point_2_3_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_spinBox_1) },

        { "ActiveCam_2", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_checkBox_2) },
        { "AliasCam_2", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_textEdit_2) },
        { "IpCam_2", UtilitesClass::GetConvertedQt_obj(ui->IpCam_textEdit_2) },
        { "MaskCam_2", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_textEdit_2) },
        { "AlarmLevel_2", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_spinBox_2) },
        { "CorrectCoefficient_2", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_doubleSpinBox_2) },
        { "InRangeSetFrom_2", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_spinBox_2) },
        { "InRangeSetTo_2", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_spinBox_2) },
        { "CountNotZero_2", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_spinBox_2) },
        { "Point_1_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_spinBox_2) },
        { "Point_1_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_spinBox_2) },
        { "Point_1_3_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_spinBox_2) },
        { "Point_2_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_spinBox_2) },
        { "Point_2_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_spinBox_2) },
        { "Point_2_3_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_spinBox_2) },

        { "ActiveCam_3", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_checkBox_3) },
        { "AliasCam_3", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_textEdit_3) },
        { "IpCam_3", UtilitesClass::GetConvertedQt_obj(ui->IpCam_textEdit_3) },
        { "MaskCam_3", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_textEdit_3) },
        { "AlarmLevel_3", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_spinBox_3) },
        { "CorrectCoefficient_3", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_doubleSpinBox_3) },
        { "InRangeSetFrom_3", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_spinBox_3) },
        { "InRangeSetTo_3", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_spinBox_3) },
        { "CountNotZero_3", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_spinBox_3) },
        { "Point_1_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_spinBox_3) },
        { "Point_1_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_spinBox_3) },
        { "Point_1_3_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_spinBox_3) },
        { "Point_2_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_spinBox_3) },
        { "Point_2_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_spinBox_3) },
        { "Point_2_3_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_spinBox_3) },

        { "ActiveCam_4", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_checkBox_4) },
        { "AliasCam_4", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_textEdit_4) },
        { "IpCam_4", UtilitesClass::GetConvertedQt_obj(ui->IpCam_textEdit_4) },
        { "MaskCam_4", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_textEdit_4) },
        { "AlarmLevel_4", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_spinBox_4) },
        { "CorrectCoefficient_4", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_doubleSpinBox_4) },
        { "InRangeSetFrom_4", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_spinBox_4) },
        { "InRangeSetTo_4", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_spinBox_4) },
        { "CountNotZero_4", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_spinBox_4) },
        { "Point_1_1_4", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_spinBox_4) },
        { "Point_1_2_4", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_spinBox_4) },
        { "Point_1_3_4", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_spinBox_4) },
        { "Point_2_1_4", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_spinBox_4) },
        { "Point_2_2_4", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_spinBox_4) },
        { "Point_2_3_4", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_spinBox_4) },

        { "ActiveCam_5", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_checkBox_5) },
        { "AliasCam_5", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_textEdit_5) },
        { "IpCam_5", UtilitesClass::GetConvertedQt_obj(ui->IpCam_textEdit_5) },
        { "MaskCam_5", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_textEdit_5) },
        { "AlarmLevel_5", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_spinBox_5) },
        { "CorrectCoefficient_5", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_doubleSpinBox_5) },
        { "InRangeSetFrom_5", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_spinBox_5) },
        { "InRangeSetTo_5", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_spinBox_5) },
        { "CountNotZero_5", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_spinBox_5) },
        { "Point_1_1_5", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_spinBox_5) },
        { "Point_1_2_5", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_spinBox_5) },
        { "Point_1_3_5", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_spinBox_5) },
        { "Point_2_1_5", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_spinBox_5) },
        { "Point_2_2_5", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_spinBox_5) },
        { "Point_2_3_5", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_spinBox_5) },

        { "ActiveCam_6", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_checkBox_6) },
        { "AliasCam_6", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_textEdit_6) },
        { "IpCam_6", UtilitesClass::GetConvertedQt_obj(ui->IpCam_textEdit_6) },
        { "MaskCam_6", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_textEdit_6) },
        { "AlarmLevel_6", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_spinBox_6) },
        { "CorrectCoefficient_6", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_doubleSpinBox_6) },
        { "InRangeSetFrom_6", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_spinBox_6) },
        { "InRangeSetTo_6", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_spinBox_6) },
        { "CountNotZero_6", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_spinBox_6) },
        { "Point_1_1_6", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_spinBox_6) },
        { "Point_1_2_6", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_spinBox_6) },
        { "Point_1_3_6", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_spinBox_6) },
        { "Point_2_1_6", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_spinBox_6) },
        { "Point_2_2_6", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_spinBox_6) },
        { "Point_2_3_6", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_spinBox_6) },

        { "ActiveCam_7", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_checkBox_7) },
        { "AliasCam_7", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_textEdit_7) },
        { "IpCam_7", UtilitesClass::GetConvertedQt_obj(ui->IpCam_textEdit_7) },
        { "MaskCam_7", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_textEdit_7) },
        { "AlarmLevel_7", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_spinBox_7) },
        { "CorrectCoefficient_7", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_doubleSpinBox_7) },
        { "InRangeSetFrom_7", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_spinBox_7) },
        { "InRangeSetTo_7", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_spinBox_7) },
        { "CountNotZero_7", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_spinBox_7) },
        { "Point_1_1_7", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_spinBox_7) },
        { "Point_1_2_7", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_spinBox_7) },
        { "Point_1_3_7", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_spinBox_7) },
        { "Point_2_1_7", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_spinBox_7) },
        { "Point_2_2_7", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_spinBox_7) },
        { "Point_2_3_7", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_spinBox_7) },

        { "ActiveCam_8", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_checkBox_8) },
        { "AliasCam_8", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_textEdit_8) },
        { "IpCam_8", UtilitesClass::GetConvertedQt_obj(ui->IpCam_textEdit_8) },
        { "MaskCam_8", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_textEdit_8) },
        { "AlarmLevel_8", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_spinBox_8) },
        { "CorrectCoefficient_8", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_doubleSpinBox_8) },
        { "InRangeSetFrom_8", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_spinBox_8) },
        { "InRangeSetTo_8", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_spinBox_8) },
        { "CountNotZero_8", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_spinBox_8) },
        { "Point_1_1_8", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_spinBox_8) },
        { "Point_1_2_8", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_spinBox_8) },
        { "Point_1_3_8", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_spinBox_8) },
        { "Point_2_1_8", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_spinBox_8) },
        { "Point_2_2_8", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_spinBox_8) },
        { "Point_2_3_8", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_spinBox_8) },

        { "ActiveCam_9", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_checkBox_9) },
        { "AliasCam_9", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_textEdit_9) },
        { "IpCam_9", UtilitesClass::GetConvertedQt_obj(ui->IpCam_textEdit_9) },
        { "MaskCam_9", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_textEdit_9) },
        { "AlarmLevel_9", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_spinBox_9) },
        { "CorrectCoefficient_9", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_doubleSpinBox_9) },
        { "InRangeSetFrom_9", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_spinBox_9) },
        { "InRangeSetTo_9", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_spinBox_9) },
        { "CountNotZero_9", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_spinBox_9) },
        { "Point_1_1_9", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_spinBox_9) },
        { "Point_1_2_9", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_spinBox_9) },
        { "Point_1_3_9", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_spinBox_9) },
        { "Point_2_1_9", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_spinBox_9) },
        { "Point_2_2_9", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_spinBox_9) },
        { "Point_2_3_9", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_spinBox_9) },

        { "ActiveCam_10", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_checkBox_10) },
        { "AliasCam_10", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_textEdit_10) },
        { "IpCam_10", UtilitesClass::GetConvertedQt_obj(ui->IpCam_textEdit_10) },
        { "MaskCam_10", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_textEdit_10) },
        { "AlarmLevel_10", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_spinBox_10) },
        { "CorrectCoefficient_10", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_doubleSpinBox_10) },
        { "InRangeSetFrom_10", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_spinBox_10) },
        { "InRangeSetTo_10", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_spinBox_10) },
        { "CountNotZero_10", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_spinBox_10) },
        { "Point_1_1_10", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_spinBox_10) },
        { "Point_1_2_10", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_spinBox_10) },
        { "Point_1_3_10", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_spinBox_10) },
        { "Point_2_1_10", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_spinBox_10) },
        { "Point_2_2_10", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_spinBox_10) },
        { "Point_2_3_10", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_spinBox_10) },
    };
    QJsonObject json;
    for (auto& elem : AllSettingsMap)
        json[QString::fromStdString(elem.first)] = QString::fromStdString(elem.second);

    QJsonDocument document;
    document.setObject(json);
    QFile file("settings.json");
    if (!file.open(QIODevice::WriteOnly)) {
     std::cerr << "Error: unable to open a file" << std::endl;
    }
    if (!file.write(document.toJson())) {
     std::cerr << "Error: unable to write a file" << std::endl;
    }
}

void MainClass::on_ImportSettings_pushButton_clicked()
{
    UtilitesClass::PrintValueToConsole("import settings");

    QFile file("settings.json");
    if (!file.open( QIODevice::ReadOnly)) {
        std::cerr << "Error: unable to open a file" << std::endl;
    }
    QByteArray data = file.readAll();
    QJsonDocument document;
    document = document.fromJson(data);
    std::map<std::string, QCheckBox*> QCheckBoxMap = {
        { "AutoPlay", ui->AutoPlay_checkBox },
        { "AutoImport", ui->AutoImport_checkBox },
        { "WriteToWidget", ui->WriteToWidget_checkBox },
        { "WriteToText", ui->WriteToText_checkBox },

        { "ActiveCam_1", ui->ActiveCam_checkBox_1 },
        { "ActiveCam_2", ui->ActiveCam_checkBox_2 },
        { "ActiveCam_3", ui->ActiveCam_checkBox_3 },
        { "ActiveCam_4", ui->ActiveCam_checkBox_4 },
        { "ActiveCam_5", ui->ActiveCam_checkBox_5 },
        { "ActiveCam_6", ui->ActiveCam_checkBox_6 },
        { "ActiveCam_7", ui->ActiveCam_checkBox_7 },
        { "ActiveCam_8", ui->ActiveCam_checkBox_8 },
        { "ActiveCam_9", ui->ActiveCam_checkBox_9 },
        { "ActiveCam_10", ui->ActiveCam_checkBox_10 },
    };
    for (auto& elem : QCheckBoxMap){
        UtilitesClass::SetConvertedQt_obj(elem.second, document.object()[QString::fromStdString(elem.first)].toString());
    }
    std::map<std::string, QSpinBox*> QSpinBoxMap = {
        { "PortCam", ui->PortCam_spinBox },

        { "AlarmLevel_1", ui->AlarmLevel_spinBox_1 },
        { "AlarmLevel_2", ui->AlarmLevel_spinBox_2 },
        { "AlarmLevel_3", ui->AlarmLevel_spinBox_3 },
        { "AlarmLevel_4", ui->AlarmLevel_spinBox_4 },
        { "AlarmLevel_5", ui->AlarmLevel_spinBox_5 },
        { "AlarmLevel_6", ui->AlarmLevel_spinBox_6 },
        { "AlarmLevel_7", ui->AlarmLevel_spinBox_7 },
        { "AlarmLevel_8", ui->AlarmLevel_spinBox_8 },
        { "AlarmLevel_9", ui->AlarmLevel_spinBox_9 },
        { "AlarmLevel_10", ui->AlarmLevel_spinBox_10 },
        { "InRangeSetFrom_1", ui->InRangeSetFrom_spinBox_1 },
        { "InRangeSetFrom_2", ui->InRangeSetFrom_spinBox_2 },
        { "InRangeSetFrom_3", ui->InRangeSetFrom_spinBox_3 },
        { "InRangeSetFrom_4", ui->InRangeSetFrom_spinBox_4 },
        { "InRangeSetFrom_5", ui->InRangeSetFrom_spinBox_5 },
        { "InRangeSetFrom_6", ui->InRangeSetFrom_spinBox_6 },
        { "InRangeSetFrom_7", ui->InRangeSetFrom_spinBox_7 },
        { "InRangeSetFrom_8", ui->InRangeSetFrom_spinBox_8 },
        { "InRangeSetFrom_9", ui->InRangeSetFrom_spinBox_9 },
        { "InRangeSetFrom_10", ui->InRangeSetFrom_spinBox_10 },
        { "InRangeSetTo_1", ui->InRangeSetTo_spinBox_1 },
        { "InRangeSetTo_2", ui->InRangeSetTo_spinBox_2 },
        { "InRangeSetTo_3", ui->InRangeSetTo_spinBox_3 },
        { "InRangeSetTo_4", ui->InRangeSetTo_spinBox_4 },
        { "InRangeSetTo_5", ui->InRangeSetTo_spinBox_5 },
        { "InRangeSetTo_6", ui->InRangeSetTo_spinBox_6 },
        { "InRangeSetTo_7", ui->InRangeSetTo_spinBox_7 },
        { "InRangeSetTo_8", ui->InRangeSetTo_spinBox_8 },
        { "InRangeSetTo_9", ui->InRangeSetTo_spinBox_9 },
        { "InRangeSetTo_10", ui->InRangeSetTo_spinBox_10 },
        { "CountNotZero_1", ui->CountNotZero_spinBox_1 },
        { "CountNotZero_2", ui->CountNotZero_spinBox_2 },
        { "CountNotZero_3", ui->CountNotZero_spinBox_3 },
        { "CountNotZero_4", ui->CountNotZero_spinBox_4 },
        { "CountNotZero_5", ui->CountNotZero_spinBox_5 },
        { "CountNotZero_6", ui->CountNotZero_spinBox_6 },
        { "CountNotZero_7", ui->CountNotZero_spinBox_7 },
        { "CountNotZero_8", ui->CountNotZero_spinBox_8 },
        { "CountNotZero_9", ui->CountNotZero_spinBox_9 },
        { "CountNotZero_10", ui->CountNotZero_spinBox_10 },
        { "Point_1_1_1", ui->Point_1_1_spinBox_1 },
        { "Point_1_1_2", ui->Point_1_1_spinBox_2 },
        { "Point_1_1_3", ui->Point_1_1_spinBox_3 },
        { "Point_1_1_4", ui->Point_1_1_spinBox_4 },
        { "Point_1_1_5", ui->Point_1_1_spinBox_5 },
        { "Point_1_1_6", ui->Point_1_1_spinBox_6 },
        { "Point_1_1_7", ui->Point_1_1_spinBox_7 },
        { "Point_1_1_8", ui->Point_1_1_spinBox_8 },
        { "Point_1_1_9", ui->Point_1_1_spinBox_9 },
        { "Point_1_1_10", ui->Point_1_1_spinBox_10 },
        { "Point_1_2_1", ui->Point_1_2_spinBox_1 },
        { "Point_1_2_2", ui->Point_1_2_spinBox_2 },
        { "Point_1_2_3", ui->Point_1_2_spinBox_3 },
        { "Point_1_2_4", ui->Point_1_2_spinBox_4 },
        { "Point_1_2_5", ui->Point_1_2_spinBox_5 },
        { "Point_1_2_6", ui->Point_1_2_spinBox_6 },
        { "Point_1_2_7", ui->Point_1_2_spinBox_7 },
        { "Point_1_2_8", ui->Point_1_2_spinBox_8 },
        { "Point_1_2_9", ui->Point_1_2_spinBox_9 },
        { "Point_1_2_10", ui->Point_1_2_spinBox_10 },
        { "Point_1_3_1", ui->Point_1_3_spinBox_1 },
        { "Point_1_3_2", ui->Point_1_3_spinBox_2 },
        { "Point_1_3_3", ui->Point_1_3_spinBox_3 },
        { "Point_1_3_4", ui->Point_1_3_spinBox_4 },
        { "Point_1_3_5", ui->Point_1_3_spinBox_5 },
        { "Point_1_3_6", ui->Point_1_3_spinBox_6 },
        { "Point_1_3_7", ui->Point_1_3_spinBox_7 },
        { "Point_1_3_8", ui->Point_1_3_spinBox_8 },
        { "Point_1_3_9", ui->Point_1_3_spinBox_9 },
        { "Point_1_3_10", ui->Point_1_3_spinBox_10 },
        { "Point_2_1_1", ui->Point_2_1_spinBox_1 },
        { "Point_2_1_2", ui->Point_2_1_spinBox_2 },
        { "Point_2_1_3", ui->Point_2_1_spinBox_3 },
        { "Point_2_1_4", ui->Point_2_1_spinBox_4 },
        { "Point_2_1_5", ui->Point_2_1_spinBox_5 },
        { "Point_2_1_6", ui->Point_2_1_spinBox_6 },
        { "Point_2_1_7", ui->Point_2_1_spinBox_7 },
        { "Point_2_1_8", ui->Point_2_1_spinBox_8 },
        { "Point_2_1_9", ui->Point_2_1_spinBox_9 },
        { "Point_2_1_10", ui->Point_2_1_spinBox_10 },
        { "Point_2_2_1", ui->Point_2_2_spinBox_1 },
        { "Point_2_2_2", ui->Point_2_2_spinBox_2 },
        { "Point_2_2_3", ui->Point_2_2_spinBox_3 },
        { "Point_2_2_4", ui->Point_2_2_spinBox_4 },
        { "Point_2_2_5", ui->Point_2_2_spinBox_5 },
        { "Point_2_2_6", ui->Point_2_2_spinBox_6 },
        { "Point_2_2_7", ui->Point_2_2_spinBox_7 },
        { "Point_2_2_8", ui->Point_2_2_spinBox_8 },
        { "Point_2_2_9", ui->Point_2_2_spinBox_9 },
        { "Point_2_2_10", ui->Point_2_2_spinBox_10 },
        { "Point_2_3_1", ui->Point_2_3_spinBox_1 },
        { "Point_2_3_2", ui->Point_2_3_spinBox_2 },
        { "Point_2_3_3", ui->Point_2_3_spinBox_3 },
        { "Point_2_3_4", ui->Point_2_3_spinBox_4 },
        { "Point_2_3_5", ui->Point_2_3_spinBox_5 },
        { "Point_2_3_6", ui->Point_2_3_spinBox_6 },
        { "Point_2_3_7", ui->Point_2_3_spinBox_7 },
        { "Point_2_3_8", ui->Point_2_3_spinBox_8 },
        { "Point_2_3_9", ui->Point_2_3_spinBox_9 },
        { "Point_2_3_10", ui->Point_2_3_spinBox_10 },
    };
    for (auto& elem : QSpinBoxMap){
        UtilitesClass::SetConvertedQt_obj(elem.second, document.object()[QString::fromStdString(elem.first)].toString());
    }
    std::map<std::string, QDoubleSpinBox*> QDoubleSpinBoxMap = {
        { "TimeDelay", ui->TimeDelay_doubleSpinBox },

        { "CorrectCoefficient_1", ui->CorrectCoefficient_doubleSpinBox_1 },
        { "CorrectCoefficient_2", ui->CorrectCoefficient_doubleSpinBox_2 },
        { "CorrectCoefficient_3", ui->CorrectCoefficient_doubleSpinBox_3 },
        { "CorrectCoefficient_4", ui->CorrectCoefficient_doubleSpinBox_4 },
        { "CorrectCoefficient_5", ui->CorrectCoefficient_doubleSpinBox_5 },
        { "CorrectCoefficient_6", ui->CorrectCoefficient_doubleSpinBox_6 },
        { "CorrectCoefficient_7", ui->CorrectCoefficient_doubleSpinBox_7 },
        { "CorrectCoefficient_8", ui->CorrectCoefficient_doubleSpinBox_8 },
        { "CorrectCoefficient_9", ui->CorrectCoefficient_doubleSpinBox_9 },
        { "CorrectCoefficient_10", ui->CorrectCoefficient_doubleSpinBox_10 },
    };
    for (auto& elem : QDoubleSpinBoxMap){
        UtilitesClass::SetConvertedQt_obj(elem.second, document.object()[QString::fromStdString(elem.first)].toString());
    }
    std::map<std::string, QTextEdit*> QTextEditMap = {
        { "ProtocolCam", ui->ProtocolCam_textEdit },
        { "LoginCam", ui->LoginCam_textEdit },
        { "PasswordCam", ui->PasswordCam_textEdit },

        { "AliasCam_1", ui->AliasCam_textEdit_1 },
        { "AliasCam_2", ui->AliasCam_textEdit_2 },
        { "AliasCam_3", ui->AliasCam_textEdit_3 },
        { "AliasCam_4", ui->AliasCam_textEdit_4 },
        { "AliasCam_5", ui->AliasCam_textEdit_5 },
        { "AliasCam_6", ui->AliasCam_textEdit_6 },
        { "AliasCam_7", ui->AliasCam_textEdit_7 },
        { "AliasCam_8", ui->AliasCam_textEdit_8 },
        { "AliasCam_9", ui->AliasCam_textEdit_9 },
        { "AliasCam_10", ui->AliasCam_textEdit_10 },
        { "IpCam_1", ui->IpCam_textEdit_1 },
        { "IpCam_2", ui->IpCam_textEdit_2 },
        { "IpCam_3", ui->IpCam_textEdit_3 },
        { "IpCam_4", ui->IpCam_textEdit_4 },
        { "IpCam_5", ui->IpCam_textEdit_5 },
        { "IpCam_6", ui->IpCam_textEdit_6 },
        { "IpCam_7", ui->IpCam_textEdit_7 },
        { "IpCam_8", ui->IpCam_textEdit_8 },
        { "IpCam_9", ui->IpCam_textEdit_9 },
        { "IpCam_10", ui->IpCam_textEdit_10 },
        { "MaskCam_1", ui->MaskCam_textEdit_1 },
        { "MaskCam_2", ui->MaskCam_textEdit_2 },
        { "MaskCam_3", ui->MaskCam_textEdit_3 },
        { "MaskCam_4", ui->MaskCam_textEdit_4 },
        { "MaskCam_5", ui->MaskCam_textEdit_5 },
        { "MaskCam_6", ui->MaskCam_textEdit_6 },
        { "MaskCam_7", ui->MaskCam_textEdit_7 },
        { "MaskCam_8", ui->MaskCam_textEdit_8 },
        { "MaskCam_9", ui->MaskCam_textEdit_9 },
        { "MaskCam_10", ui->MaskCam_textEdit_10 },
    };
    for (auto& elem : QTextEditMap){
        UtilitesClass::SetConvertedQt_obj(elem.second, document.object()[QString::fromStdString(elem.first)].toString());
    }
    std::map<std::string, QComboBox*> QComboBoxMap = {
        { "RenderType", ui->RenderType_comboBox },
    };
    for (auto& elem : QComboBoxMap){
        UtilitesClass::SetConvertedQt_obj(elem.second, document.object()[QString::fromStdString(elem.first)].toString());
    }
    std::map<std::string, QSlider*> QSliderMap = {
        { "RenderSize", ui->RenderSize_horizontalSlider },
    };
    for (auto& elem : QSliderMap){
        UtilitesClass::SetConvertedQt_obj(elem.second, document.object()[QString::fromStdString(elem.first)].toString());
    }
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
            if (UtilitesClass::GetValueFromMap(OneSettingsMap, "ActiveCam") == "true"){
                MultiThreadClass* obj = new MultiThreadClass(AllSettingsMap, OneSettingsMap, ui);
                obj->deleteLater();
            }
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
}

void UtilitesClass::SetConvertedQt_obj(QCheckBox *value, QString text)
{
    if (text == "true") {
        value->setChecked(true);
    } else {
        value->setChecked(false);
    }
}
void UtilitesClass::SetConvertedQt_obj(QSpinBox *value, QString text)
{
    value->setValue(std::stoi(text.toStdString()));
}
void UtilitesClass::SetConvertedQt_obj(QDoubleSpinBox *value, QString text)
{
    value->setValue(std::stod(text.toStdString()));
}
void UtilitesClass::SetConvertedQt_obj(QTextEdit *value, QString text)
{
    value->setText(text);
}
void UtilitesClass::SetConvertedQt_obj(QComboBox *value, QString text)
{
    value->setCurrentText(text);
}
void UtilitesClass::SetConvertedQt_obj(QSlider *value, QString text)
{
    value->setValue(std::stoi(text.toStdString()));
};
