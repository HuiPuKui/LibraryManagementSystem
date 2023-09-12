/********************************************************************************
** Form generated from reading UI file 'libraryclient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBRARYCLIENT_H
#define UI_LIBRARYCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CLibraryClient
{
public:
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *Login_Username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *Login_Password;
    QPushButton *Button_Login;
    QPushButton *Button_Delete;
    QPushButton *Button_New;

    void setupUi(QWidget *CLibraryClient)
    {
        if (CLibraryClient->objectName().isEmpty())
            CLibraryClient->setObjectName(QString::fromUtf8("CLibraryClient"));
        CLibraryClient->resize(302, 291);
        label = new QLabel(CLibraryClient);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 10, 211, 61));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        verticalLayoutWidget = new QWidget(CLibraryClient);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 70, 281, 121));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        Login_Username = new QLineEdit(verticalLayoutWidget);
        Login_Username->setObjectName(QString::fromUtf8("Login_Username"));

        horizontalLayout->addWidget(Login_Username);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        Login_Password = new QLineEdit(verticalLayoutWidget);
        Login_Password->setObjectName(QString::fromUtf8("Login_Password"));

        horizontalLayout_2->addWidget(Login_Password);


        verticalLayout_2->addLayout(horizontalLayout_2);

        Button_Login = new QPushButton(CLibraryClient);
        Button_Login->setObjectName(QString::fromUtf8("Button_Login"));
        Button_Login->setGeometry(QRect(10, 200, 281, 41));
        Button_Delete = new QPushButton(CLibraryClient);
        Button_Delete->setObjectName(QString::fromUtf8("Button_Delete"));
        Button_Delete->setGeometry(QRect(10, 240, 141, 41));
        Button_New = new QPushButton(CLibraryClient);
        Button_New->setObjectName(QString::fromUtf8("Button_New"));
        Button_New->setGeometry(QRect(150, 240, 141, 41));

        retranslateUi(CLibraryClient);

        QMetaObject::connectSlotsByName(CLibraryClient);
    } // setupUi

    void retranslateUi(QWidget *CLibraryClient)
    {
        CLibraryClient->setWindowTitle(QApplication::translate("CLibraryClient", "Widget", nullptr));
        label->setText(QApplication::translate("CLibraryClient", "\345\233\276 \344\271\246 \347\256\241 \347\220\206 \347\263\273 \347\273\237", nullptr));
        label_2->setText(QApplication::translate("CLibraryClient", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_3->setText(QApplication::translate("CLibraryClient", "\345\257\206\347\240\201   \357\274\232", nullptr));
        Button_Login->setText(QApplication::translate("CLibraryClient", "\347\231\273\351\231\206", nullptr));
        Button_Delete->setText(QApplication::translate("CLibraryClient", "\346\263\250\351\224\200", nullptr));
        Button_New->setText(QApplication::translate("CLibraryClient", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CLibraryClient: public Ui_CLibraryClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARYCLIENT_H
