#ifndef _CMYTCPSERVER_H__
#define _CMYTCPSERVER_H__

#include <QTcpServer>
#include <QList>

#include "cmytcpsocket.h"

class CMyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    static CMyTcpServer& GetInstance();
    void incomingConnection(qintptr) override;

private:
    CMyTcpServer();

public slots:
    void DeleteSocket(CMyTcpSocket*);
private:
    QList<CMyTcpSocket*> m_mySocketPtrList; // 所有套接字的列表
};

#endif // _CMYTCPSERVER_H__
