#ifndef POLYCLINIC_APP_SERVER_DATABASEHANDLER_H_
#define POLYCLINIC_APP_SERVER_DATABASEHANDLER_H_

#include <QSqlDatabase>
#include <QString>

// change later please!
#include "../../common/UserType.h"
#include "../../common/data/LoginInputData.h"

namespace polyclinic
{
class DatabaseHandler
{
public:
    DatabaseHandler();
    ~DatabaseHandler();

    bool connectToTheDatabase();

    UserType authenticateUser(const LoginInputData& loginData);

private:
    QSqlDatabase m_database{};
    QString m_connectionName{};
};
}

#endif
