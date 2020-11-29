/********************************************************************************
** Form generated from reading UI file 'app.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APP_H
#define UI_APP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_appClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButtonGetResult;
    QLineEdit *lineFirstValue;
    QLineEdit *lineSecondValue;
    QLineEdit *lineResultValue;
    QComboBox *comboBox;
    QListView *listView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *appClass)
    {
        if (appClass->objectName().isEmpty())
            appClass->setObjectName(QString::fromUtf8("appClass"));
        appClass->resize(1100, 794);
        centralWidget = new QWidget(appClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButtonGetResult = new QPushButton(centralWidget);
        pushButtonGetResult->setObjectName(QString::fromUtf8("pushButtonGetResult"));
        pushButtonGetResult->setGeometry(QRect(400, 120, 75, 23));
        lineFirstValue = new QLineEdit(centralWidget);
        lineFirstValue->setObjectName(QString::fromUtf8("lineFirstValue"));
        lineFirstValue->setGeometry(QRect(70, 120, 113, 20));
        lineSecondValue = new QLineEdit(centralWidget);
        lineSecondValue->setObjectName(QString::fromUtf8("lineSecondValue"));
        lineSecondValue->setGeometry(QRect(280, 120, 113, 20));
        lineResultValue = new QLineEdit(centralWidget);
        lineResultValue->setObjectName(QString::fromUtf8("lineResultValue"));
        lineResultValue->setGeometry(QRect(490, 120, 113, 20));
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(190, 120, 69, 22));
        listView = new QListView(centralWidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(180, 180, 256, 192));
        appClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(appClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1100, 21));
        appClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(appClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        appClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(appClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        appClass->setStatusBar(statusBar);

        retranslateUi(appClass);
        QObject::connect(lineSecondValue, SIGNAL(textEdited(QString)), appClass, SLOT(changeInputText()));
        QObject::connect(pushButtonGetResult, SIGNAL(clicked()), appClass, SLOT(pushButton()));

        QMetaObject::connectSlotsByName(appClass);
    } // setupUi

    void retranslateUi(QMainWindow *appClass)
    {
        appClass->setWindowTitle(QCoreApplication::translate("appClass", "app", nullptr));
        pushButtonGetResult->setText(QCoreApplication::translate("appClass", "PushButton", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("appClass", "=", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("appClass", "+", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("appClass", "-", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("appClass", "*", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("appClass", "/", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("appClass", "%", nullptr));

    } // retranslateUi

};

namespace Ui {
    class appClass: public Ui_appClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_H
