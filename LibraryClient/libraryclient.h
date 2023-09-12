#ifndef _CLibraryClient_H__
#define _CLibraryClient_H__

#include <QWidget>
#include <QTcpSocket>

#include "borrowandreturn.h"
#include "register.h"
#include "delete.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CLibraryClient; }
QT_END_NAMESPACE

class CLibraryClient : public QWidget
{
    Q_OBJECT

public:
    void Initlize();
    static CLibraryClient& GetInstance();
    QTcpSocket& GetTcpSocket();

private:
    CLibraryClient(QWidget *parent = nullptr);
    ~CLibraryClient();

public slots:
    void ReceiveMessage();
    void ConnectSuccessful();
    void ClickedRegister();
    void ClickedLogin();
    void ClickedDelete();

private:
    Ui::CLibraryClient *ui;

    QString m_qstrIP;   // IP
    quint16 m_quiPort;  // 端口号

    QTcpSocket m_qTcpSocket;
    QString m_qstrUsername;
};
#endif // _CLibraryClient_H__
