#ifndef DBMANAGER_H
#define DBMANAGER_H

// Qt includes
#include <QObject>
#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDesktopServices>
#include <QDir>

struct Fish
{
    uint id;
    QString name;
};

struct Aquarium
{
    uint id;
    QString name;
    std::vector <Fish> fishes;
};

struct User
{
    uint id;
    QString name;
    QString username;
    QString password;

    User()
    {

    }

    User(QString n, QString u, QString p)
    {
        name = n;
        username = u;
        password = p;
    }
};

class DbManager : public QObject
{
    Q_OBJECT
public:
    explicit DbManager(QObject *parent = nullptr);
    ~DbManager();

    // Returns user information from the database for the requester username.
    std::pair <bool, User> getUserInfo(const QString& user);

    // Used for registering a user into the database.
    bool insertUser(QString name, QString user, QString password);

    // Returns the user aquariums and their information from the database.
    std::vector <std::string> getUserAquariums(QString& user);

signals:

public slots:

private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
