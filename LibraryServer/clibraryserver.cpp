#include "clibraryserver.h"
#include "ui_CLibraryServer.h"

#include <QTcpServer>
#include <QHostAddress>

CLibraryServer::CLibraryServer(QWidget *parent) : QWidget(parent), ui(new Ui::CLibraryServer)
{
    ui->setupUi(this);
    Initilize();
    CMyTcpServer::GetInstance().listen(QHostAddress(m_qstrIP), m_quiPort);
}

CLibraryServer::~CLibraryServer()
{
    delete ui;
}

void CLibraryServer::Initilize()
{
    m_qstrIP = "127.0.0.1";
    m_quiPort = 8888;
}

