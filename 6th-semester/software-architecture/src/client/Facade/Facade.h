#ifndef POLYCLINIC_APP_CLIENT_FACADE_FACADE_H_
#define POLYCLINIC_APP_CLIENT_FACADE_FACADE_H_

#include <QObject>
#include <vector>

#include "common/data/LoginInputData.h"
#include "common/data/PatientData.h"
#include "common/data/PatientSearchData.h"
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
    void registerPatient(const PatientData& data);
    void getAllPatientBriefData();
    void getPatientBriefData(const PatientSearchData& data);
    void getPatientInfo(int id);

signals:
    void loginResult(UserType userType);
    void patientRegistrationResult(bool success);
    void getAllPatientBriefDataResult(const std::vector<PatientBriefData>& data);
    void getPatientBriefDataResult(const std::vector<PatientBriefData>& data);
    void getPatientInfoResult(const PatientData& data);

private slots:
    void onClientLoginResult(UserType userType);
    void onPatientRegistrationResult(bool success);
    void onGetAllPatientBriefDataResult(const std::vector<PatientBriefData>& data);
    void onGetPatientBriefDataResult(const std::vector<PatientBriefData>& data);
    void onGetPatientInfoResult(const PatientData& data);

private:
    Client* m_client{};
};
}

#endif
