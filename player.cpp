/**
 * @file player.cpp
 *
 * @brief 闯关者类。
 * @author 房庆凯 - 2017211131
 */

#include "player.h"

player::player(const user &base,
               const int &_levelCnt,
               const int &_experience):
    user(base), levelCnt(_levelCnt), experience(_experience) {}

int player::getLevelCnt() const {
    return this->levelCnt;
}

int player::getExperience() const {
    return this->experience;
}

void player::setLevelCnt(int tmp) {
    this->levelCnt = tmp;
}

void player::setExperience(int tmp) {
    this->experience = tmp;
}

