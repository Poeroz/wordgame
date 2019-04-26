#ifndef USER_H
#define USER_H

#include <QString>

class user {
public:
    user();
    user(const QString &_username,
         const QString &_nickname,
         const QString & _password,
         const int &_grade);
    QString getNickname();
    int getGrade();

private:
    QString username, nickname, password;
    int grade;
};

#endif // USER_H
