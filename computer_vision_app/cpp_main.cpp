#include "cpp_main.h"



/********** main **********/
int main(int argc, char *argv[])
{
    try {
        QApplication a(argc, argv);
        a.setStyle("fushion");
        UiWidgetClass w;
        w.show();
        return a.exec();
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}
/********** main **********/



/********** UiWidgetClass **********/
UiWidgetClass::UiWidgetClass(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainClass)
{
    try {
        ui->setupUi(this);
        Tray();
        AutoLogin();
        AutoImport();
        AutoPlay();
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

UiWidgetClass::~UiWidgetClass()
{
    try {
        delete ui;
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void UiWidgetClass::on_Login_Login_pushButton_clicked()
{
    try {
        auto login = ui->Login_Login_lineEdit->text().toStdString();
        auto password = ui->Password_Login_lineEdit->text().toStdString();
        if (login == "admin" and password == "admin") {
            UtilitesClass::PrintValueToConsole("admin access denied");
            if (ui->AutoLogin_Login_checkBox->isChecked()) {
                SaveOrDeleteAutoLogin(true);
            }
            ui->CV_tab->setDisabled(false);
            ui->Login_Login_lineEdit->setText("");
            ui->Password_Login_lineEdit->setText("");
            ui->Description_Login_label->setText("admin access denied");
        } else if (login == "user" and password == "user") {
            UtilitesClass::PrintValueToConsole("user access denied");
            if (ui->AutoLogin_Login_checkBox->isChecked()) {
                SaveOrDeleteAutoLogin(true);
            }
            ui->CV_tab->setDisabled(true);
            ui->Login_Login_lineEdit->setText("");
            ui->Password_Login_lineEdit->setText("");
            ui->Description_Login_label->setText("user access denied");
        } else {
            UtilitesClass::PrintValueToConsole("access not denied");
            ui->CV_tab->setDisabled(true);
            ui->Login_Login_lineEdit->setText("");
            ui->Password_Login_lineEdit->setText("");
            ui->Description_Login_label->setText("access not denied");
        };
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void UiWidgetClass::on_Logout_Login_pushButton_clicked()
{
    try {
        SaveOrDeleteAutoLogin(false);
        UtilitesClass::PrintValueToConsole("logout");
        ui->Login_Login_lineEdit->setText("");
        ui->Password_Login_lineEdit->setText("");
        ui->Description_Login_label->setText("...");
        ui->CV_tab->setDisabled(true);
        ui->AutoLogin_Login_checkBox->setChecked(false);
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void UiWidgetClass::AutoLogin()
{
    try {
        QFile file("login.json");
        if (!file.open( QIODevice::ReadOnly)) {
            std::cerr << "Error: unable to open a file" << std::endl;
            on_Logout_Login_pushButton_clicked();
        } else {
            ui->AutoLogin_Login_checkBox->setChecked(true);
            QByteArray data = file.readAll();
            QJsonDocument document;
            document = document.fromJson(data);

            std::map<std::string, QLineEdit*> QLineEditMap = {
                { "Login", ui->Login_Login_lineEdit },
                { "Password", ui->Password_Login_lineEdit },
            };
            for (auto& elem : QLineEditMap){
                UtilitesClass::SetConvertedQt_obj(elem.second, document.object()[QString::fromStdString(elem.first)].toString());
            }
            on_Login_Login_pushButton_clicked();
        }
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void UiWidgetClass::SaveOrDeleteAutoLogin(bool save)
{
    try {
        if (save) {
            UtilitesClass::PrintValueToConsole("save");
            try {
                QJsonObject json;
                std::map<std::string, std::string> QLineEditMap = {
                    { "Login", ui->Login_Login_lineEdit->text().toStdString() },
                    { "Password", ui->Password_Login_lineEdit->text().toStdString() },
                };
                for (auto& elem : QLineEditMap)
                    json[QString::fromStdString(elem.first)] = QString::fromStdString(elem.second);
                QJsonDocument document;
                document.setObject(json);
                QFile file("login.json");
                if (!file.open(QIODevice::WriteOnly)) {
                    std::cerr << "Error: unable to open a file" << std::endl;
                } else {
                    if (!file.write(document.toJson())) {
                        std::cerr << "Error: unable to write a file" << std::endl;
                    }
                }
            }  catch (std::string error) {
                UtilitesClass::WriteTextErrorToLogFile(error);
            }
        } else {
            UtilitesClass::PrintValueToConsole("delete");
            try {
                remove("login.json");
            }  catch (std::string error) {
                UtilitesClass::WriteTextErrorToLogFile(error);
            }
        }
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void UiWidgetClass::Tray()
{
    try {
        trayIcon = new QSystemTrayIcon(this);
        trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));
        trayIcon->setToolTip("SMART" "\n" "Приложение с определённым функционалом.");
        QMenu * menu = new QMenu(this);
        QAction * viewWindow = new QAction("Развернуть окно", this);
        QAction * quitAction = new QAction("Выход", this);
        connect(viewWindow, SIGNAL(triggered()), this, SLOT(show()));
        connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));
        menu->addAction(viewWindow);
        menu->addAction(quitAction);
        trayIcon->setContextMenu(menu);
        trayIcon->show();
        connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
                this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void UiWidgetClass::closeEvent(QCloseEvent *event)
{
    try {
        if(this->isVisible()){
            event->ignore();
            this->hide();
            QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
            trayIcon->showMessage("SMART",
                                  "Приложение свернуто в трей. Развернуть приложение - левая кнопка мыши. Для закрытия нажмите правой клавишей мыши.",
                                  icon, 3000);
        }
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void UiWidgetClass::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    try {
        switch (reason){
        case QSystemTrayIcon::Trigger:
            if(!this->isVisible()){
                this->show();
            } else {
                this->hide();
            }
            break;
        default:
            break;
        }
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void UiWidgetClass::on_START_CV_16_btn_clicked()
{
    try {
        on_STOP_CV_16_btn_clicked();
        Playing = true;
        ui->Playing_radioButton->setChecked(Playing);
        QCoreApplication::processEvents();
        std::pair<std::map<std::string,std::string>, std::vector<std::map<std::string,std::string>>> SettingsPair = GetMapsFromSettings();
        QCoreApplication::processEvents();
        startAnalyse(SettingsPair.first, SettingsPair.second, ui);
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void UiWidgetClass::on_STOP_CV_16_btn_clicked()
{
    try {
        Playing = false;
        cv::destroyAllWindows();
        ui->Playing_radioButton->setChecked(Playing);
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void UiWidgetClass::on_TRAY_CV_16_btn_clicked()
{
    try {
        this->close();
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void UiWidgetClass::on_CamShot_CV_16_DEBUG_pushButton_clicked()
{
    try {
        std::map <std::string,std::string> CamShotSettingsMap = {
            { "IpCamShot", UtilitesClass::GetConvertedQt_obj(ui->IpCamShot_CV_16_DEBUG_lineEdit) },
            { "PortCamShot", UtilitesClass::GetConvertedQt_obj(ui->PortCamShot_CV_16_DEBUG_spinBox) },
            { "LoginCamShot", UtilitesClass::GetConvertedQt_obj(ui->LoginCamShot_CV_16_DEBUG_lineEdit) },
            { "PasswordCamShot", UtilitesClass::GetConvertedQt_obj(ui->PasswordCamShot_CV_16_DEBUG_lineEdit) },
            { "ImageNameShot", UtilitesClass::GetConvertedQt_obj(ui->ImageNameShot_CV_16_DEBUG_lineEdit) },
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
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void UiWidgetClass::on_ExportSettings_CV_16_DEBUG_pushButton_clicked()
{
    try {
        std::map <std::string,std::string> AllSettingsMap;
        std::pair<std::map<std::string,std::string>, std::vector<std::map<std::string,std::string>>> SettingsPair =
                GetMapsFromSettings();
        for (auto& OneSettings : SettingsPair.first) {
            AllSettingsMap[OneSettings.first] = OneSettings.second;
        }
        int loop = 0;
        for (auto& OneVector : SettingsPair.second) {
            loop++;
            for (auto& OneSettings : OneVector) {
                AllSettingsMap[OneSettings.first+"_"+std::to_string(loop)] = OneSettings.second;
            }
        }
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
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void UiWidgetClass::on_ImportSettings_CV_16_DEBUG_pushButton_clicked()
{
    try {
        QFile file("settings.json");
        if (!file.open( QIODevice::ReadOnly)) {
            std::cerr << "Error: unable to open a file" << std::endl;

        } else {
            QByteArray data = file.readAll();
            QJsonDocument document;
            document = document.fromJson(data);
            std::map<std::string, QCheckBox*> QCheckBoxMap = {
                { "WriteNowSql", ui->WriteNowSql_CV_16_SQL_checkBox },
                { "WriteDataSql", ui->WriteDataSql_CV_16_SQL_checkBox },

                { "AutoPlay", ui->AutoPlay_CV_16_DEBUG_checkBox },
                { "AutoImport", ui->AutoImport_CV_16_DEBUG_checkBox },
                { "WriteToConsole", ui->WriteToConsole_CV_16_DEBUG_checkBox },
                { "WriteToText", ui->WriteToText_CV_16_DEBUG_checkBox },
                { "WriteToWidget", ui->WriteToWidget_CV_16_DEBUG_checkBox },
                { "RuntimeUpdateParams", ui->RuntimeUpdateParams_CV_16_DEBUG_checkBox },
                { "UseSQLPort", ui->UseSQLPort_CV_16_DEBUG_checkBox },

                { "ActiveCam_1", ui->ActiveCam_CV_16_checkBox_1 },
                { "ActiveCam_2", ui->ActiveCam_CV_16_checkBox_2 },
                { "ActiveCam_3", ui->ActiveCam_CV_16_checkBox_3 },
                { "ActiveCam_4", ui->ActiveCam_CV_16_checkBox_4 },
                { "ActiveCam_5", ui->ActiveCam_CV_16_checkBox_5 },
                { "ActiveCam_6", ui->ActiveCam_CV_16_checkBox_6 },
                { "ActiveCam_7", ui->ActiveCam_CV_16_checkBox_7 },
                { "ActiveCam_8", ui->ActiveCam_CV_16_checkBox_8 },
                { "ActiveCam_9", ui->ActiveCam_CV_16_checkBox_9 },
                { "ActiveCam_10", ui->ActiveCam_CV_16_checkBox_10 },
            };
            for (auto& elem : QCheckBoxMap){
                UtilitesClass::SetConvertedQt_obj(elem.second, document.object()[QString::fromStdString(elem.first)].toString());
            }
            std::map<std::string, QSpinBox*> QSpinBoxMap = {
                { "PortCam", ui->PortCam_CV_16_spinBox },
                { "PortSqlServer", ui->PortSqlServer_CV_16_SQL_spinBox },
                { "AlarmLevel_1", ui->AlarmLevel_CV_16_spinBox_1 },
                { "AlarmLevel_2", ui->AlarmLevel_CV_16_spinBox_2 },
                { "AlarmLevel_3", ui->AlarmLevel_CV_16_spinBox_3 },
                { "AlarmLevel_4", ui->AlarmLevel_CV_16_spinBox_4 },
                { "AlarmLevel_5", ui->AlarmLevel_CV_16_spinBox_5 },
                { "AlarmLevel_6", ui->AlarmLevel_CV_16_spinBox_6 },
                { "AlarmLevel_7", ui->AlarmLevel_CV_16_spinBox_7 },
                { "AlarmLevel_8", ui->AlarmLevel_CV_16_spinBox_8 },
                { "AlarmLevel_9", ui->AlarmLevel_CV_16_spinBox_9 },
                { "AlarmLevel_10", ui->AlarmLevel_CV_16_spinBox_10 },
                { "NullLevel_1", ui->NullLevel_CV_16_spinBox_1 },
                { "NullLevel_2", ui->NullLevel_CV_16_spinBox_2 },
                { "NullLevel_3", ui->NullLevel_CV_16_spinBox_3 },
                { "NullLevel_4", ui->NullLevel_CV_16_spinBox_4 },
                { "NullLevel_5", ui->NullLevel_CV_16_spinBox_5 },
                { "NullLevel_6", ui->NullLevel_CV_16_spinBox_6 },
                { "NullLevel_7", ui->NullLevel_CV_16_spinBox_7 },
                { "NullLevel_8", ui->NullLevel_CV_16_spinBox_8 },
                { "NullLevel_9", ui->NullLevel_CV_16_spinBox_9 },
                { "NullLevel_10", ui->NullLevel_CV_16_spinBox_10 },
                { "BrightLevel_1", ui->BrightLevel_CV_16_spinBox_1 },
                { "BrightLevel_2", ui->BrightLevel_CV_16_spinBox_2 },
                { "BrightLevel_3", ui->BrightLevel_CV_16_spinBox_3 },
                { "BrightLevel_4", ui->BrightLevel_CV_16_spinBox_4 },
                { "BrightLevel_5", ui->BrightLevel_CV_16_spinBox_5 },
                { "BrightLevel_6", ui->BrightLevel_CV_16_spinBox_6 },
                { "BrightLevel_7", ui->BrightLevel_CV_16_spinBox_7 },
                { "BrightLevel_8", ui->BrightLevel_CV_16_spinBox_8 },
                { "BrightLevel_9", ui->BrightLevel_CV_16_spinBox_9 },
                { "BrightLevel_10", ui->BrightLevel_CV_16_spinBox_10 },
                { "InRangeSetFrom_1", ui->InRangeSetFrom_CV_16_spinBox_1 },
                { "InRangeSetFrom_2", ui->InRangeSetFrom_CV_16_spinBox_2 },
                { "InRangeSetFrom_3", ui->InRangeSetFrom_CV_16_spinBox_3 },
                { "InRangeSetFrom_4", ui->InRangeSetFrom_CV_16_spinBox_4 },
                { "InRangeSetFrom_5", ui->InRangeSetFrom_CV_16_spinBox_5 },
                { "InRangeSetFrom_6", ui->InRangeSetFrom_CV_16_spinBox_6 },
                { "InRangeSetFrom_7", ui->InRangeSetFrom_CV_16_spinBox_7 },
                { "InRangeSetFrom_8", ui->InRangeSetFrom_CV_16_spinBox_8 },
                { "InRangeSetFrom_9", ui->InRangeSetFrom_CV_16_spinBox_9 },
                { "InRangeSetFrom_10", ui->InRangeSetFrom_CV_16_spinBox_10 },
                { "InRangeSetTo_1", ui->InRangeSetTo_CV_16_spinBox_1 },
                { "InRangeSetTo_2", ui->InRangeSetTo_CV_16_spinBox_2 },
                { "InRangeSetTo_3", ui->InRangeSetTo_CV_16_spinBox_3 },
                { "InRangeSetTo_4", ui->InRangeSetTo_CV_16_spinBox_4 },
                { "InRangeSetTo_5", ui->InRangeSetTo_CV_16_spinBox_5 },
                { "InRangeSetTo_6", ui->InRangeSetTo_CV_16_spinBox_6 },
                { "InRangeSetTo_7", ui->InRangeSetTo_CV_16_spinBox_7 },
                { "InRangeSetTo_8", ui->InRangeSetTo_CV_16_spinBox_8 },
                { "InRangeSetTo_9", ui->InRangeSetTo_CV_16_spinBox_9 },
                { "InRangeSetTo_10", ui->InRangeSetTo_CV_16_spinBox_10 },
                { "CountNotZero_1", ui->CountNotZero_CV_16_spinBox_1 },
                { "CountNotZero_2", ui->CountNotZero_CV_16_spinBox_2 },
                { "CountNotZero_3", ui->CountNotZero_CV_16_spinBox_3 },
                { "CountNotZero_4", ui->CountNotZero_CV_16_spinBox_4 },
                { "CountNotZero_5", ui->CountNotZero_CV_16_spinBox_5 },
                { "CountNotZero_6", ui->CountNotZero_CV_16_spinBox_6 },
                { "CountNotZero_7", ui->CountNotZero_CV_16_spinBox_7 },
                { "CountNotZero_8", ui->CountNotZero_CV_16_spinBox_8 },
                { "CountNotZero_9", ui->CountNotZero_CV_16_spinBox_9 },
                { "CountNotZero_10", ui->CountNotZero_CV_16_spinBox_10 },
                { "Point_1_1_1", ui->Point_1_1_CV_16_spinBox_1 },
                { "Point_1_1_2", ui->Point_1_1_CV_16_spinBox_2 },
                { "Point_1_1_3", ui->Point_1_1_CV_16_spinBox_3 },
                { "Point_1_1_4", ui->Point_1_1_CV_16_spinBox_4 },
                { "Point_1_1_5", ui->Point_1_1_CV_16_spinBox_5 },
                { "Point_1_1_6", ui->Point_1_1_CV_16_spinBox_6 },
                { "Point_1_1_7", ui->Point_1_1_CV_16_spinBox_7 },
                { "Point_1_1_8", ui->Point_1_1_CV_16_spinBox_8 },
                { "Point_1_1_9", ui->Point_1_1_CV_16_spinBox_9 },
                { "Point_1_1_10", ui->Point_1_1_CV_16_spinBox_10 },
                { "Point_1_2_1", ui->Point_1_2_CV_16_spinBox_1 },
                { "Point_1_2_2", ui->Point_1_2_CV_16_spinBox_2 },
                { "Point_1_2_3", ui->Point_1_2_CV_16_spinBox_3 },
                { "Point_1_2_4", ui->Point_1_2_CV_16_spinBox_4 },
                { "Point_1_2_5", ui->Point_1_2_CV_16_spinBox_5 },
                { "Point_1_2_6", ui->Point_1_2_CV_16_spinBox_6 },
                { "Point_1_2_7", ui->Point_1_2_CV_16_spinBox_7 },
                { "Point_1_2_8", ui->Point_1_2_CV_16_spinBox_8 },
                { "Point_1_2_9", ui->Point_1_2_CV_16_spinBox_9 },
                { "Point_1_2_10", ui->Point_1_2_CV_16_spinBox_10 },
                { "Point_1_3_1", ui->Point_1_3_CV_16_spinBox_1 },
                { "Point_1_3_2", ui->Point_1_3_CV_16_spinBox_2 },
                { "Point_1_3_3", ui->Point_1_3_CV_16_spinBox_3 },
                { "Point_1_3_4", ui->Point_1_3_CV_16_spinBox_4 },
                { "Point_1_3_5", ui->Point_1_3_CV_16_spinBox_5 },
                { "Point_1_3_6", ui->Point_1_3_CV_16_spinBox_6 },
                { "Point_1_3_7", ui->Point_1_3_CV_16_spinBox_7 },
                { "Point_1_3_8", ui->Point_1_3_CV_16_spinBox_8 },
                { "Point_1_3_9", ui->Point_1_3_CV_16_spinBox_9 },
                { "Point_1_3_10", ui->Point_1_3_CV_16_spinBox_10 },
                { "Point_2_1_1", ui->Point_2_1_CV_16_spinBox_1 },
                { "Point_2_1_2", ui->Point_2_1_CV_16_spinBox_2 },
                { "Point_2_1_3", ui->Point_2_1_CV_16_spinBox_3 },
                { "Point_2_1_4", ui->Point_2_1_CV_16_spinBox_4 },
                { "Point_2_1_5", ui->Point_2_1_CV_16_spinBox_5 },
                { "Point_2_1_6", ui->Point_2_1_CV_16_spinBox_6 },
                { "Point_2_1_7", ui->Point_2_1_CV_16_spinBox_7 },
                { "Point_2_1_8", ui->Point_2_1_CV_16_spinBox_8 },
                { "Point_2_1_9", ui->Point_2_1_CV_16_spinBox_9 },
                { "Point_2_1_10", ui->Point_2_1_CV_16_spinBox_10 },
                { "Point_2_2_1", ui->Point_2_2_CV_16_spinBox_1 },
                { "Point_2_2_2", ui->Point_2_2_CV_16_spinBox_2 },
                { "Point_2_2_3", ui->Point_2_2_CV_16_spinBox_3 },
                { "Point_2_2_4", ui->Point_2_2_CV_16_spinBox_4 },
                { "Point_2_2_5", ui->Point_2_2_CV_16_spinBox_5 },
                { "Point_2_2_6", ui->Point_2_2_CV_16_spinBox_6 },
                { "Point_2_2_7", ui->Point_2_2_CV_16_spinBox_7 },
                { "Point_2_2_8", ui->Point_2_2_CV_16_spinBox_8 },
                { "Point_2_2_9", ui->Point_2_2_CV_16_spinBox_9 },
                { "Point_2_2_10", ui->Point_2_2_CV_16_spinBox_10 },
                { "Point_2_3_1", ui->Point_2_3_CV_16_spinBox_1 },
                { "Point_2_3_2", ui->Point_2_3_CV_16_spinBox_2 },
                { "Point_2_3_3", ui->Point_2_3_CV_16_spinBox_3 },
                { "Point_2_3_4", ui->Point_2_3_CV_16_spinBox_4 },
                { "Point_2_3_5", ui->Point_2_3_CV_16_spinBox_5 },
                { "Point_2_3_6", ui->Point_2_3_CV_16_spinBox_6 },
                { "Point_2_3_7", ui->Point_2_3_CV_16_spinBox_7 },
                { "Point_2_3_8", ui->Point_2_3_CV_16_spinBox_8 },
                { "Point_2_3_9", ui->Point_2_3_CV_16_spinBox_9 },
                { "Point_2_3_10", ui->Point_2_3_CV_16_spinBox_10 },
            };
            for (auto& elem : QSpinBoxMap){
                UtilitesClass::SetConvertedQt_obj(elem.second, document.object()[QString::fromStdString(elem.first)].toString());
            }
            std::map<std::string, QDoubleSpinBox*> QDoubleSpinBoxMap = {
                { "TimeDelay", ui->TimeDelay_CV_16_DEBUG_doubleSpinBox },

                { "CorrectCoefficient_1", ui->CorrectCoefficient_CV_16_doubleSpinBox_1 },
                { "CorrectCoefficient_2", ui->CorrectCoefficient_CV_16_doubleSpinBox_2 },
                { "CorrectCoefficient_3", ui->CorrectCoefficient_CV_16_doubleSpinBox_3 },
                { "CorrectCoefficient_4", ui->CorrectCoefficient_CV_16_doubleSpinBox_4 },
                { "CorrectCoefficient_5", ui->CorrectCoefficient_CV_16_doubleSpinBox_5 },
                { "CorrectCoefficient_6", ui->CorrectCoefficient_CV_16_doubleSpinBox_6 },
                { "CorrectCoefficient_7", ui->CorrectCoefficient_CV_16_doubleSpinBox_7 },
                { "CorrectCoefficient_8", ui->CorrectCoefficient_CV_16_doubleSpinBox_8 },
                { "CorrectCoefficient_9", ui->CorrectCoefficient_CV_16_doubleSpinBox_9 },
                { "CorrectCoefficient_10", ui->CorrectCoefficient_CV_16_doubleSpinBox_10 },
            };
            for (auto& elem : QDoubleSpinBoxMap){
                UtilitesClass::SetConvertedQt_obj(elem.second, document.object()[QString::fromStdString(elem.first)].toString());
            }
            std::map<std::string, QLineEdit*> QLineEditMap = {
                { "ProtocolCam", ui->ProtocolCam_CV_16_lineEdit },
                { "LoginCam", ui->LoginCam_CV_16_lineEdit },
                { "PasswordCam", ui->PasswordCam_CV_16_lineEdit },
                { "ResourcesCam", ui->ResourcesPath_CV_16_lineEdit },

                { "IpSqlServer", ui->IpSqlServer_CV_16_SQL_lineEdit },
                { "ServerNameSql", ui->ServerNameSql_CV_16_SQL_lineEdit },
                { "DatabaseSql", ui->DatabaseSql_CV_16_SQL_lineEdit },
                { "UserSql", ui->UserSql_CV_16_SQL_lineEdit },
                { "PasswordSql", ui->PasswordSql_CV_16_SQL_lineEdit },
                { "TableNowSql", ui->TableNowSql_CV_16_SQL_lineEdit },
                { "RowsNowSql_1", ui->RowsNowSql_CV_16_SQL_lineEdit_1 },
                { "RowsNowSql_2", ui->RowsNowSql_CV_16_SQL_lineEdit_2 },
                { "RowsNowSql_3", ui->RowsNowSql_CV_16_SQL_lineEdit_3 },
                { "RowsNowSql_4", ui->RowsNowSql_CV_16_SQL_lineEdit_4 },
                { "TableDataSql", ui->TableDataSql_CV_16_SQL_lineEdit },
                { "RowsDataSql_1", ui->RowsDataSql_CV_16_SQL_lineEdit_1 },
                { "RowsDataSql_2", ui->RowsDataSql_CV_16_SQL_lineEdit_2 },
                { "RowsDataSql_3", ui->RowsDataSql_CV_16_SQL_lineEdit_3 },
                { "RowsDataSql_4", ui->RowsDataSql_CV_16_SQL_lineEdit_4 },

                { "AliasCam_1", ui->AliasCam_CV_16_lineEdit_1 },
                { "AliasCam_2", ui->AliasCam_CV_16_lineEdit_2 },
                { "AliasCam_3", ui->AliasCam_CV_16_lineEdit_3 },
                { "AliasCam_4", ui->AliasCam_CV_16_lineEdit_4 },
                { "AliasCam_5", ui->AliasCam_CV_16_lineEdit_5 },
                { "AliasCam_6", ui->AliasCam_CV_16_lineEdit_6 },
                { "AliasCam_7", ui->AliasCam_CV_16_lineEdit_7 },
                { "AliasCam_8", ui->AliasCam_CV_16_lineEdit_8 },
                { "AliasCam_9", ui->AliasCam_CV_16_lineEdit_9 },
                { "AliasCam_10", ui->AliasCam_CV_16_lineEdit_10 },
                { "IpCam_1", ui->IpCam_CV_16_lineEdit_1 },
                { "IpCam_2", ui->IpCam_CV_16_lineEdit_2 },
                { "IpCam_3", ui->IpCam_CV_16_lineEdit_3 },
                { "IpCam_4", ui->IpCam_CV_16_lineEdit_4 },
                { "IpCam_5", ui->IpCam_CV_16_lineEdit_5 },
                { "IpCam_6", ui->IpCam_CV_16_lineEdit_6 },
                { "IpCam_7", ui->IpCam_CV_16_lineEdit_7 },
                { "IpCam_8", ui->IpCam_CV_16_lineEdit_8 },
                { "IpCam_9", ui->IpCam_CV_16_lineEdit_9 },
                { "IpCam_10", ui->IpCam_CV_16_lineEdit_10 },
                { "MaskCam_1", ui->MaskCam_CV_16_lineEdit_1 },
                { "MaskCam_2", ui->MaskCam_CV_16_lineEdit_2 },
                { "MaskCam_3", ui->MaskCam_CV_16_lineEdit_3 },
                { "MaskCam_4", ui->MaskCam_CV_16_lineEdit_4 },
                { "MaskCam_5", ui->MaskCam_CV_16_lineEdit_5 },
                { "MaskCam_6", ui->MaskCam_CV_16_lineEdit_6 },
                { "MaskCam_7", ui->MaskCam_CV_16_lineEdit_7 },
                { "MaskCam_8", ui->MaskCam_CV_16_lineEdit_8 },
                { "MaskCam_9", ui->MaskCam_CV_16_lineEdit_9 },
                { "MaskCam_10", ui->MaskCam_CV_16_lineEdit_10 },
            };
            for (auto& elem : QLineEditMap){
                UtilitesClass::SetConvertedQt_obj(elem.second, document.object()[QString::fromStdString(elem.first)].toString());
            }
            std::map<std::string, QComboBox*> QComboBoxMap = {
                { "RenderType", ui->RenderType_CV_16_DEBUG_comboBox },
                { "ComputeType", ui->ComputeType_CV_16_DEBUG_comboBox },
            };
            for (auto& elem : QComboBoxMap){
                UtilitesClass::SetConvertedQt_obj(elem.second, document.object()[QString::fromStdString(elem.first)].toString());
            }
            std::map<std::string, QSlider*> QSliderMap = {
                { "RenderSize", ui->RenderSize_CV_16_DEBUG_horizontalSlider },
            };
            for (auto& elem : QSliderMap){
                UtilitesClass::SetConvertedQt_obj(elem.second, document.object()[QString::fromStdString(elem.first)].toString());
            }
        }
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void UiWidgetClass::on_CV_16_1_Resources_Path_Unlock_pushButton_clicked()
{
    try {
        ui->ResourcesPath_CV_16_lineEdit->setReadOnly(!ui->ResourcesPath_CV_16_lineEdit->isReadOnly());
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

std::pair<std::map<std::string,std::string>, std::vector<std::map<std::string,std::string>>> UiWidgetClass::GetMapsFromSettings()
{
    try {
        std::map <std::string,std::string> AllSettingsMap = {
            { "AutoPlay", UtilitesClass::GetConvertedQt_obj(ui->AutoPlay_CV_16_DEBUG_checkBox) },
            { "AutoImport", UtilitesClass::GetConvertedQt_obj(ui->AutoImport_CV_16_DEBUG_checkBox) },
            { "WriteToConsole", UtilitesClass::GetConvertedQt_obj(ui->WriteToConsole_CV_16_DEBUG_checkBox) },
            { "WriteToText", UtilitesClass::GetConvertedQt_obj(ui->WriteToText_CV_16_DEBUG_checkBox) },
            { "WriteToWidget", UtilitesClass::GetConvertedQt_obj(ui->WriteToWidget_CV_16_DEBUG_checkBox) },
            { "RenderSize", UtilitesClass::GetConvertedQt_obj(ui->RenderSize_CV_16_DEBUG_horizontalSlider) },
            { "RenderType", UtilitesClass::GetConvertedQt_obj(ui->RenderType_CV_16_DEBUG_comboBox) },
            { "ComputeType", UtilitesClass::GetConvertedQt_obj(ui->ComputeType_CV_16_DEBUG_comboBox) },
            { "TimeDelay", UtilitesClass::GetConvertedQt_obj(ui->TimeDelay_CV_16_DEBUG_doubleSpinBox) },
            { "RuntimeUpdateParams", UtilitesClass::GetConvertedQt_obj(ui->RuntimeUpdateParams_CV_16_DEBUG_checkBox) },
            { "UseSQLPort", UtilitesClass::GetConvertedQt_obj(ui->UseSQLPort_CV_16_DEBUG_checkBox) },

            { "ProtocolCam", UtilitesClass::GetConvertedQt_obj(ui->ProtocolCam_CV_16_lineEdit) },
            { "PortCam", UtilitesClass::GetConvertedQt_obj(ui->PortCam_CV_16_spinBox) },
            { "LoginCam", UtilitesClass::GetConvertedQt_obj(ui->LoginCam_CV_16_lineEdit) },
            { "PasswordCam", UtilitesClass::GetConvertedQt_obj(ui->PasswordCam_CV_16_lineEdit) },
            { "ResourcesCam", UtilitesClass::GetConvertedQt_obj(ui->ResourcesPath_CV_16_lineEdit) },

            { "IpSqlServer", UtilitesClass::GetConvertedQt_obj(ui->IpSqlServer_CV_16_SQL_lineEdit) },
            { "ServerNameSql", UtilitesClass::GetConvertedQt_obj(ui->ServerNameSql_CV_16_SQL_lineEdit) },
            { "PortSqlServer", UtilitesClass::GetConvertedQt_obj(ui->PortSqlServer_CV_16_SQL_spinBox) },
            { "DatabaseSql", UtilitesClass::GetConvertedQt_obj(ui->DatabaseSql_CV_16_SQL_lineEdit) },
            { "UserSql", UtilitesClass::GetConvertedQt_obj(ui->UserSql_CV_16_SQL_lineEdit) },
            { "PasswordSql", UtilitesClass::GetConvertedQt_obj(ui->PasswordSql_CV_16_SQL_lineEdit) },
            { "WriteNowSql", UtilitesClass::GetConvertedQt_obj(ui->WriteNowSql_CV_16_SQL_checkBox) },
            { "TableNowSql", UtilitesClass::GetConvertedQt_obj(ui->TableNowSql_CV_16_SQL_lineEdit) },
            { "RowsNowSql_1", UtilitesClass::GetConvertedQt_obj(ui->RowsNowSql_CV_16_SQL_lineEdit_1) },
            { "RowsNowSql_2", UtilitesClass::GetConvertedQt_obj(ui->RowsNowSql_CV_16_SQL_lineEdit_2) },
            { "RowsNowSql_3", UtilitesClass::GetConvertedQt_obj(ui->RowsNowSql_CV_16_SQL_lineEdit_3) },
            { "RowsNowSql_4", UtilitesClass::GetConvertedQt_obj(ui->RowsNowSql_CV_16_SQL_lineEdit_4) },
            { "WriteDataSql", UtilitesClass::GetConvertedQt_obj(ui->WriteDataSql_CV_16_SQL_checkBox) },
            { "TableDataSql", UtilitesClass::GetConvertedQt_obj(ui->TableDataSql_CV_16_SQL_lineEdit) },
            { "RowsDataSql_1", UtilitesClass::GetConvertedQt_obj(ui->RowsDataSql_CV_16_SQL_lineEdit_1) },
            { "RowsDataSql_2", UtilitesClass::GetConvertedQt_obj(ui->RowsDataSql_CV_16_SQL_lineEdit_2) },
            { "RowsDataSql_3", UtilitesClass::GetConvertedQt_obj(ui->RowsDataSql_CV_16_SQL_lineEdit_3) },
            { "RowsDataSql_4", UtilitesClass::GetConvertedQt_obj(ui->RowsDataSql_CV_16_SQL_lineEdit_4) },
        };
        std::vector<std::map<std::string,std::string>> AllSettingsVector =
        {
            {
                { "ActiveCam", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_CV_16_checkBox_1) },
                { "AliasCam", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_CV_16_lineEdit_1) },
                { "IpCam", UtilitesClass::GetConvertedQt_obj(ui->IpCam_CV_16_lineEdit_1) },
                { "MaskCam", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_CV_16_lineEdit_1) },
                { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_CV_16_spinBox_1) },
                { "NullLevel", UtilitesClass::GetConvertedQt_obj(ui->NullLevel_CV_16_spinBox_1) },
                { "BrightLevel", UtilitesClass::GetConvertedQt_obj(ui->BrightLevel_CV_16_spinBox_1) },
                { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_CV_16_doubleSpinBox_1) },
                { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_CV_16_spinBox_1) },
                { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_CV_16_spinBox_1) },
                { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_CV_16_spinBox_1) },
                { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_CV_16_spinBox_1) },
                { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_CV_16_spinBox_1) },
                { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_CV_16_spinBox_1) },
                { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_CV_16_spinBox_1) },
                { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_CV_16_spinBox_1) },
                { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_CV_16_spinBox_1) },
            },
            {
                { "ActiveCam", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_CV_16_checkBox_2) },
                { "AliasCam", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_CV_16_lineEdit_2) },
                { "IpCam", UtilitesClass::GetConvertedQt_obj(ui->IpCam_CV_16_lineEdit_2) },
                { "MaskCam", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_CV_16_lineEdit_2) },
                { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_CV_16_spinBox_2) },
                { "NullLevel", UtilitesClass::GetConvertedQt_obj(ui->NullLevel_CV_16_spinBox_2) },
                { "BrightLevel", UtilitesClass::GetConvertedQt_obj(ui->BrightLevel_CV_16_spinBox_2) },
                { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_CV_16_doubleSpinBox_2) },
                { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_CV_16_spinBox_2) },
                { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_CV_16_spinBox_2) },
                { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_CV_16_spinBox_2) },
                { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_CV_16_spinBox_2) },
                { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_CV_16_spinBox_2) },
                { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_CV_16_spinBox_2) },
                { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_CV_16_spinBox_2) },
                { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_CV_16_spinBox_2) },
                { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_CV_16_spinBox_2) },
            },
            {
                { "ActiveCam", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_CV_16_checkBox_3) },
                { "AliasCam", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_CV_16_lineEdit_3) },
                { "IpCam", UtilitesClass::GetConvertedQt_obj(ui->IpCam_CV_16_lineEdit_3) },
                { "MaskCam", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_CV_16_lineEdit_3) },
                { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_CV_16_spinBox_3) },
                { "NullLevel", UtilitesClass::GetConvertedQt_obj(ui->NullLevel_CV_16_spinBox_3) },
                { "BrightLevel", UtilitesClass::GetConvertedQt_obj(ui->BrightLevel_CV_16_spinBox_3) },
                { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_CV_16_doubleSpinBox_3) },
                { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_CV_16_spinBox_3) },
                { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_CV_16_spinBox_3) },
                { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_CV_16_spinBox_3) },
                { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_CV_16_spinBox_3) },
                { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_CV_16_spinBox_3) },
                { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_CV_16_spinBox_3) },
                { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_CV_16_spinBox_3) },
                { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_CV_16_spinBox_3) },
                { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_CV_16_spinBox_3) },
            },
            {
                { "ActiveCam", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_CV_16_checkBox_4) },
                { "AliasCam", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_CV_16_lineEdit_4) },
                { "IpCam", UtilitesClass::GetConvertedQt_obj(ui->IpCam_CV_16_lineEdit_4) },
                { "MaskCam", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_CV_16_lineEdit_4) },
                { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_CV_16_spinBox_4) },
                { "NullLevel", UtilitesClass::GetConvertedQt_obj(ui->NullLevel_CV_16_spinBox_4) },
                { "BrightLevel", UtilitesClass::GetConvertedQt_obj(ui->BrightLevel_CV_16_spinBox_4) },
                { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_CV_16_doubleSpinBox_4) },
                { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_CV_16_spinBox_4) },
                { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_CV_16_spinBox_4) },
                { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_CV_16_spinBox_4) },
                { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_CV_16_spinBox_4) },
                { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_CV_16_spinBox_4) },
                { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_CV_16_spinBox_4) },
                { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_CV_16_spinBox_4) },
                { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_CV_16_spinBox_4) },
                { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_CV_16_spinBox_4) },
            },
            {
                { "ActiveCam", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_CV_16_checkBox_5) },
                { "AliasCam", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_CV_16_lineEdit_5) },
                { "IpCam", UtilitesClass::GetConvertedQt_obj(ui->IpCam_CV_16_lineEdit_5) },
                { "MaskCam", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_CV_16_lineEdit_5) },
                { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_CV_16_spinBox_5) },
                { "NullLevel", UtilitesClass::GetConvertedQt_obj(ui->NullLevel_CV_16_spinBox_5) },
                { "BrightLevel", UtilitesClass::GetConvertedQt_obj(ui->BrightLevel_CV_16_spinBox_5) },
                { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_CV_16_doubleSpinBox_5) },
                { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_CV_16_spinBox_5) },
                { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_CV_16_spinBox_5) },
                { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_CV_16_spinBox_5) },
                { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_CV_16_spinBox_5) },
                { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_CV_16_spinBox_5) },
                { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_CV_16_spinBox_5) },
                { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_CV_16_spinBox_5) },
                { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_CV_16_spinBox_5) },
                { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_CV_16_spinBox_5) },
            },
            {
                { "ActiveCam", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_CV_16_checkBox_6) },
                { "AliasCam", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_CV_16_lineEdit_6) },
                { "IpCam", UtilitesClass::GetConvertedQt_obj(ui->IpCam_CV_16_lineEdit_6) },
                { "MaskCam", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_CV_16_lineEdit_6) },
                { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_CV_16_spinBox_6) },
                { "NullLevel", UtilitesClass::GetConvertedQt_obj(ui->NullLevel_CV_16_spinBox_6) },
                { "BrightLevel", UtilitesClass::GetConvertedQt_obj(ui->BrightLevel_CV_16_spinBox_6) },
                { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_CV_16_doubleSpinBox_6) },
                { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_CV_16_spinBox_6) },
                { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_CV_16_spinBox_6) },
                { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_CV_16_spinBox_6) },
                { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_CV_16_spinBox_6) },
                { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_CV_16_spinBox_6) },
                { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_CV_16_spinBox_6) },
                { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_CV_16_spinBox_6) },
                { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_CV_16_spinBox_6) },
                { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_CV_16_spinBox_6) },
            },
            {
                { "ActiveCam", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_CV_16_checkBox_7) },
                { "AliasCam", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_CV_16_lineEdit_7) },
                { "IpCam", UtilitesClass::GetConvertedQt_obj(ui->IpCam_CV_16_lineEdit_7) },
                { "MaskCam", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_CV_16_lineEdit_7) },
                { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_CV_16_spinBox_7) },
                { "NullLevel", UtilitesClass::GetConvertedQt_obj(ui->NullLevel_CV_16_spinBox_7) },
                { "BrightLevel", UtilitesClass::GetConvertedQt_obj(ui->BrightLevel_CV_16_spinBox_7) },
                { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_CV_16_doubleSpinBox_7) },
                { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_CV_16_spinBox_7) },
                { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_CV_16_spinBox_7) },
                { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_CV_16_spinBox_7) },
                { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_CV_16_spinBox_7) },
                { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_CV_16_spinBox_7) },
                { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_CV_16_spinBox_7) },
                { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_CV_16_spinBox_7) },
                { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_CV_16_spinBox_7) },
                { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_CV_16_spinBox_7) },
            },
            {
                { "ActiveCam", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_CV_16_checkBox_8) },
                { "AliasCam", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_CV_16_lineEdit_8) },
                { "IpCam", UtilitesClass::GetConvertedQt_obj(ui->IpCam_CV_16_lineEdit_8) },
                { "MaskCam", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_CV_16_lineEdit_8) },
                { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_CV_16_spinBox_8) },
                { "NullLevel", UtilitesClass::GetConvertedQt_obj(ui->NullLevel_CV_16_spinBox_8) },
                { "BrightLevel", UtilitesClass::GetConvertedQt_obj(ui->BrightLevel_CV_16_spinBox_8) },
                { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_CV_16_doubleSpinBox_8) },
                { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_CV_16_spinBox_8) },
                { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_CV_16_spinBox_8) },
                { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_CV_16_spinBox_8) },
                { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_CV_16_spinBox_8) },
                { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_CV_16_spinBox_8) },
                { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_CV_16_spinBox_8) },
                { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_CV_16_spinBox_8) },
                { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_CV_16_spinBox_8) },
                { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_CV_16_spinBox_8) },
            },
            {
                { "ActiveCam", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_CV_16_checkBox_9) },
                { "AliasCam", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_CV_16_lineEdit_9) },
                { "IpCam", UtilitesClass::GetConvertedQt_obj(ui->IpCam_CV_16_lineEdit_9) },
                { "MaskCam", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_CV_16_lineEdit_9) },
                { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_CV_16_spinBox_9) },
                { "NullLevel", UtilitesClass::GetConvertedQt_obj(ui->NullLevel_CV_16_spinBox_9) },
                { "BrightLevel", UtilitesClass::GetConvertedQt_obj(ui->BrightLevel_CV_16_spinBox_9) },
                { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_CV_16_doubleSpinBox_9) },
                { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_CV_16_spinBox_9) },
                { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_CV_16_spinBox_9) },
                { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_CV_16_spinBox_9) },
                { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_CV_16_spinBox_9) },
                { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_CV_16_spinBox_9) },
                { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_CV_16_spinBox_9) },
                { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_CV_16_spinBox_9) },
                { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_CV_16_spinBox_9) },
                { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_CV_16_spinBox_9) },
            },
            {
                { "ActiveCam", UtilitesClass::GetConvertedQt_obj(ui->ActiveCam_CV_16_checkBox_10) },
                { "AliasCam", UtilitesClass::GetConvertedQt_obj(ui->AliasCam_CV_16_lineEdit_10) },
                { "IpCam", UtilitesClass::GetConvertedQt_obj(ui->IpCam_CV_16_lineEdit_10) },
                { "MaskCam", UtilitesClass::GetConvertedQt_obj(ui->MaskCam_CV_16_lineEdit_10) },
                { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_CV_16_spinBox_10) },
                { "NullLevel", UtilitesClass::GetConvertedQt_obj(ui->NullLevel_CV_16_spinBox_10) },
                { "BrightLevel", UtilitesClass::GetConvertedQt_obj(ui->BrightLevel_CV_16_spinBox_10) },
                { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_CV_16_doubleSpinBox_10) },
                { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_CV_16_spinBox_10) },
                { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_CV_16_spinBox_10) },
                { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_CV_16_spinBox_10) },
                { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_CV_16_spinBox_10) },
                { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_CV_16_spinBox_10) },
                { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_CV_16_spinBox_10) },
                { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_CV_16_spinBox_10) },
                { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_CV_16_spinBox_10) },
                { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_CV_16_spinBox_10) },
            },
        };
        return std::pair<std::map<std::string,std::string>, std::vector<std::map<std::string,std::string>>>(AllSettingsMap, AllSettingsVector);
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
        std::map <std::string,std::string> AllSettingsMap;
        std::vector<std::map<std::string,std::string>> AllSettingsVector;
        return std::pair<std::map<std::string,std::string>, std::vector<std::map<std::string,std::string>>>(AllSettingsMap, AllSettingsVector);
    }
}

