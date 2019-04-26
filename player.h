/**
 * @file player.h
 *
 * @brief 闯关者类。
 * @author 房庆凯 - 2017211131
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "user.h"

/**
 * @brief 闯关者类。
 */
class player : public user {
public:
    player() = default;

    /**
     * @brief 构造函数。
     * @param base 基类。
     * @param _levelCnt 已闯关卡数。
     * @param _experience 经验值。
     */
    player(const user &base,
           const int &_levelCnt,
           const int &_experience);

    /**
     * @brief 获取已闯关卡数。
     * @return 已闯关卡数。
     */
    int getLevelCnt();

    /**
     * @brief 获取经验值。
     * @return 经验值。
     */
    int getExperience();

private:
    int levelCnt;               /**< 已闯关卡数。 */
    int experience;             /**< 经验值。 */
};

#endif // PLAYER_H
