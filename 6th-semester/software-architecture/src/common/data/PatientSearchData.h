#ifndef POLYCLINIC_APP_COMMON_DATA_PATIENTSEARCHDATA_H_
#define POLYCLINIC_APP_COMMON_DATA_PATIENTSEARCHDATA_H_

#include <QString>
#include <QDate>

#include <optional>

#include "Reflect.h"

namespace polyclinic
{
struct PatientSearchData
{
    std::optional<QString> lastName{};
    std::optional<QString> firstName{};
    std::optional<QString> middleName{};
    std::optional<QDate> dateOfBirth{};
    std::optional<QString> gender{};
    std::optional<QString> documentType{};
    std::optional<QString> documentSeries{};
    std::optional<QString> documentNumber{};
};

template <>
struct ReflectTraits<PatientSearchData> {
    static constexpr auto fields() {
        return std::make_tuple(
            std::make_pair("lastName",
                           &PatientSearchData::lastName),
            std::make_pair("firstName",
                           &PatientSearchData::firstName),
            std::make_pair("middleName",
                           &PatientSearchData::middleName),
            std::make_pair("dateOfBirth",
                           &PatientSearchData::dateOfBirth),
            std::make_pair("gender",
                           &PatientSearchData::gender),
            std::make_pair("documentType",
                           &PatientSearchData::documentType),
            std::make_pair("documentNumber",
                           &PatientSearchData::documentNumber),
            std::make_pair("documentSeries",
                           &PatientSearchData::documentSeries)
        );
    }
};
}

#endif
