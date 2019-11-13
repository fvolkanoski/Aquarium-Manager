#include "qmlcontroller.h"

QmlController::QmlController(QObject *parent) : QObject(parent)
{

}

void QmlController::registerUser(QString name, QString username, QString password)
{
    User registerUser(name, username, password);

    m_dbManager.insertUser(name, username, QString(QCryptographicHash::hash(password.toLocal8Bit(), QCryptographicHash::Sha256)));
}

bool QmlController::loginUser(QString username, QString password)
{
    std::pair <bool, User> currentUser = m_dbManager.getUserInfo(username);

    if(currentUser.first) // User has been found.
    {
        if(currentUser.second.password == QString(QCryptographicHash::hash(password.toLocal8Bit(), QCryptographicHash::Sha256))) // User and password is correct, we can log in.
        {
            // Log in user...
            qDebug() << "true";
            return true;

        }
        else
        {
            // Invalid password...

            return false;
        }
    }
    else
    {
        // User not found...

        return false;
    }
}
