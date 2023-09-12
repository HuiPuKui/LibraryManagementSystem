#include "borrowandreturn.h"
#include "ui_cborrowandreturn.h"
#include "Information.h"
#include "libraryclient.h"

CBorrowAndReturn::CBorrowAndReturn(QWidget *parent, QString Username) : QWidget(parent), m_qstrUserame(Username), ui(new Ui::CBorrowAndReturn)
{
    ui->setupUi(this);
    m_bPage = false;
    ui->LineEdit_Username->setReadOnly(true);
    ui->LineEdit_BookName->setReadOnly(true);
    ui->LineEdit_ISBN->setReadOnly(true);
    ui->LineEdit_Username->setText(Username);

    connect(ui->Button_Borrow, SIGNAL(clicked(bool)), this, SLOT(TurnToPageBorrow()));
    connect(ui->Button_Return, SIGNAL(clicked(bool)), this, SLOT(TurnToPageReturn()));
    connect(ui->Button_Refersh, SIGNAL(clicked(bool)), this, SLOT(FreshPage()));
    connect(ui->listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(ChangeLineEdit(int)));
    connect(ui->Button_ok, SIGNAL(clicked(bool)), this, SLOT(ClickedButtonOk()));
    setWindowTitle("图书管理系统");
}

CBorrowAndReturn::~CBorrowAndReturn()
{
    delete ui;
}

CBorrowAndReturn &CBorrowAndReturn::GetInstance(QString Username)
{
    static CBorrowAndReturn instance(nullptr, Username);
    return instance;
}

/**
 * @brief CBorrowAndReturn::ShowBorrowPage
 * @param information
 * 切换到借书界面
 */

void CBorrowAndReturn::ShowBorrowPage(const Information * const information)
{
    m_bPage = false;
    ui->LineEdit_BookName->clear();
    ui->LineEdit_ISBN->clear();
    disconnect(ui->listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(ChangeLineEdit(int)));
    ui->listWidget->clear();
    connect(ui->listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(ChangeLineEdit(int)));
    ui->Button_ok->setText("确定借书");
    ui->label_4->setText("借书列表");
    int Size = information->MessageLength / 100;
    char Temp[100] = {'\0'};
    for (int i = 0; i < Size; ++ i)
    {
        memcpy(Temp, (char*)(information->Message) + i * 100, 100);
        ui->listWidget->addItem(Temp);
    }
}

/**
 * @brief CBorrowAndReturn::ShowReturnPage
 * @param information
 * 切换到还书界面
 */

void CBorrowAndReturn::ShowReturnPage(const Information * const information)
{
    m_bPage = true;
    ui->LineEdit_BookName->clear();
    ui->LineEdit_ISBN->clear();
    disconnect(ui->listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(ChangeLineEdit(int)));
    ui->listWidget->clear();
    connect(ui->listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(ChangeLineEdit(int)));
    ui->Button_ok->setText("确定还书");
    ui->label_4->setText("还书列表");
    int Size = information->MessageLength / 100;
    char Temp[100] = {'\0'};
    for (int i = 0; i < Size; ++ i)
    {
        memcpy(Temp, (char*)(information->Message) + i * 100, 100);
        ui->listWidget->addItem(Temp);
    }
}

/**
 * @brief CBorrowAndReturn::ShowLineEdit
 * @param Result
 * 展示选中书的信息
 */

void CBorrowAndReturn::ShowLineEdit(const QPair<QString, QString> &Result)
{
    ui->LineEdit_BookName->clear();
    ui->LineEdit_ISBN->clear();
    ui->LineEdit_BookName->setText(Result.first);
    ui->LineEdit_ISBN->setText(Result.second);
}

/**
 * @brief CBorrowAndReturn::TurnToPageBorrow
 * 点击借书按钮
 */

void CBorrowAndReturn::TurnToPageBorrow()
{
    Information *information = PrepareInformation(0);
    information->InformationType = BorrowRequest;
    CLibraryClient::GetInstance().GetTcpSocket().write((char*)information, information->InformationLength);
    free(information);
    information = NULL;
}

/**
 * @brief CBorrowAndReturn::TurnToPageReturn
 * 点击还书按钮
 */

void CBorrowAndReturn::TurnToPageReturn()
{
    Information *information = PrepareInformation(0);
    information->InformationType = ReturnRequest;
    strncpy(information->Username, m_qstrUserame.toStdString().c_str(), 20);
    CLibraryClient::GetInstance().GetTcpSocket().write((char*)information, information->InformationLength);
    free(information);
    information = NULL;
}

/**
 * @brief CBorrowAndReturn::FreshPage
 * 刷新页面
 */

void CBorrowAndReturn::FreshPage()
{
    if (m_bPage == false)
    {
        TurnToPageBorrow();
    }
    else
    {
        TurnToPageReturn();
    }
    ui->LineEdit_BookName->clear();
    ui->LineEdit_ISBN->clear();
}

/**
 * @brief CBorrowAndReturn::ChangeLineEdit
 * @param Line
 * 选中一本书后，书的信息出现在右侧
 */

void CBorrowAndReturn::ChangeLineEdit(int Line)
{
    Information *information = PrepareInformation(0);
    QString ListWidgetText = ui->listWidget->item(Line)->text();
    strncpy(information->BookName, ListWidgetText.toStdString().c_str(), 100);
    if (m_bPage == false)
    {
        information->InformationType = ChangeBorrowLineEditRequest;
    }
    else
    {
        information->InformationType = ChangeReturnLineEditRequest;
    }
    CLibraryClient::GetInstance().GetTcpSocket().write((char*)information, information->InformationLength);
    free(information);
    information = NULL;
}

/**
 * @brief CBorrowAndReturn::ClickedButtonOk
 * 确定借书 or 还书
 */

void CBorrowAndReturn::ClickedButtonOk()
{
    if (ui->LineEdit_Username->text().size() == 0 || ui->LineEdit_BookName->text().size() == 0 || ui->LineEdit_ISBN->text().size() == 0)
    {
        return ;
    }
    Information *information = PrepareInformation(0);
    if (m_bPage == false)
    {
        information->InformationType = ButtonOkOfBorrowRequest;
    }
    else
    {
        information->InformationType = ButtonOkOfReturnRequest;
    }
    strncpy(information->Username, ui->LineEdit_Username->text().toStdString().c_str(), 20);
    strncpy(information->BookName, ui->LineEdit_BookName->text().toStdString().c_str(), 100);
    strncpy(information->ISBN, ui->LineEdit_ISBN->text().toStdString().c_str(), 100);
    CLibraryClient::GetInstance().GetTcpSocket().write((char*)information, information->InformationLength);
    free(information);
    information = NULL;
}
