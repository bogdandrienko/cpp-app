/****************************************************************************
**
** Copyright (C) 2020 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "httpwindow.h"

#include "ui_authenticationdialog.h"

#include <QtWidgets>
#include <QtNetwork>
#include <QUrl>
#include <QPixmap>

#include <algorithm>
#include <memory>

#include <iostream>
#include "windows.h"
#include <QDataStream>
#include <typeinfo>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


#if QT_CONFIG(ssl)
const char defaultUrl[] = "http://via.placeholder.com/300.jpg";
#else
const char defaultUrl[] = "http://www.qt.io/";
#endif
const char defaultFileName[] = "1.jpg";

ProgressDialog::ProgressDialog(const QUrl &url, QWidget *parent)
  : QProgressDialog(parent)
{
    setWindowTitle(tr("Download Progress"));
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setLabelText(tr("Downloading %1.").arg(url.toDisplayString()));
    setMinimum(0);
    setValue(0);
    setMinimumDuration(0);
    setMinimumSize(QSize(400, 75));
}

void ProgressDialog::networkReplyProgress(qint64 bytesRead, qint64 totalBytes)
{
    setMaximum(totalBytes);
    setValue(bytesRead);
}

HttpWindow::HttpWindow(QWidget *parent)
    : QDialog(parent)
    , statusLabel(new QLabel(tr("Please enter the URL of a file you want to download.\n\n"), this))
    , urlLineEdit(new QLineEdit(defaultUrl))
    , downloadButton(new QPushButton(tr("Download")))
    , launchCheckBox(new QCheckBox("Launch file"))
    , defaultFileLineEdit(new QLineEdit(defaultFileName))
    , downloadDirectoryLineEdit(new QLineEdit)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle(tr("HTTP"));



    QFormLayout *formLayout = new QFormLayout;
    urlLineEdit->setClearButtonEnabled(true);
    connect(urlLineEdit, &QLineEdit::textChanged, this, &HttpWindow::enableDownloadButton);
    formLayout->addRow(tr("&URL:"), urlLineEdit);
    QString downloadDirectory = "C:/Images";
    if (downloadDirectory.isEmpty() || !QFileInfo(downloadDirectory).isDir())
        downloadDirectory = QDir::currentPath();
    downloadDirectoryLineEdit->setText(QDir::toNativeSeparators(downloadDirectory));
    formLayout->addRow(tr("&Download directory:"), downloadDirectoryLineEdit);
    formLayout->addRow(tr("Default &file:"), defaultFileLineEdit);
    launchCheckBox->setChecked(true);
    formLayout->addRow(launchCheckBox);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);

    mainLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding));

    statusLabel->setWordWrap(true);
    mainLayout->addWidget(statusLabel);

    downloadButton->setDefault(true);
    connect(downloadButton, &QAbstractButton::clicked, this, &HttpWindow::downloadFile);
    QPushButton *quitButton = new QPushButton(tr("Quit"));
    quitButton->setAutoDefault(false);
    connect(quitButton, &QAbstractButton::clicked, this, &QWidget::close);
    QDialogButtonBox *buttonBox = new QDialogButtonBox;
    buttonBox->addButton(downloadButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);
    mainLayout->addWidget(buttonBox);

    urlLineEdit->setFocus();
}
HttpWindow::~HttpWindow() = default;

void HttpWindow::startRequest(const QUrl &requestedUrl)
{
    download();
    bool next = false;
    if(next)
    {
            //! [qnam-auth-required-1]
            connect(&qnam, &QNetworkAccessManager::authenticationRequired,
                    this, &HttpWindow::slotAuthenticationRequired);
            //! [qnam-auth-required-1]
            url = requestedUrl;
            httpRequestAborted = false;

            //! [qnam-download]
            reply.reset(qnam.get(QNetworkRequest(url)));
            //! [qnam-download]
            //! [connecting-reply-to-slots]
            connect(reply.get(), &QNetworkReply::finished, this, &HttpWindow::httpFinished);
            //! [networkreply-readyread-1]
            connect(reply.get(), &QIODevice::readyRead, this, &HttpWindow::httpReadyRead);
            //! [networkreply-readyread-1]
        #if QT_CONFIG(ssl)
            //! [sslerrors-1]
            connect(reply.get(), &QNetworkReply::sslErrors, this, &HttpWindow::sslErrors);
            //! [sslerrors-1]
        #endif
            //! [connecting-reply-to-slots]

            ProgressDialog *progressDialog = new ProgressDialog(url, this);
            progressDialog->setAttribute(Qt::WA_DeleteOnClose);
            connect(progressDialog, &QProgressDialog::canceled, this, &HttpWindow::cancelDownload);
            connect(reply.get(), &QNetworkReply::downloadProgress,
                    progressDialog, &ProgressDialog::networkReplyProgress);
            connect(reply.get(), &QNetworkReply::finished, progressDialog, &ProgressDialog::hide);
            progressDialog->show();

            statusLabel->setText(tr("Downloading %1...").arg(url.toString()));
    }
}

void HttpWindow::downloadFile()
{
    download();
    bool next = false;
    if(next)
    {
                const QString urlSpec = urlLineEdit->text().trimmed();
                if (urlSpec.isEmpty())
                    return;

                const QUrl newUrl = QUrl::fromUserInput(urlSpec);
                if (!newUrl.isValid()) {
                    QMessageBox::information(this, tr("Error"),
                                             tr("Invalid URL: %1: %2").arg(urlSpec, newUrl.errorString()));
                    return;
                }

                QString fileName = newUrl.fileName();
                if (fileName.isEmpty())
                    fileName = defaultFileLineEdit->text().trimmed();
                if (fileName.isEmpty())
                    fileName = defaultFileName;
                QString downloadDirectory = QDir::cleanPath(downloadDirectoryLineEdit->text().trimmed());
                bool useDirectory = !downloadDirectory.isEmpty() && QFileInfo(downloadDirectory).isDir();
                if (useDirectory)
                    fileName.prepend(downloadDirectory + '/');
                if (QFile::exists(fileName)) {
                    if (QMessageBox::question(this, tr("Overwrite Existing File"),
                                              tr("There already exists a file called %1%2."
                                                 " Overwrite?")
                                                 .arg(fileName,
                                                      useDirectory
                                                       ? QString()
                                                       : QStringLiteral(" in the current directory")),
                                                 QMessageBox::Yes | QMessageBox::No,
                                                 QMessageBox::No)
                        == QMessageBox::No) {
                        return;
                    }
                    QFile::remove(fileName);
                }

                file = openFileForWrite(fileName);
                if (!file)
                    return;

                downloadButton->setEnabled(false);

                // schedule the request
                startRequest(newUrl);
    }
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

void HttpWindow::cancelDownload()
{
    statusLabel->setText(tr("Download canceled."));
    httpRequestAborted = true;
    reply->abort();
    downloadButton->setEnabled(true);
}

void HttpWindow::httpFinished()
{
    QFileInfo fi;
    if (file) {
        fi.setFile(file->fileName());
        file->close();
        file.reset();
    }

    //! [networkreply-error-handling-1]
    QNetworkReply::NetworkError error = reply->error();
    const QString &errorString = reply->errorString();
    //! [networkreply-error-handling-1]
    reply.reset();
    //! [networkreply-error-handling-2]
    if (error != QNetworkReply::NoError) {
        QFile::remove(fi.absoluteFilePath());
        // For "request aborted" we handle the label and button in cancelDownload()
        if (!httpRequestAborted) {
            statusLabel->setText(tr("Download failed:\n%1.").arg(errorString));
            downloadButton->setEnabled(true);
        }
        return;
    }
    //! [networkreply-error-handling-2]

    statusLabel->setText(tr("Downloaded %1 bytes to %2\nin\n%3")
                                 .arg(fi.size())
                                 .arg(fi.fileName(), QDir::toNativeSeparators(fi.absolutePath())));
    if (launchCheckBox->isChecked())
        QDesktopServices::openUrl(QUrl::fromLocalFile(fi.absoluteFilePath()));
    downloadButton->setEnabled(true);
}

//! [networkreply-readyread-2]
void HttpWindow::httpReadyRead()
{
    // This slot gets called every time the QNetworkReply has new data.
    // We read all of its new data and write it into the file.
    // That way we use less RAM than when reading it at the finished()
    // signal of the QNetworkReply
    if (file)
        file->write(reply->readAll());
}
//! [networkreply-readyread-2]

void HttpWindow::enableDownloadButton()
{
    downloadButton->setEnabled(!urlLineEdit->text().isEmpty());
}

//! [qnam-auth-required-2]
void HttpWindow::slotAuthenticationRequired(QNetworkReply *, QAuthenticator *authenticator)
{
    QDialog authenticationDialog;
    Ui::Dialog ui;
    ui.setupUi(&authenticationDialog);
    authenticationDialog.adjustSize();
    ui.siteDescription->setText(tr("%1 at %2").arg(authenticator->realm(), url.host()));

    // Did the URL have information? Fill the UI.
    // This is only relevant if the URL-supplied credentials were wrong
    ui.userEdit->setText(url.userName());
    ui.passwordEdit->setText(url.password());

    if (authenticationDialog.exec() == QDialog::Accepted) {
        authenticator->setUser(ui.userEdit->text());
        authenticator->setPassword(ui.passwordEdit->text());
    }
}
//! [qnam-auth-required-2]

#if QT_CONFIG(ssl)
//! [sslerrors-2]
void HttpWindow::sslErrors(const QList<QSslError> &errors)
{
    QString errorString;
    for (const QSslError &error : errors) {
        if (!errorString.isEmpty())
            errorString += '\n';
        errorString += error.errorString();
    }

    if (QMessageBox::warning(this, tr("SSL Errors"),
                             tr("One or more SSL errors has occurred:\n%1").arg(errorString),
                             QMessageBox::Ignore | QMessageBox::Abort) == QMessageBox::Ignore) {
        reply->ignoreSslErrors();
    }
}
//! [sslerrors-2]

void HttpWindow::download()
{
    url = "http://via.placeholder.com/1000.jpg";
//    url = "http://192.168.15.203:80/ISAPI/Streaming/channels/101/picture?snapShotImageType=JPEG";
    connect(&qnam, &QNetworkAccessManager::authenticationRequired, this, &HttpWindow::authentication);
    reply.reset(qnam.get(QNetworkRequest(url)));
    connect(reply.get(), &QNetworkReply::finished, this, &HttpWindow::write);
}

void HttpWindow::authentication(QNetworkReply *, QAuthenticator *authenticator)
{
    authenticator->setUser("admin");
    authenticator->setPassword("q1234567");
}


void HttpWindow::write()
{
//    file = openFileForWrite("C:\\Images\\1.jpg");
//    file->write(reply->readAll());
//    file->close();

    cv::Mat image_source = cv::imread("C:\\Images\\1.jpg", cv::IMREAD_COLOR);
    cv::Mat mask = cv::imread("C:\\Images\\2.jpg", 0);
    cv::Mat bitwise_and;
    cv::bitwise_and(image_source, image_source, bitwise_and, mask);
    cv::Mat cvtcolor;
    cv::cvtColor(bitwise_and, cvtcolor, cv::COLOR_BGR2HSV);
    cv::Mat inrange;
    cv::inRange(cvtcolor, cv::Scalar(0, 0, 150), cv::Scalar(255, 150 , 255), inrange);
//    inrange.setTo(255, mask > 0);
    cv::Mat final;
    cv::resize(inrange, final, cv::Size(), 0.75, 0.75, cv::INTER_LINEAR);
    int image_white_pixels = cv::countNonZero(inrange > 120);
    int mask_white_pixels = cv::countNonZero(mask);
    cv::putText(final, std::to_string(double(image_white_pixels) / double(mask_white_pixels) * 100) + "%",
                cv::Point(150, 50), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(255, 255, 255), 2);
    cv::namedWindow("render", cv::WINDOW_AUTOSIZE);
    cv::imshow("render", final);
}

#endif
