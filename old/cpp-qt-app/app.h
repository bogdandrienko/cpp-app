#pragma once
#include "stdafx.h"


class app : public QMainWindow
{
    Q_OBJECT
    std::unique_ptr<QMessageBox>gmb;

public:
    app(QWidget *parent = Q_NULLPTR);

private slots:

    void changeInputText()
    {
        this->close();
    }
    void pushButton()
    {
        gmb->show();
    }
    
private:
    Ui::appClass ui;
};