#ifndef POLYCLINIC_APP_MODEL_APPLICATIONMODEL_H_
#define POLYCLINIC_APP_MODEL_APPLICATIONMODEL_H_

#include <QSqlDatabase>
#include <QString>

#include "Common/UserType.h"

namespace polyclinic
{
class ApplicationModel
{
public:
    ApplicationModel() = default;

    bool connectToTheDatabase();

    UserType authenticateUser(const QString& username, const QString& password);

private:
    QSqlDatabase m_database{};
};
}

#endif
