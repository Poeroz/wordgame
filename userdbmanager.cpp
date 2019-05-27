#include "userdbmanager.h"

userdbManager::userdbManager() {
//    userdb = QSqlDatabase::database("userConnect");
//    if (!userdb.open()) {
//        qDebug() << "not open!";
//    }
}

void userdbManager::initUserdb() {
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE", "userConnect");               /* 建立数据库连接 */
    QString dir = QDir::currentPath() + QDir::separator() + QString("user.db");
    db.setDatabaseName(dir);                                                /* 设置数据库名称 */
    if (!db.open()) {
        qDebug() << db.lastError();
    }
    else {
        QSqlQuery query(db);
        /* 建立一个表，名称为 user */
        query.exec("create table user (username varchar(20) primary key, "  /* 用户名 */
                   "nickname varchar(20), "                                 /* 昵称 */
                   "password varchar(20), "                                 /* 密码 */
                   "role bool, "                                            /* 角色 */
                   "grade int, "                                            /* 等级 */
                   "levelCnt int, "                                         /* 已闯关卡数 */
                   "experience int, "                                       /* 经验值 */
                   "questionCnt int)");                                     /* 出题数 */
    }
}

bool userdbManager::queryUserdb(QString usr) {
    QJsonObject json;
    json["type"] = "queryUser";
    json["usr"] = usr;
    QJsonObject rec = tcpMan.sendData(json);
    if (rec[STATUS].toString() == FAILED) {
        qDebug() << "failed";
    }
    else {
        if (rec["exist"].toBool() == true) {
            return true;
        }
        else {
            return false;
        }
    }
}

void userdbManager::printUserdb() {
    QSqlQuery query(userdb);
    if (!query.exec("select * from user")) {
        qDebug() << "print error";
    }
    else {
        while (query.next()) {
            for (int i = 0; i < 8; i++) {
                qDebug() << query.value(i).toString();
            }
        }
    }
}

void userdbManager::clearUserdb() {
    QSqlQuery query(userdb);
    if (!query.exec("delete from user")) {
        qDebug() << "clear error";
    }
}

void userdbManager::addUserdb(QString usr, QString name, QString pwd, bool role) {
    QJsonObject json;
    json["type"] = "addUser";
    json["usr"] = usr;
    json["name"] = name;
    json["pwd"] = pwd;
    json["role"] = role;
    QJsonObject rec = tcpMan.sendData(json);
    if (!rec.contains(STATUS) || rec[STATUS].toString() == FAILED) {
        qDebug() << "failed";
    }
}

int userdbManager::checkUser(QString usr, QString pwd) {
    QJsonObject json;
    json["type"] = "checkUser";
    json["usr"] = usr;
    json["pwd"] = pwd;
    QJsonObject rec = tcpMan.sendData(json);
    if (!rec.contains(STATUS) || rec[STATUS].toString() == FAILED) {
        qDebug() << "failed";
    }
    else {
        return rec["role"].toInt();
    }
}

player userdbManager::getPlayer(QString usr) {
    QJsonObject json;
    json["type"] = "getPlayer";
    json["usr"] = usr;
    QJsonObject rec = tcpMan.sendData(json);
    if (!rec.contains(STATUS) || rec[STATUS].toString() == FAILED) {
        qDebug() << "failed";
    }
    else {
        player tmp;
        tmp.readJson(rec);
        return tmp;
    }
}

questioner userdbManager::getQuestioner(QString usr) {
    QJsonObject json;
    json["type"] = "getQuestioner";
    json["usr"] = usr;
    QJsonObject rec = tcpMan.sendData(json);
    if (!rec.contains(STATUS) || rec[STATUS].toString() == FAILED) {
        qDebug() << "failed";
    }
    else {
        questioner tmp;
        tmp.readJson(rec);
        return tmp;
    }
}

void userdbManager::updatePlayer(const player &newPlayer) {
    QJsonObject json;
    json["type"] = "updatePlayer";
    newPlayer.writeJson(json);
    QJsonObject rec = tcpMan.sendData(json);
    if (!rec.contains(STATUS) || rec[STATUS].toString() == FAILED) {
        qDebug() << "failed";
    }
}

void userdbManager::updateQuestioner(const questioner &newQuestioner) {
    QJsonObject json;
    json["type"] = "updateQuestioner";
    newQuestioner.writeJson(json);
    QJsonObject rec = tcpMan.sendData(json);
    if (!rec.contains(STATUS) || rec[STATUS].toString() == FAILED) {
        qDebug() << "failed";
    }
}

const QSqlDatabase &userdbManager::getUserdb() {
    return userdb;
}
