#ifndef QUESTIONER_H
#define QUESTIONER_H

#include "user.h"

class questioner : public user {
public:
    questioner();
    questioner(const user &base,
               const int &_questionCnt);
    int getQuestionCnt();

private:
    int questionCnt;
};

#endif // QUESTIONER_H
