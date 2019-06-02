#include "worddbmanager.h"

worddbManager::worddbManager() {
    worddb = QSqlDatabase::database("wordConnect");
    if (!worddb.open()) {
        qDebug() << "not open!";
    }
}

void worddbManager::initWorddb() {
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE", "wordConnect");
    QString dir = QDir::currentPath() + QDir::separator() + QString("word.db");
    db.setDatabaseName(dir);
    if (!db.open()) {
        qDebug() << "not open!";
    }
    else {
        QSqlQuery query(db);
        query.exec("create table word (text varchar(20) primary key, "
                   "length int)");
    }
}

void worddbManager::addWorddb(QString newWord) {
    QSqlQuery query(worddb);
    QString str = "insert into word values(:text, :length)";
    query.prepare(str);
    query.bindValue(":text", newWord);
    query.bindValue(":length", newWord.length());
    if (!query.exec()) {
        qDebug() << "Error here:" << query.lastError();
    }
}

bool worddbManager::queryWorddb(QString word) {
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

void worddbManager::printWorddb() {
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

void worddbManager::clearWorddb() {
    QSqlQuery query(worddb);
    if (!query.exec("delete from word")) {
        qDebug() << "clear error";
    }
}

QString worddbManager::getRandWord(int minLen, int maxLen) {

    QSqlQuery query(worddb);
    QString str = "select * from word where length >= :min and length <= :max order by random() limit 1";
    query.prepare(str);
    query.bindValue(":min", minLen);
    query.bindValue(":max", maxLen);
    if (!query.exec()) {
        qDebug() << "query error";
    }
    else {
        if (query.next()) {
            return query.value(TEXT).toString();
        }
        else {
            qDebug() << "no word in database.";
        }
    }
}

QVector<QString> worddbManager::getnWord(int num) {
    QVector<QString> vec;
    for (int i = 0; i < num; i++) {
        vec.push_back(getRandWord(1, 18));
    }
    return vec;
}
