#include "ApplicationModel.h"

#include <QCoreApplication>
#include <QSqlQuery>
#include <QVariant>
#include <QSettings>
#include <QDebug>

#include <iostream>

namespace polyclinic
{
bool ApplicationModel::connectToTheDatabase()
{
    QString configPath{ QCoreApplication::applicationDirPath() + "/config/config.ini" };
    QSettings settings{ configPath, QSettings::IniFormat };
    qDebug() << "cfg path: " << configPath << '\n';

    m_database = QSqlDatabase::addDatabase("QPSQL");
    m_database.setHostName(settings.value("Database/Host").toString());

    qDebug() << settings.value("Database/Host").toString() << '\n';
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

UserType ApplicationModel::authenticateUser(const QString& login, const QString& password)
{
    QSqlQuery query{ m_database };
    query.prepare("SELECT r.registrator_id, a.administrator_id, d.doctor_id "
            "FROM login_data l "
            "LEFT JOIN registrators r ON l.login_data_id = r.login_data_id "
            "LEFT JOIN administrators a ON l.login_data_id = a.login_data_id "
            "LEFT JOIN doctors d ON l.login_data_id = d.login_data_id "
            "WHERE l.login = :login AND l.password = :password");
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.exec();

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
}
