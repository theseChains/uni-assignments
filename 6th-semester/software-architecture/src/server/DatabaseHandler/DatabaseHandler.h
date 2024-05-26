#ifndef POLYCLINIC_APP_SERVER_DATABASEHANDLER_H_
#define POLYCLINIC_APP_SERVER_DATABASEHANDLER_H_

#include <QSqlDatabase>
#include <QString>

#include <array>
#include <vector>

#include "common/UserType.h"
#include "common/data/LoginInputData.h"
#include "common/data/PatientData.h"
#include "common/data/PatientBriefData.h"
#include "common/data/PatientSearchData.h"

namespace polyclinic
{
class DatabaseHandler
{
public:
    DatabaseHandler();
    ~DatabaseHandler();

    bool connectToTheDatabase();

    UserType authenticateUser(const LoginInputData& loginData);
    bool registerPatient(const PatientData& data);
    std::vector<PatientBriefData> getAllPatientsBriefData();
    std::vector<PatientBriefData> getPatientBriefData(const PatientSearchData& data);
    PatientData getPatientInfo(int id);

private:
    QSqlDatabase m_database{};
    QString m_connectionName{};
};
}

#endif
