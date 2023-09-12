#include "register.h"
#include "ui_register.h"
#include "libraryclient.h"

#include <QMessageBox>

CRegister::CRegister(QWidget *parent) : QWidget(parent), ui(new Ui::CRegister)
{
    ui->setupUi(this);
    connect(ui->Button_ok, SIGNAL(clicked(bool)), this, SLOT(CRegisterUser()));
    connect(ui->Button_Back, SIGNAL(clicked(bool)), this, SLOT(Back()));
    ui->Register_Password->setEchoMode(QLineEdit::Password);
    ui->Register_Password2->setEchoMode(QLineEdit::Password);
    setWindowTitle("注册");
}

CRegister::~CRegister()
{
    delete ui;
}

CRegister &CRegister::GetInstance()
{
    static CRegister instance;
    return instance;
}

/**
 * @brief CRegister::CRegisterUser
 * 注册用户
 */

void CRegister::CRegisterUser()
{
    QString Username = ui->Register_Username->text();
    QString Password = ui->Register_Password->text();
    QString SecondPassword = ui->Register_Password2->text();
    if (!Username.isEmpty() && !Password.isEmpty())
    {
        if (Username.size() <= 20 && Password.size() <= 20)
        {
            if (Password.compare(SecondPassword) == 0)
            {
                Information *information = PrepareInformation(0);
                information->InformationType = RegisterRequest;
                strncpy(information->Username, Username.toStdString().c_str(), 20);
                strncpy(information->Password, Password.toStdString().c_str(), 20);
                CLibraryClient::GetInstance().GetTcpSocket().write((char*)information, information->InformationLength);
                free(information);
                information = NULL;
            }
            else
            {
                QMessageBox::critical(this, "注册", "密码与确认密码不一致！");
            }
        }
        else
        {
            QMessageBox::critical(this, "注册", "用户名或密码长度必须小于20！");
        }
    }
    else
    {
        QMessageBox::critical(this, "注册", "用户名或密码不能为空！");
    }
}

/**
 * @brief CRegister::Back
 * 返回
 */

void CRegister::Back()
{
    this->hide();
}

void CRegister::Clear()
{
    ui->Register_Username->clear();
    ui->Register_Password->clear();
    ui->Register_Password2->clear();
}
