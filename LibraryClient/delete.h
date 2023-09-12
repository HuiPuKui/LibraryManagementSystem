#ifndef _DELETE_H__
#define _DELETE_H__

#include <QWidget>

namespace Ui { class CDelete; }

class CDelete : public QWidget
{
    Q_OBJECT

public:
    static CDelete& GetInstance();
    void Clear();

private:
    explicit CDelete(QWidget *parent = nullptr);
    ~CDelete();

public slots:
    void DeleteUser();
    void Back();

private:
    Ui::CDelete *ui;
};

#endif // _DELETE_H__
