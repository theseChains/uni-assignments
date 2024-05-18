#ifndef POLYCLINIC_APP_SERVER_CLIENTHANDLER_H_
#define POLYCLINIC_APP_SERVER_CLIENTHANDLER_H_

#include <QThread>
#include <QTcpSocket>

// todo: change later please!
#include "../DatabaseHandler/DatabaseHandler.h"

namespace polyclinic
{
class ClientHandler : public QThread
{
    Q_OBJECT

public:
    explicit ClientHandler(qintptr socketDescriptor, QObject* parent = nullptr);
    ~ClientHandler();

signals:
    void finished();

protected:
    void run() override;

private slots:
    void onReadyRead();
    void onDisconnected();

private:
    void processLoginRequest(const QJsonObject& request);

private:
    qintptr m_socketDescriptor{};
    QTcpSocket* m_socket{};
    DatabaseHandler m_databaseHandler{};
};
}

#endif
