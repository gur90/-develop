#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDate>
//#include <QSqlError>
#include<chrono>
#include <ctime>
#include<iostream>
#include "myclient.h"
class MyClient;

class MyServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit MyServer(QWidget *widget = 0, QObject *parent = 0);
    bool doStartServer(QHostAddress addr, qint16 port);
    void doSendToAllUserJoin(QString name);
    void doSendToAllUserLeft(QString name);
    void doSendToAllMessage(QString message, QString fromUsername);
    void doSendToAllServerMessage(QString message);
    void doSendServerMessageToUsers(QString message, const QStringList &users);
    void doSendMessageToUsers(QString message, const QStringList &users, QString fromUsername);
    //void databaseFunction(QString message);
    void databaseFunction2(QString message, QString from);
    QStringList getUsersOnline() const;
    bool isNameValid(QString name) const;
    bool isNameUsed(QString name) const;


signals:
    void addLogToGui(QString string, QColor color = Qt::black);

public slots:
    void onMessageFromGui(QString message, const QStringList &users);

    void onRemoveUser(MyClient *client);

protected:
    void incomingConnection(qintptr handle);

private:

    QList<MyClient *> _clients;
    QWidget *_widget;
    QSqlDatabase db;


};

#endif // MYSERVER_H
