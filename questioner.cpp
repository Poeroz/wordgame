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
