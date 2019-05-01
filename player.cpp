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

int player::getLevelCnt() {
    return this->levelCnt;
}

int player::getExperience() {
    return this->experience;
}
