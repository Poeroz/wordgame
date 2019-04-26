#include "questioner.h"

questioner::questioner(const user &base,
                       const int &_questionCnt):
    user(base), questionCnt(_questionCnt) {}

int questioner::getQuestionCnt() {
    return this->questionCnt;
}
