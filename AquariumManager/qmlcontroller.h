#ifndef QMLCONTROLLER_H
#define QMLCONTROLLER_H

#include <QObject>
#include <QCryptographicHash>

#include "dbmanager.h"

class QmlController : public QObject
{
    Q_OBJECT

public:
    explicit QmlController(QObject *parent = nullptr);

    Q_INVOKABLE bool registerUser(QString name, QString username, QString password);
    Q_INVOKABLE bool loginUser(QString username, QString password);
    Q_INVOKABLE QString returnLoggedInName();

signals:

public slots:

private:
    DbManager m_dbManager;
    bool m_userLoggedIn;
    User m_currentLoggedInUser;
};

#endif // QMLCONTROLLER_H
