#ifndef QUESTIONER_H
#define QUESTIONER_H

#include "user.h"

class questioner : public user
{
public:
    questioner();

private:
    int questionCnt;
};

#endif // QUESTIONER_H
