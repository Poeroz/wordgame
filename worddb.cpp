#include "worddb.h"

void initWorddb() {
    QSqlDatabase worddb;
    worddb = QSqlDatabase::addDatabase("QSQLITE", "wordConnect");
    worddb.setDatabaseName("word.db");
    if (!worddb.open()) {
        qDebug() << "not open!";
    }
    else {
        QSqlQuery query(worddb);
        query.exec("create table word (text varchar(20) primary key, "
                   "length int)");
    }
}

void printWorddb() {
    QSqlDatabase worddb;
    worddb = QSqlDatabase::database("wordConnect");
    if (!worddb.open()) {
        qDebug() << "not open!";
    }
    else {
        QSqlQuery query(worddb);
        if (!query.exec("select * from word")) {
            qDebug() << "print error";
        }
        else {
            while (query.next()) {
                for (int i = 0; i < 2; i++) {
                    qDebug() << query.value(i).toString();
                }
            }
        }
    }
}

void clearWorddb() {
    QSqlDatabase worddb;
    worddb = QSqlDatabase::database("wordConnect");
    if (!worddb.open()) {
        qDebug() << "not open!";
    }
    else {
        QSqlQuery query(worddb);
        if (!query.exec("delete from word")) {
            qDebug() << "clear error";
        }
    }
}

void addWorddb(QString newWord) {
    QSqlDatabase worddb;
    worddb = QSqlDatabase::database("wordConnect");
    if (!worddb.open()) {
        qDebug() << "not open!";
    }
    else {
        QSqlQuery query(worddb);
        QString str = "insert into word values(:text, :length)";
        query.prepare(str);
        query.bindValue(":text", newWord);
        query.bindValue(":length", newWord.length());
        if (!query.exec()) {
            qDebug() << "Error here:" << query.lastError();
        }
    }
}

bool queryWorddb(QString word) {
    QSqlDatabase worddb;
    worddb = QSqlDatabase::database("wordConnect");
    if (!worddb.open()) {
        qDebug() << "not open!";
    }
    else {
        QSqlQuery query(worddb);
        QString str = "select * from word where text = :text";
        query.prepare(str);
        query.bindValue(":text", word);
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
    }
    return false;
}
