/**
 * @file main.cpp
 *
 * @brief 提供程序入口点。
 * @author 房庆凯 - 2017211131
 */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
