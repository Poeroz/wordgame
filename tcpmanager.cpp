#include "tcpmanager.h"

tcpManager::tcpManager(QString _IP, quint16 _PORT)
    : IP(_IP), PORT(_PORT) {
    socket = new QTcpSocket();

    connectToServer();
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
}

QJsonObject tcpManager::sendData(const QJsonObject &data) {
    if (socket->state() == QTcpSocket::UnconnectedState) {
        connectToServer();
    }
    QJsonObject recData;
    if (socket->state() == QTcpSocket::ConnectedState) {
        QJsonDocument doc = QJsonDocument(data);
        QByteArray array = doc.toJson();
        qint64 wsta = socket->write(array);
        bool fsta = socket->flush();
        if (wsta && fsta) {
            if (socket->waitForReadyRead(10000)) {
                array = socket->readAll();
                doc = QJsonDocument::fromJson(array);
                recData = doc.object();
                recData[STATUS] = SUCCESS;
            }
            else {
                recData[STATUS] = FAILED;
            }
        }
        else {
            recData[STATUS] = FAILED;
        }
    }
    else {
        recData[STATUS] = FAILED;
    }
    return recData;
}

void tcpManager::connectToServer() {
    socket->abort();
    socket->connectToHost(IP, PORT);

    if (!socket->waitForConnected(3000)) {
        qDebug() << "connection failed!";
    }
}

void tcpManager::displayError(QAbstractSocket::SocketError msg) {
    qDebug() << msg;
}

tcpManager tcpMan;
