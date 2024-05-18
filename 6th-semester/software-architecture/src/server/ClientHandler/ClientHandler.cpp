#include "ClientHandler.h"

#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>

#include "../../common/data/Reflect.h"

namespace polyclinic
{
ClientHandler::ClientHandler(qintptr socketDescriptor, QObject* parent)
    : QThread{ parent }, m_socketDescriptor{ socketDescriptor }
{
}

ClientHandler::~ClientHandler()
{
    if (isRunning())
    {
        quit();
        wait();
    }

    if (m_socket)
    {
        m_socket->deleteLater();
    }
}

void ClientHandler::run()
{
    if (!m_databaseHandler.connectToTheDatabase())
    {
        emit finished();
        return;
    }

    m_socket = new QTcpSocket{};
    if (!m_socket->setSocketDescriptor(m_socketDescriptor))
    {
        emit finished();
        return;
    }

    connect(m_socket, &QTcpSocket::readyRead, this, &ClientHandler::onReadyRead, Qt::DirectConnection);
    connect(m_socket, &QTcpSocket::disconnected, this, &ClientHandler::onDisconnected, Qt::DirectConnection);

    exec();
}

void ClientHandler::onReadyRead()
{
    if (!m_socket) return;

    QByteArray data{ m_socket->readAll() };
    QJsonDocument document{ QJsonDocument::fromJson(data) };
    QJsonObject request{ document.object() };

    QString command{ request["command"].toString() };
    if (command == "login")
    {
        processLoginRequest(request);
    }
}

void ClientHandler::processLoginRequest(const QJsonObject& request)
{
    LoginInputData inputData{ Reflect::fromJson<LoginInputData>(request) };
    UserType userType{ m_databaseHandler.authenticateUser(inputData) };

    QJsonObject response{};
    response["command"] = "loginResult";
    response["userType"] = static_cast<int>(userType);

    QJsonDocument document{ response };
    m_socket->write(document.toJson());
}

void ClientHandler::onDisconnected() {
    if (m_socket)
    {
        m_socket->deleteLater();
        m_socket = nullptr;
    }

    quit();

    emit finished();
}
}