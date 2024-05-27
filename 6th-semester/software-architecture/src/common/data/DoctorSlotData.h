#ifndef POLYCLINIC_APP_COMMON_DATA_DOCTORSLOTDATA_H_
#define POLYCLINIC_APP_COMMON_DATA_DOCTORSLOTDATA_H_

#include <QString>
#include <QTime>
#include <QDate>

#include "Reflect.h"

namespace polyclinic
{
struct DoctorSlotData
{
    int id{};
    int doctorId{};
    QDate date{};
    QTime startTime{};
    QTime endTime{};
    QString status{};
};

template <>
struct ReflectTraits<DoctorSlotData>
{
    static constexpr auto fields()
    {
        return std::make_tuple(
            std::make_pair("id", &DoctorSlotData::id),
            std::make_pair("doctorId", &DoctorSlotData::doctorId),
            std::make_pair("date", &DoctorSlotData::date),
            std::make_pair("startTime", &DoctorSlotData::startTime),
            std::make_pair("endTime", &DoctorSlotData::endTime),
            std::make_pair("status", &DoctorSlotData::status)
        );
    }
};
}

#endif
