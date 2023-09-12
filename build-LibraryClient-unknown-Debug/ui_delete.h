/********************************************************************************
** Form generated from reading UI file 'delete.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE_H
#define UI_DELETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CDelete
{
public:
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *Delete_Username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *Delete_Password;
    QPushButton *Button_ok;
    QPushButton *Button_Back;

    void setupUi(QWidget *CDelete)
    {
        if (CDelete->objectName().isEmpty())
            CDelete->setObjectName(QString::fromUtf8("CDelete"));
        CDelete->resize(302, 291);
        label = new QLabel(CDelete);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 10, 111, 31));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        verticalLayoutWidget = new QWidget(CDelete);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 50, 281, 161));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        Delete_Username = new QLineEdit(verticalLayoutWidget);
        Delete_Username->setObjectName(QString::fromUtf8("Delete_Username"));

        horizontalLayout->addWidget(Delete_Username);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        Delete_Password = new QLineEdit(verticalLayoutWidget);
        Delete_Password->setObjectName(QString::fromUtf8("Delete_Password"));

        horizontalLayout_2->addWidget(Delete_Password);


        verticalLayout_2->addLayout(horizontalLayout_2);

        Button_ok = new QPushButton(CDelete);
        Button_ok->setObjectName(QString::fromUtf8("Button_ok"));
        Button_ok->setGeometry(QRect(10, 230, 121, 51));
        Button_Back = new QPushButton(CDelete);
        Button_Back->setObjectName(QString::fromUtf8("Button_Back"));
        Button_Back->setGeometry(QRect(158, 230, 131, 51));

        retranslateUi(CDelete);

        QMetaObject::connectSlotsByName(CDelete);
    } // setupUi

    void retranslateUi(QWidget *CDelete)
    {
        CDelete->setWindowTitle(QApplication::translate("CDelete", "Form", nullptr));
        label->setText(QApplication::translate("CDelete", "\346\263\250\351\224\200\347\224\250\346\210\267", nullptr));
        label_2->setText(QApplication::translate("CDelete", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_3->setText(QApplication::translate("CDelete", "\345\257\206\347\240\201   \357\274\232", nullptr));
        Button_ok->setText(QApplication::translate("CDelete", "\346\263\250\351\224\200", nullptr));
        Button_Back->setText(QApplication::translate("CDelete", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CDelete: public Ui_CDelete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE_H
