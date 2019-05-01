/**
 * @file user.cpp
 *
 * @brief 用户类。
 * @author 房庆凯 - 2017211131
 */

#include "user.h"

user::user(const QString &_username,
           const QString &_nickname,
           const QString &_password,
           const int &_grade):
    username(_username), nickname(_nickname), password(_password), grade(_grade) {}

QString user::getNickname() {
    return this->nickname;
}

int user::getGrade() {
    return this->grade;
}
