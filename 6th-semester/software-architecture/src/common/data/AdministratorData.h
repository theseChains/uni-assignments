#ifndef POLYCLINIC_APP_COMMON_DATA_ADMINISTRATORDATA_H_
#define POLYCLINIC_APP_COMMON_DATA_ADMINISTRATORDATA_H_

#include <QString>

#include "Reflect.h"

namespace polyclinic
{
struct AdministratorData
{
    QString lastName{};
    QString firstName{};
    QString middleName{};
};
}

#endif