void UiWidgetClass::AutoImport()
{
    try {
        QFile file("settings.json");
        if (!file.open( QIODevice::ReadOnly)) {
            std::cerr << "Error: unable to open a file" << std::endl;
        } else {
            QByteArray data = file.readAll();
            QJsonDocument document;
            document = document.fromJson(data);
            if (document.object()["AutoImport"].toString() == "true") {
                Sleep(500);
                on_ImportSettings_CV_16_DEBUG_pushButton_clicked();
            }
        }
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void UiWidgetClass::AutoPlay()
{
    try {
        if (UtilitesClass::GetConvertedQt_obj(ui->AutoPlay_CV_16_DEBUG_checkBox) == "true") {
            Sleep(500);
            on_START_CV_16_btn_clicked();
        }
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void UiWidgetClass::startAnalyse(std::map<std::string, std::string> AllSettingsMap,
                             std::vector<std::map<std::string,std::string>> AllSettingsVector,
                             Ui::MainClass *ui)
{
    try {
        while(Playing) {
            if (UtilitesClass::GetValueFromMap(AllSettingsMap, "RuntimeUpdateParams") == "true") {
                std::pair<std::map<std::string,std::string>, std::vector<std::map<std::string,std::string>>> SettingsPair = GetMapsFromSettings();
                AllSettingsMap = SettingsPair.first;
                AllSettingsVector = SettingsPair.second;
            }
            if (not Playing) {
                break;
            }
            for (auto& OneSettingsMap : AllSettingsVector)
            {
                QCoreApplication::processEvents();
                try {
                    if (UtilitesClass::GetValueFromMap(OneSettingsMap, "ActiveCam") == "true" and Playing) {
                        QCoreApplication::processEvents();
                        if (UtilitesClass::GetValueFromMap(AllSettingsMap, "ComputeType") == "sync") {
                            SyncThreadClass objs(AllSettingsMap, OneSettingsMap, ui);
                        }
                        QCoreApplication::processEvents();
                        if (UtilitesClass::GetValueFromMap(AllSettingsMap, "ComputeType") == "async") {
                            AsyncThreadClass* obj = new AsyncThreadClass(AllSettingsMap, OneSettingsMap, ui);
                            obj->deleteLater();
                        }
                        QCoreApplication::processEvents();
                    }
                QCoreApplication::processEvents();
                }  catch (std::string error) {
                    UtilitesClass::WriteTextErrorToLogFile(error);
                }
            }
            if (not Playing) {
                break;
            }
            QCoreApplication::processEvents();
            Sleep(int (std::stod(UtilitesClass::GetValueFromMap(AllSettingsMap, "TimeDelay"))*1000));
            QCoreApplication::processEvents();
            if (not Playing) {
                break;
            }
        }
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void UiWidgetClass::on_START_Video_CV_btn_clicked()
{
    try {
        on_STOP_Video_CV_btn_clicked();
        Playing = true;
        ui->Playing_radioButton->setChecked(Playing);
        QCoreApplication::processEvents();
        start_video_analiz();
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void UiWidgetClass::on_STOP_Video_CV_btn_clicked()
{
    try {
        Playing = false;
        ui->Playing_radioButton_2->setChecked(Playing);
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void UiWidgetClass::on_TRAY_Video_CV_btn_clicked()
{
    try {
        on_TRAY_CV_16_btn_clicked();
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void UiWidgetClass::on_UnlockResourcesPath_CV_Video_pushButton_clicked()
{
    try {
        ui->Resources_Video_CV_lineEdit->setReadOnly(!ui->Resources_Video_CV_lineEdit->isReadOnly());
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void UiWidgetClass::start_video_analiz()
{
    try {
        std::pair<std::map<std::string, std::string>, std::vector<std::map<std::string, std::string>>> AllSettingsPair = GetMapsFrom_CV_Video_Settings();
        std::vector<cv::VideoCapture> AllCapVector;
        int i = 0;
        for (auto& OneSettingsMap : AllSettingsPair.second)
        {
            if (UtilitesClass::GetValueFromMap(OneSettingsMap, "ActiveVideo") == "true") {
                AllCapVector.push_back(cv::VideoCapture(UtilitesClass::GetValueFromMap(AllSettingsPair.first, "Resources") + UtilitesClass::GetValueFromMap(OneSettingsMap, "FileVideo")));
                i++;
            }
        }
        while(Playing) {
            if (not Playing) {
                break;
            }
            AllSettingsPair = GetMapsFrom_CV_Video_Settings();
            int i = 0;
            for (auto& OneSettingsMap : AllSettingsPair.second)
            {
                if (UtilitesClass::GetValueFromMap(OneSettingsMap, "ActiveVideo") == "true") {
                    UiWidgetClass::filter_video(AllSettingsPair.first, OneSettingsMap, AllCapVector[i]);
                    i++;
                }
            }
            if (not Playing) {
                break;
            }
            char c=(char)cv::waitKey(std::stoi(UtilitesClass::GetValueFromMap(AllSettingsPair.first, "TimeDelay")));
            if(c==27)
                break;
        }
        for (auto& OneCapVector : AllCapVector)
        {
            OneCapVector.release();
        }
        cv::destroyAllWindows();
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
        cv::destroyAllWindows();
    }
}

void UiWidgetClass::filter_video(std::map<std::string, std::string> AllSettingsMap, std::map<std::string, std::string> OneSettingsMap, cv::VideoCapture cap)
{
    try {
        cv::Mat frame;
        cv::Mat bitwise_and;
        cv::Mat cvtcolor;
        cv::Mat final;
        cv::Mat mask = cv::imread(UtilitesClass::GetValueFromMap(AllSettingsMap, "Resources") + UtilitesClass::GetValueFromMap(OneSettingsMap, "MaskVideo"), 0);
        cap >> frame;
        if (frame.empty()) {
            UtilitesClass::PrintValueToConsole("restart");
            on_STOP_Video_CV_btn_clicked();
        } else {
            cv::bitwise_and(frame, frame, bitwise_and, mask);
            cv::cvtColor(bitwise_and, cvtcolor, cv::COLOR_BGR2HSV);
            cvtcolor.convertTo(cvtcolor, -1, 1, std::stoi((UtilitesClass::GetValueFromMap(OneSettingsMap, "BrightLevel"))) - 50);
            frame.convertTo(frame, -1, 1, std::stoi((UtilitesClass::GetValueFromMap(OneSettingsMap, "BrightLevel"))) - 50);
            cv::inRange(cvtcolor, cv::Scalar(std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "Point_1_1")),
                                             std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "Point_1_2")),
                                             std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "Point_1_3"))),
                        cv::Scalar(std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "Point_2_1")),
                                   std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "Point_2_2")),
                                   std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "Point_2_3"))), final);
            final.setTo(255, final >= 1);
            double result = double(cv::countNonZero(final > std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "CountNotZero"))) /
                                   double(cv::countNonZero(mask)) * 100 * std::stod(UtilitesClass::GetValueFromMap(OneSettingsMap, "CorrectCoefficient")));
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
                if (result < std::stod(UtilitesClass::GetValueFromMap(OneSettingsMap, "NullLevel"))) {
                    result = 0.0;
                }
            }
            cv::putText(final, UtilitesClass::GetLocalTime(), cv::Point(150, 100), cv::FONT_HERSHEY_COMPLEX, 4, cv::Scalar(255, 255, 255), 1);
            if (result > std::stoi((UtilitesClass::GetValueFromMap(OneSettingsMap, "AlarmLevel")))) {
                cv::putText(final, std::to_string(result) + "%", cv::Point(150, 250), cv::FONT_HERSHEY_COMPLEX, 8, cv::Scalar(255, 255, 255), 2);
            }
            else {
                cv::putText(final, std::to_string(result) + "%", cv::Point(150, 250), cv::FONT_HERSHEY_COMPLEX, 4, cv::Scalar(128, 128, 128), 1);
            }
            if (UtilitesClass::GetValueFromMap(AllSettingsMap, "RenderSource") == "true") {
                ComputerVisionClass::RenderCvImage(frame, std::stod(UtilitesClass::GetValueFromMap(AllSettingsMap, "RenderSize")), UtilitesClass::GetValueFromMap(OneSettingsMap, "AliasVideo") + " source");
            }
            if (UtilitesClass::GetValueFromMap(AllSettingsMap, "RenderMask") == "true") {
                ComputerVisionClass::RenderCvImage(mask, std::stod(UtilitesClass::GetValueFromMap(AllSettingsMap, "RenderSize")), UtilitesClass::GetValueFromMap(OneSettingsMap, "AliasVideo") + " mask");
            }
            if (UtilitesClass::GetValueFromMap(AllSettingsMap, "RenderFinal") == "true") {
                ComputerVisionClass::RenderCvImage(final, std::stod(UtilitesClass::GetValueFromMap(AllSettingsMap, "RenderSize")), UtilitesClass::GetValueFromMap(OneSettingsMap, "AliasVideo") + " final");
            }
            if (UtilitesClass::GetValueFromMap(AllSettingsMap, "RenderContours") == "true") {
                cv::Mat canny_output;
                Canny( frame, canny_output, std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "ThreshMinLevel")), std::stoi(UtilitesClass::GetValueFromMap(OneSettingsMap, "ThreshMaxLevel")));
                std::vector<std::vector<cv::Point>> contours;
                std::vector<cv::Vec4i> hierarchy;
                findContours( canny_output, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
                cv::Mat drawing = cv::Mat::zeros( canny_output.size(), CV_8UC3 );
                for( size_t i = 0; i< contours.size(); i++ )
                {
                    cv::Scalar color = cv::Scalar(255, 255, 255);
                    drawContours( drawing, contours, (int)i, color, 1, cv::LINE_4, hierarchy, 0);
                }
                ComputerVisionClass::RenderCvImage(drawing, std::stod(UtilitesClass::GetValueFromMap(AllSettingsMap, "RenderSize")), UtilitesClass::GetValueFromMap(OneSettingsMap, "AliasVideo") + " countours");
            }
            ui->Time_Video_CV_label->setText(QString::fromStdString(UtilitesClass::GetLocalTime()));
            ui->Result_Video_CV_progressBar->setValue(result);
            ui->Result_Video_CV_LcdNumber->display(result);
            if (result > std::stoi((UtilitesClass::GetValueFromMap(OneSettingsMap, "AlarmLevel")))) {
                QString danger = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #FF0350,stop: 0.4999 #FF0020,stop: 0.5 #FF0019,stop: 1 #FF0000 );border-bottom-right-radius: 5px;border-bottom-left-radius: 5px;border: .px solid black;}";
                ui->Result_Video_CV_progressBar->setStyleSheet(danger);
            }
            else {
                QString safe= "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #78d,stop: 0.4999 #46a,stop: 0.5 #45a,stop: 1 #238 );border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;border: 1px solid black;}";
                ui->Result_Video_CV_progressBar->setStyleSheet(safe);
            }
        }
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

