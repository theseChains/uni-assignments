#ifndef POLYCLINIC_APP_COMMON_DATA_REFLECT_H_
#define POLYCLINIC_APP_COMMON_DATA_REFLECT_H_

#include <QJsonObject>
#include <QString>

#include <optional>
#include <tuple>

namespace polyclinic
{
template <typename T>
struct ReflectTraits;

struct Reflect {
    template <typename T>
    static QJsonObject toJson(const T& obj) {
        QJsonObject json;
        toJsonImpl(obj, json, std::make_index_sequence<std::tuple_size<decltype(ReflectTraits<T>::fields())>::value>{});
        return json;
    }

    template <typename T, std::size_t... Is>
    static void toJsonImpl(const T& obj, QJsonObject& json, std::index_sequence<Is...>) {
        (..., (toJsonField(json, obj.*std::get<Is>(ReflectTraits<T>::fields()).second, std::get<Is>(ReflectTraits<T>::fields()).first)));
    }

    template <typename T>
    static void toJsonField(QJsonObject& json, const T& field, const QString& key) {
        if constexpr (is_optional_v<T>) {
            if (field.has_value()) {
                json[key] = toJsonValue(field.value());
            }
        } else {
            json[key] = toJsonValue(field);
        }
    }

    template <typename T>
    static QJsonValue toJsonValue(const T& value) {
        if constexpr (std::is_same_v<T, QDate>) {
            return value.toString(Qt::ISODate);
        } else if constexpr (std::is_same_v<T, QTime>) {
            return value.toString(Qt::ISODate);
        } else {
            return QJsonValue::fromVariant(QVariant::fromValue(value));
        }
    }

    template <typename T>
    static void fromJson(const QJsonObject& json, T& obj) {
        fromJsonImpl(json, obj, std::make_index_sequence<std::tuple_size<decltype(ReflectTraits<T>::fields())>::value>{});
    }

    template <typename T, std::size_t... Is>
    static void fromJsonImpl(const QJsonObject& json, T& obj, std::index_sequence<Is...>) {
        (..., fromJsonField(json, obj.*std::get<Is>(ReflectTraits<T>::fields()).second, std::get<Is>(ReflectTraits<T>::fields()).first));
    }

    template <typename T>
    static void fromJsonField(const QJsonObject& json, T& field, const QString& key) {
        if constexpr (is_optional_v<T>) {
            if (json.contains(key) && !json[key].isNull()) {
                field = fromJsonValue<std::remove_reference_t<decltype(*field)>>(json[key]);
            } else {
                field.reset();
            }
        } else {
            if (json.contains(key) && !json[key].isNull()) {
                field = fromJsonValue<T>(json[key]);
            }
        }
    }

    template <typename T>
    static T fromJsonValue(const QJsonValue& value) {
        if constexpr (std::is_same_v<T, QDate>) {
            return QDate::fromString(value.toString(), Qt::ISODate);
        } else if constexpr (std::is_same_v<T, QTime>) {
            return QTime::fromString(value.toString(), Qt::ISODate);
        } else {
            return value.toVariant().value<T>();
        }
    }

    template <typename T>
    struct is_optional : std::false_type {};

    template <typename T>
    struct is_optional<std::optional<T>> : std::true_type {};

    template <typename T>
    static constexpr bool is_optional_v = is_optional<T>::value;
};
}

#endif
