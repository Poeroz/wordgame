/**
 * @file userdbmanager.h
 *
 * @brief 管理用户数据库的类。
 * @author 房庆凯 - 2017211131
 */

#ifndef USERDBMANAGER_H
#define USERDBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDir>
#include "player.h"
#include "questioner.h"

#define NONEXIST -1                 /**< 数据库中不存在。 */
#define PLAYER 0                    /**< 闯关者。 */
#define QUESTIONER 1                /**< 出题者。 */

/**
 * @brief 用户数据库内各属性的枚举类型。
 */
enum enumUserdb {
    USERNAME, NICKNAME, PASSWORD, ROLE, GRADE, LEVELCNT, EXPERIENCE, QUESTIONCNT
};

/**
 * @brief 管理用户数据库的类。
 */
class userdbManager {
public:
    /**
     * @brief 构造函数。
     */
    userdbManager();

    /**
     * @brief 数据库初始化，在程序开头建立数据库连接。
     */
    static void initUserdb();

    void work(int a, int b);

    /**
     * @brief 按照用户名查询数据库中的某个用户。
     * @param usr 用户名。
     * @return 若存在该用户，返回 true；否则返回 false。
     */
    bool queryUserdb(QString usr);

    /**
     * @brief 输出用户数据库中的所有记录。
     */
    void printUserdb();

    /**
     * @brief 删除用户数据库中的所有记录。
     */
    void clearUserdb();

    /**
     * @brief 向数据库中添加一个新用户。
     * @param usr 用户名。
     * @param name 昵称。
     * @param pwd 密码。
     * @param role 角色。
     */
    void addUserdb(QString usr, QString name, QString pwd, bool role);

    /**
     * @brief 检查用户名与密码是否正确。
     * @param usr 用户名。
     * @param pwd 密码。
     * @return 若正确，返回 true；否则返回 false。
     */
    int checkUser(QString usr, QString pwd);

    /**
     * @brief 返回当前用户名对应的闯关者。
     * @param usr 用户名。
     * @return 闯关者。
     */
    player getPlayer(QString usr);

    /**
     * @brief 返回当前用户名对应的出题者。
     * @param usr 用户名。
     * @return 出题者。
     */
    questioner getQuestioner(QString usr);

    /**
     * @brief 更新闯关者信息。
     * @param 闯关者。
     */
    void updatePlayer(const player &newPlayer);

    /**
     * @brief 更新出题者信息。
     * @param 出题者。
     */
    void updateQuestioner(const questioner &newQuestioner);

    /**
     * @brief 获取数据库对象的常量引用。
     */
    const QSqlDatabase &getUserdb();

private:
    QSqlDatabase userdb;                /**< 用户数据库对象。 */
};

#endif // USERDBMANAGER_H
