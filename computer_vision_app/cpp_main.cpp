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
}



MainClass::~MainClass()
{
    delete ui;
}



void MainClass::on_START_btn_clicked()
{
    on_STOP_btn_clicked();
    Playing = true;
    ui->playing_radioButton->setChecked(Playing);
    start();
}



void MainClass::on_STOP_btn_clicked()
{
    Playing = false;
    cv::destroyAllWindows();
    ui->playing_radioButton->setChecked(Playing);
}



void MainClass::on_QUIT_btn_clicked()
{
    on_STOP_btn_clicked();
    this->close();
}



void MainClass::start()
{
    if (Playing){
        QCoreApplication::processEvents();
        std::map <std::string,std::string> AllSettingsMap = {
            { "render_size", UtilitesClass::GetConvertedQt_obj(ui->render_size_horizontalSlider) },
            { "TimeDelay", UtilitesClass::GetConvertedQt_obj(ui->TimeDelay_doubleSpinBox) },
            { "protocol_type", UtilitesClass::GetConvertedQt_obj(ui->protocol_type_textEdit) },
            { "port_cam", UtilitesClass::GetConvertedQt_obj(ui->port_cam_spinBox) },
            { "login_cam", UtilitesClass::GetConvertedQt_obj(ui->login_cam_textEdit) },
            { "password_cam", UtilitesClass::GetConvertedQt_obj(ui->password_cam_textEdit) },
        };
        std::vector<std::map<std::string,std::string>> AllSettingsVector =
        {
            {
                { "alias_cam", UtilitesClass::GetConvertedQt_obj(ui->alias_cam_textEdit_1) },
                { "ip_cam", UtilitesClass::GetConvertedQt_obj(ui->ip_cam_textEdit_1) },
                { "mask_cam", UtilitesClass::GetConvertedQt_obj(ui->mask_cam_textEdit_1) },
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
                { "alias_cam", UtilitesClass::GetConvertedQt_obj(ui->alias_cam_textEdit_2) },
                { "ip_cam", UtilitesClass::GetConvertedQt_obj(ui->ip_cam_textEdit_2) },
                { "mask_cam", UtilitesClass::GetConvertedQt_obj(ui->mask_cam_textEdit_2) },
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
                { "alias_cam", UtilitesClass::GetConvertedQt_obj(ui->alias_cam_textEdit_3) },
                { "ip_cam", UtilitesClass::GetConvertedQt_obj(ui->ip_cam_textEdit_3) },
                { "mask_cam", UtilitesClass::GetConvertedQt_obj(ui->mask_cam_textEdit_3) },
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
                { "alias_cam", UtilitesClass::GetConvertedQt_obj(ui->alias_cam_textEdit_4) },
                { "ip_cam", UtilitesClass::GetConvertedQt_obj(ui->ip_cam_textEdit_4) },
                { "mask_cam", UtilitesClass::GetConvertedQt_obj(ui->mask_cam_textEdit_4) },
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
                { "alias_cam", UtilitesClass::GetConvertedQt_obj(ui->alias_cam_textEdit_5) },
                { "ip_cam", UtilitesClass::GetConvertedQt_obj(ui->ip_cam_textEdit_5) },
                { "mask_cam", UtilitesClass::GetConvertedQt_obj(ui->mask_cam_textEdit_5) },
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
                { "alias_cam", UtilitesClass::GetConvertedQt_obj(ui->alias_cam_textEdit_6) },
                { "ip_cam", UtilitesClass::GetConvertedQt_obj(ui->ip_cam_textEdit_6) },
                { "mask_cam", UtilitesClass::GetConvertedQt_obj(ui->mask_cam_textEdit_6) },
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
                { "alias_cam", UtilitesClass::GetConvertedQt_obj(ui->alias_cam_textEdit_7) },
                { "ip_cam", UtilitesClass::GetConvertedQt_obj(ui->ip_cam_textEdit_7) },
                { "mask_cam", UtilitesClass::GetConvertedQt_obj(ui->mask_cam_textEdit_7) },
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
                { "alias_cam", UtilitesClass::GetConvertedQt_obj(ui->alias_cam_textEdit_8) },
                { "ip_cam", UtilitesClass::GetConvertedQt_obj(ui->ip_cam_textEdit_8) },
                { "mask_cam", UtilitesClass::GetConvertedQt_obj(ui->mask_cam_textEdit_8) },
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
                { "alias_cam", UtilitesClass::GetConvertedQt_obj(ui->alias_cam_textEdit_9) },
                { "ip_cam", UtilitesClass::GetConvertedQt_obj(ui->ip_cam_textEdit_9) },
                { "mask_cam", UtilitesClass::GetConvertedQt_obj(ui->mask_cam_textEdit_9) },
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
                { "alias_cam", UtilitesClass::GetConvertedQt_obj(ui->alias_cam_textEdit_10) },
                { "ip_cam", UtilitesClass::GetConvertedQt_obj(ui->ip_cam_textEdit_10) },
                { "mask_cam", UtilitesClass::GetConvertedQt_obj(ui->mask_cam_textEdit_10) },
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
        for (auto& OneSettingsMap : AllSettingsVector)
        {
            QCoreApplication::processEvents();
            if (Playing){
                QCoreApplication::processEvents();

//                QFuture<double> future = QtConcurrent::run(&MainClass::startThread, AllSettingsMap, OneSettingsMap);
//                double result = future.result();
//                int alarm = 0;
//                if (result > std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "alias_cam"))){
//                    alarm = 1;
//                }
//                UtilitesClass::SetValuesToSQL(UtilitesClass::GetValueFromMap(OneSettingsMap, "alias_cam").substr(0,2) + "/" + UtilitesClass::GetValueFromMap(OneSettingsMap, "alias_cam").substr(3), result, alarm);

                startSync(AllSettingsMap, OneSettingsMap);
            }
            QCoreApplication::processEvents();
        }
        QCoreApplication::processEvents();
        Sleep(int (std::stod(UtilitesClass::GetValueFromMap(AllSettingsMap, "TimeDelay"))*1000));
        if (Playing){
            on_START_btn_clicked();
        }
    }
}



void MainClass::startSync(std::map<std::string,std::string> AllSettingsMap, std::map<std::string,std::string> OneSettingsMap)
{
    try {
        QUrl url = QString::fromStdString(UtilitesClass::GetUrlFromIp(AllSettingsMap, UtilitesClass::GetValueFromMap(OneSettingsMap, "ip_cam")));
        url.setUserName(QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettingsMap, "login_cam")));
        url.setPassword(QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettingsMap, "password_cam")));
        QNetworkAccessManager *manager = new QNetworkAccessManager;
        QNetworkReply* reply = manager->get(QNetworkRequest(url));
        QEventLoop loop;
        connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();
        QByteArray data = reply->readAll();
        cv::Mat image_source;
        QPixmap qPixmap;
        if (qPixmap.loadFromData(data,"JPG")) {
            QImage qImage = qPixmap.toImage();
            image_source = cv::Mat(qImage.height(), qImage.width(), CV_8UC4, const_cast<uchar*>(qImage.bits()), static_cast<size_t>(qImage.bytesPerLine()));
            cv::Mat mask = cv::imread(UtilitesClass::GetValueFromMap(OneSettingsMap, "mask_cam"), 0);
            cv::Mat bitwise_and;
            cv::bitwise_and(image_source, image_source, bitwise_and, mask);

            cv::Mat cvtcolor;
            cv::cvtColor(bitwise_and, cvtcolor, cv::COLOR_BGR2HSV);

            cv::Mat inrange;
            cv::inRange(cvtcolor, cv::Scalar(std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "Point_1_1")),
                                             std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "Point_1_2")),
                                             std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "Point_1_3"))),
                        cv::Scalar(std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "Point_2_1")),
                                   std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "Point_2_2")),
                                   std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "Point_2_3"))), inrange);

            inrange.setTo(std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "InRangeSetTo")), inrange >= std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "InRangeSetFrom")));
            double result = double(cv::countNonZero(inrange > std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "CountNotZero")))) / double(cv::countNonZero(mask)) * 100 * std::stod(UtilitesClass::GetValueFromMap(OneSettingsMap, "CorrectCoefficient"));
            if (result > 100){
                result = 100.0;
            } else if(result < 0){
                result = 0.0;
            } else {
                float pow_10 = pow(10.0f, (float)2);
                result = round(result * pow_10) / pow_10;
            }
            cv::Mat final;
            cv::resize(inrange, final, cv::Size(), std::stoi(UtilitesClass::GetValueFromMap(AllSettingsMap, "render_size")) / 80.0,
                       std::stoi(UtilitesClass::GetValueFromMap(AllSettingsMap, "render_size")) / 80.0, cv::INTER_LINEAR);
            cv::putText(final, UtilitesClass::GetLocalTime(),
                        cv::Point(150, 50), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
            cv::putText(final, UtilitesClass::GetValueFromMap(OneSettingsMap, "ip_cam") + " | " + UtilitesClass::GetValueFromMap(OneSettingsMap, "alias_cam"),
                        cv::Point(150, 100), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
            if(result > std::stoi((UtilitesClass::GetValueFromMap(OneSettingsMap, "AlarmLevel")))){
                cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(255, 255, 255), 2);
                QString danger = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #FF0350,stop: 0.4999 #FF0020,stop: 0.5 #FF0019,stop: 1 #FF0000 );border-bottom-right-radius: 5px;border-bottom-left-radius: 5px;border: .px solid black;}";
                ui->progressBar->setStyleSheet(danger);
                UtilitesClass::SetValuesToSQL(UtilitesClass::GetValueFromMap(OneSettingsMap, "alias_cam").substr(0,2) + "/" + UtilitesClass::GetValueFromMap(OneSettingsMap, "alias_cam").substr(3), result, 1);
            }
            else {
                cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(128, 128, 128), 1);
                QString safe= "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #78d,stop: 0.4999 #46a,stop: 0.5 #45a,stop: 1 #238 );border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;border: 1px solid black;}";
                ui->progressBar->setStyleSheet(safe);
                UtilitesClass::SetValuesToSQL(UtilitesClass::GetValueFromMap(OneSettingsMap, "alias_cam").substr(0,2) + "/" + UtilitesClass::GetValueFromMap(OneSettingsMap, "alias_cam").substr(3), result, 0);
            }
