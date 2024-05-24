#ifndef POLYCLINIC_APP_COMMON_DATA_PATIENTBRIEFDATA_H_
#define POLYCLINIC_APP_COMMON_DATA_PATIENTBRIEFDATA_H_

#include <QString>
#include <QDate>

#include "Reflect.h"

namespace polyclinic
{
struct PatientBriefData
{
    int id{};
    QString firstName{};
    QString lastName{};
    QString middleName{};
    QDate dateOfBirth{};
};

template <>
struct ReflectTraits<PatientBriefData>
{
    static constexpr auto fields()
    {
        return std::make_tuple(
            std::make_pair("id", &PatientBriefData::id),
            std::make_pair("lastName", &PatientBriefData::lastName),
            std::make_pair("firstName", &PatientBriefData::firstName),
            std::make_pair("middleName", &PatientBriefData::middleName),
            std::make_pair("dateOfBirth", &PatientBriefData::dateOfBirth)
        );
    }
};
}

#endif
