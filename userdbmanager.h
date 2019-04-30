#ifndef USERDBMANAGER_H
#define USERDBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "player.h"
#include "questioner.h"

#define NONEXIST -1
#define PLAYER 0                    /**< 闯关者。 */
#define QUESTIONER 1                /**< 出题者。 */

enum enumUserdb {
    USERNAME, NICKNAME, PASSWORD, ROLE, GRADE, LEVELCNT, EXPERIENCE, QUESTIONCNT
};

class userdbManager {
public:
    userdbManager();
    static void initUserdb();
    bool queryUserdb(QString usr);
    void printUserdb();
    void clearUserdb();
    void addUserdb(QString usr, QString name, QString pwd, bool role);
    int checkUser(QString usr, QString pwd);
    player getPlayer(QString usr, QString pwd);
    questioner getQuestioner(QString usr, QString pwd);
    const QSqlDatabase &getUserdb();

private:
    QSqlDatabase userdb;
};

#endif // USERDBMANAGER_H
