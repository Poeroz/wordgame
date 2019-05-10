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
#include <QDir>

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
    /**
     * @brief 构造函数。
     */
    worddbManager();

    /**
     * @brief 数据库初始化，在程序开头建立数据库连接。
     */
    static void initWorddb();

    /**
     * @brief 向数据库中添加新单词。
     * @param newWord 新单词。
     */
    void addWorddb(QString newWord);

    /**
     * @brief 在数据库中查询单词。
     * @param word 所查单词。
     * @return 若数据库中存在该单词，返回 true；否则返回 false。
     */
    bool queryWorddb(QString word);

    /**
     * @brief 输出单词数据库中的所有记录。
     */
    void printWorddb();

    /**
     * @brief 删除单词数据库中的所有记录。
     */
    void clearWorddb();

    /**
     * @brief 随机返回一个满足给定长度限制的单词。
     * @param minLen 最小长度。
     * @param maxLen 最大长度。
     * @return 单词。
     */
    QString getRandWord(int minLen, int maxLen);


private:
    QSqlDatabase worddb;            /**< 单词数据库对象。 */
};

#endif // WORDDBMANAGER_H
