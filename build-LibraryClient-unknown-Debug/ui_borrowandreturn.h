/********************************************************************************
** Form generated from reading UI file 'borrowandreturn.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORROWANDRETURN_H
#define UI_BORROWANDRETURN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CBorrowAndReturn
{
public:
    QPushButton *Button_Borrow;
    QPushButton *Button_Return;
    QPushButton *Button_Refersh;
    QLineEdit *LineEdit_BookName;
    QLineEdit *LineEdit_Username;
    QLineEdit *LineEdit_ISBN;
    QPushButton *Button_ok;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QListWidget *listWidget;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *CBorrowAndReturn)
    {
        if (CBorrowAndReturn->objectName().isEmpty())
            CBorrowAndReturn->setObjectName(QString::fromUtf8("CBorrowAndReturn"));
        CBorrowAndReturn->resize(586, 372);
        Button_Borrow = new QPushButton(CBorrowAndReturn);
        Button_Borrow->setObjectName(QString::fromUtf8("Button_Borrow"));
        Button_Borrow->setGeometry(QRect(10, 30, 71, 171));
        Button_Return = new QPushButton(CBorrowAndReturn);
        Button_Return->setObjectName(QString::fromUtf8("Button_Return"));
        Button_Return->setGeometry(QRect(10, 194, 71, 171));
        Button_Refersh = new QPushButton(CBorrowAndReturn);
        Button_Refersh->setObjectName(QString::fromUtf8("Button_Refersh"));
        Button_Refersh->setGeometry(QRect(340, 30, 241, 71));
        LineEdit_BookName = new QLineEdit(CBorrowAndReturn);
        LineEdit_BookName->setObjectName(QString::fromUtf8("LineEdit_BookName"));
        LineEdit_BookName->setGeometry(QRect(340, 190, 241, 25));
        LineEdit_Username = new QLineEdit(CBorrowAndReturn);
        LineEdit_Username->setObjectName(QString::fromUtf8("LineEdit_Username"));
        LineEdit_Username->setGeometry(QRect(340, 130, 241, 25));
        LineEdit_ISBN = new QLineEdit(CBorrowAndReturn);
        LineEdit_ISBN->setObjectName(QString::fromUtf8("LineEdit_ISBN"));
        LineEdit_ISBN->setGeometry(QRect(340, 250, 241, 25));
        Button_ok = new QPushButton(CBorrowAndReturn);
        Button_ok->setObjectName(QString::fromUtf8("Button_ok"));
        Button_ok->setGeometry(QRect(340, 290, 241, 71));
        label = new QLabel(CBorrowAndReturn);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 110, 67, 17));
        label_2 = new QLabel(CBorrowAndReturn);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(340, 170, 67, 17));
        label_3 = new QLabel(CBorrowAndReturn);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(340, 230, 67, 17));
        listWidget = new QListWidget(CBorrowAndReturn);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(90, 30, 241, 331));
        label_4 = new QLabel(CBorrowAndReturn);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 0, 67, 31));
        label_5 = new QLabel(CBorrowAndReturn);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 0, 67, 31));
        label_6 = new QLabel(CBorrowAndReturn);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(440, 0, 67, 31));

        retranslateUi(CBorrowAndReturn);

        QMetaObject::connectSlotsByName(CBorrowAndReturn);
    } // setupUi

    void retranslateUi(QWidget *CBorrowAndReturn)
    {
        CBorrowAndReturn->setWindowTitle(QApplication::translate("CBorrowAndReturn", "Form", nullptr));
        Button_Borrow->setText(QApplication::translate("CBorrowAndReturn", "\345\200\237\344\271\246", nullptr));
        Button_Return->setText(QApplication::translate("CBorrowAndReturn", "\350\277\230\344\271\246", nullptr));
        Button_Refersh->setText(QApplication::translate("CBorrowAndReturn", "\345\210\267\346\226\260", nullptr));
        Button_ok->setText(QApplication::translate("CBorrowAndReturn", "\347\241\256\345\256\232\345\200\237\344\271\246", nullptr));
        label->setText(QApplication::translate("CBorrowAndReturn", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QApplication::translate("CBorrowAndReturn", "\344\271\246\345\220\215", nullptr));
        label_3->setText(QApplication::translate("CBorrowAndReturn", "ISBN\345\217\267", nullptr));
        label_4->setText(QApplication::translate("CBorrowAndReturn", "\345\200\237\344\271\246\345\210\227\350\241\250", nullptr));
        label_5->setText(QApplication::translate("CBorrowAndReturn", "\351\200\211\351\241\271", nullptr));
        label_6->setText(QApplication::translate("CBorrowAndReturn", "\346\223\215\344\275\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CBorrowAndReturn: public Ui_CBorrowAndReturn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORROWANDRETURN_H
