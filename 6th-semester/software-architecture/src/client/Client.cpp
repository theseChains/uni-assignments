#include "Client.h"

#include <QJsonObject>
#include <QJsonDocument>

#include "common/data/Reflect.h"

namespace polyclinic
{
Client::Client(QObject* parent)
    : QObject{ parent }, m_socket{ new QTcpSocket{ this } }
{
    connect(m_socket, &QTcpSocket::readyRead, this, &Client::onReadyRead);
    connect(m_socket, &QTcpSocket::disconnected, this, &Client::onDisconnected);
}

void Client::connectToServer()
{
    m_socket->connectToHost("localhost", 1234);
    if (!m_socket->waitForConnected(3000))
    {
        qWarning() << "Unable to connect to server.";
    }
    else
    {
        qInfo() << "Connected to server.";
    }
}

void Client::sendLoginRequest(const LoginInputData& inputData)
{
    QJsonObject request{ Reflect::toJson(inputData) };
    request["command"] = "login";

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::onReadyRead()
{
    QByteArray data{ m_socket->readAll() };
    QJsonDocument document{ QJsonDocument::fromJson(data) };
    QJsonObject response{ document.object() };

    QString command{ response["command"].toString() };
    if (command == "loginResult")
    {
        processLoginResult(response);
    }
}

void Client::processLoginResult(const QJsonObject& response)
{
    UserType userType{ static_cast<UserType>(response["userType"].toInt()) };
    emit loginResult(userType);
}

void Client::onDisconnected()
{
    qWarning() << "Disconnected from server.";
}
}