//            cv::namedWindow("render " + UtilitesClass::GetValueFromMap(OneSettingsMap, "alias_cam"), cv::WINDOW_AUTOSIZE);
//            cv::imshow("render " + UtilitesClass::GetValueFromMap(OneSettingsMap, "alias_cam"), final);
//            cv::waitKey(1);

//            cv::resize(image_source, image_source, cv::Size(), std::stoi(UtilitesClass::GetValueFromMap(AllSettingsMap, "render_size")) / 80.0,
//                       std::stoi(UtilitesClass::GetValueFromMap(AllSettingsMap, "render_size")) / 80.0, cv::INTER_LINEAR);
//            cv::namedWindow("source " + UtilitesClass::GetValueFromMap(OneSettingsMap, "alias_cam"), cv::WINDOW_AUTOSIZE);
//            cv::imshow("source " + UtilitesClass::GetValueFromMap(OneSettingsMap, "alias_cam"), image_source);
//            cv::waitKey(1);
            ui->label_time->setText(QString::fromStdString(UtilitesClass::GetLocalTime()));
            ui->label_info->setText(QString::fromStdString(UtilitesClass::GetValueFromMap(OneSettingsMap, "ip_cam") + " | " + UtilitesClass::GetValueFromMap(OneSettingsMap, "alias_cam")));
            ui->progressBar->setValue(result);
            ui->lcdNumber->display(result);
            UtilitesClass::PrintValueToConsole("RESULT " + UtilitesClass::GetValueFromMap(OneSettingsMap, "alias_cam") + " IS : " + std::to_string(result) + "%");
            reply->deleteLater();
            manager->deleteLater();
        }
    }  catch (std::string error) {
        UtilitesClass::PrintValueToConsole(error);
    }
}



