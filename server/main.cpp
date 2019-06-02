#include "connectmanager.h"
#include <QApplication>
#include "userdbmanager.h"
#include "worddbmanager.h"
#include "onlinewidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* 初始化数据库 */
    userdbManager::initUserdb();
    worddbManager::initWorddb();

    onlineWidget w;
    w.show();

    /* 服务器初始化 */
    connectManager man;
    man.listen(QHostAddress::Any, 6666);

    QObject::connect(&man, SIGNAL(updatePlayer(QVector<QString>)), &w, SLOT(refreshTable(QVector<QString>)));

    return a.exec();
}
