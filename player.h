#ifndef PLAYER_H
#define PLAYER_H

#include "user.h"

class player : public user {
public:
    player();
    player(const user &base,
           const int &_levelCnt,
           const int &_experience);
    int getLevelCnt();
    int getExperience();

private:
    int levelCnt, experience;
};

#endif // PLAYER_H
