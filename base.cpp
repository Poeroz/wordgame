#include "base.h"

QSqlDatabase userinfo;

void initDatabase() {
    userinfo = QSqlDatabase::addDatabase("QSQLITE", "connection_userinfo"); /* add connection */
    userinfo.setDatabaseName("user.db"); /* set database name as userinfo.db */
    if (!userinfo.open()) { /* open database userinfo */
        qDebug() << "not open!";
    }
    else {
        QSqlQuery query(userinfo);
        /* create a table called user */
        query.exec("create table user (username varchar(20) primary key, "
                   "nickname varchar(20), "
                   "password varchar(20), "
                   "role bool, "
                   "grade int, "
                   "levelCnt int,"
                   "experience int,"
                   "questionCnt int)");
    }

}

void printDatabase() {
    QSqlQuery query(userinfo);
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

void clearDatabase() {
    QSqlQuery query(userinfo);
    if (!query.exec("delete from user")) {
        qDebug() << "clear error";
    }
}
