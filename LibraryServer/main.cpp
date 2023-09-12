#include "clibraryserver.h"
#include "cdatabase.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CDatabase::GetInstance().Initilize();
    CLibraryServer w;
    w.show();
    return a.exec();
}
