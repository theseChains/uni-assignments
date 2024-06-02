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

void Client::sendUpdatePatientInfoRequest(const PatientData& data, int id)
{
    QJsonObject request{ Reflect::toJson(data) };
    request["command"] = "updatePatientInfo";
    request["patientId"] = id;

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendGetDoctorsBySpecializationRequest(const QString& specialization)
{
    std::cerr << "sending get doctor by spec request\n";
    QJsonObject request{};
    request["command"] = "getDoctorsBySpecialization";
    request["specialization"] = specialization;

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendGetDoctorSlotsRequest(int doctorId, const QDate& date)
{
    QJsonObject request{};
    request["command"] = "getDoctorSlots";
    request["doctorId"] = doctorId;
    request["slotDate"] = date.toString("yyyy-MM-dd");

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendDeleteSlotRequest(int slotId)
{
    QJsonObject request{};
    request["command"] = "deleteSlot";
    request["slotId"] = slotId;

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendDeleteDayOfSlotsRequest(int doctorId, const QDate& date)
{
    QJsonObject request{};
    request["command"] = "deleteDayOfSlots";
    request["doctorId"] = doctorId;
    request["date"] = date.toString("yyyy-MM-dd");

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendAddSlotRequest(int doctorId, const QDate& date, const QTime& startTime)
{
    QJsonObject request{};
    request["command"] = "addSlot";
    request["doctorId"] = doctorId;
    request["date"] = date.toString("yyyy-MM-dd");
    request["startTime"] = startTime.toString("hh:mm");

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendAddDayOfSlotsRequest(int doctorId, const QDate& date)
{
    QJsonObject request{};
    request["command"] = "addDayOfSlots";
    request["doctorId"] = doctorId;
    request["date"] = date.toString("yyyy-MM-dd");

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendAddAppointmentRequest(const AppointmentData& data)
{
    QJsonObject request{ Reflect::toJson(data) };
    request["command"] = "addAppointment";

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendAddRegistratorRequest(const RegistratorData& data)
{
    QJsonObject request{ Reflect::toJson(data) };
    request["command"] = "addRegistrator";

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendAddDoctorRequest(const DoctorData& data)
{
    QJsonObject request{ Reflect::toJson(data) };
    request["command"] = "addDoctor";

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendGetDoctorAppointmentsRequest(const QDate& date, int doctorId)
{
    QJsonObject request{};
    request["command"] = "getDoctorAppointments";
    request["date"] = date.toString("yyyy-MM-dd");
    request["doctorId"] = doctorId;

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendAddMedicalRecordRequest(const MedicalRecordData& data)
{
    QJsonObject request{ Reflect::toJson(data) };
    request["command"] = "addMedicalRecord";
    std::cerr << "seding req to add med record\n";

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendGetOutpatientCardsRequest(const PatientBriefData& data)
{
    QJsonObject request{ Reflect::toJson(data) };
    request["command"] = "getOutpatientCards";

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendGetMedicalRecordsRequest(int patientId)
{
    QJsonObject request{};
    request["command"] = "getMedicalRecords";
    request["patientId"] = patientId;

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendGetMedicalRecordDataRequest(int recordId)
{
    QJsonObject request{};
    request["command"] = "getMedicalRecordData";
    request["recordId"] = recordId;

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendUpdateMedicalRecordRequest(const MedicalRecordData& data)
{
    QJsonObject request{ Reflect::toJson(data) };
    request["command"] = "updateMedicalRecord";

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendAddRecipeRequest(int recordId, const QString& recipe)
{
    QJsonObject request{};
    request["command"] = "addRecipe";
    request["recipe"] = recipe;
    request["recordId"] = recordId;

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendGetRegistratorsRequest(const RegistratorData& data)
{
    QJsonObject request{ Reflect::toJson(data) };
    request["command"] = "getRegistrators";

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendGetDoctorsRequest(const DoctorData& data)
{
    QJsonObject request{ Reflect::toJson(data) };
    request["command"] = "getDoctors";

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendDeleteRegistratorRequest(int registratorId)
{
    QJsonObject request{};
    request["command"] = "deleteRegistrator";
    request["registratorId"] = registratorId;

    QJsonDocument document{ request };
    m_socket->write(document.toJson());
}

void Client::sendDeleteDoctorRequest(int doctorId)
{
    QJsonObject request{};
    request["command"] = "deleteDoctor";
    request["doctorId"] = doctorId;

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
    else if (command == "updatePatientInfoResult")
    {
        processUpdatePatientInfoResult(response);
    }
    else if (command == "doctorsBySpecializationResult")
    {
        processGetDoctorsBySpecializationResult(response);
    }
    else if (command == "doctorSlotsResult")
    {
        processGetDoctorSlotsResult(response);
    }
    else if (command == "deleteSlotResult")
    {
        processDeleteSlotResult(response);
    }
    else if (command == "deleteDayOfSlotsResult")
    {
        processDeleteDayOfSlotsResult(response);
    }
    else if (command == "addSlotResult")
    {
        processAddSlotResult(response);
    }
    else if (command == "addDayOfSlotsResult")
    {
        processAddDayOfSlotsResult(response);
    }
    else if (command == "addAppointmentResult")
    {
        processAddAppointmentResult(response);
    }
    else if (command == "addRegistratorResult")
    {
        processAddRegistratorResult(response);
    }
    else if (command == "addDoctorResult")
    {
        processAddDoctorResult(response);
    }
    else if (command == "getDoctorAppointmentsResult")
    {
        processGetDoctorAppointmentsResult(response);
    }
    else if (command == "addMedicalRecordResult")
    {
        processAddMedicalRecordResult(response);
    }
    else if (command == "getOutpatientCardsResult")
    {
        processGetOutpatientCardsResult(response);
    }
    else if (command == "getMedicalRecordsResult")
    {
        processGetMedicalRecordsResult(response);
    }
    else if (command == "getMedicalRecordDataResult")
    {
        processGetMedicalRecordDataResult(response);
    }
    else if (command == "updateMedicalRecordResult")
    {
        processUpdateMedicalRecordResult(response);
    }
    else if (command == "addRecipeResult")
    {
        processAddRecipeResult(response);
    }
    else if (command == "getRegistratorsResult")
    {
        processGetRegistratorsResult(response);
    }
    else if (command == "getDoctorsResult")
    {
        processGetDoctorsResult(response);
    }
    else if (command == "deleteRegistratorResult")
    {
        processDeleteRegistratorResult(response);
    }
    else if (command == "deleteDoctorResult")
    {
        processDeleteDoctorResult(response);
    }
}

void Client::processLoginResult(const QJsonObject& response)
{
    UserType userType{ static_cast<UserType>(response["userType"].toInt()) };
    int userId{ response["id"].toInt() };

    emit loginResult({ userType, userId });
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

void Client::processUpdatePatientInfoResult(const QJsonObject& response)
{
    bool success{ response["success"].toBool() };
    emit updatePatientInfoResult(success);
}

void Client::processGetDoctorsBySpecializationResult(const QJsonObject& response)
{
    std::vector<DoctorScheduleData> data{};

    // put this in a function man
    if (response.contains("doctors") && response["doctors"].isArray())
    {
        QJsonArray jsonArray = response["doctors"].toArray();
        for (const auto& jsonValue : jsonArray)
        {
            if (jsonValue.isObject())
            {
                DoctorScheduleData doctor{};
                Reflect::fromJson(jsonValue.toObject(), doctor);
                data.push_back(doctor);
            }
        }
    }

    qDebug() << "Emitting getDoctorsBySpecializationResult signal";

    emit getDoctorsBySpecializationResult(data);
}

void Client::processGetDoctorSlotsResult(const QJsonObject& response)
{
    std::vector<DoctorSlotData> data{};

    // put this in a function man
    if (response.contains("slots") && response["slots"].isArray())
    {
        QJsonArray jsonArray = response["slots"].toArray();
        for (const auto& jsonValue : jsonArray)
        {
            if (jsonValue.isObject())
            {
                DoctorSlotData doctor{};
                Reflect::fromJson(jsonValue.toObject(), doctor);
                data.push_back(doctor);
            }
        }
    }

    emit getDoctorSlotsResult(data);
}

void Client::processDeleteSlotResult(const QJsonObject& response)
{
    bool success{ response["success"].toBool() };
    emit deleteSlotResult(success);
}

void Client::processDeleteDayOfSlotsResult(const QJsonObject& response)
{
    bool success{ response["success"].toBool() };
    emit deleteDayOfSlotsResult(success);
}

void Client::processAddSlotResult(const QJsonObject& response)
{
    bool success{ response["success"].toBool() };
    emit addSlotResult(success);
}

void Client::processAddDayOfSlotsResult(const QJsonObject& response)
{
    bool success{ response["success"].toBool() };
    emit addDayOfSlotsResult(success);
}

void Client::processAddAppointmentResult(const QJsonObject& response)
{
    bool success{ response["success"].toBool() };
    emit addAppointmentResult(success);
}

void Client::processAddRegistratorResult(const QJsonObject& response)
{
    bool success{ response["success"].toBool() };
    emit addRegistratorResult(success);
}

void Client::processAddDoctorResult(const QJsonObject& response)
{
    bool success{ response["success"].toBool() };
    emit addDoctorResult(success);
}

void Client::processGetDoctorAppointmentsResult(const QJsonObject& response)
{
    std::vector<AppointmentFullData> data{};

    // put this in a function man
    if (response.contains("appointments") && response["appointments"].isArray())
    {
        QJsonArray jsonArray = response["appointments"].toArray();
        for (const auto& jsonValue : jsonArray)
        {
            if (jsonValue.isObject())
            {
                AppointmentFullData appointment{};
                Reflect::fromJson(jsonValue.toObject(), appointment);
                data.push_back(appointment);
            }
        }
    }

    emit getDoctorAppointmentsResult(data);
}

void Client::processAddMedicalRecordResult(const QJsonObject& response)
{
    bool success{ response["success"].toBool() };
    std::cerr << "medical record result: " << success << '\n';
    emit addMedicalRecordResult(success);
}

void Client::processGetOutpatientCardsResult(const QJsonObject& response)
{
    std::vector<OutpatientCardData> data{};

    // put this in a function man
    if (response.contains("cards") && response["cards"].isArray())
    {
        QJsonArray jsonArray = response["cards"].toArray();
        for (const auto& jsonValue : jsonArray)
        {
            if (jsonValue.isObject())
            {
                OutpatientCardData card{};
                Reflect::fromJson(jsonValue.toObject(), card);
                data.push_back(card);
            }
        }
    }

    emit getOutpatientCardsResult(data);
}

void Client::processGetMedicalRecordsResult(const QJsonObject& response)
{
    std::vector<MedicalRecordData> data{};

    // put this in a function man
    if (response.contains("medicalRecords") && response["medicalRecords"].isArray())
    {
        QJsonArray jsonArray = response["medicalRecords"].toArray();
        for (const auto& jsonValue : jsonArray)
        {
            if (jsonValue.isObject())
            {
                MedicalRecordData record{};
                Reflect::fromJson(jsonValue.toObject(), record);
                data.push_back(record);
            }
        }
    }

    emit getMedicalRecordsResult(data);
}

void Client::processGetMedicalRecordDataResult(const QJsonObject& response)
{
    MedicalRecordData data{};
    Reflect::fromJson(response, data);
    emit getMedicalRecordDataResult(data);
}

void Client::processUpdateMedicalRecordResult(const QJsonObject& response)
{
    bool success{ response["success"].toBool() };
    emit updateMedicalRecordResult(success);
}

void Client::processAddRecipeResult(const QJsonObject& response)
{
    bool success{ response["success"].toBool() };
    emit addRecipeResult(success);
}

void Client::processGetRegistratorsResult(const QJsonObject& response)
{
    std::vector<RegistratorData> data{};

    // put this in a function man
    if (response.contains("registrators") && response["registrators"].isArray())
    {
        QJsonArray jsonArray = response["registrators"].toArray();
        for (const auto& jsonValue : jsonArray)
        {
            if (jsonValue.isObject())
            {
                RegistratorData registrator{};
                Reflect::fromJson(jsonValue.toObject(), registrator);
                data.push_back(registrator);
            }
        }
    }

    emit getRegistratorsResult(data);
}

void Client::processGetDoctorsResult(const QJsonObject& response)
{
    std::vector<DoctorData> data{};

    // put this in a function man
    if (response.contains("doctors") && response["doctors"].isArray())
    {
        QJsonArray jsonArray = response["doctors"].toArray();
        for (const auto& jsonValue : jsonArray)
        {
            if (jsonValue.isObject())
            {
                DoctorData doctor{};
                Reflect::fromJson(jsonValue.toObject(), doctor);
                data.push_back(doctor);
            }
        }
    }

    emit getDoctorsResult(data);
}

void Client::processDeleteRegistratorResult(const QJsonObject& response)
{
    bool success{ response["success"].toBool() };
    emit deleteRegistratorResult(success);
}

void Client::processDeleteDoctorResult(const QJsonObject& response)
{
    bool success{ response["success"].toBool() };
    emit deleteDoctorResult(success);
}

void Client::onDisconnected()
{
    qWarning() << "Disconnected from server.";
}
}
