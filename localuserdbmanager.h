#ifndef LOCALUSERDBMANAGER_H
#define LOCALUSERDBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDir>
#include "player.h"
#include "questioner.h"
#include "tcpmanager.h"
#include <QJsonArray>
#include <QJsonObject>


class localUserdbManager {
public:
    localUserdbManager();
    static void initLocalUserdb();
    void insertLocalUserdb(QString usr, QString name, QString pwd, bool role, int grade, int level, int exp, int qcnt);
    void clearLocalUserdb();
    const QSqlDatabase getLocalUserdb();
    const QSqlDatabase getOnlineUserdb();
    bool queryLocalUserdb(QString usr);
private:
    QSqlDatabase localUserdb;
};

#endif // LOCALUSERDBMANAGER_H
