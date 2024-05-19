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
    template<typename T, std::size_t... I>
    static void toJsonImpl(const T& obj, QJsonObject& json, std::index_sequence<I...>)
    {
        ((json[std::get<I>(ReflectTraits<T>::fields()).first] = obj.*std::get<I>(ReflectTraits<T>::fields()).second), ...);
    }

    template<typename T>
    static QJsonObject toJson(const T& obj)
    {
        QJsonObject json{};
        toJsonImpl(obj, json, std::make_index_sequence<std::tuple_size_v<decltype(ReflectTraits<T>::fields())>>{});
        return json;
    }

    template<typename T, std::size_t... I>
    static T fromJsonImpl(const QJsonObject& json, std::index_sequence<I...>)
    {
        return T{ json[std::get<I>(ReflectTraits<T>::fields()).first].toString()... };
    }

    template<typename T>
    static T fromJson(const QJsonObject& json)
    {
        return fromJsonImpl<T>(json, std::make_index_sequence<std::tuple_size_v<decltype(ReflectTraits<T>::fields())>>{});
    }
};
}

#endif
