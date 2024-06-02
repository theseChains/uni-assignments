#ifndef POLYCLINIC_APP_COMMON_DATA_REGISTRATORDATA_H_
#define POLYCLINIC_APP_COMMON_DATA_REGISTRATORDATA_H_

#include <QString>

#include "Reflect.h"

namespace polyclinic
{
struct RegistratorData
{
    int id{};
    QString login{};
    QString password{};
    QString lastName{};
    QString firstName{};
    QString middleName{};
    QString phoneNumber{};
};

template <>
struct ReflectTraits<RegistratorData> {
    static constexpr auto fields() {
        return std::make_tuple(
            std::make_pair("id",
                           &RegistratorData::id),
            std::make_pair("login",
                           &RegistratorData::login),
            std::make_pair("password",
                           &RegistratorData::password),
            std::make_pair("lastName",
                           &RegistratorData::lastName),
            std::make_pair("firstName",
                           &RegistratorData::firstName),
            std::make_pair("middleName",
                           &RegistratorData::middleName),
            std::make_pair("phoneNumber",
                           &RegistratorData::phoneNumber)
        );
    }
};
}

#endif
