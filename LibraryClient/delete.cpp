#include "delete.h"
#include "ui_delete.h"
#include "libraryclient.h"

#include <QMessageBox>

CDelete::CDelete(QWidget *parent) : QWidget(parent), ui(new Ui::CDelete)
{
    ui->setupUi(this);
    connect(ui->Button_ok, SIGNAL(clicked(bool)), this, SLOT(DeleteUser()));
    connect(ui->Button_Back, SIGNAL(clicked(bool)), this, SLOT(Back()));
    ui->Delete_Password->setEchoMode(QLineEdit::Password);
    setWindowTitle("注销");
}

CDelete::~CDelete()
{
    delete ui;
}

CDelete &CDelete::GetInstance()
{
    static CDelete instance;
    return instance;
}

void CDelete::Clear()
{
    ui->Delete_Username->clear();
    ui->Delete_Password->clear();
}

/**
 * @brief Delete::DeleteUser
 * 注销用户
 */

void CDelete::DeleteUser()
{
    QString Username = ui->Delete_Username->text();
    QString Password = ui->Delete_Password->text();
    if (!Username.isEmpty() && !Password.isEmpty())
    {
        if (Username.size() <= 20 && Password.size() <= 20)
        {
            Information *information = PrepareInformation(0);
            information->InformationType = DeleteUserRequest;
            strncpy(information->Username, Username.toStdString().c_str(), 20);
            strncpy(information->Password, Password.toStdString().c_str(), 20);
            CLibraryClient::GetInstance().GetTcpSocket().write((char*)information, information->InformationLength);
            free(information);
            information = NULL;
        }
        else
        {
            QMessageBox::critical(this, "注销", "用户名或密码长度必须小于20！");
        }
    }
    else
    {
        QMessageBox::critical(this, "注销", "用户名或密码不能为空！");
    }
}

/**
 * @brief Delete::Back
 * 返回
 */

void CDelete::Back()
{
    this->hide();
}