double MainClass::startThread(std::map<std::string,std::string> AllSettingsMap, std::map<std::string,std::string> OneSettingsMap)
{
    double result = 0.0;
    try {
        QUrl url = QString::fromStdString(UtilitesClass::GetUrlFromIp(AllSettingsMap ,UtilitesClass::GetValueFromMap(OneSettingsMap, "ip_cam")));
        url.setUserName("admin");
        url.setPassword("q1234567");
        QNetworkAccessManager *manager = new QNetworkAccessManager;
        QNetworkReply* reply = manager->get(QNetworkRequest(url));
        QEventLoop loop;
        connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();
        QByteArray data = reply->readAll();
        cv::Mat image_source;
        QPixmap qPixmap;
        if (qPixmap.loadFromData(data,"JPG")) {
            QImage qImage = qPixmap.toImage();
            image_source = cv::Mat(qImage.height(), qImage.width(), CV_8UC4, const_cast<uchar*>(qImage.bits()), static_cast<size_t>(qImage.bytesPerLine()));
            cv::Mat mask = cv::imread(UtilitesClass::GetValueFromMap(OneSettingsMap, "mask_cam"), 0);
            cv::Mat bitwise_and;
            cv::bitwise_and(image_source, image_source, bitwise_and, mask);
            cv::Mat cvtcolor;
            cv::cvtColor(bitwise_and, cvtcolor, cv::COLOR_BGR2HSV);
            cv::Mat inrange;
            cv::inRange(cvtcolor, cv::Scalar(std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "Point_1_1")),
                                             std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "Point_1_2")),
                                             std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "Point_1_3"))),
                        cv::Scalar(std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "Point_2_1")),
                                   std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "Point_2_2")),
                                   std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "Point_2_3"))), inrange);
            inrange.setTo(std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "InRangeSetTo")), inrange >= std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "InRangeSetFrom")));
            result = double(cv::countNonZero(inrange > std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "CountNotZero")))) / double(cv::countNonZero(mask)) * 100 * std::stod(UtilitesClass::GetValueFromMap(OneSettingsMap, "CorrectCoefficient"));
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
            UtilitesClass::PrintValueToConsole("RESULT " + UtilitesClass::GetValueFromMap(OneSettingsMap, "alias_cam") + " IS : " + std::to_string(result) + "%" + " | " + UtilitesClass::GetLocalTime());
            reply->deleteLater();
            manager->deleteLater();
            return result;
        }
    }  catch (std::string error) {
        UtilitesClass::PrintValueToConsole(error);
        return result;
    }
    return result;
}



