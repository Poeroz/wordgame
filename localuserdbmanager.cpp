#include "localuserdbmanager.h"

localUserdbManager::localUserdbManager() {
    localUserdb = QSqlDatabase::database("localUserConnect");
    if (!localUserdb.open()) {
        qDebug() << "not open!";
    }
}

void localUserdbManager::initLocalUserdb() {
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE", "localUserConnect");               /* 建立数据库连接 */
    QString dir = QDir::currentPath() + QDir::separator() + QString("localuser.db");
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

void localUserdbManager::insertLocalUserdb(QString usr, QString name, QString pwd, bool role, int grade, int level, int exp, int qcnt) {
    QSqlQuery query(localUserdb);
    QString str = "insert into user values(:usr, :name, :pwd, :role, :grade, :level, :exp, :qcnt)";
    query.prepare(str);
    query.bindValue(":usr", usr);
    query.bindValue(":name", name);
    query.bindValue(":pwd", pwd);
    query.bindValue(":role", role);
    query.bindValue(":grade", grade);
    query.bindValue(":level", level);
    query.bindValue(":exp", exp);
    query.bindValue(":qcnt", qcnt);
    if (!query.exec()) {
        qDebug() << "insert error";
    }
}

void localUserdbManager::clearLocalUserdb() {
    QSqlQuery query(localUserdb);
    if (!query.exec("delete from user")) {
        qDebug() << "clear error";
    }
}

const QSqlDatabase localUserdbManager::getLocalUserdb() {
    clearLocalUserdb();

    QJsonObject json;
    json["type"] = "getTable";
    QJsonObject rec = tcpMan.sendData(json);
    if (!rec.contains(STATUS) || rec[STATUS].toString() == FAILED) {
        qDebug() << "failed";
    }
    else {
        QJsonArray tmpArray = rec["table"].toArray();
        for (int index = 0; index < tmpArray.size(); index++) {
            QJsonObject tmpObject = tmpArray[index].toObject();
            insertLocalUserdb(tmpObject["usr"].toString(),
                    tmpObject["name"].toString(),
                    tmpObject["pwd"].toString(),
                    tmpObject["role"].toBool(),
                    tmpObject["grade"].toInt(),
                    tmpObject["level"].toInt(),
                    tmpObject["exp"].toInt(),
                    tmpObject["qcnt"].toInt());
        }
    }
    return localUserdb;
}
