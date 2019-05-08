/**
 * @file questioner.h
 *
 * @brief 出题者类。
 * @author 房庆凯 - 2017211131
 */

#ifndef QUESTIONER_H
#define QUESTIONER_H

#include "user.h"

/**
 * @brief 出题者类。
 */
class questioner : public user {
public:
    questioner() = default;

    /**
     * @brief 构造函数。
     * @param base 基类。
     * @param _questionCnt 出题数目。
     */
    questioner(const user &base,
               const int &_questionCnt);

    /**
     * @brief 获取出题数目。
     * @return 出题数目。
     */
    int getQuestionCnt() const;

    /**
     * @brief 设置出题数目。
     * @param tmp 出题数目。
     */
    void setQuestionCnt(int tmp);

private:
    int questionCnt;            /**< 出题数目。 */
};

#endif // QUESTIONER_H
