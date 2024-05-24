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

UserType DatabaseHandler::authenticateUser(const LoginInputData& loginData)
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
        return UserType::kNone;
    }

    UserType userType{ UserType::kNone };
    if (query.next()) {
        bool isRegistrator{ !query.value(0).isNull() };
        bool isAdministrator{ !query.value(1).isNull() };
        bool isDoctor{ !query.value(2).isNull() };

        if (isRegistrator) {
            userType = UserType::kRegistrator;
        } else if (isAdministrator) {
            userType = UserType::kAdministrator;
        } else if (isDoctor) {
            userType = UserType::kDoctor;
        }
    }

    return userType;
}

bool DatabaseHandler::registerPatient(const PatientRegistrationData& data)
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

    if (!query.exec()) {
        qWarning() << "Error executing query:" << query.lastError().text();
        return false;
    }

    return true;
}
}
