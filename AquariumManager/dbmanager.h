#ifndef DBMANAGER_H
#define DBMANAGER_H

// Qt includes
#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

struct User
{
    QString name;
    QString username;
    QString password;
};

class DbManager
{
public:
    DbManager();
    ~DbManager();

    // Returns user information from the database for the requester username.
    std::pair <bool, User> getUserInfo(const QString& user);

    // Used for registering a user into the database.
    bool insertUser(QString name, QString user, QString password);

    // Returns the user aquariums and their information from the database.
    std::vector <std::string> getUserAquariums(QString& user);
private:
    QSqlDatabase m_db;
    const QString dbPath = "C:\\Users\\Filip\\Desktop\\Aquarium Manager\\AquariumManager\\am-db.db";
};

#endif // DBMANAGER_H