std::pair<std::map<std::string, std::string>, std::vector<std::map<std::string, std::string>>> UiWidgetClass::GetMapsFrom_CV_Video_Settings()
{
    try {
        std::map <std::string, std::string> AllSettingsMap = {
            { "Resources", UtilitesClass::GetConvertedQt_obj(ui->Resources_Video_CV_lineEdit) },
            { "TimeDelay", UtilitesClass::GetConvertedQt_obj(ui->TimeDelayVideo_Video_CV_spinBox) },
            { "RenderSize", UtilitesClass::GetConvertedQt_obj(ui->RenderSize_Video_CV_doubleSpinBox) },
            { "RenderSource", UtilitesClass::GetConvertedQt_obj(ui->RenderSource_Video_CV_checkBox) },
            { "RenderMask", UtilitesClass::GetConvertedQt_obj(ui->RenderMask_Video_CV_checkBox) },
            { "RenderFinal", UtilitesClass::GetConvertedQt_obj(ui->RenderFinal_Video_CV_checkBox) },
            { "RenderContours", UtilitesClass::GetConvertedQt_obj(ui->RenderContours_Video_CV_checkBox) },
        };
        std::vector <std::map<std::string, std::string>> AllSettingsVector =
        {
            {
                { "ActiveVideo", UtilitesClass::GetConvertedQt_obj(ui->ActiveVideo_Video_CV_checkBox_1) },
                { "AliasVideo", UtilitesClass::GetConvertedQt_obj(ui->AliasVideo_Video_CV_lineEdit_1) },
                { "FileVideo", UtilitesClass::GetConvertedQt_obj(ui->FileVideo_Video_CV_lineEdit_1) },
                { "MaskVideo", UtilitesClass::GetConvertedQt_obj(ui->MaskVideo_Video_CV_lineEdit_1) },
                { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_Video_CV_doubleSpinBox_1) },
                { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_Video_CV_spinBox_1) },
                { "NullLevel", UtilitesClass::GetConvertedQt_obj(ui->NullLevel_Video_CV_spinBox_1) },
                { "BrightLevel", UtilitesClass::GetConvertedQt_obj(ui->BrightLevel_Video_CV_spinBox_1) },
                { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_Video_CV_spinBox_1) },
                { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_Video_CV_spinBox_1) },
                { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_Video_CV_spinBox_1) },
                { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_Video_CV_spinBox_1) },
                { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_Video_CV_spinBox_1) },
                { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_Video_CV_spinBox_1) },
                { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_Video_CV_spinBox_1) },
                { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_Video_CV_spinBox_1) },
                { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_Video_CV_spinBox_1) },
                { "ThreshMinLevel", UtilitesClass::GetConvertedQt_obj(ui->ThreshMinLevel_Video_CV_spinBox_1) },
                { "ThreshMaxLevel", UtilitesClass::GetConvertedQt_obj(ui->ThreshMaxLevel_Video_CV_spinBox_1) },

            },
            {
                { "ActiveVideo", UtilitesClass::GetConvertedQt_obj(ui->ActiveVideo_Video_CV_checkBox_2) },
                { "AliasVideo", UtilitesClass::GetConvertedQt_obj(ui->AliasVideo_Video_CV_lineEdit_2) },
                { "FileVideo", UtilitesClass::GetConvertedQt_obj(ui->FileVideo_Video_CV_lineEdit_2) },
                { "MaskVideo", UtilitesClass::GetConvertedQt_obj(ui->MaskVideo_Video_CV_lineEdit_2) },
                { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_Video_CV_doubleSpinBox_2) },
                { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_Video_CV_spinBox_2) },
                { "NullLevel", UtilitesClass::GetConvertedQt_obj(ui->NullLevel_Video_CV_spinBox_2) },
                { "BrightLevel", UtilitesClass::GetConvertedQt_obj(ui->BrightLevel_Video_CV_spinBox_2) },
                { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_Video_CV_spinBox_2) },
                { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_Video_CV_spinBox_2) },
                { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_Video_CV_spinBox_2) },
                { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_Video_CV_spinBox_2) },
                { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_Video_CV_spinBox_2) },
                { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_Video_CV_spinBox_2) },
                { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_Video_CV_spinBox_2) },
                { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_Video_CV_spinBox_2) },
                { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_Video_CV_spinBox_2) },
                { "ThreshMinLevel", UtilitesClass::GetConvertedQt_obj(ui->ThreshMinLevel_Video_CV_spinBox_2) },
                { "ThreshMaxLevel", UtilitesClass::GetConvertedQt_obj(ui->ThreshMaxLevel_Video_CV_spinBox_2) },
            },
            {
                { "ActiveVideo", UtilitesClass::GetConvertedQt_obj(ui->ActiveVideo_Video_CV_checkBox_3) },
                { "AliasVideo", UtilitesClass::GetConvertedQt_obj(ui->AliasVideo_Video_CV_lineEdit_3) },
                { "FileVideo", UtilitesClass::GetConvertedQt_obj(ui->FileVideo_Video_CV_lineEdit_3) },
                { "MaskVideo", UtilitesClass::GetConvertedQt_obj(ui->MaskVideo_Video_CV_lineEdit_3) },
                { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_Video_CV_doubleSpinBox_3) },
                { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_Video_CV_spinBox_3) },
                { "NullLevel", UtilitesClass::GetConvertedQt_obj(ui->NullLevel_Video_CV_spinBox_3) },
                { "BrightLevel", UtilitesClass::GetConvertedQt_obj(ui->BrightLevel_Video_CV_spinBox_3) },
                { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_Video_CV_spinBox_3) },
                { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_Video_CV_spinBox_3) },
                { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_Video_CV_spinBox_3) },
                { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_Video_CV_spinBox_3) },
                { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_Video_CV_spinBox_3) },
                { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_Video_CV_spinBox_3) },
                { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_Video_CV_spinBox_3) },
                { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_Video_CV_spinBox_3) },
                { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_Video_CV_spinBox_3) },
                { "ThreshMinLevel", UtilitesClass::GetConvertedQt_obj(ui->ThreshMinLevel_Video_CV_spinBox_3) },
                { "ThreshMaxLevel", UtilitesClass::GetConvertedQt_obj(ui->ThreshMaxLevel_Video_CV_spinBox_3) },
            },
            {
                { "ActiveVideo", UtilitesClass::GetConvertedQt_obj(ui->ActiveVideo_Video_CV_checkBox_4) },
                { "AliasVideo", UtilitesClass::GetConvertedQt_obj(ui->AliasVideo_Video_CV_lineEdit_4) },
                { "FileVideo", UtilitesClass::GetConvertedQt_obj(ui->FileVideo_Video_CV_lineEdit_4) },
                { "MaskVideo", UtilitesClass::GetConvertedQt_obj(ui->MaskVideo_Video_CV_lineEdit_4) },
                { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_Video_CV_doubleSpinBox_4) },
                { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_Video_CV_spinBox_4) },
                { "NullLevel", UtilitesClass::GetConvertedQt_obj(ui->NullLevel_Video_CV_spinBox_4) },
                { "BrightLevel", UtilitesClass::GetConvertedQt_obj(ui->BrightLevel_Video_CV_spinBox_4) },
                { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_Video_CV_spinBox_4) },
                { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_Video_CV_spinBox_4) },
                { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_Video_CV_spinBox_4) },
                { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_Video_CV_spinBox_4) },
                { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_Video_CV_spinBox_4) },
                { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_Video_CV_spinBox_4) },
                { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_Video_CV_spinBox_4) },
                { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_Video_CV_spinBox_4) },
                { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_Video_CV_spinBox_4) },
                { "ThreshMinLevel", UtilitesClass::GetConvertedQt_obj(ui->ThreshMinLevel_Video_CV_spinBox_4) },
                { "ThreshMaxLevel", UtilitesClass::GetConvertedQt_obj(ui->ThreshMaxLevel_Video_CV_spinBox_4) },
            },
            {
                { "ActiveVideo", UtilitesClass::GetConvertedQt_obj(ui->ActiveVideo_Video_CV_checkBox_5) },
                { "AliasVideo", UtilitesClass::GetConvertedQt_obj(ui->AliasVideo_Video_CV_lineEdit_5) },
                { "FileVideo", UtilitesClass::GetConvertedQt_obj(ui->FileVideo_Video_CV_lineEdit_5) },
                { "MaskVideo", UtilitesClass::GetConvertedQt_obj(ui->MaskVideo_Video_CV_lineEdit_5) },
                { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_Video_CV_doubleSpinBox_5) },
                { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_Video_CV_spinBox_5) },
                { "NullLevel", UtilitesClass::GetConvertedQt_obj(ui->NullLevel_Video_CV_spinBox_5) },
                { "BrightLevel", UtilitesClass::GetConvertedQt_obj(ui->BrightLevel_Video_CV_spinBox_5) },
                { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_Video_CV_spinBox_5) },
                { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_Video_CV_spinBox_5) },
                { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_Video_CV_spinBox_5) },
                { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_Video_CV_spinBox_5) },
                { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_Video_CV_spinBox_5) },
                { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_Video_CV_spinBox_5) },
                { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_Video_CV_spinBox_5) },
                { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_Video_CV_spinBox_5) },
                { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_Video_CV_spinBox_5) },
            },
            {
                { "ActiveVideo", UtilitesClass::GetConvertedQt_obj(ui->ActiveVideo_Video_CV_checkBox_6) },
                { "AliasVideo", UtilitesClass::GetConvertedQt_obj(ui->AliasVideo_Video_CV_lineEdit_6) },
                { "FileVideo", UtilitesClass::GetConvertedQt_obj(ui->FileVideo_Video_CV_lineEdit_6) },
                { "MaskVideo", UtilitesClass::GetConvertedQt_obj(ui->MaskVideo_Video_CV_lineEdit_6) },
                { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_Video_CV_doubleSpinBox_6) },
                { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_Video_CV_spinBox_6) },
                { "NullLevel", UtilitesClass::GetConvertedQt_obj(ui->NullLevel_Video_CV_spinBox_6) },
                { "BrightLevel", UtilitesClass::GetConvertedQt_obj(ui->BrightLevel_Video_CV_spinBox_6) },
                { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_Video_CV_spinBox_6) },
                { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_Video_CV_spinBox_6) },
                { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_Video_CV_spinBox_6) },
                { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_Video_CV_spinBox_6) },
                { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_Video_CV_spinBox_6) },
                { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_Video_CV_spinBox_6) },
                { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_Video_CV_spinBox_6) },
                { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_Video_CV_spinBox_6) },
                { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_Video_CV_spinBox_6) },
            },
            {
                { "ActiveVideo", UtilitesClass::GetConvertedQt_obj(ui->ActiveVideo_Video_CV_checkBox_7) },
                { "AliasVideo", UtilitesClass::GetConvertedQt_obj(ui->AliasVideo_Video_CV_lineEdit_7) },
                { "FileVideo", UtilitesClass::GetConvertedQt_obj(ui->FileVideo_Video_CV_lineEdit_7) },
                { "MaskVideo", UtilitesClass::GetConvertedQt_obj(ui->MaskVideo_Video_CV_lineEdit_7) },
                { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_Video_CV_doubleSpinBox_7) },
                { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_Video_CV_spinBox_7) },
                { "NullLevel", UtilitesClass::GetConvertedQt_obj(ui->NullLevel_Video_CV_spinBox_7) },
                { "BrightLevel", UtilitesClass::GetConvertedQt_obj(ui->BrightLevel_Video_CV_spinBox_7) },
                { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_Video_CV_spinBox_7) },
                { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_Video_CV_spinBox_7) },
                { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_Video_CV_spinBox_7) },
                { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_Video_CV_spinBox_7) },
                { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_Video_CV_spinBox_7) },
                { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_Video_CV_spinBox_7) },
                { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_Video_CV_spinBox_7) },
                { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_Video_CV_spinBox_7) },
                { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_Video_CV_spinBox_7) },
            },
            {
                { "ActiveVideo", UtilitesClass::GetConvertedQt_obj(ui->ActiveVideo_Video_CV_checkBox_8) },
                { "AliasVideo", UtilitesClass::GetConvertedQt_obj(ui->AliasVideo_Video_CV_lineEdit_8) },
                { "FileVideo", UtilitesClass::GetConvertedQt_obj(ui->FileVideo_Video_CV_lineEdit_8) },
                { "MaskVideo", UtilitesClass::GetConvertedQt_obj(ui->MaskVideo_Video_CV_lineEdit_8) },
                { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_Video_CV_doubleSpinBox_8) },
                { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_Video_CV_spinBox_8) },
                { "NullLevel", UtilitesClass::GetConvertedQt_obj(ui->NullLevel_Video_CV_spinBox_8) },
                { "BrightLevel", UtilitesClass::GetConvertedQt_obj(ui->BrightLevel_Video_CV_spinBox_8) },
                { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_Video_CV_spinBox_8) },
                { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_Video_CV_spinBox_8) },
                { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_Video_CV_spinBox_8) },
                { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_Video_CV_spinBox_8) },
                { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_Video_CV_spinBox_8) },
                { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_Video_CV_spinBox_8) },
                { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_Video_CV_spinBox_8) },
                { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_Video_CV_spinBox_8) },
                { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_Video_CV_spinBox_8) },
            },
            {
                { "ActiveVideo", UtilitesClass::GetConvertedQt_obj(ui->ActiveVideo_Video_CV_checkBox_9) },
                { "AliasVideo", UtilitesClass::GetConvertedQt_obj(ui->AliasVideo_Video_CV_lineEdit_9) },
                { "FileVideo", UtilitesClass::GetConvertedQt_obj(ui->FileVideo_Video_CV_lineEdit_9) },
                { "MaskVideo", UtilitesClass::GetConvertedQt_obj(ui->MaskVideo_Video_CV_lineEdit_9) },
                { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_Video_CV_doubleSpinBox_9) },
                { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_Video_CV_spinBox_9) },
                { "NullLevel", UtilitesClass::GetConvertedQt_obj(ui->NullLevel_Video_CV_spinBox_9) },
                { "BrightLevel", UtilitesClass::GetConvertedQt_obj(ui->BrightLevel_Video_CV_spinBox_9) },
                { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_Video_CV_spinBox_9) },
                { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_Video_CV_spinBox_9) },
                { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_Video_CV_spinBox_9) },
                { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_Video_CV_spinBox_9) },
                { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_Video_CV_spinBox_9) },
                { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_Video_CV_spinBox_9) },
                { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_Video_CV_spinBox_9) },
                { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_Video_CV_spinBox_9) },
                { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_Video_CV_spinBox_9) },
            },
            {
                { "ActiveVideo", UtilitesClass::GetConvertedQt_obj(ui->ActiveVideo_Video_CV_checkBox_10) },
                { "AliasVideo", UtilitesClass::GetConvertedQt_obj(ui->AliasVideo_Video_CV_lineEdit_10) },
                { "FileVideo", UtilitesClass::GetConvertedQt_obj(ui->FileVideo_Video_CV_lineEdit_10) },
                { "MaskVideo", UtilitesClass::GetConvertedQt_obj(ui->MaskVideo_Video_CV_lineEdit_10) },
                { "CorrectCoefficient", UtilitesClass::GetConvertedQt_obj(ui->CorrectCoefficient_Video_CV_doubleSpinBox_10) },
                { "AlarmLevel", UtilitesClass::GetConvertedQt_obj(ui->AlarmLevel_Video_CV_spinBox_10) },
                { "NullLevel", UtilitesClass::GetConvertedQt_obj(ui->NullLevel_Video_CV_spinBox_10) },
                { "BrightLevel", UtilitesClass::GetConvertedQt_obj(ui->BrightLevel_Video_CV_spinBox_10) },
                { "InRangeSetFrom", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetFrom_Video_CV_spinBox_10) },
                { "InRangeSetTo", UtilitesClass::GetConvertedQt_obj(ui->InRangeSetTo_Video_CV_spinBox_10) },
                { "CountNotZero", UtilitesClass::GetConvertedQt_obj(ui->CountNotZero_Video_CV_spinBox_10) },
                { "Point_1_1", UtilitesClass::GetConvertedQt_obj(ui->Point_1_1_Video_CV_spinBox_10) },
                { "Point_1_2", UtilitesClass::GetConvertedQt_obj(ui->Point_1_2_Video_CV_spinBox_10) },
                { "Point_1_3", UtilitesClass::GetConvertedQt_obj(ui->Point_1_3_Video_CV_spinBox_10) },
                { "Point_2_1", UtilitesClass::GetConvertedQt_obj(ui->Point_2_1_Video_CV_spinBox_10) },
                { "Point_2_2", UtilitesClass::GetConvertedQt_obj(ui->Point_2_2_Video_CV_spinBox_10) },
                { "Point_2_3", UtilitesClass::GetConvertedQt_obj(ui->Point_2_3_Video_CV_spinBox_10) },
            }
        };
        return std::pair(AllSettingsMap, AllSettingsVector);
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
        std::map <std::string, std::string> AllSettingsMap;
        std::vector <std::map<std::string, std::string>> AllSettingsVector;
        return std::pair(AllSettingsMap, AllSettingsVector);
    }
}

