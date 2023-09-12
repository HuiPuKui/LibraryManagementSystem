#ifndef _CMYTCPSOCKET_H__
#define _CMYTCPSOCKET_H__

#include <QTcpSocket>

class CMyTcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    CMyTcpSocket();
    QString GetUsername();
signals:
    void OffLine(CMyTcpSocket*);

public slots:
    void SendOffLine();
    void ReceiveMessage();

private:
    QString m_qstrUsername;
};

#endif // _CMYTCPSOCKET_H__
