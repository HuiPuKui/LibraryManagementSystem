#ifndef _CLIBRARYSERVER_H__
#define _CLIBRARYSERVER_H__

#include <QWidget>

#include <cmytcpserver.h>

QT_BEGIN_NAMESPACE
namespace Ui { class CLibraryServer; }
QT_END_NAMESPACE

class CLibraryServer : public QWidget
{
    Q_OBJECT

public:
    CLibraryServer(QWidget *parent = nullptr);
    ~CLibraryServer();
    void Initilize(); 

private:
    Ui::CLibraryServer *ui;

    QString m_qstrIP;   // IP
    quint16 m_quiPort;  // 端口号
};
#endif // _CLIBRARYSERVER_H__
