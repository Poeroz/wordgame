/**
 * @file worddbmanger.h
 *
 * @brief 管理单词数据库的类。
 * @author 房庆凯 - 2017211131
 */

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

/**
 * @brief 管理单词数据库的类。
 */
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
