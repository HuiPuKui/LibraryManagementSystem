#include "libraryclient.h"

#include <QApplication>
#include <QDesktopWidget>

#include "borrowandreturn.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CLibraryClient &w = CLibraryClient::GetInstance();
    w.move(850, 400);
    w.show();
    return a.exec();
}
