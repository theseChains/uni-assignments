#include "Server.h"

#include "ClientHandler/ClientHandler.h"

namespace polyclinic
{
Server::Server(QObject* parent) : QTcpServer{ parent }
{
    if (!listen(QHostAddress::Any, 1234))
    {
        qWarning() << "Unable to start server:" << errorString();
    }
    else
    {
        qInfo() << "Server started. Listening on port:" << serverPort();
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    auto* clientHandler{ new ClientHandler{ socketDescriptor, this } };
    connect(clientHandler, &ClientHandler::finished, clientHandler, &ClientHandler::deleteLater);
    clientHandler->start();
}
}