/********** UiWidgetClass ***********/



/********** SyncThreadClass **********/
SyncThreadClass::SyncThreadClass(std::map<std::string, std::string> AllSettingsMap,
                                 std::map<std::string,std::string> OneSettingsMap,
                                 Ui::MainClass *ui,
                                 QWidget *parent) : QObject(parent)
{
    try {
        AllSettings = AllSettingsMap;
        OneSettings = OneSettingsMap;
        Gui = ui;

        QUrl url = QString::fromStdString(UtilitesClass::GetUrlFromIp(AllSettings, UtilitesClass::GetValueFromMap(OneSettings, "IpCam")));
        url.setUserName(QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettings, "LoginCam")));
        url.setPassword(QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettings, "PasswordCam")));
        QNetworkAccessManager manager;
        QNetworkReply* reply = manager.get(QNetworkRequest(url));
        QEventLoop loop;
        connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();
        QByteArray data = reply->readAll();
        cv::Mat image_source;
        QPixmap qPixmap;
        if (qPixmap.loadFromData(data, "JPG")) {
            QImage qImage = qPixmap.toImage();
            image_source = cv::Mat(qImage.height(), qImage.width(), CV_8UC4, const_cast<uchar*>(qImage.bits()), static_cast<size_t>(qImage.bytesPerLine()));
            std::string ResourcesCam = UtilitesClass::GetValueFromMap(AllSettings, "ResourcesCam") + UtilitesClass::GetValueFromMap(OneSettings, "MaskCam");
            cv::Mat mask = cv::imread(ResourcesCam, 0);
            cv::Mat bitwise_and;
            cv::bitwise_and(image_source, image_source, bitwise_and, mask);
            cv::Mat cvtcolor;
            cv::cvtColor(bitwise_and, cvtcolor, cv::COLOR_BGR2HSV);
            cvtcolor.convertTo(cvtcolor, -1, 1, std::stoi((UtilitesClass::GetValueFromMap(OneSettings, "BrightLevel"))) - 50);
            image_source.convertTo(image_source, -1, 1, std::stoi((UtilitesClass::GetValueFromMap(OneSettings, "BrightLevel"))) - 50);
            cv::Mat final;
            cv::inRange(cvtcolor, cv::Scalar(std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "Point_1_1")),
                                             std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "Point_1_2")),
                                             std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "Point_1_3"))),
                        cv::Scalar(std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "Point_2_1")),
                                   std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "Point_2_2")),
                                   std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "Point_2_3"))), final);
            final.setTo(std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "InRangeSetTo")), final >= std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "InRangeSetFrom")));
            double result = double(cv::countNonZero(final > std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "CountNotZero")))) / double(cv::countNonZero(mask)) * 100 * std::stod(UtilitesClass::GetValueFromMap(OneSettings, "CorrectCoefficient"));
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
                if (result < std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "NullLevel"))) {
                    result = 0.0;
                }
            }
            if (result > std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "AlarmLevel"))){
                if (UtilitesClass::GetValueFromMap(AllSettings, "WriteNowSql") == "true"){
                    SQLClass::UpdateValuesToSQL(UtilitesClass::GetValueFromMap(OneSettings, "AliasCam").substr(0,2) + "/" + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam").substr(3), result, 1, AllSettings);
                }
                if (UtilitesClass::GetValueFromMap(AllSettings, "WriteDataSql") == "true"){
                    SQLClass::InsertValuesToSQL(UtilitesClass::GetValueFromMap(OneSettings, "AliasCam").substr(0,2) + "/" + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam").substr(3), result, 0, AllSettings);
                }
            } else {
                if (UtilitesClass::GetValueFromMap(AllSettings, "WriteNowSql") == "true"){
                    SQLClass::UpdateValuesToSQL(UtilitesClass::GetValueFromMap(OneSettings, "AliasCam").substr(0,2) + "/" + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam").substr(3), result, 0, AllSettings);
                }
                if (UtilitesClass::GetValueFromMap(AllSettings, "WriteDataSql") == "true"){
                    SQLClass::InsertValuesToSQL(UtilitesClass::GetValueFromMap(OneSettings, "AliasCam").substr(0,2) + "/" + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam").substr(3), result, 0, AllSettings);
                }
            }
            if (UtilitesClass::GetValueFromMap(AllSettings, "RenderType") == "none") {
            } else if (UtilitesClass::GetValueFromMap(AllSettings, "RenderType") ==  "source") {
                ComputerVisionClass::RenderCvImage(image_source, std::stoi(UtilitesClass::GetValueFromMap(AllSettings, "RenderSize")) / 80.0, "source " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"));
            } else if (UtilitesClass::GetValueFromMap(AllSettings, "RenderType") == "final") {
                cv::putText(final, UtilitesClass::GetLocalTime(), cv::Point(150, 50), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
                cv::putText(final, UtilitesClass::GetValueFromMap(OneSettings, "IpCam") + " | " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"), cv::Point(150, 100), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
                if (result > std::stoi((UtilitesClass::GetValueFromMap(OneSettings, "AlarmLevel")))) {
                    cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(255, 255, 255), 2);
                }
                else {
                    cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(128, 128, 128), 1);
                }
                ComputerVisionClass::RenderCvImage(final, std::stoi(UtilitesClass::GetValueFromMap(AllSettings, "RenderSize")) / 80.0, "final " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"));
            } else if (UtilitesClass::GetValueFromMap(AllSettings, "RenderType") == "extended") {
                ComputerVisionClass::RenderCvImage(image_source, std::stoi(UtilitesClass::GetValueFromMap(AllSettings, "RenderSize")) / 80.0, "source " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"));
                cv::putText(final, UtilitesClass::GetLocalTime(), cv::Point(150, 50), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
                cv::putText(final, UtilitesClass::GetValueFromMap(OneSettings, "IpCam") + " | " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"), cv::Point(150, 100), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
                if (result > std::stoi((UtilitesClass::GetValueFromMap(OneSettings, "AlarmLevel")))) {
                    cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(255, 255, 255), 2);
                }
                else {
                    cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(128, 128, 128), 1);
                }
                ComputerVisionClass::RenderCvImage(final, std::stoi(UtilitesClass::GetValueFromMap(AllSettings, "RenderSize")) / 80.0, "final " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"));
            } else if (UtilitesClass::GetValueFromMap(AllSettings, "RenderType") == "all") {
                ComputerVisionClass::RenderCvImage(image_source, std::stoi(UtilitesClass::GetValueFromMap(AllSettings, "RenderSize")) / 80.0, "source " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"));
                ComputerVisionClass::RenderCvImage(mask, std::stoi(UtilitesClass::GetValueFromMap(AllSettings, "RenderSize")) / 80.0, "mask " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"));
                cv::putText(final, UtilitesClass::GetLocalTime(), cv::Point(150, 50), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
                cv::putText(final, UtilitesClass::GetValueFromMap(OneSettings, "IpCam") + " | " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"), cv::Point(150, 100), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
                if (result > std::stoi((UtilitesClass::GetValueFromMap(OneSettings, "AlarmLevel")))) {
                    cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(255, 255, 255), 2);
                }
                else {
                    cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(128, 128, 128), 1);
                }
                ComputerVisionClass::RenderCvImage(final, std::stoi(UtilitesClass::GetValueFromMap(AllSettings, "RenderSize")) / 80.0, "final " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"));
            }
            if (UtilitesClass::GetValueFromMap(AllSettings, "WriteToConsole") == "true") {
                UtilitesClass::PrintValueToConsole("RESULT " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam") + " IS : " + std::to_string(result) + "%");
            }
            if (UtilitesClass::GetValueFromMap(AllSettings, "WriteToWidget") == "true") {
                Gui->Time_CV_16_label->setText(QString::fromStdString(UtilitesClass::GetLocalTime()));
                Gui->Info_CV_16_label->setText(QString::fromStdString(UtilitesClass::GetValueFromMap(OneSettings, "IpCam") + " | " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam")));
                Gui->Result_CV_16_progressBar->setValue(result);
                Gui->Result_CV_16_LcdNumber->display(result);
                if (result > std::stoi((UtilitesClass::GetValueFromMap(OneSettings, "AlarmLevel")))) {
                    QString danger = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #FF0350,stop: 0.4999 #FF0020,stop: 0.5 #FF0019,stop: 1 #FF0000 );border-bottom-right-radius: 5px;border-bottom-left-radius: 5px;border: .px solid black;}";
                    Gui->Result_CV_16_progressBar->setStyleSheet(danger);
                }
                else {
                    QString safe= "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #78d,stop: 0.4999 #46a,stop: 0.5 #45a,stop: 1 #238 );border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;border: 1px solid black;}";
                    Gui->Result_CV_16_progressBar->setStyleSheet(safe);
                }
            }
            if (UtilitesClass::GetValueFromMap(AllSettings, "WriteToText") == "true") {
                UtilitesClass::WriteResultToTextFile("RESULT " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam") + " IS : " + std::to_string(result) + "%");
            }
            reply->deleteLater();
            manager.deleteLater();
        }
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

SyncThreadClass::~SyncThreadClass()
{

}
/********** SyncThreadClass **********/



/********** AsyncThreadClass **********/
AsyncThreadClass::AsyncThreadClass(std::map<std::string,std::string> AllSettingsMap,
                                   std::map<std::string,std::string> OneSettingsMap,
                                   Ui::MainClass *ui, QWidget *parent) : QObject(parent)
{
    try {
        AllSettings = AllSettingsMap;
        OneSettings = OneSettingsMap;
        Gui = ui;
        QUrl url = QString::fromStdString(UtilitesClass::GetUrlFromIp(AllSettings, UtilitesClass::GetValueFromMap(OneSettings, "IpCam")));
        url.setUserName(QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettings, "LoginCam")));
        url.setPassword(QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettings, "PasswordCam")));
        reply.reset(manager.get(QNetworkRequest(url)));
        connect(reply.get(), &QNetworkReply::finished, this, &AsyncThreadClass::finishDownload);
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

AsyncThreadClass::~AsyncThreadClass()
{

}

void AsyncThreadClass::finishDownload()
{
    try {
        QByteArray data = reply->readAll();
        cv::Mat image_source;
        QPixmap qPixmap;
        if (qPixmap.loadFromData(data, "JPG")) {
            QImage qImage = qPixmap.toImage();
            image_source = cv::Mat(qImage.height(), qImage.width(), CV_8UC4, const_cast<uchar*>(qImage.bits()), static_cast<size_t>(qImage.bytesPerLine()));
            std::string ResourcesCam = UtilitesClass::GetValueFromMap(AllSettings, "ResourcesCam") + UtilitesClass::GetValueFromMap(OneSettings, "MaskCam");
            cv::Mat mask = cv::imread(ResourcesCam, 0);
            cv::Mat bitwise_and;
            cv::bitwise_and(image_source, image_source, bitwise_and, mask);
            cv::Mat cvtcolor;
            cv::cvtColor(bitwise_and, cvtcolor, cv::COLOR_BGR2HSV);
            cvtcolor.convertTo(cvtcolor, -1, 1, std::stoi((UtilitesClass::GetValueFromMap(OneSettings, "BrightLevel"))) - 50);
            image_source.convertTo(image_source, -1, 1, std::stoi((UtilitesClass::GetValueFromMap(OneSettings, "BrightLevel"))) - 50);
            cv::Mat final;
            cv::inRange(cvtcolor, cv::Scalar(std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "Point_1_1")),
                                             std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "Point_1_2")),
                                             std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "Point_1_3"))),
                        cv::Scalar(std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "Point_2_1")),
                                   std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "Point_2_2")),
                                   std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "Point_2_3"))), final);
            final.setTo(std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "InRangeSetTo")), final >= std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "InRangeSetFrom")));
            double result = double(cv::countNonZero(final > std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "CountNotZero")))) / double(cv::countNonZero(mask)) * 100 * std::stod(UtilitesClass::GetValueFromMap(OneSettings, "CorrectCoefficient"));
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
                if (result < std::stod(UtilitesClass::GetValueFromMap(OneSettings, "NullLevel"))) {
                    result = 0.0;
                }
            }
            if (result > std::stoi(UtilitesClass::GetValueFromMap(OneSettings, "AlarmLevel"))){
                if (UtilitesClass::GetValueFromMap(AllSettings, "WriteNowSql") == "true"){
                    SQLClass::UpdateValuesToSQL(UtilitesClass::GetValueFromMap(OneSettings, "AliasCam").substr(0,2) + "/" + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam").substr(3), result, 1, AllSettings);
                }
                if (UtilitesClass::GetValueFromMap(AllSettings, "WriteDataSql") == "true"){
                    SQLClass::InsertValuesToSQL(UtilitesClass::GetValueFromMap(OneSettings, "AliasCam").substr(0,2) + "/" + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam").substr(3), result, 0, AllSettings);
                }
            } else {
                if (UtilitesClass::GetValueFromMap(AllSettings, "WriteNowSql") == "true"){
                    SQLClass::UpdateValuesToSQL(UtilitesClass::GetValueFromMap(OneSettings, "AliasCam").substr(0,2) + "/" + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam").substr(3), result, 0, AllSettings);
                }
                if (UtilitesClass::GetValueFromMap(AllSettings, "WriteDataSql") == "true"){
                    SQLClass::InsertValuesToSQL(UtilitesClass::GetValueFromMap(OneSettings, "AliasCam").substr(0,2) + "/" + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam").substr(3), result, 0, AllSettings);
                }
            }
            if (UtilitesClass::GetValueFromMap(AllSettings, "RenderType") == "none") {
            } else if (UtilitesClass::GetValueFromMap(AllSettings, "RenderType") ==  "source") {
                ComputerVisionClass::RenderCvImage(image_source, std::stoi(UtilitesClass::GetValueFromMap(AllSettings, "RenderSize")) / 80.0, "source " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"));
            } else if (UtilitesClass::GetValueFromMap(AllSettings, "RenderType") == "final") {
                cv::putText(final, UtilitesClass::GetLocalTime(), cv::Point(150, 50), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
                cv::putText(final, UtilitesClass::GetValueFromMap(OneSettings, "IpCam") + " | " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"), cv::Point(150, 100), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
                if (result > std::stoi((UtilitesClass::GetValueFromMap(OneSettings, "AlarmLevel")))) {
                    cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(255, 255, 255), 2);
                }
                else {
                    cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(128, 128, 128), 1);
                }
                ComputerVisionClass::RenderCvImage(final, std::stoi(UtilitesClass::GetValueFromMap(AllSettings, "RenderSize")) / 80.0, "final " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"));
            } else if (UtilitesClass::GetValueFromMap(AllSettings, "RenderType") == "extended") {
                ComputerVisionClass::RenderCvImage(image_source, std::stoi(UtilitesClass::GetValueFromMap(AllSettings, "RenderSize")) / 80.0, "source " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"));
                cv::putText(final, UtilitesClass::GetLocalTime(), cv::Point(150, 50), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
                cv::putText(final, UtilitesClass::GetValueFromMap(OneSettings, "IpCam") + " | " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"), cv::Point(150, 100), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
                if (result > std::stoi((UtilitesClass::GetValueFromMap(OneSettings, "AlarmLevel")))) {
                    cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(255, 255, 255), 2);
                }
                else {
                    cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(128, 128, 128), 1);
                }
                ComputerVisionClass::RenderCvImage(final, std::stoi(UtilitesClass::GetValueFromMap(AllSettings, "RenderSize")) / 80.0, "final " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"));
            } else if (UtilitesClass::GetValueFromMap(AllSettings, "RenderType") == "all") {
                ComputerVisionClass::RenderCvImage(image_source, std::stoi(UtilitesClass::GetValueFromMap(AllSettings, "RenderSize")) / 80.0, "source " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"));
                ComputerVisionClass::RenderCvImage(mask, std::stoi(UtilitesClass::GetValueFromMap(AllSettings, "RenderSize")) / 80.0, "mask " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"));
                cv::putText(final, UtilitesClass::GetLocalTime(), cv::Point(150, 50), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
                cv::putText(final, UtilitesClass::GetValueFromMap(OneSettings, "IpCam") + " | " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"), cv::Point(150, 100), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 1);
                if (result > std::stoi((UtilitesClass::GetValueFromMap(OneSettings, "AlarmLevel")))) {
                    cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(255, 255, 255), 2);
                }
                else {
                    cv::putText(final, std::to_string(result) + "%", cv::Point(150, 150), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(128, 128, 128), 1);
                }
                ComputerVisionClass::RenderCvImage(final, std::stoi(UtilitesClass::GetValueFromMap(AllSettings, "RenderSize")) / 80.0, "final " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam"));
            }
            if (UtilitesClass::GetValueFromMap(AllSettings, "WriteToConsole") == "true") {
                UtilitesClass::PrintValueToConsole("RESULT " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam") + " IS : " + std::to_string(result) + "%");
            }
            if (UtilitesClass::GetValueFromMap(AllSettings, "WriteToWidget") == "true") {
                Gui->Time_CV_16_label->setText(QString::fromStdString(UtilitesClass::GetLocalTime()));
                Gui->Info_CV_16_label->setText(QString::fromStdString(UtilitesClass::GetValueFromMap(OneSettings, "IpCam") + " | " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam")));
                Gui->Result_CV_16_progressBar->setValue(result);
                Gui->Result_CV_16_LcdNumber->display(result);
                if (result > std::stoi((UtilitesClass::GetValueFromMap(OneSettings, "AlarmLevel")))) {
                    QString danger = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #FF0350,stop: 0.4999 #FF0020,stop: 0.5 #FF0019,stop: 1 #FF0000 );border-bottom-right-radius: 5px;border-bottom-left-radius: 5px;border: .px solid black;}";
                    Gui->Result_CV_16_progressBar->setStyleSheet(danger);
                }
                else {
                    QString safe= "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #78d,stop: 0.4999 #46a,stop: 0.5 #45a,stop: 1 #238 );border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;border: 1px solid black;}";
                    Gui->Result_CV_16_progressBar->setStyleSheet(safe);
                }
            }
            if (UtilitesClass::GetValueFromMap(AllSettings, "WriteToText") == "true") {
                UtilitesClass::WriteResultToTextFile("RESULT " + UtilitesClass::GetValueFromMap(OneSettings, "AliasCam") + " IS : " + std::to_string(result) + "%");
            }
        }
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
    delete this;
}
/********** AsyncThreadClass **********/



/********** CVClass **********/
void ComputerVisionClass::RenderCvImage(cv::Mat Image, double RenderSize, std::string name)
{
    try {
        cv::Mat source = Image.clone();
        cv::resize(source, source, cv::Size(), RenderSize, RenderSize, cv::INTER_LINEAR);
        cv::namedWindow(name, cv::WINDOW_AUTOSIZE);
        cv::imshow(name, source);
        cv::waitKey(1);
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}
/********** CVClass **********/



/*********** SQLClass **********/
std::vector<std::vector<std::string>> SQLClass::GetValuesFromSQL(std::string sqlQuery, std::string connectionString, QString connectionDriver)
{
    try {
        QSqlDatabase qdb;
        if (QSqlDatabase::database().isOpen()) {
            qdb = QSqlDatabase::database();
        } else {
            qdb = QSqlDatabase::addDatabase(connectionDriver);
        }
        qdb.setDatabaseName(QString::fromStdString(connectionString));
        if (qdb.open()) {
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
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
        return {"", ""};
    }
}

void SQLClass::UpdateValuesToSQL(std::string device_row, double value_row, bool alarm_row, std::map<std::string, std::string> AllSettingsMap, QString connectionDriver)
{
    try {
        QSqlDatabase qdb;
        if (QSqlDatabase::database().isOpen()) {
            qdb = QSqlDatabase::database();
        } else {
            qdb = QSqlDatabase::addDatabase(connectionDriver);
        }
        if (UtilitesClass::GetValueFromMap(AllSettingsMap, "UseSQLPort") == "true") {
            std::string connectionString = "DRIVER={ODBC Driver 17 for SQL Server};SERVER=tcp:" +
                    UtilitesClass::GetValueFromMap(AllSettingsMap, "IpSqlServer") + "\\" +
                    UtilitesClass::GetValueFromMap(AllSettingsMap, "ServerNameSql") + "," +
                    UtilitesClass::GetValueFromMap(AllSettingsMap, "PortSqlServer") +
                    ";DATABASE=" + UtilitesClass::GetValueFromMap(AllSettingsMap, "DatabaseSql") +
                    ";UID=" + UtilitesClass::GetValueFromMap(AllSettingsMap, "UserSql") +
                    ";PWD=" + UtilitesClass::GetValueFromMap(AllSettingsMap, "PasswordSql");
            qdb.setDatabaseName(QString::fromStdString(connectionString));
        } else {
            std::string connectionString = "DRIVER={ODBC Driver 17 for SQL Server};SERVER=tcp:" +
                    UtilitesClass::GetValueFromMap(AllSettingsMap, "IpSqlServer") + "\\" +
                    UtilitesClass::GetValueFromMap(AllSettingsMap, "ServerNameSql") +
                    ";DATABASE=" + UtilitesClass::GetValueFromMap(AllSettingsMap, "DatabaseSql") +
                    ";UID=" + UtilitesClass::GetValueFromMap(AllSettingsMap, "UserSql") +
                    ";PWD=" + UtilitesClass::GetValueFromMap(AllSettingsMap, "PasswordSql");
            qdb.setDatabaseName(QString::fromStdString(connectionString));
        }
        if (qdb.open()) {
            QSqlQuery query(qdb);
            query.prepare("UPDATE " + QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettingsMap, "TableNowSql")) + " SET " +
                          QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettingsMap, "RowsNowSql_2")) + " = :value, " +
                          QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettingsMap, "RowsNowSql_3")) + " = :alarm, " +
                          QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettingsMap, "RowsNowSql_4")) + " = GETDATE() WHERE " +
                          QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettingsMap, "RowsNowSql_1")) + " = :device");
            query.bindValue(":value", value_row);
            query.bindValue(":alarm", alarm_row);
            query.bindValue(":device", QString::fromStdString(device_row));
            query.exec();
            qdb.close();
        } else {
            UtilitesClass::PrintValueToConsole("error to open sql");
        }
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}

void SQLClass::InsertValuesToSQL(std::string device_row, double value_row, bool alarm_row, std::map<std::string, std::string> AllSettingsMap, QString connectionDriver)
{
    try {
        QSqlDatabase qdb;
        if (QSqlDatabase::database().isOpen()) {
            qdb = QSqlDatabase::database();
        } else {
            qdb = QSqlDatabase::addDatabase(connectionDriver);
        }
        if (UtilitesClass::GetValueFromMap(AllSettingsMap, "UseSQLPort") == "true") {
            std::string connectionString = "DRIVER={ODBC Driver 17 for SQL Server};SERVER=tcp:" +
                    UtilitesClass::GetValueFromMap(AllSettingsMap, "IpSqlServer") + "\\" +
                    UtilitesClass::GetValueFromMap(AllSettingsMap, "ServerNameSql") + "," +
                    UtilitesClass::GetValueFromMap(AllSettingsMap, "PortSqlServer") +
                    ";DATABASE=" + UtilitesClass::GetValueFromMap(AllSettingsMap, "DatabaseSql") +
                    ";UID=" + UtilitesClass::GetValueFromMap(AllSettingsMap, "UserSql") +
                    ";PWD=" + UtilitesClass::GetValueFromMap(AllSettingsMap, "PasswordSql");
            qdb.setDatabaseName(QString::fromStdString(connectionString));
        } else {
            std::string connectionString = "DRIVER={ODBC Driver 17 for SQL Server};SERVER=tcp:" +
                    UtilitesClass::GetValueFromMap(AllSettingsMap, "IpSqlServer") + "\\" +
                    UtilitesClass::GetValueFromMap(AllSettingsMap, "ServerNameSql") +
                    ";DATABASE=" + UtilitesClass::GetValueFromMap(AllSettingsMap, "DatabaseSql") +
                    ";UID=" + UtilitesClass::GetValueFromMap(AllSettingsMap, "UserSql") +
                    ";PWD=" + UtilitesClass::GetValueFromMap(AllSettingsMap, "PasswordSql");
            qdb.setDatabaseName(QString::fromStdString(connectionString));
        }
        if (qdb.open()) {
            QSqlQuery query(qdb);
            query.prepare("INSERT INTO " + QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettingsMap, "TableDataSql")) + " (" +
                          QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettingsMap, "RowsDataSql_1")) + ", " +
                          QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettingsMap, "RowsDataSql_2")) + ", " +
                          QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettingsMap, "RowsDataSql_3")) + ", " +
                          QString::fromStdString(UtilitesClass::GetValueFromMap(AllSettingsMap, "RowsDataSql_4")) + ") " +
                          "VALUES (:device, :value, :alarm, GETDATE())");
            query.bindValue(":device", QString::fromStdString(device_row));
            query.bindValue(":value", value_row);
            query.bindValue(":alarm", alarm_row);
            query.exec();
            qdb.close();
        } else {
            UtilitesClass::PrintValueToConsole("error to open sql");
        }
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}
/********** SQLClass **********/



