#include "libraryclient.h"
#include "ui_libraryclient.h"
#include "Information.h"


#include <QHostAddress>
#include <QMessageBox>
#include <QStyle>

CLibraryClient::CLibraryClient(QWidget *parent) : QWidget(parent), ui(new Ui::CLibraryClient)
{
    ui->setupUi(this);

    Initlize();

    connect(&m_qTcpSocket, SIGNAL(readyRead()), this, SLOT(ReceiveMessage()));
    connect(&m_qTcpSocket, SIGNAL(connected()), this, SLOT(ConnectSuccessful()));
    connect(ui->Button_New, SIGNAL(clicked(bool)), this, SLOT(ClickedRegister()));
    connect(ui->Button_Login, SIGNAL(clicked(bool)), this, SLOT(ClickedLogin()));
    connect(ui->Button_Delete, SIGNAL(clicked(bool)), this, SLOT(ClickedDelete()));

    m_qTcpSocket.connectToHost(QHostAddress(m_qstrIP), m_quiPort);
}

CLibraryClient::~CLibraryClient()
{
    delete ui;
}

/**
 * @brief CLibraryClient::Initlize
 * 初始化参数
 */

void CLibraryClient::Initlize()
{
    setWindowTitle("登陆");
    m_qstrIP = "127.0.0.1";
    m_quiPort = 8888;
    ui->Login_Password->setEchoMode(QLineEdit::Password);
}

CLibraryClient &CLibraryClient::GetInstance()
{
    static CLibraryClient instance;
    return instance;
}

QTcpSocket &CLibraryClient::GetTcpSocket()
{
    return m_qTcpSocket;
}

/**
 * @brief CLibraryClient::ReceiveMessage
 * 接收从套接字传来的消息
 */

void CLibraryClient::ReceiveMessage()
{
    uint informationLength = 0;
    m_qTcpSocket.read((char*)&informationLength, sizeof(uint));
    uint messageLength = informationLength - sizeof(Information);
    Information *information = PrepareInformation(messageLength);
    m_qTcpSocket.read((char*)information + sizeof(uint), informationLength - sizeof(uint));

    switch (information->InformationType)
    {
    case RegisterRespond:
    {
        if (strcmp(information->BookName, "Registration successful") == 0)
        {
            QMessageBox::information(this, "注册", information->BookName);
            CRegister::GetInstance().hide();
        }
        else
        {
            QMessageBox::critical(this, "注册", information->BookName);
        }
        break;
    }
    case DeleteUserRespond:
    {
        if (strcmp(information->BookName, "Logout successful") == 0)
        {
            QMessageBox::information(this, "注销", information->BookName);
            CRegister::GetInstance().hide();
        }
        else
        {
            QMessageBox::critical(this, "注销", information->BookName);
        }
        break;
    }
    case LoginRespond:
    {
        if (strcmp(information->BookName, "Login successful") == 0)
        {
            QMessageBox::information(this, "登陆", information->BookName);
            this->hide();
            CBorrowAndReturn::GetInstance(m_qstrUsername).move(800, 400);
            CBorrowAndReturn::GetInstance(m_qstrUsername).show();
        }
        else
        {
            QMessageBox::critical(this, "登陆", information->BookName);
        }
        break;
    }
    case BorrowRespond:
    {
        CBorrowAndReturn::GetInstance(m_qstrUsername).ShowBorrowPage(information);
        break;
    }
    case ReturnRespond:
    {
        CBorrowAndReturn::GetInstance(m_qstrUsername).ShowReturnPage(information);
        break;
    }
    case ChangeBorrowLineEditRespond:
    {
        CBorrowAndReturn::GetInstance(m_qstrUsername).ShowLineEdit({information->BookName, information->ISBN});
        break;
    }
    case ChangeReturnLineEditRespond:
    {
        CBorrowAndReturn::GetInstance(m_qstrUsername).ShowLineEdit({information->BookName, information->ISBN});
        break;
    }
    case ButtonOkOfBorrowRespond:
    {
        if (strcmp(information->Username, "borrow failed") == 0)
        {
            QMessageBox::critical(this, "借书", "borrow failed");
            CBorrowAndReturn::GetInstance(m_qstrUsername).FreshPage();
        }
        else
        {
            CBorrowAndReturn::GetInstance(m_qstrUsername).FreshPage();
        }
        break;
    }
    case ButtonOkOfReturnRespond:
    {
        CBorrowAndReturn::GetInstance(m_qstrUsername).FreshPage();
        break;
    }
    default:
    {
        break;
    }
    }
    free(information);
    information = NULL;
}

void CLibraryClient::ConnectSuccessful()
{
    qDebug() << "Connect Success";
}

/**
 * @brief CLibraryClient::ClickedRegister
 * 点击注册按钮
 */

void CLibraryClient::ClickedRegister()
{
    CRegister::GetInstance().Clear();
    CRegister::GetInstance().move(850, 400);
    CRegister::GetInstance().show();
}

/**
 * @brief CLibraryClient::ClickedLogin
 * 登陆
 */

void CLibraryClient::ClickedLogin()
{
    QString Username = ui->Login_Username->text();
    QString Password = ui->Login_Password->text();
    if (!Username.isEmpty() && !Password.isEmpty())
    {
        if (Username.size() <= 20 && Password.size() <= 20)
        {
            m_qstrUsername = Username;
            Information *information = PrepareInformation(0);
            information->InformationType = LoginRequest;
            strncpy(information->Username, Username.toStdString().c_str(), 20);
            strncpy(information->Password, Password.toStdString().c_str(), 20);
            m_qTcpSocket.write((char*)information, information->InformationLength);
            free(information);
            information = NULL;
        }
        else
        {
            QMessageBox::critical(this, "登陆", "用户名或密码长度必须小于20！");
        }
    }
    else
    {
        QMessageBox::critical(this, "登陆", "用户名或密码不能为空！");
    }
}

/**
 * @brief CLibraryClient::ClickedDelete
 * 点击注销按钮
 */

void CLibraryClient::ClickedDelete()
{
    CDelete::GetInstance().Clear();
    CDelete::GetInstance().move(850, 400);
    CDelete::GetInstance().show();
}

