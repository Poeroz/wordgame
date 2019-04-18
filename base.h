#ifndef BASE_H
#define BASE_H

#define PLAYER 0
#define QUESTIONER 1

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

extern QSqlDatabase userinfo; /* database of userinfo */

void initDatabase(); /* initinalize the database user */

void printDatabase(); /* print all records in the database user */

void clearDatabase(); /* remove all records in the database user */

#endif // BASE_H
