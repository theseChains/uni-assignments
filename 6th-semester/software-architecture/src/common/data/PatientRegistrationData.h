#ifndef POLYCLINIC_APP_COMMON_DATA_PATIENTREGISTRATIONDATA_H_
#define POLYCLINIC_APP_COMMON_DATA_PATIENTREGISTRATIONDATA_H_

#include <QString>
#include <QJsonObject>

#include "Reflect.h"

namespace polyclinic
{
struct PatientRegistrationData
{
    QString lastName{};
    QString firstName{};

    PatientRegistrationData() = default;
    PatientRegistrationData(const QString& username, const QString& password)
        : username{ username }, password{ password }
    {}
};

template <>
struct ReflectTraits<PatientRegistrationData> {
    static constexpr auto fields() {
        return std::make_tuple(
            std::make_pair("username", &PatientRegistrationData::username),
            std::make_pair("password", &PatientRegistrationData::password)
        );
    }
};
}

#endif