/********** UtilitesClass **********/
std::string UtilitesClass::GetValueFromMap(std::map <std::string, std::string> Map, std::string Key)
{
    try {
        std::string value = "";
        for (auto& map_elem : Map)
            if(map_elem.first == Key){
                value = map_elem.second;
            }
        return value;
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
        return "";
    }
}

std::string UtilitesClass::GetUrlFromIp(std::map <std::string, std::string> Map, std::string Ip)
{
    try {
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
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
        return "";
    }
}

void UtilitesClass::PrintValueToConsole(std::string Value)
{
    try {
        QDateTime time;
        std::string text = "console : " + time.currentDateTime().toString().toStdString() + " " + Value;
        std::cout << text << std::endl;
    }  catch (std::string error) {
        QDateTime time;
        std::cout << time.currentDateTime().toString().toStdString() + error << std::endl;
    }
}

void UtilitesClass::WriteResultToTextFile(std::string Result)
{
    try {
        QFile logFile("./result.txt");
        if  (logFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
            QTextStream stream(&logFile);
            QDateTime time;
            std::string text = "console : " + time.currentDateTime().toString().toStdString() + " " + Result;
            std::cout << text << std::endl;
            stream << QString::fromStdString(text) << '\n';
            logFile.close();
        }
    }  catch (std::string error) {
        UtilitesClass::PrintValueToConsole(error);
    }
}

