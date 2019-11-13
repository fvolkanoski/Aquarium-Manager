#include "dbmanager.h"

DbManager::DbManager(QObject *parent) : QObject(parent)
{
    QString docPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);

    if(!QDir(docPath + "/AquariumManager").exists())
    {
        QDir().mkdir(docPath + "/AquariumManager");
        qDebug() << "Created documents folder for application.";
    }

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(docPath + "/AquariumManager/" + "aquarium_manager.db");

    m_db.open();


    if (!m_db.open())
    {
        qDebug() << "Error: Connection with database failed.";
    }
    else
    {
        qDebug() << "Database: Connection ok.";

        QSqlQuery createDbQuery;
        if(createDbQuery.exec("CREATE TABLE \"users\" ( "
                               "\"id\"	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE, "
                               "\"user\"	TEXT NOT NULL UNIQUE, "
                               "\"password\"	TEXT NOT NULL, "
                               "\"name\"	TEXT NOT NULL "
                               ");"))
        {
            qDebug() << "Users table created succesfully.";
        }
        else
        {
            qDebug() << "Error while creating users table, or already it exists.";
        }

        if(createDbQuery.exec("CREATE TABLE \"Aquariums\" ( "
                               "\"id\"	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE, "
                               "\"ownerid\"	INTEGER NOT NULL, "
                               "\"name\"	TEXT NOT NULL UNIQUE, "
                               "\"capacity\"	INTEGER NOT NULL "
                               ");"))
        {
            qDebug() << "Aquariums table created succesfully.";
        }
        else
        {
            qDebug() << "Error while creating aquariums table, or already it exists.";
        }
    }
}

DbManager::~DbManager()
{
    m_db.close();
    qDebug () << "Database closed succesfully.";
}

/*
 * Returns a bool and <User, Password> pair if the requested user has been found in the database.
 * If the requested user has been found in the database the bool will be true and the pair will be
 * populated with data, if the user has not been found the bool will be false and the pair will be empty.
*/
std::pair <bool, User> DbManager::getUserInfo(const QString &user)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE user = (:user)");
    query.bindValue(":user", user);
    std::pair <bool, User> returnUser;

    // Set the found bool value false at start, so ONLY if we find a user this value will change.
    returnUser.first = false;

    if(query.exec())
    {
        if(query.next())
        {
            returnUser.second.id = query.value(0).toUInt(); // Id
            returnUser.second.username = query.value(1).toString(); // Username
            returnUser.second.password = query.value(2).toString(); // Password
            returnUser.second.name = query.value(3).toString(); // Name
            returnUser.first = true;
        }
    }
    else
    {
        qDebug() << "Error while executing the query.";
    }

    return returnUser;
}

/*
 * Inserts a user into the database, if the insert has been successfull
 * returns true, if not returns false.
*/
bool DbManager::insertUser(QString name, QString user, QString password)
{
    QSqlQuery query;
    query.prepare("INSERT INTO users (user, password, name) VALUES (:user, :password, :name)");
    query.bindValue(":user", user);
    query.bindValue(":password", password);
    query.bindValue(":name", name);

    if(query.exec())
    {
        return true;
    }
    else
    {
        qDebug() << "Error while inserting a new user into the database: " << query.lastError();
        return false;
    }
}

/*
 * Returns the names of the aquariums that the user has stored.
*/
std::vector <std::string> DbManager::getUserAquariums(QString &user)
{
    std::vector <std::string> userAquariums;

    return userAquariums;
}
