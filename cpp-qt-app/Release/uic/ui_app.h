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
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
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
    QComboBox *comboBox;
    QLCDNumber *lcdNumber;
    QCalendarWidget *calendarWidget;
    QLineEdit *lineEdit;
    QDial *dial;
    QProgressBar *progressBar;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_9;
    QPushButton *pushButton_12;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_11;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_10;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QDoubleSpinBox *doubleSpinBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *appClass)
    {
        if (appClass->objectName().isEmpty())
            appClass->setObjectName(QString::fromUtf8("appClass"));
        appClass->resize(1105, 767);
        appClass->setMinimumSize(QSize(854, 480));
        appClass->setMaximumSize(QSize(3840, 2160));
        centralWidget = new QWidget(appClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButtonGetResult = new QPushButton(centralWidget);
        pushButtonGetResult->setObjectName(QString::fromUtf8("pushButtonGetResult"));
        pushButtonGetResult->setGeometry(QRect(510, 10, 200, 75));
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(950, 20, 69, 22));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(950, 60, 64, 23));
        calendarWidget = new QCalendarWidget(centralWidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(200, 10, 181, 81));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(510, 110, 200, 75));
        lineEdit->setLayoutDirection(Qt::LeftToRight);
        dial = new QDial(centralWidget);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(840, 50, 50, 64));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(820, 20, 118, 23));
        progressBar->setValue(24);
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(210, 200, 805, 229));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(200);
        sizePolicy.setVerticalStretch(75);
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMinimumSize(QSize(200, 75));
        pushButton_3->setMaximumSize(QSize(400, 150));

        gridLayout->addWidget(pushButton_3, 2, 0, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);
        pushButton_9->setMinimumSize(QSize(200, 75));
        pushButton_9->setMaximumSize(QSize(400, 150));

        gridLayout->addWidget(pushButton_9, 2, 2, 1, 1);

        pushButton_12 = new QPushButton(gridLayoutWidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        sizePolicy.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy);
        pushButton_12->setMinimumSize(QSize(200, 75));
        pushButton_12->setMaximumSize(QSize(400, 150));

        gridLayout->addWidget(pushButton_12, 2, 3, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setMinimumSize(QSize(200, 75));
        pushButton_8->setMaximumSize(QSize(400, 150));

        gridLayout->addWidget(pushButton_8, 0, 2, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setMinimumSize(QSize(200, 75));
        pushButton_7->setMaximumSize(QSize(400, 150));

        gridLayout->addWidget(pushButton_7, 1, 2, 1, 1);

        pushButton_11 = new QPushButton(gridLayoutWidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        sizePolicy.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy);
        pushButton_11->setMinimumSize(QSize(200, 75));
        pushButton_11->setMaximumSize(QSize(400, 150));

        gridLayout->addWidget(pushButton_11, 1, 3, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setMinimumSize(QSize(200, 75));
        pushButton_4->setMaximumSize(QSize(400, 150));

        gridLayout->addWidget(pushButton_4, 0, 1, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(200, 75));
        pushButton->setMaximumSize(QSize(400, 150));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setMinimumSize(QSize(200, 75));
        pushButton_5->setMaximumSize(QSize(400, 150));

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_10 = new QPushButton(gridLayoutWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(30);
        sizePolicy1.setVerticalStretch(75);
        sizePolicy1.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy1);
        pushButton_10->setMinimumSize(QSize(200, 75));
        pushButton_10->setMaximumSize(QSize(400, 150));

        gridLayout->addWidget(pushButton_10, 0, 3, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(200, 75));
        pushButton_2->setMaximumSize(QSize(400, 150));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setMinimumSize(QSize(200, 75));
        pushButton_6->setMaximumSize(QSize(400, 150));

        gridLayout->addWidget(pushButton_6, 2, 1, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(centralWidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(920, 100, 62, 22));
        appClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(appClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1105, 21));
        appClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(appClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        appClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(appClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        appClass->setStatusBar(statusBar);

        retranslateUi(appClass);
        QObject::connect(pushButtonGetResult, SIGNAL(clicked()), appClass, SLOT(pushButton()));

        QMetaObject::connectSlotsByName(appClass);
    } // setupUi

    void retranslateUi(QMainWindow *appClass)
    {
        appClass->setWindowTitle(QCoreApplication::translate("appClass", "app", nullptr));
        pushButtonGetResult->setText(QCoreApplication::translate("appClass", "SMART", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("appClass", "=", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("appClass", "+", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("appClass", "-", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("appClass", "*", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("appClass", "/", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("appClass", "%", nullptr));

        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("appClass", "\320\235\320\260\320\271\321\202\320\270 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\265", nullptr));
        pushButton_3->setText(QCoreApplication::translate("appClass", "\320\264\320\270\320\267\320\260\320\271\320\275 \320\272\320\260\320\272 \321\203 \"\320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 windows\"", nullptr));
        pushButton_9->setText(QCoreApplication::translate("appClass", "\320\264\320\270\320\267\320\260\320\271\320\275 \320\272\320\260\320\272 \321\203 \"\320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 windows\"", nullptr));
        pushButton_12->setText(QCoreApplication::translate("appClass", "\320\264\320\270\320\267\320\260\320\271\320\275 \320\272\320\260\320\272 \321\203 \"\320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 windows\"", nullptr));
        pushButton_8->setText(QCoreApplication::translate("appClass", "\320\264\320\270\320\267\320\260\320\271\320\275 \320\272\320\260\320\272 \321\203 \"\320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 windows\"", nullptr));
        pushButton_7->setText(QCoreApplication::translate("appClass", "\320\264\320\270\320\267\320\260\320\271\320\275 \320\272\320\260\320\272 \321\203 \"\320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 windows\"", nullptr));
        pushButton_11->setText(QCoreApplication::translate("appClass", "\320\264\320\270\320\267\320\260\320\271\320\275 \320\272\320\260\320\272 \321\203 \"\320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 windows\"", nullptr));
        pushButton_4->setText(QCoreApplication::translate("appClass", "\320\264\320\270\320\267\320\260\320\271\320\275 \320\272\320\260\320\272 \321\203 \"\320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 windows\"", nullptr));
        pushButton->setText(QCoreApplication::translate("appClass", "\320\264\320\270\320\267\320\260\320\271\320\275 \320\272\320\260\320\272 \321\203 \"\320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 windows\"", nullptr));
        pushButton_5->setText(QCoreApplication::translate("appClass", "\320\264\320\270\320\267\320\260\320\271\320\275 \320\272\320\260\320\272 \321\203 \"\320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 windows\"", nullptr));
        pushButton_10->setText(QCoreApplication::translate("appClass", "\320\264\320\270\320\267\320\260\320\271\320\275 \320\272\320\260\320\272 \321\203 \"\320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 windows\"", nullptr));
        pushButton_2->setText(QCoreApplication::translate("appClass", "\320\264\320\270\320\267\320\260\320\271\320\275 \320\272\320\260\320\272 \321\203 \"\320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 windows\"", nullptr));
        pushButton_6->setText(QCoreApplication::translate("appClass", "\320\264\320\270\320\267\320\260\320\271\320\275 \320\272\320\260\320\272 \321\203 \"\320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 windows\"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class appClass: public Ui_appClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_H
