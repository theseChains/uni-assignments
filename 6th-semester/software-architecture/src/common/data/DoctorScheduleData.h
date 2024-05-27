#ifndef POLYCLINIC_APP_COMMON_DATA_DOCTORSCHEDULEDATA_H_
#define POLYCLINIC_APP_COMMON_DATA_DOCTORSCHEDULEDATA_H_

#include <QString>

#include "Reflect.h"

namespace polyclinic
{
struct DoctorScheduleData
{
    int id{};
    QString lastName{};
};

template <>
struct ReflectTraits<DoctorScheduleData>
{
    static constexpr auto fields()
    {
        return std::make_tuple(
            std::make_pair("id", &DoctorScheduleData::id),
            std::make_pair("lastName", &DoctorScheduleData::lastName)
        );
    }
};
}

#endif
