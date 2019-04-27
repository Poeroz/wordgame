#include "userdb.h"

void initUserdb() {
    QSqlDatabase userdb;
    userdb = QSqlDatabase::addDatabase("QSQLITE", "userConnect");           /* 建立连接 */
    userdb.setDatabaseName("user.db");                                      /* 数据库名称为 user.db */
    if (!userdb.open()) {
        qDebug() << "not open!";
    }
    else {
        QSqlQuery query(userdb);
        /* 建立一个表，名称为 user */
        query.exec("create table user (username varchar(20) primary key, "  /* 用户名 */
                   "nickname varchar(20), "                                 /* 昵称 */
                   "password varchar(20), "                                 /* 密码 */
                   "role bool, "                                            /* 角色 */
                   "grade int, "                                            /* 等级 */
                   "levelCnt int,"                                          /* 已闯关卡数 */
                   "experience int,"                                        /* 经验值 */
                   "questionCnt int)");                                     /* 出题数目 */
    }
}

void printUserdb() {
    QSqlDatabase userdb;
    userdb = QSqlDatabase::database("userConnect");                         /* 建立连接 */
    if (!userdb.open()) {
        qDebug() << "not open!";
    }
    else {
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

}

void clearUserdb() {
    QSqlDatabase userdb;
    userdb = QSqlDatabase::database("userConnect");                         /* 建立连接 */
    if (!userdb.open()) {
        qDebug() << "not open!";
    }
    else {
        QSqlQuery query(userdb);
        if (!query.exec("delete from user")) {
            qDebug() << "clear error";
        }
    }
}
