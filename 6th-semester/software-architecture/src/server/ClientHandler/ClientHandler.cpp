#include "ClientHandler.h"

#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <iostream>

#include "common/data/Reflect.h"
#include "common/data/PatientSearchData.h"

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
    else if (command == "registerPatient")
    {
        processPatientRegistrationRequest(request);
    }
    else if (command == "getAllPatientBriefData")
    {
        processGetAllPatientBriefDataRequest();
    }
    else if (command == "getPatientBriefData")
    {
        processGetPatientBriefDataRequest(request);
    }
    else if (command == "getPatientInfo")
    {
        processGetPatientInfoRequest(request);
    }
}

void ClientHandler::processLoginRequest(const QJsonObject& request)
{
    LoginInputData inputData{};
    Reflect::fromJson(request, inputData);
    UserType userType{ m_databaseHandler.authenticateUser(inputData) };

    QJsonObject response{};
    response["command"] = "loginResult";
    response["userType"] = static_cast<int>(userType);

    QJsonDocument document{ response };
    m_socket->write(document.toJson());
}

void ClientHandler::processPatientRegistrationRequest(const QJsonObject& request)
{
    PatientData data{};
    Reflect::fromJson(request, data);
    bool success{ m_databaseHandler.registerPatient(data) };

    QJsonObject response{};
    response["command"] = "patientRegistrationResult";
    response["success"] = success;

    QJsonDocument document{ response };
    m_socket->write(document.toJson());
}

void ClientHandler::processGetAllPatientBriefDataRequest()
{
    std::vector<PatientBriefData> patients{
            m_databaseHandler.getAllPatientsBriefData() };
    QJsonArray jsonArray{};
    for (const auto& patient : patients)
    {
        jsonArray.append(Reflect::toJson(patient));
    }

    QJsonObject response{};
    response["command"] = "allPatientsBriefDataResult";
    response["briefData"] = jsonArray;

    QJsonDocument document{ response };
    m_socket->write(document.toJson());
}

void ClientHandler::processGetPatientBriefDataRequest(const QJsonObject& request)
{
    PatientSearchData data{};
    Reflect::fromJson(request, data);
    std::vector<PatientBriefData> patients{ m_databaseHandler.getPatientBriefData(data) };

    QJsonArray jsonArray{};
    for (const auto& patient : patients)
    {
        jsonArray.append(Reflect::toJson(patient));
    }

    QJsonObject response{};
    response["command"] = "patientBriefDataResult";
    response["briefData"] = jsonArray;

    QJsonDocument document{ response };
    m_socket->write(document.toJson());
}

void ClientHandler::processGetPatientInfoRequest(const QJsonObject& request)
{
    int id{ request["patientId"].toInt() };
    PatientData data{ m_databaseHandler.getPatientInfo(id) };

    QJsonObject response{ Reflect::toJson(data) };
    response["command"] = "patientInfoResult";

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
