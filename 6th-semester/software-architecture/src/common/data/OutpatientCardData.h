#ifndef POLYCLINIC_APP_COMMON_DATA_OUTPATIENTCARDDATA_H_
#define POLYCLINIC_APP_COMMON_DATA_OUTPATIENTCARDDATA_H_

#include <QString>
#include <QDate>

#include "Reflect.h"

namespace polyclinic
{
struct OutpatientCardData
{
    int patientId{};
    QString patientLastName{};
    QString patientFirstName{};
    QString patientMiddleName{};
    QDate patientDateOfBirth{};
    QDate dateOfCreation{};
};

template <>
struct ReflectTraits<OutpatientCardData>
{
    static constexpr auto fields() {
        return std::make_tuple(
            std::make_pair("patientId", &OutpatientCardData::patientId),
            std::make_pair("patientLastName", &OutpatientCardData::patientLastName),
            std::make_pair("patientFirstName", &OutpatientCardData::patientFirstName),
            std::make_pair("patientMiddleName", &OutpatientCardData::patientMiddleName),
            std::make_pair("patientDateOfBirth", &OutpatientCardData::patientDateOfBirth),
            std::make_pair("dateOfCreation", &OutpatientCardData::dateOfCreation)
        );
    }
};
}

#endif
