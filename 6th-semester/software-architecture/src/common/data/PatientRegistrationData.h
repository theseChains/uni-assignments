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
struct ReflectTraits<PatientRegistrationData> {
    static constexpr auto fields() {
        return std::make_tuple(
            std::make_pair("lastName",
                           &PatientRegistrationData::lastName),
            std::make_pair("firstName",
                           &PatientRegistrationData::firstName),
            std::make_pair("middleName",
                           &PatientRegistrationData::middleName),
            std::make_pair("dateOfBirth",
                           &PatientRegistrationData::dateOfBirth),
            std::make_pair("gender",
                           &PatientRegistrationData::gender),
            std::make_pair("documentType",
                           &PatientRegistrationData::documentType),
            std::make_pair("documentNumber",
                           &PatientRegistrationData::documentNumber),
            std::make_pair("documentSeries",
                           &PatientRegistrationData::documentSeries),
            std::make_pair("medicalInsuranceNumber",
                           &PatientRegistrationData::medicalInsuranceNumber),
            std::make_pair("individualInsuranceNumber",
                           &PatientRegistrationData::individualInsuranceNumber),
            std::make_pair("phoneNumber",
                           &PatientRegistrationData::phoneNumber),
            std::make_pair("city",
                           &PatientRegistrationData::city),
            std::make_pair("street",
                           &PatientRegistrationData::street),
            std::make_pair("houseNumber",
                           &PatientRegistrationData::houseNumber),
            std::make_pair("apartmentNumber",
                           &PatientRegistrationData::apartmentNumber)
        );
    }
};
}

#endif
