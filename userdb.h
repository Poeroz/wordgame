/**
 * @file userdb.h
 *
 * @brief 存储用户信息的数据库。
 * @author 房庆凯 - 2017211131
 */

#ifndef USERDB_H
#define USERDB_H

#define PLAYER 0                    /**< 闯关者。 */
#define QUESTIONER 1                /**< 出题者。 */

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

/**
 * @brief 用户数据库内各属性的枚举类型。
 */
enum enumUserDatabase {
    USERNAME, NICKNAME, PASSWORD, ROLE, GRADE, LEVELCNT, EXPERIENCE, QUESTIONCNT
};

/**
 * @brief 初始化用户数据库。
 */
void initUserdb();

/**
 * @brief 输出用户数据库内的所有记录。
 */
void printUserdb();

/**
 * @brief 清空用户数据库。
 */
void clearUserdb();

#endif // USERDB_H
