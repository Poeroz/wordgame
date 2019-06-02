#include "userdbmanager.h"

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
    newPlayer.writeJson(json);
    json["type"] = "updatePlayer";
    QJsonObject rec = tcpMan.sendData(json);
    if (!rec.contains(STATUS) || rec[STATUS].toString() == FAILED) {
        qDebug() << "failed";
    }
}

void userdbManager::updateQuestioner(const questioner &newQuestioner) {
    QJsonObject json;
    newQuestioner.writeJson(json);
    json["type"] = "updateQuestioner";
    QJsonObject rec = tcpMan.sendData(json);
    if (!rec.contains(STATUS) || rec[STATUS].toString() == FAILED) {
        qDebug() << "failed";
    }
}
