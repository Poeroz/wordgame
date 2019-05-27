/**
 * @file questioner.cpp
 *
 * @brief 出题者类。
 * @author 房庆凯 - 2017211131
 */

#include "questioner.h"

questioner::questioner(const user &base,
                       const int &_questionCnt):
    user(base), questionCnt(_questionCnt) {}

int questioner::getQuestionCnt() const {
    return this->questionCnt;
}

void questioner::setQuestionCnt(int tmp) {
    this->questionCnt = tmp;
}

void questioner::writeJson(QJsonObject &json) const {
    user::writeJson(json);
    json["type"] = QUESTIONER;
    json["cnt"] = questionCnt;
}

void questioner::readJson(const QJsonObject &json) {
    user::readJson(json);
    if (json.contains("cnt")) {
        questionCnt = json["cnt"].toInt();
    }
}
