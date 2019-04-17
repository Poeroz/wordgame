#ifndef PLAYER_H
#define PLAYER_H

#include "user.h"

class player : public user
{
public:
    player();

private:
    int levelCnt, experience;
};

#endif // PLAYER_H
