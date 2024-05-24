#ifndef POLYCLINIC_APP_COMMON_DATA_REFLECT_H_
#define POLYCLINIC_APP_COMMON_DATA_REFLECT_H_

#include <QJsonObject>
#include <QString>
#include <tuple>

namespace polyclinic
{
template <typename T>
struct ReflectTraits;

struct Reflect
{
    template <typename T>
    static QJsonObject toJson(const T& obj)
    {
        QJsonObject json;
        toJsonImpl(obj, json, std::make_index_sequence<std::tuple_size<decltype(ReflectTraits<T>::fields())>::value>{});
        return json;
    }

    template <typename T, std::size_t... Is>
    static void toJsonImpl(const T& obj, QJsonObject& json, std::index_sequence<Is...>)
    {
        (..., (json[std::get<Is>(ReflectTraits<T>::fields()).first] = toJsonValue(obj.*std::get<Is>(ReflectTraits<T>::fields()).second)));
    }

    template <typename T>
    static QJsonValue toJsonValue(const T& value)
    {
        if constexpr (std::is_same_v<T, QDate>)
        {
            return value.toString(Qt::ISODate);
        }
        else
        {
            return value;
        }
    }

    template <typename T>
    static void fromJson(const QJsonObject& json, T& obj)
    {
        fromJsonImpl(json, obj, std::make_index_sequence<std::tuple_size<decltype(ReflectTraits<T>::fields())>::value>{});
    }

    template <typename T, std::size_t... Is>
    static void fromJsonImpl(const QJsonObject& json, T& obj, std::index_sequence<Is...>)
    {
        (..., fromJsonValue(json, obj.*std::get<Is>(ReflectTraits<T>::fields()).second, std::get<Is>(ReflectTraits<T>::fields()).first));
    }

    template <typename T>
    static void fromJsonValue(const QJsonObject& json, T& value, const QString& key)
    {
        if constexpr (std::is_same_v<T, QDate>)
        {
            if (json.contains(key) && json[key].isString())
            {
                value = QDate::fromString(json[key].toString(), Qt::ISODate);
            }
        }
        else
        {
            if (json.contains(key))
            {
                value = json[key].toVariant().value<T>();
            }
        }
    }
};
}

#endif
