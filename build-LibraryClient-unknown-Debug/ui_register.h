/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CRegister
{
public:
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *Register_Username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *Register_Password;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *Register_Password2;
    QPushButton *Button_ok;
    QPushButton *Button_Back;

    void setupUi(QWidget *CRegister)
    {
        if (CRegister->objectName().isEmpty())
            CRegister->setObjectName(QString::fromUtf8("CRegister"));
        CRegister->resize(302, 291);
        label = new QLabel(CRegister);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 10, 111, 31));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        verticalLayoutWidget = new QWidget(CRegister);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 50, 281, 191));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        Register_Username = new QLineEdit(verticalLayoutWidget);
        Register_Username->setObjectName(QString::fromUtf8("Register_Username"));

        horizontalLayout->addWidget(Register_Username);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        Register_Password = new QLineEdit(verticalLayoutWidget);
        Register_Password->setObjectName(QString::fromUtf8("Register_Password"));

        horizontalLayout_2->addWidget(Register_Password);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        Register_Password2 = new QLineEdit(verticalLayoutWidget);
        Register_Password2->setObjectName(QString::fromUtf8("Register_Password2"));

        horizontalLayout_3->addWidget(Register_Password2);


        verticalLayout->addLayout(horizontalLayout_3);

        Button_ok = new QPushButton(CRegister);
        Button_ok->setObjectName(QString::fromUtf8("Button_ok"));
        Button_ok->setGeometry(QRect(10, 240, 131, 41));
        Button_Back = new QPushButton(CRegister);
        Button_Back->setObjectName(QString::fromUtf8("Button_Back"));
        Button_Back->setGeometry(QRect(168, 240, 121, 41));

        retranslateUi(CRegister);

        QMetaObject::connectSlotsByName(CRegister);
    } // setupUi

    void retranslateUi(QWidget *CRegister)
    {
        CRegister->setWindowTitle(QApplication::translate("CRegister", "Form", nullptr));
        label->setText(QApplication::translate("CRegister", "\347\224\250\346\210\267\346\263\250\345\206\214", nullptr));
        label_2->setText(QApplication::translate("CRegister", "\347\224\250\346\210\267\345\220\215   \357\274\232", nullptr));
        label_3->setText(QApplication::translate("CRegister", "\345\257\206\347\240\201      \357\274\232", nullptr));
        label_4->setText(QApplication::translate("CRegister", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        Button_ok->setText(QApplication::translate("CRegister", "\347\241\256\350\256\244", nullptr));
        Button_Back->setText(QApplication::translate("CRegister", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CRegister: public Ui_CRegister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
