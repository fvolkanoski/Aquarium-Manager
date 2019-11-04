#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class DbManager
{
public:
    DbManager();
    ~DbManager();
    std::pair <bool, std::pair <QString, QString>> getUserInfo(const QString& user);
    bool insertUser(QString user, QString password);
    std::vector <std::string> getUserAquariums(QString& user);
private:
    QSqlDatabase m_db;
    const QString dbPath = "C:\\Users\\Filip\\Desktop\\Aquarium Manager\\AquariumManager\\am-db.db";
};

#endif // DBMANAGER_H
