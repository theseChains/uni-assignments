#ifndef POLYCLINIC_APP_COMMON_DATA_APPOINTMENTFULLDATA_H_
#define POLYCLINIC_APP_COMMON_DATA_APPOINTMENTFULLDATA_H_

#include <QString>

#include "Reflect.h"

namespace polyclinic
{
struct AppointmentFullData
{
    QTime startTime{};
    QTime endTime{};
    QDate date{};
    QString patientLastName{};
    QString patientFirstName{};
    QString patientMiddleName{};
    int patientId{};
    QDate dateOfBirth{};
    QString registratorLastName{};
};

template <>
struct ReflectTraits<AppointmentFullData> {
    static constexpr auto fields() {
        return std::make_tuple(
            std::make_pair("startTime", &AppointmentFullData::startTime),
            std::make_pair("endTime", &AppointmentFullData::endTime),
            std::make_pair("date", &AppointmentFullData::date),
            std::make_pair("patientLastName",
                           &AppointmentFullData::patientLastName),
            std::make_pair("patientFirstName",
                           &AppointmentFullData::patientFirstName),
            std::make_pair("patientMiddleName",
                           &AppointmentFullData::patientMiddleName),
            std::make_pair("patientId",
                           &AppointmentFullData::patientId),
            std::make_pair("dateOfBirth", &AppointmentFullData::dateOfBirth),
            std::make_pair("registratorLastName",
                           &AppointmentFullData::registratorLastName)
        );
    }
};
}

#endif
