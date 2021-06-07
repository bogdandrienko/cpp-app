#include "cpp_main.h"
#include "ui_cpp_main.h"

#include <iostream>
#include <string>
#include <map>

#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QTextEdit>
#include <QComboBox>
#include <QSlider>

#include <QApplication>
#include <QtWidgets>
#include <QtNetwork>
#include <QDataStream>

#include <opencv2/opencv.hpp>



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
    UtilitesClass::PrintValueToConsole("on_START_btn_clicked");

    Playing = true;
    AllSettingsMap = {
        { "protocol_type", UtilitesClass::GetConvertedQt_obj(ui->protocol_type_Edit)},
        { "port_cam", UtilitesClass::GetConvertedQt_obj(ui->port_cam_spinBox) },
        { "login_cam", UtilitesClass::GetConvertedQt_obj(ui->login_cam_Edit) },
        { "password_cam", UtilitesClass::GetConvertedQt_obj(ui->password_cam_Edit) },

        { "alias_cam", UtilitesClass::GetConvertedQt_obj(ui->alias_cam_1_Edit) },
        { "ip_cam", UtilitesClass::GetConvertedQt_obj(ui->ip_cam_1_Edit) },
        { "mask_cam", UtilitesClass::GetConvertedQt_obj(ui->mask_cam_1_Edit) },
        { "sensetivity_cam", UtilitesClass::GetConvertedQt_obj(ui->sensetivity_cam_1_SpinBox) },
        { "alarm_level", UtilitesClass::GetConvertedQt_obj(ui->alarm_level_1_SpinBox) },
        { "correct_coefficient", UtilitesClass::GetConvertedQt_obj(ui->correct_coefficient_1_doubleSpinBox) },

        { "render_type", UtilitesClass::GetConvertedQt_obj(ui->render_type_comboBox) },
        { "render_size", UtilitesClass::GetConvertedQt_obj(ui->render_size_horizontalSlider) },
        { "write_now_sql", UtilitesClass::GetConvertedQt_obj(ui->write_now_sql_checkBox) },
    };

    if (Playing){
        try{
            download_from_url();
            ui->playing_radioButton->setChecked(Playing);
        } catch (int number) {
            UtilitesClass::PrintValueToConsole("Exception: " + std::to_string(number));
            Sleep(1000);
            on_START_btn_clicked();
        }
    }
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

void MainClass::download_from_url()
{
    UtilitesClass::PrintValueToConsole("download_from_url");

    connect(&qnam, &QNetworkAccessManager::authenticationRequired, this, &MainClass::authentication_to_access);
    qreply.reset(qnam.get(QNetworkRequest(QString::fromStdString(UtilitesClass::GetUrlFromIp(AllSettingsMap, UtilitesClass::GetValueFromMap(AllSettingsMap, "ip_cam"))))));
    connect(qreply.get(), &QNetworkReply::finished, this, &MainClass::write_to_file);
}

void MainClass::authentication_to_access(QNetworkReply *, QAuthenticator *qauthenticator)
{
    UtilitesClass::PrintValueToConsole("authentication_to_access");

    qauthenticator->setUser(QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettingsMap, "login_cam")));
    qauthenticator->setPassword(QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettingsMap, "password_cam")));
}

std::unique_ptr<QFile> MainClass::openFileForWrite(const QString &fileName)
{
    UtilitesClass::PrintValueToConsole("openFileForWrite");

    std::unique_ptr<QFile> file = std::make_unique<QFile>(fileName);
    if (!file->open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Error"),
                                 tr("Unable to save the file %1: %2.")
                                 .arg(QDir::toNativeSeparators(fileName),
                                      file->errorString()));
        return nullptr;
    }
    return file;
}



void MainClass::write_to_file()
{
    UtilitesClass::PrintValueToConsole("write_to_file");

    file = openFileForWrite(QString::fromStdString("./" + UtilitesClass::GetValueFromMap(AllSettingsMap, "alias_cam") + ".jpg"));
    file->write(qreply->readAll());
    file->close();

    analyse_from_image();
}



