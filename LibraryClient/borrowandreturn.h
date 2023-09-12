#ifndef _CBORROWANDRETURN_H__
#define _CBORROWANDRETURN_H__

#include <QWidget>
#include "Information.h"

namespace Ui { class CBorrowAndReturn; }

class CBorrowAndReturn : public QWidget
{
    Q_OBJECT

public:
    static CBorrowAndReturn& GetInstance(QString);
    void ShowBorrowPage(const Information* const);
    void ShowReturnPage(const Information* const);
    void ShowLineEdit(const QPair<QString, QString>&);

private:
    explicit CBorrowAndReturn(QWidget *parent, QString);
    ~CBorrowAndReturn();

public slots:
    void TurnToPageBorrow();
    void TurnToPageReturn();
    void FreshPage();
    void ChangeLineEdit(int);
    void ClickedButtonOk();

private:
    QString m_qstrUserame;      // 用户名
    Ui::CBorrowAndReturn *ui;
    bool m_bPage;               // 借书 or 还书
};

#endif // _CBORROWANDRETURN_H__
