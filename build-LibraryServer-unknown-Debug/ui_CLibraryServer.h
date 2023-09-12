/********************************************************************************
** Form generated from reading UI file 'clibraryserver.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIBRARYSERVER_H
#define UI_CLIBRARYSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CLibraryServer
{
public:

    void setupUi(QWidget *CLibraryServer)
    {
        if (CLibraryServer->objectName().isEmpty())
            CLibraryServer->setObjectName(QString::fromUtf8("CLibraryServer"));
        CLibraryServer->resize(800, 600);

        retranslateUi(CLibraryServer);

        QMetaObject::connectSlotsByName(CLibraryServer);
    } // setupUi

    void retranslateUi(QWidget *CLibraryServer)
    {
        CLibraryServer->setWindowTitle(QApplication::translate("CLibraryServer", "Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CLibraryServer: public Ui_CLibraryServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIBRARYSERVER_H
