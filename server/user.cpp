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

int user::getGrade() const {
    return this->grade;
}

void user::setGrade(int tmp) {
    this->grade = tmp;
}

QString user::getUsername() const {
    return this->username;
}

void user::readJson(const QJsonObject &json) {
    if (json.contains("usr")) {
        username = json["usr"].toString();
    }
    if (json.contains("pwd")) {
        password = json["pwd"].toString();
    }
    if (json.contains("name")) {
        nickname = json["name"].toString();
    }
    if (json.contains("grade")) {
        grade = json["grade"].toInt();
    }
}

void user::writeJson(QJsonObject &json) const {
    json["usr"] = username;
    json["pwd"] = password;
    json["name"] = nickname;
    json["grade"] = grade;
}
