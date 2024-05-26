#include "Client.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

#include <iostream>

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

void Client::sendPatientRegistrationRequest(const PatientData& data)
{
    QJsonObject request{ Reflect::toJson(data) };
    request["command"] = "registerPatient";

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendGetAllPatientBriefDataRequest()
{
    QJsonObject request{};
    request["command"] = "getAllPatientBriefData";

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendGetPatientBriefDataRequest(const PatientSearchData& data)
{
    QJsonObject request{ Reflect::toJson(data) };
    request["command"] = "getPatientBriefData";

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendGetPatientInfoRequest(int id)
{
    QJsonObject request{};
    request["command"] = "getPatientInfo";
    request["patientId"] = id;

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
    else if (command == "patientRegistrationResult")
    {
        processPatientRegistrationResult(response);
    }
    else if (command == "allPatientsBriefDataResult")
    {
        processGetAllPatientBriefDataResult(response);
    }
    else if (command == "patientBriefDataResult")
    {
        processGetPatientBriefDataResult(response);
    }
    else if (command == "patientInfoResult")
    {
        processGetPatientInfoResult(response);
    }
}

void Client::processLoginResult(const QJsonObject& response)
{
    UserType userType{ static_cast<UserType>(response["userType"].toInt()) };
    emit loginResult(userType);
}

void Client::processPatientRegistrationResult(const QJsonObject& response)
{
    bool success{ response["success"].toBool() };
    emit patientRegistrationResult(success);
}

void Client::processGetAllPatientBriefDataResult(const QJsonObject& response)
{
    std::vector<PatientBriefData> data{};

    if (response.contains("briefData") && response["briefData"].isArray())
    {
        // never change to brace initialization
        QJsonArray jsonArray = response["briefData"].toArray();
        for (const auto& jsonValue : jsonArray)
        {
            if (jsonValue.isObject())
            {
                PatientBriefData patient{};
                Reflect::fromJson(jsonValue.toObject(), patient);
                data.push_back(patient);
            }
        }
    }

    emit getAllPatientsBriefDataResult(data);
}

void Client::processGetPatientBriefDataResult(const QJsonObject& response)
{
    std::vector<PatientBriefData> data{};

    // put this in a function man
    if (response.contains("briefData") && response["briefData"].isArray())
    {
        // never change to brace initialization
        QJsonArray jsonArray = response["briefData"].toArray();
        for (const auto& jsonValue : jsonArray)
        {
            if (jsonValue.isObject())
            {
                PatientBriefData patient{};
                Reflect::fromJson(jsonValue.toObject(), patient);
                data.push_back(patient);
            }
        }
    }

    emit getPatientBriefDataResult(data);
}

void Client::processGetPatientInfoResult(const QJsonObject& response)
{
    PatientData data{};
    Reflect::fromJson(response, data);
    emit getPatientInfoResult(data);
}

void Client::onDisconnected()
{
    qWarning() << "Disconnected from server.";
}
}