void MainClass::analyse_from_image()
{
    UtilitesClass::PrintValueToConsole("analyse_from_image");

    double result = 0.0;
    std::string render_type = UtilitesClass::GetValueFromMap(AllSettingsMap, "render_type");

    if (render_type == "none"){
    }
    if (render_type == "test"){
        cv::Mat source = cv::imread(UtilitesClass::GetValueFromMap(AllSettingsMap, "alias_cam") + ".jpg", cv::IMREAD_COLOR);
        cv::Mat mask = cv::imread(UtilitesClass::GetValueFromMap(AllSettingsMap, "mask_cam"), 0);

        int alarm = ui->alarm_horizontalSlider->value();
        ui->alarm_info->setText(QString::fromStdString("Alarm level: " + std::to_string(alarm)));
        double correct = ui->correct_horizontalSlider->value() / 50.0;
        ui->correct_info->setText(QString::fromStdString("Correct level: " + std::to_string(correct)));
        int countNonZero_inrange = ui->zero_inrange_horizontalSlider->value();
        ui->countnotzerol_info->setText(QString::fromStdString("CountNOotZero level: " + std::to_string(countNonZero_inrange)));
        int point_1_1 = ui->point_1_1_horizontalSlider->value();
        ui->point_1_1_info->setText(QString::fromStdString("point_1_1 level: " + std::to_string(point_1_1)));
        int point_1_2 = ui->point_1_2_horizontalSlider->value();
        ui->point_1_2_info->setText(QString::fromStdString("point_1_2 level: " + std::to_string(point_1_2)));
        int point_1_3 = ui->point_1_3_horizontalSlider->value();
        ui->point_1_3_info->setText(QString::fromStdString("point_1_3 level: " + std::to_string(point_1_3)));
        int point_2_1 = ui->point_2_1_horizontalSlider->value();
        ui->point_2_1_info->setText(QString::fromStdString("point_2_1 level: " + std::to_string(point_2_1)));
        int point_2_2 = ui->point_2_2_horizontalSlider->value();
        ui->point_2_2_info->setText(QString::fromStdString("point_2_2 level: " + std::to_string(point_2_2)));
        int point_2_3 = ui->point_2_3_horizontalSlider->value();
        ui->point_2_3_info->setText(QString::fromStdString("point_2_3 level: " + std::to_string(point_2_3)));

        cv::Mat bitwise_and;
        cv::bitwise_and(source, source, bitwise_and, mask);
        cv::Mat cvtcolor;
        cv::cvtColor(bitwise_and, cvtcolor, cv::COLOR_BGR2HSV);
        cv::Mat inrange;
        cv::inRange(cvtcolor, cv::Scalar(point_1_1, point_1_2, point_1_3), cv::Scalar(point_2_1, point_2_2, point_2_3), inrange);
//        cv::inRange(cvtcolor, cv::Scalar(0, 0, 255 - 105), cv::Scalar(255, 105, 255), inrange);
    //    inrange.setTo(255, mask > 0);
        result = double(cv::countNonZero(inrange > countNonZero_inrange)) / double(cv::countNonZero(mask)) * 100 * correct;

        cv::resize(source, source, cv::Size(), std::stoi(UtilitesClass::GetValueFromMap(AllSettingsMap, "render_size")) / 80.0,
                   std::stoi(UtilitesClass::GetValueFromMap(AllSettingsMap, "render_size")) / 80.0, cv::INTER_NEAREST);
        cv::namedWindow("source", cv::WINDOW_AUTOSIZE);
        cv::imshow("source", source);

        cv::Mat final;
        cv::resize(inrange, final, cv::Size(), std::stoi(UtilitesClass::GetValueFromMap(AllSettingsMap, "render_size")) / 80.0,
                   std::stoi(UtilitesClass::GetValueFromMap(AllSettingsMap, "render_size")) / 80.0, cv::INTER_NEAREST);
        cv::namedWindow("final", cv::WINDOW_AUTOSIZE);
        cv::imshow("final", final);
    }
    if(render_type == "debug"){

        int alarm = ui->alarm_horizontalSlider->value();
        ui->alarm_info->setText(QString::fromStdString("Alarm level: " + std::to_string(alarm)));
        double correct = ui->correct_horizontalSlider->value() / 50.0;
        ui->correct_info->setText(QString::fromStdString("Correct level: " + std::to_string(correct)));

        int countNonZero_inrange = ui->zero_inrange_horizontalSlider->value();
        ui->countnotzerol_info->setText(QString::fromStdString("CountNOotZero level: " + std::to_string(countNonZero_inrange)));

        int point_1_1 = ui->point_1_1_horizontalSlider->value();
        ui->point_1_1_info->setText(QString::fromStdString("point_1_1 level: " + std::to_string(point_1_1)));
        int point_1_2 = ui->point_1_2_horizontalSlider->value();
        ui->point_1_2_info->setText(QString::fromStdString("point_1_2 level: " + std::to_string(point_1_2)));
        int point_1_3 = ui->point_1_3_horizontalSlider->value();
        ui->point_1_3_info->setText(QString::fromStdString("point_1_3 level: " + std::to_string(point_1_3)));
        int point_2_1 = ui->point_2_1_horizontalSlider->value();
        ui->point_2_1_info->setText(QString::fromStdString("point_2_1 level: " + std::to_string(point_2_1)));
        int point_2_2 = ui->point_2_2_horizontalSlider->value();
        ui->point_2_2_info->setText(QString::fromStdString("point_2_2 level: " + std::to_string(point_2_2)));
        int point_2_3 = ui->point_2_3_horizontalSlider->value();
        ui->point_2_3_info->setText(QString::fromStdString("point_2_3 level: " + std::to_string(point_2_3)));

        cv::Mat image_source = cv::imread(UtilitesClass::GetValueFromMap(AllSettingsMap, "alias_cam") + ".jpg", cv::IMREAD_COLOR);
        cv::Mat mask = cv::imread(UtilitesClass::GetValueFromMap(AllSettingsMap, "mask_cam"), 0);
        cv::Mat bitwise_and;
        cv::bitwise_and(image_source, image_source, bitwise_and, mask);
        cv::Mat cvtcolor;
        cv::cvtColor(bitwise_and, cvtcolor, cv::COLOR_BGR2HSV);
        cv::Mat inrange;
        cv::inRange(cvtcolor, cv::Scalar(point_1_1, point_1_2, point_1_3), cv::Scalar(point_2_1, point_2_2, point_2_3), inrange);
//        cv::inRange(cvtcolor, cv::Scalar(0, 0, 255 - 105), cv::Scalar(255, 105, 255), inrange);
    //    inrange.setTo(255, mask > 0);
        result = double(cv::countNonZero(inrange > countNonZero_inrange)) / double(cv::countNonZero(mask)) * 100 * correct;



        cv::Mat final;
        cv::resize(inrange, final, cv::Size(), std::stoi(UtilitesClass::GetValueFromMap(AllSettingsMap, "render_size")) / 80.0,
                   std::stoi(UtilitesClass::GetValueFromMap(AllSettingsMap, "render_size")) / 80.0, cv::INTER_NEAREST);
        cv::putText(final, UtilitesClass::GetLocalTime(),
                    cv::Point(0, 25), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
        cv::putText(final, UtilitesClass::GetValueFromMap(AllSettingsMap, "ip_cam") + " | " + UtilitesClass::GetValueFromMap(AllSettingsMap, "alias_cam"),
                    cv::Point(0, 75), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
        if(result > alarm){
            cv::putText(final, std::to_string(result) + "%", cv::Point(0, 125), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(255, 255, 255), 2);
        }
        else {
            cv::putText(final, std::to_string(result) + "%", cv::Point(0, 125), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(128, 128, 128), 1);
        }
        cv::namedWindow("render", cv::WINDOW_AUTOSIZE);
        cv::imshow("render", final);
        cv::waitKey(1);
        cv::Mat src = image_source.clone();
        cv::resize(src, src, cv::Size(), std::stoi(UtilitesClass::GetValueFromMap(AllSettingsMap, "render_size")) / 80.0,
                   std::stoi(UtilitesClass::GetValueFromMap(AllSettingsMap, "render_size")) / 80.0, cv::INTER_NEAREST);
        cv::namedWindow("source", cv::WINDOW_AUTOSIZE);
        cv::imshow("source", src);
        cv::waitKey(1);



        ui->label_time->setText(QString::fromStdString(UtilitesClass::GetLocalTime()));
        ui->label_info->setText(QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettingsMap, "ip_cam") + " | " + UtilitesClass::GetValueFromMap(AllSettingsMap, "alias_cam")));
        QString danger = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #FF0350,stop: 0.4999 #FF0020,stop: 0.5 #FF0019,stop: 1 #FF0000 );border-bottom-right-radius: 5px;border-bottom-left-radius: 5px;border: .px solid black;}";
        QString safe= "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #78d,stop: 0.4999 #46a,stop: 0.5 #45a,stop: 1 #238 );border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;border: 1px solid black;}";
        if(result > alarm)
            ui->progressBar->setStyleSheet(danger);
        else
            ui->progressBar->setStyleSheet(safe);
        ui->progressBar->setValue(result);
        ui->lcdNumber->display(result);

        UtilitesClass::PrintValueToConsole("RESULT IS : " + std::to_string(result) + "%");
        if (Playing){
            Sleep(100);
            on_START_btn_clicked();
        }
    }
    if (render_type == "source"){
    }
    if (render_type == "final"){
    }
    if (render_type == "extended"){
        cv::Mat image_source = cv::imread(UtilitesClass::GetValueFromMap(AllSettingsMap, "alias_cam") + ".jpg", cv::IMREAD_COLOR);
        cv::Mat mask = cv::imread(UtilitesClass::GetValueFromMap(AllSettingsMap, "mask_cam"), 0);
        cv::Mat bitwise_and;
        cv::bitwise_and(image_source, image_source, bitwise_and, mask);
        cv::Mat cvtcolor;
        cv::cvtColor(bitwise_and, cvtcolor, cv::COLOR_BGR2HSV);
        cv::Mat inrange;
        cv::inRange(cvtcolor, cv::Scalar(0, 0, 255 - std::stoi((UtilitesClass::GetValueFromMap(AllSettingsMap, "sensetivity_cam")))),
                    cv::Scalar(255, std::stoi((UtilitesClass::GetValueFromMap(AllSettingsMap, "sensetivity_cam"))) , 255), inrange);
    //    inrange.setTo(255, mask > 0);
        result = double(cv::countNonZero(inrange > 120)) / double(cv::countNonZero(mask)) * 100 * std::stod(UtilitesClass::GetValueFromMap(AllSettingsMap, "correct_coefficient"));

        cv::Mat final;
        cv::resize(inrange, final, cv::Size(), std::stoi(UtilitesClass::GetValueFromMap(AllSettingsMap, "render_size")) / 80.0,
                   std::stoi(UtilitesClass::GetValueFromMap(AllSettingsMap, "render_size")) / 80.0, cv::INTER_LINEAR);
        cv::putText(final, UtilitesClass::GetLocalTime(),
                    cv::Point(150, 50), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);

        cv::putText(final, UtilitesClass::GetValueFromMap(AllSettingsMap, "ip_cam") + " | " + UtilitesClass::GetValueFromMap(AllSettingsMap, "alias_cam"),
                    cv::Point(150, 100), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
        if(result > std::stoi((UtilitesClass::GetValueFromMap(AllSettingsMap, "alarm_level")))){
            cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(255, 255, 255), 2);
        }
        else {
            cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(128, 128, 128), 1);
        }
        cv::namedWindow("render", cv::WINDOW_AUTOSIZE);
        cv::imshow("render", final);
        cv::waitKey(1);

        cv::Mat src = image_source.clone();
        cv::resize(src, src, cv::Size(), std::stoi(UtilitesClass::GetValueFromMap(AllSettingsMap, "render_size")) / 80.0,
                   std::stoi(UtilitesClass::GetValueFromMap(AllSettingsMap, "render_size")) / 80.0, cv::INTER_LINEAR);
        cv::namedWindow("source", cv::WINDOW_AUTOSIZE);
        cv::imshow("source", src);
        cv::waitKey(1);



        ui->label_time->setText(QString::fromStdString(UtilitesClass::GetLocalTime()));
        ui->label_info->setText(QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettingsMap, "ip_cam") + " | " + UtilitesClass::GetValueFromMap(AllSettingsMap, "alias_cam")));
        QString danger = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #FF0350,stop: 0.4999 #FF0020,stop: 0.5 #FF0019,stop: 1 #FF0000 );border-bottom-right-radius: 5px;border-bottom-left-radius: 5px;border: .px solid black;}";
        QString safe= "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #78d,stop: 0.4999 #46a,stop: 0.5 #45a,stop: 1 #238 );border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;border: 1px solid black;}";
        if(result > std::stoi((UtilitesClass::GetValueFromMap(AllSettingsMap, "alarm_level"))))
            ui->progressBar->setStyleSheet(danger);
        else
            ui->progressBar->setStyleSheet(safe);
        ui->progressBar->setValue(result);
        ui->lcdNumber->display(result);
        UtilitesClass::PrintValueToConsole("RESULT IS : " + std::to_string(result) + "%");
    }
    if (render_type == "all"){
    }

    if (Playing){
        Sleep(100);
        on_START_btn_clicked();
    }
}



void UtilitesClass::PrintValueToConsole(std::string Value)
{
    std::cout << Value << std::endl;
};



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
    time_t t = time(NULL);
    return asctime(localtime(&t));
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
    return value->toPlainText().toStdString();
};
std::string UtilitesClass::GetConvertedQt_obj(QComboBox *value) {
    return value->currentText().toStdString();
};
std::string UtilitesClass::GetConvertedQt_obj(QSlider *value) {
    return std::to_string(value->value());
};