void UtilitesClass::WriteTextErrorToLogFile(std::string Text)
{
    try {
        QFile logFile("./log.txt");
        if  (logFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
            QTextStream stream(&logFile);
            QDateTime time;
            std::string text = "console : " + time.currentDateTime().toString().toStdString() + " " + Text;
            std::cout << text << std::endl;
            stream << QString::fromStdString(text) << '\n';
            logFile.close();
        }
    }  catch (std::string error) {
        UtilitesClass::PrintValueToConsole(error);
    }
}

std::string UtilitesClass::GetLocalTime()
{
    try {
        QDateTime time;
        return time.currentDateTime().toString().toStdString();
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
        return "";
    }
}

std::string UtilitesClass::GetConvertedQt_obj(QCheckBox *value)
{
    try {
        if (value->isChecked() == 1) {
            return "true";
        }
        return "false";
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
        return "";
    }
}
std::string UtilitesClass::GetConvertedQt_obj(QSpinBox *value)
{
    try {
        return std::to_string(value->value());
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
        return "";
    }
}
std::string UtilitesClass::GetConvertedQt_obj(QDoubleSpinBox *value)
{
    try {
        return std::to_string(value->value());
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
        return "";
    }
}
std::string UtilitesClass::GetConvertedQt_obj(QLineEdit *value)
{
    try {
        return value->text().trimmed().toStdString();
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
        return "";
    }
}
std::string UtilitesClass::GetConvertedQt_obj(QTextEdit *value)
{
    try {
        return value->toPlainText().trimmed().toStdString();
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
        return "";
    }
}
std::string UtilitesClass::GetConvertedQt_obj(QComboBox *value)
{
    try {
        return value->currentText().toStdString();
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
        return "";
    }
}
std::string UtilitesClass::GetConvertedQt_obj(QSlider *value)
{
    try {
        return std::to_string(value->value());
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
        return "";
    }
}

void UtilitesClass::SetConvertedQt_obj(QCheckBox *value, QString text)
{
    try {
        if (text == "true") {
            value->setChecked(true);
        } else {
            value->setChecked(false);
        }
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}
void UtilitesClass::SetConvertedQt_obj(QSpinBox *value, QString text)
{
    try {
        value->setValue(std::stoi(text.toStdString()));
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}
void UtilitesClass::SetConvertedQt_obj(QDoubleSpinBox *value, QString text)
{
    try {
        value->setValue(std::stod(text.toStdString()));
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}
void UtilitesClass::SetConvertedQt_obj(QLineEdit *value, QString text)
{
    try {
        value->setText(text);
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}
void UtilitesClass::SetConvertedQt_obj(QTextEdit *value, QString text)
{
    try {
        value->setText(text);
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}
void UtilitesClass::SetConvertedQt_obj(QComboBox *value, QString text)
{
    try {
        value->setCurrentText(text);
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}
void UtilitesClass::SetConvertedQt_obj(QSlider *value, QString text)
{
    try {
        value->setValue(std::stoi(text.toStdString()));
    }  catch (std::string error) {
        UtilitesClass::WriteTextErrorToLogFile(error);
    }
}
/********** UtilitesClass **********/
