#ifndef POLYCLINIC_APP_COMMON_DATA_LOGININPUT_H_
#define POLYCLINIC_APP_COMMON_DATA_LOGININPUT_H_

#include <QString>
#include <QJsonObject>

namespace polyclinic
{
struct LoginInputData
{
    QString username{};
    QString password{};

    static LoginInputData fromJson(const QJsonObject& data)
    {
        LoginInputData inputData{};
        inputData.username = data["username"].toString();
        inputData.password = data["password"].toString();

        return inputData;
    }

    QJsonObject toJson() const
    {
        QJsonObject jsonData{};
        jsonData["username"] = username;
        jsonData["password"] = password;

        return jsonData;
    }
};
}

#endif