void UtilitesClass::PrintValueToConsole(std::string Value)
{
    std::cout << Value << std::endl;
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
        UtilitesClass::PrintValueToConsole("good to open sql");
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

    if (UtilitesClass::GetValueFromMap(Map, "protocol_type") == "http") {
//        "http://192.168.15.203:80/ISAPI/Streaming/channels/101/picture?snapShotImageType=JPEG";
        url = UtilitesClass::GetValueFromMap(Map, "protocol_type") + "://192.168." + Ip + ":" +
                UtilitesClass::GetValueFromMap(Map, "port_cam") + "/ISAPI/Streaming/channels/101/picture?snapShotImageType=JPEG";
    }
    if (UtilitesClass::GetValueFromMap(Map, "protocol_type") == "rtsp") {
//        "rtsp://admin:q1234567@192.168.15.203:554";
        url = UtilitesClass::GetValueFromMap(Map, "protocol_type") + "://" + UtilitesClass::GetValueFromMap(Map, "login_cam") + ":" +
                UtilitesClass::GetValueFromMap(Map, "password_cam") + "@" + "192.168." + Ip + ":" + UtilitesClass::GetValueFromMap(Map, "port_cam");
    }
    if (UtilitesClass::GetValueFromMap(Map, "protocol_type") == "test") {
        url = "http://via.placeholder.com/1000.jpg";
    }
    return url;
};



std::string UtilitesClass::GetLocalTime(){
    time_t now = time(0);
    return std::string(ctime(&now));
};



std::string UtilitesClass::GetConvertedQt_obj(QCheckBox *value) {
    if (value->isChecked() == 1) {
        return "True";
    }
    return "False";
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


