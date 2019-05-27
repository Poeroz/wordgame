#include "worddbmanager.h"

void worddbManager::addWorddb(QString newWord) {
    QJsonObject json;
    json["type"] = "addWord";
    json["word"] = newWord;
    QJsonObject rec = tcpMan.sendData(json);
    if (rec[STATUS].toString() == FAILED) {
        qDebug() << "failed";
    }
}

bool worddbManager::queryWorddb(QString word) {
    QJsonObject json;
    json["type"] = "queryWord";
    json["word"] = word;
    QJsonObject rec = tcpMan.sendData(json);
    if (rec[STATUS].toString() == FAILED) {
        qDebug() << "failed";
    }
    else {
        if (rec["exist"].toBool()) {
            return true;
        }
        else {
            return false;
        }
    }
}

QString worddbManager::getRandWord(int minLen, int maxLen) {
    QJsonObject json;
    json["type"] = "getWord";
    json["min"] = minLen;
    json["max"] = maxLen;
    QJsonObject rec = tcpMan.sendData(json);
    if (rec[STATUS].toString() == FAILED) {
        qDebug() << "failed";
    }
    else {
        return rec["word"].toString();
    }
}
