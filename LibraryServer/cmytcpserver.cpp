#include "cmytcpserver.h"

CMyTcpServer::CMyTcpServer()
{
}

/**
 * @brief CMyTcpServer::GetInstance
 * @return
 * 单例模式返回静态对象
 */

CMyTcpServer &CMyTcpServer::GetInstance()
{
    static CMyTcpServer myTcpServer;
    return myTcpServer;
}

/**
 * @brief CMyTcpServer::incomingConnection
 * @param SocketDescription
 * 当有连接建立，将套接字放入列表，并绑定函数当套接字消失在列表中也删除
 */

void CMyTcpServer::incomingConnection(qintptr SocketDescription)
{
    CMyTcpSocket *ptrMyTcpSocket = new CMyTcpSocket;
    ptrMyTcpSocket->setSocketDescriptor(SocketDescription);
    m_mySocketPtrList.append(ptrMyTcpSocket);
    connect(ptrMyTcpSocket, SIGNAL(OffLine(CMyTcpSocket*)), this, SLOT(DeleteSocket(CMyTcpSocket*)));
}

/**
 * @brief CMyTcpServer::DeleteSocket
 * @param myTcpSocket
 * 循环遍历找到对应的套接字并删除
 */

void CMyTcpServer::DeleteSocket(CMyTcpSocket *myTcpSocket)
{
    QList<CMyTcpSocket*>::iterator Item = m_mySocketPtrList.begin();
    for (; Item != m_mySocketPtrList.end(); ++ Item)
    {
        if (*Item == myTcpSocket)
        {
            (*Item)->deleteLater();
            *Item = NULL;
            m_mySocketPtrList.erase(Item);
            break;
        }
    }
}
