#ifndef POLYCLINIC_APP_COMMON_DATA_MEDICALRECORDDATA_H_
#define POLYCLINIC_APP_COMMON_DATA_MEDICALRECORDDATA_H_

#include <QString>

#include "Reflect.h"

namespace polyclinic
{
struct MedicalRecordData
{
    int patientId{};
    int recordId{};
    QDate dateOfEntry{};
    QString complaints{};
    QString diagnosis{};
    QString treatment{};
    QString tests{};
    QString notes{};
    QString recipe{};
};

template <>
struct ReflectTraits<MedicalRecordData>
{
    static constexpr auto fields()
    {
        return std::make_tuple(
            std::make_pair("patientId", &MedicalRecordData::patientId),
            std::make_pair("recordId", &MedicalRecordData::recordId),
            std::make_pair("dateOfEntry", &MedicalRecordData::dateOfEntry),
            std::make_pair("complaints", &MedicalRecordData::complaints),
            std::make_pair("diagnosis", &MedicalRecordData::diagnosis),
            std::make_pair("treatment", &MedicalRecordData::treatment),
            std::make_pair("tests", &MedicalRecordData::tests),
            std::make_pair("notes", &MedicalRecordData::notes),
            std::make_pair("recipe", &MedicalRecordData::recipe)
        );
    }
};
}

#endif
