/**
 * @file worddb.h
 *
 * @brief 存储单词信息的数据库。
 * @author 房庆凯 - 2017211131
 */

#ifndef WORDDB_H
#define WORDDB_H


#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

/**
 * @brief 单词数据库内各属性的枚举类型。
 */
enum enumWordDatabase {
    TEXT, LENGTH
};

/**
 * @brief 初始化单词数据库。
 */
void initWorddb();

/**
 * @brief 向数据库中添加新单词。
 * @param 新单词。
 */
void addWorddb(QString newWord);

/**
 * @brief 从数据库中查找单词。
 * @param 单词。
 * @return 若存在该单词，则返回 true；否则返回 false。
 */
bool queryWorddb(QString word);

/**
 * @brief 输出单词数据库内的所有记录。
 */
void printWorddb();

/**
 * @brief 清空单词数据库。
 */
void clearWorddb();

#endif // WORDDB_H
