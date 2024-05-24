#ifndef POLYCLINIC_APP_SERVER_DATABASEHANDLER_H_
#define POLYCLINIC_APP_SERVER_DATABASEHANDLER_H_

#include <QSqlDatabase>
#include <QString>

#include <array>
#include <vector>

#include "common/UserType.h"
#include "common/data/LoginInputData.h"
#include "common/data/PatientRegistrationData.h"
#include "common/data/PatientBriefData.h"

namespace polyclinic
{
class DatabaseHandler
{
public:
    DatabaseHandler();
    ~DatabaseHandler();

    bool connectToTheDatabase();

    UserType authenticateUser(const LoginInputData& loginData);
    bool registerPatient(const PatientRegistrationData& data);
    std::vector<PatientBriefData> getAllPatientsBriefData();

private:
    QSqlDatabase m_database{};
    QString m_connectionName{};
};
}

#endif
