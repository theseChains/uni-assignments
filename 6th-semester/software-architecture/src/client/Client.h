#ifndef POLYCLINIC_APP_CLIENT_CLIENT_H_
#define POLYCLINIC_APP_CLIENT_CLIENT_H_

#include <QObject>
#include <QTcpSocket>

#include "common/UserType.h"
#include "common/data/LoginInputData.h"
#include "common/data/PatientRegistrationData.h"

namespace polyclinic
{
class Client : public QObject
{
    Q_OBJECT

public:
    explicit Client(QObject* parent = nullptr);

    void connectToServer();
    void sendLoginRequest(const LoginInputData& inputData);
    void sendPatientRegistrationRequest(const PatientRegistrationData& data);

signals:
    void loginResult(UserType userType);
    void patientRegistrationResult(bool success);

private slots:
    void onReadyRead();
    void onDisconnected();

private:
    void processLoginResult(const QJsonObject& response);
    void processPatientRegistrationResult(const QJsonObject& response);

private:
    QTcpSocket* m_socket{};
};
}

#endif
