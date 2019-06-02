/**
 * @file connectmanager.h
 *
 * @brief 服务器 TCP 通信管理。
 * @author 房庆凯 - 2017211131
 */

#ifndef CONNECTMANAGER_H
#define CONNECTMANAGER_H

#include <QtNetwork>
#include <QVector>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QMap>
#include <QSet>
#include "userdbmanager.h"
#include "worddbmanager.h"
#include "player.h"
#include "questioner.h"

/**
 * @brief 服务器 TCP 通信管理。
 */
class connectManager : public QObject {
    Q_OBJECT
public:
    /**
     * @brief 构造函数。
     */
    connectManager();

    /**
     * @brief 析构函数。
     */
    ~connectManager();

    /**
     * @brief 设置服务器监听的 IP 和端口。
     * @param address IP 地址。
     * @param port 端口号。
     * @return 是否设置成功。
     */
    bool listen(const QHostAddress &address = QHostAddress::Any, quint16 port = 0);

private slots:
    /**
     * @brief 当出现新的客户端连接时的操作。
     */
    void newConnect();

    /**
     * @brief 当缓冲区有数据到达时的操作。
     */
    void dataArrived();

    /**
     * @brief 当客户端失去连接时的操作。
     */
    void disConnnect();

signals:
    /**
     * @brief 在线玩家出现变化。
     */
    void updatePlayer(QVector<QString> userList);

private:
    QTcpServer *server;                             /**< 服务器。 */
    QVector<QTcpSocket*> socks;                     /**< 存储各个连接。 */
    QSet<QString> buffer;                           /**< 匹配缓冲区。 */
    QMap<QString, QString> vs;                      /**< 存储对手。 */
    QMap<QString, int> end;                         /**< 当一方结束时，存储其游戏所用时间。 */
    QMap<QString, QVector<QString> > wordlist;      /**< 存储玩家在匹配中对应的单词列表。 */
    QMap<QTcpSocket*, QString> socket2user;         /**< 连接到用户名之间的映射。 */

    /**
     * @brief 获取当前在线玩家的列表。
     * @return 玩家列表。
     */
    QVector<QString> getUserList();
};

#endif // CONNECTMANAGER_H
