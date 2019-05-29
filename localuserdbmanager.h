/**
 * @file localuserdbmanager.h
 *
 * @brief 本地数据库管理。
 * @author 房庆凯 - 2017211131
 */

#ifndef LOCALUSERDBMANAGER_H
#define LOCALUSERDBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDir>
#include "player.h"
#include "questioner.h"
#include "tcpmanager.h"
#include <QJsonArray>
#include <QJsonObject>

/**
 * @brief 本地数据库管理。
 */
class localUserdbManager {
public:
    /**
     * @brief 构造函数。
     */
    localUserdbManager();

    /**
     * @brief 数据库初始化。
     */
    static void initLocalUserdb();

    /**
     * @brief 向数据库中插入一条用户记录。
     * @param usr 用户名。
     * @param name 昵称。
     * @param pwd 密码。
     * @param role 角色。
     * @param grade 等级。
     * @param level 已闯关卡数。
     * @param exp 经验值。
     * @param qcnt 出题数。
     */
    void insertLocalUserdb(QString usr, QString name, QString pwd, bool role, int grade, int level, int exp, int qcnt);

    /**
     * @brief 清空数据库。
     */
    void clearLocalUserdb();

    /**
     * @brief 获取本地数据库的常量引用。
     * @return 本地数据库的常量引用。
     */
    const QSqlDatabase &getLocalUserdb();
private:
    QSqlDatabase localUserdb;           /**< 本地数据库。 */
};

#endif // LOCALUSERDBMANAGER_H
