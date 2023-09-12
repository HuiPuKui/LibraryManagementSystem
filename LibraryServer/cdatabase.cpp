#include "cdatabase.h"

CDatabase::CDatabase(QObject *parent) : QObject(parent)
{
    m_dbDatabase = QSqlDatabase::addDatabase("QMYSQL");
}

CDatabase &CDatabase::GetInstance()
{
    static CDatabase dbInstance;
    return dbInstance;
}

/**
 * @brief CDatabase::Initilize
 * 初始化参数
 */

void CDatabase::Initilize()
{
    m_dbDatabase.setHostName("127.0.0.1");
    m_dbDatabase.setPort(3306);
    m_dbDatabase.setDatabaseName("LibraryManagementSystem");
    m_dbDatabase.setUserName("root");
    m_dbDatabase.setPassword("syuctacm");

    if (m_dbDatabase.open())
    {
        qDebug() << "success";
    }
    else
    {
        QMessageBox::critical(NULL, "连接数据库", "连接数据库失败");
    }
}

CDatabase::~CDatabase()
{
    m_dbDatabase.close();
}

/**
 * @brief CDatabase::RegisterUser
 * @param Username
 * @param Password
 * @return
 * 注册用户
 */

QString CDatabase::RegisterUser(const QString Username, const QString Password)
{
    QString Result;

    QString Sql = QString("select * from UserInfo where Username = \'%1\'").arg(Username);
    QSqlQuery query;
    query.exec(Sql);

    if (query.next())
    {
        Result = "User already exists";
    }
    else
    {
        QString Sql = QString("insert into UserInfo values(\'%1\', \'%2\', 0)").arg(Username).arg(Password);
        QSqlQuery query;
        if (query.exec(Sql))
        {
            Result = "Registration successful";
        }
        else
        {
            Result = "Registration failed";
        }
    }

    return Result;
}

/**
 * @brief CDatabase::DeleteUser
 * @param Username
 * @param Password
 * @return
 * 注销用户
 */

QString CDatabase::DeleteUser(const QString Username, const QString Password)
{
    QString Result;

    QString Sql = QString("select * from BorrowingRecord where BorrowerName = \'%1\'").arg(Username);
    QSqlQuery query;
    query.exec(Sql);

    if (query.next())
    {
        Result = "return books please";
    }
    else
    {
        QString Sql = QString("select * from UserInfo where Username = \'%1\'").arg(Username);
        QSqlQuery query;
        query.exec(Sql);

        if (query.next())
        {
            if (query.value(1) == Password)
            {
                QString Sql = QString("select * from UserInfo where Username = \'%1\' and Online = 1").arg(Username);
                QSqlQuery query;
                query.exec(Sql);
                if (query.next())
                {
                    Result = "Online";
                }
                else
                {
                    QString Sql = QString("delete from UserInfo where Username = \'%1\'").arg(Username);
                    QSqlQuery query;
                    if (query.exec(Sql))
                    {
                        Result = "Logout successful";
                    }
                    else
                    {
                        Result = "Logout failed";
                    }
                }
            }
            else
            {
                Result = "The password is incorrect";
            }
        }
        else
        {
            Result = "User not exist";
        }
    }

    return Result;
}

/**
 * @brief CDatabase::Login
 * @param Username
 * @param Password
 * @return
 * 登陆
 */

QString CDatabase::Login(const QString Username, const QString Password)
{
    QString Result;

    QString Sql = QString("select * from UserInfo where Username = \'%1\'").arg(Username);
    QSqlQuery query;
    query.exec(Sql);

    if (query.next())
    {
        if (query.value(1) == Password)
        {
            if (query.value(2) == 1)
            {
                Result = "Online";
            }
            else
            {
                Result = "Login successful";
                Sql = QString("update UserInfo set Online = 1 where Username = \'%1\'").arg(Username);
                query.exec(Sql);
            }
        }
        else
        {
            Result = "The password is incorrect";
        }
    }
    else
    {
        Result = "User not exist";
    }

    return Result;
}

