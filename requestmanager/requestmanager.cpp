#include "requestmanager.h"

#include <QtCore>
#include <QtWidgets>
#include <QtNetwork>
#include <QtSql>
#include <QtConcurrent>

RequestManager::RequestManager(QWidget *parent)
    : QMainWindow(parent)
{
    m_ppb = new QProgressBar;
    m_ptxt = new QLineEdit;
    m_pcmd = new QPushButton(tr("&Go"));

    QGridLayout* pLayout = new QGridLayout;
    pLayout->addWidget(m_ptxt, 0, 0);
    pLayout->addWidget(m_pcmd, 0, 1);
    pLayout->addWidget(m_ppb, 1, 0, 1, 1);
    setLayout(pLayout);

}

RequestManager::~RequestManager()
{
}

