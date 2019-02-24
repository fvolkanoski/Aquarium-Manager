#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

class DbManager
{
public:
    DbManager();
    ~DbManager();
    std::pair <bool, std::pair <QString, QString>> getUserInfo(const QString& user);
private:
    QSqlDatabase m_db;
    const QString dbPath = "C:/Users/Filip/Desktop/QtProjects/AquariumManager/Aquarium-Manager/AquariumManager/am-db.db";
};

#endif // DBMANAGER_H