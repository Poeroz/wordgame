#include "connectmanager.h"

connectManager::connectManager() {
    server = new QTcpServer;

    /* 初始化 */
    socks.clear();
    buffer.clear();
    vs.clear();
    end.clear();
    wordlist.clear();
    socket2user.clear();

    connect(server, &QTcpServer::newConnection, this, &connectManager::newConnect);
}

connectManager::~connectManager() {
    for (auto it : socks) {
        if (it->state() == QTcpSocket::ConnectedState) {
            it->disconnectFromHost();
        }
    }
}

void connectManager::newConnect() {
    QTcpSocket *nowConnect = server->nextPendingConnection();

    qDebug() << "connection established:" << nowConnect;

    socks.push_back(nowConnect);

    connect(socks.back(), &QTcpSocket::readyRead, this, &connectManager::dataArrived);
    connect(socks.back(), &QTcpSocket::disconnected, this, &connectManager::disConnnect);
}

void connectManager::dataArrived() {
    QTcpSocket *nowSender = qobject_cast<QTcpSocket*>(sender());
    QByteArray array = nowSender->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject obj = doc.object();                 /* 收到的 Json 文件 */

    QJsonObject reply;                              /* 回复的 Json 文件 */
    QString type = obj["type"].toString();
    if (type == "queryUser") {                      /* 查询用户名是否已被注册 */
        QString usr = obj["usr"].toString();
        userdbManager man;
        if (man.queryUserdb(usr)) {
            reply["exist"] = true;
        }
        else {
            reply["exist"] = false;
        }
    }
    else if (type == "addUser") {                   /* 向数据库中添加用户 */
        userdbManager man;
        man.addUserdb(obj["usr"].toString(), obj["name"].toString(),
                        obj["pwd"].toString(), obj["role"].toBool());
    }
    else if (type == "checkUser") {                 /* 检查用户名和密码是否正确 */
        userdbManager man;
        reply["role"] = man.checkUser(obj["usr"].toString(), obj["pwd"].toString());
        for (int i = 0; i < socks.size(); i++) {
            if (socket2user[socks[i]] == obj["usr"].toString()) {
                reply["role"] = -1;
            }
        }
    }
    else if (type == "getPlayer") {                 /* 根据用户名返回闯关者信息 */
        userdbManager man;
        player newUser = man.getPlayer(obj["usr"].toString());
        socket2user[nowSender] = newUser.getUsername();
        emit updatePlayer(getUserList());
        newUser.writeJson(reply);
    }
    else if (type == "getQuestioner") {             /* 根据用户名返回出题者信息 */
        userdbManager man;
        questioner newUser = man.getQuestioner(obj["usr"].toString());
        newUser.writeJson(reply);
    }
    else if (type == "updatePlayer") {              /* 更新闯关者信息 */
        player newPlayer;
        newPlayer.readJson(obj);
        userdbManager man;
        man.updatePlayer(newPlayer);
    }
    else if (type == "updateQuestioner") {          /* 更新出题者信息 */
        questioner newQuestioner;
        newQuestioner.readJson(obj);
        userdbManager man;
        man.updateQuestioner(newQuestioner);
    }
    else if (type == "addWord") {                   /* 向数据库中添加单词 */
        worddbManager man;
        man.addWorddb(obj["word"].toString());
    }
    else if (type == "queryWord") {                 /* 查询数据库中是否已有该单词 */
        worddbManager man;
        if (man.queryWorddb(obj["word"].toString())) {
            reply["exist"] = true;
        }
        else {
            reply["exist"] = false;
        }
    }
    else if (type == "getWord") {                   /* 从数据库中随机取一个单词 */
        worddbManager man;
        QString word = man.getRandWord(obj["min"].toInt(), obj["max"].toInt());
        qDebug() << word;
        reply["word"] = word;
    }
    else if (type == "getTable") {                  /* 返回当前玩家数据库表 */
        userdbManager man;
        QJsonArray tmpArray;
        man.writeJson(tmpArray);
        reply["table"] = tmpArray;
    }
    else if (type == "matchPlayer") {               /* 匹配玩家 */
        QString currentUser = obj["usr"].toString();
        bool succ = false;
        if (vs.find(currentUser) != vs.end()) {
            succ = true;
        }
        else if (buffer.find(currentUser) == buffer.end()) {
            buffer.insert(currentUser);
            if (end.find(currentUser) != end.end()) {
                end.erase(end.find(currentUser));
            }
            if (buffer.size() >= 2) {
                succ = true;
                buffer.erase(buffer.find(currentUser));
                QString other = *buffer.begin();
                buffer.erase(buffer.begin());
                vs[currentUser] = other;
                vs[other] = currentUser;
                worddbManager man;
                QVector<QString> list = man.getnWord(10);
                wordlist[currentUser] = list;
                wordlist[other] = list;
            }
        }
        if (succ) {
            reply["matchStatus"] = true;
            QVector<QString> list = wordlist[currentUser];
            QJsonArray tmpArray;
            for (int i = 0; i < list.size(); i++) {
                QJsonObject tmpObject;
                tmpObject["text"] = list[i];
                tmpArray.append(tmpObject);
            }
            reply["wordlist"] = tmpArray;
        }
        else {
            reply["matchStatus"] = false;
        }
    }
    else if (type == "endMatch") {                  /* 在匹配模式中结束游戏 */
        QString currentUser = obj["usr"].toString();
        QString other = vs[currentUser];
        if (obj["pass"].toInt() == -1) {
            reply["win"] = false;
            reply["exp"] = 0;
        }
        else if (end.find(currentUser) != end.end()) {
            reply["win"] = false;
            reply["exp"] = 0;
        }
        else {
            end[other] = 1;
            reply["win"] = true;
            reply["exp"] = 20;
        }
        if (end.find(currentUser) != end.end()) {
            end.erase(end.find(currentUser));
        }
        vs.erase(vs.find(currentUser));
    }
    else if (type == "cancelMatch") {               /* 取消匹配 */
        QString currentUser = obj["usr"].toString();
        if (buffer.find(currentUser) != buffer.end()) {
            buffer.erase(buffer.find(currentUser));
        }
    }

    doc = QJsonDocument(reply);
    array = doc.toJson();
    nowSender->write(array);
    nowSender->flush();
}

void connectManager::disConnnect() {
   QTcpSocket *nowSender = qobject_cast<QTcpSocket*>(sender());
   qDebug() << "connection interruption:" << nowSender;

   socks.removeOne(nowSender);

   emit updatePlayer(getUserList());
}

bool connectManager::listen(const QHostAddress &address, quint16 port) {
    if (server) {
        return server->listen(address, port);
    }
    else {
        return false;
    }
}

QVector<QString> connectManager::getUserList() {
    QVector<QString> vec;
    for (int i = 0; i < socks.size(); i++) {
        vec.push_back(socket2user[socks[i]]);
    }
    return vec;
}



