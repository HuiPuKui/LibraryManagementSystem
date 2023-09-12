#include "cmytcpsocket.h"
#include "Information.h"
#include "cdatabase.h"

CMyTcpSocket::CMyTcpSocket()
{
    connect(this, SIGNAL(readyRead()), this, SLOT(ReceiveMessage()));
    connect(this, SIGNAL(disconnected()), this, SLOT(SendOffLine()));
}

QString CMyTcpSocket::GetUsername()
{
    return m_qstrUsername;
}

/**
 * @brief CMyTcpSocket::SendOffLine
 * 向服务器发送套接字已掉线的信号
 */

void CMyTcpSocket::SendOffLine()
{
    CDatabase::GetInstance().OffLine(GetUsername());
    emit OffLine(this);
}

/**
 * @brief CMyTcpSocket::ReceiveMessage
 * 接收套接字的 Request 并返回 Respond
 */

void CMyTcpSocket::ReceiveMessage()
{
    uint informationLength = 0;
    this->read((char*)&informationLength, sizeof(uint));
    uint messageLength = informationLength - sizeof(Information);
    Information *information = PrepareInformation(messageLength);
    this->read((char*)information + sizeof(uint), informationLength - sizeof(uint));

    switch (information->InformationType)
    {
    case RegisterRequest:
    {
        QString Result = CDatabase::GetInstance().RegisterUser(information->Username, information->Password);
        Information *reInformation = PrepareInformation(0);
        reInformation->InformationType = RegisterRespond;
        strncpy(reInformation->BookName, Result.toStdString().c_str(), 100);
        this->write((char*)reInformation, reInformation->InformationLength);
        free(reInformation);
        reInformation = NULL;
        break;
    }
    case DeleteUserRequest:
    {
        QString Result = CDatabase::GetInstance().DeleteUser(information->Username, information->Password);
        Information *reInformation = PrepareInformation(0);
        reInformation->InformationType = DeleteUserRespond;
        strncpy(reInformation->BookName, Result.toStdString().c_str(), 100);
        this->write((char*)reInformation, reInformation->InformationLength);
        free(reInformation);
        reInformation = NULL;
        break;
    }
    case LoginRequest:
    {
        QString Result = CDatabase::GetInstance().Login(information->Username, information->Password);
        if (Result.compare("Login successful") == 0)
        {
            m_qstrUsername = information->Username;
        }
        Information *reInformation = PrepareInformation(0);
        reInformation->InformationType = LoginRespond;
        strncpy(reInformation->BookName, Result.toStdString().c_str(), 100);
        this->write((char*)reInformation, reInformation->InformationLength);
        free(reInformation);
        reInformation = NULL;
        break;
    }
    case BorrowRequest:
    {
        QStringList Result = CDatabase::GetInstance().SelectAllBook();
        Information *reInformation = PrepareInformation(Result.size() * 100);
        reInformation->InformationType = BorrowRespond;
        for (int i = 0; i < Result.size(); ++ i)
        {
            memcpy((char*)(reInformation->Message) + i * 100
                   , Result.at(i).toStdString().c_str()
                   , Result.at(i).size());
        }

        this->write((char*)reInformation, reInformation->InformationLength);
        free(reInformation);
        reInformation = NULL;
        break;
    }
    case ReturnRequest:
    {
        QStringList Result = CDatabase::GetInstance().SelectAllHave(information->Username);
        Information *reInformation = PrepareInformation(Result.size() * 100);
        reInformation->InformationType = ReturnRespond;

        for (int i = 0; i < Result.size(); ++ i)
        {
            memcpy((char*)(reInformation->Message) + i * 100
                   , Result.at(i).toStdString().c_str()
                   , Result.at(i).size());
        }

        this->write((char*)reInformation, reInformation->InformationLength);
        free(reInformation);
        reInformation = NULL;
        break;
    }
    case ChangeBorrowLineEditRequest:
    {
        QPair<QString, QString> Result = CDatabase::GetInstance().SelectBookNameFormLibrary(information->BookName);
        Information *reInformation = PrepareInformation(0);
        reInformation->InformationType = ChangeBorrowLineEditRespond;
        strncpy(reInformation->BookName, Result.first.toStdString().c_str(), 100);
        strncpy(reInformation->ISBN, Result.second.toStdString().c_str(), 100);
        this->write((char*)reInformation, reInformation->InformationLength);
        free(reInformation);
        reInformation = NULL;
        break;
    }
    case ChangeReturnLineEditRequest:
    {
        QPair<QString, QString> Result = CDatabase::GetInstance().SelectBookNameFormBorrowingRecord(information->BookName);
        Information *reInformation = PrepareInformation(0);
        reInformation->InformationType = ChangeReturnLineEditRespond;
        strncpy(reInformation->BookName, Result.first.toStdString().c_str(), 100);
        strncpy(reInformation->ISBN, Result.second.toStdString().c_str(), 100);
        this->write((char*)reInformation, reInformation->InformationLength);
        free(reInformation);
        reInformation = NULL;
        break;
    }
    case ButtonOkOfBorrowRequest:
    {
        bool Result = CDatabase::GetInstance().TurnBookFromLibraryToUser(information->Username, information->BookName, information->ISBN);
        Information *reInformation = PrepareInformation(0);
        reInformation->InformationType = ButtonOkOfBorrowRespond;
        if (Result == false)
        {
            memcpy((char*)(reInformation->Username), QString("borrow failed").toStdString().c_str(), 20);
        }
        else
        {
            memcpy((char*)(reInformation->Username), QString("borrow successful").toStdString().c_str(), 20);
        }
        this->write((char*)reInformation, reInformation->InformationLength);
        free(reInformation);
        reInformation = NULL;
        break;
    }
    case ButtonOkOfReturnRequest:
    {
        CDatabase::GetInstance().TurnBookFromUserToLibrary(information->Username, information->BookName, information->ISBN);
        Information *reInformation = PrepareInformation(0);
        reInformation->InformationType = ButtonOkOfReturnRespond;
        this->write((char*)reInformation, reInformation->InformationLength);
        free(reInformation);
        reInformation = NULL;
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
