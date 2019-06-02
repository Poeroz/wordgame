/**
 * @file tcpmanager.h
 *
 * @brief 客户端 TCP 通信管理。
 * @author 房庆凯 - 2017211131
 */

#ifndef TCPMANAGER_H
#define TCPMANAGER_H

#include <QTcpSocket>
#include <QObject>
#include <QDataStream>
#include <QAbstractSocket>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#define DEFAULT_IP "127.0.0.1"          /**< 默认 IP 地址。 */
#define DEFAULT_PORT 6666               /**< 默认端口。 */
#define STATUS "status"                 /**< 包的状态字段。 */

/**
 * @brief 状态字段的枚举类型。
 */
enum enumStatus {
    FAILED, SUCCESS
};

/**
 * @brief 客户端 TCP 通信管理。
 */
class tcpManager : public QObject {
    Q_OBJECT
public:
    /**
     * @brief 构造函数。
     * @param _IP IP 地址。
     * @param _PORT 端口。
     */
    explicit tcpManager(QString _IP = DEFAULT_IP, quint16 _PORT = DEFAULT_PORT);

    /**
     * @brief 发送一个 Json 数据包。
     * @param data 数据包。
     * @return 服务器发回的 Json 数据包。
     */
    QJsonObject sendData(const QJsonObject &data);

    /**
     * @brief 连接到服务器。
     */
    void connectToServer();

private:
    QTcpSocket *socket;                 /**< TCP 连接。 */
    QString IP;                         /**< IP 地址。 */
    quint16 PORT;                       /**< 端口。 */

public slots:
    /**
     * @brief 输出错误信息。
     * @param msg 错误信息。
     */
    void displayError(QAbstractSocket::SocketError msg);
};

extern tcpManager tcpMan;               /**< TCP 管理的全局变量。 */

#endif // TCPMANAGER_H
