#include "DatabaseHandler.h"

#include <QCoreApplication>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QSettings>
#include <QDebug>
#include <QThread>
#include <QUuid>

#include <iostream>

namespace polyclinic
{
DatabaseHandler::DatabaseHandler()
{
    m_connectionName = QUuid::createUuid().toString();
}

DatabaseHandler::~DatabaseHandler()
{
    if (m_database.isOpen())
    {
        m_database.close();
    }

    QSqlDatabase::removeDatabase(m_connectionName);
}

bool DatabaseHandler::connectToTheDatabase()
{
    QString configPath{ QCoreApplication::applicationDirPath() + "/../config/config.ini" };
    QSettings settings{ configPath, QSettings::IniFormat };

    m_database = QSqlDatabase::addDatabase("QPSQL", m_connectionName);
    m_database.setHostName(settings.value("Database/Host").toString());
    m_database.setDatabaseName(settings.value("Database/DatabaseName").toString());
    m_database.setUserName(settings.value("Database/Username").toString());
    m_database.setPassword(settings.value("Database/Password").toString());
    m_database.setPort(settings.value("Database/Port").toInt());

    if (!m_database.open())
    {
        std::cerr << "Error connecting to the database\n";
        return false;
    }

    return true;
}

std::pair<UserType, int> DatabaseHandler::authenticateUser(const LoginInputData& loginData)
{
    QSqlQuery query{ m_database };
    query.prepare("SELECT r.registrator_id, a.administrator_id, d.doctor_id "
            "FROM login_data l "
            "LEFT JOIN registrators r ON l.login_data_id = r.login_data_id "
            "LEFT JOIN administrators a ON l.login_data_id = a.login_data_id "
            "LEFT JOIN doctors d ON l.login_data_id = d.login_data_id "
            "WHERE l.login = :username AND l.password = :password");
    query.bindValue(":username", loginData.username);
    query.bindValue(":password", loginData.password);

    if (!query.exec()) {
        qWarning() << "Database query error: " << query.lastError().text();
        return { UserType::kNone, -1 };
    }

    UserType userType{ UserType::kNone };
    int userId{ -1 };
    if (query.next()) {
        bool isRegistrator{ !query.value(0).isNull() };
        bool isAdministrator{ !query.value(1).isNull() };
        bool isDoctor{ !query.value(2).isNull() };

        if (isRegistrator) {
            userType = UserType::kRegistrator;
            userId = query.value(0).toInt();
        } else if (isAdministrator) {
            userType = UserType::kAdministrator;
            userId = query.value(1).toInt();
        } else if (isDoctor) {
            userType = UserType::kDoctor;
            userId = query.value(2).toInt();
        }
    }

    return { userType, userId };
}

bool DatabaseHandler::registerPatient(const PatientData& data)
{
    QSqlQuery query{ m_database };
    query.prepare("INSERT INTO patients "
                  "(last_name, first_name, middle_name, date_of_birth, gender, document_type, "
                  "document_number, document_series, medical_insurance_number, individual_insurance_number, "
                  "phone_number, city, street, house_number, apartment_number) "
                  "VALUES "
                  "(:last_name, :first_name, :middle_name, :date_of_birth, :gender, :document_type, "
                  ":document_number, :document_series, :medical_insurance_number, :individual_insurance_number, "
                  ":phone_number, :city, :street, :house_number, :apartment_number)");

    query.bindValue(":last_name", data.lastName);
    query.bindValue(":first_name", data.firstName);
    query.bindValue(":middle_name", data.middleName);
    query.bindValue(":date_of_birth", data.dateOfBirth);
    query.bindValue(":gender", data.gender);
    query.bindValue(":document_type", data.documentType);
    query.bindValue(":document_number", data.documentNumber);
    query.bindValue(":document_series", data.documentSeries);
    query.bindValue(":medical_insurance_number", data.medicalInsuranceNumber);
    query.bindValue(":individual_insurance_number", data.individualInsuranceNumber);
    query.bindValue(":phone_number", data.phoneNumber);
    query.bindValue(":city", data.city);
    query.bindValue(":street", data.street);
    query.bindValue(":house_number", data.houseNumber);
    query.bindValue(":apartment_number", data.apartmentNumber);

    // might want to pass those to the client
    if (!query.exec()) {
        qWarning() << "Error executing query:" << query.lastError().text();
        return false;
    }

    return true;
}

std::vector<PatientBriefData> DatabaseHandler::getAllPatientsBriefData()
{
    QSqlQuery query{ m_database };
    query.prepare("SELECT patient_id, last_name, first_name, middle_name, date_of_birth "
                  "FROM patients");

    if (!query.exec()) {
        qWarning() << "Error executing query:" << query.lastError().text();
        return {};
    }

    std::vector<PatientBriefData> data{};
    while (query.next())
    {
        PatientBriefData patient{};
        patient.id = query.value("patient_id").toInt();
        patient.lastName = query.value("last_name").toString();
        patient.firstName = query.value("first_name").toString();
        patient.middleName = query.value("middle_name").toString();
        patient.dateOfBirth = query.value("date_of_birth").toDate();

        data.push_back(patient);
    }

    return data;
}

std::vector<PatientBriefData> DatabaseHandler::getPatientBriefData(const PatientSearchData& data)
{
    QSqlQuery query{ m_database };
    QString queryString{ "SELECT patient_id, last_name, first_name, middle_name, date_of_birth "
                        "FROM patients WHERE 1 = 1" };
    if (data.lastName.has_value())
        queryString += " AND last_name = '" + data.lastName.value() + "'";
    if (data.firstName.has_value())
        queryString += " AND first_name = '" + data.firstName.value() + "'";
    if (data.middleName.has_value())
        queryString += " AND middle_name = '" + data.middleName.value() + "'";
    if (data.dateOfBirth.has_value())
        queryString += " AND date_of_birth = '" +
                data.dateOfBirth.value().toString("yyyy-MM-dd") + "'";
    if (data.documentType.has_value())
        queryString += " AND document_type = '" + data.documentType.value() + "'";
    if (data.documentSeries.has_value())
        queryString += " AND document_series = '" + data.documentSeries.value() + "'";
    if (data.documentNumber.has_value())
        queryString += " AND document_number = '" + data.documentNumber.value() + "'";
    if (data.gender.has_value())
        queryString += " AND gender = '" + data.gender.value() + "'";

    query.prepare(queryString);

    if (!query.exec()) {
        qWarning() << "Error executing query:" << query.lastError().text();
        return {};
    }

    std::vector<PatientBriefData> briefData{};
    while (query.next())
    {
        PatientBriefData patient{};
        patient.id = query.value("patient_id").toInt();
        patient.lastName = query.value("last_name").toString();
        patient.firstName = query.value("first_name").toString();
        patient.middleName = query.value("middle_name").toString();
        patient.dateOfBirth = query.value("date_of_birth").toDate();

        briefData.push_back(patient);
    }

    return briefData;
}

PatientData DatabaseHandler::getPatientInfo(int id)
{
    QSqlQuery query{ m_database };
    query.prepare("SELECT * FROM patients WHERE patient_id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qWarning() << "Error executing query:" << query.lastError().text();
        return {};
    }

    PatientData data{};
    if (query.next())
    {
        data.lastName = query.value("last_name").toString();
        data.firstName = query.value("first_name").toString();
        data.middleName = query.value("middle_name").toString();
        data.dateOfBirth = query.value("date_of_birth").toDate();
        data.documentType = query.value("document_type").toString();
        data.documentNumber = query.value("document_number").toString();
        data.documentSeries= query.value("document_series").toString();
        data.medicalInsuranceNumber = query.value("medical_insurance_number").toString();
        data.individualInsuranceNumber= query.value("individual_insurance_number").toString();
        data.phoneNumber = query.value("phone_number").toString();
        data.city = query.value("city").toString();
        data.street = query.value("street").toString();
        data.houseNumber = query.value("house_number").toInt();
        data.apartmentNumber = query.value("apartment_number").toInt();
    }

    return data;
}

bool DatabaseHandler::setPatientInfo(const PatientData& data, int id)
{
    QSqlQuery query{ m_database };
    query.prepare("UPDATE patients SET "
            "last_name = :last_name, "
            "first_name = :first_name, "
            "middle_name = :middle_name, "
            "date_of_birth = :date_of_birth, "
            "gender = :gender, "
            "document_type = :document_type, "
            "document_number = :document_number, "
            "document_series = :document_series, "
            "medical_insurance_number = :medical_insurance_number, "
            "individual_insurance_number = :individual_insurance_number, "
            "phone_number = :phone_number, "
            "city = :city, "
            "street = :street, "
            "house_number = :house_number, "
            "apartment_number = :apartment_number "
            "WHERE patient_id = :id");

    query.bindValue(":id", id);
    query.bindValue(":last_name", data.lastName);
    query.bindValue(":first_name", data.firstName);
    query.bindValue(":middle_name", data.middleName);
    query.bindValue(":date_of_birth", data.dateOfBirth);
    query.bindValue(":gender", data.gender);
    query.bindValue(":document_type", data.documentType);
    query.bindValue(":document_number", data.documentNumber);
    query.bindValue(":document_series", data.documentSeries);
    query.bindValue(":medical_insurance_number", data.medicalInsuranceNumber);
    query.bindValue(":individual_insurance_number", data.individualInsuranceNumber);
    query.bindValue(":phone_number", data.phoneNumber);
    query.bindValue(":city", data.city);
    query.bindValue(":street", data.street);
    query.bindValue(":house_number", data.houseNumber);
    query.bindValue(":apartment_number", data.apartmentNumber);

    if (!query.exec()) {
        qWarning() << "Error executing query:" << query.lastError().text();
        return false;
    }

    return true;
}

std::vector<DoctorScheduleData>
DatabaseHandler::getDoctorsBySpecialization(const QString& specialization)
{
    QSqlQuery query{ m_database };
    query.prepare("SELECT doctor_id, last_name FROM doctors "
                  "WHERE :specialization = specialization");
    query.bindValue(":specialization", specialization);

    if (!query.exec())
    {
        qWarning() << "Error executing query:" << query.lastError().text();
        return {};
    }

    std::vector<DoctorScheduleData> data{};
    while (query.next())
    {
        DoctorScheduleData doctor{};
        doctor.id = query.value("doctor_id").toInt();
        doctor.lastName = query.value("last_name").toString();
        doctor.specialization = specialization;

        data.push_back(doctor);
    }

    return data;
}

std::vector<DoctorSlotData> DatabaseHandler::getDoctorSlots(int doctorId, const QDate& date)
{
    QSqlQuery query{ m_database };
    query.prepare("SELECT doctor_slot_id, date, start_time, end_time, status "
            "FROM doctor_slots WHERE doctor_id = :doctor_id AND date = :date");
    query.bindValue(":doctor_id", doctorId);
    query.bindValue(":date", date);

    if (!query.exec())
    {
        qWarning() << "Error executing query:" << query.lastError().text();
        return {};
    }

    std::vector<DoctorSlotData> data{};
    while (query.next())
    {
        DoctorSlotData slot{};
        slot.id = query.value("doctor_slot_id").toInt();
        slot.doctorId = doctorId;
        slot.date = query.value("date").toDate();
        slot.startTime = query.value("start_time").toTime();
        slot.endTime = query.value("end_time").toTime();
        slot.status = query.value("status").toString();

        data.push_back(slot);
    }

    return data;
}

bool DatabaseHandler::deleteSlot(int slotId)
{
    QSqlQuery query{ m_database };
    query.prepare("DELETE FROM doctor_slots WHERE doctor_slot_id = :id");
    query.bindValue(":id", slotId);

    if (!query.exec())
    {
        qWarning() << "Error executing query:" << query.lastError().text();
        return false;
    }

    return true;
}

bool DatabaseHandler::deleteDayOfSlots(int doctorId, const QDate& date)
{
    QSqlQuery query{ m_database };
    query.prepare("DELETE FROM doctor_slots WHERE doctor_id = :doctor_id "
            "AND date = :date");
    query.bindValue(":doctor_id", doctorId);
    query.bindValue(":date", date);

    if (!query.exec())
    {
        qWarning() << "Error executing query:" << query.lastError().text();
        return false;
    }

    return true;
}

bool DatabaseHandler::addDayOfSlots(int doctorId, const QDate& date)
{
    QTime startTime{ 9, 0 };
    QTime endTime{ 17, 0 };
    QTime lunchStart{ 12, 0 };
    QTime lunchEnd{ 13, 0 };

    QSqlQuery checkQuery{ m_database };
    checkQuery.prepare("SELECT COUNT(*) FROM doctor_slots WHERE doctor_id = :doctor_id AND date = :date AND start_time = :start_time");

    QSqlQuery insertQuery{ m_database };
    insertQuery.prepare("INSERT INTO doctor_slots "
                        "(doctor_id, date, start_time, end_time, status) "
                        "VALUES (:doctor_id, :date, :start_time, :end_time, 'Свободен')");

    while (startTime < endTime)
    {
        if (startTime < lunchStart || startTime >= lunchEnd)
        {
            checkQuery.bindValue(":doctor_id", doctorId);
            checkQuery.bindValue(":date", date);
            checkQuery.bindValue(":start_time", startTime);

            if (checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() == 0)
            {
                insertQuery.bindValue(":doctor_id", doctorId);
                insertQuery.bindValue(":date", date);
                insertQuery.bindValue(":start_time", startTime);
                insertQuery.bindValue(":end_time", startTime.addSecs(10 * 60));
                if (!insertQuery.exec())
                {
                    qWarning() << "Error inserting slot:" << insertQuery.lastError().text();
                    return false;
                }
            }
        }
        startTime = startTime.addSecs(10 * 60);
    }

    return true;
}

bool DatabaseHandler::addSlot(int doctorId, const QDate& date, const QTime& startTime)
{
    QSqlQuery checkQuery{ m_database };
    checkQuery.prepare("SELECT COUNT(*) FROM doctor_slots WHERE doctor_id = :doctor_id AND date = :date AND start_time = :start_time");
    checkQuery.bindValue(":doctor_id", doctorId);
    checkQuery.bindValue(":date", date);
    checkQuery.bindValue(":start_time", startTime);

    if (checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() == 0)
    {
        QSqlQuery insertQuery{ m_database };
        insertQuery.prepare("INSERT INTO doctor_slots (doctor_id, date, start_time, end_time, status) "
                            "VALUES (:doctor_id, :date, :start_time, :end_time, 'Свободен')");
        insertQuery.bindValue(":doctor_id", doctorId);
        insertQuery.bindValue(":date", date);
        insertQuery.bindValue(":start_time", startTime);
        insertQuery.bindValue(":end_time", startTime.addSecs(10 * 60));

        if (!insertQuery.exec())
        {
            qWarning() << "Error inserting slot:" << insertQuery.lastError().text();
            return false;
        }

        return true;
    }
    else
    {
        qWarning() << "Slot already exists.";
        return false;
    }
}
}
