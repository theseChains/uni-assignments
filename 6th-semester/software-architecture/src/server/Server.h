#ifndef POLYCLINIC_APP_SERVER_SERVER_H_
#define POLYCLINIC_APP_SERVER_SERVER_H_

#include <QTcpServer>

namespace polyclinic
{
class Server : public QTcpServer
{
    Q_OBJECT

public:
    explicit Server(QObject* parent = nullptr);

protected:
    void incomingConnection(qintptr socketDescriptor) override;
};
}

#endif
