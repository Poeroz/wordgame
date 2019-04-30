#ifndef WORDDBMANAGER_H
#define WORDDBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

/**
 * @brief 单词数据库内各属性的枚举类型。
 */
enum enumWordDatabase {
    TEXT, LENGTH
};

class worddbManager {
public:
    worddbManager();
    static void initWorddb();
    void addWorddb(QString newWord);
    bool queryWorddb(QString word);
    void printWorddb();
    void clearWorddb();
    QString getRandWord(int minLen, int maxLen);


private:
    QSqlDatabase worddb;
};

#endif // WORDDBMANAGER_H
