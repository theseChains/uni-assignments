#ifndef POLYCLINIC_APP_COMMON_DATA_DOCTORDATA_H_
#define POLYCLINIC_APP_COMMON_DATA_DOCTORDATA_H_

#include <QString>

#include "Reflect.h"

namespace polyclinic
{
struct DoctorData
{
    QString login{};
    QString password{};
    QString lastName{};
    QString firstName{};
    QString middleName{};
    QString phoneNumber{};
    QString specialization{};
    int cabinetNumber{};
};

template <>
struct ReflectTraits<DoctorData> {
    static constexpr auto fields() {
        return std::make_tuple(
            std::make_pair("login",
                           &DoctorData::login),
            std::make_pair("password",
                           &DoctorData::password),
            std::make_pair("lastName",
                           &DoctorData::lastName),
            std::make_pair("firstName",
                           &DoctorData::firstName),
            std::make_pair("middleName",
                           &DoctorData::middleName),
            std::make_pair("phoneNumber",
                           &DoctorData::phoneNumber),
            std::make_pair("specialization",
                           &DoctorData::specialization),
            std::make_pair("cabinetNumber",
                           &DoctorData::cabinetNumber)
        );
    }
};
}

#endif
