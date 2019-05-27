#ifndef TCPMANAGER_H
#define TCPMANAGER_H

#include <QTcpSocket>
#include <QObject>
#include <QDataStream>
#include <QAbstractSocket>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#define DEFAULT_IP "127.0.0.1"
#define DEFAULT_PORT 6666
#define STATUS "status"
#define ACKFIELD "ackfield"

enum enumStatus {
    FAILED, SUCCESS
};

class tcpManager : public QObject {
    Q_OBJECT
public:
    explicit tcpManager(QString _IP = DEFAULT_IP, quint16 _PORT = DEFAULT_PORT);

    QJsonObject sendData(const QJsonObject &data);

    void connectToServer();

private:
    QTcpSocket *socket;
    QString IP;
    quint16 PORT;

public slots:
    void displayError(QAbstractSocket::SocketError msg);
};

extern tcpManager tcpMan;

#endif // TCPMANAGER_H
