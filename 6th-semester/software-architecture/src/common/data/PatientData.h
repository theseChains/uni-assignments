#ifndef POLYCLINIC_APP_COMMON_DATA_PATIENTREGISTRATIONDATA_H_
#define POLYCLINIC_APP_COMMON_DATA_PATIENTREGISTRATIONDATA_H_

#include <QString>
#include <QJsonObject>

#include "Reflect.h"

namespace polyclinic
{
struct PatientData
{
    QString lastName{};
    QString firstName{};
    QString middleName{};
    QDate dateOfBirth{};
    QString gender{};
    QString documentType{};
    QString documentNumber{};
    QString documentSeries{};
    QString medicalInsuranceNumber{};
    QString individualInsuranceNumber{};
    QString phoneNumber{};
    QString city{};
    QString street{};
    int houseNumber{};
    int apartmentNumber{};
};

template <>
struct ReflectTraits<PatientData> {
    static constexpr auto fields() {
        return std::make_tuple(
            std::make_pair("lastName",
                           &PatientData::lastName),
            std::make_pair("firstName",
                           &PatientData::firstName),
            std::make_pair("middleName",
                           &PatientData::middleName),
            std::make_pair("dateOfBirth",
                           &PatientData::dateOfBirth),
            std::make_pair("gender",
                           &PatientData::gender),
            std::make_pair("documentType",
                           &PatientData::documentType),
            std::make_pair("documentNumber",
                           &PatientData::documentNumber),
            std::make_pair("documentSeries",
                           &PatientData::documentSeries),
            std::make_pair("medicalInsuranceNumber",
                           &PatientData::medicalInsuranceNumber),
            std::make_pair("individualInsuranceNumber",
                           &PatientData::individualInsuranceNumber),
            std::make_pair("phoneNumber",
                           &PatientData::phoneNumber),
            std::make_pair("city",
                           &PatientData::city),
            std::make_pair("street",
                           &PatientData::street),
            std::make_pair("houseNumber",
                           &PatientData::houseNumber),
            std::make_pair("apartmentNumber",
                           &PatientData::apartmentNumber)
        );
    }
};
}

#endif
