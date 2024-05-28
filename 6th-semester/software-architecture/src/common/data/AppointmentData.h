#ifndef POLYCLINIC_APP_COMMON_DATA_APPOINTMENTDATA_H_
#define POLYCLINIC_APP_COMMON_DATA_APPOINTMENTDATA_H_

#include <QString>

#include "Reflect.h"

namespace polyclinic
{
struct AppointmentData
{
    QString firstDiagnosis{};
    int slotId{};
    int doctorId{};
    int patientId{};
    int registratorId{};
    int cardId{};
};

template <>
struct ReflectTraits<AppointmentData> {
    static constexpr auto fields() {
        return std::make_tuple(
            std::make_pair("firstDiagnosis", &AppointmentData::firstDiagnosis),
            std::make_pair("slotId", &AppointmentData::slotId),
            std::make_pair("doctorId", &AppointmentData::doctorId),
            std::make_pair("patientId", &AppointmentData::patientId),
            std::make_pair("registratorId", &AppointmentData::registratorId),
            std::make_pair("cardId", &AppointmentData::cardId)
        );
    }
};
}

#endif
