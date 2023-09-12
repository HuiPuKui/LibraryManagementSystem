#ifndef _CRegister_H__
#define _CRegister_H__

#include <QWidget>

namespace Ui { class CRegister; }

class CRegister : public QWidget
{
    Q_OBJECT

public:
    static CRegister& GetInstance();
    void Clear();

private:
    explicit CRegister(QWidget *parent = nullptr);
    ~CRegister();

public slots:
    void CRegisterUser();
    void Back();

private:
    Ui::CRegister *ui;
};

#endif // _CRegister_H__
