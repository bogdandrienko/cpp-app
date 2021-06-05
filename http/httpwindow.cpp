#include "httpwindow.h"
#include "ui_authenticationdialog.h"

#include <QtWidgets>
#include <QtNetwork>

#include <opencv2/opencv.hpp>

HttpWindow::HttpWindow(QWidget *parent)
    : QDialog(parent)
    , downloadButton(new QPushButton(tr("Download")))
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle(tr("HTTP"));

    QFormLayout *formLayout = new QFormLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);

    mainLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding));

    downloadButton->setDefault(true);
    connect(downloadButton, &QAbstractButton::clicked, this, &HttpWindow::download_from_url);
    QPushButton *quitButton = new QPushButton(tr("Quit"));
    quitButton->setAutoDefault(false);
    connect(quitButton, &QAbstractButton::clicked, this, &QWidget::close);
    QDialogButtonBox *buttonBox = new QDialogButtonBox;
    buttonBox->addButton(downloadButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);
    mainLayout->addWidget(buttonBox);
}
HttpWindow::~HttpWindow() = default;

void HttpWindow::download_from_url()
{
    connect(&qnam, &QNetworkAccessManager::authenticationRequired, this, &HttpWindow::authentication_to_access);
    reply.reset(qnam.get(QNetworkRequest(QString::fromStdString(url_v))));
//    connect(reply.get(), &QIODevice::readyRead, this, &HttpWindow::write_to_file);
    connect(reply.get(), &QNetworkReply::finished, this, &HttpWindow::write_to_file);
}

void HttpWindow::authentication_to_access(QNetworkReply *, QAuthenticator *authenticator)
{
    authenticator->setUser("admin");
    authenticator->setPassword("q1234567");
}

std::unique_ptr<QFile> HttpWindow::openFileForWrite(const QString &fileName)
{
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

void HttpWindow::write_to_file()
{
    file = openFileForWrite(QString::fromStdString(path_source_v));
    file->write(reply->readAll());
    file->close();
    analyse_from_image();
}

void HttpWindow::analyse_from_image()
{
    time_t t = time(NULL);

    cv::Mat image_source = cv::imread(path_source_v, cv::IMREAD_COLOR);
    cv::Mat mask = cv::imread(path_mask_v, 0);
    cv::Mat bitwise_and;
    cv::bitwise_and(image_source, image_source, bitwise_and, mask);
    cv::Mat cvtcolor;
    cv::cvtColor(bitwise_and, cvtcolor, cv::COLOR_BGR2HSV);
    cv::Mat inrange;
    cv::inRange(cvtcolor, cv::Scalar(0, 0, 150), cv::Scalar(255, 150 , 255), inrange);
//    inrange.setTo(255, mask > 0);
    cv::Mat final;
    cv::resize(inrange, final, cv::Size(), 0.4, 0.4, cv::INTER_LINEAR);
    int image_white_pixels = cv::countNonZero(inrange > 120);
    int mask_white_pixels = cv::countNonZero(mask);
    cv::putText(final, asctime(localtime(&t)),
                cv::Point(150, 50), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(255, 255, 255), 2);
    cv::putText(final, std::to_string(double(image_white_pixels) / double(mask_white_pixels) * 100) + "%",
                cv::Point(150, 100), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(255, 255, 255), 2);
    cv::namedWindow("render", cv::WINDOW_AUTOSIZE);
    cv::imshow("render", final);
}

