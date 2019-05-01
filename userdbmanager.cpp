#include "userdbmanager.h"

userdbManager::userdbManager() {
    userdb = QSqlDatabase::database("userConnect");
    if (!userdb.open()) {
        qDebug() << "not open!";
    }
}

void userdbManager::initUserdb() {
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE", "userConnect");               /* 建立数据库连接 */
    db.setDatabaseName("user.db");                                          /* 设置数据库名称 */
    if (!db.open()) {
        qDebug() << "not open!";
    }
    else {
        QSqlQuery query(db);
        /* 建立一个表，名称为 user */
        query.exec("create table user (username varchar(20) primary key, "  /* 用户名 */
                   "nickname varchar(20), "                                 /* 昵称 */
                   "password varchar(20), "                                 /* 密码 */
                   "role bool, "                                            /* 角色 */
                   "grade int, "                                            /* 等级 */
                   "levelCnt int,"                                          /* 已闯关卡数 */
                   "experience int,"                                        /* 经验值 */
                   "questionCnt int)");
    }
}

bool userdbManager::queryUserdb(QString usr) {
    QSqlQuery query(userdb);
    QString str = "select * from user where username = :usr";
    query.prepare(str);
    query.bindValue(":usr", usr);
    if (!query.exec()) {
        qDebug() << "query error";
    }
    else {
        if (query.next()) {
            return true;
        }
        else {
            return false;
        }
    }
    return false;
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
    QSqlQuery query(userdb);
    /* 向数据库中插入新用户的信息 */
    QString str = "insert into user values(:usr, :name, :pwd, :role, 0, 0, 0, 0)";
    query.prepare(str);
    query.bindValue(":usr", usr);
    query.bindValue(":name", name);
    query.bindValue(":pwd", pwd);
    query.bindValue(":role", role);
    if (!query.exec()) {
        qDebug() << "Error here:" << query.lastError();
    }
}

int userdbManager::checkUser(QString usr, QString pwd) {
    QSqlQuery query(userdb);
    QString str = QString("select * from user where username = :usr and password = :pwd");
    query.prepare(str);
    query.bindValue(":usr", usr);
    query.bindValue(":pwd", pwd);
    if (!query.exec()) {
        qDebug() << "query error";
    }
    else {
        if (query.next()) {
            if (query.value(ROLE) == PLAYER) {
                return PLAYER;
            }
            else {
                return QUESTIONER;
            }
        }
        else {
            return NONEXIST;
        }
    }
    return NONEXIST;
}

player userdbManager::getPlayer(QString usr) {
    QSqlQuery query(userdb);
    QString str = QString("select * from user where username = :usr");
    query.prepare(str);
    query.bindValue(":usr", usr);
    if (!query.exec()) {
        qDebug() << "query error";
    }
    else {
        if (query.next()) {
            user base = user(query.value(USERNAME).toString(),
                             query.value(NICKNAME).toString(),
                             query.value(PASSWORD).toString(),
                             query.value(GRADE).toInt());
            player newUser = player(base,
                                    query.value(LEVELCNT).toInt(),
                                    query.value(EXPERIENCE).toInt());
            return newUser;
        }
    }
}

questioner userdbManager::getQuestioner(QString usr) {
    QSqlQuery query(userdb);
    QString str = QString("select * from user where username = :usr");
    query.prepare(str);
    query.bindValue(":usr", usr);
    if (!query.exec()) {
        qDebug() << "query error";
    }
    else {
        if (query.next()) {
            user base = user(query.value(USERNAME).toString(),
                             query.value(NICKNAME).toString(),
                             query.value(PASSWORD).toString(),
                             query.value(GRADE).toInt());
            questioner newUser = questioner(base, query.value(QUESTIONCNT).toInt());
            return newUser;
        }
    }
}

const QSqlDatabase &userdbManager::getUserdb() {
    return userdb;
}
