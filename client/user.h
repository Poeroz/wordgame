/**
 * @file user.h
 *
 * @brief 用户类。
 * @author 房庆凯 - 2017211131
 */

#ifndef USER_H
#define USER_H

#include <QString>
#include <QJsonObject>

enum USERTYPE {
    PLAYER, QUESTIONER
};

/**
 * @brief 用户类。
 */
class user {
public:
    user() = default;

    /**
     * @brief 构造函数。
     * @param _username 用户名。
     * @param _nickname 昵称。
     * @param _password 密码。
     * @param _grade    等级。
     */
    user(const QString &_username,
         const QString &_nickname,
         const QString & _password,
         const int &_grade);
    /**
     * @brief 获取用户昵称。
     * @return 用户昵称。
     */
    QString getNickname();

    /**
     * @brief 获取用户名。
     * @return 用户名。
     */
    QString getUsername() const;

    /**
     * @brief 获取用户等级。
     * @return 用户等级。
     */
    int getGrade() const;

    /**
     * @brief 设置用户等级。
     * @param tmp 用户等级。
     */
    void setGrade(int tmp);

    /**
     * @brief 从 json 中读出信息
     */
    void readJson(const QJsonObject &json);

    /**
     * @brief 向 json 中写入信息
     */
    void writeJson(QJsonObject &json) const;

private:
    QString username;       /**< 用户名。 */
    QString nickname;       /**< 昵称。 */
    QString password;       /**< 密码。 */
    int grade;              /**< 等级。 */
};

#endif // USER_H
