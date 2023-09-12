#ifndef _CDATABASE_H__
#define _CDATABASE_H__

#include <QObject>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

class CDatabase : public QObject
{
    Q_OBJECT
public:
    static CDatabase& GetInstance();
    void Initilize();

    QString RegisterUser(const QString, const QString);
    QString DeleteUser(const QString, const QString);
    QString Login(const QString, const QString);
    void OffLine(const QString);

    QStringList SelectAllBook();
    QStringList SelectAllHave(const QString);

    QPair<QString, QString> SelectBookNameFormLibrary(const QString);
    QPair<QString, QString> SelectBookNameFormBorrowingRecord(const QString);

    bool TurnBookFromLibraryToUser(const QString, const QString, const QString);
    void TurnBookFromUserToLibrary(const QString, const QString, const QString);

private:
    explicit CDatabase(QObject *parent = nullptr);
    ~CDatabase();

private:
    QSqlDatabase m_dbDatabase;
};

#endif // _CDATABASE_H__
