#ifndef POLYCLINIC_APP_COMMON_DATA_LOGININPUT_H_
#define POLYCLINIC_APP_COMMON_DATA_LOGININPUT_H_

#include <QString>
#include <QJsonObject>

#include "Reflect.h"

namespace polyclinic
{
struct LoginInputData
{
    QString username{};
    QString password{};

    LoginInputData() = default;
    LoginInputData(const QString& username, const QString& password)
        : username{ username }, password{ password }
    {}
};

template <>
struct ReflectTraits<LoginInputData> {
    static constexpr auto fields() {
        return std::make_tuple(
            std::make_pair("username", &LoginInputData::username),
            std::make_pair("password", &LoginInputData::password)
        );
    }
};
}

#endif