void CDatabase::OffLine(const QString Username)
{
    QString Sql = QString("update UserInfo set Online = 0 where Username = \'%1\'").arg(Username);
    QSqlQuery query;
    query.exec(Sql);
}

/**
 * @brief CDatabase::SelectAllBook
 * @return
 * 查询出所有图书馆的书
 */

QStringList CDatabase::SelectAllBook()
{
    QStringList Result;
    Result.clear();

    QString Sql = QString("select * from Library");
    QSqlQuery query;
    query.exec(Sql);

    while (query.next())
    {
        Result.append(query.value(0).toString());
    }

    return Result;
}

/**
 * @brief CDatabase::SelectAllHave
 * @param Username
 * @return
 * 查询出所有自己的书（要还的）
 */

QStringList CDatabase::SelectAllHave(const QString Username)
{
    QStringList Result;
    Result.clear();

    QString Sql = QString("select * from BorrowingRecord where BorrowerName = \'%1\'").arg(Username);
    QSqlQuery query;
    query.exec(Sql);

    while (query.next())
    {
        Result.append(query.value(1).toString());
    }

    return Result;
}

/**
 * @brief CDatabase::SelectBookNameFormLibrary
 * @param BookName
 * @return
 * 从图书馆查询出书的信息
 */

QPair<QString, QString> CDatabase::SelectBookNameFormLibrary(const QString BookName)
{
    QPair<QString, QString> Result;

    QString Sql = QString("select * from Library where BookName = \'%1\'").arg(BookName);
    QSqlQuery query;
    query.exec(Sql);

    if (query.next())
    {
        Result.first = query.value(0).toString();
        Result.second = query.value(1).toString();
    }
    else
    {
        Result.first = "not exist";
        Result.second = "not exist";
    }

    return Result;
}

/**
 * @brief CDatabase::SelectBookNameFormBorrowingRecord
 * @param BookName
 * @return
 * 从没还的书中查询出书的信息
 */

QPair<QString, QString> CDatabase::SelectBookNameFormBorrowingRecord(const QString BookName)
{
    QPair<QString, QString> Result;

    QString Sql = QString("select * from BorrowingRecord where BookName = \'%1\'").arg(BookName);
    QSqlQuery query;
    query.exec(Sql);

    if (query.next())
    {
        Result.first = query.value(1).toString();
        Result.second = query.value(2).toString();
    }

    return Result;
}

/**
 * @brief CDatabase::TurnBookFromLibraryToUser
 * @param Username
 * @param BookName
 * @param ISBN
 * @return
 * 借书
 */

bool CDatabase::TurnBookFromLibraryToUser(const QString Username, const QString BookName, const QString ISBN)
{
    bool Result;
    QString Sql = QString("select * from Library where ISBN = \'%1\'").arg(ISBN);
    QSqlQuery query;
    query.exec(Sql);
    if (query.next())
    {
        QString Sql = QString("delete from Library where ISBN = \'%1\'").arg(ISBN);
        QSqlQuery query;
        query.exec(Sql);

        Sql = QString("insert into BorrowingRecord values(\'%1\', \'%2\', \'%3\')").arg(Username).arg(BookName).arg(ISBN);
        query.exec(Sql);
        Result = true;
    }
    else
    {
        Result = false;
    }
    return Result;
}

/**
 * @brief CDatabase::TurnBookFromUserToLibrary
 * @param Username
 * @param BookName
 * @param ISBN
 * 还书
 */

void CDatabase::TurnBookFromUserToLibrary(const QString Username, const QString BookName, const QString ISBN)
{
    QString Sql = QString("delete from BorrowingRecord where BorrowerName = \'%1\' and BookName = \'%2\' and ISBN = \'%3\'").arg(Username).arg(BookName).arg(ISBN);
    QSqlQuery query;
    query.exec(Sql);

    Sql = QString("insert into Library values(\'%1\', \'%2\')").arg(BookName).arg(ISBN);
    query.exec(Sql);
}


