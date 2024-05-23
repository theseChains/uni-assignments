#ifndef POLYCLINIC_APP_CLIENT_FACADE_H_
#define POLYCLINIC_APP_CLIENT_FACADE_H_

#include <QObject>

#include "common/data/LoginInputData.h"
#include "common/data/PatientRegistrationData.h"
#include "common/UserType.h"
#include "client/Client.h"

namespace polyclinic
{
class Facade : public QObject
{
    Q_OBJECT

public:
    explicit Facade(QObject* parent = nullptr);

    void login(const LoginInputData& inputData);
    void registerPatient(const PatientRegistrationData& data);

signals:
    void loginResult(UserType userType);
    void patientRegistrationResult(bool success);

private slots:
    void onClientLoginResult(UserType userType);
    void onPatientRegistrationResult(bool success);

private:
    Client* m_client{};
};
}

#endif
