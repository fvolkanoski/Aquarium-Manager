#include "dbmanager.h"

/*
 * Constructor: Tries to open a connection to the Sqlite database. If it is successfull
 * just prints at QDebug that the database connection is ok, if there is an error prints
 * at QDebug an error.
 * TODO: Complete the constructor, what to do if connection is not ok, what to do if it is okay.
*/
DbManager::DbManager()
{
   m_db = QSqlDatabase::addDatabase("QSQLITE");
   m_db.setDatabaseName(dbPath);

   if (!m_db.open())
   {
      qDebug() << "Error: connection with database fail";
   }
   else
   {
      qDebug() << "Database: connection ok";
   }
}

/*
 * Returns a bool and <User, Password> pair if the requested user has been found in the database.
 * If the requested user has been found in the database the bool will be true and the pair will be
 * populated with data, if the user has not been found the bool will be false and the pair will be empty.
*/
std::pair <bool, std::pair <QString, QString>> DbManager::getUserInfo(const QString &user)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE user = (:user)");
    query.bindValue(":user", user);
    std::pair <bool, std::pair <QString, QString>> returnUser;

    // Set the found bool value false at start, so ONLY if we find a user this value will change.
    returnUser.first = false;

    if(query.exec())
    {
        // We do not use while, the user is a unique field in the database,
        // so the query should not return more than one result.
        if(query.next())
        {
            returnUser.second.first = query.value(1).toString(); // User
            returnUser.second.second = query.value(2).toString(); // Password
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
bool DbManager::insertUser(QString user, QString password)
{
    QSqlQuery query;
    query.prepare("INSERT INTO users (user, password) VALUES (:user, :password)");
    query.bindValue(":user", user);
    query.bindValue(":password", password);

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

/*
 * Destructor: Closes the database.
*/
DbManager::~DbManager()
{
    m_db.close();
    qDebug () << "Database closed succesfully.";
}
